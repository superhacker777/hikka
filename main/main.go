package main

import (
	"net/http"
	"net/http/httputil"
	"net/url"

	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()

	r.LoadHTMLGlob("dist/*.html")      // 添加入口index.html
	r.LoadHTMLFiles("static/*/*")      // 添加资源路径
	r.Static("/js", "./dist/js")       // 添加资源路径
	r.Static("/css", "./dist/css")     // 添加资源路径
	r.Static("/media", "./dist/media") // 添加资源路径
	r.Static("/img", "./dist/img")     // 添加资源路径
	r.StaticFile("/", "dist/index.html")

	// r.GET("/rtsp/:door", Proxy)

	var ip string
	r.GET("/open/:door", func(c *gin.Context) {
		door := c.Param("door")
		if door == "aDoor" {
			ip = "192.168.22.248"
		} else if door == "bDoor" {
			ip = "192.168.22.249"
		}

		// ip := c.DefaultQuery("ip", "192.168.22.249")
		user := "admin"
		password := "Pccwc@m5"
		go Start(ip, user, password)
		c.JSON(200, gin.H{
			"message": "pong",
		})
	})
	r.Run() // listen and serve on 0.0.0.0:8080 (for windows "localhost:8080")
}

func Proxy(c *gin.Context) {
	door := c.Param("door")
	if door == "" {
		c.JSON(200, gin.H{"message": "door must not null"})
		return
	}

	remote, err := url.Parse("http://127.0.0.1:8888")
	if err != nil {
		panic(err)
	}

	proxy := httputil.NewSingleHostReverseProxy(remote)
	proxy.Director = func(req *http.Request) {
		req.Header = c.Request.Header
		req.Host = remote.Host
		req.URL.Scheme = remote.Scheme
		req.URL.Host = remote.Host
		req.URL.Path = "/" + door
	}

	proxy.ServeHTTP(c.Writer, c.Request)

}
