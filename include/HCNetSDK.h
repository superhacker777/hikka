/*
*
* Slightly modified for C compatibility
*
*/

#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef __PLAYRECT_defined
  #define __PLAYRECT_defined
  typedef struct __PLAYRECT
  {
      int x;                                
      int y;                                   
      int uWidth;                             
      int uHeight;                             
  } PLAYRECT; 
#endif

#if defined(_WIN32)
 //#define NET_DVR_API  extern "C" __declspec(dllimport)
  
  #ifndef __MINGW32__
    typedef  unsigned _int64 UINT64;
  #else
    typedef unsigned long long UINT64;
  #endif
#endif

#if defined(__linux__) || defined(__APPLE__) || defined(__MINGW32__) // *nix
  #define     BOOL  int
  // typedef     unsigned int        DWORD;
  // typedef     unsigned short      WORD;
  // typedef     unsigned short      USHORT;
  // typedef     int                 LONG;
  // typedef     unsigned char       BYTE ;
  // typedef     unsigned int        UINT;
  // typedef     void*               LPVOID;
  // typedef     void*               HANDLE;
  // typedef     unsigned int*       LPDWORD; 
  // typedef     unsigned long long  UINT64;

  #include <stdint.h>
  typedef uint32_t    DWORD;
  typedef uint16_t    WORD;
  typedef uint16_t    SHORT;
  typedef uint16_t    USHORT;
  typedef int32_t     LONG;
  typedef uint8_t     BYTE;
  typedef uint32_t    UINT;
  typedef void*       LPVOID;
  typedef void*       HANDLE;
  typedef uint32_t *  LPDWORD;
  typedef uint64_t    UINT64;

  #ifndef    TRUE
    #define    TRUE 1
  #endif
  #ifndef    FALSE
    #define    FALSE 0
  #endif
  #ifndef    NULL
    #define    NULL 0
  #endif

  
  #ifdef __linux__
    #define __stdcall 
  #endif
  #define CALLBACK  

  #ifndef __cplusplus
    #define NET_DVR_API 
  #else
    #define NET_DVR_API extern "C"
  #endif

  typedef unsigned int  COLORKEY;
  typedef unsigned int  COLORREF;

  #ifndef __HWND_defined
    #define __HWND_defined
    #ifdef __linux__
      typedef unsigned int HWND;
    #else
      typedef void* HWND;
    #endif
  #endif

  #ifndef __HDC_defined
    #define __HDC_defined
    #ifdef __linux__
      typedef struct __DC
      {
        void*   surface;        //SDL Surface
        HWND    hWnd;           // HDC window handle
      } DC;
      typedef DC* HDC;
    #else
      typedef void* HDC;
    #endif
  #endif

  typedef struct tagInitInfo
  {
    int uWidth; 
    int uHeight; 
  } INITINFO;
#endif

//Macro definition 
#define MAX_NAMELEN			        16		//DVR's local Username
#define MAX_RIGHT			        32		//Authority permitted by Device (1- 12 for local authority,  13- 32 for remote authority) 
#define NAME_LEN			        32      //Username length
#define PASSWD_LEN			        16      //Password length
#define SERIALNO_LEN		        48      //SN length
#define MACADDR_LEN			        6       //Length of MAC address
#define MAX_ETHERNET		        2       //Configurable Ethernet of device
#define MAX_NETWORK_CARD            4       //Configurable Network card of device
#define PATHNAME_LEN		        128     //length of path name
#define MAX_PRESET_V13              16      //Preset number

#define MAX_TIMESEGMENT_V30	        8       //Maximum number of time segments in 9000 DVR's guard schedule
#define MAX_TIMESEGMENT		        4       //Maximum number of time segments in 8000 DVR's guard schedule
#define MAX_SHELTERNUM			    4       //Maximum number of mask areas in 8000 DVR
#define MAX_DAYS				    7       //The number of days in a week
#define PHONENUMBER_LEN			    32      //Maximum length of PPPOE number

#define MAX_DISKNUM_V30		    	33		//Maximum disk number in 9000 DVR,  including 16 internal SATA disks,  1 eSTAT disk and 16 NFS disks
#define MAX_DISKNUM		            16      //Maximum disk number in 8000 DVR
#define MAX_DISKNUM_V10		        8       //used in 1.2 or earlier version

#define MAX_WINDOW_V30			    32      //9000 maximum number of local display windows
#define MAX_WINDOW				    16      //8000 maximum number of local display windows
#define MAX_VGA_V30				    4       //9000 maximum number of VGA
#define MAX_VGA			    	    1       //8000 maximum number of VGA

#define MAX_USERNUM_V30			    32      //Maximum number of 9000 DVR users
#define MAX_USERNUM			        16      //Maximum number of 8000 DVR users
#define MAX_EXCEPTIONNUM_V30	    32      //Maximum number of exceptions handled by 9000 DVR
#define MAX_EXCEPTIONNUM		    16      //Maximum number of exceptions handled by 8000 DVR
#define MAX_LINK				    6       //Maximum number of video connections to 8000's single channel

#define MAX_DECPOOLNUM			    4       //Maximum loop decoding number supported by each decoding channel of single channel decoder
#define MAX_DECNUM				    4       //Maximum decoding channel number of single channel decoder (only has one channel,  others are reserved) 
#define MAX_TRANSPARENTNUM		    2       //Maximum number of Transparent channel in single channel decoder
#define MAX_CYCLE_CHAN			    16      //Maximum number of loop channels in single channel decoder
#define MAX_CYCLE_CHAN_V30          64      //Maximum number of loop channels in single channel decoder (extend) 
#define MAX_DIRNAME_LENGTH		    80      //Maximum number of directory name
#define MAX_WINDOWS				    16      //Maximum number of windows

#define MAX_STRINGNUM_V30		    8		//Maximum number of OSD lines in 9000 DVR
#define MAX_STRINGNUM			    4       //Maximum number of OSD lines in 8000 DVR
#define MAX_STRINGNUM_EX		    8       //8000 customized extensions
#define MAX_AUXOUT_V30			    16      //9000 maximum number of AUX output ports
#define MAX_AUXOUT			        4       //8000 maximum number of AUX output ports
#define MAX_HD_GROUP			    16      //9000 maximum number of hard disk groups
#define MAX_NFS_DISK			    8       //8000 maximum number of NFS disks

#define IW_ESSID_MAX_SIZE	        32      //SSID length of WIFI
#define IW_ENCODING_TOKEN_MAX	    32      //Maximum bytes of WIFI security Key
#define MAX_SERIAL_NUM			    64	    //Maximum number of Transparent channel
#define MAX_DDNS_NUMS	            10      //Maximum number of DDNS in 9000
#define MAX_DOMAIN_NAME		        64		//Maximum Domain Name length
#define MAX_EMAIL_ADDR_LEN		    48		//Maximum Email Address length
#define MAX_EMAIL_PWD_LEN	        32      //Maximum Email password length

#define MAXPROGRESS		            100     //Maximum percent while playing back
#define MAX_SERIALNUM	            2       //Serial Port supported by 8000 DVR,  1- 232,  2- 485
#define CARDNUM_LEN		            20      //Card number length
#define MAX_VIDEOOUT_V30            4       //9000 DVR analog video output number. 
#define MAX_VIDEOOUT	            2       //8000 DVR analog video output number

#define MAX_PRESET_V30			    256		// 9000 Preset number of PTZ  
#define MAX_TRACK_V30			    256		// 9000 Track number of PTZ   
#define MAX_CRUISE_V30			    256		// 9000 Cruise number of PTZ  
#define MAX_PRESET				    128		// 8000 Preset number of PTZ  
#define MAX_TRACK				    128		// 8000 Track number of PTZ   
#define MAX_CRUISE				    128		// 8000 Cruise number of PTZ  

#define CRUISE_MAX_PRESET_NUMS	    32 	    // Maximum number of Cruise points in one Cruise 

#define MAX_SERIAL_PORT             8       // Maximum number of RS232 supported by 9000 DVR
#define MAX_PREVIEW_MODE            8       // Maximum number of display layout mode;  single windows/4 windows/9 windows/16 windows/... 
#define MAX_MATRIXOUT               16      // Maximum number of analog matrix output 
#define LOG_INFO_LEN                11840   // Additional information of Log 
#define DESC_LEN                    16      // String length of PTZ description 
#define PTZ_PROTOCOL_NUM            200     // Maximum number of PTZ protocols in 9000 DVR 
#define IPC_PROTOCOL_NUM            50      // Maximum number of ipc protocols in 9000 DVR 

#define MAX_AUDIO			        1       //Number of talk channels in 8000 DVR
#define MAX_AUDIO_V30			    2       //Number of talk channels in 9000 DVR
#define MAX_CHANNUM			        16      //Maximum number of video/audio channels in 8000 DVR
#define MAX_ALARMIN			        16      //Maximum number of alarm input channels in 8000 DVR
#define MAX_ALARMOUT		        4       //Maximum number of alarm output channels in 8000 DVR
//9000 IP Camera
#define MAX_ANALOG_CHANNUM          32      //32 analog channels in total
#define MAX_ANALOG_ALARMOUT         32      //32 analog alarm output channels intotal
#define MAX_ANALOG_ALARMIN          32      //32 analog alarm input channels intotal
#define MAX_IP_DEVICE               32      //9000 DVR can connect 32 IP devices
#define MAX_IP_DEVICE_V40           64      //Maximum number of IP devices that can be added, the value is 64, including IVMS-2000
#define MAX_IP_CHANNEL              32      //9000 DVR can connect 32 IP channels
#define MAX_IP_ALARMIN              128     //Maximum number of alarm input channels that can be added
#define MAX_IP_ALARMOUT             64      //Maximum number of alarm output channels that can be added

#define MAX_RECORD_FILE_NUM         20	    //max file number for back , cd write or delete

//SDK_V31 ATM
#define MAX_ACTION_TYPE	            12	    //Maximum action number of the transactions added  
#define MAX_ATM_PROTOCOL_NUM        256     //Maximum protocol number of each input sort
#define ATM_CUSTOM_PROTO            1025    //user- defined protocol
#define ATM_PROTOCOL_SORT           4       //number of ATM protocol segment 
#define ATM_DESC_LEN                32      //Length of the ATM description string
// SDK_V31 ATM

/*Maximum channels number including analog channels and IP channels */
#define MAX_CHANNUM_V30                ( MAX_ANALOG_CHANNUM + MAX_IP_CHANNEL )   //64
#define MAX_ALARMOUT_V30               ( MAX_ANALOG_ALARMOUT + MAX_IP_ALARMOUT ) //96
#define MAX_ALARMIN_V30                ( MAX_ANALOG_ALARMIN + MAX_IP_ALARMIN )   //160

#define MAX_LANERECT_NUM            5       //Max Lane rect num
#define MAX_FORTIFY_NUM				10      //Max number of channels to be fortified
#define MAX_INTERVAL_NUM			4       //Max number of interval
#define MAX_CHJC_NUM				3       //Max number of chars short for province of car
#define MAX_VL_NUM					5       //Max number of virtual lines
#define MAX_DRIVECHAN_NUM			16      //max number of drive channels
#define MAX_COIL_NUM				3       //max number of coils
#define MAX_SIGNALLIGHT_NUM			6       //max number of signal lights

#define AUDIOTALKTYPE_G722			0
#define AUDIOTALKTYPE_G711_MU		1
#define AUDIOTALKTYPE_G711_A		2
#define AUDIOTALKTYPE_G726			6

/*******************Global Error Code**********************/	
#define NET_DVR_NOERROR 					0	//No Error
#define NET_DVR_PASSWORD_ERROR 				1	//Username or Password error
#define NET_DVR_NOENOUGHPRI 				2	//Don't have enough authority 
#define NET_DVR_NOINIT 						3	//have not Initialized
#define NET_DVR_CHANNEL_ERROR 				4	//Channel number error
#define NET_DVR_OVER_MAXLINK 				5	//Number of clients connecting to DVR beyonds the Maximum
#define NET_DVR_VERSIONNOMATCH				6	//Version is not matched
#define NET_DVR_NETWORK_FAIL_CONNECT		7	//Connect to server failed
#define NET_DVR_NETWORK_SEND_ERROR			8	//Send data to server failed
#define NET_DVR_NETWORK_RECV_ERROR			9	//Receive data from server failed
#define NET_DVR_NETWORK_RECV_TIMEOUT		10	//Receive data from server timeout
#define NET_DVR_NETWORK_ERRORDATA			11	//Transferred data has error
#define NET_DVR_ORDER_ERROR					12	//Wrong Sequence of invoking API
#define NET_DVR_OPERNOPERMIT				13	//No such authority. 
#define NET_DVR_COMMANDTIMEOUT				14	//Execute command timeout
#define NET_DVR_ERRORSERIALPORT				15	//Serial port number error
#define NET_DVR_ERRORALARMPORT				16	//Alarm port error
#define NET_DVR_PARAMETER_ERROR 			17  //Parameters error
#define NET_DVR_CHAN_EXCEPTION				18	//Server channel in error status
#define NET_DVR_NODISK						19	//No hard disk
#define NET_DVR_ERRORDISKNUM				20	//Hard disk number error
#define NET_DVR_DISK_FULL					21	//Server's hard disk is full
#define NET_DVR_DISK_ERROR					22	//Server's hard disk error
#define NET_DVR_NOSUPPORT					23	//Server doesn't support
#define NET_DVR_BUSY						24	//Server is busy
#define NET_DVR_MODIFY_FAIL					25	//Server modification failed
#define NET_DVR_PASSWORD_FORMAT_ERROR		26	//Input format of Password error
#define NET_DVR_DISK_FORMATING				27	//Hard disk is formating,  cannot execute.  
#define NET_DVR_DVRNORESOURCE				28	//DVR don't have enough resource
#define	NET_DVR_DVROPRATEFAILED				29  //DVR Operation failed
#define NET_DVR_OPENHOSTSOUND_FAIL 			30  //Open PC audio failed
#define NET_DVR_DVRVOICEOPENED 				31  //Server's talk channel is occupied 
#define	NET_DVR_TIMEINPUTERROR				32  //Time input is not correct
#define	NET_DVR_NOSPECFILE					33  //Can't playback the file that does not exist in Server
#define NET_DVR_CREATEFILE_ERROR			34	//Create file error
#define	NET_DVR_FILEOPENFAIL				35  //Open file error
#define	NET_DVR_OPERNOTFINISH				36  //The previous operation is not finished yet
#define	NET_DVR_GETPLAYTIMEFAIL				37  //Get current playing time error
#define	NET_DVR_PLAYFAIL					38  //Playback error
#define NET_DVR_FILEFORMAT_ERROR			39  //Wrong file format
#define NET_DVR_DIR_ERROR					40	//Wrong directory 
#define NET_DVR_ALLOC_RESOURCE_ERROR		41  //Assign resource error
#define NET_DVR_AUDIO_MODE_ERROR			42	//Audio card mode error
#define NET_DVR_NOENOUGH_BUF				43	//Buffer is too small
#define NET_DVR_CREATESOCKET_ERROR		 	44	//Create SOCKET error
#define NET_DVR_SETSOCKET_ERROR				45	//Setup SOCKET error
#define NET_DVR_MAX_NUM						46	//Reach the maximum number
#define NET_DVR_USERNOTEXIST				47	//User does not exist
#define NET_DVR_WRITEFLASHERROR				48  //Write to FLASH error
#define NET_DVR_UPGRADEFAIL					49  //DVR update failed 
#define NET_DVR_CARDHAVEINIT				50  //Decoding Card has been initialized already
#define NET_DVR_PLAYERFAILED				51	//Invoke API of player library error
#define NET_DVR_MAX_USERNUM					52  //Reach the maximum number of DVR Users
#define NET_DVR_GETLOCALIPANDMACFAIL		53  //Failed to get Client software's IP or MAC address
#define NET_DVR_NOENCODEING					54	//No encoding on this channel
#define NET_DVR_IPMISMATCH					55	//IP address is not matched
#define NET_DVR_MACMISMATCH					56	//MAC address is not matched
#define NET_DVR_UPGRADELANGMISMATCH			57	//Update file has wrong language
#define NET_DVR_MAX_PLAYERPORT				58	//Reach the maximum player number
#define NET_DVR_NOSPACEBACKUP				59	//There is no enough space on the backup device
#define NET_DVR_NODEVICEBACKUP				60	//Failed to find the specified backup device 
#define NET_DVR_PICTURE_BITS_ERROR			61	//Image has wrong color bit,  24 color only
#define NET_DVR_PICTURE_DIMENSION_ERROR		62	//Image size exceeds the maximum value;  smaller than 128*256
#define NET_DVR_PICTURE_SIZ_ERROR			63	//Image file exceeds the maximum size;  smaller than 100K
#define NET_DVR_LOADPLAYERSDKFAILED			64	//Failed to load the player SDK from current directory
#define NET_DVR_LOADPLAYERSDKPROC_ERROR		65	//Failed to find the API's entry in player SDK
#define NET_DVR_LOADDSSDKFAILED				66	//Failed to load the DSsdk from current directory
#define NET_DVR_LOADDSSDKPROC_ERROR		    67	//Failed to find the API's entry in DSsDK
#define NET_DVR_DSSDK_ERROR					68	//Failed to involve the API of DSsDK.dll
#define NET_DVR_VOICEMONOPOLIZE				69	//Audio card has been occupied exclusively
#define NET_DVR_JOINMULTICASTFAILED			70	//Join to multicast group error
#define NET_DVR_CREATEDIR_ERROR				71	//Failed to create log directory
#define NET_DVR_BINDSOCKET_ERROR			72	//Failed to bind socked error. 
#define NET_DVR_SOCKETCLOSE_ERROR			73	//socket is disconnected,  that caused by network disconnected or unreachable destination mostly
#define NET_DVR_USERID_ISUSING			    74	//User ID is using when logout
#define NET_DVR_SOCKETLISTEN_ERROR			75	//Socket listen error
#define NET_DVR_PROGRAM_EXCEPTION			76	//Application error
#define NET_DVR_WRITEFILE_FAILED			77	//Failed to write file
#define NET_DVR_FORMAT_READONLY				78  //Forbidden to format read only disk
#define NET_DVR_WITHSAMEUSERNAME		    79  //Same user name already exists.
#define NET_DVR_DEVICETYPE_ERROR            80  //Device Model is not matched when import parameters
#define NET_DVR_LANGUAGE_ERROR              81  //Audio is not matched when import parameters
#define NET_DVR_PARAVERSION_ERROR           82  //Software version is not matched when import parameters
#define NET_DVR_IPCHAN_NOTALIVE             83  //IP Channels is off line when
#define NET_DVR_RTSP_SDK_ERROR				84	//Failed to load IPC communication library
#define NET_DVR_CONVERT_SDK_ERROR			85	//Failed to load stream format convertion library
#define NET_DVR_IPC_COUNT_OVERFLOW			86  //ip count overflow
#define NET_DVR_MAX_ADD_NUM                 87  //add label or other operation reach the maximum number
#define NET_DVR_PARAMMODE_ERROR             88  //Param Mode Error
//2009- 01- 04 
#define NET_DVR_CODESPITTER_OFFLINE			89  //Videoplat: CodeSpitter is Offline
#define NET_DVR_BACKUP_COPYING				90  //Device is backuping
//2010-01-16
#define NET_DVR_CHAN_NOTSUPPORT             91  //Channel doesn't support

#define NET_DVR_CALLINEINVALID              92  // The height line location is too concentrated, or the length line is not inclined enough 
#define NET_DVR_CALCANCELCONFLICT           93  // Cancel calibration conflict, if the rule and overall actual size filter have been set
#define NET_DVR_CALPOINTOUTRANGE            94 	// Calibration point exceeds the range 
#define NET_DVR_FILTERRECTINVALID           95  // The size filter does not meet the requirement
#define NET_DVR_DDNS_DEVOFFLINE             96  // Device hasn't registered to ddns
#define NET_DVR_DDNS_INTER_ERROR            97  // DDNS inter error
#define NET_DVR_FUNCTION_NOT_SUPPORT_OS     98  //This function don't support this OS.
#define NET_DVR_DEC_CHAN_REBIND             99  //Decode channel can not bind two or more display channel
#define NET_DVR_ALIAS_DUPLICATE				150	// Alias is duplicate  //2011-08-31 the configuration of new ddns accessing device by alias or serial number


// RAID error code
#define RAID_ERROR_INDEX	                200
#define NET_DVR_NAME_NOT_ONLY               (RAID_ERROR_INDEX + 0)  // Existing name
#define NET_DVR_OVER_MAX_ARRAY              (RAID_ERROR_INDEX + 1 ) // Number of arrays has reached its limit
#define NET_DVR_OVER_MAX_VD                 (RAID_ERROR_INDEX + 2 ) // Number of virtual disks  has reached its limit
#define NET_DVR_VD_SLOT_EXCEED              (RAID_ERROR_INDEX + 3 ) // Virtual disk slot is full
#define NET_DVR_PD_STATUS_INVALID           (RAID_ERROR_INDEX + 4 ) // Physical disk for rebuilding array is with error status
#define NET_DVR_PD_BE_DEDICATE_SPARE        (RAID_ERROR_INDEX + 5 ) // Physical disk for rebuilding array is specified as spare drive
#define NET_DVR_PD_NOT_FREE                 (RAID_ERROR_INDEX + 6 ) // Physical disk for rebuilding array is not idle
#define NET_DVR_CANNOT_MIG2NEWMODE          (RAID_ERROR_INDEX + 7 ) // Unable to migrate from the current array type to the new array type
#define NET_DVR_MIG_PAUSE                   (RAID_ERROR_INDEX + 8 ) // The migration operation has been paused
#define NET_DVR_MIG_CANCEL                  (RAID_ERROR_INDEX + 9 ) // The migration operation has been canceled
#define NET_DVR_EXIST_VD                    (RAID_ERROR_INDEX + 10) // Operation failed! Please delete the virtual disk existed in the array first
#define NET_DVR_TARGET_IN_LD_FUNCTIONAL     (RAID_ERROR_INDEX + 11) // Target physical disk is part of the virtual disk and is functional
#define NET_DVR_HD_IS_ASSIGNED_ALREADY      (RAID_ERROR_INDEX + 12) // Specified physical disk is assigned to a virtual disk
#define NET_DVR_INVALID_HD_COUNT            (RAID_ERROR_INDEX + 13) // Number of physical disks doesn't fit the specified RAID level
#define NET_DVR_LD_IS_FUNCTIONAL            (RAID_ERROR_INDEX + 14) // Specified virtual disk is functional
#define NET_DVR_BGA_RUNNING                 (RAID_ERROR_INDEX + 15) // BGA is running
#define NET_DVR_LD_NO_ATAPI                 (RAID_ERROR_INDEX + 16) // Can not create virtual disk with ATAPI drive
#define NET_DVR_MIGRATION_NOT_NEED          (RAID_ERROR_INDEX + 17) // Migration is not necessary
#define NET_DVR_HD_TYPE_MISMATCH            (RAID_ERROR_INDEX + 18) // Physical disks are not of the same type
#define NET_DVR_NO_LD_IN_DG                 (RAID_ERROR_INDEX + 19) // No virtual disk exist on the specified array
#define NET_DVR_NO_ROOM_FOR_SPARE           (RAID_ERROR_INDEX + 20) // Disk space is too small to be assigned as spare drive
#define NET_DVR_SPARE_IS_IN_MULTI_DG        (RAID_ERROR_INDEX + 21) // Disk is already assigned as a spare drive for an array
#define NET_DVR_DG_HAS_MISSING_PD           (RAID_ERROR_INDEX + 22) // Disk is missing from an array
// x86 64bit nvr 2012-02-04
#define NET_DVR_NAME_EMPTY					(RAID_ERROR_INDEX + 23) /*Name is empty*/
#define NET_DVR_INPUT_PARAM					(RAID_ERROR_INDEX + 24) /*Input param is wrong*/
#define NET_DVR_PD_NOT_AVAILABLE			(RAID_ERROR_INDEX + 25) /*Physics disk is not available*/
#define NET_DVR_ARRAY_NOT_AVAILABLE			(RAID_ERROR_INDEX + 26) /*Array is not available*/
#define NET_DVR_PD_COUNT					(RAID_ERROR_INDEX + 27) /*Physics disk number is wrong*/
#define NET_DVR_VD_SMALL					(RAID_ERROR_INDEX + 28) /*Virtual disk is small*/
#define NET_DVR_NO_EXIST					(RAID_ERROR_INDEX + 29) /*Raid No exist*/
#define NET_DVR_NOT_SUPPORT					(RAID_ERROR_INDEX + 30) /*Operation not support*/
#define NET_DVR_NOT_FUNCTIONAL	 			(RAID_ERROR_INDEX + 31) /*Raid is not functional*/
#define NET_DVR_DEV_NODE_NOT_FOUND			(RAID_ERROR_INDEX + 32) /*Virtual disk device node is no exist*/
#define NET_DVR_SLOT_EXCEED					(RAID_ERROR_INDEX + 33) /*Slot is exceed*/ 
#define NET_DVR_NO_VD_IN_ARRAY				(RAID_ERROR_INDEX + 34) /*Virtual disk is not exist in array*/
#define NET_DVR_VD_SLOT_INVALID				(RAID_ERROR_INDEX + 35) /*Virtual disk slot is invalid*/
#define NET_DVR_PD_NO_ENOUGH_SPACE			(RAID_ERROR_INDEX + 36) /*Physics disk is no enough space*/
#define NET_DVR_ARRAY_NONFUNCTION			(RAID_ERROR_INDEX + 37) /*Only functional raid can move*/
#define NET_DVR_ARRAY_NO_ENOUGH_SPACE		(RAID_ERROR_INDEX + 38) /*Array is no enough space*/
#define NET_DVR_STOPPING_SCANNING_ARRAY		(RAID_ERROR_INDEX + 39) /*Pull disk or scan array is processing*/
#define NET_DVR_NOT_SUPPORT_16T             (RAID_ERROR_INDEX + 40) /*Not support 16T*/

// Intelligence error code  
#define VCA_ERROR_INDEX                     300 // Index of intelligence error code
#define NET_DVR_ID_ERROR                    (VCA_ERROR_INDEX + 0)   // Configuration ID is illegal
#define NET_DVR_POLYGON_ERROR               (VCA_ERROR_INDEX + 1)   // Polygon does not match requirement
#define NET_DVR_RULE_PARAM_ERROR            (VCA_ERROR_INDEX + 2)   // Rule parameter is illegal
#define NET_DVR_RULE_CFG_CONFLICT           (VCA_ERROR_INDEX + 3)   // Configuration conflict
#define NET_DVR_CALIBRATE_NOT_READY         (VCA_ERROR_INDEX + 4)   // Calibration not ready
#define NET_DVR_CAMERA_DATA_ERROR           (VCA_ERROR_INDEX + 5)   // Camera parameter is illegal
#define NET_DVR_CALIBRATE_DATA_UNFIT        (VCA_ERROR_INDEX + 6)	// Not tilt enough, not fit to calibrate
#define NET_DVR_CALIBRATE_DATA_CONFILICT    (VCA_ERROR_INDEX + 7)	// Calibration error, all points are collinear or there locations are too concentrated
#define NET_DVR_CALIBRATE_CALC_FAIL         (VCA_ERROR_INDEX + 8)	// Failed to calculate camera calibration parameter
#define	NET_DVR_CALIBRATE_LINE_OUT_RECT		(VCA_ERROR_INDEX + 9)	// The input calibrating line exceeds the external rectangle sample
#define NET_DVR_ENTER_RULE_NOT_READY		(VCA_ERROR_INDEX + 10)  // Enter rule not ready
#define NET_DVR_AID_RULE_NO_INCLUDE_LANE	(VCA_ERROR_INDEX + 11)	// It does not include lane in the traffic event rule (especial for traffic jam or driving against the traffic)
#define NET_DVR_LANE_NOT_READY				(VCA_ERROR_INDEX + 12)	// Lane not ready
#define NET_DVR_RULE_INCLUDE_TWO_WAY		(VCA_ERROR_INDEX + 13)	// There are two different directions in event rule
#define NET_DVR_LANE_TPS_RULE_CONFLICT      (VCA_ERROR_INDEX + 14)  // The lane conflicts with the data rule
#define NET_DVR_NOT_SUPPORT_EVENT_TYPE      (VCA_ERROR_INDEX + 15)  // The event type is not supported by the device
#define NET_DVR_LANE_NO_WAY                 (VCA_ERROR_INDEX + 16)  // The lane has no direction
#define NET_DVR_SIZE_FILTER_ERROR           (VCA_ERROR_INDEX + 17)  // The size of filter is illegal

// VCA error
#define VCA_ERROR_INDEX                     300 // VCA error index
#define NET_DVR_ID_ERROR                    (VCA_ERROR_INDEX + 0)   // Configuration ID is illegal.
#define NET_DVR_POLYGON_ERROR               (VCA_ERROR_INDEX + 1)   // Polygon does not match requirement.
#define NET_DVR_RULE_PARAM_ERROR            (VCA_ERROR_INDEX + 2)   // Rule parameter is illegal.
#define NET_DVR_RULE_CFG_CONFLICT           (VCA_ERROR_INDEX + 3)   // Configuration conflict.
#define NET_DVR_CALIBRATE_NOT_READY         (VCA_ERROR_INDEX + 4)   // Calibration not ready.
#define NET_DVR_CAMERA_DATA_ERROR           (VCA_ERROR_INDEX + 5)   // Camera parameter is illegal.
#define NET_DVR_CALIBRATE_DATA_UNFIT        (VCA_ERROR_INDEX + 6)	// Not tilt enough, not fit to calibrate.
#define NET_DVR_CALIBRATE_DATA_CONFILICT    (VCA_ERROR_INDEX + 7)	// Calibration error.
#define NET_DVR_CALIBRATE_CALC_FAIL         (VCA_ERROR_INDEX + 8)	// Failed to calculate camera calibration parameter.
#define	NET_DVR_CALIBRATE_LINE_OUT_RECT		(VCA_ERROR_INDEX + 9)	// The input calibrating line exceeds the external rectangle sample.
#define NET_DVR_ENTER_RULE_NOT_READY		(VCA_ERROR_INDEX + 10)  // Enter rule not ready.
#define NET_DVR_AID_RULE_NO_INCLUDE_LANE	(VCA_ERROR_INDEX + 11)	// It does not include lane in the traffic event rule (especial for traffic jam or driving against the traffic).
#define NET_DVR_LANE_NOT_READY				(VCA_ERROR_INDEX + 12)	// Lane not ready.
#define NET_DVR_RULE_INCLUDE_TWO_WAY		(VCA_ERROR_INDEX + 13)	// There are two different directions in event rule.
#define NET_DVR_LANE_TPS_RULE_CONFLICT      (VCA_ERROR_INDEX + 14)  // The lane conflicts with the data rule.
#define NET_DVR_NOT_SUPPORT_EVENT_TYPE      (VCA_ERROR_INDEX + 15)  // Event type is not support.
#define NET_DVR_LANE_NO_WAY                 (VCA_ERROR_INDEX + 16)  // Lane has not direction.
#define NET_DVR_SIZE_FILTER_ERROR           (VCA_ERROR_INDEX + 17)  // Size filter is error.
#define NET_DVR_LIB_FFL_NO_FACE             (VCA_ERROR_INDEX + 18)  // Picture of feature point location has not face.
#define NET_DVR_LIB_FFL_IMG_TOO_SMALL       (VCA_ERROR_INDEX + 19)  // Picture of feature point location is too small.
#define NET_DVR_LIB_FD_IMG_NO_FACE          (VCA_ERROR_INDEX + 20)  // Picture of single detect has not face.
#define NET_DVR_LIB_FACE_TOO_SMALL          (VCA_ERROR_INDEX + 21)  // Face is too small when modeling.
#define NET_DVR_LIB_FACE_QUALITY_TOO_BAD    (VCA_ERROR_INDEX + 22)  // Face quality is too bad when modeling.
#define NET_DVR_KEY_PARAM_ERR               (VCA_ERROR_INDEX + 23)  //Key parameter is error.
#define NET_DVR_CALIBRATE_DATA_ERR          (VCA_ERROR_INDEX + 24)  //Calibrate data is error.
#define NET_DVR_CALIBRATE_DISABLE_FAIL      (VCA_ERROR_INDEX + 25)  //Disable calibrate has failed.
#define NET_DVR_VCA_LIB_FD_SCALE_OUTRANGE   (VCA_ERROR_INDEX + 26)  //Filter scale is out range.
#define NET_DVR_LIB_FD_REGION_TOO_LARGE     (VCA_ERROR_INDEX + 27)  //Region is too big.

#define NET_DVR_GET_AP_INFO_LIST					305//Get wireless network resource settings
#define NET_DVR_SET_WIFI_CFG						306	//Set wireless parameters for IP device
#define NET_DVR_GET_WIFI_CFG						307	//Get wireless parameters for IP device
#define NET_DVR_SET_WIFI_WORKMODE					308	//Set the network interface working mode of IP device 
#define NET_DVR_GET_WIFI_WORKMODE					309	//Get the network interface working mode of IP device 

#define NET_DVR_RTSP_ERROR_NOENOUGHPRI              401  // no authoration: RTSP return error code 401.
#define NET_DVR_RTSP_ERROR_ALLOC_RESOURCE           402  // fail to alloc resource
#define NET_DVR_RTSP_ERROR_PARAMETER                403  // parameter error.
#define NET_DVR_RTSP_ERROR_NO_URL                   404  // can't find the url. when server return 404，RTSP return it.
#define NET_DVR_RTSP_ERROR_FORCE_STOP               406  // user force to stop.
#define NET_DVR_RTSP_GETPORTFAILED                  407  // rtsp get port failed

#define NET_DVR_RTSP_DESCRIBERROR                   410  // rtsp describe communicate error
#define NET_DVR_RTSP_DESCRIBESENDTIMEOUT			411  // Sending signal "DECRIBE" is timeout
#define NET_DVR_RTSP_DESCRIBESENDERROR				412  // Failed to send signal "DECRIBE"
#define NET_DVR_RTSP_DESCRIBERECVTIMEOUT			413  // Receiving signal "DECRIBE" is timeout
#define NET_DVR_RTSP_DESCRIBERECVDATALOST			414  // Receiving data of signal "DECRIBE" error
#define NET_DVR_RTSP_DESCRIBERECVERROR			    415  // Failed to receive signal "DECRIBE"
#define NET_DVR_RTSP_DESCRIBESERVERERR				416  // Signal "DECRIBE" server returns the error that values 401 or 501, 401: user name or password error or no authorization, 501: device inner resource allocation failed 

#define NET_DVR_RTSP_SETUPERROR			            420  // rtsp setup communicate error
#define NET_DVR_RTSP_SETUPSENDTIMEOUT			    421  // Sending signal "SETUP" is timeout
#define NET_DVR_RTSP_SETUPSENDERROR					422  // Sending signal "SETUP" error
#define NET_DVR_RTSP_SETUPRECVTIMEOUT				423  // Receiving signal "SETUP" is timeout
#define NET_DVR_RTSP_SETUPRECVDATALOST				424  // Receiving data of signal "SETUP" error
#define NET_DVR_RTSP_SETUPRECVERROR					425  // Failed to receive signal "SETUP"
#define NET_DVR_RTSP_OVER_MAX_CHAN					426  // Signal "SETUP" server returns the error that values 401 or 501. It exceeds the max connection number

#define NET_DVR_RTSP_PLAYERROR			            430  // rtsp play communicate error
#define NET_DVR_RTSP_PLAYSENDTIMEOUT			    431  // Sending signal "PLAY" is timeout
#define NET_DVR_RTSP_PLAYSENDERROR					432  // Sending signal "PLAY" error
#define NET_DVR_RTSP_PLAYRECVTIMEOUT				433  // Receiving signal "PLAY" is timeout
#define NET_DVR_RTSP_PLAYRECVDATALOST				434  // Receiving data of signal "PLAY" error
#define NET_DVR_RTSP_PLAYRECVERROR					435  // Failed to receive signal "PLAY"
#define NET_DVR_RTSP_PLAYSERVERERR					436  // Signal "PLAY" server returns the error that values 401 or 501

#define NET_DVR_RTSP_TEARDOWNERROR			        440  // rtsp teardown communicate error
#define NET_DVR_RTSP_TEARDOWNSENDTIMEOUT			441  // Sending signal "TEARDOWN" is timeout
#define NET_DVR_RTSP_TEARDOWNSENDERROR				442  // Sending signal "TEARDOWN" error
#define NET_DVR_RTSP_TEARDOWNRECVTIMEOUT			443  // Receiving signal "TEARDOWN" is timeout
#define NET_DVR_RTSP_TEARDOWNRECVDATALOST			444  // Receiving data of signal "TEARDOWN" error
#define NET_DVR_RTSP_TEARDOWNRECVERROR				445  // Failed to receive signal "TEARDOWN"
#define NET_DVR_RTSP_TEARDOWNSERVERERR				446  // Signal "TEARDOWN" server returns the error that values 401 or 501

#define NET_PLAYM4_NOERROR							500	 // No error
#define	NET_PLAYM4_PARA_OVER						501	 // Input parameter is invalid; 
#define NET_PLAYM4_ORDER_ERROR						502	 // The order of the function to be called is error.
#define	NET_PLAYM4_TIMER_ERROR						503	 // Create multimedia clock failed; 
#define NET_PLAYM4_DEC_VIDEO_ERROR					504	 // Decode video data failed.
#define NET_PLAYM4_DEC_AUDIO_ERROR					505	 // Decode audio data failed.
#define	NET_PLAYM4_ALLOC_MEMORY_ERROR				506	 // Allocate memory failed.
#define NET_PLAYM4_OPEN_FILE_ERROR					507	 // Open the file failed.
#define NET_PLAYM4_CREATE_OBJ_ERROR					508	 // Create thread or event failed
#define NET_PLAYM4_CREATE_DDRAW_ERROR				509	 // Create DirectDraw object failed.
#define NET_PLAYM4_CREATE_OFFSCREEN_ERROR			510	 // Failed when creating off- screen surface.
#define NET_PLAYM4_BUF_OVER							511	 // Buffer is overflow
#define NET_PLAYM4_CREATE_SOUND_ERROR				512	 // Failed when creating audio device.	
#define	NET_PLAYM4_SET_VOLUME_ERROR					513	 // Set volume failed
#define NET_PLAYM4_SUPPORT_FILE_ONLY				514	 // The function only support play file.
#define NET_PLAYM4_SUPPORT_STREAM_ONLY				515	 // The function only support play stream.
#define NET_PLAYM4_SYS_NOT_SUPPORT					516	 // System not support.
#define NET_PLAYM4_FILEHEADER_UNKNOWN				517	 // No file header.
#define NET_PLAYM4_VERSION_INCORRECT				518	 // The version of decoder and encoder is not adapted.  
#define NET_PALYM4_INIT_DECODER_ERROR				519	 // Initialize decoder failed.
#define NET_PLAYM4_CHECK_FILE_ERROR					520	 // The file data is unknown.
#define NET_PLAYM4_INIT_TIMER_ERROR					521	 // Initialize multimedia clock failed.
#define	NET_PLAYM4_BLT_ERROR						522	 // BLT failed.
#define NET_PLAYM4_UPDATE_ERROR						523	 // Update failed.
#define NET_PLAYM4_OPEN_FILE_ERROR_MULTI			524  // Open file error,  stream type is multi
#define NET_PLAYM4_OPEN_FILE_ERROR_VIDEO			525  // Open file error,  stream type is video
#define NET_PLAYM4_JPEG_COMPRESS_ERROR				526  // JPEG compress error
#define NET_PLAYM4_EXTRACT_NOT_SUPPORT				527	 // Don't support the version of this file.
#define NET_PLAYM4_EXTRACT_DATA_ERROR				528	 // Extract video data failed.


#define NET_QOS_OK									700					    // No error
#define NET_QOS_ERROR								(NET_QOS_OK - 1)		// Qos error
#define NET_QOS_ERR_INVALID_ARGUMENTS				(NET_QOS_OK - 2)		// Invalid arguments 
#define NET_QOS_ERR_SESSION_NOT_FOUND				(NET_QOS_OK - 3)		// Session net found
#define NET_QOS_ERR_LIB_NOT_INITIALIZED				(NET_QOS_OK - 4)		// Lib not initialized
#define NET_QOS_ERR_OUTOFMEM						(NET_QOS_OK - 5)		// Out of memory
#define NET_QOS_ERR_PACKET_UNKNOW					(NET_QOS_OK - 10)		// Packet unknown
#define NET_QOS_ERR_PACKET_VERSION					(NET_QOS_OK - 11)		// Packet version error
#define NET_QOS_ERR_PACKET_LENGTH					(NET_QOS_OK - 12)		// Packet length error
#define NET_QOS_ERR_PACKET_TOO_BIG					(NET_QOS_OK - 13)		// Packet too big
#define NET_QOS_ERR_SCHEDPARAMS_INVALID_BANDWIDTH	(NET_QOS_OK - 20)		// Schedule parameters invalid bandwidth
#define NET_QOS_ERR_SCHEDPARAMS_BAD_FRACTION		(NET_QOS_OK - 21)		// Schedule parameters bad fraction
#define NET_QOS_ERR_SCHEDPARAMS_BAD_MINIMUM_INTERVAL (NET_QOS_OK - 22)	    // Schedule parameters bad minimum interval

#define NET_DVR_DEV_NET_OVERFLOW		             800	// Over the ability of the device network
#define NET_DVR_STATUS_RECORDFILE_WRITING_NOT_LOCK   801    // Can't lock because the file being recording.
#define NET_DVR_STATUS_CANT_FORMAT_LITTLE_DISK       802    // Can't format little disk.

#define NET_ERR_WINCHAN_IDX							 901	// Window index error
#define NET_ERR_WIN_LAYER							 902	// Window Layer	error
#define NET_ERR_WIN_BLK_NUM							 903	// Window Block error
#define NET_ERR_OUTPUT_RESOLUTION					 904	// Output resolution error
#define NET_ERR_LAYOUT								 905	// Layout Index error
#define NET_ERR_INPUT_RESOLUTION    				 906    // Input  resolution error

#define NET_ERR_SUBDEVICE_OFFLINE					 907    // device is off-line
#define NET_ERR_NO_DECODE_CHAN						 908    // no decode channel for use
#define NET_ERR_MAX_WINDOW_ABILITY					 909    // no enough resource for openning window 
#define NET_ERR_ORDER_ERROR							 910    // order error

#define NET_ERR_PLAYING_PLAN    					 911    //plan is running
#define NET_ERR_DECODER_USED						 912    //decoder is using

//ability analyze error
#define		XML_ANALYZE_NOENOUGH_BUF				1001		//no enough buf
#define		XML_ANALYZE_FIND_LOCALXML_ERROR			1002		//can not find local xml
#define		XML_ANALYZE_LOAD_LOCALXML_ERROR			1003		//local local xml error
#define		XML_NANLYZE_DVR_DATA_FORMAT_ERROR		1004		//device ability data format error
#define		XML_ANALYZE_TYPE_ERROR					1005		//ability type error
#define		XML_ANALYZE_XML_NODE_ERROR				1006		//XML ability node format error
/*******************Global Error Code end**********************/

/*************************************************
Return value of NET_DVR_IsSupport () ,  
the definition of bit 1 to bit 9 is below and TRUE means support
**************************************************/
#define NET_DVR_SUPPORT_DDRAW			0x01  // Support DIRECTDRAW,  otherwise Player can't work
#define NET_DVR_SUPPORT_BLT				0x02  // Display adapter supports BLT,  otherwise Player can't work
#define NET_DVR_SUPPORT_BLTFOURCC		0x04  // BLT supports color conversion,  otherwise,  Player will do RGB conversion in software mode; 
#define NET_DVR_SUPPORT_BLTSHRINKX		0x08  // BLT supports X- coordinate shrink,  otherwise,  Player will do it in software mode; 
#define NET_DVR_SUPPORT_BLTSHRINKY		0x10  // BLT supports Y- coordinate shrink,  otherwise,  Player will do it in software mode; 
#define NET_DVR_SUPPORT_BLTSTRETCHX		0x20  // BLT supports X- coordinate expand,  otherwise,  Player will do it in software mode; 
#define NET_DVR_SUPPORT_BLTSTRETCHY		0x40  // BLT supports Y- coordinate expand,  otherwise,  Player will do it in software mode; 
#define NET_DVR_SUPPORT_SSE				0x80  // CPU supports SSE commands, Intel Pentium3 or higher version supports SSE; 
#define NET_DVR_SUPPORT_MMX				0x100 // CPU supports MMX commands, Intel Pentium3 or higher version supports MMX

/**********************PTZ Commands begin*************************/	
#define LIGHT_PWRON		2	// Switch on light 
#define WIPER_PWRON		3	// Switch on Wiper 
#define FAN_PWRON		4	// Switch on Fan 
#define HEATER_PWRON	5	// Switch on Heater 
#define AUX_PWRON1		6	// Switch on auxiliary equipment 1
#define AUX_PWRON2		7	// Switch on auxiliary equipment 2
#define SET_PRESET		8	// Configure Preset 
#define CLE_PRESET		9	// Clean Preset 

#define ZOOM_IN			11	// Zoom in
#define ZOOM_OUT		12	// Zoom out 
#define FOCUS_NEAR      13  // Focus in 
#define FOCUS_FAR       14  // Focus out
#define IRIS_OPEN       15  // Iris open 
#define IRIS_CLOSE      16  // Iris close 

#define TILT_UP			21	// PTZ tilt up 
#define TILT_DOWN		22	// PTZ tilt down
#define PAN_LEFT		23	// PTZ pan left 
#define PAN_RIGHT		24	// PTZ pan right
#define UP_LEFT			25	// PTZ turn up and left 
#define UP_RIGHT		26	// PTZ turn up and right 
#define DOWN_LEFT		27	// PTZ turn down and left 
#define DOWN_RIGHT		28	// PTZ turn down and right 
#define PAN_AUTO		29	// PTZ auto pan 

#define FILL_PRE_SEQ	30	// Add preset to sequence 
#define SET_SEQ_DWELL	31	// Set cruise point's residence time 
#define SET_SEQ_SPEED	32	// Set cruise point 
#define CLE_PRE_SEQ		33	// Delete preset from sequence 
#define STA_MEM_CRUISE	34	// Start recording trace 
#define STO_MEM_CRUISE	35	// Stop recoding trace  
#define RUN_CRUISE		36	// Start Cruise 
#define RUN_SEQ			37	// Start Sequence 
#define STOP_SEQ		38	// Stop Sequence 
#define GOTO_PRESET		39	// Go to preset 
#define DEL_SEQ         43  /* delete cruise path */

#define PAN_CIRCLE     50  //PTZ of the SS speed automatic circle scanning
/**********************PTZ Commands end*************************/	

/*************************************************
Play Control Commands
Macro Definition
NET_DVR_PlayBackControl
NET_DVR_PlayControlLocDisplay
NET_DVR_DecPlayBackCtrl
**************************************************/	
#define NET_DVR_PLAYSTART		1  // Start Play
#define NET_DVR_PLAYSTOP		2  // Stop Play
#define NET_DVR_PLAYPAUSE		3  // Pause Play
#define NET_DVR_PLAYRESTART	    4  // Restore Play
#define NET_DVR_PLAYFAST		5  // Play faster
#define NET_DVR_PLAYSLOW		6  // Play slower
#define NET_DVR_PLAYNORMAL		7  // Normal Speed
#define NET_DVR_PLAYFRAME		8  // Play frame by frame
#define NET_DVR_PLAYSTARTAUDIO	9  // Open audio
#define NET_DVR_PLAYSTOPAUDIO	10 // Close audio
#define NET_DVR_PLAYAUDIOVOLUME	11 // Adjust volume 
#define NET_DVR_PLAYSETPOS		12 // Change the playback progress 
#define NET_DVR_PLAYGETPOS		13 // Get the playback progress
#define NET_DVR_PLAYGETTIME		14 // Get the played time (available when playback by time) 
#define NET_DVR_PLAYGETFRAME	15 // Get the played frame number (available when playback by file) 
#define NET_DVR_GETTOTALFRAMES  16 // Get total frame number of current file (available when playback by file) 
#define NET_DVR_GETTOTALTIME    17 // Get total time of current file (available when playback by file) 
#define NET_DVR_THROWBFRAME	    20 // Discard B frame
#define NET_DVR_SETSPEED		24 // Setup stream speed
#define NET_DVR_KEEPALIVE		25 // Keep connection with server (if callback is blocked,  send it every 2 second) 
#define NET_DVR_PLAYSETTIME		26 // Set playback position according to absolute time 
#define NET_DVR_PLAYGETTOTALLEN	27 // Get total time length of all the detected files under playback by time mode
#define NET_DVR_PLAY_FORWARD    29 //change stream from reverse to forward
#define NET_DVR_PLAY_REVERSE    30 //change stream from froward to reverse

//Remote Key//
/* key value send to CONFIG program */
#define KEY_CODE_1		1
#define KEY_CODE_2		2
#define KEY_CODE_3		3
#define KEY_CODE_4		4
#define KEY_CODE_5		5
#define KEY_CODE_6		6
#define KEY_CODE_7		7
#define KEY_CODE_8		8
#define KEY_CODE_9		9
#define KEY_CODE_0		10
#define KEY_CODE_POWER	11
#define KEY_CODE_MENU	12
#define KEY_CODE_ENTER	13
#define KEY_CODE_CANCEL 14
#define KEY_CODE_UP		15
#define KEY_CODE_DOWN	16
#define KEY_CODE_LEFT	17
#define KEY_CODE_RIGHT	18
#define KEY_CODE_EDIT	19
#define KEY_CODE_ADD	20
#define KEY_CODE_MINUS	21
#define KEY_CODE_PLAY	22
#define KEY_CODE_REC	23
#define KEY_CODE_PAN	24
#define KEY_CODE_M		25
#define KEY_CODE_A		26
#define KEY_CODE_F1		27
#define KEY_CODE_F2		28

/* for PTZ control */
#define KEY_PTZ_UP_START	 KEY_CODE_UP
#define KEY_PTZ_UP_STOP		 32

#define KEY_PTZ_DOWN_START	 KEY_CODE_DOWN
#define KEY_PTZ_DOWN_STOP	 33

#define KEY_PTZ_LEFT_START	 KEY_CODE_LEFT
#define KEY_PTZ_LEFT_STOP	 34

#define KEY_PTZ_RIGHT_START  KEY_CODE_RIGHT
#define KEY_PTZ_RIGHT_STOP	 35

#define KEY_PTZ_AP1_START	 KEY_CODE_EDIT /* Iris+ */
#define KEY_PTZ_AP1_STOP	 36

#define KEY_PTZ_AP2_START	 KEY_CODE_PAN /* Iris-  */
#define KEY_PTZ_AP2_STOP	 37

#define KEY_PTZ_FOCUS1_START KEY_CODE_A /* Focus+ */
#define KEY_PTZ_FOCUS1_STOP  38

#define KEY_PTZ_FOCUS2_START KEY_CODE_M /* Focus-  */
#define KEY_PTZ_FOCUS2_STOP  39

#define KEY_PTZ_B1_START	 40 /* Zoom+ */
#define KEY_PTZ_B1_STOP		 41

#define KEY_PTZ_B2_START	 42 /* Zoom-  */
#define KEY_PTZ_B2_STOP		 43

//New in 9000
#define KEY_CODE_11			 44
#define KEY_CODE_12			 45
#define KEY_CODE_13			 46
#define KEY_CODE_14			 47
#define KEY_CODE_15			 48
#define KEY_CODE_16			 49

/*************************Parameter Configure Commands begin*******************************/
//Used for NET_DVR_SetDVRConfig and NET_DVR_GetDVRConfig,  pay attention to corresponding Structure

#define NET_DVR_GET_DEVICECFG		100		//Get DVR Parameters
#define NET_DVR_SET_DEVICECFG		101		//Set DVR Parameters
#define NET_DVR_GET_NETCFG			102		//Get Network Parameters
#define NET_DVR_SET_NETCFG			103		//Set Network Parameters
#define NET_DVR_GET_PICCFG			104		//Get Image Parameters
#define NET_DVR_SET_PICCFG			105		//Set Image Parameters
#define NET_DVR_GET_COMPRESSCFG		106		//Get Compression Parameters
#define NET_DVR_SET_COMPRESSCFG		107		//Set Compression Parameters
#define NET_DVR_GET_RECORDCFG		108		//Get Record Parameters
#define NET_DVR_SET_RECORDCFG		109		//Set Record Parameters
#define NET_DVR_GET_DECODERCFG		110		//Get PTZ Parameters
#define NET_DVR_SET_DECODERCFG		111		//Set PTZ Parameters
#define NET_DVR_GET_RS232CFG 		112		//Get RS232 Parameters
#define NET_DVR_SET_RS232CFG		113		//Set RS232 Parameters
#define NET_DVR_GET_ALARMINCFG 		114		//Get Alarm In Parameters
#define NET_DVR_SET_ALARMINCFG		115		//Set Alarm In Parameters
#define NET_DVR_GET_ALARMOUTCFG 	116		//Get Alarm Out Parameters
#define NET_DVR_SET_ALARMOUTCFG		117		//Set Alarm Out Parameters
#define NET_DVR_GET_TIMECFG 		118		//Get DVR time
#define NET_DVR_SET_TIMECFG			119		//Set DVR time
#define NET_DVR_GET_PREVIEWCFG 		120		//Get Local Preview Parameters
#define NET_DVR_SET_PREVIEWCFG		121		//Set Local Preview Parameters
#define NET_DVR_GET_VIDEOOUTCFG 	122		//Get Video Output Parameters
#define NET_DVR_SET_VIDEOOUTCFG		123		//Set Video Output Parameters
#define NET_DVR_GET_USERCFG 		124		//Get User Parameters
#define NET_DVR_SET_USERCFG			125		//Set User Parameters
#define NET_DVR_GET_EXCEPTIONCFG 	126		//Get Exception Parameters
#define NET_DVR_SET_EXCEPTIONCFG	127		//Set Exception Parameters
#define NET_DVR_GET_ZONEANDDST		128		//Get Time Zone & DST Parameters
#define NET_DVR_SET_ZONEANDDST		129		//Set Time Zone & DST Parameters
#define NET_DVR_GET_SHOWSTRING		130		//Get OSD Parameters
#define NET_DVR_SET_SHOWSTRING		131		//Set OSD Parameters
#define NET_DVR_GET_EVENTCOMPCFG	132		//Get Event Record Parameters
#define NET_DVR_SET_EVENTCOMPCFG	133		//Set Event Record  Parameters

#define NET_DVR_GET_FTPCFG			134		//get ftp parameters
#define NET_DVR_SET_FTPCFG			135		//set ftp parameters

#define NET_DVR_GET_AUXOUTCFG		140		//Get External Alarm Configuration
#define NET_DVR_SET_AUXOUTCFG		141		//Set External Alarm Configuration
#define NET_DVR_GET_PREVIEWCFG_AUX 	142		//Get - S device dual output parameters
#define NET_DVR_SET_PREVIEWCFG_AUX	143		//Set - S device dual output parameters

/*********************************Intelligence APIs Begin***************************************/

//VCA  (NET_VCA_RULECFG) 
#define NET_DVR_SET_RULECFG					152  //Set rule of VCA
#define NET_DVR_GET_RULECFG					153	 //Get rule of VCA
//Track parameters of Speed dome (NET_DVR_TRACK_CFG) 
#define NET_DVR_SET_TRACK_CFG				160  //Set Speed dome config 
#define NET_DVR_GET_TRACK_CFG				161  //Get Speed dome config

//Config Commands for Getting Stream
#define NET_DVR_SET_IVMS_STREAMCFG			162	 //Set IVMS Parameter for getting stream
#define NET_DVR_GET_IVMS_STREAMCFG			163	 //Get IVMS Parameter

//Intelligent control parameter
#define NET_DVR_SET_VCA_CTRLCFG				164	 //Set intelligent control parameter
#define NET_DVR_GET_VCA_CTRLCFG				165	 //Get intelligent control parameter

//Mask Area,  NET_VCA_MASK_REGION_LIST
#define NET_DVR_SET_VCA_MASK_REGION			166	 //Set Mask Area 
#define NET_DVR_GET_VCA_MASK_REGION			167	 //Get Mask Area 

//Get/Set Enter ATM Region Commands,  NET_VCA_ENTER_REGION
#define NET_DVR_SET_VCA_ENTER_REGION		168	 //Set region parameter
#define NET_DVR_GET_VCA_ENTER_REGION		169	 //Get region parameter

// ivms mask region,  NET_IVMS_MASK_REGION_LIST
#define NET_DVR_SET_IVMS_MASK_REGION		172	 //SetIVMS mask region parameter 
#define NET_DVR_GET_IVMS_MASK_REGION		173	 //GetIVMS mask region parameter 
// ivms enter detecting region,  NET_IVMS_ENTER_REGION
#define NET_DVR_SET_IVMS_ENTER_REGION		174	 //Set IVMS enter region parameter 
#define NET_DVR_GET_IVMS_ENTER_REGION		175	 //Get IVMS enter region parameter 

//IVMS VCA Config Commands
#define NET_DVR_SET_IVMS_BEHAVIORCFG		176	//Set IVMS VCA rule 
#define NET_DVR_GET_IVMS_BEHAVIORCFG		177	//Get IVMS VCA rule 

// IVMS Playback Search
#define NET_DVR_IVMS_SET_SEARCHCFG			178	 //SetIVMS Playback Search parameter 
#define NET_DVR_IVMS_GET_SEARCHCFG			179  	 //GetIVMS Playback Search parameter 

// SDK_V35
#define NET_DVR_SET_POSITION_TRACK			180  // Set track scene configuration info
#define NET_DVR_GET_POSITION_TRACK			181  // Get track scene configuration info

#define NET_DVR_SET_CALIBRATION				182  // Set calibration info
#define NET_DVR_GET_CALIBRATION				183  // Get calibration info

#define NET_DVR_SET_PDC_RULECFG				184  // Set PDC counting rule
#define NET_DVR_GET_PDC_RULECFG				185  // Get PDC counting rule

#define NET_DVR_SET_PU_STREAMCFG			186  // Set PU stream configuration info
#define NET_DVR_GET_PU_STREAMCFG			187  // Get PU stream configuration info

#define NET_VCA_SET_IVMS_BEHAVIOR_CFG		192  // Set IVMS VCA without time period settings
#define NET_VCA_GET_IVMS_BEHAVIOR_CFG		193  // Get IVMS VCA without time period settings

//Global Target Size filter
#define NET_VCA_SET_SIZE_FILTER				194  //Set global target size filter
#define NET_VCA_GET_SIZE_FILTER				195  //Get global target size filter

#define NET_DVR_SET_TRACK_PARAMCFG			196  // Set local menu rules of speed dome
#define NET_DVR_GET_TRACK_PARAMCFG			197  // Get local menu rules of speed dome

#define NET_DVR_SET_DOME_MOVEMENT_PARAM		198  // Set movement parameters of speed dome
#define NET_DVR_GET_DOME_MOVEMENT_PARAM		199  // Get movement parameters of speed dome

/**************************************Intelligent APIs Begin**********************************/

#define NET_DVR_GET_PICCFG_EX		200		//Get Image Parameters  (Extended) 
#define NET_DVR_SET_PICCFG_EX		201		//Set Image Parameters  (Extended) 
#define NET_DVR_GET_USERCFG_EX 		202		//Get User Parameters (Extended) 
#define NET_DVR_SET_USERCFG_EX		203		//Set User Parameters (Extended) 
#define NET_DVR_GET_COMPRESSCFG_EX	204		//Get Compression Parameters  (Extended) 
#define NET_DVR_SET_COMPRESSCFG_EX	205		//Set Compression Parameters  (Extended) 


#define NET_DVR_GET_NETAPPCFG		222		//Get Network Application Parameters NTP/DDNS/EMAIL
#define NET_DVR_SET_NETAPPCFG		223		//Set Network Application Parameters NTP/DDNS/EMAIL
#define NET_DVR_GET_NTPCFG			224		//Get Network Application Parameters NTP
#define NET_DVR_SET_NTPCFG			225		//Set Network Application Parameters NTP
#define NET_DVR_GET_DDNSCFG			226		//Get Network Application Parameters DDNS
#define NET_DVR_SET_DDNSCFG			227		//Set Network Application Parameters DDNS

//Corresponding with NET_DVR_EMAILPARA
#define NET_DVR_GET_EMAILCFG		228		//Get EMAIL Configuration
#define NET_DVR_SET_EMAILCFG		229		//Set EMAIL Configuration

#define NET_DVR_GET_NFSCFG			230		// NFS disk configuration 
#define NET_DVR_SET_NFSCFG			231		// NFS disk configuration 

#define NET_DVR_GET_SHOWSTRING_EX	238		//Get Extended OSD Parameters 
#define NET_DVR_SET_SHOWSTRING_EX	239		//Set Extended OSD Parameters
#define NET_DVR_GET_NETCFG_OTHER	244		//Get Network Parameters
#define NET_DVR_SET_NETCFG_OTHER	245		//Set Network Parameters 

//NET_DVR_EMAILCFG
#define NET_DVR_GET_EMAILPARACFG	250		//Get EMAIL parameters
#define NET_DVR_SET_EMAILPARACFG	251		//Setup EMAIL parameters


#define NET_DVR_GET_DDNSCFG_EX		274		//Get Extended DDNS Parameters
#define NET_DVR_SET_DDNSCFG_EX		275		//Set Extended DDNS Parameters


#define	NET_DVR_SET_PTZPOS			292		//Set PTZ Position
#define	NET_DVR_GET_PTZPOS			293		//Get PTZ Position
#define	NET_DVR_GET_PTZSCOPE		294		//Get PTZ Scope

/*********************************Intelligent Traffic Event Begin***************************************/
#define NET_DVR_GET_REFERENCE_REGION        400     // Get reference region
#define NET_DVR_SET_REFERENCE_REGION        401     //Set reference region

#define NET_DVR_GET_TRAFFIC_MASK_REGION     402     //Get traffic event mask region
#define NET_DVR_SET_TRAFFIC_MASK_REGION     403     //Set traffic event mask region

// #define NET_DVR_GET_SCENE_MODE           404     // Get scenario mode
// #define NET_DVR_SET_SCENE_MODE           405     // Set scenario mode 

#define NET_DVR_SET_AID_RULECFG             404     // Set traffic event rule parameters
#define NET_DVR_GET_AID_RULECFG             405     // Get traffic event rule parameters

#define NET_DVR_SET_TPS_RULECFG             406     // Set traffic rule statistics
#define NET_DVR_GET_TPS_RULECFG             407     // Get traffic rule statistics

#define NET_DVR_SET_LANECFG			        408	    // Set traffic lane rules
#define	NET_DVR_GET_LANECFG			     	409		// Get traffic lane rules


/*********************************Intelligent traffic events end***************************************/
#define NET_DVR_SET_FACEDETECT_RULECFG      420      // Set face detection rule
#define NET_DVR_GET_FACEDETECT_RULECFG      421      // Get face detection rule

/***************************DS9000 New Commands (_V30)  begin *****************************/
//Network (NET_DVR_NETCFG_V30) 
#define NET_DVR_GET_NETCFG_V30		        1000     //Get  Network  Parameters
#define NET_DVR_SET_NETCFG_V30		        1001	 //Set  Network  Parameters

//Image (NET_DVR_PICCFG_V30) 
#define NET_DVR_GET_PICCFG_V30		        1002	 //Get Image Parameters
#define NET_DVR_SET_PICCFG_V30		        1003	 //Set Image Parameters

//Record (NET_DVR_RECORD_V30) 
#define NET_DVR_GET_RECORDCFG_V30	        1004   	 //Get Record Parameters
#define NET_DVR_SET_RECORDCFG_V30	        1005	 //Set Record Parameters

//User (NET_DVR_USER_V30) 
#define NET_DVR_GET_USERCFG_V30 	        1006	 //Get User Parameters
#define NET_DVR_SET_USERCFG_V30		        1007	 //Set User Parameters

//9000DDNS Config (NET_DVR_DDNSPARA_V30) 
#define NET_DVR_GET_DDNSCFG_V30		        1010	 //Get DDNS  (9000Extended) 
#define NET_DVR_SET_DDNSCFG_V30		        1011	 //Set DDNS  (9000Extended) 

//EMAIL  (NET_DVR_EMAILCFG_V30) 
#define NET_DVR_GET_EMAILCFG_V30		    1012	 //Get EMAIL Configuration
#define NET_DVR_SET_EMAILCFG_V30	    	1013	 //Set EMAIL Configuration

//Cruise  (NET_DVR_CRUISE_PARA) 
#define NET_DVR_GET_CRUISE		    		1020		
#define NET_DVR_SET_CRUISE					1021		


//Alarm input   (NET_DVR_ALARMINCFG_V30) 
#define NET_DVR_GET_ALARMINCFG_V30			1024		
#define NET_DVR_SET_ALARMINCFG_V30			1025

//Alarm output   (NET_DVR_ALARMOUTCFG_V30) 
#define NET_DVR_GET_ALARMOUTCFG_V30			1026		
#define NET_DVR_SET_ALARMOUTCFG_V30			1027

//Video output   (NET_DVR_VIDEOOUT_V30) 
#define NET_DVR_GET_VIDEOOUTCFG_V30			1028		
#define NET_DVR_SET_VIDEOOUTCFG_V30			1029	

//OSD   (NET_DVR_SHOWSTRING_V30) 
#define NET_DVR_GET_SHOWSTRING_V30			1030		
#define NET_DVR_SET_SHOWSTRING_V30			1031

//Exception   (NET_DVR_EXCEPTION_V30) 
#define NET_DVR_GET_EXCEPTIONCFG_V30		1034		
#define NET_DVR_SET_EXCEPTIONCFG_V30		1035

//RS232   (NET_DVR_RS232CFG_V30) 
#define NET_DVR_GET_RS232CFG_V30			1036		
#define NET_DVR_SET_RS232CFG_V30			1037

//Structure of Setting Network Hard Disk Drive   (NET_DVR_NET_DISKCFG struct) 
#define	NET_DVR_GET_NET_DISKCFG				1038		//Get the configuration of Network Hard Disk Drive	
#define	NET_DVR_SET_NET_DISKCFG				1039		//Set the configuration of Configuring Network Hard Disk Drive


//Encoding   (NET_DVR_COMPRESSIONCFG_V30) 
#define NET_DVR_GET_COMPRESSCFG_V30	        1040		
#define NET_DVR_SET_COMPRESSCFG_V30			1041		

//RS485   (NET_DVR_DECODERCFG_V30) 
#define NET_DVR_GET_DECODERCFG_V30			1042		//Get Decoder Parameters
#define NET_DVR_SET_DECODERCFG_V30			1043		//Set Decoder parameters

//Preview   (NET_DVR_PREVIEWCFG_V30) 
#define NET_DVR_GET_PREVIEWCFG_V30			1044		//Get Preview Parameters
#define NET_DVR_SET_PREVIEWCFG_V30			1045		//Set Preview Parameters

//AUX Preview  (NET_DVR_PREVIEWCFG_AUX_V30) 
#define NET_DVR_GET_PREVIEWCFG_AUX_V30		1046		//Get AUX Preview Parameters
#define NET_DVR_SET_PREVIEWCFG_AUX_V30		1047		//Set AUX Preview Parameters

//IP Channel Configuration  (NET_DVR_IPPARACFG) 
#define NET_DVR_GET_IPPARACFG				1048        //Get IP Channel Configuration info 
#define NET_DVR_SET_IPPARACFG				1049        //Set IP Channel Configuration info 

//IP Alarm In Configuration  (NET_DVR_IPALARMINCFG) 
#define NET_DVR_GET_IPALARMINCFG			1050        //Get IP Alarm In Configuration info
#define NET_DVR_SET_IPALARMINCFG			1051        //Set IP Alarm In Configuration info

//IP Alarm Out Configuration  (NET_DVR_IPALARMOUTCFG) 
#define NET_DVR_GET_IPALARMOUTCFG			1052        //Get IP Alarm Out Configuration info  
#define NET_DVR_SET_IPALARMOUTCFG			1053        //Set IP Alarm Out Configuration info 

//HD management Configuration  (NET_DVR_HDCFG) 
#define NET_DVR_GET_HDCFG					1054	    //Get HD management Configuration
#define NET_DVR_SET_HDCFG					1055	    //Get HD management Configuration

//HD Group Configuration  (NET_DVR_HDGROUP_CFG) 
#define NET_DVR_GET_HDGROUP_CFG				1056	    //Get HD Group Configuration Parameters
#define NET_DVR_SET_HDGROUP_CFG				1057	    //Set HD Group Configuration Parameters

//Device AudioTalk Configuration (NET_DVR_COMPRESSION_AUDIO) 
#define NET_DVR_GET_COMPRESSCFG_AUD			1058        //Get AudioTalk Configuration Parameters
#define NET_DVR_SET_COMPRESSCFG_AUD			1059        //Set AudioTalk Configuration Parameters

//2008- 08- 25
//IP Camera parameter (NET_DVR_IPPARACFG_V31 struct) 
#define NET_DVR_GET_IPPARACFG_V31			1060        //Get IP device parameter 
#define NET_DVR_SET_IPPARACFG_V31			1061        //Set IP device parameter 

//Channel resource configuration(NET_DVR_IPPARACFG_V40 structure)
#define NET_DVR_GET_IPPARACFG_V40            1062        // Get IP device parameter V40
#define NET_DVR_SET_IPPARACFG_V40            1063        // Set IP device parameter V40

//Multi network card parameter
#define NET_DVR_GET_NETCFG_MULTI			 1161        //Get multi network card parameter
#define NET_DVR_SET_NETCFG_MULTI			 1162        //Set multi network card parameter


//2009- 10- 26 snap device begin

#define NET_DVR_GET_CCDPARAMCFG              1067       //Get IPC CCD parameters
#define NET_DVR_SET_CCDPARAMCFG              1068       //Set IPC CCD parameters

#define NET_DVR_GET_IOINCFG		             1070       //Get I0 input parameters
#define NET_DVR_SET_IOINCFG		             1071	    //Set IO input parameters

#define NET_DVR_GET_IOOUTCFG		         1072       //Get I0 output parameters
#define NET_DVR_SET_IOOUTCFG		         1073	    //Set IP output parameters

#define NET_DVR_GET_FLASHCFG		         1074       //Get io flash parameters
#define NET_DVR_SET_FLASHCFG		         1075	    //Set io flash parameters

#define NET_DVR_GET_LIGHTSNAPCFG		     1076       //Get light parameters
#define NET_DVR_SET_LIGHTSNAPCFG	         1077	    //Set light parameters

#define NET_DVR_GET_MEASURESPEEDCFG		     1078       //Get measure speed parameters
#define NET_DVR_SET_MEASURESPEEDCFG		     1079	    //Set measure speed parameters

#define NET_DVR_GET_IMAGEOVERLAYCFG	         1080       //Get image overlay parameters
#define NET_DVR_SET_IMAGEOVERLAYCFG	         1081       //Set image overlay parameters

#define NET_DVR_GET_SNAPCFG	                 1082       //Get single IO parameters
#define NET_DVR_SET_SNAPCFG	                 1083       //Set single IO parameters

#define NET_DVR_GET_VTPPARAM		         1084       //Get virtual circuit parameters
#define NET_DVR_SET_VTPPARAM		         1085       //Set virtual circuit parameters
 
#define NET_DVR_GET_SNAPENABLECFG			 1086       //Get snap enable parameters
#define NET_DVR_SET_SNAPENABLECFG		     1087       //Set snap enable parameters

#define NET_DVR_GET_POSTEPOLICECFG           1088       //Get police parameters
#define NET_DVR_SET_POSTEPOLICECFG           1089       //Set police parameters

#define NET_DVR_GET_JPEGCFG_V30			     1090	    //Get JPEG parameters
#define NET_DVR_SET_JPEGCFG_V30				 1091	    //Set JPEG parameters

#define NET_DVR_GET_SPRCFG	                 1092       //Get configuration of license plate recognition
#define NET_DVR_SET_SPRCFG	                 1093       //Set configuration of license plate recognition

#define NET_DVR_GET_PLCCFG                   1094       //Get brightness compensation configuration of license plate
#define NET_DVR_SET_PLCCFG                   1095       //Set brightness compensation configuration of license plate

#define NET_DVR_GET_DEVICESTATECFG           1096       //Get current status of device

#define NET_DVR_GET_DEVICECFG_V40	         1100       //Get extended device parameters 
#define NET_DVR_SET_DEVICECFG_V40	         1101       //Set extended device parameters 

#define NET_DVR_GET_ZEROCHANCFG              1102    	//Get Zero channel compression parameters
#define NET_DVR_SET_ZEROCHANCFG  	         1103	    //Set Zero channel compression parameters

#define NET_DVR_GET_ZERO_PREVIEWCFG_V30      1104       //Get Zero channel live view parameters
#define NET_DVR_SET_ZERO_PREVIEWCFG_V30      1105       //Set Zero channel live view parameters


#define NET_DVR_SET_ZERO_ZOOM	             1106       //Set Zero channel zoom configuration 
#define NET_DVR_GET_ZERO_ZOOM            	 1107       //Get Zero channel zoom configuration 

//2010- 04- 13 Add NAT configuration
#define	NET_DVR_NATASSOCIATECFG_GET          1110       //Get NAT function configuration info
#define	NET_DVR_NATASSOCIATECFG_SET	         1111       //Set NAT function configuration info

#define NET_DVR_GET_SNMPCFG   	             1112       //Get SNMP parameters
#define NET_DVR_SET_SNMPCFG  	             1113       //Set SNMP parameters

#define NET_DVR_GET_SNMPCFG_V30   			 1114        //Get SNMPv30 parameters 
#define NET_DVR_SET_SNMPCFG_V30  			 1115        //Set SNMPv30 parameters

//2010- 06- 01 Video Management System alarm configuration
#define	NET_DVR_VIDEOPLATFORMALARMCFG_GET 	 1130       //Get Video Management System alarm configuration
#define	NET_DVR_VIDEOPLATFORMALARMCFG_SET	 1131       //Set Video Management System alarm configuration

#define NET_DVR_GET_RAID_ADAPTER_INFO        1134       //Get RAID adapter's information
#define NET_DVR_SET_RAID_ADAPTER_INFO        1135       //Get adapter information
//Big Screen Splice
#define	NET_DVR_MATRIX_BIGSCREENCFG_GET		 1140       //Get Parameter
#define	NET_DVR_MATRIX_BIGSCREENCFG_SET		 1141	    //Set Parameter

#define NET_DVR_SET_SENSOR_CFG				 1180       //Set sensor parameter 
#define NET_DVR_GET_SENSOR_CFG				 1181       //Get sensor parameter 
#define NET_DVR_SET_ALARMIN_PARAM			 1182		//Set alarm input parameter 
#define NET_DVR_GET_ALARMIN_PARAM			 1183		//Get alarm input parameter 
#define NET_DVR_SET_ALARMOUT_PARAM			 1184		//Set alarm output parameter 
#define NET_DVR_GET_ALARMOUT_PARAM			 1185		//Get alarm output parameter 
#define NET_DVR_SET_SIREN_PARAM				 1186		//Set siren parameter 
#define NET_DVR_GET_SIREN_PARAM				 1187		//Get siren parameter 
#define NET_DVR_SET_ALARM_RS485CFG			 1188		//Set alarm host RS-485 parameter 
#define NET_DVR_GET_ALARM_RS485CFG			 1189		//Get alarm host RS-485 parameter 
#define NET_DVR_GET_ALARMHOST_MAIN_STATUS	 1190		//Get alarm host main status 
#define NET_DVR_GET_ALARMHOST_OTHER_STATUS	 1191		//Get alarm host other status
#define NET_DVR_SET_ALARMHOST_ENABLECFG		 1192		//Set alarm host enable status
#define NET_DVR_GET_ALARMHOST_ENABLECFG	     1193		//Get alarm host enable status
#define NET_DVR_SET_ALARM_CAMCFG			 1194		//Set configation of video integrated platform alarm triggering CAM operation
#define NET_DVR_GET_ALARM_CAMCFG			 1195		//Get configation of video integrated platform alarm triggering CAM operation
#define NET_DVR_GET_GATEWAY_CFG              1196       //Get gateway configuration 
#define NET_DVR_SET_GATEWAY_CFG              1197       //Set gateway configuration
#define NET_DVR_GET_ALARMDIALMODECFG		 1198		//Get alarm dial parameter
#define NET_DVR_SET_ALARMDIALMODECFG		 1199		//Set alarm dial parameter
#define NET_DVR_GET_ALARMHOSTDIALSETUPMODE	 1204		//Get alarm dial setup mode
#define NET_DVR_SET_ALARMHOSTDIALSETUPMODE	 1205		//Set alarm dial setup mode

#define NET_DVR_GET_HOLIDAY_PARAM_CFG        1240       //Get holiday parameter
#define NET_DVR_SET_HOLIDAY_PARAM_CFG        1241       //Set holiday parameter

#define NET_DVR_GET_MOTION_HOLIDAY_HANDLE    1242       //Get holiday alarm handling mode of motion detection
#define NET_DVR_SET_MOTION_HOLIDAY_HANDLE    1243       //Set holiday alarm handling mode of motion detection

#define NET_DVR_GET_VILOST_HOLIDAY_HANDLE    1244       //Get holiday alarm handling mode of video signal lost
#define NET_DVR_SET_VILOST_HOLIDAY_HANDLE    1245       //Set holiday alarm handling mode of video signal lost

#define NET_DVR_GET_HIDE_HOLIDAY_HANDLE      1246       //Get holiday alarm handling mode of video tampering
#define NET_DVR_SET_HIDE_HOLIDAY_HANDLE      1247       //Set holiday alarm handling mode of video tampering

#define NET_DVR_GET_ALARMIN_HOLIDAY_HANDLE   1248       //Get holiday alarm handling mode of alarm input
#define NET_DVR_SET_ALARMIN_HOLIDAY_HANDLE   1249       //Set holiday alarm handling mode of alarm input

#define NET_DVR_GET_ALARMOUT_HOLIDAY_HANDLE  1250       //Get holiday alarm handling mode of alarm output
#define NET_DVR_SET_ALARMOUT_HOLIDAY_HANDLE  1251       //Set holiday alarm handling mode of alarm output

#define NET_DVR_GET_HOLIDAY_RECORD           1252       //Get holiday recording parameter
#define NET_DVR_SET_HOLIDAY_RECORD           1253       //Set holiday recording parameter

#define NET_DVR_GET_NETWORK_BONDING          1254       //Get BONDING network card parameter
#define NET_DVR_SET_NETWORK_BONDING          1255       //Set BONDING network card parameter

#define NET_DVR_GET_LINK_STATUS              1256       //Get link status of channel

#define NET_DVR_GET_DISK_QUOTA_CFG           1278       //Get disk quota configuration
#define NET_DVR_SET_DISK_QUOTA_CFG           1279       //Set disk quota configuration

#define NET_DVR_GET_JPEG_CAPTURE_CFG         1280       //Get capture configuration
#define NET_DVR_SET_JPEG_CAPTURE_CFG         1281       //Set capture configuration

#define NET_DVR_GET_SCHED_CAPTURECFG         1282       //Get capture schedule configuration
#define NET_DVR_SET_SCHED_CAPTURECFG         1283       //Set capture schedule configuration

#define NET_DVR_GET_VGA_PREVIEWCFG           1284       //Get VGA preview configuration
#define NET_DVR_SET_VGA_PREVIEWCFG           1285       //Set VGA preview configuration 

#define NET_DVR_GET_VIDEO_INPUT_EFFECT       1286       //Get the video effect
#define NET_DVR_SET_VIDEO_INPUT_EFFECT       1287       //Set the video effect

#define NET_DVR_GET_OPTICAL_CHANNEL			 1300		//Get coder subsystem optical channel relation
#define NET_DVR_SET_OPTICAL_CHANNEL			 1301		//Set coder subsystem optical channel relation
#define NET_DVR_GET_FIBER_CASCADE			 1302		//Get fiber cascade mode
#define NET_DVR_SET_FIBER_CASCADE			 1303		//Set fiber cascade mode
#define NET_DVR_GET_SPARTAN_STATUS			 1304		//Get spatan status
#define NET_DVR_SET_SPARTAN_STATUS			 1305		//Set spatan status
#define NET_DVR_GET_ETHERNET_CHANNEL		 1306		//Get ethernet channel configuration
#define NET_DVR_SET_ETHERMET_CHANNEL		 1307		//Set ethernet channel configuration
#define NET_DVR_OPTICAL_REBOOT				 1320		//Reboot optical transceiver

#define	NET_DVR_V6PSUBSYSTEMARAM_GET		 1501		//get V6 subsystem config
#define	NET_DVR_V6PSUBSYSTEMARAM_SET		 1502		//set V6 subsystem config
#define	NET_DVR_GET_ALLWINCFG		         1503		//get screen window information
#define	NET_DVR_GETSCREENINFO				 1601		//Get big screen information
#define	NET_DVR_SETSCREENINFO				 1602		//Set big screen information
#define	NET_DVR_GET_SCREEN_WINCFG			 1603		//Get single window parameter 
#define	NET_DVR_LAYOUTLIST_GET 				 1605		//Get layout list
#define	NET_DVR_SET_LAYOUTCFG				 1606		//Set layout
#define	NET_DVR_LAYOUTCTRL					 1607		//Layout control，1-open，2-close
#define	NET_DVR_INPUTLIST_GET				 1608		//Get signal source list
#define	NET_DVR_SET_INPUTSTREAMCFG			 1609		//Set signal source
#define	NET_DVR_OUTPUT_SET					 1610		//Set output parameter
#define	NET_DVR_OUTPUT_GET					 1611		//Get output parameter
//2011-11-2
#define	NET_DVR_SET_OSDCFG					 1612		//Set OSD parameter
#define	NET_DVR_GET_OSDCFG					 1613		//Get OSD parameter
#define	NET_DVR_BIGSCREEN_GETSERIAL			 1614		//Get serial information

#define	NET_DVR_SET_PLAN					 1616		//set plan
#define	NET_DVR_CTRL_PLAN					 1617		//control plan
#define	NET_DVR_GET_DEVICE_RUN_STATUS		 1618		//get the running status of the device

/********************************dvcs begin****************************/
/*1650~1700*/
#define NET_DVR_GET_DEV_BASEINFO			 1650		// get single sub device base information
#define NET_DVR_SET_DEV_BASEINFO			 1651		// set single sub device base information
#define NET_DVR_GET_DEV_NETINFO				 1652		// get single sub device net information
#define NET_DVR_SET_DEV_NETINFO				 1653		// set single sub device net information
#define NET_DVR_GET_SIGNAL_SOURCE_INFO		 1654		// get signal source information
#define NET_DVR_SET_SIGNAL_SOURCE_INFO		 1655		// set signal source information
#define NET_DVR_ADJUST_PIC_V40				 1656		// adjust picture
#define NET_DVR_RESTORE_V40					 1657		// restore default
#define	NET_DVR_SET_NET_SIGNAL				 1658		// set net signal
#define NET_DVR_REBOOT_V40					 1659		// reboot 
#define NET_DVR_GET_AUTO_REBOOT_CFG          1710       // get auto reboot config
#define NET_DVR_SET_AUTO_REBOOT_CFG          1711       // set auto reboot config

#define NET_DVR_GET_ALARMHOSTSUBSYSTEM_CFG	 2001		//	Get alarm subsystem
#define NET_DVR_SET_ALARMHOSTSUBSYSTEM_CFG	 2002		//	Set alarm subsystem
#define NET_DVR_GETEXTENDALARMININFO    	 2003		//	Get alarm info
#define NET_DVR_MODIFYALARMINNO 	         2004		//	mod alarm info

#define NET_DVR_GET_ALARMHOST_GPRSCFG		 2005		// Get GPRS info
#define	NET_DVR_SET_ALARMHOST_GPRSCFG		 2006		// Set GPRS info
#define	NET_DVR_GET_ALARMHOST_NETCFG		 2007		// Get Net info
#define	NET_DVR_SET_ALARMHOST_NETCFG		 2008		// Set Net info

#define 	NET_DVR_GET_LED_SCREEN_CFG		2009	// Get LED Parameter
#define 	NET_DVR_SET_LED_SCREEN_CFG		2010	// Set LED Parameter
#define 	NET_DVR_GET_LED_CONTENT_CFG		2011	// Get LED Content
#define		NET_DVR_SET_LED_CONTENT_CFG		2012	// Set LED Content
#define 	NET_DVR_TURNON_LED				2013	// turn on LED
#define 	NET_DVR_TURNOFF_LED				2014	// turn off LED
#define 	NET_DVR_GET_LED_TIMER_SWITCH	2015	// Get LED timer switch
#define 	NET_DVR_SET_LED_TIMER_SWITCH	2016	// Set LED timer switch
#define 	NET_DVR_SET_LED_BRIGHTNESS		2017	// set LED brightness
#define 	NET_DVR_GET_LED_TIMER_BRIGHTNESS		2018	// set timer brightness
#define 	NET_DVR_SET_LED_TIMER_BRIGHTNESS		2019	// get timer brightness
#define 	NET_DVR_LED_CHECKTIME			2020	// LED checktime
#define		NET_DVR_GET_LED_STATUS			2023		//get LED status

#define 	NET_DVR_GET_ALARMHOST_AUDIO_ASSOCIATE_ALARM		2021 //获取音频跟随报警事件
#define 	NET_DVR_SET_ALARMHOST_AUDIO_ASSOCIATE_ALARM		2022 //设置音频跟随报警事件

//2009-2020，2023 use for DS-19C08-JN V2.0
#define 	NET_DVR_GET_ALARMHOST_AUDIO_ASSOCIATE_ALARM		2021 //Get audio associate alarm
#define 	NET_DVR_SET_ALARMHOST_AUDIO_ASSOCIATE_ALARM		2022 //set audio associate alarm

#define NET_ITC_GET_TRIGGERCFG               3003       //Get trigger configuration
#define NET_ITC_SET_TRIGGERCFG               3004		//Set trigger configuration
#define NET_ITC_GET_IOOUT_PARAM_CFG	         3005		//Get io out configuration(3.1)
#define NET_ITC_SET_IOOUT_PARAM_CFG	         3006		//Set io out configuration(3.1)
#define NET_ITC_GET_TRIGGER_DEFAULTCFG       3013		//Get trigger default configuration
#define NET_DVR_GET_STATUS_DETECTCFG         3015		//Get status detect configuration
#define NET_DVR_SET_STATUS_DETECTCFG         3016		//Set statue detect configuration
#define NET_ITC_GET_VIDEO_TRIGGERCFG         3017		//Get video epolice configuration
#define NET_ITC_SET_VIDEO_TRIGGERCFG         3018		//Set video epolice configuration
#define NET_DVR_GET_REDAREACFG               3100		//Get red area configuration
#define NET_DVR_SET_REDAREACFG               3101		//Set red area configuration

#define NET_DVR_GET_AUDIO_INPUT              3201		//Get audio in info
#define NET_DVR_SET_AUDIO_INPUT              3202		//Set audio in info
#define NET_DVR_GET_CAMERA_DEHAZE_CFG        3203		//Get fog remove configuration
#define NET_DVR_SET_CAMERA_DEHAZE_CFG        3204		//Set fog remove configuration
#define NET_DVR_REMOTECONTROL_ALARM          3205		//remote control alarm
#define NET_DVR_REMOTECONTROL_DISALARM       3206		//remote control disalarm
#define NET_DVR_REMOTECONTROL_STUDY          3207		//remote control study
#define NET_DVR_WIRELESS_ALARM_STUDY         3208		//wireless alarm study
#define NET_IPC_GET_AUX_ALARMCFG             3209		//get aux alarm configuration
#define NET_IPC_SET_AUX_ALARMCFG             3210		//set aux alarm configuration
#define NET_DVR_GET_PREVIEW_DISPLAYCFG	     3211		//Get preview shows the parameters
#define NET_DVR_SET_PREVIEW_DISPLAYCFG	     3212		//Set preview shows the parameters
#define NET_DVR_REMOTECONTROL_PTZ            3213       //Remote control of PTZ
#define NET_DVR_REMOTECONTROL_PRESETPOINT    3214       //Remote Control preset point
#define NET_DVR_REMOTECONTROL_CRUISE         3215       //Remote control cruise

#define NET_DVR_GET_WPSCFG	                 3218		//Get WPS configuration
#define NET_DVR_SET_WPSCFG	                 3219		//Set WPS configuration
#define NET_DVR_WPS_CONNECT                  3220		//WPS connect
#define NET_DVR_GET_DEVICE_PIN               3221		//Get device PIN
#define NET_DVR_UPDATE_PIN                   3223		//Update device PIN
#define NET_DVR_GET_PRESETCFG                3224		//Get preset point parameters
#define NET_DVR_GET_PTZCRUISECFG			 3225		//Get cruise path parameters
#define NET_DVR_GET_PRESET_NUM				 3226		//Access to preset point number
#define NET_DVR_GET_PTZCRUISE_NUM			 3227		//Access to the cruise path number

#define NET_DVR_GET_MOTION_TRACK_CFG		 3228		//Access to track parameters
#define NET_DVR_SET_MOTION_TRACK_CFG		 3229		//Set the track parameter

#define NET_DVR_GET_IPADDR_FILTERCFG		 3232		//Get IP address filter
#define NET_DVR_SET_IPADDR_FILTERCFG		 3233		//Set IP address filter

#define NET_DVR_GET_LOGO_OVERLAYCFG	         3234       //Get LOGO overlay configuration 
#define NET_DVR_SET_LOGO_OVERLAYCFG	         3235       //Set LOGO overlay configuration

#define NET_DVR_GET_FACESNAPCFG              5001       //Get face snap configuration
#define NET_DVR_SET_FACESNAPCFG              5002       //Set face snap configuration
#define NET_DVR_GET_DEVACCESS_CFG            5005       //Get device access configuration
#define NET_DVR_SET_DEVACCESS_CFG            5006       //Set device access configuration
#define NET_DVR_GET_SAVE_PATH_CFG            5007       //Get storage information parameter
#define NET_DVR_SET_SAVE_PATH_CFG            5008       //Set storage information parameter
#define NET_VCA_GET_RULECFG_V41			     5011		//Get behavior analysis parameters (extended)
#define NET_VCA_SET_RULECFG_V41			     5012		//Set behavior analysis parameters (extended)

/********************************ITS****************************/
#define NET_ITS_GET_BASE_INFO		         5060		//Get ITS base information
#define NET_ITS_GET_IMGMERGE_CFG	         5063		//Get image merge configuration
#define NET_ITS_SET_IMGMERGE_CFG			 5064		//Set image merge configuration
#define NET_ITS_GET_UPLOAD_CFG				 5065		//Get upload data configuration
#define NET_ITS_SET_UPLOAD_CFG				 5066		//Set upload data configuration
#define NET_ITS_GET_WORKSTATE				 5069		//Get ITS work state
#define NET_ITS_GET_IPC_CHAN_CFG			 5070		//Get ITS IPC channel configuration
#define NET_ITS_SET_IPC_CHAN_CFG			 5071		//Set ITS IPC channel configuration
#define NET_ITS_GET_OVERLAP_CFG				 5072		//Get overlap configuration
#define NET_ITS_SET_OVERLAP_CFG				 5073		//Set overlap configuration
#define NET_ITS_GET_ROAD_INFO				 5076		//Get road information
//NVR which has 64 IPC: Get the information of disk raid.
#define NET_DVR_GET_DISK_RAID_INFO			 6001       //Get the information of disk raid
#define NET_DVR_SET_DISK_RAID_INFO			 6002       //Set the information of disk raid
#define NET_DVR_GET_DVR_SYNCHRONOUS_IPC      6005       //Set the parameter which is used to synchronise IPC.
#define NET_DVR_SET_DVR_SYNCHRONOUS_IPC      6006       //Get the parameter which is used to synchronise IPC.
#define NET_DVR_SET_DVR_IPC_PASSWD			 6008		//Set the password of IPC.
#define NET_DVR_GET_DEVICE_NET_USING_INFO	 6009		//Get the using information of device net.
#define NET_DVR_SET_DVR_IPC_NET              6012		//Set the IP of IPC.
#define NET_DVR_GET_RECORD_CHANNEL_INFO      6013		//Get record channel information
#define NET_DVR_SET_RECORD_CHANNEL_INFO      6014		//Set record channel information

#define NET_DVR_MOUNT_DISK					 6015       // Mount disk
#define NET_DVR_UNMOUNT_DISK				 6016       // Unmount disk

// CVR 
#define NET_DVR_GET_STREAM_SRC_INFO			 6017		//Get stream source information
#define NET_DVR_SET_STREAM_SRC_INFO			 6018		//Set stream source information
#define NET_DVR_GET_STREAM_RECORD_INFO		 6019		//Get stream record information
#define NET_DVR_SET_STREAM_RECORD_INFO		 6020		//Set stream record information
#define NET_DVR_GET_STREAM_RECORD_STATUS	 6021		//Get stream record status
#define NET_DVR_SET_STREAM_RECORD_STATUS	 6022		//Set stream record status

//NVR：96xx
#define NET_DVR_GET_IP_ALARM_GROUP_NUM		 6100  
#define NET_DVR_GET_IP_ALARM_IN				 6101  
#define NET_DVR_GET_IP_ALARM_OUT			 6102

#define NET_DVR_GET_ACCESS_CAMERA_INFO			6201		// Get access camera information
#define LONG_CFG_TYPE_SET_ACCESS_CAMERA_INFO    6202		// Set access camera information
#define LONG_CFG_TYPE_PULL_DISK					6203		// Pull disk
#define LONG_CFG_TYPE_SCAN_RAID					6204		// Scan raid

//9000 v2.2
#define NET_DVR_GET_FTPCFG_SECOND			 6103  		//Get FTP parameter to which upload the picture
#define NET_DVR_SET_FTPCFG_SECOND			 6104  		//Set FTP parameter to which upload the picture

#define NET_DVR_GET_DEFAULT_VIDEO_EFFECT	 6105		//Get default video effect
#define NET_DVR_SET_VIDEO_EFFECT			 6106       //Set video effect

#define NET_DVR_DEL_INVALID_DISK			 6107       // Delete invalid disk

#define NET_DVR_GET_DRAWFRAME_DISK_QUOTA_CFG 6109		//Get disk quota of frame extracting channel
#define NET_DVR_SET_DRAWFRAME_DISK_QUOTA_CFG 6110		//Set disk quota of frame extracting channel

#define NET_DVR_GET_UPNP_CFG                 6111       //Get UPNP parameter
#define NET_DVR_SET_UPNP_CFG                 6112       //Set UPNP parameter  

#define NET_DVR_GET_AES_KEY                  6113       //Get device's AES key

#define NET_DVR_GET_POE_CFG                  6114		//Get POE parameter
#define NET_DVR_SET_POE_CFG                  6115		//Set POE parameter

#define NET_DVR_GET_CUSTOM_PRO_CFG           6116		//Get customized protocol parameter 
#define NET_DVR_SET_CUSTOM_PRO_CFG           6117		//Set customized protocol parameter  

#define NET_DVR_GET_STREAM_CABAC			 6118		//Get Stream CABAC
#define NET_DVR_SET_STREAM_CABAC			 6119		//Set Stream CABAC

#define NET_DVR_GET_ESATA_MINISAS_USAGE_CFG	 6120		//Get eSATA & miniSAS usage
#define NET_DVR_SET_ESATA_MINISAS_USAGE_CFG	 6121		//Set eSATA & miniSAS usage

#define NET_DVR_GET_HDCFG_V40				 6122		//Get hard disk info
#define NET_DVR_SET_HDCFG_V40				 6123		//Set hard disk info

#define NET_DVR_GET_POE_CHANNEL_ADD_MODE     6124		//Get POE channel add mode
#define NET_DVR_SET_POE_CHANNEL_ADD_MODE     6125		//Set POE channel add mode

#define NET_DVR_GET_DIGITAL_CHANNEL_STATE    6126		//Get digital channel state

#define NET_DVR_GET_OUTPUT_CFG               6401       //get output config
#define NET_DVR_SET_OUTPUT_CFG               6402       //set output config
#define NET_DVR_CODER_DISPLAY_START          6403       //start display
#define NET_DVR_CODER_DISPLAY_STOP           6404       //stop display
#define NET_DVR_GET_WINDOW_STATUS            6405       //get display window status

#define NET_DVR_GET_ISCSI_CFG                11070      //Get ISCSI storage configuration protocol 
#define NET_DVR_SET_ISCSI_CFG                11071      //Set ISCSI storage configuration protocol 

// American branch office coustom
#define NET_DVR_GET_MEMU_OUTPUT_MODE		0x26001		//Get menu output mode
#define NET_DVR_SET_MEMU_OUTPUT_MODE		0x26002		//Set menu output mode

/***************************DS9000 New Commands (_V30)  end *****************************/

/*************************Parameter Configure Commands end*******************************/

/*******************Return Value of File&Log Query API*************************/
#define NET_DVR_FILE_SUCCESS			1000	//Get log information
#define NET_DVR_FILE_NOFIND				1001	//No log
#define NET_DVR_ISFINDING				1002	//On searching
#define	NET_DVR_NOMOREFILE				1003	//No more files
#define	NET_DVR_FILE_EXCEPTION			1004	//Error on log query

//alarm of plate: NET_DVR_PLATE_RESULT

/*************Operation Exception**********************/
#define EXCEPTION_EXCHANGE				0x8000	//Network user exception
#define EXCEPTION_AUDIOEXCHANGE			0x8001	//Network voice talk exception
#define EXCEPTION_ALARM					0x8002	//Alarm exception
#define EXCEPTION_PREVIEW				0x8003	//Network preview exception
#define EXCEPTION_SERIAL				0x8004	//Transparent channel exception
#define EXCEPTION_RECONNECT				0x8005	//Network preview reconnected
#define EXCEPTION_ALARMRECONNECT		0x8006	//Alarm reconnected
#define EXCEPTION_SERIALRECONNECT		0x8007	//Transparent channel reconnected
#define SERIAL_RECONNECTSUCCESS			0x8008	//Transparent reconnected success
#define EXCEPTION_PLAYBACK				0x8010	//Playback exception
#define EXCEPTION_DISKFMT				0x8011	//Hard Disk format exception
#define EXCEPTION_PASSIVEDECODE			0x8012  //Passive decode exception
#define EXCEPTION_EMAILTEST				0x8013  //Email test exception    
#define EXCEPTION_BACKUP				0x8014  //Backup exception
#define PREVIEW_RECONNECTSUCCESS		0x8015  //Network preview reconnected successfully
#define ALARM_RECONNECTSUCCESS			0x8016  //Alarm reconnected successfully
#define RESUME_EXCHANGE					0x8017	//User interaction resume

#define NETWORK_FLOWTEST_EXCEPTION      0x8018  // Network flow exception
//2011-11-24
#define EXCEPTION_PICPREVIEWRECONNECT	0x8019	//Picture Preview reconnect
#define PICPREVIEW_RECONNECTSUCCESS		0x8020	//Picture Preview reconnect successfully
#define EXCEPTION_PICPREVIEW			0x8021	//Picture Preview exception
/********************Preview Callback Function*********************/
#define NET_DVR_SYSHEAD					1	//System header
#define NET_DVR_STREAMDATA				2	//stream data
#define NET_DVR_AUDIOSTREAMDATA			3	//Audio Stream data
#define NET_DVR_STD_VIDEODATA			4	//Standard video stream data
#define NET_DVR_STD_AUDIODATA			5	//Standard audio stream data 
#define NET_DVR_CHANGE_FORWARD			10  //stream change from reverse to forward  
#define NET_DVR_CHANGE_REVERSE			11  //stream change from forward to reverse
#define NET_DVR_PRIVATE_DATA			112 //Private data

/******************************Abilities Set*********************************/
//Capabilities
#define DEVICE_SOFTHARDWARE_ABILITY   0x001  //Software / hardware abilities of the device
#define DEVICE_NETWORK_ABILITY        0x002  //Network abilities of the device
#define DEVICE_ENCODE_ALL_ABILITY     0x003  //Encode abilities of the device
#define	DEVICE_ENCODE_CURRENT         0x004  //Current encode ability of the device
#define IPC_FRONT_PARAMETER		      0x005	 //Network camera parameters
#define IPC_UPGRADE_DESCRIPTION		  0x006	 //Network camera upgrade info
#define DEVICE_RAID_ABILITY           0x007  //RAID 
#define DEVICE_ENCODE_ALL_ABILITY_V20 0x008	 //Encode abilities of the device 2.0
#define IPC_FRONT_PARAMETER_V20		  0x009	 //Network camera parameters 2.0
#define DEVICE_ALARM_ABILITY          0x00a  //alarm ability
#define DEVICE_DYNCHAN_ABILITY		  0x00b  //device dyn channel ability
#define DEVICE_USER_ABILITY           0x00c  //user ability
#define DEVICE_NETAPP_ABILITY         0x00d  //net app ability
#define DEVICE_VIDEOPIC_ABILITY       0x00e  //video picture ability
#define DEVICE_JPEG_CAP_ABILITY       0x00f  //JPEG capture ability
#define DEVICE_SERIAL_ABILITY         0x010  //RS232 and RS485 ability
#define VCA_DEV_ABILITY 	          0x100  //Intelligent analysis ability of the device
#define VCA_CHAN_ABILITY              0x110  //VCA ability of the device
#define MATRIXDECODER_ABILITY         0x200  //display and decoding ability of the multi-channel decoder
#define VIDEOPLATFORM_ABILITY         0x210  //Ability set of video management system
#define MATRIXDECODER_ABILITY_V41     0x260  //decoder ability
#define DECODER_ABILITY               0x261  //decoder ability
#define CODECARD_ABILITY              0x271  //coder card server ability
#define SNAPCAMERA_ABILITY            0x300  //Ability set for the camera
#define ITC_TRIGGER_MODE_ABILITY      0x301  //IPC Trigger mode ability
#define COMPRESSIONCFG_ABILITY        0x400  //Get compression parameter abilities
#define COMPRESSION_LIMIT             0x401  //get compression ability between main and sub stream
#define PIC_CAPTURE_ABILITY           0x402  //get picture capture ability 
#define IT_DEVICE_ABILITY             0x501  //ITS ability
#define	SCREENCONTROL_ABILITY		  0x600  //Ability of screen controller
#define	SCREENSERVER_ABILITY		  0x610  //Ability of screen server
#define FISHEYE_ABILITY               0x700   //Fisheye ability

//alarm callback
#define COMM_ALARM					  0x1100	//8000 Upload alarm message
//corresponding to NET_DVR_PLATE_RESULT
#define COMM_ALARM_PLATE			  0x1101  //LPR alarm info
//corresponding to NET_VCA_RULE_ALARM
#define COMM_ALARM_RULE				  0x1102  //VCA alarm info
#define COMM_ALARM_PDC                0x1103  // PDC alarm info
#define COMM_ALARM_AID                0x1110  // Traffic event alarm info
#define COMM_ALARM_VIDEOPLATFORM      0x1104  // Video Management System alarm
#define COMM_ALARM_ALARMHOST          0x1105  // Network alarm host alarm 
#define COMM_ALARM_FACE               0x1106  // Face detection recognition alarm information
#define COMM_RULE_INFO_UPLOAD         0x1107  // Event data information upload
#define COMM_ALARM_AID                0x1110  // Traffic event alarm info
#define COMM_ALARM_TPS                0x1111  // Traffic statistics alarm info
#define COMM_UPLOAD_FACESNAP_RESULT   0x1112  //Upload face snap result
#define COMM_SENSOR_VALUE_UPLOAD	  0x1120  // Sensor data realtime upload
#define COMM_SENSOR_ALARM          	  0x1121  // Analog alarm upload
#define COMM_SWITCH_ALARM			  0x1122	
#define COMM_ALARMHOST_EXCEPTION      0x1123  // Alarm host exception alarm
#define COMM_ALARMHOST_SAFETYCABINSTATE 0x1125	//SafetyCabin State
#define COMM_ALARMHOST_ALARMOUTSTATUS 0x1126	//Alarm Out Status
#define	COMM_TRADEINFO				  0x1500  //ATM DVR transaction information
//NET_DVR_PLATE_RESULT
#define COMM_UPLOAD_PLATE_RESULT	  0x2800  //Uploaded License info
#define COMM_ITC_STATUS_DETECT_RESULT 0x2810  //status detect
#define COMM_IPC_AUXALARM_RESULT      0x2820  //PIR alarm\wireless alarm\callhelp alarm
#define COMM_SNAP_MATCH_ALARM         0x2902  //blacklist comparison result upload
#define COMM_ITS_PLATE_RESULT  	      0x3050  //ITS plate result upload
#define	COMM_ITS_TRAFFIC_COLLECT	  0x3051  //ITS traffic collect upload
#define COMM_ALARM_V30				  0x4000	//9000 upload alarm message
#define COMM_IPCCFG					  0x4001	//9000 IPC configuration changed,  upload with push mode
#define COMM_IPCCFG_V31				  0x4002	//Initiative alarm upload when IPC connection configuration changes on 9000 device,  extended for 9000_1.1
#define COMM_IPCCFG_V40				  0x4003  //Alarm information upload when IPC connection configuration of IVMS-2000 or NVR changes
#define	COMM_ITS_ROAD_EXCEPTION		  0x4500  //ITS road exception upload
#define	COMM_SCREEN_ALARM			  0x5000  //Alarm type
#define COMM_DVCS_STATE_ALARM		  0x5001  // alarm of dvcs
/* Device model*/
#define DVR							1				//Undefined DVR
#define ATMDVR						2				//ATM DVR
#define DVS							3				//DVS
#define DEC							4				//6001DI 
#define ENC_DEC						5				//6001FI 
#define DVR_HC						6				//8000HCI
#define DVR_HT						7				//8000HTI
#define DVR_HF						8				//8000HFI
#define DVR_HS						9				//8000HSI DVR (no audio) 
#define DVR_HTS						10              //8016HTS DVR (no audio) 
#define DVR_HB						11              //HB DVR (SATA HD)  
#define DVR_HCS						12              //8000HCS DVR 
#define DVS_A						13              //DVS with ATA Hard disk 
#define DVR_HC_S					14              //8000HCI- S 
#define DVR_HT_S					15              //8000HTI- S 
#define DVR_HF_S					16              //8000HFI- S 
#define DVR_HS_S					17              //8000HSI- S 
#define ATMDVR_S					18              //ATM- S 
#define DVR_7000H					19				//7000HI Series
#define DEC_MAT						20              //Multichannel Decoder
#define DVR_MOBILE					21				//Mobile DVR           
#define DVR_HD_S					22              //8000HDI- S 
#define DVR_HD_SL					23				//8000HDI- SL
#define DVR_HC_SL					24				//8000HCI- SL
#define DVR_HS_ST					25				//8000HSI- ST
#define DVS_HW						26              //6000HW 
#define DS630X_D					27				//DS630X_DI
#define DS640X_HD					28				//DS640X_HDI
#define DS610X_D                    29              //610X Decoder
#define IPCAM						30				//IP Camera
#define MEGA_IPCAM					31				//Mega Pixels IP Camera
#define IPCAM_X62MF					32				//862MF IP Camera
#define ITCCAM                      35              //ITC Camera
#define IVS_IPCAM                   36              //VCA ITC Camera
#define ZOOMCAM                     38              //ZOOM Camera
#define IPDOME                      40     			//IP Speed Dome
#define IPDOME_MEGA200              41     			//Mega Pixels IP Dome (2 million) 
#define IPDOME_MEGA130              42     			//Mega Pixels IP Dome (1.3 million) 
#define IPDOME_AI                   43              //IP AI Dome
#define TII_IPCAM                   44              //Thermal infrared imaging IP camera
#define IPMOD						50				//IP Model
#define IDS6101_HF_A                61              //61ATM
#define IDS6002_HF_B                62              //Tracked by two camera:  iDS6002- HF/B
#define IDS6101_HF_B	            63              //VCA:  iDS6101- HF/B
#define IDS52XX		                64              //Intelligent Analysis:  IVMS
#define IDS90XX						65				//9000 with intelligent function
#define IDS8104_AHL_S_HX            66              //Face Recognition ATM
#define IDS8104_AHL_S_H             67              //Private Face Recognition ATM
#define IDS91XX						68				//9100 with intelligent function
#define IIP_CAM_B                   69              //intelligent behavior analyze IP camera
#define IIP_CAM_F                   70              //intelligent face analyze IP camera
#define DS71XX_H					71				//DS71XXHI_S 
#define DS72XX_H_S					72				//DS72XXHI_S 
#define DS73XX_H_S					73				//DS73XXHI_S 
#define DS72XX_HF_S                 74              //DS72XX_HF_S
#define DS73XX_HFI_S                75              //DS73XX_HFI_S
#define DS76XX_H_S					76				//DVR, e.g. DS7604_HI_S 
#define DS76XX_N_S					77				//NVR, e.g. DS7604_NI_S 
#define DS81XX_HS_S					81				//DS81XX_HSI_S 
#define DS81XX_HL_S					82				//DS81XX_HLI_S 
#define DS81XX_HC_S					83				//DS81XX_HCI_S 
#define DS81XX_HD_S					84				//DS81XX_HDI_S 
#define DS81XX_HE_S					85				//DS81XX_HE_S 
#define DS81XX_HF_S					86				//DS81XX_HFI_S 
#define DS81XX_AH_S					87				//DS81XX_AHI_S 
#define DS81XX_AHF_S				88				//DS81XX_AHFI_S 
#define DS90XX_HF_S		            90              //DS90XX_HFI_S
#define DS91XX_HF_S					91              //DS91XX_HFI_S
#define DS91XX_HD_S					92              //91XXHDI- S (MD) 
#define IDS90XX_A					93				//9000 intelligent ATM
#define IDS91XX_A					94				//9100 intelligent ATM
#define DS95XX_N_S					95              //DS95XX_NI_S NVR with no output interfaces
#define DS96XX_N_SH					96              //DS96XX_NI_SH NVR
#define DS90XX_HF_SH                97              //DS90XX_HFI_SH    
#define DS91XX_HF_SH                98              //DS91XX_HFI_SH 
#define DS_B10_XY                   100             //Video integrated platform Device Type (X: Encoder Number, Y: Decoder Number) 
#define DS_6504HF_B10               101             //Video integrated platform Encoder
#define DS_6504D_B10                102             //Video integrated platform Decoder
#define DS_1832_B10                 103				//Video integrated platform code splitter
#define DS_6401HFH_B10              104             //Video integrated platform optical
#define DS_65XXHC					105				//65XXHCI DVS
#define DS_65XXHC_S					106				//65XXHCI- SATA DVS
#define DS_65XXHF					107				//65XXHFI DVS
#define DS_65XXHF_S					108				//65XXHFI- SATA DVS
#define DS_6500HF_B                 109             //DS- 6500 series rack mount DVS
#define IVMS_6200_C                 110             //IVMS- 6200 (/C)   
#define IVMS_6200_B                 111             //IVMS- 6200 (/B) 
#define DS_72XXHV_ST15				112				//72XXHVI_ST15 DVR
#define DS_72XXHV_ST20				113				//72XXHVI_ST20 DVR
#define IVMS_6200_T			        114             //IVMS- 6200 (/T) 
#define IVMS_6200_BP                115             //IVMS- 6200 (/BP) 
#define DS_81XXHC_ST				116				//DS_81XXHC_ST
#define DS_81XXHS_ST				117				//DS_81XXHS_ST
#define DS_81XXAH_ST				118				//DS_81XXAH_ST ATM
#define DS_81XXAHF_ST				119				//DS_81XXAHF_ST ATM
#define DS_66XXDVS				    120				//66XX DVS

#define DS_18XX_PTZ					141				
#define DS_19AXX					142				
#define DS_19BXX					143				
#define DS_19CXX					144				
#define DS_19DXX					145				//DS_19DXX	
#define DS_19XX                     146             //DS_19XX
#define DS_19SXX					147				//DS_19SXX
#define DS_1HXX						148				//CS

//2011-11-30
#define	DS_C10H						161				/*CVCS*/
#define DS_C10N_BI					162				//DVCS BNC processor 
#define DS_C10N_DI					163				//DVCS RGB processor
#define DS_C10N_SI					164				//DVCS STREAM processor
#define DS_C10N_DO					165				//DVCS DISP processor
#define DS_C10N_SERVER				166				//DVCS SERVER

#define IDS_8104_AHFL_S_H           171             //8104ATM 
#define IDS_65XX_HF_A               172             //65 ATM
#define IDS90XX_HFI_RH              173             //9000 intelligent RH
#define IDS91XX_HFI_RH              174             //9100 intelligent RH
#define IDS_65XX_HF_B               175             //65 behavior analyze
#define IDS_65XX_HF_P               176             //65 plate recognize
#define IVMS_6200_F 		        177             //IVMS-6200(/F)
#define IVMS_6200_A                 178             //IVMS-6200(/A)
#define IVMS_6200_F_S 		        179             // IVMS-6200(/F_S)

#define DS90XX_HF_RH                181             //9000 RH
#define DS91XX_HF_RH                182             //9100 RH
#define DS72XXHVI_S                 183             //DVR DS-7204HVI-ST/SE 
#define DS81XXHW_S					185				//81 Resolution 960 
#define DS81XXHW_ST					186             //DS81XXHW_ST
#define DS91XXHW_ST					187             //DS91XXHW_ST
#define DS91XX_ST					188             //DS91XX_ST
#define DS81XX_ST					189             //DS81XX_ST
#define DS81XXHX_ST					190             //DS81XXHDI_ST,DS81XXHE_ST ky2012
#define DS73XXHX_ST					191             //DS73XXHI_ST ky2012
#define DS81XX_SH                   192             //Inquest81SH,81SHF
#define DS81XX_SN                   193             //Inquest81SNL

#define DS96XXN_ST                  194             //NVR:DS96xxN_ST
#define DS86XXN_ST                  195             //NVR:DS86xxN_ST
#define DS80XXHF_ST                 196             //DVR:DS80xxHF_ST
#define DS90XXHF_ST                 197             //DVR:DS90xxHF_ST
#define DS76XXN_ST                  198             //NVR:DS76xxN_ST

#define ENCODER_SERVER				200			    // ENCODER_SERVER
#define DECODER_SERVER              201             // DECODER_SERVER
#define PCNVR_SERVER                202             // PCNVR_SERVER
#define CVR_SERVER                  203             // CVR
#define DS_91XXHFH_ST				204             // 91HD-SDI
#define DS_66XXHFH					205             // 66 decoder
#define	TRAFFIC_TS_SERVER			210				//ITS server
#define	TRAFFIC_VAR					211				//ITS VAR

#define DS_19M00_MN					601				//network moudle

#define DS64XXHD_T					701				//64-T Decoder
#define DS_6516D_B10				702				//65 Decoder
#define DS_65XXD                    703             //65 Decoder
#define DS63XXD_T					704				//63-T Decoder

// DVR
#define DS90XXHW_ST					2001			// DS90XXHW_ST
#define DS72XXHX_SH                 2002            // DS-72xxHV_SH, DS-72xxHF-SH 
#define DS_92XX_HF_ST				2003			// DS-92XX-HF-ST 
#define DS_91XX_HF_XT				2004			// NETRET_9100DVR_HF_XT
#define DS_90XX_HF_XT               2005			// NETRET_9000DVR_HF_XT 
#define DS_73XXHX_SH				2006			// NETRET_7300DVR_HX_SH  

// NVR
#define DS_77XXN_ST					2201			// Netra NVR DS-77XXHF-ST
#define DS_95XX_N_ST				2202			// Netra 95XXN_ST NVR          
#define DS_85XX_N_ST				2203			// Netra 85XXN_ST NVR
#define DS_96XX_N_XT				2204			// NETRET_9600NVR_N_XT
#define DS_76XX_N_SE				2205			// NETRET_7600NVR_N_SE

//PCNVR
#define PCNVR_IVMS_4200             2301            //PCNVR_IVMS_4200

/**********************Device model end***********************/

/************************DVR Log begin***************************/

/* Alarm */
//Main Type
#define MAJOR_ALARM						0x1
//Hypo- Type
#define MINOR_ALARM_IN					0x1   //Alarm input 
#define MINOR_ALARM_OUT					0x2   //Alarm output
#define MINOR_MOTDET_START				0x3   //Motion detection alarm start 
#define MINOR_MOTDET_STOP				0x4   //Motion detection alarm stop
#define MINOR_HIDE_ALARM_START			0x5   //Mask alarm start 
#define MINOR_HIDE_ALARM_STOP			0x6   //Mask alarm stop 
#define MINOR_VCA_ALARM_START			0x7   //VCA alarm start 
#define MINOR_VCA_ALARM_STOP			0x8   //VCA alarm stop
#define MINOR_ITS_ALARM_START           0x09  // Traffic event alarm start
#define MINOR_ITS_ALARM_STOP            0x0A  //Traffic event alarm stop
#define MINOR_NETALARM_START            0x0b  //Net alarm start
#define MINOR_NETALARM_STOP             0x0c  //Net alarm stop
//2012-4-5 IPC PIR\wireless\callhelp
#define MINOR_WIRELESS_ALARM_START		0x0e  /* wireless alarm start */
#define MINOR_WIRELESS_ALARM_STOP  		0x0f /* wireless alarm stop */
#define MINOR_PIR_ALARM_START   		0x10  /* PIR alarm start */
#define MINOR_PIR_ALARM_STOP   			0x11  /* PIR alarm stop */
#define MINOR_CALLHELP_ALARM_START  	0x12  /* callhelp start */
#define MINOR_CALLHELP_ALARM_STOP  		0x13  /* callhelp stop */
#define MINOR_IPCHANNEL_ALARMIN_START   0x14  //IP channel alarm in start: It happens whenPCNVR receives the alarm in from its IP channel.After 10s,  "IP channel alarm in stop" happens if PCNVR can't receive it.  
#define MINOR_IPCHANNEL_ALARMIN_STOP    0x15  //IP channel alarm in stop. 

/*Exception */
//Main Type
#define MAJOR_EXCEPTION					0x2
//Hypo- Type

#define MINOR_RAID_ERROR				0x20	/* RAID Exception */
#define MINOR_VI_LOST					0x21  //Video loss
#define MINOR_ILLEGAL_ACCESS			0x22  //Illegal access 
#define MINOR_HD_FULL					0x23  //HD full 
#define MINOR_HD_ERROR					0x24  //HD error 
#define MINOR_DCD_LOST					0x25  //MODEM  off- line (Reserved)  
#define MINOR_IP_CONFLICT				0x26  //IP conflict 
#define MINOR_NET_BROKEN				0x27  //Network disconnected 
#define MINOR_REC_ERROR                 0x28  //Record error 
#define MINOR_IPC_NO_LINK               0x29  //IPC connection failed 
#define MINOR_VI_EXCEPTION              0x2a  //Video input error  (for analog channel only)  
#define MINOR_IPC_IP_CONFLICT           0x2b  //IPC IP conflict
#define MINOR_SENCE_EXCEPTION           0x2c  //Sence exception
#define MINOR_PIC_REC_ERROR             0x2d  //Snapshot error!
#define MINOR_VI_MISMATCH               0x2e  //Video format error.
#define MINOR_RESOLUTION_MISMATCH		0x2f	/*Resolution miamatch */

//2009- 12- 16 Add Video integrated platform Log Type
#define MINOR_FANABNORMAL				0x31  //Video integrated platform: fan abnormal
#define MINOR_FANRESUME					0x32  //Video integrated platform: fan resume normal
#define MINOR_SUBSYSTEM_ABNORMALREBOOT	0x33  //Video integrated platform: 6467abnormal reboot
#define MINOR_MATRIX_STARTBUZZER		0x34  //Video integrated platform: dm6467 abnormal, start buzzer
//2010- 01- 22
#define MINOR_NET_ABNORMAL				0x35  //Net abnormal
#define MINOR_MEM_ABNORMAL				0x36  //Memory abnormal
#define MINOR_FILE_ABNORMAL				0x37  //File abnormal
/* Operation */
//Main Type
#define MAJOR_OPERATION					0x3
#define MINOR_SCREEN_SUBSYSTEM_ABNORMALREBOOT   0x3c            //abnormal reboot
#define	MINOR_SCREEN_SUBSYSTEM_ABNORMALINSERT	0x3d			//sub board insert
#define	MINOR_SCREEN_SUBSYSTEM_ABNORMALPULLOUT	0x3e			//sub board pull out
#define	MINOR_SCREEN_ABNARMALTEMPERATURE		0x3f			//abnormal temperature
//2012-07-26
#define MINOR_HIGH_TEMPERATURE_PROTECT  0x40 //sub board high temperature protect

//Hypo- Type
#define MINOR_START_DVR					0x41    /* Power On */
#define MINOR_STOP_DVR					0x42    /* Power off */
#define MINOR_STOP_ABNORMAL				0x43    /* Illegal shut down */
#define MINOR_REBOOT_DVR                0x44    /*Local reboot DVR*/

#define MINOR_LOCAL_LOGIN				0x50    /* Login  (local)  */
#define MINOR_LOCAL_LOGOUT				0x51    /* Logout  (local) */
#define MINOR_LOCAL_CFG_PARM			0x52    /* Configuration  (local)  */
#define MINOR_LOCAL_PLAYBYFILE			0x53    /* Playback  (local)  */
#define MINOR_LOCAL_PLAYBYTIME			0x54    /* Playback or download by time  (local) */
#define MINOR_LOCAL_START_REC			0x55    /* Start record  (local)  */
#define MINOR_LOCAL_STOP_REC			0x56    /* Stop record  (local) */
#define MINOR_LOCAL_PTZCTRL				0x57    /* PTZ control  (local)  */
#define MINOR_LOCAL_PREVIEW				0x58    /* Preview  (local)  (Reserved) */
#define MINOR_LOCAL_MODIFY_TIME         0x59    /* Change time  (local)  (Reserved)  */
#define MINOR_LOCAL_UPGRADE				0x5a    /* Upgrade  (local)  */
#define MINOR_LOCAL_RECFILE_OUTPUT      0x5b    /* Backup  (local)  */
#define MINOR_LOCAL_FORMAT_HDD          0x5c    /* HD format (local)  */
#define MINOR_LOCAL_CFGFILE_OUTPUT      0x5d    /* Export Configuration  (local)  */
#define MINOR_LOCAL_CFGFILE_INPUT       0x5e    /* Import Configuration  (local)  */
#define MINOR_LOCAL_COPYFILE            0x5f    /* Backup file  (local)  */
#define MINOR_LOCAL_LOCKFILE            0x60    /* File lockup  (local) Reboot IPC  (local)  */
#define MINOR_LOCAL_UNLOCKFILE          0x61    /* File unlock  (local)  */
#define MINOR_LOCAL_DVR_ALARM           0x62    /* Clear/Trigger Alarm  (Local) */
#define MINOR_IPC_ADD                   0x63    /* Add IPC  (local)  */
#define MINOR_IPC_DEL                   0x64    /* Delete IPC  (local) */
#define MINOR_IPC_SET                   0x65    /* Set IPC  (local)  */
#define MINOR_LOCAL_START_BACKUP		0x66	/* local start backup file */
#define MINOR_LOCAL_STOP_BACKUP			0x67	/* local stop backup file*/
#define MINOR_LOCAL_COPYFILE_START_TIME 0x68	/* local backup: file start time*/
#define MINOR_LOCAL_COPYFILE_END_TIME	0x69	/* local backup: file end time*/
#define MINOR_LOCAL_ADD_NAS             0x6a	/* Add network hard disk in local configuration  (NFS/iSCSI) */
#define MINOR_LOCAL_DEL_NAS             0x6b	/* Delete network hard disk in local configuration  (NFS/iSCSI) */
#define MINOR_LOCAL_SET_NAS             0x6c	/* Set network hard disk in local configuration  (NFS/iSCSI) */
#define MINOR_LOCAL_RESET_PASSWD        0x6d    /* Local Resume Admin's Password*/ 

#define MINOR_REMOTE_LOGIN				0x70    /* Login  (remote) */
#define MINOR_REMOTE_LOGOUT				0x71    /* Logout   (remote)  */
#define MINOR_REMOTE_START_REC			0x72    /* Start record  (remote) */
#define MINOR_REMOTE_STOP_REC			0x73    /* Stop record   (remote)  */
#define MINOR_START_TRANS_CHAN			0x74    /* Start transparent channel  (remote)  */
#define MINOR_STOP_TRANS_CHAN			0x75    /* Stop transparent channel  (remote)  */
#define MINOR_REMOTE_GET_PARM			0x76    /* Get parameter  (remote) */
#define MINOR_REMOTE_CFG_PARM			0x77    /* configuration  (remote) */
#define MINOR_REMOTE_GET_STATUS         0x78    /* Get status  (remote)  */
#define MINOR_REMOTE_ARM				0x79    /* On guard   (remote)  */
#define MINOR_REMOTE_DISARM				0x7a    /* Disarm   (remote)  */
#define MINOR_REMOTE_REBOOT				0x7b    /* Reboot   (remote)  */
#define MINOR_START_VT					0x7c    /* Start voice talk */
#define MINOR_STOP_VT					0x7d    /* Stop voice talk */
#define MINOR_REMOTE_UPGRADE			0x7e    /* upgrade  (remote)  */
#define MINOR_REMOTE_PLAYBYFILE         0x7f    /* Playback by file name  (remote)  */
#define MINOR_REMOTE_PLAYBYTIME         0x80    /* Playback by time  (remote)  */
#define MINOR_REMOTE_PTZCTRL			0x81    /* PTZ control  (remote)  */
#define MINOR_REMOTE_FORMAT_HDD         0x82    /* Format hard disk (remote)  */
#define MINOR_REMOTE_STOP               0x83    /* Shut Down  (remote)  */
#define MINOR_REMOTE_LOCKFILE			0x84    /* File lockup  (remote)  */
#define MINOR_REMOTE_UNLOCKFILE         0x85    /* File unlock  (remote */
#define MINOR_REMOTE_CFGFILE_OUTPUT     0x86    /* Export Configuration   (remote)  */
#define MINOR_REMOTE_CFGFILE_INTPUT     0x87    /* Import Configuration  (remote)  */
#define MINOR_REMOTE_RECFILE_OUTPUT     0x88    /* Backup recording files  (remote)  */
#define MINOR_REMOTE_DVR_ALARM          0x89    /* Trigger/clear alarm  (remote) */
#define MINOR_REMOTE_IPC_ADD			0x8a    /* Add IPC  (remote) */
#define MINOR_REMOTE_IPC_DEL			0x8b    /* Delete IPC  (remote) */
#define MINOR_REMOTE_IPC_SET			0x8c    /* Set  IPC  (remote) */
#define MINOR_REBOOT_VCA_LIB            0x8d    /* Reboot vca library*/
#define MINOR_REMOTE_ADD_NAS            0x8e	/* Remote add nas disk*/
#define MINOR_REMOTE_DEL_NAS            0x8f	/* Remote delete nas disk*/
#define MINOR_REMOTE_SET_NAS            0x90	/* Remote set nas disk*/

//2010- 05- 26 Add Inquest DVR Log Type
#define MINOR_LOCAL_START_REC_CDRW      0x91    /* Local start CD/DVD writing */
#define MINOR_LOCAL_STOP_REC_CDRW       0x92    /* Local stop CD/DVD writing */
#define MINOR_REMOTE_START_REC_CDRW     0x93    /* Remote Start CD/DVD writing  */
#define MINOR_REMOTE_STOP_REC_CDRW      0x94    /* Remote stop CD/DVD writing */

#define MINOR_LOCAL_PIC_OUTPUT			0x95    /* local save picture */ 
#define MINOR_REMOTE_PIC_OUTPUT			0x96    /* remote save picture */

//2011-07-26 Add 81 Inquest DVR Log Type
#define MINOR_LOCAL_INQUEST_RESUME      0x97    /* local resume inquest event*/
#define MINOR_REMOTE_INQUEST_RESUME     0x98    /* remote resume inquest event*/

//2009- 12- 16 Add Video integrated platform Log Type
#define MINOR_SUBSYSTEMREBOOT           0xa0	/*Video integrated platform: dm6467 normal reboot*/
#define MINOR_MATRIX_STARTTRANSFERVIDEO 0xa1	/*Video integrated platform: Matrix Switch start transmitting images*/
#define MINOR_MATRIX_STOPTRANSFERVIDEO	0xa2	/*Video integrated platform: Matrix Switching to stop transmission of images*/
#define MINOR_REMOTE_SET_ALLSUBSYSTEM   0xa3	/*Video integrated platform: Set all the 6467 sub- systems of information*/
#define MINOR_REMOTE_GET_ALLSUBSYSTEM   0xa4	/*Video integrated platform: Get all the 6467 sub- systems of information*/
#define MINOR_REMOTE_SET_PLANARRAY      0xa5	/*Video integrated platform: Set plan array*/
#define MINOR_REMOTE_GET_PLANARRAY      0xa6	/*Video integrated platform: Get plan array*/
#define MINOR_MATRIX_STARTTRANSFERAUDIO 0xa7	/*Video integrated platform: Start transmission Audio Matrix Switch */
#define MINOR_MATRIX_STOPRANSFERAUDIO   0xa8	/*Video integrated platform: Stop transmission Audio Matrix Switch*/
#define MINOR_LOGON_CODESPITTER         0xa9	/*Video integrated platform: Logon spitter code*/
#define MINOR_LOGOFF_CODESPITTER        0xaa	/*Video integrated platform: Logoff spitter code*/
//2010- 01- 22 Add Video integrated platform Log Type
#define MINOR_START_DYNAMIC_DECODE 		0xb0	/*Start dynamic decode*/
#define MINOR_STOP_DYNAMIC_DECODE		0xb1	/*Stop dynamic decode*/
#define MINOR_GET_CYC_CFG				0xb2	/*Get cycle config*/
#define MINOR_SET_CYC_CFG				0xb3	/*Set cycle config*/
#define MINOR_START_CYC_DECODE			0xb4	/*Start cycle decode*/
#define MINOR_STOP_CYC_DECODE			0xb5	/*Stop cycle decode*/
#define MINOR_GET_DECCHAN_STATUS		0xb6	/*Get decode channel status*/
#define MINOR_GET_DECCHAN_INFO			0xb7	/*Get decode channel information*/
#define MINOR_START_PASSIVE_DEC			0xb8	/*Start passive*/
#define MINOR_STOP_PASSIVE_DEC			0xb9	/*Stop passive decode*/
#define MINOR_CTRL_PASSIVE_DEC			0xba	/*Passive decode control*/
#define MINOR_RECON_PASSIVE_DEC			0xbb	/*Passive decode reconnect*/
#define MINOR_GET_DEC_CHAN_SW			0xbc	/*Get decode channel switch*/
#define MINOR_SET_DEC_CHAN_SW			0xbd	/*Set decode channel switch*/
#define MINOR_CTRL_DEC_CHAN_SCALE		0xbe	/*Decode channel scale control*/
#define MINOR_SET_REMOTE_REPLAY			0xbf	/*Set remote replay*/
#define MINOR_GET_REMOTE_REPLAY			0xc0	/*Get remote replay*/
#define MINOR_CTRL_REMOTE_REPLAY		0xc1	/*Remote replay control*/
#define MINOR_SET_DISP_CFG				0xc2	/*Set display config*/
#define MINOR_GET_DISP_CFG				0xc3	/*Get display config*/
#define MINOR_SET_PLANTABLE				0xc4	/*Set plan table*/
#define MINOR_GET_PLANTABLE				0xc5	/*Get plan table*/
#define MINOR_START_PPPPOE				0xc6	/*Start pppoe*/
#define MINOR_STOP_PPPPOE				0xc7	/*Stop pppoe*/
#define MINOR_UPLOAD_LOGO				0xc8	/*Upload logo*/

#define MINOR_LOCAL_CONF_REB_RAID       0x101           /*Rebuild configuration automatically and locally*/
#define MINOR_LOCAL_CONF_SPARE          0x102           /*Hot spare of local configuration*/
#define MINOR_LOCAL_ADD_RAID            0x103           /*Add RAID locally*/
#define MINOR_LOCAL_DEL_RAID            0x104           /*Delete RAID locally*/
#define MINOR_LOCAL_MIG_RAID            0x105           /*Migrate RAID locally*/
#define MINOR_LOCAL_REB_RAID            0x106           /*Rebuild RAID manually and locally*/
#define MINOR_LOCAL_QUICK_CONF_RAID     0x107           /*Quick local configuration by one key*/
#define MINOR_LOCAL_ADD_VD              0x108           /*Add visual disk locally*/
#define MINOR_LOCAL_DEL_VD              0x109           /*Delete visual disk locally*/
#define MINOR_LOCAL_RP_VD               0x10a           /*Repair visual disk locally*/
#define MINOR_LOCAL_FORMAT_EXPANDVD     0X10b           /*Expand volume of visual disk locally*/
#define MINOR_LOCAL_STOP_RAID           0x10d           /*Local stop RAID*/
#define MINOR_LOCAL_RAID_UPGRADE        0X10c           /*Upgrade RAID locally*/    
#define MINOR_REMOTE_CONF_REB_RAID      0x111           /*Rebuild configuration automatically and remotely*/
#define MINOR_REMOTE_CONF_SPARE         0x112           /*Hot spare of remote configuration*/
#define MINOR_REMOTE_ADD_RAID           0x113           /*Add RAID remotely*/
#define MINOR_REMOTE_DEL_RAID           0x114           /*Delete RAID remotely*/
#define MINOR_REMOTE_MIG_RAID           0x115           /*Migrate RAID remotely*/
#define MINOR_REMOTE_REB_RAID           0x116           /*Rebuild RAID manually and remotely*/
#define MINOR_REMOTE_QUICK_CONF_RAID    0x117           /*Quick remote configuration by one key*/
#define MINOR_REMOTE_ADD_VD             0x118           /*Add visual disk remotely*/
#define MINOR_REMOTE_DEL_VD             0x119           /*Delete visual disk remotely*/
#define MINOR_REMOTE_RP_VD              0x11a           /*Repair visual disk remotely*/
#define MINOR_REMOTE_FORMAT_EXPANDVD    0X11b           /*Expand volume of visual disk remotely*/
#define MINOR_REMOTE_RAID_UPGRADE       0X11c           /*Upgrade RAID remotely*/  
#define MINOR_REMOTE_STOP_RAID          0x11d           /*Remote stop RAID*/

#define MINOR_LOCAL_START_PIC_REC		0x121           /*local start snapshot*/ 
#define MINOR_LOCAL_STOP_PIC_REC		0x122           /*local stop snapshot*/
#define MINOR_LOCAL_SET_SNMP			0x125           /*local set SNMP*/
#define MINOR_LOCAL_TAG_OPT				0x126           /*local operate label*/
#define MINOR_REMOTE_START_PIC_REC		0x131           /*remote start snapshot*/
#define MINOR_REMOTE_STOP_PIC_REC		0x132           /*remote stop snapshot*/
#define MINOR_REMOTE_SET_SNMP			0x135           /*remote set SNMP*/
#define MINOR_REMOTE_TAG_OPT			0x136           /*remote operate label*/  

// 9000 v2.2.0
#define MINOR_LOCAL_VOUT_SWITCH         0x140    /* local video out switch*/
#define MINOR_STREAM_CABAC         		0x141    /* stream cabac configuration*/
#define MINOR_SET_MULTI_MASTER          0x201    /*set multi master*/
#define MINOR_SET_MULTI_SLAVE           0x202    /*set multi slave*/
#define MINOR_CANCEL_MULTI_MASTER       0x203    /*cancel multi master*/
#define MINOR_CANCEL_MULTI_SLAVE        0x204    /*cancel multi slave*/
//2011-11-11 增加大屏控制器操作日志次类型
#define MINOR_SCREEN_SET_INPUT			0x251    /*set input signal*/
#define MINOR_SCREEN_SET_OUTPUT			0x252    /*set output channel*/
#define MINOR_SCREEN_SET_OSD			0x253    /*set OSD*/
#define MINOR_SCREEN_SET_LOGO			0x254    /*set LOGO*/
#define MINOR_SCREEN_SET_LAYOUT			0x255    /*set layout*/
#define	MINOR_SCREEN_PICTUREPREVIEW		0x256	 /*picture preview*/

//2012-06-14 CVCS2.0, 窗口设置等操作在V1.0， V1.1中已经有了，当时在设备日志中没有定义 
#define MINOR_SCREEN_GET_OSD			0x257   /*get OSD*/
#define MINOR_SCREEN_GET_LAYOUT			0x258   /*get layout*/
#define MINOR_SCREEN_LAYOUT_CTRL		0x259   /*layout control*/
#define MINOR_GET_ALL_VALID_WND			0x260	/*get all valid window*/
#define MINOR_GET_SIGNAL_WND			0x261	/*get single window information*/
#define MINOR_WINDOW_CTRL				0x262	/*window control*/
#define MINOR_GET_LAYOUT_LIST			0x263	/*get layout list*/
#define MINOR_LAYOUT_CTRL				0x264	/*layout control*/
#define MINOR_SET_LAYOUT				0x265	/*set single layout*/
#define MINOR_GET_SIGNAL_LIST			0x266	/*get input signal list*/
#define MINOR_GET_PLAN_LIST				0x267	/*get plan list*/
#define MINOR_SET_PLAN					0x268	/*set plan*/
#define MINOR_CTRL_PLAN					0x269	/*plan control*/
#define MINOR_CTRL_SCREEN				0x270	/*screen control*/
#define MINOR_ADD_NETSIG				0x271	/*add net signal*/
#define MINOR_SET_NETSIG				0x272	/*mod net signal*/
#define MINOR_SET_DECBDCFG				0x273	/*set decoder parameter*/
#define MINOR_GET_DECBDCFG				0x274	/*get decoder parameter*/
#define MINOR_GET_DEVICE_STATUS			0x275	/*get device status*/
#define MINOR_UPLOAD_PICTURE			0x276	/*upload picture*/
#define MINOR_SET_USERPWD				0x277	/*set user name and password*/
#define MINOR_ADD_LAYOUT				0x278	/*add layout*/
#define MINOR_DEL_LAYOUT				0x279	/*delete layout*/
#define MINOR_DEL_NETSIG				0x280	/*delete net signal*/
#define MINOR_ADD_PLAN					0x281	/*add plan*/
#define MINOR_DEL_PLAN					0x282	/*delete plan*/

//2012-03-05 ITC
#define MINOR_SET_TRIGGERMODE_CFG       0x1001  /*Set trigger configuration*/
#define MINOR_GET_TRIGGERMODE_CFG       0x1002  /*Get trigger configuration*/
#define MINOR_SET_IOOUT_CFG             0x1003  /*Set IO out configuration*/
#define MINOR_GET_IOOUT_CFG             0x1004  /*Get IO out configuration*/
#define MINOR_GET_TRIGGERMODE_DEFAULT   0x1005  /*Get trigger default configuration*/
#define MINOR_GET_ITCSTATUS             0x1006  /*Get status */
#define MINOR_SET_STATUS_DETECT_CFG     0x1007  /*Set status detect configuration*/
#define MINOR_GET_STATUS_DETECT_CFG     0x1008  /*Get status detect configuration*/
#define MINOR_SET_VIDEO_TRIGGERMODE_CFG 0x1009  /*Set video trigger configuration*/
#define MINOR_GET_VIDEO_TRIGGERMODE_CFG 0x100a  /*Get video trigger configuration*/

/*Additional Log Info*/
//Main Type
#define MAJOR_INFORMATION			    0x4     /*Extra Info*/
//Hypo- Type
#define MINOR_HDD_INFO                  0xa1 //HD info*/
#define MINOR_SMART_INFO                0xa2 //SMART info*/
#define MINOR_REC_START                 0xa3 //Start record*/
#define MINOR_REC_STOP                  0xa4 //Stop record */
#define MINOR_REC_OVERDUE				0xa5 //Record overdue*/
#define MINOR_LINK_START				0xa6 //start to link device
#define MINOR_LINK_STOP					0xa7 //stop to link device
#define MINOR_NET_DISK_INFO				0xa8 //Network hard disk info
#define MINOR_RAID_INFO                 0xa9 //raid Info

#define MINOR_PIC_REC_START             0xb3 //start snapshot     
#define MINOR_PIC_REC_STOP              0xb4 //stop snapshot 
#define MINOR_PIC_REC_OVERDUE           0xb5 //delete delayed picture

typedef enum tagALARMHOST_MAJOR_TYPE
{
    MAJOR_ALARMHOST_ALARM = 1,
    MAJOR_ALARMHOST_EXCEPTION,
    MAJOR_ALARMHOST_OPERATION,
    MAJ0R_ALARMHOST_EVENT
}ALARMHOST_MAJOR_TYPE;

typedef enum tagALARMHOST_MINOR_TYPE
{
    // Alarm 
    MINOR_SHORT_CIRCUIT =0x01,      // Short circuit alarm
    MINOR_BROKEN_CIRCUIT,           // Broken circuit alarm
    MINOR_ALARM_RESET,              // Alarm reset 
    MINOR_ALARM_NORMAL,				// Alarm resumes to normal
    MINOR_PASSWORD_ERROR,			// Password error(consecutive times for password error)
    MINOR_ID_CARD_ILLEGALLY,		// Illegal proximity card ID
    MINOR_KEYPAD_REMOVE,			// Keypad tamper
    MINOR_KEYPAD_REMOVE_RESTORE,	// Keypad tamper reset
    MINOR_DEV_REMOVE,				// Device tamper
    MINOR_DEV_REMOVE_RESTORE,		// Device tamper reset
    MINOR_BELOW_ALARM_LIMIT1,		// Analog lower than alarm limit 1
    MINOR_BELOW_ALARM_LIMIT2,		// Analog lower than alarm limit 2
    MINOR_BELOW_ALARM_LIMIT3,		// Analog lower than alarm limit 3
    MINOR_BELOW_ALARM_LIMIT4,		// Analog lower than alarm limit 4
    MINOR_ABOVE_ALARM_LIMIT1,		// Analog higher than alarm limit 1
    MINOR_ABOVE_ALARM_LIMIT2,		// Analog higher than alarm limit 2
    MINOR_ABOVE_ALARM_LIMIT3,		// Analog higher than alarm limit 3
    MINOR_ABOVE_ALARM_LIMIT4,		// Analog higher than alarm limit 4
	MINOR_URGENCYBTN_ON,			// Urgency button on
	MINOR_URGENCYBTN_OFF,			// Urgency button off

    // Exception
    MINOR_POWER_ON      = 0x01,	    // Power on
    MINOR_POWER_OFF,				// Power off
    MINOR_WDT_RESET,				// WDT reset
    MINOR_LOW_BATTERY_VOLTAGE,		// Low battery voltage
    MINOR_AC_LOSS,					// AC loss
    MINOR_AC_RESTORE,				// AC restore
    MINOR_RTC_EXCEPTION,			// RTC real-time clock exception
    MINOR_NETWORK_CONNECT_FAILURE,	// Network is disconnected
    MINOR_NETWORK_CONNECT_RESTORE,	// Network connection restore
    MINOR_TEL_LINE_CONNECT_FAILURE,	// Telephone line is disconnected
    MINOR_TEL_LINE_CONNECT_RESTORE,	// Telephone line restore
    MINOR_EXPANDER_BUS_LOSS,		// Expansion bus module dropped
    MINOR_EXPANDER_BUS_RESTORE,		// Expansion bus module restore
    MINOR_KEYPAD_BUS_LOSS,			// Keyboard bus module dropped
    MINOR_KEYPAD_BUS_RESTORE,		// Keyboard bus module restore 
    MINOR_SENSOR_FAILURE,			// Analog sensor failure
    MINOR_SENSOR_RESTORE,			// Analog sensor restore
    MINOR_RS485_CONNECT_FAILURE,	// RS485 channel is disconnected
    MINOR_RS485_CONNECT_RESTORE,	// RS485 channel disconnection restore
    MINOR_BATTERT_VOLTAGE_RESTORE,  // Battery voltage resume to normal 

    // Operation
    MINOR_GUARD         = 0x01,	    // Fortify
    MINOR_UNGUARD,					// Cancel fortification
    MINOR_BYPASS,					// Bypass
    MINOR_DURESS_ACCESS,			// Duress access
    MINOR_ALARMHOST_LOCAL_REBOOT,	// Local reboot
    MINOR_ALARMHOST_REMOTE_REBOOT,	// Remote reboot
    MINOR_ALARMHOST_LOCAL_UPGRADE,	// Local upgrade
    MINOR_ALARMHOST_REMOTE_UPGRADE,	// Remote upgrade
    MINOR_RECOVERY_DEFAULT_PARAM,	// Recovery default parameter
    MINOR_ALARM_OUTPUT,				// Control alarm output 
    MINOR_ACCESS_OPEN,				// Control access open
    MINOR_ACCESS_CLOSE,				// Control access close
    MINOR_SIREN_OPEN,				// Control siren open
    MINOR_SIREN_CLOSE,				// Control siren close
    MINOR_MOD_ZONE_CONFIG,	  	    // Modify defense area configuration
    MINOR_MOD_ALARMOUT_CONIFG,	    // Control alarmout configuration
    MINOR_MOD_ANALOG_CONFIG,		// Modify analog configuration
    MINOR_RS485_CONFIG,				// Modify RS-485 configuration
    MINOR_PHONE_CONFIG,				// Modify dialing configuration
    MINOR_ADD_ADMIN,                // Add administrator
    MINOR_MOD_ADMIN_PARAM,	        // Modify password of administrator
    MINOR_DEL_ADMIN,	            // Delete administrator
    MINOR_ADD_NETUSER,		        // Add network user
    MINOR_MOD_NETUSER_PARAM,	    // Modify password of network user
    MINOR_DEL_NETUSER,				// Delete network user
    MINOR_ADD_OPERATORUSER,			// Add operator user
    MINOR_MOD_OPERATORUSER_PW,		// Add operator user
    MINOR_DEL_OPERATORUSER,			// Add operator user
    MINOR_ADD_KEYPADUSER,			// Add user of keyboard or card reader	
    MINOR_DEL_KEYPADUSER,			// Delete user of keyboard or card reader
    MINOR_REMOTEUSER_LOGIN,	    	// Remote login
    MINOR_REMOTEUSER_LOGOUT,		// Remote logout
    MINOR_REMOTE_GUARD,				// Remotely fortify
    MINOR_REMOTE_UNGUARD,			// Remotely cancel fortification
    MINOR_MOD_HOST_CONFIG,          // Modify host configuration
    MINOR_RESTORE_BYPASS,			// Bypass restore

    // Event 
    MINOR_SCHOOLTIME_IRGI_B = 0x01,		// B code timing
    MINOR_SCHOOLTIME_SDK,				// SDK timing
    MINOR_SCHOOLTIME_SELFTEST			// Scheduled self-test timing
}ALARMHOST_MINOR_TYPE;
/*
If the main type of the log is MAJOR_OPERATION=03 (Operation) And Sub type is
MINOR_LOCAL_CFG_PARM=0x52 (local configuration) 
MINOR_REMOTE_GET_PARM=0x76 (remote get configuration) 
MINOR_REMOTE_CFG_PARM=0x77 (remote set configuration) 
dwParaType:  is valid,  and the relative definition is listed as below: 
*/
#define PARA_VIDEOOUT	  0x1
#define PARA_IMAGE		  0x2
#define PARA_ENCODE		  0x4
#define PARA_NETWORK	  0x8
#define PARA_ALARM		  0x10
#define PARA_EXCEPTION	  0x20
#define PARA_DECODER	  0x40    /*Decoder*/
#define PARA_RS232		  0x80
#define PARA_PREVIEW	  0x100
#define PARA_SECURITY	  0x200
#define PARA_DATETIME	  0x400
#define PARA_FRAMETYPE	  0x800    /*Frame Type*/
#define PARA_VCA_RULE     0x1001   //Rules of conduct 
#define PARA_VCA_CTRL     0x1002   //Intelligent control information configured
#define PARA_VCA_PLATE	  0x1003   //  License Plate Recognition

#define PARA_CODESPLITTER 0x2000 /*spitter code parameter*/
//2010- 01- 22 
#define PARA_RS485		  0x2001			/* RS485 config info*/
#define PARA_DEVICE		  0x2002			/* Device config info*/
#define PARA_HARDDISK	  0x2003			/* HD config info */
#define PARA_AUTOBOOT	  0x2004			/* Auto-reboot info*/
#define PARA_HOLIDAY	  0x2005			/* Holiday info*/			
#define PARA_IPC		  0x2006			/* IPC channel info */

//Time correction structure
typedef struct
{
    DWORD dwYear; 		    //Year
    DWORD dwMonth; 		    //Month
    DWORD dwDay; 		    //Day
    DWORD dwHour; 		    //Hour
    DWORD dwMinute; 		//Minute
    DWORD dwSecond; 		//Second
}NET_DVR_TIME,  *LPNET_DVR_TIME; 

/*
IP Address
*/
typedef struct
{		
    char	sIpV4[16]; 						//IPv4 Address 
    BYTE	byIPv6[128]; 					//Reserved 
}NET_DVR_IPADDR,  *LPNET_DVR_IPADDR; 

//Log Info (9000extended) 
typedef struct 
{
    NET_DVR_TIME strLogTime; 
    DWORD	dwMajorType; 	//Main type 1- alarm;  2- abnormal;  3- operation;  0xff- all 
    DWORD	dwMinorType; 	//Hypo- Type 0- all; 
    BYTE	sPanelUser[MAX_NAMELEN];  //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN]; //user ID for network operation
    NET_DVR_IPADDR	struRemoteHostAddr; //remote host IP
    DWORD	dwParaType; //parameter type,  for 9000 series MINOR_START_VT/MINOR_STOP_VT,  channel of the voice talking
    DWORD	dwChannel; //channel number
    DWORD	dwDiskNumber; //HD number
    DWORD	dwAlarmInPort; //alarm input port
    DWORD	dwAlarmOutPort; //alarm output port
    DWORD   dwInfoLen; 
    char    sInfo[LOG_INFO_LEN]; 
}NET_DVR_LOG_V30,  *LPNET_DVR_LOG_V30; 

//Log Info
typedef struct 
{
    NET_DVR_TIME strLogTime; 
    DWORD	dwMajorType; 	//MMain type 1- alarm;  2- abnormal;  3- operation;  0xff- all 
    DWORD	dwMinorType; //Hypo- Type 0- all; 
    BYTE	sPanelUser[MAX_NAMELEN];  //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN]; //user ID for network operation
    char	sRemoteHostAddr[16]; //remote host IP
    DWORD	dwParaType; //parameter type
    DWORD	dwChannel; //channel number
    DWORD	dwDiskNumber; //HD number
    DWORD	dwAlarmInPort; //alarm input port
    DWORD	dwAlarmOutPort; //alarm output port
}NET_DVR_LOG,  *LPNET_DVR_LOG; 

/************************DVR Log end***************************/

/*************************************************
Parameters configuration structure (_V30 is for 9000) 
**************************************************/

/////////////////////////////////////////////////////////////////////////

//Time Segment (Sub structure) 
typedef struct
{
    //Start
    BYTE byStartHour; 
    BYTE byStartMin; 
    //End
    BYTE byStopHour; 
    BYTE byStopMin; 
}NET_DVR_SCHEDTIME,  *LPNET_DVR_SCHEDTIME; 

/*Handling way of Alarm & Exception*/
#define NOACTION			0x0				/*Don't Respond*/
#define WARNONMONITOR		0x1				/*Warning on Monitor*/
#define WARNONAUDIOOUT		0x2				/*Audio Warning*/
#define UPTOCENTER			0x4				/*Upload to center*/
#define TRIGGERALARMOUT		0x8				/*Trigger Alarm Output*/
#define TRIGGERCATPIC		0x10			/*capture picture and E-mail*/
#define SEND_PIC_FTP        0x200           /*capture picture and upload to ftp*/

//Handle Alarm & Exception
typedef struct
{
    DWORD	dwHandleType; 	/*Way to handle,  result of operation OR*/
    /*0x00:  No response*/
    /*0x01:  Alarm on monitor*/
    /*0x02:  Audio Alarm*/
    /*0x04:  Upload to center*/
    /*0x08:  Trigger alarm output*/
    /*0x10:  Grab JPEG image and EMail it*/
	/*0x20:  wireless voice and light alarm*/
	/*0x40:  Trigger electric map(only PCNVR supports)*/
	/*0x200: capture jpeg and update to FTP*/
    BYTE byRelAlarmOut[MAX_ALARMOUT_V30];   
    //Alarm out channel,  1 means trigger this channel
}NET_DVR_HANDLEEXCEPTION_V30,  *LPNET_DVR_HANDLEEXCEPTION_V30; 

//Handle Alarm & Exception  (sub structure) 
typedef struct
{
    DWORD	dwHandleType; 			/*Way to handle,  result of operation OR*/
    /*0x00:  No response*/
    /*0x01:  Alarm on monitor*/
    /*0x02:  Audio Alarm*/
    /*0x04:  Upload to center*/
    /*0x08:  Trigger alarm output*/
    /*0x10:  Grab JPEG image and EMail it*/
    BYTE byRelAlarmOut[MAX_ALARMOUT];  //Alarm out channel,  1 means trigger this channel
}NET_DVR_HANDLEEXCEPTION,  *LPNET_DVR_HANDLEEXCEPTION; 

//DVR Device Parameters
typedef struct
{
    DWORD dwSize; 
    BYTE sDVRName[NAME_LEN];    //DVR Name
    DWORD dwDVRID; 				//DVR ID for IR Control //V1.4 (0- 99) ,  V1.5 (0- 255) 
    DWORD dwRecycleRecord; 		//cycle Record, 0: No cycle;  1: cycle
    //The variable below is read only
    BYTE sSerialNumber[SERIALNO_LEN]; 	//SN
    DWORD dwSoftwareVersion; 			//software version, high 16 bits is main version,  low 16 bits is hypo- version
    DWORD dwSoftwareBuildDate; 			//build date, 0xYYYYMMDD
    DWORD dwDSPSoftwareVersion; 		//DSP software version,  high 16 bits is main version,  low 16 bits is hypo- version
    DWORD dwDSPSoftwareBuildDate; 		// DSP software build date, 0xYYYYMMDD
    DWORD dwPanelVersion; 				// Front panel version,  high 16 bits is main version,  low 16 bits is hypo- version
    DWORD dwHardwareVersion; 	//Hardware version,  high 16 bits is main version,  low 16 bits is hypo- version
    BYTE byAlarmInPortNum; 		//Number of alarm input
    BYTE byAlarmOutPortNum;     //Number of alarm output
    BYTE byRS232Num; 			//Number of DVR RS232 ports
    BYTE byRS485Num; 			//Number of DVR RS485 ports
    BYTE byNetworkPortNum; 		//Number of network ports
    BYTE byDiskCtrlNum; 		//Number of DVR hardware controllers
    BYTE byDiskNum; 			//DVR Hard disk number
    BYTE byDVRType; 			//DVR Model,  1: DVR 2: ATM DVR 3: DVS ......
    BYTE byChanNum; 			//DVR channel number
    BYTE byStartChan; 			//First channel's No. e.g.,  DVS- 1, DVR -  1
    BYTE byDecordChans; 		//Number of decoding channels
    BYTE byVGANum; 				//Number of VGA ports
    BYTE byUSBNum; 				//Number of USB ports
    BYTE byAuxoutNum; 			//Number of AUX ports
    BYTE byAudioNum; 			//Number of audio ports
    BYTE byIPChanNum; 			//Maximum number of IP channels
}NET_DVR_DEVICECFG,  *LPNET_DVR_DEVICECFG; 

/*
Network structure  (9000) 
*/
typedef struct 
{
    NET_DVR_IPADDR	struDVRIP;           	//DVR IP address
    NET_DVR_IPADDR	struDVRIPMask; 			//DVR IP Mask
    DWORD	dwNetInterface;    				//Network port,  1- 10MBase- T, 2- 10MBase- T full duplex,  3- 100MBase- TX, 4- 100M full duplex,  5- 10M/100M adaptive
    WORD	wDVRPort; 						//Port
    WORD	wMTU; 							//MTU,  1500 by default
    BYTE	byMACAddr[MACADDR_LEN]; 		//MAC address
	BYTE    byRes[2];              
}NET_DVR_ETHERNET_V30,  *LPNET_DVR_ETHERNET_V30; 

/*
Network data structure (Sub structure) 
*/
typedef struct
{
    char sDVRIP[16];              //DVR IP address
    char sDVRIPMask[16];          //DVR IP Mask
    DWORD dwNetInterface;         //Network interface: 1- 10MBase- T, 2- 10MBase- T full duplex, 3- 100MBase- TX, 4- 100M full duplex, 5- 10M/100M adaptive
    WORD wDVRPort; 		          //Port
    BYTE byMACAddr[MACADDR_LEN];  //Mac address
}NET_DVR_ETHERNET; 

//pppoe structure
typedef struct 
{
    DWORD	dwPPPOE; 										//0- disable, 1- enable
    BYTE	sPPPoEUser[NAME_LEN]; 							//PPPoE user name
    char	sPPPoEPassword[PASSWD_LEN]; 					//PPPoE password
    NET_DVR_IPADDR	struPPPoEIP; 							//PPPoE IP address
}NET_DVR_PPPOECFG,  *LPNET_DVR_PPPOECFG; 

//Network Configure Structure  (9000DVR extended) 
typedef struct
{	
    DWORD dwSize; 
    NET_DVR_ETHERNET_V30	struEtherNet[MAX_ETHERNET]; 	//Network Port
    NET_DVR_IPADDR	struRes1[2]; 							//Reserved
    NET_DVR_IPADDR	struAlarmHostIpAddr; 					//IP address of Alarm Host 
    WORD	wRes2[2]; 										//Reserved 
    WORD	wAlarmHostIpPort; 								//Port of Alarm Host 
    BYTE    byUseDhcp;                                      //Enable DHCP or not 0xff- invalid 0- disable 1- enable
    BYTE	byRes3; 
    NET_DVR_IPADDR	struDnsServer1IpAddr; 					//IP address of DNS 1
    NET_DVR_IPADDR	struDnsServer2IpAddr; 					//IP address of DNS 2
    BYTE	byIpResolver[MAX_DOMAIN_NAME]; 					//IP address or domain name of analysis server
    WORD	wIpResolverPort; 								//Port of IP analysis server
    WORD	wHttpPortNo; 									//HTTP port 
    NET_DVR_IPADDR	struMulticastIpAddr; 					//Multicast group address 
    NET_DVR_IPADDR	struGatewayIpAddr; 						//Gateway address 
    NET_DVR_PPPOECFG struPPPoE; 	
    BYTE    byRes[64]; 
} NET_DVR_NETCFG_V30,  *LPNET_DVR_NETCFG_V30; 

//Netcard Configure Structure
typedef struct 
{
    NET_DVR_IPADDR struDVRIP; 				 /*Network card IP address */
    NET_DVR_IPADDR struDVRIPMask; 			 /*Network card IP address mask*/
    DWORD dwNetInterface; 				     /*Network port,  1- 10MBase- T 2- 10MBase- T full duplex  3- 100MBase- TX 4- 100M full duplex  5- 10M/100M adaptive*/
    BYTE byRes1[2];  			             /*port*/
    WORD wMTU; 						         /*MTU,  1500 by default*/
    BYTE byMACAddr[MACADDR_LEN]; 		     /*Mac address*/
    BYTE byRes2[2];                          /*Reserved*/
    BYTE byUseDhcp;                          /* Enable DHCP or not 0xff- invalid 0- disable 1- enable*/
    BYTE byRes3[3]; 				   	     /*Reserved*/
    NET_DVR_IPADDR struGatewayIpAddr; 		 /*Gateway address*/
    NET_DVR_IPADDR struDnsServer1IpAddr; 	 /*IP address of DNS 1*/
    NET_DVR_IPADDR struDnsServer2IpAddr; 	 /*IP address of DNS 2*/
}NET_DVR_ETHERNET_MULTI,  *LPNET_DVR_ETHERNET_MULTI; 

//Multi Netcard Configure Structure
typedef struct
{
    DWORD  dwSize; 
    BYTE   byDefaultRoute;           /* Default route, 0:  struEtherNet[0], 1:  struEtherNet[1] */
    BYTE   byNetworkCardNum;         //Network card sum
    BYTE   byRes[2];  //res
    NET_DVR_ETHERNET_MULTI struEtherNet[MAX_NETWORK_CARD];  /* Network Port*/
    NET_DVR_IPADDR         struManageHost1IpAddr;        /* Manage host 1 IP */
    NET_DVR_IPADDR         struManageHost2IpAddr;        /* Manage host 2 IP */
    NET_DVR_IPADDR	       struAlarmHostIpAddr;          /* Alarm host IP 1 */
    WORD wManageHost1Port;      /* Manage host 1 port */
    WORD wManageHost2Port;      /* Manage host 2 port */
    WORD wAlarmHostIpPort;      /* Alarm host port */
    BYTE  byIpResolver[MAX_DOMAIN_NAME];      /* IP address or domain name of analysis serve */
    WORD wIpResolverPort;                    /* Port of IP analysis server */
    WORD wDvrPort;                            //DVR port ,  default 8000 
    WORD wHttpPortNo;                        /* HTTP port */
    BYTE  byRes2[6]; 
    NET_DVR_IPADDR   struMulticastIpAddr;          /* Multicast group address */
    NET_DVR_PPPOECFG struPPPoE; 
    BYTE        byRes3[24]; 
}NET_DVR_NETCFG_MULTI,  *LPNET_DVR_NETCFG_MULTI; 

//Network Configure Structure
typedef struct
{
    DWORD dwSize; 
    NET_DVR_ETHERNET struEtherNet[MAX_ETHERNET]; 		/* Network Port */
    char sManageHostIP[16]; 		//IP address of remote management host
    WORD wManageHostPort; 		//Port of remote management Host
    char sIPServerIP[16];        //Address of IPServer
    char sMultiCastIP[16];      //Multicast group address
    char sGatewayIP[16];        	//Gateway address
    char sNFSIP[16]; 			//IP address of NFS host
    BYTE sNFSDirectory[PATHNAME_LEN]; //NFS directory
    DWORD dwPPPOE; 				//0- disable, 1- enable
    BYTE sPPPoEUser[NAME_LEN]; 	//PPPoE username
    char sPPPoEPassword[PASSWD_LEN]; // PPPoE password
    char sPPPoEIP[16]; 			//PPPoE IP address  (read only) 
    WORD wHttpPort; 				//HTTP port
}NET_DVR_NETCFG,  *LPNET_DVR_NETCFG; 

//Channel Image structure
//Motion detection structure (sub structure)  (9000 extended) 
typedef struct 
{
    BYTE byMotionScope[64][96]; 									/*Motion detection area, 0- 96 bits stand for 64 lines and there are 96*64 small areas,  1- - it is motion detection area, 0- - not*/
    BYTE byMotionSensitive; 										/*sensitive grade of motion detection,  0 -  5 (5 is most sensitive) ,  oxff turn off*/
    BYTE byEnableHandleMotion; 									    /* Process motion alarm  0- No 1- Yes*/ 
    BYTE byEnableDisplay;	/*Display motion detect,0- No 1- Yes*/
    char reservedData; 	
    NET_DVR_HANDLEEXCEPTION_V30 struMotionHandleType; 				/* The way to process */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*Guard time*/
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; 							/* Channel triggered to record*/
}NET_DVR_MOTION_V30,  *LPNET_DVR_MOTION_V30; 

//Motion detection structure (sub structure) 
typedef struct 
{
    BYTE byMotionScope[18][22]; 	/*motion detection area,  22*18 blocks in total,  1- - it's motion detection area,  0- - not*/
    BYTE byMotionSensitive; 		/*sensitive grade of motion detection,  0 -  5 (5 is most sensitive) ,  oxff turn off*/
    BYTE byEnableHandleMotion; 	/* process motion detection or not */
	BYTE byEnableDisplay;	/*Display motion detect,0- No 1- Yes*/
    char reservedData; 
    NET_DVR_HANDLEEXCEPTION strMotionHandleType; 	/* method to process alarm */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT]; //Guard time
    BYTE byRelRecordChan[MAX_CHANNUM]; 				//Channel triggered to record*/
}NET_DVR_MOTION,  *LPNET_DVR_MOTION; 

//Tamper Alarm  (sub structure)  (9000 extended)   area size:  704*576
typedef struct 
{
    DWORD dwEnableHideAlarm; 				/* Enable tamper alarm or not , 0- disable, 1- low sensitivity 2- Middle 3- High*/
    WORD wHideAlarmAreaTopLeftX; 			/* X- coordinate of tamper area */
    WORD wHideAlarmAreaTopLeftY; 			/* Y- coordinate of tamper area */
    WORD wHideAlarmAreaWidth; 				/* Width of tampered area */
    WORD wHideAlarmAreaHeight; 				/* Height of tampered area*/
    NET_DVR_HANDLEEXCEPTION_V30 strHideAlarmHandleType; 	/* Way to handle alarm */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; //Guard time
}NET_DVR_HIDEALARM_V30,  *LPNET_DVR_HIDEALARM_V30; 

//Tamper Alarm  (sub structure)  area size:  704*576
typedef struct 
{
    DWORD dwEnableHideAlarm; 				/* Enable tamper alarm or not , 0- disable, 1- low sensitivity 2- Middle 3- High*/
    WORD wHideAlarmAreaTopLeftX; 			/* X- coordinate of tamper area */
    WORD wHideAlarmAreaTopLeftY; 			/* Y- coordinate of tamper area */
    WORD wHideAlarmAreaWidth; 				/* Width of tampered area */
    WORD wHideAlarmAreaHeight; 				/* Height of tampered area*/
    NET_DVR_HANDLEEXCEPTION strHideAlarmHandleType; 	/* Way to handle the alarm */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT]; //Guard time
}NET_DVR_HIDEALARM,  *LPNET_DVR_HIDEALARM; 

//Signal Lost Alarm (sub structure)  (9000 extended) 
typedef struct 
{
    BYTE byEnableHandleVILost; 	/* Respond the alarm or not */
    NET_DVR_HANDLEEXCEPTION_V30 strVILostHandleType; 	/* Way to respond*/
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; //Guard time
}NET_DVR_VILOST_V30,  *LPNET_DVR_VILOST_V30; 

//Signal Lost Alarm (sub structure) 
typedef struct 
{
    BYTE byEnableHandleVILost; 	/* Respond the alarm or not */
    NET_DVR_HANDLEEXCEPTION strVILostHandleType; 	/* Way to respond*/
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT]; //Guard time
}NET_DVR_VILOST,  *LPNET_DVR_VILOST; 

//Tampered Area (sub structure) 
typedef struct 
{
    WORD wHideAreaTopLeftX; 				/* X- coordinate of tamper area */
    WORD wHideAreaTopLeftY; 				/* Y- coordinate of tamper area */
    WORD wHideAreaWidth; 				/* Width of tampered area */
    WORD wHideAreaHeight; 				/* Height of tampered area*/
}NET_DVR_SHELTER,  *LPNET_DVR_SHELTER; 

typedef struct
{
    BYTE byBrightness;   	/*Brightness, 0- 255*/
    BYTE byContrast;     	/*contrast, 0- 255*/	
    BYTE bySaturation;   	/*Saturation, 0- 255*/
    BYTE byHue;     			/*Hue, 0- 255*/
}NET_DVR_COLOR,  *LPNET_DVR_COLOR; 


//Video Structure (9000 extended) 
typedef struct
{
    DWORD dwSize; 
    BYTE sChanName[NAME_LEN]; 
    DWORD dwVideoFormat; 	/* Read only,  Video Standard 1- NTSC 2- PAL*/
    BYTE  byReservedData[64]; /*Reserved*/
    //Display Channel Name
    DWORD dwShowChanName;  // Display channel name or not, 0- no, 1- display size = 704*576
    WORD wShowNameTopLeftX; 				/* X- coordinate of display position */
    WORD wShowNameTopLeftY; 				/* Y- coordinate of display position  */
    //Signal lost Alarm
    NET_DVR_VILOST_V30 struVILost; 
    NET_DVR_VILOST_V30 struRes; 		/*Reserved*/
    //Motion detection
    NET_DVR_MOTION_V30 struMotion; 
    //Tamper alarm
    NET_DVR_HIDEALARM_V30 struHideAlarm; 
    //Tampered Area 704*576
    DWORD dwEnableHide; 		/* Enable Tamper Alarm , 0- disable, 1- enable*/
    NET_DVR_SHELTER struShelter[MAX_SHELTERNUM]; 
    //OSD
    DWORD dwShowOsd; 		// Display OSD or not, 0- No OSD, 1- Display Area for display:  704*576
    WORD wOSDTopLeftX; 				/* X- coordinate of OSD */
    WORD wOSDTopLeftY; 				/* Y- coordinate of OSD*/
    BYTE byOSDType; 					/* OSD Type  (format of Year/Month/Day)  */
    /* 0:  XXXX- XX- XX Year Month Day */
    /* 1:  XX- XX- XXXX Month Day Year */
    /* 2:  XXXXYearXXNonthXXDay */
    /* 3:  XXMonthXXDayXXXXYear */
    /* 4:  XX- XX- XXXX Day Month Year*/
    /* 5:  XXDayXXMonthXXXXYear */
	/*6: xx/xx/xxxx(Month/Day/Year) */
	/*7: xxxx/xx/xx(Year/Month/Day) */
	/*8: xx/xx/xxxx(Day/Month/Year)*/
    BYTE byDispWeek; 				/* display Week */
    BYTE byOSDAttrib; 				/* OSD attribute:  Transparent, Flash */
    /* 1:  Transparent, Flash */
    /* 2:  Transparent, not Flash */
    /* 3:  Flash, not Transparent */
    /* 4:  not Transparent,  not Flash */
    BYTE byHourOSDType; 				/* : 24- Hour system, 12- Hour system */
	BYTE byFontSize;
    BYTE byRes[63]; 
}NET_DVR_PICCFG_V30,  *LPNET_DVR_PICCFG_V30; 

//Video Structure (SDK_V14 extended) 
typedef struct 
{
    DWORD dwSize; 
    BYTE sChanName[NAME_LEN]; 
    DWORD dwVideoFormat; 	/* Read only,  Video Standard 1- NTSC 2- PAL*/
	BYTE byBrightness;  	/*0-255*/
	BYTE byContrast;    	/*0-255*/	
	BYTE bySaturation;  	/*0-255 */
	BYTE byHue;    			/*0-255*/
    //Display Channel Name
    DWORD dwShowChanName;  // Display channel name or not, 0- no, 1- display size = 704*576
    WORD wShowNameTopLeftX; 				/* X- coordinate of display position */
    WORD wShowNameTopLeftY; 				/* Y- coordinate of display position  */
    //Signal lost Alarm
    NET_DVR_VILOST struVILost; 
    //Motion Detection
    NET_DVR_MOTION struMotion; 
    //Tamper Alarm
    NET_DVR_HIDEALARM struHideAlarm; 
    //Tamper Area size:  704*576
    DWORD dwEnableHide; 		/* Enable Tamper Alarm , 0- disable, 1- enable**/
    NET_DVR_SHELTER struShelter[MAX_SHELTERNUM]; 
    //OSD
    DWORD dwShowOsd; 				// Display OSD or not, 0- No OSD, 1- Display Area for display:  704*576
    WORD wOSDTopLeftX; 				/* X- coordinate of OSD */
    WORD wOSDTopLeftY; 				/* Y- coordinate of OSD*/
    BYTE byOSDType; 					/* OSD Type  (format of Year/Month/Day)  */
    /* 0:  XXXX- XX- XX Year/Month/Day */
    /* 1:  XX- XX- XXXX Month/Day/Year */
    /* 2:  XXXXYearXXNonthXXDay */
    /* 3:  XXMonthXXDayXXXXYear */
    /* 4:  XX- XX- XXXX Day Month Year*/
    /* 5:  XXDayXXMonthXXXXYear */
	/*6: xx/xx/xxxx(Month/Day/Year) */
	/*7: xxxx/xx/xx(Year/Month/Day) */
	/*8: xx/xx/xxxx(Day/Month/Year)*/
    BYTE byDispWeek; 				/* display Week */
    BYTE byOSDAttrib; 				/* OSD attribute:  Transparent, Flash */
    /* 1:  Transparent, Flash */
    /* 2:  Transparent, not Flash */
    /* 3:  Flash, not Transparent */
    /* 4:  not Transparent,  not Flash */
    BYTE byHourOsdType; 	//hour: 0- 24 hours, 1- am/pm
}NET_DVR_PICCFG_EX,  *LPNET_DVR_PICCFG_EX; 

//Video Structure (SDK_V14 extended) 
typedef struct 
{
    DWORD dwSize; 
    BYTE sChanName[NAME_LEN]; 
    DWORD dwVideoFormat; 	/* Read only,  Video Standard 1- NTSC 2- PAL*/
	BYTE byBrightness;  	/*0-255*/
	BYTE byContrast;    	/*0-255*/	
	BYTE bySaturation;  	/*0-255 */
	BYTE byHue;    			/*0-255*/
    //Display Channel Name
    DWORD dwShowChanName;  // Display channel name or not, 0- no, 1- display size = 704*576
    WORD wShowNameTopLeftX; 				/* X- coordinate of display position */
    WORD wShowNameTopLeftY; 				/* Y- coordinate of display position  */
    //Signal lost Alarm
    NET_DVR_VILOST struVILost; 
    //Motion Detection
    NET_DVR_MOTION struMotion; 
    //Tamper Alarm
    NET_DVR_HIDEALARM struHideAlarm; 
    //Tamper Area size:  704*576
    DWORD dwEnableHide; 		/* Enable Tamper Alarm , 0- disable, 1- enable*/
    WORD wHideAreaTopLeftX; 				/* X- coordinate of tampered area*/
    WORD wHideAreaTopLeftY; 				/* Y- coordinate of tampered area */
    WORD wHideAreaWidth; 				/* Width of tampered area */
    WORD wHideAreaHeight; 				/* Height of tampered area */
    //OSD
    DWORD dwShowOsd; 				// Display OSD or not, 0- No OSD, 1- Display Area for display:  704*576
    WORD wOSDTopLeftX; 				/* X- coordinate of OSD */
    WORD wOSDTopLeftY; 				/* Y- coordinate of OSD*/
    BYTE byOSDType; 					/* OSD Type  (format of Year/Month/Day)  */
    /* 0:  XXXX- XX- XX Year/Month/Day */
    /* 1:  XX- XX- XXXX Month/Day/Year */
    /* 2:  XXXXYearXXNonthXXDay */
    /* 3:  XXMonthXXDayXXXXYear */
    /* 4:  XX- XX- XXXX Day Month Year*/
    /* 5:  XXDayXXMonthXXXXYear */
	/*6: xx/xx/xxxx(Month/Day/Year) */
	/*7: xxxx/xx/xx(Year/Month/Day) */
	/*8: xx/xx/xxxx(Day/Month/Year)*/
    BYTE byDispWeek; 				/* display Week */
    BYTE byOSDAttrib; 				/* OSD attribute:  Transparent, Flash */
    /* 1:  Transparent, Flash */
    /* 2:  Transparent, not Flash */
    /* 3:  Flash, not Transparent */
    /* 4:  not Transparent,  not Flash */
    char reservedData2; 
}NET_DVR_PICCFG,  *LPNET_DVR_PICCFG; 

//Encoding Parameters (Sub Strut)  (9000 extended) 
typedef struct 
{
    BYTE byStreamType; 		//Stream type 0- video,  1- video&audio,  when it stands for compression parameters,  the highest bit stands for whether adopt encoding parameters
    /*Resolution 0-DCIF(P528*384), 1-CIF(P352*288), 2-QCIF(P176*144), 3-4CIF(P704*576),
    4-2CIF(P704×288), 6-QVGA(320*240), 16-VGA(640*480), 17-UXGA(1600*1200), 
    18-SVGA(800*600), 19-HD720p(1280*720), 20-XVGA(1280x960), 21-HD900p(1600x900), 22-SXGAp(1360*1024),
    27-1920*1080, 28-2560*1920, 29-1600*304, 30-2048*153, 31-2448*2048, 32-2448*1200,
    33-2448*800, 34-XGA(1024*768), 35-SXGA(1280*1024), 36-WD1(960*576/960*480),37-1080i,38-WXGA(1440*900),
	39-HD_F(1920*1080/1280*720),40-HD_H(1920*540/1280*360),41-HD_Q(960*540/630*360)
	0xff-Auto(use the value of the stream)*/
    BYTE byResolution;   	
    BYTE byBitrateType; 		//Bitrate Type 0: VBR, 1: CBR
    BYTE byPicQuality; 		//Image Quality 0- best 1- much better 2- better 3- Normal 4- worse 5- worst
    /*video bit rate 0- reserved 1- 16K 2- 32K 3- 48k 4- 64K 5- 80K 6- 96K 7- 128K 8- 160k 9- 192K 10- 224K 11- 256K 12- 320K
    13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K  24-3072K 25-4096K 26-8192K 27-16384K
    if The highest bit (31 bit)  is 1,  it stands for user defined bit rate,  0- 30 is the value of bit rate*/
    DWORD dwVideoBitrate;  
    DWORD dwVideoFrameRate; //Frame rate 0- full;  1- 1/16;  2- 1/8;  3- 1/4;  4- 1/2;  5- 1;  6- 2;  7- 4;  8- 6;  9- 8;  10- 10;  11- 12;  12- 16;  13- 20; 14- 15;  15- 18;  16- 22; 
    WORD  wIntervalFrameI;  //interval of I frame
    BYTE  byIntervalBPFrame;//0- BBP frame;  1- BP frame;  2- P frame only(2006-08-11 Add single P frame).
    BYTE  byres1;           //reserve
    BYTE  byVideoEncType;   //Video Code Type:  0- private h264; 1- standard H264; 2- standard MPEG4;  3- M- JPEG
    BYTE  byAudioEncType;   //Audio Code Type:  0- OggVorbis; 1- G711_U; 2- G711_A;6- G726
	BYTE  byVideoEncComplexity; //Video encode complexity, 0-low,1-middle,2-high
    BYTE  byres[9]; //reserve
}NET_DVR_COMPRESSION_INFO_V30,  *LPNET_DVR_COMPRESSION_INFO_V30; 

//Encoding Parameters  (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_COMPRESSION_INFO_V30 struNormHighRecordPara;     //Record,  corresponding to 8000's normal
    NET_DVR_COMPRESSION_INFO_V30 struRes; 					//Reserved char reserveData[28]; 
    NET_DVR_COMPRESSION_INFO_V30 struEventRecordPara;        //Encoding parameters triggered by Events
    NET_DVR_COMPRESSION_INFO_V30 struNetPara;                //network transfer
}NET_DVR_COMPRESSIONCFG_V30,  *LPNET_DVR_COMPRESSIONCFG_V30; 

//Encoding Parameters (Sub Strut) 
typedef struct 
{
    BYTE byStreamType; 		//Stream type 0- video,  1- video&audio,  when it stands for compression parameters,  the hightest bit stands for whether adopt encoding parameters
    BYTE byResolution;   	//Resolution 0- DCIF 1- CIF,  2- QCIF,  3- 4CIF,  4- 2CIF,  5- 2QCIF (352X144)  (for Mobile DVR) 
    BYTE byBitrateType; 		//Bit rate type 0: VBR, 1: CBR
    BYTE  byPicQuality; 		//Image Quality 0- best 1- much better 2- better 3- Normal 4- worse 5- worst
    DWORD dwVideoBitrate;  	//video bit rate 0- reserved 1- 16K (reserved)  2- 32K 3- 48k 4- 64K 5- 80K 6- 96K 7- 128K 8- 160k 9- 192K 10- 224K 11- 256K 12- 320K
    // 13- 384K 14- 448K 15- 512K 16- 640K 17- 768K 18- 896K 19- 1024K 20- 1280K 21- 1536K 22- 1792K 23- 2048K
    //if The highest bit (31 bit)  is 1,  it stands for user defined bit rate,  0- 30 is the value of bit rate (MIN- 32K) 
    DWORD dwVideoFrameRate; 	//Frame rate 0- full;  1- 1/16;  2- 1/8;  3- 1/4;  4- 1/2;  5- 1;  6- 2;  7- 4;  8- 6;  9- 8;  10- 10;  11- 12;  12- 16;  13- 20; 
}NET_DVR_COMPRESSION_INFO,  *LPNET_DVR_COMPRESSION_INFO; 

//Encoding Parameters
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_COMPRESSION_INFO struRecordPara;  //Record triggered by events
    NET_DVR_COMPRESSION_INFO struNetPara; 	//Network transfer (reserved) 
}NET_DVR_COMPRESSIONCFG,  *LPNET_DVR_COMPRESSIONCFG; 

//Encoding Parameters (Sub Strut)  (extended)  Add I Frame interval
typedef struct 
{
    BYTE byStreamType; 		//Stream type 0- video,  1- video&audio, 
    BYTE byResolution;  		//Resolution 0- DCIF 1- CIF,  2- QCIF,  3- 4CIF,  4- 2CIF,  5- 2QCIF (352X144)  (for Mobile DVR) 
    BYTE byBitrateType; 		//Bit rate type 0: VBR, 1: CBR
    BYTE  byPicQuality; 		//Image Quality 0- best 1- much better 2- better 3- Normal 4- worse 5- worst
    DWORD dwVideoBitrate;  	//video bit rate 0- reserved 1- 16K (reserved)  2- 32K 3- 48k 4- 64K 5- 80K 6- 96K 7- 128K 8- 160k 9- 192K 10- 224K 11- 256K 12- 320K
    // 13- 384K 14- 448K 15- 512K 16- 640K 17- 768K 18- 896K 19- 1024K 20- 1280K 21- 1536K 22- 1792K 23- 2048K
    //if The highest bit (31 bit)  is 1,  it stands for user defined bit rate,  0- 30 is the value of bit rate (MIN- 32K MAX- 8192K) 
    DWORD dwVideoFrameRate; 	//Frame rate 0- full;  1- 1/16;  2- 1/8;  3- 1/4;  4- 1/2;  5- 1;  6- 2;  7- 4;  8- 6;  9- 8;  10- 10;  11- 12;  12- 16;  13- 20, 14- 15,  15- 18,  16- 22; 
    WORD  wIntervalFrameI;   //I Frame interval
    //2006- 08- 11 Add single P frame
    BYTE  byIntervalBPFrame; //0- BBP frame;  1- BP frame;  2- P frame only.
    BYTE  byRes; 
}NET_DVR_COMPRESSION_INFO_EX,  *LPNET_DVR_COMPRESSION_INFO_EX; 

//Encoding Parameters  (extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_COMPRESSION_INFO_EX struRecordPara;  //Record
    NET_DVR_COMPRESSION_INFO_EX struNetPara; 	//Network Transfer
}NET_DVR_COMPRESSIONCFG_EX,  *LPNET_DVR_COMPRESSIONCFG_EX; 


//Parameters Configure of Recording in Time segment  (Sub Strut) 
typedef struct 
{
    NET_DVR_SCHEDTIME struRecordTime; 
    BYTE byRecordType; 	//0: Time Record, 1: Motion detection, 2: Alarm record, 3: Motion|alarm, 4: Motion&Alarm,  5: Triggered by Commands,  6:  Intelligent Record,10-PIR,11-wireless,12-callhelp,13-motion|alarm|PIR|wireless|callhelp,14-Intelligent Transportation
    char reservedData[3]; 
}NET_DVR_RECORDSCHED,  *LPNET_DVR_RECORDSCHED; 

//Record All- day 
typedef struct 
{
    WORD wAllDayRecord; 				/* Enable record all- day or not; 0- disable, 1- enable*/
    BYTE byRecordType; 				//0: Time Record, 1: Motion detection, 2: Alarm record, 3: Motion|alarm, 4: Motion&Alarm,  5: Triggered by Commands,  6:  Intelligent Record,10-PIR,11-wireless,12-callhelp,13-motion|alarm|PIR|wireless|callhelp,14-Intelligent Transportation
    char reservedData; 
}NET_DVR_RECORDDAY,  *LPNET_DVR_RECORDDAY; 

//Recording Parameters  (9000 extended) 
typedef struct 
{
    DWORD	dwSize; 
    DWORD	dwRecord;   						/*Record or not 0- not 1- Record*/
    NET_DVR_RECORDDAY	struRecAllDay[MAX_DAYS]; 
    NET_DVR_RECORDSCHED	struRecordSched[MAX_DAYS][MAX_TIMESEGMENT_V30]; 
    DWORD	dwRecordTime; 					/* post record time  0- 5Seconds,  1- 10Seconds,  2- 30Seconds,  3- 1 Minutes,  4- 2Minutes, ,  5- 5Minutes, ,  6- 10Minutes, */
    DWORD	dwPreRecordTime; 				/* Pre- record time 0- disable 1- 5Seconds 2- 10Seconds 3- 15Seconds 4- 20Seconds 5- 25Seconds 6- 30Seconds 7- 0xffffffff */
    DWORD	dwRecorderDuration; 				/*  */
    BYTE	byRedundancyRec; 			 	/*Redundancy record to backup important data: 0/1*/
    BYTE	byAudioRec; 						/*Record audio or not*/
	BYTE	byReserve[10]; 
}NET_DVR_RECORD_V30,  *LPNET_DVR_RECORD_V30; 

//Recording Parameters
typedef struct 
{
    DWORD dwSize; 
    DWORD dwRecord;   	/*Record or not 0- not 1- Record*/
    NET_DVR_RECORDDAY struRecAllDay[MAX_DAYS]; 
    NET_DVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT]; 
    DWORD dwRecordTime; 		/* Pre- record time*/
    DWORD dwPreRecordTime; 	/* Pre- record time 0- disable 1- 5Seconds 2- 10Seconds 3- 15Seconds 4- 20Seconds 5- 25Seconds 6- 30Seconds 7- 0xffffffff  (A.F.A.P) */
}NET_DVR_RECORD,  *LPNET_DVR_RECORD; 

//PTZ protocol structure configuration
typedef struct
{ 
    DWORD dwType;                /*Type value of decoder,  increase from 1 by degrees*/    
    BYTE  byDescribe[DESC_LEN];  /*Description of decoder,  same with 8000*/    
}NET_DVR_PTZ_PROTOCOL; 

typedef struct
{    
    DWORD   dwSize;     
    NET_DVR_PTZ_PROTOCOL struPtz[PTZ_PROTOCOL_NUM]; /*200 PTZ protocols in total*/    
    DWORD   dwPtzNum;            /*Number of valid PTZ protocol, Start from 0*/
    BYTE    byRes[8]; 
}NET_DVR_PTZCFG,  *LPNET_DVR_PTZCFG; 

#define IPC_PROTOCOL_NUM      50   //max number of IP camera protocol

//PTZ protocol structure configuration
typedef struct tagNET_DVR_PROTO_TYPE
{ 
    DWORD dwType;                /*Type value of IP camera protocol,  increase from 0 by degrees*/    
    BYTE  byDescribe[DESC_LEN];  /*Description of IP camera protocol,  same with 8000*/    
}NET_DVR_PROTO_TYPE; 

typedef struct
{    
    DWORD   dwSize;     
	DWORD   dwProtoNum;            /*Number of valid PTZ protocol, Start from 0*/
    NET_DVR_PROTO_TYPE struProto[IPC_PROTOCOL_NUM]; /*200 PTZ protocols in total*/    
    BYTE    byRes[8]; 
}NET_DVR_IPC_PROTO_LIST,  *LPNET_DVR_IPC_PROTO_LIST; 


/***************************PTZ Protocol (end) ******************************/

//PTZ configuration  (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    DWORD dwBaudRate;   //Baud rate (bps) , 0- 50, 1- 75, 2- 110, 3- 150, 4- 300, 5- 600, 6- 1200, 7- 2400, 8- 4800, 9- 9600, 10- 19200,  11- 38400, 12- 57600, 13- 76800, 14- 115.2k; 
    BYTE byDataBit;     //Data bit 0- 5Seconds, 1- 6bit, 2- 7bit, 3- 8bit; 
    BYTE byStopBit;     //Stop bit 0- 1bit, 1- 2bit; 
    BYTE byParity;      //Parity 0- No parity, 1- odd, 2- even; 
    BYTE byFlowcontrol; //Flow control:  0- None, 1- software , 2- Hardware
    WORD wDecoderType;  //Decoder Type,  corresponding to PTZ list
    WORD wDecoderAddress; 	          //Decoder address: 0 -  255
    BYTE bySetPreset[MAX_PRESET_V30]; //Configure Preset or not, 0- No, 1- Yes
    BYTE bySetCruise[MAX_CRUISE_V30]; //Configure Cruise or not:  0- No, 1- Yes 
    BYTE bySetTrack[MAX_TRACK_V30];   //Configure Track or not, 0- No, 1- Yes
}NET_DVR_DECODERCFG_V30,  *LPNET_DVR_DECODERCFG_V30; 

//PTZ decoder configuration
typedef struct 
{
    DWORD dwSize; 
    DWORD dwBaudRate;   //Baud rate (bps) , 0- 50, 1- 75, 2- 110, 3- 150, 4- 300, 5- 600, 6- 1200, 7- 2400, 8- 4800, 9- 9600, 10- 19200,  11- 38400, 12- 57600, 13- 76800, 14- 115.2k; 
    BYTE byDataBit;     //Data bit 0- 5bit, 1- 6bit, 2- 7bit, 3- 8bit; 
    BYTE byStopBit;     //Stop bit 0- 1bit, 1- 2bit; 
    BYTE byParity;      //Parity 0- No parity, 1- odd, 2- even; 
    BYTE byFlowcontrol; //Flow control:  0- None, 1- software , 2- Hardware
    
    WORD wDecoderType;       //Decoder Type,  0- YouLi, 1- LiLin- 1016, 2- LiLin- 820, 3- Pelco- p, 4- DM DynaColor, 5- HD600, 6- JC- 4116, 7- Pelco- d WX, 8- Pelco- d PICO
    WORD wDecoderAddress; 	 //Decoder Address: 0 -  255
    BYTE bySetPreset[MAX_PRESET]; 		//Configure Preset or not, 0- No, 1- Yes
    BYTE bySetCruise[MAX_CRUISE]; 		//Configure Cruise or not:  0- No, 1- Yes 
    BYTE bySetTrack[MAX_TRACK]; 	    //Configure Track or not, 0- No, 1- Yes
}NET_DVR_DECODERCFG,  *LPNET_DVR_DECODERCFG; 

//ppp parameters configuration (Sub Struct) 
typedef struct 
{
    NET_DVR_IPADDR struRemoteIP; 	//Remote IP
    NET_DVR_IPADDR struLocalIP; 	//Local IP
    char sLocalIPMask[16]; 			//Local Mask
    BYTE sUsername[NAME_LEN]; 		//Username 
    BYTE sPassword[PASSWD_LEN]; 	//Password 
    BYTE byPPPMode; 				//PPP mode,  0- active, 1- passive
    BYTE byRedial; 					//Callback or not : 0- No, 1- Yes
    BYTE byRedialMode; 				//Callback, 0- user specified, 1- preseted number
    BYTE byDataEncrypt; 			//Encrypt Data , 0- No, 1- Yes
    DWORD dwMTU; 					//MTU
    char sTelephoneNumber[PHONENUMBER_LEN];    //Telephone number
}NET_DVR_PPPCFG_V30,  *LPNET_DVR_PPPCFG_V30; 

//ppp parameters configuration (Sub Struct) 
typedef struct 
{
    char sRemoteIP[16]; 		    //Remote IP
    char sLocalIP[16]; 				//Local IP
    char sLocalIPMask[16]; 			//Local Mask
    BYTE sUsername[NAME_LEN]; 		//Username 
    BYTE sPassword[PASSWD_LEN]; 	//Password 
    BYTE byPPPMode; 				//PPP mode,  0- active, 1- passive
    BYTE byRedial; 					//Callback or not : 0- No, 1- Yes
    BYTE byRedialMode; 				//Callback, 0- user specified, 1- preset number
    BYTE byDataEncrypt; 			//Encrypt Data , 0- No, 1- Yes
    DWORD dwMTU; 					//MTU
    char sTelephoneNumber[PHONENUMBER_LEN];    //Telephone number
}NET_DVR_PPPCFG,  *LPNET_DVR_PPPCFG; 

//RS232 Configuration (9000 extended) 
typedef struct
{
    DWORD dwBaudRate; //Baud rate (bps) , 0- 50, 1- 75, 2- 110, 3- 150, 4- 300, 5- 600, 6- 1200, 7- 2400, 8- 4800, 9- 9600, 10- 19200,  11- 38400, 12- 57600, 13- 76800, 14- 115.2k; 
    BYTE byDataBit;   //Data bit 0- 5bit, 1- 6bit, 2- 7bit, 3- 8bit; 
    BYTE byStopBit;   //Stop bit 0- 1bit, 1- 2bit; 
    BYTE byParity;    //Parity 0- No parity, 1- odd, 2- even; 
    BYTE byFlowcontrol; //Flow control:  0- None, 1- software , 2- Hardware
    DWORD dwWorkMode;   //Word mode, 0- 232 for PPP dial, 1- 232 for parameter control, 2- for transparent channel 3- ptz mode 4-Alarm mode
}NET_DVR_SINGLE_RS232; 

//RS232 Configuration (9000 extended) 
typedef struct 
{
    DWORD dwSize;
    NET_DVR_SINGLE_RS232 struRs232[MAX_SERIAL_PORT];/*note: this structure has change*/
    NET_DVR_PPPCFG_V30 struPPPConfig;
}NET_DVR_RS232CFG_V30,  *LPNET_DVR_RS232CFG_V30; 

//RS232 Configuration
typedef struct 
{
    DWORD dwSize; 
    DWORD dwBaudRate; //Baud rate (bps) , 0- 50, 1- 75, 2- 110, 3- 150, 4- 300, 5- 600, 6- 1200, 7- 2400, 8- 4800, 9- 9600, 10- 19200,  11- 38400, 12- 57600, 13- 76800, 14- 115.2k; 
    BYTE byDataBit;   //Data bit 0- 5bit, 1- 6bit, 2- 7bit, 3- 8bit; 
    BYTE byStopBit;   //Stop bit 0- 1bit, 1- 2bit; 
    BYTE byParity;    //Parity 0- No parity, 1- odd, 2- even; 
    BYTE byFlowcontrol; //Flow control:  0- None, 1- software , 2- Hardware
    DWORD dwWorkMode;   //Word mode, 0- 232 for PPP dial, 1- 232 for parameter control, 2- for transparent channel
    NET_DVR_PPPCFG struPPPConfig; 
}NET_DVR_RS232CFG,  *LPNET_DVR_RS232CFG; 

//Alarm Input Configuration (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    BYTE sAlarmInName[NAME_LEN]; 	//Name 
    BYTE byAlarmType; 	            //Alarm Type, 0: normally open, 1: normally close
    BYTE byAlarmInHandle; 	        //Handle alarm or not 0- No 1- Yes
    BYTE byChannel;                 //Intelligent recognition channel triggered by alarm input
    BYTE byRes1[1];			
    NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType; 	//The way to handle alarm 
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; //Guard time
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; 		//Channel triggered to record,  1- - trigger
    BYTE byEnablePreset[MAX_CHANNUM_V30]; 		//Call preset or not 0- No, 1- Yes
    BYTE byPresetNo[MAX_CHANNUM_V30]; 			//Preset No. One alarm input can trigger several presets,  0xff- disable
    BYTE byRes2[192]; 							//Reserved
    BYTE byEnableCruise[MAX_CHANNUM_V30]; 		//Call Cruise or not 0- No, 1- Yes
    BYTE byCruiseNo[MAX_CHANNUM_V30]; 			//Cruise No.
    BYTE byEnablePtzTrack[MAX_CHANNUM_V30];     //Call Track or not 0- No, 1- Yes
    BYTE byPTZTrack[MAX_CHANNUM_V30]; 			//Track No. 
    BYTE byRes3[16]; 
}NET_DVR_ALARMINCFG_V30,  *LPNET_DVR_ALARMINCFG_V30; 

//Alarm Input Configuration
typedef struct 
{
    DWORD dwSize; 
    BYTE sAlarmInName[NAME_LEN]; 	//Name 
    BYTE byAlarmType; 				//Alarm Type, 0: normally open, 1: normally close
    BYTE byAlarmInHandle; 			//Handle alarm or not 0- No 1- Yes
    BYTE byChannel;                 //Intelligent recognition channel triggered by alarm input
    BYTE byRes;                     
    NET_DVR_HANDLEEXCEPTION struAlarmHandleType; //The way to handle alarm 
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT]; //Guard time
    BYTE byRelRecordChan[MAX_CHANNUM]; 		//Channel triggered to record,  1- - trigger
    BYTE byEnablePreset[MAX_CHANNUM]; 		//Call preset or not 0- No, 1- Yes
    BYTE byPresetNo[MAX_CHANNUM]; 			//Preset No. One alarm input can trigger several presets,  set 0xff to disable
    BYTE byEnableCruise[MAX_CHANNUM]; 		//Call Cruise or not 0- No, 1- Yes
    BYTE byCruiseNo[MAX_CHANNUM]; 			//Cruise No.
    BYTE byEnablePtzTrack[MAX_CHANNUM]; 	//Call Track or not 0- No, 1- Yes
    BYTE byPTZTrack[MAX_CHANNUM]; 			//Track No. 
}NET_DVR_ALARMINCFG,  *LPNET_DVR_ALARMINCFG; 


//Upload Alarm Information  (9000 extended) 
typedef struct 
{
    DWORD dwAlarmType; /*0- sensor alarm; 1- hard disk full; 2- video lost; 3- motion detection; 4- hard disk unformatted; 5- hard disk error; 6- tampering detection; 7- unmatched video output standard; 8- illegal operation; 9- video exception; 0xa- record exception 
                        11- Vca scene change 12-Array exception 13 resolution dismatch*/
    DWORD dwAlarmInputNumber; /*Alarm input Port*/
    BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30]; /*State of Alarm output channel, 1- - Triggered*/
    BYTE byAlarmRelateChannel[MAX_CHANNUM_V30]; /*channels triggered to record, 1- recording,  dwAlarmRelateChannel[0] is the first channel*/
    BYTE byChannel[MAX_CHANNUM_V30]; /*If the dwAlarmType is 2, 3 or 6, it stands for channel, dwChannel[0] is the first channel*/
    BYTE byDiskNumber[MAX_DISKNUM_V30]; /*When dwAlarmType is 1, 4 or 5,  it stands for Hard Disk,  dwDiskNumber[0] is the first disk*/
}NET_DVR_ALARMINFO_V30,  *LPNET_DVR_ALARMINFO_V30; 

typedef struct 
{
    DWORD dwAlarmType; /*0- sensor alarm; 1- hard disk full; 2- video lost; 3- motion detection; 4- hard disk unformatted; 5- hard disk error; 6- tampering detection; 7- unmatched video output standard; 8- illegal operation; 9- video exception; 0xa- record exception*/
    DWORD dwAlarmInputNumber; /*/*Alarm input Port*/
    DWORD dwAlarmOutputNumber[MAX_ALARMOUT]; /*State of Alarm output channel, 1- - Triggered*/
    DWORD dwAlarmRelateChannel[MAX_CHANNUM]; /*channels triggered to record, 1- recording,  dwAlarmRelateChannel[0] is the first channel*/
    DWORD dwChannel[MAX_CHANNUM]; /*If the dwAlarmType is 2, 3 or 6, it stands for channel, dwChannel[0] is the first channel*/
    DWORD dwDiskNumber[MAX_DISKNUM]; /*When dwAlarmType is 1, 4 or 5,  it stands for Hard Disk,  dwDiskNumber[0] is the first disk*/
}NET_DVR_ALARMINFO,  *LPNET_DVR_ALARMINFO; 




//////////////////////////////////////////////////////////////////////////////////////
//IP Camera Parameter
/* IP Device */
//extended ipc connection functions,  support add IPC domain name
typedef struct tagNET_DVR_IPDEVINFO_V31
{
    BYTE byEnable; 				    //Valid status for IP device
    BYTE byProType; 				//Protocol type,  0- private (default) ,  1-  Panasonic,  2-  SONY
    BYTE byEnableQuickAdd;          //0-  does not support quick adding of IP device;  1-   enable quick adding of IP device
    //Quick add of device IP and protocol,  fill in the other parameters as system default 
    BYTE byRes1; 					//reserved as 0
    BYTE sUserName[NAME_LEN]; 		//user name
    BYTE sPassword[PASSWD_LEN]; 	//Password
    BYTE byDomain[MAX_DOMAIN_NAME]; //Domain name of the device
    NET_DVR_IPADDR struIP; 			//IP
    WORD wDVRPort; 			 	    //Port number
    BYTE byRes2[34]; 				//Reserved as 0
}NET_DVR_IPDEVINFO_V31,  *LPNET_DVR_IPDEVINFO_V31; 

typedef struct 
{
    DWORD dwEnable; 				/* Enable this device */
    BYTE sUserName[NAME_LEN]; 		/* Username */
    BYTE sPassword[PASSWD_LEN]; 	/* Password */ 
    NET_DVR_IPADDR struIP; 			/* IP address */
    WORD wDVRPort; 			 	    /* Port */
    BYTE byRes[34]; 		    	/* Reserved */
}NET_DVR_IPDEVINFO,  *LPNET_DVR_IPDEVINFO; 

/* IP Channel parameters */
typedef struct 
{
    BYTE byEnable; 					//0- Failed to connect IP device; 1- Successfully; 
    BYTE byIPID; 					//ID of IP device,  low 8 bit 
    BYTE byChannel; 			    //Channel No. 
	BYTE byIPIDHigh;                //ID of IP device,  high 8 bit 
    BYTE byres[32]; 				//Reserved
} NET_DVR_IPCHANINFO,  *LPNET_DVR_IPCHANINFO; 

/* Struct of connecting IP device*/
typedef struct 
{
    DWORD dwSize; 			                             /* Structure Size */
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];     /* IP Device */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];         /* Enable analog channel or not, channel 1 (low bit)  to channel 32 (high bit) , 0- invalid;  1- valid */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];   /* IP Channel */    
}NET_DVR_IPPARACFG,  *LPNET_DVR_IPPARACFG; 

typedef struct tagNET_DVR_IPPARACFG_V31
{
    DWORD dwSize; 			                             /* Structure size */
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE]; /* IP device */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];         /* Enable/disable analog channels,  stands for channel 1- 32 ,  0- disable;  1- enable */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL]; 	 /* IP channel*/    
}NET_DVR_IPPARACFG_V31,  *LPNET_DVR_IPPARACFG_V31; 

typedef  struct tagNET_DVR_IPSERVER_STREAM
{
    BYTE    byEnable;   //Is enable
    BYTE    byRes[3];
    NET_DVR_IPADDR struIPServer;   //IPServer Address
    WORD  wPort;                   //IPServer port
    WORD  wDvrNameLen;             //DVR Name Length
    BYTE   byDVRName[NAME_LEN];    //DVR Name
    WORD  wDVRSerialLen;           //Serial Length
    WORD  byRes1[2];               //reserved
    BYTE   byDVRSerialNumber[SERIALNO_LEN];    //DVR Serial
    BYTE   byUserName[NAME_LEN];               //DVR User name
    BYTE   byPassWord[PASSWD_LEN];             //DVR User password
    BYTE    byChannel;                         //DVR channel
    BYTE   byRes2[11];              //Reserved
}NET_DVR_IPSERVER_STREAM, *LPNET_DVR_IPSERVER_STREAM;

/*the configuration of stream server*/
typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG
{
    BYTE	byValid;			//Is enable
    BYTE	byRes1[3];
    NET_DVR_IPADDR  struDevIP;  //stream server IP    
    WORD	wDevPort;			//stream server Port    
    BYTE	byTransmitType;		//Protocol: 0-TCP, 1-UDP
    BYTE	byRes2[69];
}NET_DVR_STREAM_MEDIA_SERVER_CFG,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG;

//device information
typedef struct tagNET_DVR_DEV_CHAN_INFO
{
    NET_DVR_IPADDR 	struIP;		    //DVR IP address
    WORD 	wDVRPort;			 	//DVR PORT
    BYTE 	byChannel;				//Channel
    BYTE	byTransProtocol;		//Transmit protocol:0-TCP，1-UDP
    BYTE	byTransMode;			//Stream mode: 0－mian stream 1－sub stream
    BYTE	byFactoryType;			/*IPC factory type*/
    BYTE	byDeviceType; //Device type(Used by videoplatfom VCA card)，1-decoder（use decode channel No. or display channel depends on byVcaSupportChanMode in videoplatform ability struct），2-coder
    BYTE    byDispChan;//Display channel No. used by VCA configuration
    BYTE	bySubDispChan;//Display sub channel No. used by VCA configuration
	BYTE	byResolution;	//Resolution: 1-CIF 2-4CIF 3-720P 4-1080P 5-500w used by big screen controler
    BYTE	byRes[2];
    BYTE    byDomain[MAX_DOMAIN_NAME];	//Device domain name
    BYTE	sUserName[NAME_LEN];	//Remote device user name
    BYTE	sPassword[PASSWD_LEN];	//Remote device password
}NET_DVR_DEV_CHAN_INFO,*LPNET_DVR_DEV_CHAN_INFO;

typedef struct tagNET_DVR_PU_STREAM_CFG
{
    DWORD								dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG	struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG,*LPNET_DVR_PU_STREAM_CFG;

typedef struct tagNET_DVR_DDNS_STREAM_CFG
{
	BYTE   byEnable;   //Is Enable.
    BYTE   byRes1[3];
    NET_DVR_IPADDR  struStreamServer;   //Stream server IP
    WORD   wStreamServerPort;           //Stream server Port   
    BYTE   byStreamServerTransmitType;  //Stream protocol
	BYTE   byRes2;
	NET_DVR_IPADDR   struIPServer;      //IPserver IP
	WORD   wIPServerPort;               //IPserver Port
	BYTE   byRes3[2];           
    BYTE   sDVRName[NAME_LEN];     //DVR Name
	WORD   wDVRNameLen;            //DVR Name Len
    WORD   wDVRSerialLen;          //Serial Len
    BYTE   sDVRSerialNumber[SERIALNO_LEN];    //Serial number
    BYTE   sUserName[NAME_LEN];   //the user name which is used to login DVR.
    BYTE   sPassWord[PASSWD_LEN]; //the password which is used to login DVR.
	WORD   wDVRPort;        //DVR port
    BYTE   byRes4[2];    
    BYTE   byChannel;       //channel
	BYTE   byTransProtocol; //protocol 
    BYTE   byTransMode;     //transform mode
    BYTE   byFactoryType;   //The type of factory who product the device.
}NET_DVR_DDNS_STREAM_CFG, *LPNET_DVR_DDNS_STREAM_CFG;

typedef struct tagNET_DVR_PU_STREAM_URL
{
	BYTE    byEnable; 
	BYTE    strURL[240];
	BYTE    byRes[11];   
}NET_DVR_PU_STREAM_URL, *LPNET_DVR_PU_STREAM_URL;

typedef  struct tagNET_DVR_HIDDNS_STREAM
{
    BYTE    byEnable;   //Is enable
    BYTE    byRes[3];
    BYTE    byDDNSDomain[64];    // HiDDNS domain
    WORD	wPort;                   //IPServer port
    WORD	wAliasLen;               //Alias Length
    BYTE	byAlias[NAME_LEN];		 //Alias
    WORD	wDVRSerialLen;           //Serial Length
    BYTE	byRes1[2];               //reserved
    BYTE	byDVRSerialNumber[SERIALNO_LEN];    //DVR Serial
    BYTE	byUserName[NAME_LEN];               //DVR User name
    BYTE	byPassWord[PASSWD_LEN];             //DVR User passward
    BYTE    byChannel;                          //DVR channel
    BYTE	byRes2[11];              //Reserved
}NET_DVR_HIDDNS_STREAM, *LPNET_DVR_HIDDNS_STREAM;

typedef union tagNET_DVR_GET_STREAM_UNION
{
    NET_DVR_IPCHANINFO      struChanInfo;	     //Get stream from Device.
    NET_DVR_IPSERVER_STREAM struIPServerStream;  //Get stream from Device which register the IPServer
    NET_DVR_PU_STREAM_CFG   struPUStream;         //Get stream from stream server.
	NET_DVR_DDNS_STREAM_CFG struDDNSStream;      //Get stream by IPserver and stream server.
	NET_DVR_PU_STREAM_URL   struStreamUrl;        //get stream through stream server by url.
	NET_DVR_HIDDNS_STREAM struHiDDNSStream;   //get stream through HiDDNS
}NET_DVR_GET_STREAM_UNION, *LPNET_DVR_GET_STREAM_UNION;

typedef enum
{
    NET_SDK_IP_DEVICE = 0,
    NET_SDK_STREAM_MEDIA,
    NET_SDK_IPSERVER,
	NET_SDK_DDNS_STREAM_CFG,
	NET_SDK_STREAM_MEDIA_URL,
	NET_SDK_HIDDNS
}GET_STREAM_TYPE;

typedef struct tagNET_DVR_STREAM_MODE
{
    BYTE    byGetStreamType; //the type of gettin stream:0-Get stream from Device, 1-Get stream fram stream server, 
	                         //2-Get stream from Device which register the IPServer, 3.Get stream by IPserver and stream server
	                         //4-get stream by url
	BYTE    byRes[3];        //reserved
    NET_DVR_GET_STREAM_UNION uGetStream;    //the union of different getting stream type.
}NET_DVR_STREAM_MODE, *LPNET_DVR_STREAM_MODE;


typedef struct tagNET_DVR_IPPARACFG_V40
{
    DWORD      dwSize;			            //Size
    DWORD		dwGroupNum;					//The number of group    
    DWORD      dwAChanNum;					//The number of simulate channel
    DWORD      dwDChanNum;                  //the number of IP channel
    DWORD      dwStartDChan;		        //the begin NO. of IP channel
    BYTE       byAnalogChanEnable[MAX_CHANNUM_V30];    //Is simulate channel enable? represent by bit
    NET_DVR_IPDEVINFO_V31   struIPDevInfo[MAX_IP_DEVICE_V40];      //IP device
    NET_DVR_STREAM_MODE  struStreamMode [MAX_CHANNUM_V30];
    BYTE            byRes2[20];                 //reserved
}NET_DVR_IPPARACFG_V40, *LPNET_DVR_IPPARACFG_V40;

#define COMM_ALARM_DEVICE           0x4004

typedef struct tagNET_DVR_ALARMINFO_DEV
{
	DWORD     dwAlarmType;    //type
	NET_DVR_TIME   struTime;  //time
	BYTE       byRes[32];     //reserved
	DWORD      dwNumber;      //number
	WORD       *pNO;          
}NET_DVR_ALARMINFO_DEV, *LPNET_DVR_ALARMINFO_DEV;

/* Alarm output channel */
typedef struct 
{
    BYTE byIPID; 					/* ID of IP device,  the range:  1 to MAX_IP_DEVICE */
    BYTE byAlarmOut; 				/* Alarm output NO. */
    BYTE byRes[18]; 				/* Reserved */
}NET_DVR_IPALARMOUTINFO,  *LPNET_DVR_IPALARMOUTINFO; 

/* IP Alarm output configuration */
typedef struct 
{
    DWORD dwSize; 												/*struct size */    
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP alarm output */
}NET_DVR_IPALARMOUTCFG,  *LPNET_DVR_IPALARMOUTCFG; 

/* Alarm input parameters */
typedef struct 
{
    BYTE byIPID; 					/* ID of IP device,  the range:  1 to MAX_IP_DEVICE */
    BYTE byAlarmIn; 				/* Alarm input NO. */
    BYTE byRes[18]; 				/* Reserved */
}NET_DVR_IPALARMININFO,  *LPNET_DVR_IPALARMININFO; 

/* IP Alarm input configuration */
typedef struct 
{
    DWORD dwSize; 											 /*struct size */  				  
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];  /* IP alarm input */
}NET_DVR_IPALARMINCFG,  *LPNET_DVR_IPALARMINCFG; 

//IP Camera alarm info
typedef struct 
{
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];             /* IP Device */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                 /* Enable analog channel or not, 0- Enable;  1- Disable */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL]; 	         /* IP Channel */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];     /* IP Alarm input */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];  /* IP Alarm output */
}NET_DVR_IPALARMINFO,  *LPNET_DVR_IPALARMINFO; 

//IPC configuration change alarm  (Extended for 9000_1.1) 
typedef struct tagNET_DVR_IPALARMINFO_V31
{
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];         /* IP device*/
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                 /* Enable/ disable analog channel,  0-  disable;  1- enable */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL]; 	         /* IP channel */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];     /* IP alarm input */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];  /* IP alarm output */   
}NET_DVR_IPALARMINFO_V31,  *LPNET_DVR_IPALARMINFO_V31; 

typedef struct tagNET_DVR_IPALARMINFO_V40
{
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE_V40];     //IP device
    BYTE     byAnalogChanEnable[MAX_CHANNUM_V30];               //Enable analog channel or not: 0- disable, 1- enable
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_CHANNUM_V30];	        //IP channel
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    //IP alarm input 
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; //IP alarm output   
    BYTE                    byRes[20];                          //Reserved
}NET_DVR_IPALARMINFO_V40, *LPNET_DVR_IPALARMINFO_V40;

typedef enum _HD_STAT_
{
    HD_STAT_OK					=	0,   /* Normal */
    HD_STAT_UNFORMATTED			=	1,   /* Raw */
    HD_STAT_ERROR           	=	2,   /* Error */
    HD_STAT_SMART_FAILED    	=	3,   /* SMART State */
    HD_STAT_MISMATCH        	=	4,   /* Unmatched */
    HD_STAT_IDLE            	=	5,   /* Sleep*/
    NET_HD_STAT_OFFLINE     	=	6,   /* Net Disk is off line */
	HD_RIADVD_EXPAND            =   7,   /* riad virtual disk expand */
	HD_STAT_REPARING            =   10,  /* disk is repairing */
	HD_STAT_FORMATING           =   11,  /* disk is formating */ 
}HD_STAT; 

//Configuration of local Hard Disk
typedef struct
{
    DWORD dwHDNo;          /*Hard Disk No.  (0~MAX_DISKNUM_V30- 1)  */
    DWORD dwCapacity;      /*Capacity (Read only) */
    DWORD dwFreeSpace;     /*Free space (Read only) */
    DWORD dwHdStatus;      /*Disk status (Read only)  0- Normal,  1- Raw,  2- Error,  3- SMART State,  4- Unmatched,  5- Sleep*/
    BYTE  byHDAttr;        /*0- Default,  1- Redundancy;  2- Read only, , 3- iSCSI disk*/
	BYTE  byHDType;		   /*0- Local HD,1-ESATA HD,2-NAS HD,3-iSCSI HD 4-Array Virtual Disk*/
    BYTE  byDiskDriver;    //The value means its ANSC character, added for IVMS device
    BYTE  byRes1[1];
    DWORD dwHdGroup;       //Disk Group  (1- MAX_HD_GROUP) 
	BYTE  byRecycling;	   //  0：no reuse，1：reuse
    BYTE  byRes2[119]; 
}NET_DVR_SINGLE_HD,  *LPNET_DVR_SINGLE_HD; 

typedef struct
{
    DWORD dwSize; 
    DWORD dwHDCount;                               //Number of Disk (Read only)
    NET_DVR_SINGLE_HD struHDInfo[MAX_DISKNUM_V30]; //Reboot Device to take effect
}NET_DVR_HDCFG,  *LPNET_DVR_HDCFG; 

//Local Disk Group Configuration
typedef struct
{
    DWORD dwHDGroupNo;        /*Group NO. (Read only)  1- MAX_HD_GROUP*/        
    BYTE byHDGroupChans[MAX_CHANNUM_V30];  /*Corresponding Channel of HD Group,  0- Not record in this group, 1- Record in this group*/
    BYTE byRes[8]; 
}NET_DVR_SINGLE_HDGROUP,  *LPNET_DVR_SINGLE_HDGROUP; 

typedef struct
{
    DWORD dwSize; 
    DWORD dwHDGroupCount;         /*Total groups (Read only) */
    NET_DVR_SINGLE_HDGROUP struHDGroupAttr[MAX_HD_GROUP]; //Reboot Device to take effect
}NET_DVR_HDGROUP_CFG,  *LPNET_DVR_HDGROUP_CFG; 


//Display Scale Configuration
typedef struct
{
    DWORD dwSize; 
    DWORD dwMajorScale;     /* Main Screen  0- No Scale, 1- Scale*/
    DWORD dwMinorScale;     /* AUX Screen   0- No Scale, 1- Scale*/
    DWORD dwRes[2]; 
}NET_DVR_SCALECFG,  *LPNET_DVR_SCALECFG; 



//DVR Alarm output (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    BYTE sAlarmOutName[NAME_LEN]; 	/* Name */
    DWORD dwAlarmOutDelay; 			/* Alarm Duration (- 1- - Stop manually)  */
    //0- 5 Sec, 1- 10Sec, 2- 30Sec, 3- 1Min, 4- 2Min, 5- 5Min, 6- 10Min, 7- Stop Manually
    NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /* Time Segment for Alarm output */
    BYTE byRes[16]; 
}NET_DVR_ALARMOUTCFG_V30,  *LPNET_DVR_ALARMOUTCFG_V30; 

//DVR Alarm output
typedef struct 
{
    DWORD dwSize; 
    BYTE sAlarmOutName[NAME_LEN]; 	/* Name */
    DWORD dwAlarmOutDelay; 	/* Alarm Duration (- 1- - Stop manually)  */
    //0- 5Sec, 1- 10Sec, 2- 30Sec, 3- 1Min, 4- 2Min, 5- 5Min, 6- 10Min, 7- Stop Manually
    NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT];  /* Time Segment for Alarm output */
}NET_DVR_ALARMOUTCFG,  *LPNET_DVR_ALARMOUTCFG; 

//DVR Local Preview (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    BYTE byPreviewNumber; //Number of preview channels, 0- 1 window, 1- 4 windows, 2- 9 windows, 3- 16 windows, 0xff:  largest
    BYTE byEnableAudio; //Preview audio, 0- No, 1- Yes
    WORD wSwitchTime; //duration to switch, 0- disable, 1- 5s, 2- 10s, 3- 20s, 4- 30s, 5- 60s, 6- 120s, 7- 300s
    BYTE bySwitchSeq[MAX_PREVIEW_MODE][MAX_WINDOW_V30]; //Order to switch,  lSwitchSeq[i]==0xff- not used
    BYTE byRes[24]; 
}NET_DVR_PREVIEWCFG_V30,  *LPNET_DVR_PREVIEWCFG_V30; 
//DVR Local Preview 
typedef struct 
{
    DWORD dwSize; 
    BYTE byPreviewNumber; //Number of preview channels, 0- 1 window, 1- 4 windows, 2- 9 windows, 3- 16 windows, 0xff:  largest
    BYTE byEnableAudio; //Preview audio, 0- No, 1- Yes
    WORD wSwitchTime; //duration to switch, 0- disable, 1- 5s, 2- 10s, 3- 20s, 4- 30s, 5- 60s, 6- 120s, 7- 300s
    BYTE bySwitchSeq[MAX_WINDOW]; //Order to switch,  lSwitchSeq[i] 0xff- not used
}NET_DVR_PREVIEWCFG,  *LPNET_DVR_PREVIEWCFG; 

//DVR video output
typedef struct 
{
    WORD wResolution; 						    	/* Resolution */
    WORD wFreq; 									/* Refresh rate */
    DWORD dwBrightness; 							/* Brightness */
}NET_DVR_VGAPARA; 

/*
* MATRIX Output Configuration
*/
typedef struct
{		
    WORD	wOrder[MAX_ANALOG_CHANNUM]; 		/* Preview order,  0xff means this channel is disabled */
    WORD	wSwitchTime; 					    /* Time to witch */
    BYTE	res[14]; 
}NET_DVR_MATRIXPARA_V30,  *LPNET_DVR_MATRIXPARA_V30; 

typedef struct 
{
    WORD wDisplayLogo; 						/* Display Channel No. */
    WORD wDisplayOsd; 						/* Display Time */
}NET_DVR_MATRIXPARA; 

typedef struct 
{
    BYTE byVideoFormat; 					/* Video Standard, 0- PAL, 1- NTSC */
    BYTE byMenuAlphaValue; 					/* the contrast between Menu and background image */
    WORD wScreenSaveTime; 					/* Screen Saver 0- Never, 1- 1Min, 2- 2Min, 3- 5Min, 4- 10Min, 5- 20Min, 6- 30Min */
    WORD wVOffset; 							/* Offset of video output */
    WORD wBrightness; 						/* Brightness*/
    BYTE byStartMode; 						/* Video output mode (0: Menu, 1: Preview) */
    BYTE byEnableScaler;                    /* Enable Scale  (0- Disable,  1- Enable) */
}NET_DVR_VOOUT; 

//DVR Video output  (9000 extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT_V30]; 
    NET_DVR_VGAPARA struVGAPara[MAX_VGA_V30]; 					/* VGA Parameter */
    NET_DVR_MATRIXPARA_V30 struMatrixPara[MAX_MATRIXOUT]; 		/* MATRIX Parameter */
    BYTE byRes[16]; 
}NET_DVR_VIDEOOUT_V30,  *LPNET_DVR_VIDEOOUT_V30; 

//DVR Video Output
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT]; 
    NET_DVR_VGAPARA struVGAPara[MAX_VGA]; 	/* VGA Parameter */
    NET_DVR_MATRIXPARA struMatrixPara; 		/* MATRIX Parameter */
}NET_DVR_VIDEOOUT,  *LPNET_DVR_VIDEOOUT; 

//Single User Parameters (Sub Struct)  (9000 extended) 
typedef struct
{
    BYTE sUserName[NAME_LEN]; 		/* Username */
    BYTE sPassword[PASSWD_LEN]; 	/* Password */
    BYTE byLocalRight[MAX_RIGHT]; 	/* Local privilege */
                                    /*   
                                    array 0:  local PTZ control
                                    array 1:  local manual record
                                    array 2:  local playback
                                    array 3:  local configuration 
                                    array 4:  local log & status query 
                                    array 5:  local advanced settings  (upgrade,  format,  reboot,  shut down) 
                                    array 6:  local parameter check
                                    array 7:  local analog & IP camera management 
                                    array 8:  local backup
                                    array 9:  local shut down/reboot
									*/
    
    BYTE byRemoteRight[MAX_RIGHT]; /* remote privilege settings */
                                  /* 
                                  array 0:  remote PTZ control
                                  array 1:  remote manual record
                                  array 2:  remote playback
                                  array 3:  remote configuration 
                                  array 4:  remote log & status query
                                  array 5:  remote advanced settings  (upgrade,  format,  reboot,  shut down) 
                                  array 6:  remote start voice talk
                                  array 7:  remote preview
                                  array 8: remote alarm upload to center,  alarm output
                                  array 9: remote control local output
                                  array 10: remote serial port control
                                  array 11:  remote parameter query
                                  array 12:  remote analog & IP camera management
                                  array 13:  remote shut down/reboot
								  */
    BYTE byNetPreviewRight[MAX_CHANNUM_V30]; 		/* remote preview channel ,  0- enable,  1- disable*/
    BYTE byLocalPlaybackRight[MAX_CHANNUM_V30]; 		/* local playback channel ,  0- enable,  1- disable*/
    BYTE byNetPlaybackRight[MAX_CHANNUM_V30]; 		/* remote playback channel ,  0- enable,  1- disable*/
    BYTE byLocalRecordRight[MAX_CHANNUM_V30]; 		/* local record channel ,  0- enable,  1- disable*/
    BYTE byNetRecordRight[MAX_CHANNUM_V30]; 		/* remote record channel ,  0- enable,  1- disable*/
    BYTE byLocalPTZRight[MAX_CHANNUM_V30]; 		/* local PTZ channel ,  0- enable,  1- disable*/
    BYTE byNetPTZRight[MAX_CHANNUM_V30]; 			/* remote PTZ channel ,  0- enable,  1- disable*/
    BYTE byLocalBackupRight[MAX_CHANNUM_V30]; 		/* local backup channel ,  0- enable,  1- disable*/
    NET_DVR_IPADDR struUserIP; 		/* User IP  (0 stands for no IP restriction)  */
    BYTE byMACAddr[MACADDR_LEN]; 	/* MAC */
    BYTE byPriority; 				/* Priority settings ,  0xff-  disable ,  0- low,  1- Mid,  2- High */
                                    /*
                                    Low……Default privileges including local/remote playback,  log & status query,  reboot/shut down.
                                    Mid……Include local/remote PTZ control,  manual record,  voice talk,  playback,  log & status query,  reboot/shut down,  log backup and remote preview. 
                                    High……Administrator
									*/
    BYTE	byAlarmOnRight;         // Alarm In guard privileges
    BYTE	byAlarmOffRight;        // Alarm In unguard privileges
    BYTE	byBypassRight;          // Alarm In bypass privileges
    BYTE	byRes[14];	
}NET_DVR_USER_INFO_V30,  *LPNET_DVR_USER_INFO_V30; 

//Single User Parameters (SDK_V15extended)  (Sub Structure) 
typedef struct 
{
    BYTE sUserName[NAME_LEN]; 		/* Username */
    BYTE sPassword[PASSWD_LEN]; 	/* Password */
    DWORD dwLocalRight[MAX_RIGHT]; 	/* privilege */
                                    /*
                                    array 0- local PTZ control
                                    array 1- local manual record
                                    array 2- local playback
                                    array 3- local configuration
                                    array 4- local log & status query
                                    array 5- local advanced settings  (upgrade,  format,  reboot,  shut down) 
									*/
    DWORD dwLocalPlaybackRight; 		/*  local playback channel. 1 bit0 - -  channel 1*/
    DWORD dwRemoteRight[MAX_RIGHT]; 	/* privilege */
                                    /*
                                    array 0- remote  PTZ control
                                    array 1- remote manual record
                                    array 2- remote playback
                                    array 3- remote configuration
                                    array 4- remote log & status query
                                    array 5- remote advanced settings  (upgrade,  format,  reboot,  shut down) 
                                    array 6- remote start voice talk
                                    array 7- remote preview
                                    array 8- remote alarm upload to center,  alarm output
                                    array 9- remote control local output
                                    array 10- remote serial port control
									*/
    DWORD dwNetPreviewRight; 		/* remote preview channel number,  bit0 - -  channel 1*/
    DWORD dwNetPlaybackRight; 		/* remote playback channel number,  bit0 - -  channel 1*/
    char sUserIP[16]; 				/* User IP  (0 stands for no IP restriction)  */
    BYTE byMACAddr[MACADDR_LEN]; 	/* MAC */
}NET_DVR_USER_INFO_EX,  *LPNET_DVR_USER_INFO_EX; 

//Single User Parameters (Sub Structure) 
typedef struct 
{
    BYTE sUserName[NAME_LEN]; 		/* Username */
    BYTE sPassword[PASSWD_LEN]; 	/* Password */
    DWORD dwLocalRight[MAX_RIGHT]; 	/* privilege */
                                    /*
                                    array 0- local PTZ control
                                    array 1- local manual record
                                    array 2- local playback
                                    array 3- local configuration
                                    array 4- local log & status query
                                    array 5- local advanced settings  (upgrade,  format,  reboot,  shut down) 
    */
    DWORD dwRemoteRight[MAX_RIGHT]; /* privilege */
                                    /*
                                    array 0- remote  PTZ control
                                    array 1- remote manual record
                                    array 2- remote playback
                                    array 3- remote configuration
                                    array 4- remote log & status query
                                    array 5- remote advanced settings  (upgrade,  format,  reboot,  shut down) 
                                    array 6- remote start voice talk
                                    array 7- remote preview
                                    array 8- remote alarm upload to center,  alarm output
                                    array 9- remote control local output
                                    array 10- remote serial port control
    */
    char sUserIP[16]; 				/* User IP  (0 stands for no IP restriction)  */
    BYTE byMACAddr[MACADDR_LEN]; 	/* MAC */
}NET_DVR_USER_INFO,  *LPNET_DVR_USER_INFO; 


//DVR User Parameters (9000extended) 
typedef struct
{
    DWORD dwSize; 
    NET_DVR_USER_INFO_V30 struUser[MAX_USERNUM_V30]; 
}NET_DVR_USER_V30,  *LPNET_DVR_USER_V30; 

//DVR User Parameters (SDK_V15extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_USER_INFO_EX struUser[MAX_USERNUM]; 
}NET_DVR_USER_EX,  *LPNET_DVR_USER_EX; 

//DVR User Parameters
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_USER_INFO struUser[MAX_USERNUM]; 
}NET_DVR_USER,  *LPNET_DVR_USER; 

//DVR Exception Parameters (9000extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_HANDLEEXCEPTION_V30 struExceptionHandleType[MAX_EXCEPTIONNUM_V30]; 
    /*array 0-  hard disk is full,  1-  hard disk error,  2-  signal lost,  3-  network link is broken,  4- illegal access,  5-  input/output video standard not match,  6- overspeed Car (for mobile DVR) ,  7- record exception 8-raid exception*/
}NET_DVR_EXCEPTION_V30,  *LPNET_DVR_EXCEPTION_V30; 

//DVR Exception Parameters
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_HANDLEEXCEPTION struExceptionHandleType[MAX_EXCEPTIONNUM]; 
    /*array 0-  hard disk is full,  1-  hard disk error,  2-  signal lost,  3-  network link is broken,  4- illegal access,  5-  input/output video standard not match,  6- overspeed Car (for mobile DVR) */
}NET_DVR_EXCEPTION,  *LPNET_DVR_EXCEPTION; 

//Channel State (9000 extended) 
typedef struct 
{
    BYTE byRecordStatic;  //whether the channel is in recording,  0-  no,  1-  yes
    BYTE bySignalStatic;  //video signal status,  0-  normal,  1-  lost
    BYTE byHardwareStatic; //the channel hardware status,  0-  normal,  1-  abnormal,  e.g. DSP is not work
    BYTE byRes1; 		//Reserved
    DWORD dwBitRate; 	//actual bit rate
    DWORD dwLinkNum; 	//connected client number
    NET_DVR_IPADDR struClientIP[MAX_LINK]; //client IP referred to NET_DVR_IPADDR
    DWORD dwIPLinkNum; //if the current channel is set as IPC channel,  then this parameter represents the current connected IP channel number.
	BYTE byExceedMaxLink;   // 0-less than 6 link, 1 more than 6 link
    BYTE byRes[11];         // Reserved
}NET_DVR_CHANNELSTATE_V30,  *LPNET_DVR_CHANNELSTATE_V30; 

//Channel State
typedef struct 
{
    BYTE byRecordStatic;        //Whether the channel is in recording,  0-  no,  1-  yes
    BYTE bySignalStatic;        //Video signal status,  0-  normal,  1-  lost
    BYTE byHardwareStatic;      //The channel hardware status,  0-  normal,  1-  abnormal,  e.g. DSP is not work
    char reservedData; 		    //Reserved
    DWORD dwBitRate; 	        //Actual bit rate
    DWORD dwLinkNum; 	        //Connected client number
    DWORD dwClientIP[MAX_LINK]; //Client IP
}NET_DVR_CHANNELSTATE,  *LPNET_DVR_CHANNELSTATE; 

//Hard Disk Status
typedef struct 
{
    DWORD dwVolume; //Capacity
    DWORD dwFreeSpace; //Free Space
    DWORD dwHardDiskStatic;  //HD status: 0- active; 1- sleep mode; 2- abnormal;  3-  sleep mode error, 4-not format, 5- can't connect(net disk) 6- being formating.
}NET_DVR_DISKSTATE,  *LPNET_DVR_DISKSTATE; 

//DVR Work State (9000 extended) 
typedef struct 
{
    DWORD dwDeviceStatic;  	//the device's status,  0-  normal,  1-  the occupancy of CPU is too high,  more than 85%,  2- hardware error,  e.g. the serial ports do not work
    NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];  
    NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30]; //channel status  as NET_DVR_CHANNELSTATE
    BYTE  byAlarmInStatic[MAX_ALARMIN_V30];  //alarm input status,  0-  no alarm,  1- alarm
    BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30];  //alarm output status,  0- no output,  1- alarm output
    DWORD  dwLocalDisplay; //Local display status,  0-  normal,  1- abnormal
    BYTE  byAudioChanStatus[MAX_AUDIO_V30]; //Audio channel status,  0- unused;  1- on using; 0xff- invalid
    BYTE  byRes[10]; 
}NET_DVR_WORKSTATE_V30,  *LPNET_DVR_WORKSTATE_V30; 

//DVR Status Structure 
typedef struct 
{
    DWORD dwDeviceStatic;  	//the device's status,  0-  normal,  1-  the occupancy of CPU is too high,  more than 85%,  2- hardware error,  e.g. the serial ports do not work
    NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM]; 
    NET_DVR_CHANNELSTATE struChanStatic[MAX_CHANNUM]; //channel status  as NET_DVR_CHANNELSTATE
    BYTE  byAlarmInStatic[MAX_ALARMIN]; 			//alarm input status,  0-  no alarm,  1- alarm
    BYTE  byAlarmOutStatic[MAX_ALARMOUT]; 		//alarm output status,  0- no output,  1- alarm output
    DWORD  dwLocalDisplay; 						//Local display status,  0-  normal,  1- abnormal
}NET_DVR_WORKSTATE,  *LPNET_DVR_WORKSTATE; 



/************************ Alarm-host log searching begin************************************************/
typedef struct tagNET_DVR_ALARMHOST_SEARCH_LOG_PARAM
{
    WORD            wMajorType;		// Major type
    WORD            wMinorType;		// Minor type 
    NET_DVR_TIME    struStartTime;	// Start time 
    NET_DVR_TIME    struEndTime;	// End time
    BYTE            byRes[8];		// Reserved
}NET_DVR_ALARMHOST_SEARCH_LOG_PARAM, LPNET_DVR_ALARMHOST_SEARCH_LOG_PARAM;

typedef struct tagNET_DVR_ALARMHOST_LOG_RET
{
    NET_DVR_TIME	struLogTime;                // Log time
    BYTE		    sUserName[NAME_LEN];        // Operator user
    NET_DVR_IPADDR	struIPAddr;                 // Operator IP address
    WORD		    wMajorType;                 // Major type 
    WORD		    wMinorType;                 // Minor type
    WORD	    	wParam;	                    // Operation parameter
    BYTE		    byRes[10];
    DWORD		    dwInfoLen;	                // Length of description information
    char			sInfo[LOG_INFO_LEN];        // Description information
}NET_DVR_ALARMHOST_LOG_RET, *LPNET_DVR_ALARMHOST_LOG_RET;

/************************* Alarm-host log searching end***********************************************/

//Alarm output state (9000 extended) 
typedef struct 
{
    BYTE Output[MAX_ALARMOUT_V30]; 
}NET_DVR_ALARMOUTSTATUS_V30,  *LPNET_DVR_ALARMOUTSTATUS_V30; 

//Alarm output state
typedef struct 
{
    BYTE Output[MAX_ALARMOUT]; 
}NET_DVR_ALARMOUTSTATUS,  *LPNET_DVR_ALARMOUTSTATUS; 

//Transaction Info
typedef struct 
{
    USHORT m_Year; 
    USHORT m_Month; 
    USHORT m_Day; 
    USHORT m_Hour; 
    USHORT m_Minute; 
    USHORT m_Second; 
    BYTE DeviceName[24]; 	//Device name
    DWORD dwChannelNumer; 	//Channel name
    BYTE CardNumber[32]; 	//Credit Card No.
    char cTradeType[12]; 	//Transaction type	
    DWORD dwCash; 			//Transaction money 
}NET_DVR_TRADEINFO,  *LPNET_DVR_TRADEINFO; 


//Special for ATM
/****************************ATM (begin) ***************************/
#define NCR				0
#define DIEBOLD			1
#define WINCOR_NIXDORF	2
#define SIEMENS			3
#define OLIVETTI		4
#define FUJITSU			5
#define HITACHI			6
#define SMI				7
#define IBM				8
#define BULL			9
#define YiHua			10
#define LiDe			11
#define GDYT			12
#define Mini_Banl		13
#define GuangLi			14
#define DongXin			15
#define ChenTong		16
#define NanTian			17
#define XiaoXing		18
#define GZYY			19
#define QHTLT			20
#define DRS918			21
#define KALATEL			22
#define NCR_2			23	
#define NXS				24


/*Frame Type*/
typedef struct 
{
    BYTE code[12]; 		/* code */
}NET_DVR_FRAMETYPECODE; 

//ATM Parameters
typedef struct 
{
    DWORD dwSize; 
    char sATMIP[16]; 							/* ATM IP */
    DWORD dwATMType; 							/* ATM Type*/
    DWORD	dwInputMode; 						/* 0-  network listening 1- network receive; 2-directly input via serial port; 3-input ATM command via serial port*/
    DWORD	dwFrameSignBeginPos; 				/* the start position of Message flag*/
    DWORD	dwFrameSignLength; 					/* the length of Message flag */
    BYTE	byFrameSignContent[12]; 			/* the content of Message flag */
    DWORD	dwCardLengthInfoBeginPos; 			/* offset of credit card No. length information */
    DWORD	dwCardLengthInfoLength; 			/* the length of the card length information */
    DWORD	dwCardNumberInfoBeginPos; 			/* Start position of the card number information */
    DWORD	dwCardNumberInfoLength; 			/* Length of the card number information */
    DWORD	dwBusinessTypeBeginPos; 			/* the offset of operation type information */
    DWORD	dwBusinessTypeLength; 				/* the length of the operation type */
    NET_DVR_FRAMETYPECODE	frameTypeCode[10]; 	/* type */
}NET_DVR_FRAMEFORMAT,  *LPNET_DVR_FRAMEFORMAT; 

//SDK_V31 ATM
/*1.1.1.18	Structure of package filter*/
typedef struct	tagNET_DVR_FILTER
{	
    BYTE			        byEnable; 			//0,  disable;  1,  enable
    BYTE					byMode; 			//0, ASCII; 1, HEX	
    BYTE                    byFrameBeginPos;    //begin position of target text  
    BYTE					byRes[1];           //Reserved
    BYTE 					byFilterText[16]; 	//filter text
    BYTE					byRes2[12];         //Reserved
}NET_DVR_FILTER,  *LPNET_DVR_FILTER; 

//Package structure of starting flag
typedef struct	tagNET_DVR_IDENTIFICAT
{	
    BYTE					byStartMode; 		//start mode: 0, ASCII; 1, HEX
    BYTE					byEndMode; 			//end mode:  0, ASCII; 1, HEX
    BYTE					byRes[2];           //Reserved
    NET_DVR_FRAMETYPECODE	struStartCode; 		//start code
    NET_DVR_FRAMETYPECODE	struEndCode; 		//end code
    BYTE					byRes1[12];         //Reserved
}NET_DVR_IDENTIFICAT,  *LPNET_DVR_IDENTIFICAT; 

typedef struct	tagNET_DVR_PACKAGE_LOCATION/* package information position*/
{	
    BYTE 					byOffsetMode; 			/* 0, token (character flag mode) ; 1, fix (fix mode) */
    BYTE                    byRes1[3]; 				// Reserved
    DWORD  				    dwOffsetPos; 			/*Used when mode is 1,  offset size*/
    NET_DVR_FRAMETYPECODE	struTokenCode; 			/*Flag bit*/
    BYTE					byMultiplierValue; 		/*number of Flags*/
    BYTE					byEternOffset; 			/*extern offset*/
    BYTE					byCodeMode; 			/*0, ASCII; 1, HEX*/
    BYTE 					byRes2[9]; 			    //Reserved
}NET_DVR_PACKAGE_LOCATION,  *LPNET_DVR_PACKAGE_LOCATION; 


typedef struct	tagNET_DVR_PACKAGE_LENGTH//package length
{	
    BYTE					byLengthMode; 			//length mode:  0,  variable;  1,  fixed ; 2, gotten from package (Used when setting the card number length ) 
    BYTE                    byRes1[3];              // Reserved
    DWORD  			    	dwFixLength; 			//Used when mode is 1,  fixed length
    DWORD					dwMaxLength;            //Maximum length  byLengthMode is 0 
    DWORD					dwMinLength;            //Minimum length  byLengthMode is 0
    BYTE					byEndMode; 			    //Terminator:  0, ASCII; 1, HEX	
    BYTE                    byRes2[3];              //Reserved
    NET_DVR_FRAMETYPECODE	struEndCode; 			//Terminator with variable length
    DWORD					dwLengthPos; 			//Used when length mode is 2,  card length position in the package
    DWORD					dwLengthLen; 			//Used when length mode is 2,  length of the card number length
    BYTE					byRes3[8];              // Reserved
}NET_DVR_PACKAGE_LENGTH, * LPNET_DVR_PACKAGE_LENGTH; 

typedef struct	tagNET_DVR_OSD_POSITION//OSD overlay position
{	
    BYTE					byPositionMode; 		//Mode,  0:  not display,  1: Custom
    BYTE                    byRes1[3];              // Reserved
    DWORD 					dwPosX; 				//X- coordinator,  used when position mode is custom
    DWORD					dwPosY; 				//Y- coordinator,  used when position mode is custom
    BYTE					byRes2[8];              //Reserved
}NET_DVR_OSD_POSITION,  *LPNET_DVR_OSD_POSITION; 

typedef struct	tagNET_DVR_DATE_FORMAT//date display format
{	
    BYTE					byMonth; 			    //Month, 0-mm; 1-mmm; 2-mmmm							
    BYTE 					byDay; 				    //Day, 0-dd; 									
    BYTE 					byYear; 				//Year, 0-yy; 1-yyyy	
    BYTE					byDateForm; 			//0-5,  permutations and combinations of year, month, day
    BYTE					byRes[20];              // Reserved
    char					chSeprator[4]; 		    //separator
    char	    			chDisplaySeprator[4]; 	//display separator
    BYTE	    			byDisplayForm; 			//0-5, permutations and combinations of 3 items
    BYTE					res[27];                // Reserved
}NET_DVR_DATE_FORMAT,  *LPNET_DVR_DATE_FORMAT; 
typedef struct	tagNET_DVRT_TIME_FORMAT//time display format
{	
    BYTE					byTimeForm; 			//1. HH MM SS; 0. HH MM
    BYTE 					byRes1[23];             // Reserved
    BYTE                    byHourMode;             //0, 12; 1, 24 
    BYTE                    byRes2[3];              // Reserved
    char					chSeprator[4];  	    //package separator,  reserved
    char					chDisplaySeprator[4]; 	//display separator
    BYTE	    			byDisplayForm; 			//0~5,  permutations and combinations  of 3 items
    BYTE                    byRes3[3];              // Reserved
    BYTE					byDisplayHourMode; 		//0-12;  1- 24 
    BYTE					byRes4[19];             // Reserved
}NET_DVR_TIME_FORMAT,  *LPNET_DVR_TIME_FORMAT; 

typedef struct tagNET_DVR_OVERLAY_CHANNEL
{	
    BYTE                    byChannel[64]; //overlay channel,  Set 1 to display,  set 0 to hide
    DWORD					dwDelayTime; 			//overlay delay time
    BYTE					byEnableDelayTime; 		//enable or disable. Overlay delay is enabled,  in the absence of withdrawal card command 
    BYTE					byRes[11];           // Reserved
}NET_DVR_OVERLAY_CHANNEL,  *LPNET_DVR_OVERLAY_CHANNEL; 

// Structure of Trading action
typedef struct tagNET_DVR_ATM_PACKAGE_ACTION
{	
    NET_DVR_PACKAGE_LOCATION	struPackageLocation; // location of package
    NET_DVR_OSD_POSITION		struOsdPosition;     // OSD overlay position
    NET_DVR_FRAMETYPECODE		struActionCode; 		//codes of trading type
    NET_DVR_FRAMETYPECODE		struPreCode; 		//character before overlaying
    BYTE					byActionCodeMode; 		//codes of trading type. 0, ASCII; 1, HEX
    BYTE					byRes[7];                // Reserved
}NET_DVR_ATM_PACKAGE_ACTION,  *LPNET_DVR_ATM_PACKAGE_ACTION; 

//  Date info of ATM package
typedef struct tagNET_DVR_ATM_PACKAGE_DATE
{	
    NET_DVR_PACKAGE_LOCATION	struPackageLocation; // Position of date
    NET_DVR_DATE_FORMAT		    struDateForm; 		//date display mode
    NET_DVR_OSD_POSITION		struOsdPosition; 	// OSD overly position
    BYTE				    	res[8];  			// Reserved
}NET_DVR_ATM_PACKAGE_DATE,  *LPNET_DVR_ATM_PACKAGE_DATE; 


//Time info of ATM package
typedef struct tagNET_DVR_ATM_PACKAGE_TIME
{	
    NET_DVR_PACKAGE_LOCATION	location; 		// Position of time
    NET_DVR_TIME_FORMAT		    struTimeForm; 	//display mode
    NET_DVR_OSD_POSITION		struOsdPosition; // OSD overly position
    BYTE					    byRes[8]; 		// Reserved
}NET_DVR_ATM_PACKAGE_TIME,  *LPNET_DVR_ATM_PACKAGE_TIME; 


//other info of  ATM package (Card SN.,  Transaction amount,  Transaction SN.) 
typedef struct tagNET_DVR_ATM_PACKAGE_OTHERS
{	
    NET_DVR_PACKAGE_LOCATION	struPackageLocation;  //Position info
    NET_DVR_PACKAGE_LENGTH	struPackageLength; 		//length Info
    NET_DVR_OSD_POSITION		struOsdPosition; 	//overlay position
    NET_DVR_FRAMETYPECODE		struPreCode; 		//character before overlaying
    BYTE					res[8]; 					//Reserved
}NET_DVR_ATM_PACKAGE_OTHERS,  *LPNET_DVR_ATM_PACKAGE_OTHERS; 


//User- defined Protocol
typedef struct tagNET_DVR_ATM_USER_DEFINE_PROTOCOL
{
    NET_DVR_IDENTIFICAT        struIdentification;   //Package Flag
    NET_DVR_FILTER             struFilter;  //Filter settings
    NET_DVR_ATM_PACKAGE_OTHERS struCardNoPara;  // Settings of overlay card number 
    NET_DVR_ATM_PACKAGE_ACTION struTradeActionPara[MAX_ACTION_TYPE];  //Settings of overlay trade action, 0- 9: InCard,  OutCard,  OverLay,  SetTime,  GetStatus,  Query,  WithDraw,  Deposit,  ChanPass,  Transfer
    NET_DVR_ATM_PACKAGE_OTHERS struAmountPara;  //Settings of overlay Transaction amount
    NET_DVR_ATM_PACKAGE_OTHERS struSerialNoPara;  //Settings of overlay trade SN
    NET_DVR_OVERLAY_CHANNEL    struOverlayChan;  //Settings of overlay channel
    NET_DVR_ATM_PACKAGE_DATE   struRes1;  //Settings of overlay data,  reserved
    NET_DVR_ATM_PACKAGE_TIME   struRes2;  //Settings of overlay time,  reserved
    BYTE                       byRes3[124];         //Reserved
}NET_DVR_ATM_USER_DEFINE_PROTOCOL,  *LPNET_DVR_ATM_USER_DEFINE_PROTOCOL; 

typedef struct tagNET_DVR_ATM_FRAMEFORMAT_V30
{		
    DWORD                        dwSize;                 //structure size
    BYTE					    byEnable; 				/*0:  Enable,  1:  Disable*/
    BYTE					    byInputMode; 			/*Input mode:  0- Network Listen,  1- Network Protocol,  2- Serial Listen,  3- Serial Protocol*/
    BYTE					    byRes1[34];              //Reserved 
    NET_DVR_IPADDR		    	struAtmIp; 				/*ATM IP,  used in network listen mode */
    WORD					    wAtmPort; 				/* Get port by card number,  Network Protocol mode or Serial server port mode*/
    BYTE					    byRes2[2];               // Reserved
    DWORD					    dwAtmType; 				/*ATM protocol type,  get from NET_DVR_ATM_PROTOCOL,  using user- defined protocol when the type is user_defined*/
    NET_DVR_ATM_USER_DEFINE_PROTOCOL   struAtmUserDefineProtocol;  //User- defined protocol,  using this definition when the ATM protocol is user- defined.
    BYTE					    byRes3[8]; 
}NET_DVR_ATM_FRAMEFORMAT_V30,  *LPNET_DVR_ATM_FRAMEFORMAT_V30; 


typedef struct  tagNET_DVR_ATM_PROTO_TYPE
{
    DWORD dwAtmType;  //ATM protocol type,  index SN,  and 1025 is for user- defined.
    char chDesc[ATM_DESC_LEN];  //Simple description of ATM protocol
}NET_DVR_ATM_PROTO_TYPE,  *LPNET_DVR_ATM_PROTO_TYPE;  //Data structure of protocol information

typedef struct tagNET_DVR_ATM_PROTO_LIST    //ATM Protocol List
{
    DWORD                  dwAtmProtoNum;    // Number of protocol 
    NET_DVR_ATM_PROTO_TYPE struAtmProtoType[MAX_ATM_PROTOCOL_NUM];  //protocol list info
}NET_DVR_ATM_PROTO_LIST,  *LPNET_DVR_ATM_PROTO_LIST; 

typedef struct tagNET_DVR_ATM_PROTOCOL
{
    DWORD dwSize; 
    NET_DVR_ATM_PROTO_LIST struNetListenList;  // Description of Network Listen protocol
    NET_DVR_ATM_PROTO_LIST struSerialListenList;  //Description of Serial Listen protocol
    NET_DVR_ATM_PROTO_LIST struNetProtoList;      //Description of Network protocol
    NET_DVR_ATM_PROTO_LIST struSerialProtoList;    //Description of Serial Protocol
    NET_DVR_ATM_PROTO_TYPE struCustomProto;         //User- defined protocol
}NET_DVR_ATM_PROTOCOL,  *LPNET_DVR_ATM_PROTOCOL; 
//SDK_V31

/*****************************DS- 6001D/F (begin) ***************************/
//DS- 6001D Decoder
typedef struct 
{
    BYTE byEncoderIP[16]; 		//Server IP that decoder connected
    BYTE byEncoderUser[16]; 		//Server Username that decoder connected
    BYTE byEncoderPasswd[16]; 	//Server Password that decoder connected
    BYTE bySendMode; 			//Server Connection Mode that decoder connected
    BYTE byEncoderChannel; 		//Server Channel No. that decoder connected
    WORD wEncoderPort; 			//Server Port that decoder connected
    BYTE reservedData[4]; 		//Reserved
}NET_DVR_DECODERINFO,  *LPNET_DVR_DECODERINFO; 

typedef struct 
{
    BYTE byEncoderIP[16]; 		//Server IP that decoder connected
    BYTE byEncoderUser[16]; 		//Server Username that decoder connected
    BYTE byEncoderPasswd[16]; 	//Server Password that decoder connected
    BYTE byEncoderChannel; 		//Server Channel No. that decoder connected
    BYTE bySendMode; 			//Server Connection Mode that decoder connected
    WORD wEncoderPort; 			//Server Port that decoder connected
    DWORD dwConnectState; 		//Server State that decoder connected
    BYTE reservedData[4]; 		//Reserved
}NET_DVR_DECODERSTATE,  *LPNET_DVR_DECODERSTATE; 

/*Definition of Decoder Control Code */
#define NET_DEC_STARTDEC		1
#define NET_DEC_STOPDEC			2
#define NET_DEC_STOPCYCLE		3
#define NET_DEC_CONTINUECYCLE	4

/*Channel Connected Configuration*/
typedef struct 
{
    char sDVRIP[16]; 				/* DVR IP Address */
    WORD wDVRPort; 			 		/* Ports */
    BYTE sUserName[NAME_LEN]; 		/* Username */
    BYTE sPassword[PASSWD_LEN]; 		/* Password */
    BYTE byChannel; 					/* Channel No. */
    BYTE byLinkMode; 				/* Connection Mode */
    BYTE byLinkType; 				/* Stream for Connection  0- Main Stream 1- Sub Stream */
}NET_DVR_DECCHANINFO,  *LPNET_DVR_DECCHANINFO; 

/*Configuration of Each Decoding Channel*/
typedef struct 
{
    BYTE	byPoolChans; 			/*Switch channel number on each decoder channel,  range from 0- 4*/
    NET_DVR_DECCHANINFO struchanConInfo[MAX_DECPOOLNUM]; 
    BYTE	byEnablePoll; 			/*enable switching or not:  0-  disable 1-  enable*/
    BYTE	byPoolTime; 				/*switching interval:  1- 10 sec;  2-  15 sec;  3-  20 sec;  4-  30 sec;   5-  45 sec;  6-  1min;  7-  2min;  8-  5min */
}NET_DVR_DECINFO,  *LPNET_DVR_DECINFO; 

/*Decoder Configuration*/
typedef struct 
{
    DWORD	dwSize; 
    DWORD	dwDecChanNum;  		/*Number of decoding channels*/
    NET_DVR_DECINFO struDecInfo[MAX_DECNUM]; 
}NET_DVR_DECCFG,  *LPNET_DVR_DECCFG; 

//2005- 08- 01
/* Transparent Channel of Decoder */
typedef struct 
{
    DWORD dwEnableTransPort; 	/* Enable transparent channel or not:  0-  disable;  1-  enable*/
    char sDecoderIP[16]; 		/* DVR IP */
    WORD wDecoderPort; 			/* Port number */
    WORD wDVRTransPort; 			/* Configuration DVR output serial port:  1-  232;  2-  485 */
    char cReserve[4]; 
}NET_DVR_PORTINFO,  *LPNET_DVR_PORTINFO; 

typedef struct 
{
    DWORD dwSize; 
    NET_DVR_PORTINFO struTransPortInfo[MAX_TRANSPARENTNUM];  /* Array 0- - 232;  Array 1- - 485 */
}NET_DVR_PORTCFG,  *LPNET_DVR_PORTCFG; 

/* Remote Playback */
typedef struct 
{
    DWORD dwSize; 
    char sDecoderIP[16]; 		/* DVR IP*/
    WORD wDecoderPort; 			/* Port */
    WORD wLoadMode; 				/* Playback Mode 1- by name 2- by time */
    union
    {
        BYTE byFile[100]; 		/* File Name */
        struct
        {
            DWORD dwChannel; 
            BYTE sUserName[NAME_LEN]; 	/* Username for playback*/
            BYTE sPassword[PASSWD_LEN]; 	/* Password */
            NET_DVR_TIME struStartTime; 	/* Start time of playback by time mode*/
            NET_DVR_TIME struStopTime; 	/* End time */
        }bytime; 
    }mode_size; 
}NET_DVR_PLAYREMOTEFILE,  *LPNET_DVR_PLAYREMOTEFILE; 

/*Decoder Channel Status Structure */
typedef struct 
{
    DWORD dwWorkType; 		/*Work mode:  1-  switching;  2-  dynamic connect to decoder;  3-  playback by file;  4-  playback by time*/
    char sDVRIP[16]; 		/*Connected device IP*/
    WORD wDVRPort; 			/*Connected port number*/
    BYTE byChannel; 			/*Channel number */
    BYTE byLinkMode; 		/*Connection mode */
    DWORD	dwLinkType; 		/*Connection stream type:  0-  main stream;  1-  sub stream*/
    union
    {
        struct
        {
            BYTE sUserName[NAME_LEN]; 	/*Username*/
            BYTE sPassword[PASSWD_LEN]; 	/* Password */
            char cReserve[52]; 
        }userInfo; 
        struct
        {
            BYTE   fileName[100]; 
        }fileInfo; 
        struct
        {
            DWORD	dwChannel; 
            BYTE	sUserName[NAME_LEN]; 	/*Username*/
            BYTE	sPassword[PASSWD_LEN]; 	/* Password */
            NET_DVR_TIME struStartTime; 		/* Start position for playback by time */
            NET_DVR_TIME struStopTime; 		/* End position for playback by time */
        }timeInfo; 
    }objectInfo; 
}NET_DVR_DECCHANSTATUS,  *LPNET_DVR_DECCHANSTATUS; 

typedef struct 
{
    DWORD   dwSize; 
    NET_DVR_DECCHANSTATUS struDecState[MAX_DECNUM]; 
}NET_DVR_DECSTATUS,  *LPNET_DVR_DECSTATUS; 
/*****************************DS- 6001D/F (end) ***************************/

//Single Character Struct  (Sub Struct) 
typedef struct 
{
    WORD wShowString; 				//enable text overlay on preview image:  0- disable;  1- enable. The display area ranges totally 704*576 ,  with single character size as 32*32
    WORD wStringSize; 				/* text length,  no more than 44 text character */
    WORD wShowStringTopLeftX; 		/* top left X axis position for text overlay*/
    WORD wShowStringTopLeftY; 		/* top left Y axis position for text overlay */
    char sString[44]; 				/* overlay text content*/
}NET_DVR_SHOWSTRINGINFO,  *LPNET_DVR_SHOWSTRINGINFO; 

//Text Overlay  (9000extended) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_V30]; 				/* Content for display */
}NET_DVR_SHOWSTRING_V30,  *LPNET_DVR_SHOWSTRING_V30; 

//Text Overlay extended (8 lines) 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_EX]; 				/* Content for display  */
}NET_DVR_SHOWSTRING_EX,  *LPNET_DVR_SHOWSTRING_EX; 

//Text Overlay 
typedef struct 
{
    DWORD dwSize; 
    NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM]; 				/* Content for display  */
}NET_DVR_SHOWSTRING,  *LPNET_DVR_SHOWSTRING; 

/****************************DS9000 added Structure (begin) ******************************/

/*
EMAIL Parameters Struct
*/
typedef struct
{		
    DWORD		dwSize; 
    BYTE		sAccount[NAME_LEN]; 				/* Email Account*/ 
    BYTE		sPassword[MAX_EMAIL_PWD_LEN]; 			/*Password */
    struct
    {
        BYTE	sName[NAME_LEN]; 				/* sender name */
        BYTE	sAddress[MAX_EMAIL_ADDR_LEN]; 		/* sender address */
    }struSender; 
    BYTE		sSmtpServer[MAX_EMAIL_ADDR_LEN]; 	/* SMTP server */
    BYTE		sPop3Server[MAX_EMAIL_ADDR_LEN]; 	/* POP3 server */
    struct
    {
        BYTE	sName[NAME_LEN]; 				/* receiver Name */
        BYTE	sAddress[MAX_EMAIL_ADDR_LEN]; 		/* receiver address */
    }struReceiver[3]; 							/* support up to 3 receivers */
    BYTE		byAttachment; 					/* with attached snapshot or not */
    BYTE		bySmtpServerVerify; 				/* Enable Email server authentication:  1- enable;  0- disable */
    BYTE        byMailInterval;                  /* mail interval 0- 2s,  1- 3s,  2- 4s. 3- 5s*/
    BYTE        byEnableSSL; 					//enable ssl
    WORD        wSmtpPort; 						//gmail default 465,  else default 25     
    BYTE        byRes[74]; 						//reserve
} NET_DVR_EMAILCFG_V30,  *LPNET_DVR_EMAILCFG_V30; 

/*
DVR Cruise Structure
*/
typedef struct
{	
    DWORD 	dwSize; 
    BYTE	byPresetNo[CRUISE_MAX_PRESET_NUMS]; 		/* Preset No. */
    BYTE 	byCruiseSpeed[CRUISE_MAX_PRESET_NUMS]; 	/* Cruise Speed */
    WORD	wDwellTime[CRUISE_MAX_PRESET_NUMS]; 		/* Dwell time */
    BYTE	byEnableThisCruise; 						/* Enable this cruise */
    BYTE	res[15]; 
}NET_DVR_CRUISE_PARA,  *LPNET_DVR_CRUISE_PARA;  
/****************************DS9000 Added (end) ******************************/


//Time
typedef struct 
{
    DWORD dwMonth; 		//Month 0- 11 for 1- 12 month
    DWORD dwWeekNo; 		//Week 0-  First Week 1- Second Week 2- Third Week 3- Fourth Week 4- last Week
    DWORD dwWeekDate; 	//Day 0- Sun 1- Mon 2- Tue 3- Wed 4- Thu 5- Fri 6- Sat
    DWORD dwHour; 		//begin/end hour,  begin hour ranges from 0- 23,  and end hour ranges from 1- 23
    DWORD dwMin; 		//begin/stop minutes ranges from 0- 59
}NET_DVR_TIMEPOINT; 

//Time Zone & DST 
typedef struct 
{
    DWORD dwSize; 
    BYTE byRes1[16]; 			//Reserved
    DWORD dwEnableDST; 		//enable DST,  0- disable;  1- enable
    BYTE byDSTBias; 			//DST bias;  30min,  60min,  90min,  120min,  count with minute
    BYTE byRes2[3]; 
    NET_DVR_TIMEPOINT struBeginPoint; 	//DST start time
    NET_DVR_TIMEPOINT struEndPoint; 		//DST stop time
}NET_DVR_ZONEANDDST,  *LPNET_DVR_ZONEANDDST; 



//Image Quality
typedef struct NET_DVR_JPEGPARA
{
/*Note:  If encoding resolution is VGA, it supports grabbing 0=CIF,  1=QCIF,  2=D1 image.
    But if encoding resolution is 3=UXGA (1600x1200) ,  4=SVGA (800x600) ,  5=HD720p (1280x720) ,  6=VGA,  7=XVGA,  and 8=HD900p it only support grabbing image with current resolution*/
    WORD	wPicSize; 				/* 0- CIF,  1- QCIF, 2- D1, 3- UXGA, 4- SVGA, 5- HD720p, 6- VGA, 7- XVGA, 8- HD900p, 9- HD1080, 
									10- 2560*1920, 11- 1600*304, 12- 2048*1536, 13- 2448*2048, 14-2448*1200, 15-2448*800,
                                16-XGA(1024*768), 17-SXGA(1280*1024),18-WD1(960*576/960*480),19-1080i*/
    WORD	wPicQuality; 			/* 0 -  the best,  1 -  better,  2 -  average;  */
}NET_DVR_JPEGPARA,  *LPNET_DVR_JPEGPARA; 

/* aux video out parameter */
//AUX Output Parameter
typedef struct 
{
    DWORD dwSize; 
    DWORD dwAlarmOutChan;                        /* 0–main video output;  1–aux1 video output;  2–aux2 video output;  3–aux3 video output;  4–aux4 video output*/
    DWORD dwAlarmChanSwitchTime;                 /* : 1Sec -  10: 10Sec */
    DWORD dwAuxSwitchTime[MAX_AUXOUT]; 			/* aux output switch time:  0-  no switch;  1- 5sec; 2- 10sec; 3- 20sec; 4- 30sec; 5- 60sec; 6- 120sec; 7- 300sec*/
    BYTE  byAuxOrder[MAX_AUXOUT][MAX_WINDOW]; 	/* aux output preview sequence,  0xff means not preview the camera */
}NET_DVR_AUXOUTCFG,  *LPNET_DVR_AUXOUTCFG; 


//ntp
typedef struct 
{
    BYTE sNTPServer[64];    /* Domain Name or IP address of NTP server */
    WORD wInterval; 		 /* adjust time interval (hours)  */
    BYTE byEnableNTP;     /* enable NPT client 0- no, 1- yes*/
    signed char cTimeDifferenceH;  /* Difference with Standard Time  (Hour) :  ranges from - 12... +13 */
    signed char cTimeDifferenceM; /* Difference with Standard Time  (Minute) */
    BYTE res1; 
    WORD wNtpPort;          /* ntp server port (9000 added) ,  123 is default*/
    BYTE res2[8]; 
}NET_DVR_NTPPARA,  *LPNET_DVR_NTPPARA; 

//DDNS
typedef struct 
{
    BYTE sUsername[NAME_LEN];   /* DDNS Username*/								
    BYTE sPassword[PASSWD_LEN]; /*Password */
    BYTE sDomainName[64];        /* Domain name */
    BYTE byEnableDDNS; 			/*Enable DDNS 0- disable, 1- enable*/
    BYTE res[15]; 
}NET_DVR_DDNSPARA,  *LPNET_DVR_DDNSPARA; 


typedef struct
{
    BYTE byHostIndex; 					/* 0- private DNS (Reserved)  1- Dyndns 2- PeanutHull 3- xw3322  */
    BYTE byEnableDDNS; 					/*enable DDNS:  0- disable;  1- enable*/
    WORD wDDNSPort; 						/* DDNS port */
    BYTE sUsername[NAME_LEN]; 			/* DDNS Username*/
    BYTE sPassword[PASSWD_LEN]; 			/* DDNS Password */
    BYTE sDomainName[MAX_DOMAIN_NAME]; 	/* DVR domain name*/
    BYTE sServerName[MAX_DOMAIN_NAME]; 	/* DDNS server domain name or IP */
    BYTE byRes[16]; 
}NET_DVR_DDNSPARA_EX,  *LPNET_DVR_DDNSPARA_EX; 

//9000extended
typedef struct
{
    BYTE byEnableDDNS; 
    BYTE byHostIndex; /*0-IPServer 1－Dyndns 2－PeanutHull，3- NO-IP, 4- HiDDNS*/
    BYTE byRes1[2]; 
    struct
    {    
        BYTE sUsername[NAME_LEN]; 			/* DDNS Username*/
        BYTE sPassword[PASSWD_LEN]; 			/* Password */
        BYTE sDomainName[MAX_DOMAIN_NAME]; 	/* DVR domain name */
        BYTE sServerName[MAX_DOMAIN_NAME]; 	/* DDNS server domain name or IP*/
        WORD wDDNSPort; 						/* Port */
        BYTE byRes[10]; 
    } struDDNS[MAX_DDNS_NUMS]; 
    BYTE byRes2[16]; 
}NET_DVR_DDNSPARA_V30,  *LPNET_DVR_DDNSPARA_V30; 

//email
typedef struct 
{
    BYTE sUsername[64];   /* Email Account */
    BYTE sPassword[64]; 
    BYTE sSmtpServer[64]; 
    BYTE sPop3Server[64]; 
    BYTE sMailAddr[64];    /* email */
    BYTE sEventMailAddr1[64];   /* email for upload Alarm/Exception */
    BYTE sEventMailAddr2[64]; 
    BYTE res[16]; 
}NET_DVR_EMAILPARA,  *LPNET_DVR_EMAILPARA; 

//Network Parameter
typedef struct 
{
    DWORD  dwSize; 
    char  sDNSIp[16];                 /* DNS Server IP */
    NET_DVR_NTPPARA  struNtpClientParam;       /* NTP Parameters */
    NET_DVR_DDNSPARA struDDNSClientParam;      /* DDNS Parameters */
    BYTE res[464]; 			/* Reserved */
}NET_DVR_NETAPPCFG,  *LPNET_DVR_NETAPPCFG; 

//nfs Structure Configuration
typedef struct
{
    char sNfsHostIPAddr[16]; 
    BYTE sNfsDirectory[PATHNAME_LEN];         // PATHNAME_LEN = 128
}NET_DVR_SINGLE_NFS,  *LPNET_DVR_SINGLE_NFS; 

typedef struct 
{
    DWORD  dwSize; 
    NET_DVR_SINGLE_NFS struNfsDiskParam[MAX_NFS_DISK]; 
}NET_DVR_NFSCFG,  *LPNET_DVR_NFSCFG; 

typedef struct tagNET_DVR_ISCSI_CFG
{   
    DWORD dwSize;                   // Structure size
    WORD wVrmPort;                  // VRM listening port
    BYTE byEnable;                  // Enable ISCSI storage or not
    BYTE byRes[69];                 // Reserved
    NET_DVR_IPADDR struVrmAddr;     // VRM IP address, 16-bit
    char chNvtIndexCode[64];        //nvt index Code 
}NET_DVR_ISCSI_CFG, *LPNET_DVR_ISCSI_CFG;  

//Cruise Point Configuration (for private IP Speed Dome) 
typedef struct
{
    BYTE	PresetNum; 	//Preset
    BYTE	Dwell; 		//Dwell time
    BYTE	Speed; 		//Speed
    BYTE	Reserve; 	//Reserved
}NET_DVR_CRUISE_POINT,  *LPNET_DVR_CRUISE_POINT; 

typedef struct 
{
    NET_DVR_CRUISE_POINT struCruisePoint[32]; 			//32 points in total
}NET_DVR_CRUISE_RET,  *LPNET_DVR_CRUISE_RET; 

/************************************Multi- Channel Decoder (begin) ***************************************/
typedef struct 
{
    DWORD	dwSize; 
    char	sFirstDNSIP[16]; 
    char	sSecondDNSIP[16]; 
    char	sRes[32]; 
}NET_DVR_NETCFG_OTHER,  *LPNET_DVR_NETCFG_OTHER; 

typedef struct 
{
    char 	sDVRIP[16]; 				/* DVR IP */
    WORD 	wDVRPort; 			 	/* Port */
    BYTE 	byChannel; 				/* Channel No. */
    BYTE	byTransProtocol; 			/* Network Protocol 0- TCP,  1- UDP */
    BYTE	byTransMode; 				/* Stream Type 0 -  Main Stream 1 -  Sub Stream*/
    BYTE	byRes[3]; 
    BYTE	sUserName[NAME_LEN]; 			/* DVR login user name */
    BYTE	sPassword[PASSWD_LEN]; 			/* DVR login Password */
}NET_DVR_MATRIX_DECINFO,  *LPNET_DVR_MATRIX_DECINFO; 

//Dynamic Decoding
typedef struct 
{
    DWORD	dwSize; 				
    NET_DVR_MATRIX_DECINFO struDecChanInfo; 		/*Info of Dynamic Decoding Channel*/
}NET_DVR_MATRIX_DYNAMIC_DEC,  *LPNET_DVR_MATRIX_DYNAMIC_DEC; 

typedef struct  
{
    DWORD 	dwSize; 
    DWORD   dwIsLinked;          /* Network link status tag,  0:  Sleep,  1:  linking,  2:  linked,  3:  decoding */
    DWORD   dwStreamCpRate;      /* Stream copy rate,  X kbits/second */
    char    cRes[64]; 		/* Reserved */
}NET_DVR_MATRIX_DEC_CHAN_STATUS,  *LPNET_DVR_MATRIX_DEC_CHAN_STATUS; 

typedef struct 
{
    DWORD	dwSize; 
    NET_DVR_MATRIX_DECINFO struDecChanInfo; 		/* Decode channel information  */
    DWORD	dwDecState; 	/* 0- dynamic decode 1-  switch decode 2- playback by time 3- playback by file */
    NET_DVR_TIME StartTime; 		/* start time for playback by time mode,  */
    NET_DVR_TIME StopTime; 		/* stop time for playback by time mode */
    char    sFileName[128]; 		/* file name for playback by file mode */
}NET_DVR_MATRIX_DEC_CHAN_INFO,  *LPNET_DVR_MATRIX_DEC_CHAN_INFO; 

//Channel Connected Configuration 2007- 11- 05
typedef struct 
{
    DWORD dwEnable; 					/*0- Disable 1- Enable*/
    NET_DVR_MATRIX_DECINFO struDecChanInfo; 		/* Info of switching decoding channel */
}NET_DVR_MATRIX_DECCHANINFO,  *LPNET_DVR_MATRIX_DECCHANINFO; 

//2007- 11- 05 Configuration for each channel
typedef struct 
{
    DWORD	dwSize; 
    DWORD	dwPoolTime; 			/*Switch interval */
    NET_DVR_MATRIX_DECCHANINFO struchanConInfo[MAX_CYCLE_CHAN]; 
}NET_DVR_MATRIX_LOOP_DECINFO,  *LPNET_DVR_MATRIX_LOOP_DECINFO; 

//2007- 12- 22
typedef struct 
{
    BYTE	baudrate;  		/* baud rate */
    BYTE	databits; 		/* Data bit */
    BYTE	stopbits; 		/* Stop bit*/
    BYTE	parity; 			/* Parity digit */
    BYTE	flowcontrol; 	/* Flow control */
    BYTE	res[3]; 
}TTY_CONFIG,  *LPTTY_CONFIG; 

typedef struct  
{					
    BYTE byTranChanEnable; 	/* Open current transparent channel or not 0:  close 1:  open */	
                            /*
                            There is a 232 interface and a 485 interface on the decoder,  which can all be set as transparent channel,  device number can be distributed as below: 
                            0 -  RS485; 1 -  RS232 Console
    */
    BYTE	byLocalSerialDevice; 			/* Local serial device */
                                            /*
                                            *	Remote output serial device
                                            *	1- RS232
                                            *	2- RS485
    */
    BYTE	byRemoteSerialDevice; 			/* Remote output serial device */
    BYTE	res1; 							/* Reserved */
    char	sRemoteDevIP[16]; 				/* Remote Device IP */
    WORD	wRemoteDevPort; 					/* Remote Net Communication Port */
    BYTE	res2[2]; 						/* Reserved */
    TTY_CONFIG RemoteSerialDevCfg; 
}NET_DVR_MATRIX_TRAN_CHAN_INFO,  *LPNET_DVR_MATRIX_TRAN_CHAN_INFO; 

typedef struct  
{
    DWORD dwSize; 
    BYTE 	by232IsDualChan;  /* Set full- duplex 232 transparent channel,  set value ranges from 1 to MAX_SERIAL_NUM */
    BYTE	by485IsDualChan;  /* Set full- duplex 485 transparent channel,  set value ranges from 1 to MAX_SERIAL_NUM */
    BYTE	res[2]; 	/* Reserved */
    NET_DVR_MATRIX_TRAN_CHAN_INFO struTranInfo[MAX_SERIAL_NUM]; /*Support to create transparent channel number up to MAX_SERIAL_NUM*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG,  *LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG; 

//2007- 12- 24 Merry Christmas Eve...
typedef struct 
{
    DWORD	dwSize; 
    char	sDVRIP[16]; 			/* DVR IP */	
    WORD	wDVRPort; 			/* Port */	
    BYTE	byChannel; 			/* Channel Port */
    BYTE 	byReserve; 
    BYTE	sUserName[NAME_LEN]; 		/* Username */
    BYTE	sPassword[PASSWD_LEN]; 		/* Password */
    DWORD	dwPlayMode;    	/* 0- by file 1-  by time*/        	
    NET_DVR_TIME StartTime; 
    NET_DVR_TIME StopTime; 
    char    sFileName[128]; 
}NET_DVR_MATRIX_DEC_REMOTE_PLAY,  *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY; 

/* Commands for playing file*/
#define NET_DVR_PLAYSTART		1//Start play
#define NET_DVR_PLAYSTOP		2//Stop play
#define NET_DVR_PLAYPAUSE		3//Pause
#define NET_DVR_PLAYRESTART		4//Restore
#define NET_DVR_PLAYFAST		5//Play Faster
#define NET_DVR_PLAYSLOW		6//Play Slower
#define NET_DVR_PLAYNORMAL		7//Normal Speed
#define NET_DVR_PLAYSTARTAUDIO	9//Open Audio
#define NET_DVR_PLAYSTOPAUDIO	10//Close Audio
#define NET_DVR_PLAYSETPOS		12//Change playing progress

typedef struct 
{
    DWORD	dwSize; 
    DWORD	dwPlayCmd; 		/* Command of Play*/
    DWORD	dwCmdParam; 		/* Parameter of Command*/
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL,  *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL; 

typedef struct  
{
    DWORD dwSize; 
    DWORD dwCurMediaFileLen; 		/* Current file length  */       
    DWORD dwCurMediaFilePosition; 	/* Current file position */        
    DWORD dwCurMediaFileDuration; 	/* Current file duration */        
    DWORD dwCurPlayTime; 			/* Current playback time  */        
    DWORD dwCurMediaFIleFrames; 		/* Current playback frame number  */        
    DWORD dwCurDataType; 			/* Current stream type,  19- file header,  20-  stream data,  21- end */        
    BYTE res[72]; 	
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS,  *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS; 


//Multi- channels Decoder new
typedef struct tagNET_MATRIX_PASSIVEMODE
{
    WORD	wTransProtol; 		//Transfer Protocol, 0- TCP,  1- UDP,  2- MCAST
    WORD	wPassivePort; 		//UDP port. When TCP,  use default value
    NET_DVR_IPADDR  struMcastIP; //Multicast address,  invalid when using TCP or UDP, 
    BYTE	byStreamType; /* play mode: REAL_TIME_STREAM (1) real-time, RECORD_STREAM (2) record */
    BYTE	byRes[7]; 
}NET_DVR_MATRIX_PASSIVEMODE,  *LPNET_DVR_MATRIX_PASSIVEMODE; 

typedef struct tagMATRIX_TRAN_CHAN_INFO 
{					
    BYTE byTranChanEnable; 	/*Transparent Channel State:  0- Close,  1- Open */	
                            /*
                            *	Multi- channel Decoder has 1 RS485 port and 1 RS232 Port,  both of them can be transparent channel. Device Number is : 
                            *	0 -  RS485
                            *	1 -  RS232 Console
    */
    BYTE	byLocalSerialDevice; 			/* Local serial device */
                                            /*
                                            *	Remote Serial Output Port:  one RS232 and one RS485
                                            *	1 -  RS232
                                            *	2 -  RS485
    */
    BYTE	byRemoteSerialDevice; 			/* Remote output serial device */
    BYTE	res1; 							/* Reserved */
    // char	sRemoteDevIP[16]; 				/* Remote Device IP */
    NET_DVR_IPADDR  struRemoteDevIP; 
    WORD    wRemoteDevPort; 				/* Remote Net Communication Port */
    BYTE  byIsEstablished; 	/* Establish Transparent channel: 0- Failure,  1- Success*/
    BYTE	res2[1]; 					/* Reserved */
    TTY_CONFIG RemoteSerialDevCfg; 
    BYTE  	byUsername[NAME_LEN];  		/* 32BYTES */
    BYTE   	byPassword[PASSWD_LEN];  	/* 16BYTES */
    BYTE 	res3[16]; 					/* Reserved */
}NET_DVR_MATRIX_TRAN_CHAN_INFO_V30, *LPNET_DVR_MATRIX_TRAN_CHAN_INFO_V30; 

typedef struct tagMATRIX_TRAN_CHAN_CONFIG 
{
    DWORD   dwSize; 
    BYTE 	by232IsDualChan;  /* Set this RS232 transparent channel as Duplex: 1 ~ MAX_SERIAL_NUM*/
    BYTE	by485IsDualChan;  /* Set this RS485 transparent channel as Duplex: 1 ~ MAX_SERIAL_NUM */
    BYTE	vyRes[2]; 	/* Reserved */
    NET_DVR_MATRIX_TRAN_CHAN_INFO_V30 struTranInfo[MAX_SERIAL_NUM]; /*Support MAX_SERIAL_NUM Transparent channels simultaneously*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30, *LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30; 


typedef struct  
{
    DWORD								dwEnable; 	/*0- Disable,  1- Enable*/
    NET_DVR_STREAM_MEDIA_SERVER_CFG	streamMediaServerCfg; 	
    NET_DVR_DEV_CHAN_INFO 		struDevChanInfo; 		/* Loop Decoding channel info */
}NET_DVR_MATRIX_CHAN_INFO_V30, *LPNET_DVR_CYC_SUR_CHAN_ELE_V30; 

typedef struct  tagMATRIX_LOOP_DECINFO_V30
{
    DWORD							dwSize; 
    DWORD							dwPoolTime; 		/*Loop Interval*/
    NET_DVR_MATRIX_CHAN_INFO_V30	struchanConInfo[MAX_CYCLE_CHAN_V30]; 
    BYTE               				byRes[16]; 
} NET_DVR_MATRIX_LOOP_DECINFO_V30, *LPNET_DVR_MATRIX_LOOP_DECINFO_V30; 


typedef struct tagDEC_MATRIX_CHAN_INFO
{
    DWORD	dwSize; 
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg; 	/*Streaming Media Server Config*/
    NET_DVR_DEV_CHAN_INFO 			  struDevChanInfo; 		/*Decoding Channel Info  */
    DWORD	dwDecState; 		/*  0- Dynamic Decoding,  1- Loop Decoding 2- Playback by time,  3- Playback by file */
    NET_DVR_TIME StartTime; 		/* Start time of playback by time */
    NET_DVR_TIME StopTime; 			/* End time of playback by time */
    char    sFileName[128]; 		/* File name for playback by file */
    DWORD   dwGetStreamMode; 	/*Fetch Stream Mode: 1- Positive, 2- Passive*/
    NET_DVR_MATRIX_PASSIVEMODE      struPassiveMode; 
    BYTE	byRes[32]; 
}NET_DVR_MATRIX_DEC_CHAN_INFO_V30, *LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30; 

#define MAX_RESOLUTIONNUM    64 //Max resolution number
typedef struct tagNET_DVR_MATRIX_ABILITY
{
    DWORD dwSize; 
    BYTE  byDecNums; 
    BYTE  byStartChan; 
    BYTE  byVGANums; 
    BYTE  byBNCNums; 
    BYTE  byVGAWindowMode[8][12];      /*Window Mode of VGA*/
    BYTE  byBNCWindowMode[4];        	/*Window Mode of BNC*/
    BYTE  byDspNums;    
    BYTE  byHDMINums; //HDMI display channel number  ( start from 25) 
    BYTE  byDVINums; //DVI display channel number  (start from 29) 
    BYTE  byRes1[13]; 
    BYTE  bySupportResolution[MAX_RESOLUTIONNUM]; //resolution enable, 1: enable, 0: unenable
    BYTE  byHDMIWindowMode[4][8]; //Window-split mode supported by HDMI
    BYTE  byDVIWindowMode[4][8]; //Window-split mode supported by DVI
    BYTE  byRes2[24]; 
}NET_DVR_MATRIX_ABILITY,  *LPNET_DVR_MATRIX_ABILITY; 
//Upload Logo
typedef struct tagNET_DVR_DISP_LOGOCFG
{
    DWORD		dwCorordinateX; 	//X- coordinate for logo display 
    DWORD		dwCorordinateY; 	//Y- coordinate for logo display 
	WORD  wPicWidth; //Picture width
	WORD  wPicHeight; //Picture height
    BYTE        byRes1[4]; 
    BYTE        byFlash;   //Flash or not:  1- Flash,  0- Not flash
    BYTE        byTranslucent;  //Translucence or not:  1- Yes,  0- NO
    BYTE		byRes2[6]; 				//Reserved
    DWORD		dwLogoSize; //LOGO size including BMP file head
}NET_DVR_DISP_LOGOCFG, *LPNET_DVR_DISP_LOGOCFG; 

/*Encoding Format*/
#define NET_DVR_ENCODER_UNKOWN		 0 /*Unknown Format*/
#define NET_DVR_ENCODER_H264		 1 /*private H264*/
#define NET_DVR_ENCODER_S264		 2 /*Standard H264*/
#define NET_DVR_ENCODER_MPEG4		 3 /*MPEG4*/
#define NET_DVR_ORIGINALSTREAM		 4 /*Original Stream*/
#define NET_DVR_PICTURE				 5 /*Picture*/

/* Encapsulation Format */
#define NET_DVR_STREAM_TYPE_UNKOWN   0   /*Unknown Format*/
#define NET_DVR_STREAM_TYPE_PRIVT    1   /*private Format*/
#define NET_DVR_STREAM_TYPE_TS		 7   /* TS */
#define NET_DVR_STREAM_TYPE_PS		 8   /* PS */
#define NET_DVR_STREAM_TYPE_RTP		 9   /* RTP */
#define NET_DVR_STREAM_TYPE_ORIGIN   10  //ORIGIN

/*State of decoding channel*/
typedef struct
{
    BYTE  byDecodeStatus; 	/*Status:  0- Disabled,  1- Enabled*/
    BYTE  byStreamType;     /*Stream Type*/
    BYTE  byPacketType;     /*Encapsulation Type*/
    BYTE  byRecvBufUsage; 	/*Usage of receiving buffer*/
    BYTE  byDecBufUsage; 	/*Usage of decoding buffer*/
    BYTE  byFpsDecV; 		/*video decoding frame*/
    BYTE  byFpsDecA; 		/*audio decoding frame*/
    BYTE  byCpuLoad; 		/*DSP CPU usage*/ 
    BYTE  byRes1[4]; 		//Reserved
    DWORD dwDecodedV; 		/*Decoded Video Frame*/
    DWORD dwDecodedA; 		/*Decoded Audio Frame*/
    WORD  wImgW; 			/*Current Image size*/
    WORD  wImgH;  
    BYTE  byVideoFormat;    /*inputted Video standard:  1- PAL,  2- NTSC*/
    BYTE  byRes2[27]; 
}NET_DVR_MATRIX_CHAN_STATUS,  *LPNET_DVR_MATRIX_CHAN_STATUS; 

/*Status of Display Channel*/
#define NET_DVR_MAX_DISPREGION  16        /*Maximum display regions of each display channel*/


//resolution
typedef enum
{
        /*VGA*/
        VGA_NOT_AVALIABLE, 
        VGA_THS8200_MODE_SVGA_60HZ,     // (800*600) 
        VGA_THS8200_MODE_SVGA_75HZ,     // (800*600) 
        VGA_THS8200_MODE_XGA_60HZ,      // (1024*768) 
        VGA_THS8200_MODE_XGA_75HZ,      // (1024*768) 
        VGA_THS8200_MODE_SXGA_60HZ,     // (1280*1024) 
        VGA_THS8200_MODE_720P_60HZ,     // (1280*720) 
        VGA_THS8200_MODE_1080I_60HZ,    // (1920*1080) 
        VGA_THS8200_MODE_1080P_30HZ,    // (1920*1080) 
        VGA_THS8200_MODE_UXGA_30HZ ,    // (1600*1200) 
        /*HDMI*/	
        HDMI_SII9134_MODE_XGA_60HZ, 	// (1024*768) 
        HDMI_SII9134_MODE_SXGA_60HZ,    // (1280*1024) 
        HDMI_SII9134_MODE_SXGA2_60HZ,   // (1280*960) 
        HDMI_SII9134_MODE_720P_60HZ,    // (1280*720) 	
        HDMI_SII9134_MODE_720P_50HZ,    // (1280*720) 		
        HDMI_SII9134_MODE_1080I_60HZ,   // (1920*1080) 
        HDMI_SII9134_MODE_1080I_50HZ,   // (1920*1080) 	
        HDMI_SII9134_MODE_1080P_25HZ,   // (1920*1080) 
        HDMI_SII9134_MODE_1080P_30HZ,   // (1920*1080) 
        HDMI_SII9134_MODE_1080P_50HZ,   // (1920*1080) 
        HDMI_SII9134_MODE_1080P_60HZ,   // (1920*1080) 
        HDMI_SII9134_MODE_UXGA_60HZ,    // (1600*1200) 
        /*DVI*/	
        DVI_SII9134_MODE_XGA_60HZ, 	    // (1024*768) 
        DVI_SII9134_MODE_SXGA_60HZ, 	// (1280*1024) 
        DVI_SII9134_MODE_SXGA2_60HZ,    // (1280*960) 
        DVI_SII9134_MODE_720P_60HZ, 	// (1280*720) 	
        DVI_SII9134_MODE_720P_50HZ,     // (1280*720) 		
        DVI_SII9134_MODE_1080I_60HZ,    // (1920*1080) 
        DVI_SII9134_MODE_1080I_50HZ,    // (1920*1080) 
        DVI_SII9134_MODE_1080P_25HZ,    // (1920*1080) 
        DVI_SII9134_MODE_1080P_30HZ,    // (1920*1080) 
        DVI_SII9134_MODE_1080P_50HZ,    // (1920*1080) 
        DVI_SII9134_MODE_1080P_60HZ,    // (1920*1080) 
        DVI_SII9134_MODE_UXGA_60HZ      // (1600*1200) 
}VGA_MODE; 

//low frame per second
#define           LOW_DEC_FPS_1_2                51
#define           LOW_DEC_FPS_1_4                52
#define           LOW_DEC_FPS_1_8                53
#define           LOW_DEC_FPS_1_16               54

/*Video Standard*/
typedef enum
{
    VS_NON  = 0, 
    VS_NTSC = 1, 
    VS_PAL  = 2
}VIDEO_STANDARD; 

typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG
{        
    DWORD	dwSize;  
    BYTE	byAudio; 			/*Enable Audio, 0- No, 1- Yes*/
    BYTE    byAudioWindowIdx;       /*child window of enabled audio*/
    BYTE 	byVgaResolution;       /*VGA resolution*/
    BYTE	byVedioFormat;          /*Video Standard,  1: NTSC, 2: PAL, 0- NON*/
    DWORD	dwWindowMode; 		/*Windows layout mode gotten from Capability Set:  1, 2, 4, 9, 16 windows*/       
    BYTE	byJoinDecChan[MAX_WINDOWS]; /*Decoding channel associated by each display window*/
    BYTE	byEnlargeStatus;           /*0: Enlarge, 1: not enlarge*/
    BYTE    byEnlargeSubWindowIndex; //Sub Window Index
	union
	{
		BYTE byRes[16];
		struct
		{
			/*Decoding sub system's slot number of the display window's corresponding decoding channel number*/
			BYTE	 byJoinDecoderId[MAX_WINDOWS];
		}struVideoPlatform;
		struct
		{
			BYTE	 byRes[16];
		}struNotVideoPlatform;
	}struDiff;
	/*diff union, 0- video platform integrated decoder, 1-others*/
	BYTE		byUnionType;
	BYTE		byScale; /*show mode,0-real,1-zoom(BNC)*/
}NET_DVR_VGA_DISP_CHAN_CFG, *LPNET_DVR_VGA_DISP_CHAN_CFG; 

/*Status of Display Channel*/
#define NET_DVR_MAX_DISPREGION 16 /*Maximum display regions of each display channel*/
typedef struct
{
    BYTE  byDispStatus;           /*Display Status: 0- No Display, 1- Enabled*/
    BYTE  byBVGA;                 /*0- BNC, 1- VGA,  2- HDMI, 3- DVI*/
    BYTE  byVideoFormat;         /*Video Standard: 1- PAL,  2- NTSC*/
    BYTE  byWindowMode;         /*Current window Layout*/
    BYTE  byJoinDecChan[MAX_WINDOWS];         /*Decoding channel of each region*/
    BYTE  byFpsDisp[NET_DVR_MAX_DISPREGION];  /*Display frame rate of each region*/
    BYTE  byRes2[32]; 
}NET_DVR_DISP_CHAN_STATUS,  *LPNET_DVR_DISP_CHAN_STATUS; 

#define MAX_DECODECHANNUM   32//Maximum number of decoding channel
#define MAX_DISPCHANNUM   24//Maximum number of display channel
/*Decoder Status*/
typedef struct tagNET_DVR_DECODER_WORK_STATUS
{
    DWORD dwSize; 
    NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[MAX_DECODECHANNUM];  /*Status of decoding channel*/
    NET_DVR_DISP_CHAN_STATUS   struDispChanStatus[MAX_DISPCHANNUM];   /*Status of display channel*/
    BYTE byAlarmInStatus[MAX_ANALOG_ALARMIN];          /*Status of Alarm input*/
    BYTE byAlarmOutStatus[MAX_ANALOG_ALARMOUT];        /*Status of Alarm output*/
    BYTE byAudioInChanStatus;           /*Status of intercom*/
    BYTE byRes[127]; 
}NET_DVR_DECODER_WORK_STATUS, *LPNET_DVR_DECODER_WORK_STATUS; 

//2009- 12- 1 Add passive decode play control
typedef struct tagNET_DVR_PASSIVEDECODE_CONTROL
{
    DWORD	dwSize; 
    DWORD	dwPlayCmd; 		/* play command*/
    DWORD	dwCmdParam; 		/* command parameter */
    BYTE	byRes[16]; //Reverse
}NET_DVR_PASSIVEDECODE_CONTROL, *LPNET_DVR_PASSIVEDECODE_CONTROL; 

#define		PASSIVE_DEC_PAUSE				1	/*passive decode pause (only file stream valid) */
#define		PASSIVE_DEC_RESUME				2	/*passive decode resume (only file stream valid) */
#define 	PASSIVE_DEC_FAST          	    3   /*passive decode fast (only file stream valid) */
#define 	PASSIVE_DEC_SLOW			    4   /*passive decode slow (only file stream valid) */
#define 	PASSIVE_DEC_NORMAL      	    5   /*passive decode normal*/
#define 	PASSIVE_DEC_ONEBYONE      	    6   /*passive decode one by one (reserved) */
#define 	PASSIVE_DEC_AUDIO_ON 		    7   /*passive decode open audio*/
#define 	PASSIVE_DEC_AUDIO_OFF		    8  	/*passive decode close audio*/
#define		PASSIVE_DEC_RESETBUFFER			9   /*reset buffer */

//2009- 12- 16 scale control
typedef struct tagNET_DVR_MATRIX_DECCHAN_CONTROL
{        
    DWORD	dwSize; 
    BYTE	byDecChanScaleStatus; /*decode channel scale control, 1: scale display, 0: real display*/
	BYTE    byDecodeDelay;//Decoding delay: 0- default, 1- most real-time, 2- more real-time, 3- real-time and fluency, 4- more fluency, 5- most fluency, 0xff- automatically adjust
	BYTE	byRes[66];//Reverse
}NET_DVR_MATRIX_DECCHAN_CONTROL, *LPNET_DVR_MATRIX_DECCHAN_CONTROL; 

/************************************Decoder (end) ***************************************/

typedef struct 
{	/* 12 bytes */
    DWORD	dwSize; 
    char	sUserName[32]; 
    char 	sPassWord[32]; 
    char 	sFromName[32]; 			/* Sender */
    char 	sFromAddr[48]; 			/* Sender address */
    char 	sToName1[32]; 			/* Receiver1 */
    char 	sToName2[32]; 			/* Receiver2 */
    char 	sToAddr1[48]; 			/* Receiver address1 */
    char 	sToAddr2[48]; 			/* Receiver address2 */
    char	sEmailServer[32]; 		/* Email server address */
    BYTE	byServerType; 			/* Email server type:  0- SMTP,  1- POP,  2- IMTP...*/
    BYTE	byUseAuthen; 			/* Email server authentication method:  1- enable,  0- disable */
    BYTE	byAttachment; 			/* enable attachment */
    BYTE	byMailinterval; 		/* mail interval 0- 2s,  1- 3s,  2- 4s. 3- 5s*/
} NET_DVR_EMAILCFG,  *LPNET_DVR_EMAILCFG; 

typedef struct 
{
    DWORD dwSize; 
    NET_DVR_COMPRESSION_INFO_EX  struLowCompression; 	// Time Record
    NET_DVR_COMPRESSION_INFO_EX  struEventCompression; 	//  Triggered by events
}NET_DVR_COMPRESSIONCFG_NEW,  *LPNET_DVR_COMPRESSIONCFG_NEW; 

//Position info of Speed Dome
typedef struct
{
    WORD wAction; //invalid 
    WORD wPanPos; //pan position
    WORD wTiltPos; //tilt position
    WORD wZoomPos; //zoom position
}NET_DVR_PTZPOS,  *LPNET_DVR_PTZPOS; 

//PTZ Scope Structure 
typedef struct
{
    WORD wPanPosMin; //min pan position
    WORD wPanPosMax; //max pan position
    WORD wTiltPosMin; //min tilt position
    WORD wTiltPosMax; //max tilt position
    WORD wZoomPosMin; //min zoom factor
    WORD wZoomPosMax; //max zoom factor
}NET_DVR_PTZSCOPE,  *LPNET_DVR_PTZSCOPE; 

//rtsp Configuration (Special for IP camera) 
typedef struct
{
    DWORD dwSize;          //Length
    WORD  wPort;           //rtsp Port
    BYTE  byReserve[54];   //Reserved
}NET_DVR_RTSPCFG,  *LPNET_DVR_RTSPCFG; 


/********************************Interface Parameters Structure (begin) *********************************/

//NET_DVR_Login () 
typedef struct NET_DVR_DEVICEINFO
{
    BYTE sSerialNumber[SERIALNO_LEN];   //SN
    BYTE byAlarmInPortNum; 		        //DVR Alarm input
    BYTE byAlarmOutPortNum; 		    //DVR Alarm Output
    BYTE byDiskNum; 				    //DVR Number of Hard Disk
    BYTE byDVRType; 				    //DVR Type,  1: DVR 2: ATM DVR 3: DVS ......
    BYTE byChanNum; 				    //DVR Number of Channel
    BYTE byStartChan; 			        //The first Channel No. E.g. DVS- 1, DVR- 1
}NET_DVR_DEVICEINFO,  *LPNET_DVR_DEVICEINFO; 

//NET_DVR_Login_V30 () 
typedef struct
{
    BYTE sSerialNumber[SERIALNO_LEN];    //SN
    BYTE byAlarmInPortNum; 		        //Number of Alarm input
    BYTE byAlarmOutPortNum; 		        //Number of Alarm Output
    BYTE byDiskNum; 						//Number of Hard Disk
    BYTE byDVRType; 						//DVR Type,  1: DVR 2: ATM DVR 3: DVS ......
    BYTE byChanNum; 						//Number of Analog Channel
    BYTE byStartChan; 			        //The first Channel No. E.g. DVS- 1, DVR- 1
    BYTE byAudioChanNum;                 //Number of Audio Channel
    BYTE byIPChanNum; 					//Maximum number of IP Channel  
    BYTE byZeroChanNum; 			//Zero channel encoding number//2010- 01- 16
    BYTE byMainProto; 			//Main stream transmission protocol 0- private,  1- rtsp
    BYTE bySubProto; 				//Sub stream transmission protocol 0- private,  1- rtsp
    BYTE bySupport;         //Ability, the 'AND' result by bit: 0- not support;  1- support
    //bySupport & 0x1,  smart search
    //bySupport & 0x2,  backup
    //bySupport & 0x4,  get compression configuration ability
    //bySupport & 0x8,  multi network adapter
    //bySupport & 0x10, support remote SADP
    //bySupport & 0x20  support Raid card
    // bySupport & 0x40 support IPSAN directory search
	BYTE bySupport1;        // Ability expand, the 'AND' result by bit: 0- not support;  1- support
							// bySupport1 & 0x1, support snmp v30
						    // bySupport1& 0x2，support distinguish download and playback
	                        //bySupport1 & 0x4, support deployment level
	                        //bySupport1 & 0x8, support vca alarm time extension 
							//bySupport1 & 0x10, support muti disks(more than 33)
	                        //bySupport1 & 0x20, support rtsp over http
    BYTE byRes1;
	WORD wDevType;              //device type
    BYTE byRes2[16];						
}NET_DVR_DEVICEINFO_V30,  *LPNET_DVR_DEVICEINFO_V30; 

//sdk Network environment,  for update
typedef enum _SDK_NET_ENV
{
    LOCAL_AREA_NETWORK = 0, 
    WIDE_AREA_NETWORK
}SDK_NETWORK_ENVIRONMENT; 

//Display Mode
typedef enum
{
    NORMALMODE = 0, 
    OVERLAYMODE
}DISPLAY_MODE; 

//Send Mode
typedef enum
{
    PTOPTCPMODE = 0, 
    PTOPUDPMODE, 
    MULTIMODE, 
    RTPMODE, 
    RESERVEDMODE
}SEND_MODE; 

//Grub Mode
typedef enum 
{
    BMP_MODE  = 0, 		//BMP Mode
    JPEG_MODE = 1		//JPEG Mode 
}CAPTURE_MODE; 

//Real time Audio mode
typedef enum
{
    MONOPOLIZE_MODE = 1, //exclusive mode
    SHARE_MODE      = 2	 //shared mode
}REALSOUND_MODE; 

//Preview via software decoding
typedef struct
{
    LONG  lChannel; //channel no.
    LONG  lLinkMode; //If 31st bit is 0,  it means connect main stream,  is 1 means sub stream. Bit 0~bit 30 are used for link mode:  0:  TCP mode,  1:  UDP mode,  2:  Multi- play mode,  3:  RTP mode,4-RTP/RTSP,5-RSTP/HTTP
    HWND  hPlayWnd; // the play window's handle;  set NULL to disable preview
    char* sMultiCastIP;  //Multicast group
}NET_DVR_CLIENTINFO,  *LPNET_DVR_CLIENTINFO; 

//SDK information (9000 added) 
typedef struct 
{
    DWORD dwTotalLoginNum; 		//current login user operation number
    DWORD dwTotalRealPlayNum; 	//current real play operation number
    DWORD dwTotalPlayBackNum; 	//current playback or download operation number
    DWORD dwTotalAlarmChanNum; 	//current alarm channel operation number
    DWORD dwTotalFormatNum; 		//current HDD format operation number
    DWORD dwTotalFileSearchNum; 	//current files search operation number
    DWORD dwTotalLogSearchNum; 	//current logs search operation number
    DWORD dwTotalSerialNum; 	    //current transparent series port operation number
    DWORD dwTotalUpgradeNum; 	//current upgrading operation number
    DWORD dwTotalVoiceComNum; 	//current network voice communication operation number
    DWORD dwTotalBroadCastNum; 	//current network broadcast voice communication operation number
    DWORD dwTotalListenNum; 	    //current net listen operation number
    DWORD dwEmailTestNum;        //current E- mail test operation number
    DWORD dwBackupNum;           //current backup  operation number
    DWORD dwTotalInquestUploadNum;  //current inquest upload operation number
    DWORD dwRes[6]; 
}NET_DVR_SDKSTATE,  *LPNET_DVR_SDKSTATE; 

//SDK Ability Information  (9000 added) 
typedef struct 
{
    DWORD dwMaxLoginNum; 		//maximum login user operation number MAX_LOGIN_USERS
    DWORD dwMaxRealPlayNum; 		//maximum realplay operation number WATCH_NUM
    DWORD dwMaxPlayBackNum; 		//maximum playback or download operation number WATCH_NUM
    DWORD dwMaxAlarmChanNum; 	//maximum alarm channel operation number ALARM_NUM
    DWORD dwMaxFormatNum; 		//maximum HDD format operation number SERVER_NUM
    DWORD dwMaxFileSearchNum; 	//maximum files search operation number SERVER_NUM
    DWORD dwMaxLogSearchNum; 	//maximum logs search operation number SERVER_NUM
    DWORD dwMaxSerialNum; 	    //maximum transparent series port operation number SERVER_NUM
    DWORD dwMaxUpgradeNum; 	    //maximum current upgrading operation number SERVER_NUM
    DWORD dwMaxVoiceComNum; 		//maximum network voice communication operation number SERVER_NUM
    DWORD dwMaxBroadCastNum; 	//maximum network broadcast voice communication operation number MAX_CASTNUM
    DWORD dwRes[10]; 
}NET_DVR_SDKABL,  *LPNET_DVR_SDKABL; 

//Alarm Device Infor
typedef struct
{   
    BYTE byUserIDValid;                  /* Whether userID is valid,  0- invalid 1- valid. */
    BYTE bySerialValid;                  /* Whether serial number is valid,  0- invalid 1- valid.  */
    BYTE byVersionValid;                 /* Whether version number is valid,  0- invalid 1- valid. */
    BYTE byDeviceNameValid;              /* Whether device name is valid,  0- invalid 1- valid. */
    BYTE byMacAddrValid;                 /* Whether MAC address is valid,  0- invalid 1- valid. */    
    BYTE byLinkPortValid;                /* Whether login port number is valid,  0- invalid 1- valid. */
    BYTE byDeviceIPValid;                /* Whether device IP is valid,  0- invalid 1- valid.*/
    BYTE bySocketIPValid;                /* Whether socket IP is valid,  0- invalid 1- valid. */
    LONG lUserID;                        /* NET_DVR_Login () effective when establishing alarm upload channel*/
    BYTE sSerialNumber[SERIALNO_LEN]; 	/* Serial number. */
    DWORD dwDeviceVersion; 			    /* Version number,  2 high byte means the major version,  2 low byte means the minor version*/
    char sDeviceName[NAME_LEN]; 		    /* Device name. */
    BYTE byMacAddr[MACADDR_LEN]; 		/* MAC address */    
    WORD wLinkPort;                      /* link port */
    char sDeviceIP[128];     			/* IP address */
    char sSocketIP[128];     			/* alarm push- mode socket IP address. */
    BYTE byIpProtocol;                   /* IP protocol:  0- IPV4;  1- IPV6. */
    BYTE byRes2[11]; 
}NET_DVR_ALARMER,  *LPNET_DVR_ALARMER; 

//Display Area Parameter of Hardware Decoding (Sub Structure) 
typedef struct
{
    long bToScreen; 
    long bToVideoOut; 
    long nLeft; 
    long nTop; 
    long nWidth; 
    long nHeight; 
    long nReserved; 
}NET_DVR_DISPLAY_PARA,  *LPNET_DVR_DISPLAY_PARA; 

//Preview Parameter of Hardware Decoding
typedef struct
{
    LONG lChannel; // Channel No.
    LONG lLinkMode;  //0-  TCP;  1-  UDP;  2-  Multicast;  3-  RTP;  4-  PPPoE;  5-  128k;  6-  256k;  7-  384k;  8-  512k
    char* sMultiCastIP; 
    NET_DVR_DISPLAY_PARA struDisplayPara; 
}NET_DVR_CARDINFO,  *LPNET_DVR_CARDINFO; 

//Record Parameters
typedef struct 
{
    char sFileName[100]; // File Name
    NET_DVR_TIME struStartTime; //Start time of the file
    NET_DVR_TIME struStopTime; //End time of the file
    DWORD dwFileSize; //File size
}NET_DVR_FIND_DATA,  *LPNET_DVR_FIND_DATA; 

//Record Parameters (9000) 
typedef struct 
{
    char sFileName[100]; //File Name
    NET_DVR_TIME struStartTime; //Start time of the file
    NET_DVR_TIME struStopTime; //End time of the file
    DWORD dwFileSize; //File size
    char sCardNum[32]; 
    BYTE byLocked; //9000 DVR supports this, 1- file is locked, 0- file is Normal
    BYTE byFileType;   //File Type:  0:  scheduled record,  1:  Motion detection,  2:  alarm record,  3:  motion detection| alarm,  4:  motion detection & alarm 5:  command trigger,  6:  manually record
	//9-VCA alarm,10-PIR alarm,11-wireless alarm,12-callhelp alarm,14-Intelligent Transportation
    BYTE byRes[2]; 
}NET_DVR_FINDDATA_V30,  *LPNET_DVR_FINDDATA_V30; 

//Record Parameters (with Card No.) 
typedef struct 
{
    char sFileName[100]; //File Name
    NET_DVR_TIME struStartTime; //Start time of the file
    NET_DVR_TIME struStopTime; //End time of the file
    DWORD dwFileSize; //File size
    char sCardNum[32]; 
}NET_DVR_FINDDATA_CARD,  *LPNET_DVR_FINDDATA_CARD; 


//Record Query Condition
typedef struct 
{
    LONG lChannel; //channel number
    DWORD dwFileType; /*file record mode: 0xff - all,  0 - scheduled record,  1 - Motion detection,  2 - alarm record,  3:  motion detection| alarm,  
	                                  4 - motion detection & alarm, 5 - command trigger,  6 - manually record,7-VCA record,10-PIR alarm,11-wireless alarm,12-callhelp alarm,13-motion|alarm|PIR|wireless|callhelp,14-Intelligent Transportation*/
    DWORD dwIsLocked; //whether file is locked,  0- normal;  1- locked;  0xff- all
    DWORD dwUseCardNo; //whether card no. is used
    BYTE sCardNumber[32]; //card no.
    NET_DVR_TIME struStartTime; //start time
    NET_DVR_TIME struStopTime; //end time
}NET_DVR_FILECOND,  *LPNET_DVR_FILECOND; 


// PTZ Image Zooming  (Special for private Speed dome) 
typedef struct 
{
    int xTop;      //x coordinate of the origination point of the pane
    int yTop;      //y coordinate of the origination point of the pane
    int xBottom;   //x coordinate of the end point of the pane
    int yBottom;   //y coordinate of the end point of the pane
    int bCounter;  //reserve
}NET_DVR_POINT_FRAME,  *LPNET_DVR_POINT_FRAME; 

//audio encode type
typedef struct tagNET_DVR_COMPRESSION_AUDIO
{
    BYTE  byAudioEncType;    //AudioTalk Code Type 0- OggVorbis; 1- G711_U; 2- G711_A
    BYTE  byres[7];    //reserve
}NET_DVR_COMPRESSION_AUDIO,  *LPNET_DVR_COMPRESSION_AUDIO; 

//2009- 7- 22
#define IW_ESSID_MAX_SIZE						 32
#define WIFI_WEP_MAX_KEY_COUNT					 4
#define WIFI_WEP_MAX_KEY_LENGTH					 33
#define WIFI_WPA_PSK_MAX_KEY_LENGTH				 63
#define WIFI_WPA_PSK_MIN_KEY_LENGTH				 8
#define WIFI_MAX_AP_COUNT						 20

typedef struct tagNET_DVR_AP_INFO
{
    char  sSsid[IW_ESSID_MAX_SIZE]; 
    DWORD  dwMode; 						/* 0- mange mode; 1 ad- hoc mode, plz refer to NICMODE */
    DWORD  dwSecurity;            /*0 - not encrypted;  1 wep encrypted;  2 wpa- psk; 3 wpa- Enterprise; 4-WPA2_PSK;refer to WIFISECURITY*/
    DWORD  dwChannel;             /*1-11,  stands for 11 channels*/
    DWORD  dwSignalStrength;     /* Signal strength, 0 (lowest)- 100 (highest)*/
    DWORD  dwSpeed;                /* Signal speed, unit: 0.01mbps*/
}NET_DVR_AP_INFO, *LPNET_DVR_AP_INFO; 

typedef struct tagNET_DVR_AP_INFO_LIST
{
    DWORD dwSize; 
    DWORD dwCount;         /*Wireless AP number, should be less than 20*/
    NET_DVR_AP_INFO struApInfo[WIFI_MAX_AP_COUNT]; 
}NET_DVR_AP_INFO_LIST, *LPNET_DVR_AP_INFO_LIST; 

typedef struct tagNET_DVR_WIFIETHERNET
{	
    char    sIpAddress[16]; 				/*IP*/
    char    sIpMask[16]; 					/*Sub net mask*/	
    BYTE    byMACAddr[MACADDR_LEN]; 		/*Physical address, read-only*/
    BYTE	bRes[2]; 
    DWORD	dwEnableDhcp; 				/*DHCP: 0-disable;  1- enable*/
    DWORD	dwAutoDns; 					/*Get DNS automatically after enable DHCP: 0-disable;  1-enable;  for cable network, DHCP will be set as 'get DNS automatically' mode*/	
    char    sFirstDns[16]; 						 /*Preferred DNS*/
    char    sSecondDns[16]; 					 /*Alternate DNS*/
    char    sGatewayIpAddr[16];  				/*Network Gateway*/
    BYTE    bRes2[8]; 
}NET_DVR_WIFIETHERNET, *LPNET_DVR_WIFIETHERNET; 

typedef struct tagNET_DVR_WIFI_CFG_EX
{
    NET_DVR_WIFIETHERNET struEtherNet;         /*WIFI port*/
    char sEssid[IW_ESSID_MAX_SIZE]; 	 /*SSID*/
    DWORD dwMode;       /* 0- mange  mode; 1 ad- hoc mode*/
    DWORD dwSecurity;  /*0- no encryption; 1- wep encryption; 2 wpa- psk;3-WPA_ENTPRISE;4-WPA2_PSK,5-WPA2_ENTPRISE  */
    union 
    {
        struct 
        {
            DWORD dwAuthentication; /*0 - open mode;  1- share mode*/
            DWORD dwKeyLength; /* 0 - 64 bit;  1-  128bit;  2- 152 bit*/
            DWORD dwKeyType; /*0-HEX;  1-ASCI */
            DWORD dwActive; /*0- index: 0- - - 3 stands for the KEY mode*/
            char sKeyInfo[WIFI_WEP_MAX_KEY_COUNT][WIFI_WEP_MAX_KEY_LENGTH]; 
        }wep; 
        struct 
        {
            DWORD dwKeyLength; /*8~ 63 ASCII characters*/
            char sKeyInfo[WIFI_WPA_PSK_MAX_KEY_LENGTH]; 
            BYTE byEncryptType;  /*WPA/WPA2:0-AES, 1-TKIP*/
        }wpa_psk; 
		struct 
		{
            BYTE byEncryptType;  /*加密类型,0-AES, 1-TKIP*/
			BYTE byAuthType; //认证类型，0-EAP_TTLS,1-EAP_PEAP,2-EAP_TLS
            BYTE byRes[2];
			union
            {
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-PAP，1-MSCHAPV2
                    BYTE byRes1[2];
                    BYTE byAnonyIdentity [NAME_LEN]; //匿名身份
					BYTE byUserName[NAME_LEN]; //用户名
                    BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44];
				}EAP_TTLS; //WPA-enterprise/WPA2-enterpris模式适用
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-GTC，1-MD5，2-MSCHAPV2
                    BYTE byPeapVersion; //PEAP版本，0-版本0，1-版本1
                    BYTE byPeapLabel; //PEAP标签，0-老标签，1-新标签
                    BYTE byAnonyIdentity[NAME_LEN]; //匿名身份
					BYTE byUserName[NAME_LEN]; //用户名
					BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44]; 
				}EAP_PEAP; //WPA-enterprise/WPA2-enterpris模式适用
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byRes1[3]; 
                    BYTE byIdentity[NAME_LEN]; //身份
					BYTE byPrivateKeyPswd[NAME_LEN]; //私钥密码
                    BYTE byRes[76]; 
				}EAP_TLS; 
            }auth_param;
		}wpa_wpa2; //WPA-enterprise/WPA2-enterpris模式适用
    }key; 	
}NET_DVR_WIFI_CFG_EX, *LPNET_DVR_WIFI_CFG_EX; 

//WIFI configuration structure
typedef struct tagNET_DVR_WIFI_CFG
{
    DWORD dwSize; 
    NET_DVR_WIFI_CFG_EX struWifiCfg; 
}NET_DVR_WIFI_CFG, *LPNET_DVR_WIFI_CFG; 

//WIFI working mode
typedef struct tagNET_DVR_WIFI_WORKMODE
{
    DWORD dwSize; 
    DWORD dwNetworkInterfaceMode;  /*0- auto switch mode;  1- cable network*/
}NET_DVR_WIFI_WORKMODE, *LPNET_DVR_WIFI_WORKMODE; 


//Structure parameters  
#define VCA_MAX_POLYGON_POINT_NUM		10		//Support polygon with up to 10 coordinates
#define MAX_RULE_NUM					8		//Max. rule number
#define MAX_TARGET_NUM    				30		//Max. target number
#define MAX_CALIB_PT 					6		//Max. calibration number
#define MIN_CALIB_PT 					4		//Min. calibration number
#define MAX_TIMESEGMENT_2	    		2		//Max. time periods number
#define MAX_LICENSE_LEN					16		//Max. length of the license number
#define MAX_PLATE_NUM					3		//license plate number
#define MAX_MASK_REGION_NUM				4       //Max. 4 mask area
#define MAX_SEGMENT_NUM					6        //Max. segment number for camera calibration
#define MIN_SEGMENT_NUM					3        //Min. segment number for camera calibration


//Intelligent config info
#define MAX_VCA_CHAN  16//Max. intelligent channel number
typedef struct tagNET_VCA_CTRLINFO
{
    BYTE   byVCAEnable; 		//enable or disable intelligent function
    BYTE   byVCAType; 	    //intelligent analysis mode, VCA_CHAN_ABILITY_TYPE 
    BYTE   byStreamWithVCA;  //include intelligent info in video stream
    BYTE   byMode; 			// VCA_CHAN_MODE_TYPE , for ATM intelligent analysis
	BYTE  byControlType; //control type,0-no,1-yes
	// byControlType &1 enable snap
    BYTE   byRes[3];  		//Reserved as 0 
}NET_VCA_CTRLINFO,  *LPNET_VCA_CTRLINFO; 

//Intelligent config info structure
typedef struct tagNET_VCA_CTRLCFG
{
    DWORD dwSize; 
    NET_VCA_CTRLINFO  struCtrlInfo[MAX_VCA_CHAN];  	//Config info, array 0 is corresponding to the 1st channel of the system
    BYTE byRes[16]; 
}NET_VCA_CTRLCFG,  * LPNET_VCA_CTRLCFG; 

//Intelligent device ability set
typedef struct tagNET_VCA_DEV_ABILITY
{
    DWORD dwSize; 			//structure length
    BYTE byVCAChanNum; 		//intelligent channel number
    BYTE byPlateChanNum;  	//LPR channel number
    BYTE byBBaseChanNum; 	//Basic VCA number
    BYTE byBAdvanceChanNum;  //Advanced VCA number
    BYTE byBFullChanNum;     //Complete VCA number
    BYTE byATMChanNum; 		//Intelligent ATM number
    BYTE byPDCChanNum;       //PDC channel number
    BYTE byITSChanNum;       //Traffic event analysis channel number
    BYTE byBPrisonChanNum; 	// VCA (prison surveillance version) channel number
    BYTE byFSnapChanNum;  //Face snap channel number
	BYTE byFSnapRecogChanNum;  //Face snap and recognize channel number
	BYTE byFRetrievalChanNum; //Face retrieval channel number
	BYTE bySupport; //ability, bit, 0-not support,1-support
	//bySupport & 0x1,support track 2012-3-22
	BYTE byFRecogChanNum; //Face recognize channel number
	BYTE byBPPerimeterChanNum; //prison perimeter channel number
	BYTE byTPSChanNum; //Traffic TPS channel number
    BYTE byRes[24];
}NET_VCA_DEV_ABILITY,  *LPNET_VCA_DEV_ABILITY; 


//VCA Abilities Set
typedef enum _VCA_ABILITY_TYPE_
{
    TRAVERSE_PLANE_ABILITY       = 0x01,        //traverse plane
    ENTER_AREA_ABILITY           = 0x02,        //Enter area
    EXIT_AREA_ABILITY            = 0x04,        //Leave area
    INTRUSION_ABILITY            = 0x08,        //Intrusion
    LOITER_ABILITY               = 0x10,        //Loitering
    LEFT_TAKE_ABILITY            = 0x20,        //Object left/take
    PARKING_ABILITY              = 0x40,        //Illegal parking
    RUN_ABILITY                  = 0x80,        //Running
    HIGH_DENSITY_ABILITY         = 0x100,       //People density
    LF_TRACK_ABILITY			 = 0x200,       //Auto-tracking of the speed dome
    VIOLENT_MOTION_ABILITY		 = 0x400, 		//Violent motion
    REACH_HIGHT_ABILITY			 = 0x800, 		//Reach High
    GET_UP_ABILITY				 = 0x1000, 	    //Get up
    LEFT_ABILITY                 = 0x2000,      //Item left
    TAKE_ABILITY                 = 0x4000,      //Item take
	LEAVE_POSITION               = 0x8000,      //Leave position
	TRAIL_ABILITY                = 0x10000,     //Trial
	FALL_DOWN_ABILITY            = 0x80000,     //Fall down
	AUDIO_ABNORMAL_ABILITY       = 0x100000,    //Audio abnormal
    HUMAN_ENTER_ABILITY          = 0x10000000,  //Human enter ATM, supported only in ATM_PANEL mode
    OVER_TIME_ABILITY            = 0x20000000,  //Overtime, supported only in ATM_PANEL mode
    STICK_UP_ABILITY             = 0x40000000,  //ATM stick-up
    INSTALL_SCANNER_ABILITY      = 0x80000000   //Install scanner on ATM
}VCA_ABILITY_TYPE; 


//Intelligent channel type
typedef enum _VCA_CHAN_ABILITY_TYPE_
{
    VCA_BEHAVIOR_BASE     =  1,         //Basic VCA
    VCA_BEHAVIOR_ADVANCE  =  2,     //Advanced VCA
    VCA_BEHAVIOR_FULL     =  3,     //FULL VCA
    VCA_PLATE     		  =  4,     //LPR
    VCA_ATM               =  5,     //ATM
    VCA_PDC               =  6,     //PDC
    VCA_ITS               =  7,     //Intelligent traffic surveillance
    VCA_BEHAVIOR_PRISON   =  8,     //VCA (prison surveillance version)  
    VCA_FACE_SNAP         =  9,     //Face snap
	VCA_FACE_SNAPRECOG    =  10,    //Face snap and recognize
	VCA_FACE_RETRIEVAL    =  11,    //Face retrieval
	VCA_FACE_RECOG        = 12,    //Face recognize
	VCA_BEHAVIOR_PRISON_PERIMETER  =  13,     //VCA (prison perimeter version)
	VCA_TPS               = 14     //TPS
}VCA_CHAN_ABILITY_TYPE; 

//Intelligent ATM Mode 
typedef enum _VCA_CHAN_MODE_TYPE_
{
    VCA_ATM_PANEL     =  0,  //ATM front panel
    VCA_ATM_SURROUND  =  1,   //ATM scenario
    VCA_ATM_FACE	  =  2		//ATM face recognition & private ATM face detect
}VCA_CHAN_MODE_TYPE; 


//Channel ability input
typedef struct tagNET_VCA_CHAN_IN_PARAM
{
    BYTE byVCAType; 	//VCA_CHAN_ABILITY_TYPE enum
    BYTE byMode; 		//VCA_CHAN_MODE_TYPE for ATM analysis; when VCA_TYPE is traffic event, please refer to TRAFFIC_SCENE_MODE
    BYTE byRes[2];  	//Reserved
}NET_VCA_CHAN_IN_PARAM,  *LPNET_VCA_CHAN_IN_PARAM; 


//Behavior ability set
typedef struct tagNET_VCA_BEHAVIOR_ABILITY
{
    DWORD dwSize; 		 //Structure length
    DWORD dwAbilityType;  //Support ability type by digit, please refer to VCA_ABILITY_TYPE
    BYTE byMaxRuleNum; 	 //Max. rule number
    BYTE byMaxTargetNum;  //Max. target number
    BYTE	bySupport; 		//Function type supported (represented by digit)  
    // bySupport & 0x01 -Calibration
    BYTE byRes[9];         //Reserved as 0
}NET_VCA_BEHAVIOR_ABILITY,  *LPNET_VCA_BEHAVIOR_ABILITY; 

// Traffic ability structure
typedef struct tagNET_DVR_ITS_ABILITY
{
    DWORD 	dwSize;             //Structure size
    DWORD 	dwAbilityType;      //Supported ability list, see to ITS_ABILITY_TYPE
    BYTE 	byMaxRuleNum;	 	//Max number of rules
    BYTE 	byMaxTargetNum; 	//Max number of targets
   	BYTE	byRes[10];		    //Reserved
}NET_DVR_ITS_ABILITY, *LPNET_DVR_ITS_ABILITY;

/***********************************end*******************************************/

/************************************Intelligent Parameter Structure*********************************/
//Public structure for intelligent functions
//Coordinates normalized, and the  floating-point value is the percentage of the current screen size
//Take accuracy of three decimal places

//Point
typedef struct tagNET_VCA_POINT
{	
    float fX; 								//X axis coordinate,  0.001~1
    float fY; 								//Y axis coordinate,  0.001~1
}NET_VCA_POINT,  *LPNET_VCA_POINT; 

//Region
typedef struct tagNET_VCA_RECT
{
    float fX;                //X axis coordinate of the upper-left,  0.001~1
    float fY;                //Y axis coordinate of the upper-left,  0.001~1
    float fWidth;            //Region width,  0.001~1
    float fHeight;           //Region height,  0.001~1
}NET_VCA_RECT,  *LPNET_VCA_RECT; 

//Behavior event type
typedef enum _VCA_EVENT_TYPE_
{
    VCA_TRAVERSE_PLANE		= 0x1,      //Traverse plane
    VCA_ENTER_AREA		= 0x2,			//Enter area (region rule)
    VCA_EXIT_AREA		= 0x4,			//Leave area (region rule)
    VCA_INTRUSION		= 0x8,			//Intrusion (region rule)
    VCA_LOITER			= 0x10,			//Loitering (region rule)
    VCA_LEFT_TAKE		= 0x20,			//Object left or take (region rule)
    VCA_PARKING			= 0x40,			//Illegal parking (region rule)
    VCA_RUN				= 0x80,			//Running (region rule)
    VCA_HIGH_DENSITY	= 0x100,		//People density (region rule)
    VCA_VIOLENT_MOTION	= 0x200, 		//Violent motion
    VCA_REACH_HIGHT		= 0x400, 		//Reach high
    VCA_GET_UP			= 0x800, 		//Get up
    VCA_LEFT            = 0x1000,		//Item left
    VCA_TAKE            = 0x2000,		//Item take
	VCA_LEAVE_POSITION  = 0x4000,       //Leave position
	VCA_TRAIL           = 0x8000,       //Trail
	VCA_FALL_DOWN       = 0x80000,      //Fall down
	VCA_AUDIO_ABNORMAL  = 0x100000,     //Audio abnormal
    VCA_HUMAN_ENTER     = 0x10000000,   //Human enter ATM, supported only in ATM_PANEL mode
    VCA_OVER_TIME       = 0x20000000,   //Operation overtime, supported only in ATM_PANEL mode
    VCA_STICK_UP        = 0x40000000,   //ATM stick up (region rule)
    VCA_INSTALL_SCANNER = 0x80000000    //Install scanner on ATM (region rule)
}VCA_EVENT_TYPE; 

//Traverse plane direction
typedef enum _VCA_CROSS_DIRECTION_
{
    VCA_BOTH_DIRECTION,   // Bi-direction
    VCA_LEFT_GO_RIGHT,    // Left to right
    VCA_RIGHT_GO_LEFT     // Right to left
}VCA_CROSS_DIRECTION; 

//Line
typedef struct tagNET_VCA_LINE
{
    NET_VCA_POINT struStart;     // start point
    NET_VCA_POINT struEnd;       // end point
}NET_VCA_LINE,  *LPNET_VCA_LINE; 

//Polygon
typedef struct tagNET_VCA_POLYGON
{
    DWORD dwPointNum;                                   //Valid point number , should be no less than 3 
    NET_VCA_POINT  struPos[VCA_MAX_POLYGON_POINT_NUM];  //Boundary point, up to 10 points for each polygon
}NET_VCA_POLYGON,  *LPNET_VCA_POLYGON; 

//Traverse plane 
typedef struct tagNET_VCA_TRAVERSE_PLANE
{	
    NET_VCA_LINE struPlaneBottom;   //Bottom line of the alarm plane
    VCA_CROSS_DIRECTION dwCrossDirection;  //Traverse direction:  0- bi-directional, 1- left to right, 2- right to left
    BYTE byRes1; //Reserved 
    BYTE byPlaneHeight;  //Height of the alarm plane
    BYTE byRes2[38]; 				//Reserved
}NET_VCA_TRAVERSE_PLANE,  *LPNET_VCA_TRAVERSE_PLANE; 

//Enter or Leave area
typedef struct tagNET_VCA_AREA
{
    NET_VCA_POLYGON struRegion; //Region
    BYTE byRes[8]; 
}NET_VCA_AREA,  *LPNET_VCA_AREA; 

//Mark the alarm snapshot according to the alarm delay time (alarm interval is consistent with IO alarm), send 1 snapshot every second
//Intrusion
typedef struct tagNET_VCA_INTRUSION
{
    NET_VCA_POLYGON struRegion; //region
    WORD wDuration;     // trigger after:  1- 120 second, suggested 5 
    BYTE byRes[6]; 
}NET_VCA_INTRUSION,  *LPNET_VCA_INTRUSION; 

//Loitering
typedef struct tagNET_VCA_PARAM_LOITER
{
    NET_VCA_POLYGON struRegion; //Region
    WORD wDuration;  //Trigger after: 1- 120 second, suggested 10
    BYTE byRes[6]; 
}NET_VCA_LOITER,  *LPNET_VCA_LOITER; 

//Object left or taken
typedef struct tagNET_VCA_TAKE_LEFT
{
    NET_VCA_POLYGON struRegion; //Region
    WORD wDuration;  //Trigger after: 1- 120 second, suggested 10
    BYTE byRes[6]; 
}NET_VCA_TAKE_LEFT,  *LPNET_VCA_TAKE_LEFT; 

//Illegal 
typedef struct tagNET_VCA_PARKING
{
    NET_VCA_POLYGON struRegion; 	//Region
    WORD wDuration; 				//Trigger after: 1- 100 second, suggested 10
    BYTE byRes[6]; 
}NET_VCA_PARKING,  *LPNET_VCA_PARKING; 

//Running
typedef struct tagNET_VCA_RUN
{
    NET_VCA_POLYGON struRegion; 	//Region
    float  fRunDistance; 		//Target running distance: [0.1,  1.00]
    BYTE    byRes1;             // Reserved
    BYTE    byMode;             // 0- pixel mode, 1- actual mode
    BYTE byRes[2];
}NET_VCA_RUN,  *LPNET_VCA_RUN; 

//People gathering
typedef struct tagNET_VCA_HIGH_DENSITY
{
    NET_VCA_POLYGON struRegion;     //Region
    float fDensity;                 //Density range:  [0.1,  1.0]
    BYTE            bySensitivity;	//Sensitivity, value range: [1,5]
    BYTE            byRes;          //Reserved
    WORD            wDuration;      //Threshold of triggering people aggregation alarm,value: 20-360s
}NET_VCA_HIGH_DENSITY,  *LPNET_VCA_HIGH_DENSITY;  

//Violent motion
typedef struct tagNET_VCA_VIOLENT_MOTION
{
    NET_VCA_POLYGON struRegion; //Region
    WORD wDuration;  //Trigger after: 1- 120 second
    BYTE  bySensitivity;        //Sensitivity range: [1, 5]
    BYTE byRes[5]; 
}NET_VCA_VIOLENT_MOTION,  *LPNET_VCA_VIOLENT_MOTION;  

// Reach high
typedef struct tagNET_VCA_REACH_HIGHT
{
    NET_VCA_LINE struVcaLine;    //Alarm plane
    WORD wDuration;  //Trigger after: 1- 120 second
    BYTE	byRes[6];            // Reserved
}NET_VCA_REACH_HIGHT,  *LPNET_VCA_REACH_HIGHT; 

// Get up
typedef struct tagNET_VCA_GET_UP
{
    NET_VCA_POLYGON struRegion;  // Region
    WORD	wDuration; 	// Trigger after: 1- 120 second
    BYTE	byRes[6]; 		// Reserved
}NET_VCA_GET_UP,  * LPNET_VCA_GET_UP; 

// Items left
typedef struct tagNET_VCA_LEFT
{
    NET_VCA_POLYGON struRegion;  // Region 
    WORD      wDuration;         // Threshold of triggering itmes left alarm, value: 4-60s
    BYTE       byRes[6];         // Reserved
}NET_VCA_LEFT, *LPNET_VCA_LEFT;

//Items take
typedef struct tagNET_VCA_TAKE
{
    NET_VCA_POLYGON struRegion;     // Region
    WORD            wDuration;      // Threshold of triggering itmes take alarm, value: 4-60s
    BYTE            byRes[6];       // Reserved
}NET_VCA_TAKE, *LPNET_VCA_TAKE;

typedef struct tagNET_VCA_OVER_TIME
{
    NET_VCA_POLYGON     struRegion; // Region
    WORD               wDuration;   // Time threshold of operation alarm, value: 4s-60000s
    BYTE   byRes[6];                // Reserved
}NET_VCA_OVER_TIME, *LPNET_VCA_OVER_TIME;

typedef struct tagNET_VCA_HUMAN_ENTER
{
    DWORD                dwRes[23];			//Reserved
}NET_VCA_HUMAN_ENTER, *LPNET_VCA_HUMAN_ENTER;

//ATM stick up
typedef struct tagNET_VCA_STICK_UP
{
    NET_VCA_POLYGON struRegion; //Region
    WORD wDuration;  //Trigger after: 4- 60 second, suggested 10 second
    BYTE  bySensitivity;        // Sensitivity range: [1, 5]
    BYTE byRes[5]; 
}NET_VCA_STICK_UP,  *LPNET_VCA_STICK_UP;  

//Install scanner on ATM
typedef struct tagNET_VCA_SCANNER
{
    NET_VCA_POLYGON struRegion; //Region
    WORD wDuration;  // Scanner reading time: 4- 60 seconds
    BYTE  bySensitivity;        // Sensitivity range: [1, 5]
    BYTE byRes[5]; 
}NET_VCA_SCANNER,  *LPNET_VCA_SCANNER;  

//Leave position
typedef struct tagNET_VCA_LEAVE_POSITION
{
	NET_VCA_POLYGON   struRegion; //Region
	WORD wLeaveDelay;  //Alarm time of no people, unit: s, value:1-1800
	WORD wStaticDelay; //Alarm time of sleeping, unit: s, value:1-1800
	BYTE byRes[4]; 
}NET_VCA_LEAVE_POSITION, *LPNET_VCA_LEAVE_POSITION;

//Trail
typedef struct tagNET_VCA_TRAIL
{
	NET_VCA_POLYGON struRegion;//Region
	WORD  wRes;     
	BYTE  bySensitivity;       /* Sensitivity range: [1, 5] */
	BYTE  byRes[5];
}NET_VCA_TRAIL, *LPNET_VCA_TRAIL;

//Fall down
typedef struct tagNET_VCA_FALL_DOWN
{
	NET_VCA_POLYGON struRegion;//Region
	WORD  wDuration;      /* Threshold of triggering itmes take alarm, value: 1-60s*/
	BYTE  bySensitivity;       /* Sensitivity range: [1, 5] */
	BYTE  byRes[5];
}NET_VCA_FALL_DOWN, *LPNET_VCA_FALL_DOWN;

//Audio abnormal
typedef struct tagNET_VCA_AUDIO_ABNORMAL
{
    WORD  wDecibel;        //Audio decibel
	BYTE   bySensitivity;    /* Sensitivity range: [1, 5] */
    BYTE   byRes;   
    DWORD dwRes[14];        
}NET_VCA_AUDIO_ABNORMAL, *LPNET_VCA_AUDIO_ABNORMAL;

//Alarm event parameters
typedef union tagNET_VCA_EVENT_UNION
{
    DWORD                uLen[23]; 			        //Parameters
    NET_VCA_TRAVERSE_PLANE    struTraversePlane; 	//Traverse plane parameters 
    NET_VCA_AREA    	 struArea; 			        //Enter or Leave area
    NET_VCA_INTRUSION    struIntrusion; 		    //Intrusion
    NET_VCA_LOITER       struLoiter; 	         	//Loitering
    NET_VCA_TAKE_LEFT    struTakeTeft; 	            //Object left or taken
    NET_VCA_PARKING      struParking; 		        //Illegal parking
    NET_VCA_RUN          struRun; 			        //Running
    NET_VCA_HIGH_DENSITY struHighDensity; 	        //People gathering  
    NET_VCA_VIOLENT_MOTION struViolentMotion; 	    //Violent motion
    NET_VCA_REACH_HIGHT	struReachHight; 	        //Reach High
    NET_VCA_GET_UP		struGetUp; 		            //Get up
    NET_VCA_LEFT        struLeft;                   //Items left
    NET_VCA_TAKE        struTake;                   //Items take
    NET_VCA_HUMAN_ENTER struHumanEnter;             //Human entrance
    NET_VCA_OVER_TIME   struOvertime;               //Operation overtime
    NET_VCA_STICK_UP 	struStickUp; 		//ATM stick up
    NET_VCA_SCANNER 	struScanner; 		//Install scanner on ATM 	
    NET_VCA_LEAVE_POSITION struLeavePos;    //Parameter that leave the position
	NET_VCA_TRAIL          struTrail; //Trail
	NET_VCA_FALL_DOWN      struFallDown; //Fall down
	NET_VCA_AUDIO_ABNORMAL struAudioAbnormal;  //Audio abnormal
}NET_VCA_EVENT_UNION,  *LPNET_VCA_EVENT_UNION; 

// Target size filter
typedef enum _VCA_SIZE_FILTER_MODE_
{
    IMAGE_PIX_MODE,   // Set by pixels
	REAL_WORLD_MODE,  // Set by actual size
    DEFAULT_MODE 	  // Default
}SIZE_FILTER_MODE; 
//Size filter
typedef struct tagNET_VCA_SIZE_FILTER
{
    BYTE    byActive; 			// Enable filter: 0- disable;  1- enable
    BYTE    byMode; 		    //SIZE_FILTER_MODE
    BYTE    byRes[2];           //Reserved as 0
    NET_VCA_RECT struMiniRect;  //Min. target region, 0 stands for no region settings
    NET_VCA_RECT struMaxRect; 	//Max. target region, 0 stands for no region settings
}NET_VCA_SIZE_FILTER,  *LPNET_VCA_SIZE_FILTER; 

//Alarm rule configuration
typedef struct tagNET_VCA_ONE_RULE
{
    BYTE   byActive; 				 	 //Activate rule settings: 0- disable;  1- enable
    BYTE   byRes[7];          			 //Reserved as 0
    BYTE   byRuleName[NAME_LEN]; 	 	 //Rule name
    VCA_EVENT_TYPE dwEventType; 		 //VCA event type
    NET_VCA_EVENT_UNION uEventParam; 	 //VCA event parameters
    NET_VCA_SIZE_FILTER  struSizeFilter; //Size filter
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2]; // Arm time
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType; 	//Handle method
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; 			//Alarm trigger recording channel, 1- trigger recording on this channel
}NET_VCA_ONE_RULE,  *LPNET_VCA_ONE_RULE; 

//VCA configuration structure
typedef struct tagNET_VCA_RULECFG
{
    DWORD  dwSize; 			//Structure length
    BYTE    byPicProType; 	//0- do not upload snapshot;  1 - Upload  snapshot on VCA alarm
	BYTE    byUpLastAlarm;  //2011-04-06 Whether upload last alarm firstly 
	BYTE   byPicRecordEnable;  /*2012-3-1 Whether record picture, 0-no,1-yes*/
	BYTE    byRes;
    NET_DVR_JPEGPARA struPictureParam;  		//snapshot structure
    NET_VCA_ONE_RULE  struRule[MAX_RULE_NUM];   //Rule array
}NET_VCA_RULECFG,  *LPNET_VCA_RULECFG; 

//Alarm rule configuration
typedef struct tagNET_VCA_ONE_RULE_V41
{
	BYTE   byActive;					//Activate rule settings: 0- disable;  1- enable
	BYTE   byRes1[7];         			
    BYTE   byRuleName[NAME_LEN];		//Rule name
	VCA_EVENT_TYPE dwEventType;			//VCA event type
    NET_VCA_EVENT_UNION uEventParam;	//VCA event parameters
    NET_VCA_SIZE_FILTER  struSizeFilter;  //Size filter
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];// Arm time
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //Handle method
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//Alarm trigger recording channel, 1- trigger recording on this channel
    BYTE byRes[60];
}NET_VCA_ONE_RULE_V41, *LPNET_VCA_ONE_RULE_V41;

//VCA configuration structure
typedef struct tagNET_VCA_RULECFG_V41
{
	DWORD  dwSize;			
	BYTE    byPicProType;	//0- do not upload snapshot;  1 - Upload  snapshot on VCA alarm
	BYTE    byUpLastAlarm; //2011-04-06 Whether upload last alarm firstly
	BYTE    byPicRecordEnable;  /*2012-3-1 Whether to enable the image storage, 0-Not enabled, 1-enabled*/
	BYTE    byRes1;
	NET_DVR_JPEGPARA struPictureParam; 		//snapshot structure
	NET_VCA_ONE_RULE_V41  struRule[MAX_RULE_NUM];  //Rule array
	BYTE byRes[32];
}NET_VCA_RULECFG_V41, *LPNET_VCA_RULECFG_V41;

//Simplified target info structure
typedef struct tagNET_VCA_TARGET_INFO
{
    DWORD    dwID; 				//Target ID, the target ID will be 0 on high density alarm
    NET_VCA_RECT struRect;       //target brim rectangle
    BYTE      byRes[4]; 			//Reserved
}NET_VCA_TARGET_INFO,  *LPNET_VCA_TARGET_INFO; 

//Simplified rule info
typedef struct tagNET_VCA_RULE_INFO
{
    BYTE   byRuleID; 		    //Rule ID, 0- 7
    BYTE   byRes[3]; 			//Reserved
    BYTE   byRuleName[NAME_LEN];  //Rule name
    VCA_EVENT_TYPE  dwEventType;  //Intelligent event type
    NET_VCA_EVENT_UNION uEventParam; //Event parameters
}NET_VCA_RULE_INFO,  *LPNET_VCA_RULE_INFO; 

//PU address info, (address of connected IP device for iVMS, or local address for the other intelligent devices)
typedef struct tagNET_VCA_DEV_INFO
{
    NET_DVR_IPADDR  struDevIP;  //PU address  
    WORD wPort;  			//PU port number  
    BYTE byChannel;   		//PU channel number
    BYTE byIvmsChannel; 		// Ivms channel
} NET_VCA_DEV_INFO,  *LPNET_VCA_DEV_INFO; 

//VCA upload info
typedef struct  tagNET_VCA_RULE_ALARM
{
    DWORD    dwSize; 						//Structure length
    DWORD    dwRelativeTime; 				//relative time stamp
    DWORD    dwAbsTime; 					//Absolute time stamp
    NET_VCA_RULE_INFO     struRuleInfo; 	//Event rule info
    NET_VCA_TARGET_INFO  struTargetInfo; 	//Alarm target info
    NET_VCA_DEV_INFO  	 struDevInfo; 		//PU device info
    DWORD dwPicDataLen; 		//Return snapshot length, 0- no snapshot;  others- snapshot data size followed*/
    BYTE       byPicType;		//0- normal picture, 1- contrast picture
    BYTE       byRes[3];		//Reserved 
    DWORD       dwRes[3]; 		//Reserved 
    BYTE  *pImage;    						//Pointer to the snapshot picture
}NET_VCA_RULE_ALARM,  *LPNET_VCA_RULE_ALARM; 

//VCA info overlay via DSP
typedef struct tagNET_VCA_DRAW_MODE
{ 
    DWORD  dwSize; 
    BYTE	byDspAddTarget; 		//Overlay target info during encoding
    BYTE    byDspAddRule; 			//Overlay rule info during encoding
    BYTE	byDspPicAddTarget; 		//Overlay target info for snapshot
    BYTE	byDspPicAddRule; 		//Overlay rule info for snapshot
    BYTE	byRes[4]; 			
}NET_VCA_DRAW_MODE,  *LPNET_VCA_DRAW_MODE; 

//Sub structure for calibration point
typedef struct tagNET_DVR_CB_POINT
{
    NET_VCA_POINT struPoint;      //calibration point, main camera (fixed camera) 
    NET_DVR_PTZPOS struPtzPos;    //Input PTZ position of the speed dome
    BYTE	byRes[8]; 
}NET_DVR_CB_POINT,  LPNET_DVR_CB_POINT; 

//Calibration parameters
typedef struct tagNET_DVR_TRACK_CALIBRATION_PARAM
{	
    BYTE byPointNum; 			//Valid calibration
    BYTE byRes[3]; 				
    NET_DVR_CB_POINT  struCBPoint[MAX_CALIB_PT];  //Valid calibration group
}NET_DVR_TRACK_CALIBRATION_PARAM,  *LPNET_DVR_TRACK_CALIBRATION_PARAM; 

//Speed Dome configuration
typedef struct tagNET_DVR_TRACK_CFG 
{	
    DWORD dwSize; 			  	    //Structure size	
    BYTE byEnable; 				    //Enable/disable calibration
    BYTE byFollowChan;              //Corresponding channel calibrated
    BYTE byDomeCalibrate; 			//Set calibration for auto-tracking speed dome, 1-enable, 0-disable 
    BYTE byRes; 					//Reserved
    NET_DVR_TRACK_CALIBRATION_PARAM  struCalParam;  //Calibration group
}NET_DVR_TRACK_CFG,  *LPNET_DVR_TRACK_CFG ; 

//Tracking mode
typedef enum _TRACK_MODE_
{
    MANUAL_CTRL = 0,   //Manual tracking
    ALARM_TRACK,       //Alarm triggering tracking
    TARGET_TRACK       //Target tracking
}TRACK_MODE; 

//Manual control mode
typedef struct tagNET_DVR_MANUAL_CTRL_INFO 
{
    NET_VCA_POINT struCtrlPoint; 
    BYTE  byRes[8]; 
}NET_DVR_MANUAL_CTRL_INFO,  *LPNET_DVR_MANUAL_CTRL_INFO ; 

//Tracking mode
typedef struct tagNET_DVR_TRACK_MODE
{
    DWORD dwSize; 		   //Structure size
    BYTE byTrackMode;      //Tracking mode
    BYTE byRuleConfMode;   //Configuration of tracking mode: 0- local tracking mode config, 1- remote tracking mode config
    BYTE byRes[2];         //Reserved
    union
    {
        DWORD dwULen[4]; 
        NET_DVR_MANUAL_CTRL_INFO  struManualCtrl; //Manual tracking structure
    }uModeParam; 
}NET_DVR_TRACK_MODE, *LPNET_DVR_TRACK_MODE; 

typedef struct tagNET_DVR_ALARM_JPEG
{
    BYTE    byPicProType; 	        //Upload snapshot on alarm 0- disable;  1- upload
    BYTE    byRes[3];               //Reserved
    NET_DVR_JPEGPARA struPicParam;  //Snapshot structure
}NET_DVR_ALARM_JPEG,  *LPNET_DVR_ALARM_JPEG; 

//iVMS rule structure
//Alarm rule structure
typedef struct tagNET_IVMS_ONE_RULE_
{
    BYTE    byActive;            /* active the rule, 0- disable,  else- yes */
    BYTE	byRes1[7]; 	//Reserved as 0
    BYTE   byRuleName[NAME_LEN];  //Rule name
    VCA_EVENT_TYPE dwEventType;    //VCA event type
    NET_VCA_EVENT_UNION uEventParam; //VCA parameters
    NET_VCA_SIZE_FILTER  struSizeFilter;   //Size filter
    BYTE byRes2[68];  /*Reserved as 0*/
}NET_IVMS_ONE_RULE,  *LPNET_IVMS_ONE_RULE; 

// iVMS rule structure
typedef struct tagNET_IVMS_RULECFG
{
    NET_IVMS_ONE_RULE  struRule[MAX_RULE_NUM];    //rule array
}NET_IVMS_RULECFG,  *LPNET_IVMS_RULECFG; 

// IVMS VCA configuration structure
typedef struct tagNET_IVMS_BEHAVIORCFG
{
    DWORD dwSize; 
    BYTE    byPicProType; 	    //Upload snapshot on alarm: 0-disable;  else- upload
    BYTE    byRes[3]; 
    NET_DVR_JPEGPARA struPicParam;  				//snapshot structure
    NET_IVMS_RULECFG struRuleCfg[MAX_DAYS][MAX_TIMESEGMENT]; //corresponding rule on each time period
} NET_IVMS_BEHAVIORCFG,  *LPNET_IVMS_BEHAVIORCFG; 

//Sub structure of the iVMS sub stream query
typedef struct tagNET_IVMS_DEVSCHED
{
    NET_DVR_SCHEDTIME 	struTime;        //time structure
    NET_DVR_PU_STREAM_CFG struPUStream;  //PU streaming parameters
}NET_IVMS_DEVSCHED,  *LPNET_IVMS_DEVSCHED; 

//iVMS configuration structure
typedef struct tagNET_IVMS_STREAMCFG
{
    DWORD dwSize; 
    NET_IVMS_DEVSCHED	struDevSched[MAX_DAYS][MAX_TIMESEGMENT]; // Set PU streaming and rule by time period
} NET_IVMS_STREAMCFG,  *LPNET_IVMS_STREAMCFG; 

//Mask Area
typedef struct tagNET_VCA_MASK_REGION
{
    BYTE byEnable; 			//Activate privacy mask,  0- disable, else- enable
    BYTE byRes[3];          //Reserved as 0
    NET_VCA_POLYGON  struPolygon;  //Mask Polygon
}NET_VCA_MASK_REGION,  * LPNET_VCA_MASK_REGION; 

//Mask region list structure
typedef struct tagNET_VCA_MASK_REGION_LIST
{
    DWORD dwSize;      //Structure length
    BYTE byRes[4];      //Reserved as 0
    NET_VCA_MASK_REGION  struMask[MAX_MASK_REGION_NUM];  //Mask region list structure
}NET_VCA_MASK_REGION_LIST,  *LPNET_VCA_MASK_REGION_LIST; 


//ATM Enter Region
typedef struct tagNET_VCA_ENTER_REGION//Mask the target entering the region to avoid interference on ATM detection
{
    DWORD dwSize; 
    BYTE byEnable; 			//Activate the function, 0- disable, else- enable
    BYTE byRes1[3]; 
    NET_VCA_POLYGON  struPolygon;  //Enter area
    BYTE byRes2[16]; 
}NET_VCA_ENTER_REGION,  * LPNET_VCA_ENTER_REGION; 

//IVMS mask region list
typedef struct tagNET_IVMS_MASK_REGION_LIST
{
    DWORD dwSize;     //Structure length
    NET_VCA_MASK_REGION_LIST struList[MAX_DAYS][ MAX_TIMESEGMENT]; 
}NET_IVMS_MASK_REGION_LIST,  *LPNET_IVMS_MASK_REGION_LIST; 

//ATM enter area parameters of iVMS
typedef struct tagNET_IVMS_ENTER_REGION
{
    DWORD dwSize; 
    NET_VCA_ENTER_REGION  struEnter[MAX_DAYS][ MAX_TIMESEGMENT];  //Enter area
}NET_IVMS_ENTER_REGION,  *LPNET_IVMS_ENTER_REGION; 

// iVMS alarm upload structure
typedef struct tagNET_IVMS_ALARM_JPEG
{
    BYTE                byPicProType;                
    BYTE                byRes[3]; 
    NET_DVR_JPEGPARA      struPicParam;      
}NET_IVMS_ALARM_JPEG,  *LPNET_IVMS_ALARM_JPEG; 

// IVMS  Playback Search Config
typedef struct tagNET_IVMS_SEARCHCFG
{
    DWORD                        dwSize; 
    NET_DVR_MATRIX_DEC_REMOTE_PLAY struRemotePlay; // Remote playback
    NET_IVMS_ALARM_JPEG         struAlarmJpeg;  // alarm snapshot upload config
    NET_IVMS_RULECFG           struRuleCfg;    //IVMS VCA rule config
}NET_IVMS_SEARCHCFG,  *LPNET_IVMS_SEARCHCFG; 
/************************************end******************************************/

//Network Disk configuration
typedef struct tagNET_DVR_SINGLE_NET_DISK_INFO
{
    BYTE byNetDiskType; 						//0- NFS, 1- iSCSI
    BYTE byRes1[3]; 							//Reserved
    NET_DVR_IPADDR struNetDiskAddr; 			//IP address
    BYTE sDirectory[PATHNAME_LEN]; 			// PATHNAME_LEN = 128
    WORD wPort; 							    //iSCSI port
    BYTE byRes2[66]; 							//Reserved
}NET_DVR_SINGLE_NET_DISK_INFO,  *LPNET_DVR_SINGLE_NET_DISK_INFO; 

#define MAX_NET_DISK	16//Max. HDD number

typedef struct tagNET_DVR_NET_DISKCFG 
{
    DWORD  dwSize; 
    NET_DVR_SINGLE_NET_DISK_INFO struNetDiskParam[MAX_NET_DISK]; 
}NET_DVR_NET_DISKCFG,  *LPNET_DVR_NET_DISKCFG; 

//Event Type
//Main type
typedef enum _MAIN_EVENT_TYPE_
{
    EVENT_MOT_DET = 0, 			//Motion Detect
    EVENT_ALARM_IN = 1, 		//Alarm input
    EVENT_VCA_BEHAVIOR = 2, 	//VCA
	EVENT_INQUEST = 3,			//Inquest Event
	EVENT_STREAM_INFO = 100     //Stream ID information
}MAIN_EVENT_TYPE; 

#define INQUEST_START_INFO        0x1001
#define INQUEST_STOP_INFO         0x1002
#define INQUEST_TAG_INFO          0x1003
#define INQUEST_SEGMENT_INFO      0x1004

//VCA event type corresponding to the main event type, 0xffff stands for all
typedef enum _BEHAVIOR_MINOR_TYPE_
{
    EVENT_TRAVERSE_PLANE     = 0,   //Traverse plane
    EVENT_ENTER_AREA, 				//target enter area (region rule)
    EVENT_EXIT_AREA, 				//target leave area  (region rule)
    EVENT_INTRUSION, 				//Intrusion  (region rule)
    EVENT_LOITER, 				    //Loitering  (region rule)
    EVENT_LEFT_TAKE, 				//Object left or taken  (region rule)
    EVENT_PARKING, 					//Illegal parking  (region rule)
    EVENT_RUN, 					    //Running (region rule)
    EVENT_HIGH_DENSITY, 
    EVENT_STICK_UP,				    //Stick up, support area rule
    EVENT_INSTALL_SCANNER,			//Install scanner, support area rule
    EVENT_OPERATE_OVER_TIME,        //Operation overtime
    EVENT_FACE_DETECT,              //Exception face 
    EVENT_LEFT,                     //Items left
    EVENT_TAKE,                      //Items take
	EVENT_LEAVE_POSITION,         //Leave position
	EVENT_TRAIL_INFO = 16,            //Trial
	EVENT_FALL_DOWN_INFO = 19,                 //Fall down
	EVENT_OBJECT_PASTE	    =20,		//object paste
	EVENT_FACE_CAPTURE_INFO = 21,                //Face capture
	EVENT_MULTI_FACES_INFO = 22,                  //Multi faces
	EVENT_AUDIO_ABNORMAL_INFO = 23             //Audio abnormal
}BEHAVIOR_MINOR_TYPE; 

// Major type 100, minor type
typedef enum _STREAM_INFO_MINOR_TYPE_
{
	EVENT_STREAM_ID  = 0 
}STREAM_INFO_MINOR_TYPE;

// Brainare CVR
#define MAX_ID_COUNT    64
#define MAX_STREAM_ID_COUNT    1024
#define STREAM_ID_LEN   32

// Stream info
typedef struct tagNET_DVR_STREAM_INFO 
{
	DWORD dwSize;
	BYTE  byID[STREAM_ID_LEN];      //ID
	DWORD dwChannel;                //Relation channel, 0xffffffff: not related
	BYTE  byRes[32];                
}NET_DVR_STREAM_INFO, *LPNET_DVR_STREAM_INFO;

#define SEARCH_EVENT_INFO_LEN 300	//Event info length

//Event search condition
typedef struct tagNET_DVR_SEARCH_EVENT_PARAM
{
    WORD wMajorType; 			//0- Motion detect, 1- Alarm input,  2-  intelligent event
    WORD wMinorType; 			//Sub type- diverse according to the main type, 0xffff- all
    NET_DVR_TIME struStartTime; //Search start and end time, (0,  0) stands for searching from the earliest time and get maximum 4000 events 
    NET_DVR_TIME struEndTime; 	
    BYTE byRes[132]; 			//Reserved
    union	
    {
        BYTE byLen[SEARCH_EVENT_INFO_LEN]; 		  
        struct//Alarm input
        {
            BYTE byAlarmInNo[MAX_ALARMIN_V30];     //Alarm input, if the byAlarmInNo[0] is set as 1, then it stands for event triggered by alarm input 1 
            BYTE byRes[SEARCH_EVENT_INFO_LEN -  MAX_ALARMIN_V30]; 
        }struAlarmParam; 
        struct//motion detect
        {
            BYTE byMotDetChanNo[MAX_CHANNUM_V30]; //Motion detect channel, if byMotDetChanNo[0] is set as 1, then it stands for event triggered by channel 1 motion detect
            BYTE byRes[SEARCH_EVENT_INFO_LEN -  MAX_CHANNUM_V30]; 
        }struMotionParam; 
        struct//VCA
        {
            BYTE byChanNo[MAX_CHANNUM_V30]; //Channel than triggered the event
            BYTE byRuleID; 					//Rule ID, 0xff- all
            BYTE byRes1[43]; 				//Reserved
        }struVcaParam; 
		struct//Inquest
		{			
			BYTE byRoomIndex;    //Inquest room number
			BYTE byRes[299];     //Reserved
		} struInquestParam; 
		NET_DVR_STREAM_INFO   struIDInfo;
    }uSeniorParam; 
}NET_DVR_SEARCH_EVENT_PARAM,  *LPNET_DVR_SEARCH_EVENT_PARAM; 

//Search result returned
typedef struct tagNET_DVR_SEARCH_EVENT_RET
{
    WORD wMajorType; 			//Main type
    WORD wMinorType; 			//Sub type
    NET_DVR_TIME struStartTime; //Event starts time
    NET_DVR_TIME struEndTime;   //Event ends time, it will be equal to the start time for pulse event
    BYTE byChan[MAX_CHANNUM_V30]; 	
    BYTE byRes[36]; 
    union		
    {
        struct//alarm input result
        {
            DWORD dwAlarmInNo;      //alarm input number
            BYTE byRes[SEARCH_EVENT_INFO_LEN]; 
        }struAlarmRet; 
        struct//Motion detect result
        {
            DWORD dwMotDetNo; 	//Motion detect channel
            BYTE byRes[SEARCH_EVENT_INFO_LEN]; 
        }struMotionRet; 
        struct//VCA
        {
            DWORD dwChanNo; 					//Channel than VCA event is triggered
            BYTE byRuleID; 					//Rule ID
            BYTE byRes1[3]; 					//Reserved
            BYTE byRuleName[NAME_LEN]; 		//Rule ID
            NET_VCA_EVENT_UNION uEvent;      //VCA event parameters, wMinorType = VCA_EVENT_TYPE
        }struVcaRet; 
		struct//Inquest
		{
			BYTE  byRoomIndex;     //Inquest room number
            BYTE  byDriveIndex;    //Driver number
			BYTE  byRes1[6];       //Reserved
            DWORD dwSegmentNo;     //Segment number
			WORD  wSegmetSize;     //Segment size,M
            WORD  wSegmentState;   //Segment state: 0- Normal, 1- Exception, 2- CD not write when inquest
			BYTE  byRes2[288];     //Reserved
		}struInquestRet;
		struct // Stream id
		{
			DWORD dwRecordType;		//record type 
			DWORD dwRecordLength;	//record length
			BYTE  byLockFlag;    // lock flag 0：locked 1：not locked
			BYTE  byRes[295];
		}struStreamIDRet;
    }uSeniorRet; 
}NET_DVR_SEARCH_EVENT_RET,  *LPNET_DVR_SEARCH_EVENT_RET; 

//SDK_V35  2009- 10- 26


// Set face recognition parameter key word
typedef enum _FACE_PARAM_KEY_
{
    MAX_FACE_SIZE  = 20,    //Max. face size
    MINI_FACE_SIZE = 21	    //Min. Face size
}FACE_PARAM_KEY;            //Face recognition parameter 


// Calibration type 
typedef enum tagCALIBRATE_TYPE
{
    PDC_CALIBRATE           = 0x01,  //PDC calibration
    BEHAVIOR_OUT_CALIBRATE  = 0x02,  //VCA outdoor calibration  
    BEHAVIOR_IN_CALIBRATE   = 0x03,  //VCA indoor calibration
    ITS_CALBIRETE           = 0x04   //Traffic event calibration
        
}CALIBRATE_TYPE; 

#define MAX_RECT_NUM  6
typedef struct tagNET_DVR_RECT_LIST
{	
    BYTE    byRectNum;     // Rectangle number
    BYTE    byRes1[11];   //Reserved
    NET_VCA_RECT struVcaRect[MAX_RECT_NUM];  // Maximum 6 rectangles 
}NET_DVR_RECT_LIST,  *LPNET_DVR_RECT_LIST; 

// PDC  Calibration
typedef struct tagNET_DVR_PDC_CALIBRATION
{
    NET_DVR_RECT_LIST struRectList;   //Calibrated rectangle list
    BYTE           byRes[120];        //Reserved 
}NET_DVR_PDC_CALIBRATION,  *LPNET_DVR_PDC_CALIBRATION; 


//Calibration line mode
typedef enum tagLINE_MODE
{
    HEIGHT_LINE,           //Height calibration
        LENGTH_LINE        //Length calibration
}LINE_MODE; 
/*
For calibration setting, if the user also set 'enable' status, then they can set corresponding parameters,  
otherwise the users can get relative parameters after calibration setting
*/
typedef struct tagNET_DVR_CAMERA_PARAM
{
    BYTE    byEnableHeight;    //Enable camera height line setting
    BYTE    byEnableAngle;     //Enable camera view angle setting
    BYTE    byEnableHorizon;   //Enable camera horizon setting
    BYTE    byRes[5];          //Reserved 
    float   fCameraHeight;     //Enable Camera height setting
    float   fCameraAngle;      //Enable Camera install angle setting
    float   fHorizon;          //enable setting of  video scene's horizon
}NET_DVR_CAMERA_PARAM,  *LPNET_DVR_CAMERA_PARAM; 
/*
 If the fValue stands for the target height, then struStartPoint and struEndPoint stands for the target upped point and bottom point
If the fValue stands for the length of the line, then struStartPoint and struEndPoint stands for the start point and end point of the line 
mode stands for the line type (height or length)
*/
typedef struct tagNET_DVR_LINE_SEGMENT
{
    BYTE            byLineMode;      //plz refer to LINE_MODE
    BYTE            byRes[3];        //Reserved 
    NET_VCA_POINT   struStartPoint;   
    NET_VCA_POINT   struEndPoint; 
    float           fValue; 
}NET_DVR_LINE_SEGMENT,  *LPNET_DVR_LINE_SEGMENT; 

#define  MAX_LINE_SEG_NUM 8

/*
Needs 4-8 calibration lines to get camera parameters
*/
typedef struct tagNET_DVR_BEHAVIOR_OUT_CALIBRATION
{
    DWORD                   dwLineSegNum;                          // Calibration line number
    NET_DVR_LINE_SEGMENT    struLineSegment[MAX_LINE_SEG_NUM];     // Max. calibration line number
    NET_DVR_CAMERA_PARAM    struCameraParam;                       // Camera parameters
    BYTE byRes[20]; 
}NET_DVR_BEHAVIOR_OUT_CALIBRATION,  *LPNET_DVR_BEHAVIOR_OUT_CALIBRATION; 

/*
Calibration sample
--including 1 target brim rectangle (standing target) and 1 corresponding height calibration line (from head to bottom)
*/
typedef struct tagNET_DVR_IN_CAL_SAMPLE
{
    NET_VCA_RECT struVcaRect;    // target brim rectangle
    NET_DVR_LINE_SEGMENT struLineSegment;     // Height calibration line
}NET_DVR_IN_CAL_SAMPLE,  *LPNET_DVR_IN_CAL_SAMPLE; 

#define  MAX_SAMPLE_NUM 5
typedef struct tagNET_DVR_BEHAVIOR_IN_CALIBRATION 
{
    DWORD    dwCalSampleNum;       //  Calibration sample number
    NET_DVR_IN_CAL_SAMPLE  struCalSample[MAX_SAMPLE_NUM];  // Max. calibration sample number
    NET_DVR_CAMERA_PARAM    struCameraParam;     // Camera parameters
    BYTE byRes[20]; 
}NET_DVR_BEHAVIOR_IN_CALIBRATION,  *LPNET_DVR_BEHAVIOR_IN_CALIBRATION; 

#define  CALIB_PT_NUM 4
typedef struct tagNET_DVR_ITS_CALIBRATION
{
    DWORD dwPointNum;  //Calibration number
    NET_VCA_POINT struPoint[CALIB_PT_NUM];  //Image coordinates
    float       fWidth; 
    float       fHeight; 
    BYTE        byRes1[100];         // Reserved
}NET_DVR_ITS_CALIBRATION,  *LPNET_DVR_ITS_CALIBRATION; 


// Calibration union
typedef union tagNET_DVR_CALIBRATION_PRARM_UNION
{
    BYTE byRes[240];                     //Union size
    NET_DVR_PDC_CALIBRATION struPDCCalibration;   //PDC calibration parameters
    NET_DVR_BEHAVIOR_OUT_CALIBRATION  struBehaviorOutCalibration;   //  Outdoor calibration for VCA (mainly for IVS)
    NET_DVR_BEHAVIOR_IN_CALIBRATION  struBehaviorInCalibration;      // Indoor calibration for VCA (mainly for IAS)
    NET_DVR_ITS_CALIBRATION struITSCalibration; 
}NET_DVR_CALIBRATION_PRARM_UNION,  *LPNET_DVR_CALIBRATION_PRARM_UNION; 


// Calibration configuration
typedef struct tagNET_DVR_CALIBRATION_CFG
{
    DWORD   dwSize;                // Calibration structure size
    BYTE    byEnable;              // Enable/disable calibration
    BYTE    byCalibrationType;     // Calibration type, please refer to CALIBRATE_TYPE
    BYTE    byRes1[2]; 
    NET_DVR_CALIBRATION_PRARM_UNION uCalibrateParam;   // Calibration type union
    BYTE    byRes2[12]; 
}NET_DVR_CALIBRATION_CFG,  *LPNET_DVR_CALIBRATION_CFG;  

//PDC direction structure
typedef struct  tagNET_DVR_PDC_ENTER_DIRECTION
{
    NET_VCA_POINT struStartPoint;   // Start point of the direction
    NET_VCA_POINT struEndPoint;     // End point of the direction 
}NET_DVR_PDC_ENTER_DIRECTION,  *LPNET_DVR_PDC_ENTER_DIRECTION; 

typedef struct tagNET_DVR_PDC_RULE_CFG
{
    DWORD           dwSize;               //Structure size
    BYTE            byEnable;             //Enable/disable the function; 
    BYTE            byRes1[23];           //Reserved 
    NET_VCA_POLYGON          struPolygon;              //Polygon
    NET_DVR_PDC_ENTER_DIRECTION  struEnterDirection;   //Enter direction
} NET_DVR_PDC_RULE_CFG,  *LPNET_DVR_PDC_RULE_CFG; 

//Set PDC statistic parameters 
// HUMAN_GENERATE_RATE
// Speed for target generating. This parameter controls the time interval from target appear in the image to analysis starts. For video scene with various interference signals, please set a lower speed to avoid false alarm;  and for video scene with high speed objects, please set a higher speed to avoid event missing. Totally 5 levels, ranges from 1 (lowest speed)~ 5 (highest speed), and the default value is 3
// 
// DETECT_SENSITIVE
//Object detection sensitivity level , ranges from 1(lowest) to 5 (highest) , default level: 3

typedef enum tagPDC_PARAM_KEY
{
    HUMAN_GENERATE_RATE = 50,                //Target  generating speed, start from 50
    DETECT_SENSITIVE    = 51,                //Detecting sensitivity
}PDC_PARAM_KEY; 


typedef struct tagNET_DVR_PDC_TARGET_INFO
{
    DWORD       dwTargetID;                  //Target ID
    NET_VCA_RECT struTargetRect;             //Target brim
    BYTE      byRes1[8];                     //Reserved
}NET_DVR_PDC_TARGET_INFO,  *LPNET_DVR_PDC_TARGET_INFO; 

typedef struct tagNET_DVR_PDC_TARGET_IN_FRAME
{
    BYTE           byTargetNum;                    //Target number
    BYTE            byRes1[3]; 
    NET_DVR_PDC_TARGET_INFO  struTargetInfo[MAX_TARGET_NUM];    //Target info array
    BYTE    byRes2[8];                   // Reserved
}NET_DVR_PDC_TARGET_IN_FRAME,  *LPNET_DVR_PDC_TARGET_IN_FRAME; 

typedef struct tagNET_DVR_PDC_ALRAM_INFO
{
    DWORD                       dwSize;             // PDC alarm upload structure size
    BYTE                        byMode;             // 0 - single frame statistic result;  1- statistic result in min. time period  
    BYTE                        byChannel;          // Alarm upload channel
    BYTE                        byRes1[2];          // Reserved   
    NET_VCA_DEV_INFO  	 struDevInfo; 		        // PU device info
    union		
    {
        struct   // For single frame statistic result
        {
            DWORD   dwRelativeTime;      // Relative time stamp
            DWORD   dwAbsTime;           // Absolute time stamp
            BYTE    byRes[92];             
        }struStatFrame; 
        struct
        {
            NET_DVR_TIME                      tmStart; // Statistic start time 
            NET_DVR_TIME                      tmEnd;   //  Statistic end time
            BYTE byRes[92]; 
        }struStatTime; 
    }uStatModeParam;   
    DWORD                       dwLeaveNum;         // Number of left
    DWORD                       dwEnterNum;         // Number of entered
    BYTE                        byRes2[40];         // Reserved
}NET_DVR_PDC_ALRAM_INFO,  *LPNET_DVR_PDC_ALRAM_INFO; 


//  PDC Info Query
typedef struct tagNET_DVR_PDC_QUERY
{
    NET_DVR_TIME tmStart; 
    NET_DVR_TIME tmEnd; 
    DWORD        dwLeaveNum; 
    DWORD        dwEnterNum;  
    BYTE         byRes1[256]; 
}NET_DVR_PDC_QUERY,  *LPNET_DVR_PDC_QUERY; 

typedef struct    tagNET_DVR_PTZ_POSITION
{
    // Enable/disable the video scene functions (for speed dome local video scene position configuration) , invalid for video scene rule configuration mode,
    BYTE byEnable; 
    BYTE byRes1[3];   //Reserved
    BYTE byPtzPositionName[NAME_LEN];  //Video scene position name
    NET_DVR_PTZPOS struPtzPos;  //PTZ  coordinates
    BYTE byRes2[40]; 
}NET_DVR_PTZ_POSITION,  *LPNET_DVR_PTZ_POSITION; 

typedef struct tagNET_DVR_POSITION_RULE_CFG
{
    DWORD                   dwSize;              // Structure size
    NET_DVR_PTZ_POSITION    struPtzPosition;     // Video scene position info
    NET_VCA_RULECFG         struVcaRuleCfg;      //Video 
    BYTE                    byRes2[80];          // Reserved
}NET_DVR_POSITION_RULE_CFG,  *LPNET_DVR_POSITION_RULE_CFG; 

typedef struct tagNET_DVR_POSITION_RULE_CFG_V41
{
    DWORD                   dwSize;             // Structure size 
    NET_DVR_PTZ_POSITION    struPtzPosition;    // Video scene position info
	NET_VCA_RULECFG_V41         struVcaRuleCfg;     //Video
	BYTE  byTrackEnable; //Enable track
	BYTE  byRes1;
	WORD wTrackDuration; //Track duration(s)
    BYTE                    byRes2[76];         // 
}NET_DVR_POSITION_RULE_CFG_V41, *LPNET_DVR_POSITION_RULE_CFG_V41;

typedef struct tagNET_DVR_LIMIT_ANGLE
{
    BYTE                byEnable; 	 // Enable video scene position limitation
    BYTE				byRes1[3]; 
    NET_DVR_PTZPOS      struUp;      // upper limit position
    NET_DVR_PTZPOS      struDown;    // bottom limit position 
    NET_DVR_PTZPOS      struLeft;    // left limit position
    NET_DVR_PTZPOS      struRight;   // right limit position
    BYTE                byRes2[20]; 
}NET_DVR_LIMIT_ANGLE,  *LPNET_DVR_LIMIT_ANGLE; 

typedef struct tagNET_DVR_POSITION_INDEX
{
    BYTE    byIndex;    //video scene index
    BYTE    byRes1;
    WORD	wDwell; 	// dwell time
    BYTE    byRes2[4];  // Reserved
}NET_DVR_POSITION_INDEX,  *LPNET_DVR_POSITION_INDEX; 

#define  MAX_POSITION_NUM 10
typedef struct tagNET_DVR_POSITION_TRACK_CFG
{
    DWORD   dwSize; 
    BYTE    byNum;  // video scene number
    BYTE    byRes1[3]; 
    NET_DVR_POSITION_INDEX   struPositionIndex[MAX_POSITION_NUM]; 
    BYTE    byRes2[8]; 
}NET_DVR_POSITION_TRACK_CFG,  *LPNET_DVR_POSITION_TRACK_CFG; 

//Patrol path scene info
typedef struct tagNET_DVR_PATROL_SCENE_INFO
{
    WORD   wDwell;          // Dwell time [30- 300]
    BYTE   byPositionID;    // Scene number 1- 10, Default: 0 (do not add to patrol scene)
    BYTE   byRes[5]; 
}NET_DVR_PATROL_SCENE_INFO,  *LPNET_DVR_PATROL_SCENE_INFO; 

// Patrol scene tracking info
typedef struct tagNET_DVR_PATROL_TRACKCFG
{
    DWORD  dwSize;                                  // Structure size
    NET_DVR_PATROL_SCENE_INFO struPatrolSceneInfo[10];     // patrol path
    BYTE   byRes[16];                               // Reserved
}NET_DVR_PATROL_TRACKCFG,  *LPNET_DVR_PATROL_TRACKCFG; 

//Speed dome local rule configuration via menu
typedef struct tagNET_DVR_TRACK_PARAMCFG
{
    DWORD   dwSize;             // Structure size
    WORD    wAlarmDelayTime;    // Alarm delay time (speed dome only supports global intrusion detection mode) range:1-120s
    WORD    wTrackHoldTime;     // Alarm tracking holding time range 0-300s
    BYTE    byTrackMode;        //  Plz refer to IPDOME_TRACK_MODE
    BYTE	byPreDirection; 	// Pre judge of tracking direction 0-disable 1-enable
    BYTE 	byTrackSmooth; 	    //Smooth tracking 0-disable 1-enable    
    BYTE	byZoomAdjust; 	    // Zoom adjustment
    BYTE	byMaxTrackZoom; 	// Max. zoom ratio 0-default zoom ratio,1-15
    BYTE    byRes[11];          //  Reserved                
}NET_DVR_TRACK_PARAMCFG,  *LPNET_DVR_TRACK_PARAMCFG; 

typedef struct tagNET_DVR_DOME_MOVEMENT_PARAM
{
    WORD wMaxZoom;    // Max. zoom ratio
    BYTE    byRes[42];   // Reserved
}NET_DVR_DOME_MOVEMENT_PARAM,  *LPNET_DVR_DOME_MOVEMENT_PARAM;


/********************************Intelligent traffic event  begin****************************************/
#define  MAX_REGION_NUM			8       // Max. region list number
#define  MAX_TPS_RULE			8       // Max. rule number
#define  MAX_AID_RULE			8       // Max. event rule number
#define  MAX_LANE_NUM			8		// Max. traffic lane number

//Traffic event type
typedef enum tagTRAFFIC_AID_TYPE
{
    CONGESTION          = 0x01,     //Traffic jam
    PARKING             = 0x02,     //Parking
    INVERSE             = 0x04,     //Inverse travel
    PEDESTRIAN          = 0x08,     //Pedestrian                      
    DEBRIS              = 0x10,     //Debris 
    SMOKE               = 0x20      //smoke
}TRAFFIC_AID_TYPE; 

typedef enum tagTRAFFIC_SCENE_MODE
{
    FREEWAY = 0,	//  High-speed outdoor scene
	TUNNEL,         //  High-speed tunnel scene 
	BRIDGE          //  High-speed bridge scene
}TRAFFIC_SCENE_MODE; 

typedef enum tagITS_ABILITY_TYPE
{
    ITS_CONGESTION_ABILITY             = 0x01,       //Traffic jam
    ITS_PARKING_ABILITY                = 0x02,       //Parking 
    ITS_INVERSE_ABILITY                = 0x04,       //Inverse travel
    ITS_PEDESTRIAN_ABILITY             = 0x08,       //Pedestrian                      
    ITS_DEBRIS_ABILITY                 = 0x10,       //Debris
    ITS_SMOKE_ABILITY                  = 0x20,       //Smoke - tunnel

    ITS_LANE_VOLUME_ABILITY            = 0x010000,   //Flow  counting of traffic lane
    ITS_LANE_VELOCITY_ABILITY          = 0x020000,   //Vehicle velocity of traffic lane
    ITS_TIME_HEADWAY_ABILITY           = 0x040000,   //Vehicle headway counting (unit: time)
    ITS_SPACE_HEADWAY_ABILITY          = 0x080000,   //Vehicle headway counting (unit: distance) 
    ITS_TIME_OCCUPANCY_RATIO_ABILITY   = 0x100000,   //Traffic lane occupancy (unit: time)
    ITS_SPACE_OCCUPANCY_RATIO_ABILITY  = 0x200000,   //Traffic lane occupancy (unit: distance) 
    ITS_LANE_QUEUE_ABILITY             = 0x400000    //Queue length
}ITS_ABILITY_TYPE;

// Traffic statistics
typedef enum tagITS_TPS_TYPE
{
    LANE_VOLUME           = 0x01,     //Traffic lane flow
    LANE_VELOCITY         = 0x02,     //Vehicle velocity
    TIME_HEADWAY          = 0x04,     //Vehicle headway counting (unit: time)
    SPACE_HEADWAY         = 0x08,     //Vehicle headway counting (unit: distance) 
    TIME_OCCUPANCY_RATIO  = 0x10,     //Traffic lane occupancy (unit: time)
    SPACE_OCCUPANCY_RATIO = 0x20,     //Traffic lane occupancy (unit: distance)  
    QUEUE                 = 0x40      //Queue length
}ITS_TPS_TYPE;  

typedef struct tagNET_DVR_REGION_LIST 
{
    DWORD	dwSize; 	// Structure size
    BYTE    byNum;       // Region number
    BYTE    byRes1[3];     // Reserved
    NET_VCA_POLYGON struPolygon[MAX_REGION_NUM];  // Region
    BYTE	byRes2[20]; 	// Reserved
}NET_DVR_REGION_LIST, *LPNET_DVR_REGION_LIST; 


// Direction structure
typedef struct tagNET_DVR_DIRECTION
{
    NET_VCA_POINT struStartPoint;    // Direction start point
    NET_VCA_POINT struEndPoint;      // Direction end point
}NET_DVR_DIRECTION,  *LPNET_DVR_DIRECTION; 

// Single traffic lane
typedef struct tagNET_DVR_ONE_LANE
{
    BYTE	byEnable;  // Enable traffic lane
    BYTE	byRes1[11]; 	// Reserved
    BYTE    byLaneName[NAME_LEN];        // Traffic lane name
    NET_DVR_DIRECTION struFlowDirection; 	// Flow direction of the traffic lane
    NET_VCA_POLYGON struPolygon; 		// Traffic lane region
}NET_DVR_ONE_LANE,  *LPNET_DVR_ONE_LANE; 

// Traffic lane configuration
typedef struct tagNET_DVR_LANE_CFG
{
    DWORD	dwSize; 	// Structure size
    NET_DVR_ONE_LANE struLane[MAX_LANE_NUM]; 	// Traffic lane parameter, and the  subscript is corresponding to the traffic lane ID 
    BYTE	byRes1[40]; 	 // Reserved
}NET_DVR_LANE_CFG,  *LPNET_DVR_LANE_CFG; 

// Traffic event parameters
typedef struct tagNET_DVR_AID_PARAM
{
    WORD    wParkingDuration;        // Parking time [10s- 120s]
    WORD    wPedestrianDuration;     // Pedestrian time [1s- 120s]
    WORD    wDebrisDuration;         // Debris time [10s- 120s]
    WORD    wCongestionLength;       // Traffic jam distance threshold [5m- 200m] 
    WORD    wCongestionDuration;     // Traffic jam time length [10s- 120s]
    WORD    wInverseDuration;        // Inverse travel time [1s- 10s]
    WORD    wInverseDistance;        // Inverse travel distance [2m- 100m] (default: 10m)
    WORD    wInverseAngleTolerance;  // Inverse angle tolerance [90- 180] degree
    BYTE    byRes1[28];              //  Reserved
}NET_DVR_AID_PARAM,  *LPNET_DVR_AID_PARAM; 

// Traffic rule structure
typedef struct tagNET_DVR_ONE_AID_RULE
{   
    BYTE    byEnable;    // enable/disable event rules
    BYTE    byRes1[3];   // Reserved
    BYTE    byRuleName[NAME_LEN];    // rule name 
    DWORD   dwEventType;     // traffic event detection type TRAFFIC_AID_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter;  // Size filter
    NET_VCA_POLYGON     struPolygon;     // Rule region
    NET_DVR_AID_PARAM struAIDParam;  //  Event parameters
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2]; //Arm time
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType; 	  // Handle method
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; 			//Recording channel triggered by alarm, 1-trigger recording on this channel
    BYTE    byRes2[20]; 
}NET_DVR_ONE_AID_RULE,  *LPNET_DVR_ONE_AID_RULE; 

// Traffic events
typedef struct tagNET_DVR_AID_RULECFG
{
    DWORD   dwSize;      // Structure size 
    BYTE    byPicProType; 	//0- do not upload snapshot on alarm;  else-  upload snapshot on alarm
    BYTE    byRes1[3];   // Reserved
    NET_DVR_JPEGPARA struPictureParam;  		//Snapshot parameter structure
    NET_DVR_ONE_AID_RULE  struOneAIDRule[MAX_AID_RULE]; 
    BYTE    byRes2[32]; 
}NET_DVR_AID_RULECFG,  *LPNET_DVR_AID_RULECFG; 

// Traffic statistics structure
typedef struct tagNET_DVR_ONE_TPS_RULE
{
    BYTE    byEnable;        // Enable traffic rule parameters
    BYTE	byLaneID; 		// Traffic lane ID
    BYTE    byRes1[2];
    DWORD   dwCalcType;      // Statistics type ITS_TPS_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter;  // Size filter
    NET_VCA_POLYGON struVitrualLoop;     // Virtual coil
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2]; //Arm schedule
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType; 	//Handle mode (upload to center)
    BYTE    byRes2[20];   // Reserved
}NET_DVR_ONE_TPS_RULE,  *LPNET_DVR_ONE_TPS_RULE; 

// Traffic statistics rule configuration structure
typedef struct tagNET_DVR_TPS_RULECFG
{
    DWORD   dwSize;               // Structure size
    NET_DVR_ONE_TPS_RULE struOneTpsRule[MAX_TPS_RULE];  // The subscript is corresponding to the traffic parameter's ID
    BYTE    byRes2[40];      // Reserved
}NET_DVR_TPS_RULECFG,  *LPNET_DVR_TPS_RULECFG; 

// Traffic event info
typedef struct tagNET_DVR_AID_INFO
{
    BYTE            byRuleID;    // Rule ID, which is equal to the subscript of the rule configuration structure ([0- 16])
    BYTE            byRes1[3]; 
    BYTE            byRuleName[NAME_LEN];  //  Rule ID
    DWORD           dwAIDType;   // Alarm event type
    NET_DVR_DIRECTION   struDirect;  // ALarm region   
    BYTE            byRes2[40];   // Reserved 
}NET_DVR_AID_INFO,  *LPNET_DVR_AID_INFO; 

// Traffic event alarm
typedef struct tagNET_DVR_AID_ALARM
{
    DWORD               dwSize;          // Structure length
    DWORD               dwRelativeTime; 	// Relative time stamp
    DWORD               dwAbsTime; 		// Absolute time stamp
    NET_VCA_DEV_INFO  	struDevInfo; 	// PU info
    NET_DVR_AID_INFO    struAIDInfo;     // Traffic event info
    DWORD               dwPicDataLen;    // Return snapshot picture length, 0- no snapshot;  else- snapshot data length
    BYTE                *pImage;         // pointer to the snapshot picture data
    BYTE                byRes[40];       // Reserved  
}NET_DVR_AID_ALARM,  *LPNET_DVR_AID_ALARM; 

// Queue structure of the Traffic Line
typedef struct tagNET_DVR_LANE_QUEUE
{
    NET_VCA_POINT   struHead;        //Head of the queue
    NET_VCA_POINT   struTail;        //End of the queue
    float           fLength;      //Actual queue length
}NET_DVR_LANE_QUEUE,  *LPNET_DVR_LANE_QUEUE;  


typedef struct tagNET_DVR_LANE_PARAM
{
    BYTE    byRuleName[NAME_LEN];                  //Traffic lane rule name
    BYTE    byRuleID;                // Rule ID, which is equal to the subscript of the rule configuration structure ([0- 7]) 
    BYTE    byVaryType;       //Vehicle status for virtual coil, 1-vehicle passing, 0-no vehicle passing 
    BYTE	byLaneType; 			// Traffic lane type
    BYTE	byRes1; 
    DWORD    dwLaneVolume; 	// Traffic flow
    DWORD   dwLaneVelocity;       //velocity on this traffic lane (km/h)
    DWORD   dwTimeHeadway ;       //Vehicle headway counting (unit: time)
    DWORD   dwSpaceHeadway;        //Vehicle headway counting (unit: m)
    float   fSpaceOccupyRation;  //Occupation 
    NET_DVR_LANE_QUEUE  struLaneQueue;          //Queue length of the traffic lane
    NET_VCA_POINT       struRuleLocation;      //Center position of the coil rule
    BYTE    byRes2[32]; 
}NET_DVR_LANE_PARAM,  *LPNET_DVR_LANE_PARAM; 


typedef struct tagNET_DVR_TPS_INFO
{
    DWORD   dwLanNum;    // Traffic lane number for the rule
    NET_DVR_LANE_PARAM  struLaneParam[MAX_TPS_RULE]; 
}NET_DVR_TPS_INFO,  *LPNET_DVR_TPS_INFO; 

typedef struct tagNET_DVR_TPS_ALARM
{
    DWORD dwSize;    // Structure size
    DWORD       dwRelativeTime; 				// relative time stamp
    DWORD       dwAbsTime; 						// Absolute time stamp
    NET_VCA_DEV_INFO  	struDevInfo; 		// PU device info
    NET_DVR_TPS_INFO  struTPSInfo;      // Traffic event info
    BYTE        byRes1[32];          // Reserved
}NET_DVR_TPS_ALARM,  *LPNET_DVR_TPS_ALARM; 

// Face rule configuration 
typedef struct tagNET_DVR_FACEDETECT_RULECFG
{
    DWORD          dwSize;              //Structure size
    BYTE           byEnable;            //Enable or not
    BYTE           byEventType;			//Event type: 0- abnormal face, 1- normal face, 2- abnormal face and normal face
	BYTE           byUpLastAlarm;       //2011-04-06 Whether upload last alarm firstly
	BYTE           byUpFacePic; //Enable upload face picture,0-no, 1-yes
    BYTE           byRuleName[NAME_LEN];
    NET_VCA_POLYGON     struVcaPolygon; //Face detection rule region
    BYTE           byPicProType;	    //Picture handling mode when alarming: 0- not handle, none 0- upload
    BYTE           bySensitivity;       //Rule sensitivity
    WORD            wDuration;          //Time threshold to trigger face alarm
    NET_DVR_JPEGPARA    struPictureParam; 		//Picture parameter
    NET_VCA_SIZE_FILTER struSizeFilter;         //Size filter
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//Time parameter of fortification 
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //Handling mode 
    BYTE           byRelRecordChan[MAX_CHANNUM_V30];//Whether alarm triggers recording channel:1-trigger;0-not trigger 
	BYTE          byPicRecordEnable;  /*2012-3-1 Whether record picture, 0-no, 1-yes*/
    BYTE            byRes2[39];         //Reserved
}NET_DVR_FACEDETECT_RULECFG, *LPNET_DVR_FACEDETECT_RULECFG;

typedef struct tagNET_DVR_FACEDETECT_ALARM
{
    DWORD  dwSize;     		    // Structure size
    DWORD 	dwRelativeTime;     // Relative time
    DWORD	dwAbsTime;			// Absolute time
    BYTE        byRuleName[NAME_LEN];       //Rule name
    NET_VCA_TARGET_INFO  struTargetInfo;	//Alarm target information
    NET_VCA_DEV_INFO  	 struDevInfo;		//Device information
    DWORD dwPicDataLen;						//Returned picture length, 0 means no picture, larger than 0 means picture data follows the structure
    BYTE		byAlarmPicType;			    //0- abnormal face alarm picture, 1- face picture,2-multi faces 
	BYTE     byPanelChan;        /*2012-3-1 Related panel channel*/
    BYTE byRes1[2];
	DWORD dwFacePicDataLen;			//Face picture length
    BYTE   byRes[48];              
    BYTE  *pFaceImage; //Pointer to face picture
    BYTE  *pImage;   						//Pointer to picture
}NET_DVR_FACEDETECT_ALARM, *LPNET_DVR_FACEDETECT_ALARM;

typedef struct tagNET_DVR_EVENT_PARAM_UNION
{
    DWORD  uLen[3];        //Union size, 12 bytes
    DWORD  dwHumanIn;  	   //There are nobody or someone access, 0 -nobody, 1- someone  
    float  fCrowdDensity;  //Aggregation value of people
}NET_DVR_EVENT_PARAM_UNION, *LPNET_DVR_EVENT_PARAM_UNION;

//Real-time alarm upload of someone and onbody event or people aggregation event
typedef struct tagNET_DVR_EVENT_INFO
{
    BYTE   byRuleID;				// Rule ID
    BYTE   byRes[3];				// Reserved
    BYTE   byRuleName[NAME_LEN];	// Rule name
    DWORD       dwEventType;    	// See to VCA_EVENT_TYPE
    NET_DVR_EVENT_PARAM_UNION uEventParam;  
}NET_DVR_EVENT_INFO, *LPNET_DVR_EVENT_INFO;

typedef struct tagNET_DVR_EVENT_INFO_LIST
{
    BYTE			byNum;		// Total number of event real-time information
    BYTE			byRes1[3];			// Reserved
    NET_DVR_EVENT_INFO struEventInfo[MAX_RULE_NUM];	// Event real-time information
}NET_DVR_EVENT_INFO_LIST,*LPNET_DVR_EVENT_INFO_LIST;

typedef struct tagNET_DVR_RULE_INFO_ALARM
{
    DWORD 			dwSize;				// Structure size
    DWORD 		dwRelativeTime; 	    // Relative time
    DWORD		dwAbsTime;		        // Absolute time
    NET_VCA_DEV_INFO  	struDevInfo;    // Front-end device information
    NET_DVR_EVENT_INFO_LIST struEventInfoList;	//Event information list
    BYTE			byRes2[40];			// Reserved
}NET_DVR_RULE_INFO_ALARM, *LPNET_DVR_RULE_INFO_ALARM;

/*******************************Intelligent Traffic Function end*****************************************/

#define PRIVT_XXX_MAJOR_VERSION      2

#define PRIVT_XXX_SUB_VERSION        3 /* Sub version value, up to 31 */

#define PRIVT_XXX_REVISION_VERSION   4

typedef struct tagNET_DVR_VCA_VERSION
{
    WORD    wMajorVersion; 		// Main version
    WORD    wMinorVersion; 		// Sub version
    WORD    wRevisionNumber; 	// Revision
    WORD    wBuildNumber; 		// Build
    WORD	wVersionYear; 		//Version date- Year
    BYTE	byVersionMonth; 		//Version date- Month
    BYTE	byVersionDay; 			//Version date- Day
    BYTE	byRes[8]; 			// Reserved
}NET_DVR_VCA_VERSION,  *LPNET_DVR_VCA_VERSION; 

/******************************Intelligent function end***********************************/

/*******************************Video Management system***********************************/
//09- 11- 21
#define MAX_SUBSYSTEM_NUM	80   //Max. sub system number in the matrix
#define MAX_SERIALLEN		36   //Max. SN Length
#define MAX_LOOPPLANNUM		16   //Max loop group number
#define DECODE_TIMESEGMENT  4    //Time segment number of decoding schedule
typedef struct tagNET_DVR_SUBSYSTEMINFO
{
    BYTE		bySubSystemType; //Sub system type, 1- decoding, 2- encoding, 0- NULL (Read-only) 
    BYTE		byChan; //Channel parameters for the sub system (Read-only) 
    BYTE		byLoginType; //Registration type, 1- direct connect, 2- DNS, 3- Peanut Hull
    BYTE		byRes1[5]; 
    NET_DVR_IPADDR   struSubSystemIP; 		/*IP Address */
    WORD		wSubSystemPort;         //Sub system port number 
    BYTE		byRes2[6]; 
    NET_DVR_IPADDR  struSubSystemIPMask; //Subnet mask
    NET_DVR_IPADDR	struGatewayIpAddr; 	/*Network Gateway*/   
    BYTE		sUserName[NAME_LEN]; 	/* User name  (Read-only) */
    BYTE		sPassword[PASSWD_LEN]; 	/*Password (Read-only) */
    char		sDomainName[MAX_DOMAIN_NAME]; // Domain name  
    char 		sDnsAddress[MAX_DOMAIN_NAME]; /*DNS domain name or IP*/
    BYTE		sSerialNumber[SERIALNO_LEN]; //SN (Read-only) 
}NET_DVR_SUBSYSTEMINFO,  *LPNET_DVR_SUBSYSTEMINFO; 

typedef struct tagNET_DVR_ALLSUBSYSTEMINFO
{
    DWORD dwSize; 
    NET_DVR_SUBSYSTEMINFO struSubSystemInfo[MAX_SUBSYSTEM_NUM]; 
    BYTE byRes[8]; 
}NET_DVR_ALLSUBSYSTEMINFO,  *LPNET_DVR_ALLSUBSYSTEMINFO; 

typedef struct tagNET_DVR_ALARMMODECFG
{
    DWORD 	dwSize; 
    BYTE	byAlarmMode; //Alarm trigger mode, 1- loop, 2- Remain		
    WORD	wLoopTime; //Loop cycle interval (unit: second)			
    BYTE    byRes[9]; 
}NET_DVR_ALARMMODECFG, *LPNET_DVR_ALARMMODECFG; 

typedef struct  tagNET_DVR_CODESPLITTERINFO
{
    DWORD			dwSize; 
    NET_DVR_IPADDR   struIP; 		/*IP of Code Distributor*/
    WORD		wPort;         			//Port number of Code Distributor
    BYTE		byRes1[6]; 
    BYTE		sUserName[NAME_LEN]; 	/* User name */
    BYTE		sPassword[PASSWD_LEN]; 	/*Password */
    BYTE        byChan; //485 port number of the Code Distributor
    BYTE		by485Port; //485 address of the Code Distributor
    BYTE		byRes2[14]; 
} NET_DVR_CODESPLITTERINFO,  *LPNET_DVR_CODESPLITTERINFO; 

typedef struct tagNET_DVR_ASSOCIATECFG
{
    BYTE	byAssociateType; //Alarm linkage, 1- alarm out
    WORD	wAlarmDelay; //Alarm out delay, 0- 5 seconds;  1- 10 seconds; 2- 30 seconds; 3- 1 minute; 4- 2 minutes; 5- 5 minutes; 6- 10 minutesw; 
    BYTE	byAlarmNum; //Alarm ID number
    BYTE	byRes[8]; 
} NET_DVR_ASSOCIATECFG, *LPNET_DVR_ASSOCIATECFG; 

typedef struct tagNET_DVR_DYNAMICDECODE
{
    DWORD						    dwSize; 
    NET_DVR_ASSOCIATECFG   		struAssociateCfg; //Trigger dynamic decoding associated structure
    NET_DVR_PU_STREAM_CFG		struPuStreamCfg; //Dynamic decoding structure
    BYTE							byRes[8]; 
}NET_DVR_DYNAMICDECODE, *LPNET_DVR_DYNAMICDECODE; 

typedef struct  tagNET_DVR_DECODESCHED
{
    NET_DVR_SCHEDTIME  struSchedTime; //
    BYTE  byDecodeType; /*0- no, 1- loop decoding, 2- dynamic decoding*/
    BYTE  byLoopGroup; //Loop Group
    BYTE  byRes[6]; 
    NET_DVR_PU_STREAM_CFG struDynamicDec; //Dynamic decoding
} NET_DVR_DECODESCHED,  *LPNET_DVR_DECODESCHED; 

typedef struct tagNET_DVR_PLANDECODE
{
    DWORD dwSize; 
    NET_DVR_DECODESCHED struDecodeSched[MAX_DAYS][DECODE_TIMESEGMENT]; //Start from Monday, consistent with 9000
    BYTE byRes[8]; 
} NET_DVR_PLANDECODE, *LPNET_DVR_PLANDECODE; 

typedef struct 
{
    NET_DVR_TIME strLogTime; 
    DWORD	dwMajorType; 	//Main type 1- alarm;  2- abnormal;  3- operation;  0xff- all 
    DWORD	dwMinorType; 	//Hypo- Type 0- all; 
    BYTE	sPanelUser[MAX_NAMELEN];  //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN]; //user ID for network operation
    NET_DVR_IPADDR	struRemoteHostAddr; //remote host IP
    DWORD	dwParaType; //parameter type
    DWORD	dwChannel; //channel number
    DWORD	dwDiskNumber; //HD number
    DWORD	dwAlarmInPort; //alarm input port
    DWORD	dwAlarmOutPort; //alarm output port
    DWORD   dwInfoLen; 
    BYTE  byDevSequence; //Slot number
    BYTE  byMacAddr[MACADDR_LEN]; //MAC address, 6
    BYTE  sSerialNumber[SERIALNO_LEN]; //Serial Number, 48
    char  sInfo[LOG_INFO_LEN -  SERIALNO_LEN -  MACADDR_LEN -  1 ]; 
}NET_DVR_LOG_MATRIX,  *LPNET_DVR_LOG_MATRIX; 

//2009- 11- 21 Video Management Platform
typedef struct tagVEDIOPLATLOG
{
    BYTE bySearchCondition; //Search condition, 0-  search by slot number, 1- Search by SN,  2- Search by MAC
	//Slot number, 0- 79: (corresponding to the slot number in the sub system); 
    //0xff: Search all the logs
    //0xfe: Search logs on 78k;0xfd:Search logs on sub domain;0xfc:Search logs on domain
    BYTE byDevSequence; 
    BYTE  sSerialNumber[SERIALNO_LEN]; //Serial Number, 48
    BYTE  byMacAddr[MACADDR_LEN]; //MAC, 6
} NET_DVR_VEDIOPLATLOG,  *LPNET_DVR_VEDIOPLATLOG; 

//2009- 11- 21
#define VIDEOPLATFORM_SBUCODESYSTEM_ABILITY          0x211 //Encoding sub system ability
typedef struct tagNET_DVR_CODESYSTEMABILITY
{
    DWORD dwSize; 
    DWORD dwAbilityVersion; //Ability version number, the highest 16 digits stands for the main version and the lowest 16 digits stands for the sub version 
    DWORD dwSupportMaxVideoFrameRate; //Unit (Kbps) 
                                     /*Recording mode by digit: 
                                     0: continuous recording according to time schedule; 
                                     1: continues| event trigger recording 
                                     2: Motion detect 
                                     3: Network alarm; 
                                     4: Motion| Network Alarm; 
                                     5: Motion & Network alarm; 
                                     6: Perimeter alarm; 
                                     7: Face recognition; 
                                     8: LPR; 
    			9: Manual recording*/
    DWORD dwSupportRecordType; 
    BYTE  bySupportLinkMode; //By digit: 0th-main stream; 1st: sub stream
	BYTE  bySupportStringRow;//Supported character string rows
    BYTE  byRes1[2];
    //Resolution:0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5-(Reserved),
    //16-VGA(640*480), 17-UXGA(1600*1200), 18-SVGA(800*600),
    //19-HD720p(1280*720),20-XVGA,  21-HD900p, 27-HD1080i, 
    //28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048	
    BYTE  byMainStreamSupportResolution[32]; //Supported resolution of main stream(added in v1.1 ability)
    BYTE  bySubStreamSupportResolution[32];  //Supported resolution of sub stream(added in v1.1 ability)
    BYTE  byEventStreamSupportResolution[32];//Supported resolution of event stream(added in v1.1 ability)
    BYTE  byRes2[28];//Reserved
}NET_DVR_CODESYSTEMABILITY,  *LPNET_DVR_CODESYSTEMABILITY; 

//2010- 03- 31 Add ability set of the video management system
typedef struct tagNET_DVR_SUBSYSTEM_ABILITY
{
    BYTE  bySubSystemType; //Sub system type, 1- Decoding, 2- Encoding, 0- NULL
    BYTE  byChanNum; //Channel number in the sub system
    BYTE  byStartChan; //Start channel of the sub system
    BYTE  byRes1[5]; 
    union
    {
        BYTE Res[200]; 
        struct
        {
            BYTE  byVGANums; // Display channel number of VGA( start from 1) 
            BYTE  byBNCNums; // Display channel number of BNC(start from 9) 
            BYTE  byHDMINums; // Display channel number of HDMI (start from 25) 
            BYTE  byDVINums; // Display channel number of DVI(start from 29) 
            BYTE  byRes[196]; 
        }struDecoderSystemAbility; 
        struct
        {
            BYTE  byRes[200]; 
        }struCoderSystemAbility; 
    }struAbility; 
}NET_DVR_SUBSYSTEM_ABILITY,  *LPNET_DVR_SUBSYSTEM_ABILITY; 

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY
{
    DWORD dwSize; 
    BYTE  byCodeSubSystemNums; //number of encoding sub system
    BYTE  byDecodeSubSystemNums; //number of decoding sub system
    BYTE  bySupportNat; //0- does not support NAT, 1- support NAT
    BYTE  byRes1[17]; 
    NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM]; 
    BYTE  byRes2[640]; 
}NET_DVR_VIDEOPLATFORM_ABILITY,  *LPNET_DVR_VIDEOPLATFORM_ABILITY; 

/********************************end*******************************************/

/******************************Intelligent Traffic Surveillance Camera*******************************************/
//IO input
typedef struct tagNET_DVR_IO_INCFG
{
    DWORD   dwSize; 
    BYTE    byIoInStatus; //Input IO status, 0- Falling edge, 1- Rising edge, 2- Falling edge and Rising edge, 3- HIGH, 4- LOW
    BYTE	byRes[3]; //Reserved
}NET_DVR_IO_INCFG,  *LPNET_DVR_IO_INCFG; 

//IO output
typedef struct tagNET_DVR_IO_OUTCFG
{
    DWORD   dwSize; 
    BYTE    byDefaultStatus; //Default IO status: 0- LOW, 1- HIGH 
    BYTE    byIoOutStatus; //IO valid status: 0- LOW, 1- HIGH, 2- PULSE
    WORD    wAheadTime; //Advance time of IO Output, Unit: us
    DWORD   dwTimePluse; //Pulse interval (unit: us)
    DWORD   dwTimeDelay; //IO delay time (unit: us)
	BYTE    byFreqMulti;		//frequence,[1,15]
	BYTE    byDutyRate;		//duty rate,[0,40%]
    BYTE    byRes2[2]; 
}NET_DVR_IO_OUTCFG,  *LPNET_DVR_IO_OUTCFG; 

//Flashlight
typedef struct tagNET_DVR_FLASH_OUTCFG
{
    DWORD  dwSize;
    BYTE   byMode;// 0- not flashing, 1- flashing, 2- alarm linkage, 3- loop mode
    BYTE   byRelatedIoIn;//Corresponding IO (for alarm linkage mode) 
    BYTE   byRecognizedLane;  /*Corresponding IO, expressed by bit, bit0 means whether IO1 is related: 0-not related, 1-related*/
	BYTE   byDetectBrightness;/*Detect brightness enable flashlight automatically:0-not detect;1-detect*/
	BYTE   byBrightnessThreld;/*Brightness threshold of enable flashlight:[0,100].Flashlight works when up to the threshold*/
    BYTE   byStartHour;		    //Start time--hour, value range: 0-23
	BYTE   byStartMinute;	    //Start time--minute, value range: 0-59
	BYTE   byEndHour;		    //End time--hour, value range: 0-23
	BYTE   byEndMinute;		    //End time--minute, value range: 0-59
	BYTE   byFlashLightEnable;	//Set flashlight time enable: 0 - off, 1 - open
	BYTE   byRes[2];
}NET_DVR_FLASH_OUTCFG, *LPNET_DVR_FLASH_OUTCFG;

//Traffic light 
typedef struct tagNET_DVR_LIGHTSNAPCFG
{
    DWORD   dwSize; 
    BYTE	byLightIoIn; //Traffic Light IO
    BYTE	byTrigIoIn; //Triggered IO
    BYTE	byRelatedDriveWay; //Corresponding traffic lane
    BYTE	byTrafficLight;  //0- HIGH status for red light and LOW for green light; 1- HIGH status for green light and LOW for red light
    BYTE 	bySnapTimes1;  //Red light snapshot time, 0- disable, else- snapshot time (up to 5)
    BYTE 	bySnapTimes2;  //Green light snapshot time, 0-disable, else- snapshot time (up to 5) 
    BYTE	byRes1[2]; 
    WORD	wIntervalTime1[4]; //Red light snapshot interval (unit: ms)
    WORD	wIntervalTime2[4]; //Green light snapshot interval (unit: ms)
    BYTE	byRecord; //Record when driving on red light, 0- disable, 1- enable
    BYTE	bySessionTimeout; //Time out session for red light recording (unit: s) 
    BYTE	byPreRecordTime; //Pre-Recording time for red light recording (unit: s)
    BYTE	byVideoDelay; //Post--Recording time for red light recording (unit: s) 
    BYTE	byRes2[32]; //Reserved
}NET_DVR_LIGHTSNAPCFG,  *LPNET_DVR_LIGHTSNAPCFG; 

//Speed Measurement
typedef struct tagNET_DVR_MEASURESPEEDCFG
{
    DWORD   dwSize; 
    BYTE	byTrigIo1;    //Testing coil 1
    BYTE	byTrigIo2;    //Testing coil 2
    BYTE	byRelatedDriveWay; //Corresponding traffic lane
    BYTE	byTestSpeedTimeOut; //Timeout for speed testing (unit: s) 
    DWORD   dwDistance; //Coil distance, cm
    BYTE	byCapSpeed; //Capture speed starts from (unit:km/h)
    BYTE	bySpeedLimit; //Speed limitation (km/h)
    BYTE 	bySnapTimes1;  //Snapshot time for coil 1, 0- disable, else- snapshot time (up to 5)
    BYTE 	bySnapTimes2;  //Snapshot time for coil 2, 0- disable, else- snapshot time (up to 5)
    WORD	wIntervalTime1[4]; //Snapshot interval for Coil 1 (unit: ms)
    WORD	wIntervalTime2[4]; //Snapshot interval for Coil 2 (unit: ms)
    BYTE	byRes[32]; //Reserved
}NET_DVR_MEASURESPEEDCFG,  *LPNET_DVR_MEASURESPEEDCFG; 

//Video parameter configuration
typedef struct tagNET_DVR_VIDEOEFFECT
{
    BYTE byBrightnessLevel;  /*0- 100*/
    BYTE byContrastLevel;  /*0- 100*/
    BYTE bySharpnessLevel;  /*0- 100*/
    BYTE bySaturationLevel;  /*0- 100*/
    BYTE byHueLevel;  /*0- 100,  (Reserved) */
    BYTE byEnableFunc; //enable,bit0-SMART IR,bit1-illumination,bit2-light inhibit,0-no,1-yes
	BYTE byLightInhibitLevel; //light inhibit level,[1-3]
	BYTE byGrayLevel; //gray level,0-[0-255],1-[16-235]
}NET_DVR_VIDEOEFFECT,  *LPNET_DVR_VIDEOEFFECT; 

//Gain Configuration
typedef struct tagNET_DVR_GAIN
{
    BYTE byGainLevel;  /*Gain: 0- 100*/
    BYTE byGainUserSet;  /*Customize Gain level adjustment ([0- 100]) for CCD mode*/
    BYTE byRes[2]; 
    DWORD byMaxGainValue; /*Max. Gain level (unit: dB)*/
}NET_DVR_GAIN,  *LPNET_DVR_GAIN; 

//White Balance
typedef struct tagNET_DVR_WHITEBALANCE
{
    BYTE byWhiteBalanceMode;  /*0-manual white balance;  1-ATW1(small range) ;  2- ATW2  (2200K- 15000K) ; 3- ATW3,4-outdoor,5-indoor,6-light,7-NA light*/
    BYTE byWhiteBalanceModeRGain;  /*R Gain for Manual White Balance mode*/
    BYTE byWhiteBalanceModeBGain;  /*B Gain for Manual White Balance mode*/
    BYTE byRes[5]; 
}NET_DVR_WHITEBALANCE,  *LPNET_DVR_WHITEBALANCE; 

//Exposure Control
typedef struct tagNET_DVR_EXPOSURE
{
    BYTE  byExposureMode;  /*0 - manual exposure 1- auto exposure*/
	BYTE  byAutoApertureLevel; /* Auto Aperture Level, 0-10 */ 
    BYTE  byRes[2]; 
    DWORD dwVideoExposureSet;  /* Exposure time for manual mode or Max. exposure time for auto mode(unit: us) */
    DWORD dwExposureUserSet;  /* Exposure time (Shutter speed for CCD mode)*/   
    DWORD dwRes;     
} NET_DVR_EXPOSURE,  *LPNET_DVR_EXPOSURE; 

//WDR configuration
typedef struct tagNET_DVR_WDR
{
    BYTE byWDREnabled;  /*WDR: 0 disable  1 enable 2 auto*/
    BYTE byWDRLevel1;  /*0- F*/
    BYTE byWDRLevel2;  /*0- F*/
    BYTE byWDRContrastLevel;  /*0- 100*/
    BYTE byRes[16]; 
} NET_DVR_WDR,  *LPNET_DVR_WDR; 

//Day/Night Switching
typedef struct tagNET_DVR_DAYNIGHT
{
    BYTE byDayNightFilterType;  /*Day/Night mode: 0 day, 1 night, 2 auto,3-timing,4-alarm in trigger */
    BYTE bySwitchScheduleEnabled;  /*0 disable  1 enable (Reserved) */
    //Mode 1 
    BYTE byBeginTime;  /*begin time hour,0-23*/
    BYTE byEndTime;  /*end time hour,0-23*/
    //Mode 2 (Reserved)
    BYTE byDayToNightFilterLevel;  //0- 7
    BYTE byNightToDayFilterLevel;  //0- 7
    BYTE byDayNightFilterTime; // (60 sec) 
    BYTE byBeginTimeMin; //begin time min,0-59
	BYTE byBeginTimeSec; //begin time sec,0-59
	BYTE byEndTimeMin; //end time min,0-59
	BYTE byEndTimeSec; //end time sec,0-59
    BYTE byAlarmTrigState; //alarm in trigger state,0-day,1-night
} NET_DVR_DAYNIGHT,  *LPNET_DVR_DAYNIGHT; 

//Gamma correction
typedef struct tagNET_DVR_GAMMACORRECT
{
    BYTE byGammaCorrectionEnabled;  /*0- disable;  1- enable*/
    BYTE byGammaCorrectionLevel;  /*0- 100*/
    BYTE byRes[6]; 
} NET_DVR_GAMMACORRECT,  *LPNET_DVR_GAMMACORRECT; 

//BLC
typedef struct tagNET_DVR_BACKLIGHT
{
    BYTE byBacklightMode;  /*BLC: 0-off  1- UP, 2- DOWN, 3- LEFT, 4- RIGHT, 5- MIDDLE, 6-USERSET*/
    BYTE byBacklightLevel;  /*0x0- 0xF*/
    BYTE byRes1[2]; 
    DWORD dwPositionX1;  // (X coordinate 1) 
    DWORD dwPositionY1;  // (Y coordinate 1) 
    DWORD dwPositionX2;  // (X coordinate 2) 
    DWORD dwPositionY2;  // (Y coordinate 2) 
    BYTE byRes2[4]; 
} NET_DVR_BACKLIGHT,  *LPNET_DVR_BACKLIGHT; 

//DNR
typedef struct tagNET_DVR_NOISEREMOVE
{
    BYTE byDigitalNoiseRemoveEnable;  /*DNR: 0- disable  1- normal mode, 2-expert mode*/
    BYTE byDigitalNoiseRemoveLevel;  /*0x0- 0xF*/
	BYTE bySpectralLevel;   /*expert mode Spatial intensity, 0-100*/
    BYTE byTemporalLevel;   /*expert mode Time-domain intensity, 0-100*/
    BYTE byRes[4]; 
} NET_DVR_NOISEREMOVE,  *LPNET_DVR_NOISEREMOVE; 

//Lens configuration under CMOS mode
typedef struct tagNET_DVR_CMOSMODCFG
{
    BYTE byCaptureMod;    //Snapshot mode: 0- mode1; 1- mode2
    BYTE byBrightnessGate; //Brightness threshold
    BYTE byCaptureGain1;    //Snapshot Gain1, 0- 100
    BYTE byCaptureGain2;    //Snapshot Gain2, 0- 100
    DWORD dwCaptureShutterSpeed1; //Snapshot Shutter speed 1
    DWORD dwCaptureShutterSpeed2; //Snapshot Shutter speed 2
    BYTE    byRes[4]; 
}NET_DVR_CMOSMODECFG,  *LPNET_DVR_CMOSMODECFG; 

//IPC CCD Parameter Configuration
typedef struct tagNET_DVR_CAMERAPARAMCFG
{
    DWORD dwSize; 
    NET_DVR_VIDEOEFFECT struVideoEffect; /*Brightness, Contrast, Saturation, Sharpness, Hue Configuration*/    
    NET_DVR_GAIN struGain; /*Auto Gain*/
    NET_DVR_WHITEBALANCE struWhiteBalance; /*White Balance*/
    NET_DVR_EXPOSURE struExposure;  /*Exposure Control*/
    NET_DVR_GAMMACORRECT struGammaCorrect; /*Gamma Correction*/
    NET_DVR_WDR struWdr; /*WDR*/
    NET_DVR_DAYNIGHT struDayNight; /*Day/Night*/
    NET_DVR_BACKLIGHT struBackLight; /*BLC*/
    NET_DVR_NOISEREMOVE struNoiseRemove; /*DNR*/
    BYTE byPowerLineFrequencyMode;  /*0- 50HZ;  1- 60HZ*/
    BYTE byIrisMode;  /*0-Auto Iris 1-Manual Iris*/    
    BYTE byMirror ;   /* Mirror: 0 off, 1- leftright, 2- updown, 3-center */
    BYTE byDigitalZoom;   /*Digital zoom: 0 disable  1 enable*/
    BYTE byDeadPixelDetect;    /*Corrupted Pixel detect, 0-disable  1-enable*/
    BYTE byBlackPwl; /*Black Power Level ,   0- 255*/ 
    BYTE byEptzGate; // EPTZ: 0-off; 1-Eletronic PTZ
    BYTE byLocalOutputGate; //Local output 0- local output closed; 1- Local BNC output open; 2- HDMI output closed  
    //20- HDMI_720P50 output open
    //21- HDMI_720P60 output open
    //22- HDMI_1080I60 output open
    //23- HDMI_1080I50 output open
    //24- HDMI_1080P24 output open
    //25- HDMI_1080P25 output open
    //26- HDMI_1080P30 output open
    //27- HDMI_1080P50 output open
    //28- HDMI_1080P60 output open
    BYTE byCoderOutputMode; //Encoder's FPGA output mode
    BYTE byLineCoding; //Enable line coding or not: 0- enable, 1- disable
    BYTE byDimmerMode; //Dimming mode: 0- semi-automatic, 1- automatic
	BYTE byPaletteMode; //Color palette: 0- incandescence, 1- Black heat, 2- palette 2, ..., 8- palette 8
	BYTE byEnhancedMode; //Enhance mode (around detected object): 0- not enhance, 1- 1, 2- 2, 3- 3, 4- 4
    BYTE byDynamicContrastEN;     //Increase Dynamic Contrast 0- 1
    BYTE byDynamicContrast;     //Dynamic Contrast 0- 100
    BYTE byJPEGQuality;     //JPEG Quality: 0- 100
    NET_DVR_CMOSMODECFG struCmosModeCfg; //Configuration under CMOS mode
    BYTE byFilterSwitch; //Filter switch: 0- disable, 1- enable
	BYTE byFocusSpeed;  //Focus speed: 0-10
	BYTE byAutoCompensationInterval; //Scheduled automatic shutter compensation: 1-120, unit: minute
	BYTE bySceneMode;  //Scene mode: 0- outdoor, 1- indoor
}NET_DVR_CAMERAPARAMCFG,  *LPNET_DVR_CAMERAPARAMCFG; 

//plate color
typedef enum _VCA_PLATE_COLOR_
{
    	VCA_BLUE_PLATE  = 0,       //Blue license plate
		VCA_YELLOW_PLATE,          //Yellow license plate
		VCA_WHITE_PLATE,           //White license plate
		VCA_BLACK_PLATE            //Black license plate
}VCA_PLATE_COLOR;

//plate type
typedef enum _VCA_PLATE_TYPE_
{
    VCA_STANDARD92_PLATE = 0,	//Standard civil car and military car
	VCA_STANDARD02_PLATE,		//civil car license plate of form 02
	VCA_WJPOLICE_PLATE,		    //Armed police car 
	VCA_JINGCHE_PLATE,			//Police car
	STANDARD92_BACK_PLATE,  	//Dual-line rear plate of civil car
	VCA_SHIGUAN_PLATE,          //Embassy license plate
	VCA_NONGYONG_PLATE,         //Agricultural vehicles
	VCA_MOTO_PLATE              //Motorcycle
}VCA_PLATE_TYPE;

//LPR sub structure
typedef struct tagNET_DVR_PLATE_INFO
{
    BYTE  byPlateType; 					//license type
    BYTE  byColor; 						//License color
    BYTE  byBright; 						//License brightness
    BYTE  byLicenseLen; 					//Character number of the license plate
    BYTE  byEntireBelieve; 					//Accuracy of the license plate (percentage)
    BYTE  byRes[35]; 					//Reserved
    NET_VCA_RECT	struPlateRect; 		//License plate position
    char sLicense[MAX_LICENSE_LEN]; 		//license content
    BYTE byBelieve[MAX_LICENSE_LEN]; 	//Accuracy of each letter
}NET_DVR_PLATE_INFO,  *LPNET_DVR_PLATE_INFO; 

//Vehicle info
typedef struct tagNET_DVR_VEHICLE_INFO_
{
    DWORD dwIndex; 					//Vehicle index
    BYTE  byVehicleType; 		//Vehicle type
    BYTE  byColorDepth; 		//Vehicle color (dark/light)
    BYTE  byColor; 					//Vehicle color
    BYTE  byRes1[1]; 				//Reserved
    WORD  wSpeed; 					//Speed (km/h)
    WORD  wLength; 					//Vehicle length of the previous one
    BYTE  byIllegalType;            //0- normal; 1- low speed 2- High speed 3- traverse travelling,4-run red light,5-drive line,6-direction
	BYTE  byRes2[3]; //Reserved
	BYTE  byCustomInfo[16];  //Custom information
	BYTE  byRes3[16];	//Reserved
}NET_DVR_VEHICLE_INFO,  *LPNET_DVR_VEHICLE_INFO; 

//License Recognition
typedef struct tagNET_DVR_PLATE_RESULT
{
    DWORD   dwSize; 						//Structure length
    BYTE	byResultType; 			//0- video recognition result, 1- Image  recognition result
    BYTE    byChanIndex; 			//Channel number
    BYTE    byRes1[2]; 				//Reserved
    DWORD   dwRelativeTime; 		//relative time   
    BYTE    byAbsTime[32]; 		//Relative time, yyyymmddhhmmssxxx, e.g.20090810235959999 (unit: ms) 
    DWORD   dwPicLen; 					//Picture length
    DWORD	dwPicPlateLen; 			//License plate snapshot length 
    DWORD   dwVideoLen; 					//recoding video length
    BYTE	byTrafficLight; 				//0- non traffic light snapshot, 1- Green light snapshot; 2- Red light snapshot
    BYTE    byPicNum; 				//Picture index on multi-shot mode
    BYTE	byDriveChan; 				//Traffic lane index
	BYTE    byRes2;                      //Reserved
    DWORD   dwBinPicLen; //Bin picture length
	DWORD   dwCarPicLen;//car picture length
	DWORD   dwFarCarPicLen;  //far car picture length
	BYTE    *pBuffer3;   //bin picture
	BYTE    *pBuffer4;  //car picture 
	BYTE    *pBuffer5;  //far car picture
	BYTE    byRes3[8];                      //Reserved 
    NET_DVR_PLATE_INFO  struPlateInfo;     //License plate info structure
    NET_DVR_VEHICLE_INFO struVehicleInfo;  //Vehicle info
    BYTE	*pBuffer1;    		        // Pointer to the upload snapshot or video, set it as NULL if no upload is required
    BYTE    *pBuffer2;                   // Pointer to the snapshot picture
}NET_DVR_PLATE_RESULT,  *LPNET_DVR_PLATE_RESULT; 
//For snapshot, the data would be arranged as video scene snapshot picture + license snapshot picture 

//Picture overlay info configuration      
typedef struct tagNET_DVR_IMAGEOVERLAYCFG
{
    DWORD		dwSize; 
    BYTE		byOverlayInfo; //0- disable overlay 1- enable overlay
    BYTE		byOverlayMonitorInfo; //Overlay info of the monitor spot, 0- disable, 1- enable
    BYTE		byOverlayTime; //Overlay time, 0- disable, 1- enable
    BYTE		byOverlaySpeed; //Overlay speed, 0- disable, 1- enable
    BYTE		byOverlaySpeeding; //Overlay over-speed proportion, 0- disable, 1- enable
    BYTE		byOverlayLimitFlag; //Overlay speed-limitation mark, 0- disable, 1- enable
    BYTE		byOverlayPlate; //Overlay license plate, 0- disable, 1- enable
    BYTE		byOverlayColor; //Overlay vehicle color, 0- disable, 1- enable
    BYTE		byOverlayLength; //Overlay vehicle length, 0- disable, 1- enable
    BYTE		byOverlayType; //Overlay vehicle type, 0- disable, 1- enable
    BYTE		byOverlayColorDepth; //Overlay vehicle color depth, 0- disable, 1- enable
    BYTE		byOverlayDriveChan; //Overlay traffic lane info, 0- disable, 1- enable
    BYTE		byOverlayMilliSec;  //Overlay millisecond info: 0- disable, 1- enable
	BYTE		byOverlayIllegalInfo;  //Overlay illegal record info: 0- disable, 1- enable
	BYTE        byOverlayRedOnTime;   //Overlay time duration after red Light is on: 0- disable, 1- enable
	BYTE        byFarAddPlateJpeg;      //Far picture overlay plate jpeg,0- disable, 1- enable
	BYTE        byNearAddPlateJpeg;      //Near picture overlay plate jpeg,0- disable, 1- enable
	BYTE		byRes1[3];     //Reserved
	BYTE		byMonitorInfo1[32];     //Monitor spot info 1
	BYTE		byMonitorInfo2[44];  //Monitor spot info 2
	BYTE		byRes2[52];     //Reserved
}NET_DVR_IMAGEOVERLAYCFG,  *LPNET_DVR_IMAGEOVERLAYCFG; 

//Single IO Triggering 
typedef struct tagNET_DVR_SNAPCFG
{
    DWORD   dwSize; 
    BYTE	byRelatedDriveWay; //Traffic lane
    BYTE 	bySnapTimes;  //Snapshot time 0- disable, else- snapshot time (up to 5)  
    WORD	wSnapWaitTime;   //Snapshot wait time (unit: ms) , [67, 60000]
    WORD	wIntervalTime[4]; //multi-shot interval 1, (unit:ms)
    BYTE	byRes2[24]; //Reserved
}NET_DVR_SNAPCFG,  *LPNET_DVR_SNAPCFG; 

typedef enum _ITC_MAINMODE_ABILITY_
{
    ITC_MODE_UNKNOW    = 0x0,   //无
	ITC_POST_MODE  = 0x1,  //post
	ITC_EPOLICE_MODE      = 0x2,  //epolice
	ITC_POSTEPOLICE_MODE  = 0x4  //post epolice
}ITC_MAINMODE_ABILITY;

typedef enum _ITC_RECOG_REGION_TYPE_
{
    ITC_REGION_RECT     = 0x0,  //rect
	ITC_REGION_POLYGON  = 0x1,  //polygon
}ITC_RECOG_REGION_TYPE;

typedef struct tagNET_DVR_SNAP_ABILITY
{
    DWORD dwSize; 
    BYTE  byIoInNum; //IO input number
    BYTE  byIoOutNum; //IO output number
    BYTE  bySingleSnapNum; //Group number of Single IO triggering 
    BYTE  byLightModeArrayNum; //Group number of Traffic Light Mode 
    BYTE  byMeasureModeArrayNum; //Speed Measure mode group number
    BYTE  byPlateEnable;  //LPR ability
    BYTE  byLensMode; //Lens mode: 0- CCD, 1- CMOS
	BYTE  byPreTriggerSupport; //Support original trigger mode,0-yes,1-no
	DWORD dwAbilityType; //Trigger ability, bit Express, see ITC_MAINMODE_ABILITY
	BYTE  byIoSpeedGroup; //IO speed group number
	BYTE  byIoLightGroup; //IO light group number
	BYTE  byRecogRegionType; //Plate region type, see ITC_RECOG_REGION_TYPE
	BYTE  byRes[21]; 
} NET_DVR_SNAP_ABILITY,  *LPNET_DVR_SNAP_ABILITY; 

typedef struct tagNET_DVR_TRIGCOORDINATE
{
    WORD wTopLeftX;  /*X axis coordinate of the coil's upper left corner (2 bytes) */
    WORD wTopLeftY;  /*Y axis coordinate of the coil's upper left corner (2 bytes) */
    WORD wWdith;  /*Coil width (2 bytes) */
    WORD wHeight;  /*Coil height (2 bytes) */
} NET_DVR_TRIGCOORDINATE,  *LPNET_DVR_TRIGCOORDINATE; 

typedef enum _PROVINCE_CITY_IDX_
{
	ANHUI_PROVINCE             = 0,              //An Hui
	AOMEN_PROVINCE             = 1,              //Macao 
	BEIJING_PROVINCE           = 2,              //Bei Jing
	CHONGQING_PROVINCE         = 3,              //Chong Qing
	FUJIAN_PROVINCE            = 4,              //Fu Jian
	GANSU_PROVINCE             = 5,              //Gan Su
	GUANGDONG_PROVINCE         = 6,              //Guang Dong
	GUANGXI_PROVINCE           = 7,              //Guang Xi
	GUIZHOU_PROVINCE           = 8,              //Gui Zhou
	HAINAN_PROVINCE            = 9,              //Hai Nan 
	HEBEI_PROVINCE             = 10,             //He Bei
	HENAN_PROVINCE             = 11,             //He Nan 
	HEILONGJIANG_PROVINCE      = 12,             //Hei Long Jiang
	HUBEI_PROVINCE             = 13,             //Hu Bei
	HUNAN_PROVINCE             = 14,             //Hu Nan
	JILIN_PROVINCE             = 15,             //Ji Lin
	JIANGSU_PROVINCE           = 16,             //Jiang Su
	JIANGXI_PROVINCE           = 17,             //Jiang Xi
	LIAONING_PROVINCE          = 18,             //Liao Ning
	NEIMENGGU_PROVINCE         = 19,             //Nei Meng Gu
	NINGXIA_PROVINCE           = 20,             //Ning Xia
	QINGHAI_PROVINCE           = 21,             //Qing Hai
	SHANDONG_PROVINCE          = 22,             //Shan Dong
	SHANXI_JIN_PROVINCE        = 23,             //Shan Xi
	SHANXI_SHAN_PROVINCE       = 24,             //Shaan Xi
	SHANGHAI_PROVINCE          = 25,             //Shang Hai
	SICHUAN_PROVINCE           = 26,             //Si Chuan
	TAIWAN_PROVINCE            = 27,             //Tai Wan
	TIANJIN_PROVINCE           = 28,             //Tian Jin
	XIZANG_PROVINCE            = 29,             //Xi Zang
	XIANGGANG_PROVINCE         = 30,             //HongKong
	XINJIANG_PROVINCE          = 31,             //Xin Jiang
	YUNNAN_PROVINCE            = 32,             //Yun Nan
	ZHEJIANG_PROVINCE          = 33              //Zhe Jiang
}PROVINCE_CITY_IDX;

typedef struct tagNET_DVR_GEOGLOCATION
{
	int iRes[2];  /*Reserved*/
	DWORD dwCity; /*City, see to PROVINCE_CITY_IDX */
}NET_DVR_GEOGLOCATION, *LPNET_DVR_GEOGLOCATION;

//Scene mode
typedef enum _SCENE_MODE_
{
	UNKOWN_SCENE_MODE   = 0,            //Unknown
	HIGHWAY_SCENE_MODE  = 1,            //High-speed outdoor scene mode
	SUBURBAN_SCENE_MODE = 2,            //Suburban scene mode
	URBAN_SCENE_MODE    = 3,            //Urban scene mode
	TUNNEL_SCENE_MODE   = 4             //High-speed tunnel scene mode 
}SCENE_MODE;

typedef struct tagNET_DVR_VTPARAM
{
    DWORD   dwSize; 
    BYTE    byEnable;   /* Enable virtual coil: 0- disable, 1- enable*/
    BYTE    byIsDisplay;  /* display virtual coil,0- disable, 1- enable*/
    BYTE    byLoopPos; //night loop position:0-up,1-down
	BYTE    bySnapGain; /*snap gain*/
	DWORD   dwSnapShutter; /*snap shutter*/
    NET_DVR_TRIGCOORDINATE struTrigCoordinate; 
    NET_DVR_TRIGCOORDINATE struRes[5]; 
    BYTE    byTotalLaneNum; /*traffic lane 1*/
    BYTE    byPolarLenType;  /*Polar Len type, 0-disable; 1-Schneider Polar len*/
    BYTE	byDayAuxLightMode;  /*Day time aux Lighting, 0- disable; 1-LED; 2- Flash light*/
    BYTE	byLoopToCalRoadBright;  /*Traffic lane used for counting road brightness (Virtual coil) */
    BYTE	byRoadGrayLowTh;  /*Low threshold of road brightness, default:1*/
    BYTE	byRoadGrayHighTh;  /*High threshold of road brightness, default:140*/
    WORD	wLoopPosBias;  /*Loop position bias for Night mode,default: 30*/
    DWORD   dwHfrShtterInitValue;  /*Continuous exposure time, default:2000*/
    DWORD   dwSnapShtterInitValue;  /*Exposure time, default:500*/
    DWORD   dwHfrShtterMaxValue;  /*Max. Exposure time for multi-shot*/
    DWORD   dwSnapShtterMaxValue;  /*Max. Exposure time for snapshot*/
    DWORD   dwHfrShtterNightValue;  /*Exposure time for multi-shot at night: default: 3000*/
    DWORD   dwSnapShtterNightMinValue;  /*Min. Exposure time for multi-shot at night: default: 3000*/
    DWORD   dwSnapShtterNightMaxValue;  /*Max. Exposure time for multi-shot at night: default: 5000*/
    DWORD   dwInitAfe;  /*Gain, default:200*/
    DWORD   dwMaxAfe;  /*Max. Gain: default: 400*/
    WORD    wResolutionX; /* Resolution (horizontal)*/
    WORD    wResolutionY; /* Resolution (height)*/
    DWORD   dwGainNightValue; /*night gain:default:70*/
	DWORD   dwSceneMode; /*scene type, see SCENE_MODE */
	DWORD   dwRecordMode; /*record flag: 0-disable,1-enable*/
	NET_DVR_GEOGLOCATION struGeogLocation; /*geolocation*/
	BYTE    byTrigFlag[MAX_VL_NUM]; /*trigger flag,0-car front;1-car end;2-car front and car end all*/
	BYTE    byTrigSensitive[MAX_VL_NUM];  /*sensitive 1-100*/
	BYTE    byRes2[62];
}NET_DVR_VTPARAM,  *LPNET_DVR_VTPARAM; 

typedef struct tagNET_DVR_SNAPENABLECFG
{
	DWORD		dwSize; 
	BYTE		byPlateEnable; //0- disable LPR 1- enable
	BYTE        byRes1[2];   //Reserved
	BYTE        byFrameFlip;    //Flip image 0- disable; 1- enable
	WORD        wFlipAngle;     //Flip angle: 0, 90, 180, 270
	WORD        wLightPhase;    //Phase, [0,  360]
	BYTE        byLightSyncPower;   //Power synchronize for the flash light, 0- disable; 1- enable
	BYTE        byFrequency;		//signal frequency
	BYTE        byUploadSDEnable;  //upload SD picture,0-no,1-yes
    BYTE        byPlateMode; //recognition mode:0-video trigger,1-IO trigger
	BYTE  byUploadInfoFTP; //UploadInfoFTP,0-no,1-yes
	BYTE  byAutoFormatSD; //Auto Format SD,0-no,1-yes
	BYTE 		byRes[58];  //Reserved
}NET_DVR_SNAPENABLECFG,  *LPNET_DVR_SNAPENABLECFG; 

/* ftp Upload*/
typedef struct 
{
    DWORD	dwSize; 
    DWORD	dwEnableFTP; 			/*Enable FTP upload*/
    char	sFTPIP[16]; 				/*FTP IP*/
    DWORD	dwFTPPort; 				/*FTP port number*/
    BYTE	sUserName[NAME_LEN]; 	/*User name*/
    BYTE	sPassword[PASSWD_LEN]; 	/*Password*/
    DWORD	dwDirLevel; 	/*0 - Save in root directory, 1 - 1st directory, 2= 2nd directory*/
    WORD 	wTopDirMode; 	/* 1st directory, 0x1 = device name, 0x2 = device ID, 0x3 = device IP, 0x4=Monitor spot, 0x5= time (YM)*/
    WORD 	wSubDirMode; 	/* 2nd directory, 0x1 = channel name, 0x2 = Channel number, , 0x3= time (YMD) , 0x4=traffic lane number*/
	BYTE    byEnableAnony; //anony enable,0-no,1-yes
    BYTE 	byRes[23]; 
}NET_DVR_FTPCFG,  *LPNET_DVR_FTPCFG; 

/*Snapshot naming elements*/
#define PICNAME_ITEM_DEV_NAME 	    1		/*device name*/
#define PICNAME_ITEM_DEV_NO 	    2		/*Device ID*/
#define PICNAME_ITEM_DEV_IP 	    3		/*IP*/
#define PICNAME_ITEM_CHAN_NAME 	    4		/*channel name*/
#define PICNAME_ITEM_CHAN_NO 	    5		/*Channel number*/
#define PICNAME_ITEM_TIME 		    6		/*time*/
#define PICNAME_ITEM_CARDNO		    7		/*card number*/
#define PICNAME_ITEM_PLATE_NO       8       /*license number*/
#define PICNAME_ITEM_PLATE_COLOR    9       /*license color*/
#define PICNAME_ITEM_CAR_CHAN       10      /*traffic lane*/
#define PICNAME_ITEM_CAR_SPEED      11      /*speed*/
#define PICNAME_ITEM_CARCHAN        12      /*monitor spot*/
#define PICNAME_ITEM_PIC_NUMBER     13      //picture number
#define PICNAME_MAXITEM 		    15


typedef struct 
{
    BYTE 	byItemOrder[PICNAME_MAXITEM]; 	
    BYTE 	byDelimiter; 		/*delimiter'_'*/
}NET_DVR_PICTURE_NAME,  *LPNET_DVR_PICTURE_NAME; 

/* Serial port snapshot*/
typedef struct 
{
    BYTE	byStrFlag; 	/*serial port data start*/
    BYTE 	byEndFlag; 	/*data end*/
    WORD	wCardIdx; 	/*card number start digit (relative)*/
    DWORD 	dwCardLen; 	/*card number length*/
    DWORD   dwTriggerPicChans; 	/*Channel number, by bit. Count from the first bit, and 0x2 means channel NO.1*/
}NET_DVR_SERIAL_CATCHPIC_PARA,  *LPNET_DVR_SERIAL_CATCHPIC_PARA; 

//DVR snapshot
typedef struct 
{
    DWORD	dwSize; 
    NET_DVR_JPEGPARA struJpegPara[MAX_CHANNUM_V30]; 	/*image parameter for each channel*/
    WORD	wBurstMode; 							/*snapshot trigger mode, 0x1=alarm in, 0x2=Motion 0x4=232, 0x8=485, 0x10=network*/
    WORD	wUploadInterval; 					/*snapshot upload interval (seconds) [0, 65535]*/
    NET_DVR_PICTURE_NAME 	struPicNameRule; 	/* snapshot naming rule */
    BYTE	bySaveToHD; 		/*Save to HD*/
    BYTE	byRes1; 
    WORD	wCatchInterval; 		/*Snapshot interval (unit: ms) [0, 65535]*/
    BYTE	byRes2[12]; 
    NET_DVR_SERIAL_CATCHPIC_PARA struRs232Cfg; 
    NET_DVR_SERIAL_CATCHPIC_PARA struRs485Cfg; 
    DWORD dwTriggerPicTimes[MAX_CHANNUM_V30]; 	/* Snapshot number for each channel */
    DWORD dwAlarmInPicChanTriggered[MAX_ALARMIN_V30];  /*Alarm linked snapshot channel*/
}NET_DVR_JPEGCFG_V30,  *LPNET_DVR_JPEGCFG_V30; 

//Reserved 
typedef struct tagNET_DVR_MANUALSNAP
{
    BYTE byRes[24];  //Reserved
}NET_DVR_MANUALSNAP,  *LPNET_DVR_MANUALSNAP; 

typedef struct tagNET_DVR_SPRCFG    
{
    DWORD dwSize;  
	BYTE byDefaultCHN[3];  /*Set short-form of province name*/
	BYTE byPlateOSD;     /*license snapshot: 0-disable , 1- enable*/
	BYTE bySendJPEG1;    /*Send JPEG snapshot 1:  0-disable , 1- enable*/
	BYTE bySendJPEG2;    /*Send JPEG snapshot 2:  0-disable , 1- enable*/
	WORD wDesignedPlateWidth;    /*license width*/
	BYTE byTotalLaneNum;   /*Traffic lane number*/
	BYTE byRes1;       /*Reserved*/
	WORD wRecognizedLane;  /*Recognized lane, represented by bit. Bit0: whether lane 1 is recognized or not, 0- no, 1- yes*/
    NET_VCA_RECT struLaneRect[MAX_LANERECT_NUM];   /*Traffic lane region*/
	DWORD dwRecogMode;  /*Recognition type,
						bit0- Recognition direction: 0- from front,1- from back ;
					   bit1- Big plate of little plate: 0- small plate,1- big plate ; 
					   bit2- Color recognition: 0- disable color recognition, when recognizing from back or recognizing small plate, 1- enable color recognition;
					   bit3- Agricultural car recognition: 0-disable,1-enable; 
					   bit4- Blur recognition: 0-disable,1-enable; 
					   bit5- Frame or scene location: 0-fram location,1-scene location;
					   bit6- Frame or scene recognition: 0-fram recognition,1-scene recognition;
                       bit7- Day or night: 0-Day,1-Night */
	BYTE  bySendPRRaw;       	//Send raw picture:0-disable,1-enable
	BYTE  bySendBinImage;  	//Send bin picture:0-disable,1-enable
	BYTE  byDelayCapture;  //snap delay,uint:frame
	BYTE  byUseLED;    //LED control:0-no,1-yes
	BYTE  byRes2[68];    //Reserved
}NET_DVR_SPRCFG,  *LPNET_DVR_SPRCFG; 

typedef struct tagNET_DVR_PLCCFG
{
	DWORD dwSize;
	BYTE byPlcEnable;	//Whether to open brightness compensation of license plate or not(default:open): 0-close, 1-open 
	BYTE byPlateExpectedBright;	//Expected brightness of license plate(default:50),range:[0, 100]
	BYTE byRes1[2];
	BYTE byTradeoffFlash;     //Whether to consider flashlight: 0 - no;  1 - yes(default); 
	//When flash works, if consider to weaken brightness compensation of flashlight, set it to 1, or to 0
	BYTE byCorrectFactor;     //Correct factor, range:[0, 100], default:50 (resume to default when cut tradeoff_flash)
	WORD wLoopStatsEn;  //Whether to count loop brightness, represented by bit, 0- no, 1- yes
	BYTE byRes[20];
}NET_DVR_PLCCFG, *LPNET_DVR_PLCCFG;

#define NET_DVR_GET_DEVICESTATECFG              1096   //Get current state parameters of device

typedef struct tagNET_DVR_DEVICESTATECFG
{
	DWORD dwSize;
	WORD wPreviewNum; //Preview number
	WORD wFortifyLinkNum; //Fortify link number
	NET_DVR_IPADDR struPreviewIP[MAX_LINK];  //User IP address of preview
	NET_DVR_IPADDR struFortifyIP[MAX_FORTIFY_NUM]; //User IP address of fortify
	DWORD dwVideoFrameRate;	//Frame rate:0-all; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; 14-15; 15-18; 16-22;
	BYTE byResolution;  	//Resolution:0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5(reserved),16-VGA(640*480), 17-UXGA(1600*1200), 18-SVGA (800*600),19-HD720p(1280*720),20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE bySnapResolution;  	//Resolution of snap:0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5(reserved),16-VGA(640*480), 17-UXGA(1600*1200), 18-SVGA (800*600),19-HD720p(1280*720),20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE byStreamType; //Stream type:0-major stream;1-minor stream
	BYTE byTriggerType; //Trigger mode:0-video trigger;1-normal trigger
	DWORD dwSDVolume;  //Volume of SD card
	DWORD dwSDFreeSpace; //Free space of SD card
	BYTE byDetectorState[MAX_DRIVECHAN_NUM][MAX_COIL_NUM];  //State of magnetic vehicle detector: 0-unused;1-normal;2-exceptional 
	BYTE byDetectorLinkState; //Connection state of magnetic vehicle detector: 0-disconnected;1-connected 
	BYTE bySDStatus;    //SD state 0－activity,1－Dormancy,2－Abnormal, 3-no sd
	BYTE byFortifyLevel[MAX_FORTIFY_NUM]; //Fortify level,0-no,1-level 1(high),2-level 2(middle),3-level 3(low)
	BYTE byRes2[116]; //Reserved
}NET_DVR_DEVICESTATECFG, *LPNET_DVR_DEVICESTATECFG;

typedef struct tagNET_DVR_POSTEPOLICECFG
{
	DWORD dwSize;
	DWORD dwDistance;//Coil distance, cm, [0,20000]
	DWORD dwLightChan[MAX_SIGNALLIGHT_NUM];	// Channel number of signal light
	BYTE  byCapSpeed;//Sign speed limit, unit: km/h, value range: [0,255]
	BYTE  bySpeedLimit;//Speed limit value, unit: km/h, value range:[0,255]
	BYTE  byTrafficDirection;//Traffic direction: 0-from east to west, 1-from west to east, 2-from south to north, 3-from north to south
	BYTE  byRes1; //Reserved
	WORD  wLoopPreDist;        /*Trigger delay distance,unit:dm*/
	WORD  wTrigDelay;             /*Trigger delay time,unit: ms*/
	BYTE  byRes[124];//Reserved
}NET_DVR_POSTEPOLICECFG, *LPNET_DVR_POSTEPOLICECFG;

/***************************** end *********************************************/

#define IPC_PROTOCOL_NUM      50   //max number of ipc protocol

//Smart search 
typedef struct tagNET_DVR_SMART_SEARCH_PARAM
{
    BYTE	  byChan; 					//Channel number
    BYTE      byRes1[3]; 
    NET_DVR_TIME struStartTime; 		//Recording start time
    NET_DVR_TIME struEndTime; 		//Recording stop time
    BYTE byMotionScope[64][96]; 		//Detect region: 96*64 macro blocks, 1-enable; 0-disable
    BYTE  bySensitivity;    			//sensitivity,  1- >80%,  2-40%~80%,  3-1%~40%
    BYTE byRes2[11]; 
}NET_DVR_SMART_SEARCH_PARAM,  *LPNET_DVR_SMART_SEARCH_PARAM; 

typedef struct tagNET_DVR_SMART_SEARCH_RET
{
    NET_DVR_TIME struStartTime; 	//Motion detect start time
    NET_DVR_TIME struEndTime;    //event stop time
    BYTE byRes[64]; 
}NET_DVR_SMART_SEARCH_RET,  *LPNET_DVR_SMART_SEARCH_RET; 

// IPSAN search directory
typedef struct tagNET_DVR_IPSAN_SERACH_PARAM
{
    NET_DVR_IPADDR  struIP;     // IPSAN IPaddress
    WORD            wPort;      // IPSAN  port
    BYTE            byRes[10];  // 
}NET_DVR_IPSAN_SERACH_PARAM, *LPNET_DVR_IPSAN_SERACH_PARAM;

typedef struct tagNET_DVR_IPSAN_SERACH_RET
{
    BYTE byDirectory[128];  // Directory
    BYTE byRes[20];
}NET_DVR_IPSAN_SERACH_RET, *LPNET_DVR_IPSAN_SERACH_RET;

//DVR device parameters
typedef struct
{
    DWORD dwSize; 
    BYTE sDVRName[NAME_LEN];      //DVR name
    DWORD dwDVRID; 				//DVR ID //V1.4 (0- 99) ,  V1.5 (0- 255) 
    DWORD dwRecycleRecord; 		//cycle record, 0-disable, 1-enable
    //Read-only
    BYTE sSerialNumber[SERIALNO_LEN];   //SN
    DWORD dwSoftwareVersion; 			//Software version
    DWORD dwSoftwareBuildDate; 			//Build, 0xYYYYMMDD
    DWORD dwDSPSoftwareVersion; 		    //DSP Version: 16 high bit is the major version, and 16 low bit is the minor version
    DWORD dwDSPSoftwareBuildDate; 		// DSP Build, 0xYYYYMMDD
    DWORD dwPanelVersion; 				// Front panel version
    DWORD dwHardwareVersion; 	// Hardware version
    BYTE byAlarmInPortNum; 		//DVR Alarm input
    BYTE byAlarmOutPortNum; 		//DVR Alarm output
    BYTE byRS232Num; 			//DVR 232 port number
    BYTE byRS485Num; 			//DVR 485 port number
    BYTE byNetworkPortNum; 		//Network port number
    BYTE byDiskCtrlNum; 			//DVR HDD number
    BYTE byDiskNum; 				//DVR disk number
    BYTE byDVRType; 				//DVR type,  1: DVR 2: ATM DVR 3: DVS ......- - 
    BYTE byChanNum; 				//DVR channel number
    BYTE byStartChan; 			//start Channel number, DVS- 1, DVR -  1
    BYTE byDecordChans; 			//DVR decoding
    BYTE byVGANum; 				//VGA number 
    BYTE byUSBNum; 				//USB number
    BYTE byAuxoutNum; 			//Aux output number
    BYTE byAudioNum; 			//voice interface number
    BYTE byIPChanNum; 			//Max. IP channel number 
    BYTE byZeroChanNum; 			//Zero channel number
    BYTE bySupport;         //Ability set
    //bySupport & 0x1,  smart search
    //bySupport & 0x2,  backup
    //bySupport & 0x4,  compression ability set
    //bySupport & 0x8,  multiple network adapter
    //bySupport & 0x10, remote SADP
    //bySupport & 0x20  support Raid
    //bySupport & 0x40  support IPSAN
	//bySupport & 0x80, support RTP over RTSP
    BYTE byEsataUseage; 		//Default E-SATA: 0- backup, 1- record
    BYTE byIPCPlug; 			//0- disable plug-and-play, 1- enable plug-and-play
	BYTE byStorageMode;		  //Hard Disk Mode:0-group,1-quota,2-drawframe
	BYTE bySupport1;		  //Ability set
	// bySupport1 & 0x1, support snmp v30
	// bySupport1& 0x2，support distinguish download and playback
	//bySupport1 & 0x4, support deployment level
	//bySupport1 & 0x8, support vca alarm time extension 
	//bySupport1 & 0x10, support muti disks(more than 33)
	//bySupport1 & 0x20, support rtsp over http
	WORD wDevType;//Device type
	BYTE  byDevTypeName[24];//Device type name 
	BYTE byRes2[16];			//Reserved 2
}NET_DVR_DEVICECFG_V40,  *LPNET_DVR_DEVICECFG_V40; 

#define MAX_ZEROCHAN_NUM    16
//Zero Channel 
typedef struct tagNET_DVR_ZEROCHANCFG
{
    DWORD dwSize; 			//Structure length
    BYTE  byEnable; 			//0- Disable 0 channel encoding, 1-enable  0 channel encoding
    BYTE  byRes1[3]; 			//Reserved
    DWORD dwVideoBitrate;  	//Video bit rate: 0- Reserved; 1- 16K (Reserved);  2- 32K; 3- 48k; 4- 64K; 5- 80K; 6- 96K; 7- 128K; 8- 160k; 9- 192K; 10- 224K; 11- 256K; 12- 320K
    // 13- 384K; 14- 448K; 15- 512K; 16- 640K; 17- 768K; 18- 896K; 19- 1024K; 20- 1280K; 21- 1536K; 22- 1792K; 23- 2048K
    //If the 31st digit is set as 1, then the 0- 30th digit stands for customized bit rate value (MIN- 32K MAX- 8192K) 
    DWORD dwVideoFrameRate; 	//Frame rate 0- full;  1- 1/16;  2- 1/8;  3- 1/4;  4- 1/2;  5- 1;  6- 2;  7- 4;  8- 6;  9- 8;  10- 10;  11- 12;  12- 16;  13- 20,  //V2.0: 14- 15,  15- 18,  16- 22; 
    BYTE  byRes2[32];         //Reserved
}NET_DVR_ZEROCHANCFG,  *LPNET_DVR_ZEROCHANCFG; 

//0 Channel zooming
typedef struct tagNET_DVR_ZERO_ZOOMCFG
{
    DWORD dwSize; 			    //Structure length
    NET_VCA_POINT  struPoint; 	//point
    BYTE byState; 			    //status, 0- zoom in, 1- zoom out 
    BYTE byPreviewNumber;        //Live view, 0- 1 screen-split, 1- 4 screen-split, 2- 9 screen-split, 3- 16 screen-split (read-only)
    BYTE byPreviewSeq[MAX_WINDOW_V30]; //channel info (read-only)
    BYTE byRes[30]; 				//Reserved 
}NET_DVR_ZERO_ZOOMCFG,  *LPNET_DVR_ZERO_ZOOMCFG; 

#define DESC_LEN_64 64
typedef struct tagNET_DVR_SNMPCFG
{
    DWORD   dwSize; 			//Structure length
    BYTE    byEnable; 			//0- disable SNMP, 1- enable SNMP
    BYTE    byRes1[3]; 			//Reserved
    WORD    wVersion; 		//snmp version v1 = 1,  v2 =2,  v3 =3 (V3 is reserved)
    WORD    wServerPort;  //snmp port, default: 161
    BYTE    byReadCommunity[NAME_LEN];  //Read community, max: 31bytes, default: "public"
    BYTE    byWriteCommunity[NAME_LEN]; //Write community: max: 31 bytes, default:  "private"
    BYTE 	byTrapHostIP [DESC_LEN_64]; 	//Trap host ip   
    WORD    wTrapHostPort;    // trap host port
    BYTE    byRes2[102];         // Reserved
}NET_DVR_SNMPCFG,  *LPNET_DVR_SNMPCFG; 

typedef struct tagNET_DVR_SNMPv3_USER
{
    BYTE	byUserName[NAME_LEN];
    BYTE	bySecLevel;						// Secure level 1: no auth, 2: no Privacy auth, 3: Privacy auth
    BYTE	byAuthtype;						// auth type 0: MD5 1: SHA; 2: none
	BYTE	byPrivtype;						// private type 0: DES; 1: AES; 2: none;
	BYTE	byRes[5];
    BYTE	byAuthpass[PASSWD_LEN];
    BYTE	byPrivpass[PASSWD_LEN];
}NET_DVR_SNMPv3_USER, *LPNET_DVR_SNMPv3_USER;

// snmpv30
typedef struct tagNET_DVR_SNMPCFG_V30
{
    DWORD			dwSize;						// Structure length
    BYTE			byEnableV1;					//0-disable SNMP V1，1-enable SNMP V1
	BYTE			byEnableV2;					//0-disable SNMP V2，1-enable SNMP V2
	BYTE			byEnableV3;					//0-disable SNMP V3，1-enable SNMP V3
    BYTE			byRes1[3];
    WORD			wServerPort;				// snmp port, default: 161
    BYTE			byReadCommunity[NAME_LEN];	// Read community, max: 31bytes, default: "public"
    BYTE			byWriteCommunity[NAME_LEN];	// Write community: max: 31 bytes, default:  "private"
    BYTE 			byTrapHostIP [DESC_LEN_64];	// Trap host ip    
    WORD			wTrapHostPort;				// trap host port
    BYTE			byRes2[2];					// reserve
	NET_DVR_SNMPv3_USER	struRWUser;				// Read&Write user
	NET_DVR_SNMPv3_USER	struROUser;				// Read only user
	BYTE			byRes3[32]; 
}NET_DVR_SNMPCFG_V30, *LPNET_DVR_SNMPCFG_V30;

#define  PROCESSING          0     //on processing
#define  PROCESS_SUCCESS     100   //complete
#define  PROCESS_EXCEPTION   400   //processing exception
#define  PROCESS_FAILED      500   //processing failed


#define  SOFTWARE_VERSION_LEN 48
typedef struct tagNET_DVR_SADPINFO
{
    NET_DVR_IPADDR  struIP;      // IP
    WORD            wPort;       // port number
    WORD            wFactoryType;    // manufacture
    char        chSoftwareVersion[SOFTWARE_VERSION_LEN]; 
    char        chSerialNo[16];  // SN
    WORD       wEncCnt;        // Encoding channel number
    BYTE	    byMACAddr[MACADDR_LEN]; 		// MAC
    NET_DVR_IPADDR  struSubDVRIPMask;    // DVR IP
    NET_DVR_IPADDR  struGatewayIpAddr;   // Gateway
    NET_DVR_IPADDR	struDnsServer1IpAddr; 			/* IP of DNS1*/
    NET_DVR_IPADDR	struDnsServer2IpAddr; 			/* IP of DNS2 */
    BYTE        byDns; 
    BYTE        byDhcp; 
    BYTE        byRes[158];      // Reserved
}NET_DVR_SADPINFO,  *LPNET_DVR_SADPINFO; 

#define  MAX_SADP_NUM   256   // Max device number for searching
typedef struct tagNET_DVR_SADPINFO_LIST
{
    DWORD               dwSize;    //  Structure size
    WORD                wSadpNum;    // detected device number
    BYTE                byRes[6];    // Reserved
    NET_DVR_SADPINFO    struSadpInfo[MAX_SADP_NUM];  
}NET_DVR_SADPINFO_LIST,  *LPNET_DVR_SADPINFO_LIST; 

typedef struct tagNET_DVR_SADP_VERIFY
{
    char chPassword[PASSWD_LEN]; 
    NET_DVR_IPADDR struOldIP; 
    WORD        wOldPort; 
    BYTE        byRes[62]; 
}NET_DVR_SADP_VERIFY,  *LPNET_DVR_SADP_VERIFY; 

/*******************************Backup begin********************************/

#define DESC_LEN_32          32   //description length
#define MAX_NODE_NUM         256  //node number

typedef struct tagNET_DVR_DESC_NODE
{ 
    int  iValue;            
    BYTE  byDescribe[DESC_LEN_32];  //description
    DWORD  dwFreeSpace;            //unit:Mbps
    BYTE  byRes[12]; 			  //Reserved  
}NET_DVR_DESC_NODE,  *LPNET_DVR_DESC_NODE; 

typedef struct tagNET_DVR_DISKABILITY_LIST
{ 
    DWORD     dwSize;             //Structure length
    DWORD     dwNodeNum; 		 //ability node number
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];   //description  
}NET_DVR_DISKABILITY_LIST,  *LPNET_DVR_DISKABILITY_LIST; 

//backup process
#define BACKUP_SUCCESS                100  //complete
#define BACKUP_CHANGE_DEVICE          101  //backup device is full, change the device and contiue backup

#define BACKUP_SEARCH_DEVICE          300  //Search backup device
#define BACKUP_SEARCH_FILE            301  //Search recording files
#define BACKUP_SEARCH_LOG_FILE        302  //Search log files

#define BACKUP_EXCEPTION			  400  //Backup exception
#define BACKUP_FAIL					  500  //Backup failed

#define BACKUP_TIME_SEG_NO_FILE       501  //No recording files
#define BACKUP_NO_RESOURCE            502  //Not enough resource
#define BACKUP_DEVICE_LOW_SPACE       503  //NOt enough space on backup device
#define BACKUP_DISK_FINALIZED         504  //Backup disk finalized
#define BACKUP_DISK_EXCEPTION         505  //Backup disk exception
#define BACKUP_DEVICE_NOT_EXIST       506  //Backup disk not exist
#define BACKUP_OTHER_BACKUP_WORK      507  //Other backup on progress
#define BACKUP_USER_NO_RIGHT          508  //No user right
#define BACKUP_OPERATE_FAIL           509  //Operation failure
#define BACKUP_NO_LOG_FILE            510  //No log files


typedef struct tagNET_DVR_BACKUP_NAME_PARAM
{
    DWORD dwFileNum;    //File number
    NET_DVR_FINDDATA_V30 struFileList[MAX_RECORD_FILE_NUM];  //File list
    BYTE byDiskDes[DESC_LEN_32];    //Backup disk
    BYTE byWithPlayer;       //Backup with player
    BYTE byContinue;    //Continue backup or not
	BYTE byRes[34];     //Reserved
}NET_DVR_BACKUP_NAME_PARAM,  *LPNET_DVR_BACKUP_NAME_PARAM; 

//Backup by time
typedef struct tagNET_DVR_BACKUP_TIME_PARAM
{
    LONG            lChannel;         //Channel number
    NET_DVR_TIME    struStartTime;    //Start time
    NET_DVR_TIME    struStopTime;     //End time
    BYTE byDiskDes[DESC_LEN_32];      //Backup disk
    BYTE byWithPlayer;                //0 not backup with player 1  backup with player
    BYTE byContinue;                  //0 not continue 1 continue
	BYTE byDrawFrame;			      //0 not draw frame  1 draw frame
	BYTE byRes[33];					  // Reserved 
}NET_DVR_BACKUP_TIME_PARAM,  *LPNET_DVR_BACKUP_TIME_PARAM; 

/********************************* end *******************************************/

typedef enum _COMPRESSION_ABILITY_TYPE_
{
    COMPRESSION_STREAM_ABILITY = 0,  //Stream type
    MAIN_RESOLUTION_ABILITY    = 1,  //Main stream resolution
    SUB_RESOLUTION_ABILITY     = 2,  //Sub stream resolution
    EVENT_RESOLUTION_ABILITY   = 3,  //Event encoding resolution
    FRAME_ABILITY              = 4,  //Frame rate capability set
    BITRATE_TYPE_ABILITY       = 5,  //bit rate type capability set
    BITRATE_ABILITY            = 6,  //Max. bit rate
// 	MAIN_ENCODE_FORMAT_ABILITY = 7,	//Main stream encode format(reserved)
// 	SUB_ENCODE_FORMAT_ABILITY = 8   //Sub stream encode format(reserved)
}COMPRESSION_ABILITY_TYPE; 

//Capability
typedef struct tagNET_DVR_ABILITY_LIST
{ 
    DWORD     dwAbilityType; 		// COMPRESSION_ABILITY_TYPE
    BYTE      byRes[32];            //Reserved
    DWORD     dwNodeNum;            //node number
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];   //Description 
}NET_DVR_ABILITY_LIST,  *LPNET_DVR_ABILITY_LIST; 

#define MAX_ABILITYTYPE_NUM  12   //Max. ability set

//Compression parameter capability set 
typedef struct tagNET_DVR_COMPRESSIONCFG_ABILITY
{ 
    DWORD     dwSize;             //Structure length
    DWORD     dwAbilityNum; 		//capability  number
    NET_DVR_ABILITY_LIST struAbilityNode[MAX_ABILITYTYPE_NUM];  //description  
}NET_DVR_COMPRESSIONCFG_ABILITY,  *LPNET_DVR_COMPRESSIONCFG_ABILITY; 


/********************************9000RH begin****************************************/
#define SUPPORT_PD_NUM			16
#define SUPPORT_ARRAY_NUM		8
#define SUPPORT_VD_NUM			128


typedef enum tagRAID_MODE
{
    RAID0 = 1, 
    RAID1, 
    RAID10, 
    RAID1E, 
    RAID5, 
    RAID6, 
    RAID50, 
    JBOD,  
    RAID60
}RAID_MODE; 

typedef enum tagHD_SUPPORT_TYPE
{
    HD_TYPE_SATA    = 0x01, 
    HD_TYPE_PATA    = 0x02, 
    HD_TYPE_SAS     = 0x04, 
    HD_TYPE_ATAPI   = 0x08, 
    HD_TYPE_TAPE    = 0x10, 
    HD_TYPE_SES     = 0x20
}HD_SUPPORT_TYPE; 

// 0-do not support; 1-support
typedef enum tagSUPPORT_RAID_TYPE
{
    RAID0_ABILITY   = 0x0001, 
    RAID1_ABILITY   = 0x0002, 
    RAID10_ABILITY  = 0x0004, 
    RAID1E_ABILITY  = 0x0008, 
    RAID5_ABILITY   = 0x0010, 
    RAID6_ABILITY   = 0x0020, 
    RAID50_ABILITY  = 0x0040, 
    JBOD_ABILITY    = 0x0080, 
    RAID60_ABILITY  = 0x0100
}SUPPORT_RAID_TYPE; 

// Physical HD
typedef struct tagNET_DVR_PHY_DISK_INFO
{
    WORD    wPhySlot;          // HD slot 
    BYTE    byType;          // HD info; 0 -normal, 1-global hot-swap, 2- array hot-swap 3-raid array
    BYTE    byStatus;        // HD status;  1- normal
    BYTE    byMode[40];    // HD type
    DWORD   dwHCapacity;     //  HD capacity (Highest 32bit) Unit:kb
    DWORD   dwLCapacity;     //   HD capacity (Lowest 32bit) 
    BYTE    byArrrayName[MAX_NAMELEN]; 
    WORD    wArrayID;           // Array ID
    BYTE    byRes[102];          // Reserved  
}NET_DVR_PHY_DISK_INFO,  *LPNET_DVR_PHY_DISK_INFO; 

typedef struct tagNET_DVR_PHY_DISK_LIST
{
    DWORD   dwSize; 
    DWORD   dwCount; 
    NET_DVR_PHY_DISK_INFO struPhyDiskInfo[SUPPORT_PD_NUM]; 
}NET_DVR_PHY_DISK_LIST,  *LPNET_DVR_PHY_DISK_LIST; 

typedef enum tagBGA_TYPE
{
    BGA_REBUILD           = 0x01,     // Rebuild
    BGA_CONSISTENCY_FIX   = 0x02,     //Consistency fix
    BGA_CONSISTENCY_CHECK = 0x04,     // Consistency check
    BGA_INIT_QUICK        = 0x08,     // Fast init
    BGA_INIT_BACK         = 0x10,     // Full init 
    BGA_MIGRATION         = 0x20,     // Migration
    BGA_INIT_FORE         = 0x40,     // Init
    BGA_COPYBACK          = 0x80      // Copy back
}BGA_TYPE; 

typedef enum tagBGA_STATE
{
    BGA_STATE_NONE = 0,      //  no bga task
    BGA_STATE_RUNNING,       //  bga is running
    BGA_STATE_ABORTED,       //  bga is aborted
    BGA_STATE_PAUSED       //  bga is pause   
}BGA_STATE;

typedef struct tagNET_DVR_BGA_INFO
{
    BYTE    byBga;   // Background task
    BYTE	byBgaState; 		   /*FunctionReturn- - Background task status*/
    WORD    wBgaPercentage;      /*FunctionReturn- - Background task process in percentage, if it's 65535, pecentage is invalid */
    BYTE    byRes[4];   // Reserved
}NET_DVR_BGA_INFO,  *LPNET_DVR_BGA_INFO; 

// Array info
typedef struct tagNET_DVR_ARRAY_INFO
{
    WORD    wArrayID;  // Array ID
    BYTE    byRaidMode;  //Please refer to RAID_MODE
    BYTE    byStatus;   // 0- on-line; 1- No HD; 2- off-line
    DWORD   dwHCapacity;  // Array capacity (Highest 32 bit)
    DWORD   dwLCapacity;  // Array capacity (Lowest 32 bit)
    DWORD   dwHFreeSpace;    // Array free space  (Highest 32 bit)
    DWORD   dwLFreeSpace;    // Array free space  (Lowest 32 bit)
    BYTE    byArrayName[MAX_NAMELEN];  // Array name
    BYTE    byPDCount;   // Physical HD number
    BYTE    bySpareCount;    // Spare count
    BYTE    byRes1[2]; 
    WORD    wPDSlots[SUPPORT_PD_NUM]; 	// Physical HD index
    WORD    wSparePDSlots[SUPPORT_PD_NUM]; 	// Spare HD index
    NET_DVR_BGA_INFO	struBgaInfo; 	// Background task status
    BYTE    byRes2[80];  // Reserved
}NET_DVR_ARRAY_INFO,  *LPNET_DVR_ARRAY_INFO; 

typedef struct tagNET_DVR_ARRAY_LIST
{
    DWORD   dwSize;      // Structure size
    DWORD   dwCount;     // Array number
    NET_DVR_ARRAY_INFO struArrayInfo[SUPPORT_ARRAY_NUM]; 
}NET_DVR_ARRAY_LIST,  *LPNET_DVR_ARRAY_LIST; 

//Virtual HD info
typedef struct tagNET_DVR_VD_INFO
{
    WORD    wSlot;     //Virtual HD slot
    BYTE    byStatus;  // Status: 0- normal 1- Demote 2- deleted 3- HD not found 4- off-line 5- sub-normal 6- foreign 7-Exception 0xff-not exist
    BYTE    byRaidMode;  // Please refer to RAID_MODE
    WORD    wArrayID;       // array ID
    BYTE    byRepair;   // Need repair  0 -don not need repair 1-need repair
    BYTE    byRes1[1];  // reserved
    BYTE	byArrayName[MAX_NAMELEN]; 
    BYTE    byName[MAX_NAMELEN];     // virtual disk name
    DWORD   dwHCapacity;     // Virtual disk capacity (Highest 32 bit)
    DWORD   dwLCapacity;     //  Virtual disk capacity (lowest 32 bit)
    DWORD   dwHFreeSpace;    //  Virtual disk free space (Highest 32 bit)
    DWORD   dwLFreeSpace;    //  Virtual disk capacity (lowest 32 bit)
    NET_DVR_BGA_INFO	struBgaInfo; 	// Background running status
    BYTE    byRes2[80]; 
}NET_DVR_VD_INFO,  *LPNET_DVR_VD_INFO; 

typedef struct tagNET_DVR_VD_LIST
{
    DWORD   dwSize;      // Structure size
    DWORD   dwCount;     // VD number
    NET_DVR_VD_INFO struVDInfo[SUPPORT_VD_NUM];   //Virtual HD info
}NET_DVR_VD_LIST,  *LPNET_DVR_VD_LIST; 

typedef struct tagNET_DVR_ADAPTER_VERSION
{
    WORD    wMajorVersion; 
    WORD    wMinorVersion; 
    WORD    wRevisionNumber; 
    WORD    wBuildNumber; 
}NET_DVR_ADAPTER_VERSION,  *LPNET_DVR_ADAPTER_VERSION; 

typedef struct tagNET_DVR_VD_SLOT
{
    WORD wVDSlot; 
    BYTE  byAlloc;   // Allocated status
    BYTE    byRes[5]; 
    DWORD dwHVDSlotSize; 	// Virtual disk space  (Highest 32 bit)
    DWORD dwLVDSlotSize; 	//  Virtual disk space  (Lowest 32 bit)
}NET_DVR_VD_SLOT,  *LPNET_DVR_VD_SLOT; 

typedef struct tagNET_DVR_ARRAY_SPACE_ALLOC_INFO
{
    BYTE    byVDSlotCount; 						/*current number of slots in DG*/ 
    BYTE    byRes1[3];               // Reserved
    NET_DVR_VD_SLOT struVDSlots[SUPPORT_VD_NUM]; 
}NET_DVR_ARRAY_SPACE_ALLOC_INFO,  *LPNET_DVR_ARRAY_SPACE_ALLOC_INFO; 

typedef struct tagNET_DVR_RAID_ADAPTER_INFO
{
    DWORD dwSize;     // Structure size
    NET_DVR_ADAPTER_VERSION struVersion; 	// Adapter version
    BYTE    bySlotCount;     //Slot count
    BYTE    bySupportMigrate;   // Migrate (1- support  0- not support) 
    BYTE    bySupportExpand;    // Expand (1- support  0- not support) 
    BYTE    bySupportRebuild;   // Array rebuild  (1- support  0- not support) 
    WORD    wSlotSupportType;  //  HD_SUPPORT_TYPE
    WORD    wSupportRaidType;       // Support RAID type  
    BYTE    byAutoRebuild;       // Auto-rebuild 0-disable  1-enable
    BYTE    byRes[27];       // Reserved
}NET_DVR_RAID_ADAPTER_INFO,  *LPNET_DVR_RAID_ADAPTER_INFO; 

typedef struct tagNET_DVR_OPERATE_ARRAY_PARAM
{
    BYTE    byRaidMode;      // RAID type
    BYTE    byPDCount;   // Physical HD number
    WORD    wArrayID;    // Array ID      
    WORD    wPDSlots[SUPPORT_PD_NUM]; // Physical disk 
    BYTE    byName[MAX_NAMELEN];   // array name
	BYTE    byInitMode;              //init mode
    BYTE    byRes2[19]; 
}NET_DVR_OPERATE_ARRAY_PARAM,  *LPNET_DVR_OPERATE_ARRAY_PARAM; 


typedef struct tagNET_DVR_OPERATE_VD_PARAM
{
    WORD    wArrayID; 		// Array ID
    BYTE    bySlot; 		// Slot for virtual disk
    BYTE    byInitType;     // Type of initialization when creating virtual disk, 0 - fast initialization, 1 - full initialization in foreground, 2 - full initialization in background
    DWORD	dwHCapacity; 	// Virtual disk capacity (Highest 32 bit)
    DWORD	dwLCapacity; 	// Virtual disk capacity (Lowest 32 bit)
    BYTE    byName[MAX_NAMELEN];  // Virtual disk name
    BYTE    byRes2[16];           // Reserved 
}NET_DVR_OPERATE_VD_PARAM,  *LPNET_DVR_OPERATE_VD_PARAM; 


typedef struct tagNET_DVR_SPARE_DISK_PARAM
{
    WORD    wPDSlot;         // Virtual disk slot
    WORD    wArrayID;        // Array
    BYTE    bySpareType;     // Spare type 1- global  2- array
    BYTE    byRes[7];        // Reserved
}NET_DVR_SPARE_DISK_PARAM,  *LPNET_DVR_SPARE_DISK_PARAM; 


/********************************9000RH End****************************************/

#define MATRIX_MAXDECSUBSYSTEMCHAN	4//Decoding system channel number of Video management system's 

//Linkage status for decoding sub system
typedef struct tagNET_DVR_DECSUBSYSTEMJIONSTATUS
{
    BYTE		byJoinStatus; //link status, 0- not linked, 1- linked
    BYTE		byJoinSubSystem; //linked sub system slot number
    BYTE		byJoinDispNum; // display channel number
    BYTE		byJoinSubWindowNum; //sub-window number
    BYTE		byRes[4]; 
}NET_DVR_DECSUBSYSTEMJIONSTATUS, LPNET_DVR_DECSUBSYSTEMJIONSTATUS; 

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO
{
    BYTE	bySubSystemType; //sub-system type, 0- no sub-system, 1- decoding sub-system, 2- encoding sub-system
    BYTE	byRes1[3]; 
    NET_DVR_DECSUBSYSTEMJIONSTATUS struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN]; 
    BYTE  byRes[8]; 
}NET_DVR_SINGLESUBSYSTEMJOININFO, LPNET_DVR_SINGLESUBSYSTEMJOININFO; 

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO
{
    DWORD dwSize; 
    NET_DVR_SINGLESUBSYSTEMJOININFO struSingleSubSystemJoinInfo [MAX_SUBSYSTEM_NUM]; //80
    BYTE  byRes[8]; 
}NET_DVR_ALLDECSUBSYSTEMJOININFO,  *LPNET_DVR_ALLDECSUBSYSTEMJOININFO; 

//2010- 04- 13 NAT configuration
typedef struct tagNET_DVR_NATASSOCIATECFG
{
    DWORD		  		dwSize; 
    NET_DVR_NETCFG_V30  struNatIpAddress[2]; //NAT IP
    BYTE				byNATEnable; //0- disable NAT, 1- enable NAT
    BYTE		  		byRes[63]; 
}NET_DVR_NATASSOCIATECFG,  *LPNET_DVR_NATASSOCIATECFG; 

//2010- 06- 01 Video management system alarm
typedef struct tagNET_DVR_TEMPERATUREALARMCFG
{
    BYTE	 byEnableTemperatureAlarm; //Over temperature alarm: 0- disable, 1- enable
    BYTE	 byRes1[3]; 
    int 	 iTemperatureUpLimited; 	//2 digit after the decimal, i.e. 1234 stands for 12.34 degree
    int 	 iTemperatureDownLimited; 	
    NET_DVR_HANDLEEXCEPTION_V30 struTempHandleType; 	/* handle mode */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];  /*Arm schedule*/
    BYTE	 byRes2[32]; 
}NET_DVR_TEMPERATUREALARMCFG,  *LPNET_DVR_TEMPERATUREALARMCFG; 

typedef struct tagNET_DVR_BOARDALARMCFG
{
    BYTE   byEnablePullAlarm; //hot-swap alarm,  0- disable, 1- enable
    BYTE   byRes1[3]; 
    NET_DVR_HANDLEEXCEPTION_V30 struBoardHandleType; 	/* handle mode */
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];  /*Arm schedule*/
    BYTE   byRes2[32]; 
}NET_DVR_BOARDALARMCFG,  *LPNET_DVR_BOARDALARMCFG; 


typedef struct tagNET_DVR_VIDEOPLATFORMALARMCFG
{
    DWORD 						 dwSize; 
    NET_DVR_TEMPERATUREALARMCFG  struTempAlarmCfg; 	
    NET_DVR_BOARDALARMCFG 		 struBoardAlarmCfg; 	
    NET_DVR_HANDLEEXCEPTION_V30  struHandleException[MAX_EXCEPTIONNUM]; //Exception type: 0- fan 1- sub-system, 2- IP conflict, 3- network disconnect, 4- illegal access
    BYTE						 byRes[32]; 
}NET_DVR_VIDEOPLATFORMALARMCFG, *LPNET_DVR_VIDEOPLATFORMALARMCFG; 
//2010- 05- 17
typedef struct  tagNET_DVR_CODESPLITTERASSOCIATE
{
    DWORD		dwSize; 
    NET_DVR_IPADDR   struIP; 		/*encoder IP*/
    WORD		wPort;         //port number
    BYTE		byRes1[6]; 
    BYTE		sUserName[NAME_LEN]; 	/* user  */
    BYTE		sPassword[PASSWD_LEN]; 	/*password */
    BYTE        byChan; //encoder's Channel number
    BYTE		byRes2[15]; 
} NET_DVR_CODESPLITTERASSOCIATE,  *LPNET_DVR_CODESPLITTERASSOCIATE; 

//2010- 06- 01 Alarm upload for VMS
typedef struct tagNET_DVR_VIDEOPLATFORM_ALRAMINFO
{
    DWORD  dwSize;       //Structure size
    BYTE   byAlarmType; 	// 0- unplug sub-board , 1- plug sub-board , 2- temperature too high, 3- temperature too low, 4- fan exception, 5- sub-system exception 6- illegal access
    BYTE   byRes1[3]; 
    BYTE   bySubSystemChan[8];  //sub-system channel number. There are 8 sub-system for the sub board     
    int    iTemperature;   //Temperature (valid when there is temperature alarm)
    BYTE   byMainboardSeq; // 1- main board, 2-else (valid when there is temperature alarm)
    BYTE   byRes2[3]; 
    BYTE   byFanSequence[32]; //Exception fan number
    BYTE   byRes3[100]; 
}NET_DVR_VIDEOPLATFORM_ALRAMINFO, *LPNET_DVR_VIDEOPLATFORM_ALRAMINFO; 

/*************************** Trial DVR begin *****************************/
#define MAX_INQUEST_PIP_NUM   3     //Picture-split number for the channel
#define MAX_INQUEST_CDRW_NUM  4     //Max. CD/DVD writer number

typedef struct 
{
    DWORD      dwSize; 
    DWORD      dwNum;                        //CD/DVD writer number
    DWORD      dwRwSelectPara[MAX_CHANNUM_V30]; // Select the CD/DVD writer
    DWORD      dwModeSelect;                 //0-cycle mode 1-Parallel mode (default) 
    BYTE	   byRes[24];                    //Reserved
    DWORD	   dwStartCDRW;                  //DVR local writing started
    DWORD      dwHdExcp;                     //HD exception
    DWORD	   dwInterval;                   //Time interval, 0-10 min, 1- 20 min , 2- 30 min 
    char 	   sLable[64];                   //Disc number
}NET_DVR_INQUEST_CDRW_CFG,  *LPNET_DVR_INQUEST_CDRW_CFG;

typedef struct
{
    char      sFileName[36]; 			 //file name
    DWORD     dwFileLen; 				 //file length
}NET_DVR_INQUEST_FILEINFO,  *LPNET_DVR_INQUEST_FILEINFO; 

typedef struct 
{
    DWORD     dwFileNum; 			         // Delete or copy file number, Max.20
    NET_DVR_INQUEST_FILEINFO struFileInfo[MAX_RECORD_FILE_NUM]; 
    //For CD/DVD writing
    DWORD     dwCDIndex; 				    //CD/DVD writer index : 1: 1st CD/DVD writer; 2: 2nd CD/DVD writer;  3: 3rd CD/DVD writer, 4: 4th CD/DVD writer, 5: all
    BOOL      bFinalizeDisc; 		     	// Finalize the CD/DVD after writing finished: 0-disable; 1-enable
}NET_DVR_INQUEST_FILES,  *LPNET_DVR_INQUEST_FILES; 

typedef struct {	
	DWORD     dwEnable;			//0-Invalid,1-Valid	
	DWORD     dwStatus;			/* when dwType=0,
								0-CD Normal, 1-No CD or CD Exception,
								  when dwType=1 or 2,
								0-Normal, 1-No CD or CD Exception,
								2-CD is covered(81not support), 3-CD low space,
								4-Exception caused Inquest stop(81not support)
								when dwType=3, 
								0-Normal, 1-No CD or CD Exception, 
								2-CD is covered(81not support), 3-CD low space,
								when dwType=4,
								0-Normal, 1-No CD or CD Exception, 
								2-CD is covered(81not support), 3-CD low space, 
								when dwType=5,
								0-Normal, 1-No CD or CD Exception,
								2-CD is covered(81not support)
								when dwType=6 or 7,
								0-Normal, 1-No CD or CD Exception,
								2-CD is covered(81not support), 3-CD low space*/		
	DWORD    dwVolumn;			//Disk volume, M
	DWORD    dwFreeSpace;		//Disk free space,M    
	BYTE     byRes[8];			//Reserved
}NET_DVR_INQUEST_CDRW, *LPNET_DVR_INQUEST_CDRW;

typedef struct {	
	DWORD    dwType;         /*State: 0-Inquest begin,
							 1-CD write while inquest, 2-Inquest stop,
							 3-Write inquest file, 
							 4-Backup
							 5-Empty
							 6-Initialize hard disk
							 7-Resume inquest event*/	
	NET_DVR_INQUEST_CDRW   strCDRWNum[MAX_INQUEST_CDRW_NUM]; 	
	BYTE     byRes[24];      //Reserved	
}NET_DVR_INQUEST_CDRW_STATUS, *LPNET_DVR_INQUEST_CDRW_STATUS;

typedef struct
{
    BYTE     byPipChan; 			  //channel of picture-in-picture mode, 0xFF-close
    BYTE     byRes[3]; 			  //Reserved
    WORD     wTopLeftX; 			  //X coordinate of picture-in-picture 
    WORD     wTopLeftY; 			  //Y coordinate of picture-in-picture 
}NET_DVR_INQUEST_PIP_PARAM,  *LPNET_DVR_INQUEST_PIP_PARAM; 

typedef struct 
{
    BYTE     byBaseChan;           //Display channel of picture-in-picture mode
    BYTE     byBackChan;           //Display background channel of picture-in-picture mode
    BYTE     byPIPMode;            //picture-in-picture mode,  0-disable; 1-enable
    BYTE     byRes;                //Reserved
    NET_DVR_INQUEST_PIP_PARAM  strPipPara[MAX_INQUEST_PIP_NUM];   //position 
}NET_DVR_INQUEST_PIP_STATUS,  *LPNET_DVR_INQUEST_PIP_STATUS; 

typedef struct 
{
    BYTE	sSecretKey[16];         //secrete key
    BYTE	byRes[64];              /*Reserved*/
}NET_DVR_INQUEST_SECRET_INFO,  *LPNET_DVR_INQUEST_SECRET_INFO; 

/***************************DVR end *****************************/
/********************************Interface Parameter Structure (end) *********************************/


/************************************************************************/
#define MAX_ALARMHOST_ALARMIN_NUM	        512 //Max number of alarm host alarm input ports
#define MAX_ALARMHOST_ALARMOUT_NUM	        512 //Max number of alarm host alarm output ports
#define ALARMHOST_MAX_AUDIOOUT_NUM		    32  //Max number of alarm host audio output ports
#define ALARMHOST_MAX_ELECTROLOCK_NUM		32  //Max number of alarm host electric locks
#define ALARMHOST_MAX_MOBILEGATE_NUM		32  //Max number of alarm host mobile gate
#define ALARMHOST_MAX_SIREN_NUM             8   //Max number of sirens 
#define MAX_ALARMHOST_SUBSYSTEM             32// Max number of subsystem

typedef enum tagSENSOR_TYPE
{
	SENSOR_TYPE_NONE = 0,        //None
	SENSOR_TYPE_TEMPERATURE = 1, //Temperature
	SENSOR_TYPE_HUMIDITY ,       //Humidity
	SENSOR_TYPE_WINDSPEED,       //Wind speed
	SENSOR_TYPE_GAS,             //Gas
	SENSOR_TYPE_UNKNOW = 255     //Undefined
}SENSOR_TYPE;

typedef struct tagNET_DVR_SENSOR_INFO
{
	DWORD   dwSize;                  //Structure size
	BYTE    byName[NAME_LEN];       //Sensor name
	BYTE    byEnable;               //Enable or not 
	BYTE    byValid;                //Valid or not, sensor is normal or abnormal(read-only) 
	BYTE    byType;                 //Type
	BYTE	byAlarmMode;            //Alarm mode, five kinds: 15-HHHH, 14-HHHL, 12-HHLL, 8-HLLL, 0-LLLL,
	                                //that is, 1111(UP UP UP UP), 1110(UP UP UP DOWN), 1100(UP UP DOWN DOWN), 1000(UP DOWN DOWN DOWN), 0000(DOWN DOWN DOWN DOWN)
	float   fMeasureHigh;           //Upper limit of measuring range
	float   fMeasureLow;            //Lower limit of measuring range
	//Alarm limit 1-4, increases in turn
	float	fAlarm1;           //Alarm limit 1
	float	fAlarm2;           //Alarm limit 2
	float	fAlarm3;           //Alarm limit 3
	float	fAlarm4;           //Alarm limit 4
	DWORD   dwOsdCfg;          //Analog OSD, indicated by bit, 0-15 corresponds to video channel 1-16
	float	fSensitive;		   //Sensitivity
	BYTE    byRes3[116];       // Reserved
}NET_DVR_SENSOR_INFO, *LPNET_DVR_SENSOR_INFO;

typedef struct tagNET_DVR_SIREN_PARAM
{
	DWORD   dwSize;             //Structure size
    BYTE    byName[NAME_LEN];   //Name
	WORD    wDelay;             //Output delay, unit: s, 0 means output all the time
    BYTE	byRes1[2];
    BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //Alarm input channel followed by siren(multi alarm inputs trigger one siren output)
	                            //Subscript 0 means alarm input 1, 0- not follow, 1- follow
    BYTE    byRes2[68];         //Reserved
}NET_DVR_SIREN_PARAM, *LPNET_DVR_SIREN_PARAM;

typedef struct tagNET_DVR_AIR_CONDITION_PARAM
{
	DWORD	dwSize;		    //Structure size
	BYTE	byEnable;	    //0- open, 1- shutdown
	BYTE	byMode;		    //Air conditioning mode
	BYTE	byTemperature;	//Temperature, general value is 16-30°
	BYTE	byRes[9];		//Reserved
}NET_DVR_AIR_CONDITION_PARAM, *LPNET_DVR_AIR_CONDITION_PARAM;

typedef enum tagDETECTOR_TYPE
{
    PANIC_BUTTON = 0,               //Panic button
    MAGNETIC_CONTACT,               //Magnetic contact
    SMOKE_DETECTOR,                 //Smoke detector
    ACTIVE_INFRARED_DETECTOR,       //Active infrared detector 
    PASSIVE_INFRARED_DETECTOR,      //Passive infrared detector 
    GLASS_BREAK_DETECTOR,           //Glass break detector
    VIBRATION_DETECTOR,             //Vibration detector
    DUAL_TECHNOLOGY_PIR_DETECTOR,   //Dual technology motion detector
    TRIPLE_TECHNOLOGY_PIR_DETECTOR, //Triple technology detector
    HUMIDITY_DETECTOR,              //Humidity detector
    TEMPERATURE_DETECTOR,           //Temperature detector
    COMBUSTIBLE_GAS_DETECTOR,       //Combustible gas detector
    OTHER_DETECTOR = 0xffff         //Other detector 
}DETECTOR_TYPE;

typedef struct tagNET_DVR_ALARMIN_PARAM
{
	DWORD   dwSize;
	BYTE    byName[NAME_LEN];
	WORD    wDetectorType; //see to DETECTOR_TYPE
	BYTE    byType;        //Alarm in type,0: immediately alarm in,1-24hour audible alarm in,2-delay alarm in ,3-inside alarm in，4-key alarm in 5-Fire alarm in 6-perimeter Alarm in 7. 24-hour silent alarm in 0xff-no Alarm in
	BYTE    byRes1;    
	DWORD	dwParam;       //Area parameter, the delay time of delay area 
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];/*Time period of fortification*/
	BYTE    byAssociateAlarmOut[MAX_ALARMHOST_ALARMOUT_NUM];  //Alarm output channel associated with the alarm input
    BYTE	byAssociateSirenOut[8];		//Siren output, subscript 0 means siren NO.1, the value equals to 1 means output, 0 means not output
	BYTE	bySensitivityParam;//Sensitivity parameter, 0-10ms、1-250ms、2-500ms、3-750ms
    BYTE	byArrayBypass; //0-not support bypass,1-support bypass
    BYTE    byRes[50];      // res
}NET_DVR_ALARMIN_PARAM, *LPNET_DVR_ALARMIN_PARAM;

typedef struct tagNET_DVR_ALARMOUT_PARAM
{
	DWORD   dwSize;             //Structure size
	BYTE    byName[NAME_LEN];   //Name
	WORD    wDelay;             //Output delay, unit: s, 0 means output all the time
	BYTE    byRes1[2];          // Reserved
	BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //Alarm input channel followed by siren(multi alarm inputs trigger one siren output)
	                            //Subscript 0 means alarm input 1, 0- not follow, 1- follow
    BYTE    byRes2[60]; 
}NET_DVR_ALARMOUT_PARAM, *LPNET_DVR_ALARMOUT_PARAM;

typedef struct tagNET_DVR_ALARMIN_SETUP
{
    BYTE byAssiciateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];//Alarm input channel, subscript 0 corresponds to channel NO.1
    BYTE byRes[100];//Reserved
}NET_DVR_ALARMIN_SETUP, *LPNET_DVR_ALARMIN_SETUP;

typedef struct tagNET_DVR_ALARMHOST_MAIN_STATUS
{
	DWORD  dwSize; 
	BYTE   bySetupAlarmStatus[MAX_ALARMHOST_ALARMIN_NUM];   //Arming status of alarm input port(support to query max 512 alarm input ports), 0- disarmed, 1- armed
	BYTE   byAlarmInStatus[MAX_ALARMHOST_ALARMIN_NUM];      //Alarm status of alarm input port(support to query max 512 alarm input ports), 0- without alarm, 1- with alarm
	BYTE   byAlarmOutStatus[MAX_ALARMHOST_ALARMOUT_NUM];    //Status of alarm output port(support to query max 512 alarm output ports), 0- without alarm, 1- with alarm
	BYTE   byBypassStatus[MAX_ALARMHOST_ALARMIN_NUM];       //Bypass status
	BYTE   bySubSystemGuardStatus[MAX_ALARMHOST_SUBSYSTEM]; //subsystem status, 0-close state，1-setup state
    BYTE   byRes[568]; 
}NET_DVR_ALARMHOST_MAIN_STATUS, *LPNET_DVR_ALARMHOST_MAIN_STATUS;

typedef struct tagNET_DVR_ALARMHOST_OTHER_STATUS
{
	DWORD  dwSize;
    BYTE   bySirenStatus[ALARMHOST_MAX_SIREN_NUM];    //Siren output status, 0- in the status without alarm, 1- in the status with alarm
    BYTE   byRes[92];             // Reserved
}NET_DVR_ALARMHOST_OTHER_STATUS, *LPNET_DVR_ALARMHOST_OTHER_STATUS;

//Enable status configuration
typedef struct tagNET_DVR_ALARMHOST_ENABLECFG
{
	DWORD dwSize;
	BYTE  byAudioOutEnable[ALARMHOST_MAX_AUDIOOUT_NUM];//Enable audio output or not, 0- disable, 1- enable
	BYTE  byElectroLockEnable[ALARMHOST_MAX_ELECTROLOCK_NUM];//Enable electronic lock or not, 0- disable, 1- enable
	BYTE  byMobileGateEnable[ALARMHOST_MAX_MOBILEGATE_NUM];//Enable mobile gateway or not, 0- disable, 1- enable
	BYTE  bySirenEnable[ALARMHOST_MAX_SIREN_NUM];//Enable siren or not, 0- disable, 1- enable
	BYTE  bySerialPurpose;//Serial purpose, 0- used to cascade with alarm host, 1- used to PTZ control
	BYTE  byRes[63];	
}NET_DVR_ALARMHOST_ENABLECFG, *LPNET_DVR_ALARMHOST_ENABLECFG;

typedef struct tagNET_DVR_ALARMHOST_ABILITY
{
	DWORD   dwSize;					//Structure size
	WORD    wTotalAlarmInNum;       //Total number of alarm input ports(alarm areas), including cascade
	WORD    wLocalAlarmInNum;       //Total number of local alarm input ports
	WORD    wExpandAlarmInNum;      //Total number of expandable alarm input ports
	WORD    wTotalAlarmOutNum;      //Total number of alarm output ports(supported by device)
	WORD    wLocalAlarmOutNum;      //Total number of local alarm output ports
	WORD    wExpandAlarmOutNum;     //Total number of expandable alarm output ports
	WORD    wTotalRs485Num;         //Total number of RS-485 ports(supported by device)
	WORD    wLocalRs485Num;         //Total number of local RS-485 ports
	WORD    wExpandRs485Num;        //Total number of expandable RS-485 ports
	WORD	wFullDuplexRs485Num;    //Total number of full duplex RS-485 ports
	WORD    wTotalSensorNum;        //Total number of analog(supported by device)
	WORD	wLocalSensorNum;		//Total number of local analog
	WORD    wExpandSensorNum;       //Total number of expandable local analog
	WORD    wAudioOutNum;			//Total number of audio outputs
	WORD    wGatewayNum;			//Total number of mobile gateways
	WORD    wElectroLockNum;		//Total number of electronic locks
	WORD    wSirenNum;     			//Total number of sirens
	WORD    wSubSystemNum;			//Total number of divided subsystems
    WORD    wNetUserNum;            //Total number of network users
    WORD    wKeyboardUserNum;       //Total number of keyboard users
    WORD    wOperatorUserNum;       //Total number of operator users

	BYTE    bySupportDetector;		//Is support detector，1-support，0-not support
    BYTE    bySupportSensitivity;   //Is support sensitivity，1-support，0-not support
    BYTE    bySupportArrayBypass;   //Is support array Bypass，1-support，0-not support
    BYTE    bySupportAlarmInDelay;  //Is support alarm in delay,1-support，0-not support
    BYTE    bySupportAlarmInType[16];//Alarm in type,0: immediately alarm in,1-24hour audible alarm in,2-delay alarm in ,3-inside alarm in，4-key alarm in 5-Fire alarm in 6-perimeter Alarm in 7. 24-hour silent alarm in 15-no
	BYTE	byTelNum;		        //Total number of telephone
	BYTE	byCenterGroupNum;	    //Total number of center group number
	BYTE	byGPRSNum;		        //Total number of GPRS number ,the max number is 4
	BYTE	byNetNum;		        //Total number of net number ,the max number is 4
	BYTE	byAudioNum;				//Total Audio number
	BYTE	by3GNum;				//Total 3G module number
    WORD    wRes[73];				//Reserved
}NET_DVR_ALARMHOST_ABILITY, *LPNET_DVR_ALARMHOST_ABILITY;


typedef struct tagNET_DVR_ALARM_RS485CFG
{
	DWORD   dwSize;                 //Structure size
	BYTE    sDeviceName[NAME_LEN];  //Front-end device name 
	WORD    wDeviceType;            //Device type, see to ALARM_FRONT_DEVICE _TYPE
	WORD    wDeviceProtocol;        //Device protocol, got from protocol list	
	DWORD   dwBaudRate;             //Baud rate(bps), 0- 50, 1- 75, 2- 110, 3- 150, 4- 300, 5- 600, 6-1200, 7- 2400, 
                                  	//8- 4800, 9- 9600, 10- 19200, 11- 38400, 12- 57600, 13- 76800, 14-115.2k 
	BYTE    byDataBit;              //Data bit: 0- 5 bit, 1- 6 bit, 2- 7 bit, 3- 8 bit 
	BYTE    byStopBit;              //Stop bit: 0- 1 bit, 1- 2bit 
	BYTE    byParity;               //Parity or not: 0- no parity, 1- odd parity, 2- even parity 
	BYTE    byFlowcontrol;          //Flow control or not: 0- none, 1- soft flow control, 2- hard flow control 
	BYTE	byDuplex;				//0 - half-duplex, 1- full-duplex, only channel no.1 supports full duplex, others support half duplex only
    BYTE    byWorkMode;				//work mode, 0- console, 1- transparent channel
    BYTE    byRes[38];              // Reserved
}NET_DVR_ALARM_RS485CFG, *LPNET_DVR_ALARM_RS485CFG;

#define MAX_DEVICE_PROTO_NUM       256
#define MAX_DEVICE_TYPE_NUM			256

// Protocol list supported by RS-485 front-end device
typedef struct tagNET_DVR_DEVICE_PROTO_LIST
{
    DWORD   dwSize;             //Structure size
    DWORD   dwProtoNum;         //Total number of protocol
    NET_DVR_PROTO_TYPE struProtoType[MAX_DEVICE_PROTO_NUM];  //Protocol type
    BYTE    byRes[12];          // Reserved
}NET_DVR_DEVICE_PROTO_LIST, *LPNET_DVR_DEVICE_PROTO_LIST;

typedef struct tagNET_DVR_DEVICE_TYPE
{
	DWORD	dwType;
	BYTE	byDescribe[DESC_LEN];
}NET_DVR_DEVICE_TYPE, *LPNET_DVR_DEVICE_TYPE;

typedef struct tagNET_DVR_DEVICE_TYPE_LIST
{
	DWORD	dwSize;				//Structure size
	DWORD	dwTypeNum;			//Total number of types
	NET_DVR_DEVICE_TYPE struDeviceType[MAX_DEVICE_TYPE_NUM];
	BYTE	byRes[12];
}NET_DVR_DEVICE_TYPE_LIST, *LPNET_DVR_DEVICE_TYPE_LIST;

#define ALARMHOST_ABILITY     0x500 //Network alarm host ability


typedef struct tagNET_DVR_ALARM_DEVICE_USER
{
	DWORD  dwSize;                  //Structure size
	BYTE   sUserName[NAME_LEN];     //User name
	BYTE	sPassword[PASSWD_LEN];	//Password
    NET_DVR_IPADDR	struUserIP;		//User IP (0 stands for no IP restriction) 
    BYTE	byMACAddr[MACADDR_LEN];	//MAC
    BYTE	    byUserType;         //0- general user, 1- administrator user
	BYTE   byAlarmOnRight;          //Arming authority
	BYTE   byAlarmOffRight;         //Disarming authority
	BYTE   byBypassRight;           //Bypass authority
	BYTE   byOtherRight[MAX_RIGHT]; //Other authority 
	// Array 0  Log authority
	// Array 1  Reboot and shutdown
	// Array 2  Parameter setting 
	// Array 3  Get parameter
	// Array 4  Reset to default 
	// Array 5  Siren output authority
	// Array 6  PTZ control authority (used by matrix) 
    // Array 7  Remote upgrade
    BYTE	byRes2[200];              // Reserved
}NET_DVR_ALARM_DEVICE_USER, *LPNET_DVR_ALARM_DEVICE_USER;


typedef struct tagNET_DVR_KEYBOARD_USER
{
	DWORD 	dwSize; 	//Structure size
	DWORD	dwID;		//Keyboard user ID
	BYTE	byDefanceArea[MAX_ALARMHOST_ALARMIN_NUM]; //Area authority, indicated by subscript, it supports max 512 areas. 0 - no authority, 1 - privileged
	BYTE	byRes[560];		// Reserved
}NET_DVR_KEYBOARD_USER, *LPNET_DVR_KEYBOARD_USER;


typedef struct tagNET_DVR_OPERATE_USER
{
	DWORD	dwSize;		
	BYTE    sUserName[NAME_LEN];    // UserName
    BYTE    sPassword[PASSWD_LEN];  // Password
    BYTE    bySubSystemPermission;
    BYTE    byRes[63];              // res
}NET_DVR_OPERATE_USER, *LPNET_DVR_OPERATE_USER;

typedef struct tagNET_DVR_GATEWAY_CFG
{
    DWORD	dwSize;		        //Structure size
    BYTE	byName[NAME_LEN];	//Access control name	
    BYTE	byEnable;	        //Enable or not
    BYTE    byLocalEnable;      //Disabled or enabled in local
    WORD    wDelayTime;	        //Delay time of opening, unit:s, value range: 0-65535, 0 means open all the time
	BYTE	byLockWorkMode;		//lock work mode，0- start when power on，1- start when power off
    BYTE	byRes2[31];	        // Reserved
}NET_DVR_GATEWAY_CFG, *LPNET_DVR_GATEWAY_CFG;

typedef struct tagNET_DVR_SENSOR_ALARM
{
    DWORD dwSize;		//Structure size
    DWORD dwAbsTime;	//Absolute time, OSD display information
    
    BYTE   byName[NAME_LEN];   //Analog name
    BYTE   bySensorChannel;    //Analog channel
    BYTE   byType;             //Analog type
    BYTE	byAlarmType;	   //1- UP4, 2- UP3, 3- UP2, 4- UP1, 5- DOWN1, 6- DOWN2, 7- DOWN3, 8- DOWN4, related to current mode
                               //E.g. when it equals to 1000, there are four alarm types: UP1 and DOWN1,2,3.
    BYTE	byAlarmMode;       //Alarm mode, five kinds: -HHHH, -HHHL, -HHLL, HLLL, -LLLL, used to judge function alarm level for platform
    //That is: 1111(UP UP UP UP), 1110(UP UP UP DOWM), 1100(UP UP DOWM DOWM), 1000(UP DOWM DOWM DOWM), 0000(DOWM DOWM DOWM DOWM)
    float		fValue;		   // Current analog value
    BYTE	byRes2[32];		   // Reserved
}NET_DVR_SENSOR_ALARM, *LPNET_DVR_SENSOR_ALARM;
typedef struct 
{
    /*Reserved,currently alarm of alarm host has no type(fortification network sequence, listening host sequence)*/
    DWORD  dwAlarmType;             
    /*Array 0 is corresponding to NO.1 input pot*/
    BYTE   byAlarmInputNumber[MAX_ALARMHOST_ALARMIN_NUM];
    BYTE	byRes[160];
}NET_DVR_ALARMHOST_ALARMINFO,*LPNET_DVR_ALARMHOST_ALARMINFO;

//Switch alarm upload
typedef struct tagNET_DVR_TIME_EX
{
	WORD wYear;
	BYTE byMonth;
	BYTE byDay;
	BYTE byHour;
	BYTE byMinute;
	BYTE bySecond;
	BYTE byRes;
}NET_DVR_TIME_EX,*LPNET_DVR_TIME_EX;

typedef struct tagNET_DVR_SWITCH_ALARM
{
    DWORD dwSize;
    BYTE   byName[NAME_LEN]; 	//Switch name
    WORD  wSwitchChannel;       //Switch channel
    BYTE	byAlarmType;		//Alarm type
	BYTE	byEventType;		//Event type 0-alarm，1-defense area fault
    DWORD  dwRelativeTime;		//relative time
    NET_DVR_TIME_EX struOperateTime; 
    BYTE 	byRes[28];			//Reserved
}NET_DVR_SWITCH_ALARM, *LPNET_DVR_SWITCH_ALARM;

typedef union tagNET_DVR_ALARMHOST_EXCEPTION_PARAM
{
    DWORD   dwUnionSize[20];        //Union size    
}NET_DVR_ALARMHOST_EXCEPTION_PARAM, *LPNET_DVR_ALARMHOST_EXCEPTION_PARAM;


typedef struct tagNET_DVR_ALARMHOST_EXCEPTION_ALARM
{
    DWORD   dwSize;             // structure size
	//Exception parameter, 1- device tamper alarm, 2- resume to normal after device tamper, 3- alarm of major power off, 4- resume after major power off
	//5- internal communication failure alarm, 6- resume after internal communication failure, 7- telephone line dropped,
	//8- resume telephone line dropped, 9- self-test failure alarm,  10- resume after self-test failure   11-storage battery low voltage 
	//12- voltage of storage battery resume 13- storage battery trouble 14- MBUS module dropped 15-MBUS module dropped resume 16-keyboard dropped 17-keyboard dropped resume
	//18-device moved, 19-device moved resume, 20-485 peripheral circuit broken alarm, 21-resume after peripheral circuit broken
    DWORD   dwExceptionType;    
    NET_DVR_ALARMHOST_EXCEPTION_PARAM uExceptionParam;
    DWORD  dwRelativeTime;  
    NET_DVR_TIME_EX struOperateTime; 
    BYTE   byRes[4];          // reserved
}NET_DVR_ALARMHOST_EXCEPTION_ALARM, *LPNET_DVR_ALARMHOST_EXCEPTION_ALARM;

//
#define MAX_CENTERNUM			    4		//G1,G2 G3 G4 or N1，N2，N3，N4 or T1，T2，T3，T4
#define MAX_PHONE_NUM		        32
typedef struct tagNET_DVR_PHONECENTERDIALCFG
{
    BYTE sCenterName[NAME_LEN];
    BYTE byPhoneNum[MAX_PHONE_NUM/*32*/];  //center number  
    BYTE byRepeatCall;          //time of repeat call ，1~15times
    BYTE byPstnProtocol;        //protocol，0-CID；
    BYTE byDialDelay;           //time of dial delay, max time is 150s
    BYTE byPstnTransMode;       //trans mode，0-DTMF 5/S，1-DTMF 10/S；
    BYTE byRes1[6];
    BYTE byReceiverId[6];     	//receive account ID；
    BYTE byRes2[32];
}NET_DVR_PHONECENTERDIALCFG, *LPNET_DVR_PHONECENTERDIALCFG;

typedef struct tagNET_DVR_ALARMHOSTDIALCFG
{
    DWORD dwSize;
    NET_DVR_PHONECENTERDIALCFG struPhoneCenterParam[MAX_CENTERNUM];//parameter of center 
	WORD wReportPeriod;      //period of report:hour (max period is 168 hour)
	WORD wFirstReportTime;	 //the time of sending first report，1~3600min
	BYTE  byReportValid;	//turn on the report mode 0-valid 1-invalidation
    BYTE  byRes[19];
}NET_DVR_ALARMHOSTDIALCFG, *LPNET_DVR_ALARMHOSTDIALCFG;

typedef struct _tagNET_DVR_ALARMHOSTDIALSETUPMODE
{
	DWORD dwSize;
	BYTE byEnableMode;//enable mode 0：close，1：open ，2:open while the net is cutted down，close while natural；
    BYTE byCallType; //report mode，1-one center，2-two centers，3，one is main center and the other is standby
    BYTE byRes1[14];
}NET_DVR_ALARMHOSTDIALSETUPMODE, *LPNET_DVR_ALARMHOSTDIALSETUPMODE;

#define  MAX_ALARM_CAM_NUM	32		// Total number of alarm triggered CAMs

typedef struct tagNET_DVR_PTZ_CTRL
{
    BYTE    byEnable;   //Enable PTZ control or not
    BYTE    byType;     //PTZ control type: 1- preset, 2- cruise  3- track
    BYTE    byPtzNo;    //Preset, cruise, or track number of PTZ control
    BYTE    byRes[5];   //Reserved
}NET_DVR_PTZ_CTRL, *LPNET_DVR_PTZ_CTRL;

typedef struct tagNET_DVR_ALARM_CAM_INFO
{
    DWORD			dwCamID;         //Operation of triggered CAM channel
    DWORD           dwRecordTime;    //Triggered record time, unit: s, -1- continuously record, 0- do not record
    DWORD           dwMonID;         //Trigger Cam to Mon display
    DWORD           dwResidentTime;  //Polling stay time, unit: s  -1- continuously stay, 0- do not stay
    NET_DVR_PTZ_CTRL    struPtzCtrl; //PTZ control information
    BYTE			byAlarmOffMode;  //Canceling mode of alarm switching to the wall, 0- cancel immediately, 1- cancel automatically, 2- cancel manually
    BYTE            byDevType;		 //When it is intelligent device, valid means stream resource of intelligent alarmer: 1- decode card, 2- encode card
    BYTE            byDecChan;		 //When the channel is decoding channel, it is decoding channel number
    BYTE            byRes[17];       //Reserved
}NET_DVR_ALARM_CAM_INFO, *LPNET_DVR_ALARM_CAM_INFO;

typedef struct tagNET_DVR_ALARM_CAM_CFG
{
    DWORD		dwSize;			//Structure size
    BYTE        byEnable;       //Enable alarm triggering CAM interaction or not, default: disabled
    BYTE        byRes[7];       //Reserved
    DWORD		dwNum;			//The number of triggering CAM interaction, that is, take the first few data of array to handle  
    NET_DVR_ALARM_CAM_INFO struAlarmCam[MAX_ALARM_CAM_NUM];
}NET_DVR_ALARM_CAM_CFG, *LPNET_DVR_ALARM_CAM_CFG;

#define MAX_GATEWAY_NUM 		8  // max gateway num
typedef struct _tagNET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM
{
	DWORD 		dwSize;
	BYTE		byEnterDoor[8];	// Subscript is number of enter door, the value is assiociate information，0-not associated， 1-8 is the audio index of associated
	BYTE		byExitDoor[8]; 	//  Subscript is number of exit door, the value is assiociate information，0-not associated， 1-8 is the audio index of associated
	BYTE 		byAlarmIn[MAX_ALARMHOST_ALARMIN_NUM/*512*/];  // Subscript is number of alarm in, the value is assiociate information，0-not associated， 1-8 is the audio index of associated
	BYTE 		byRes[128];
}NET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM, *LPNET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM;

typedef struct tagNET_DVR_UPLOAD_PARAM
{
	DWORD 		dwSize;
	BYTE		byUploadType;	/*Upload type，1-get data by reading file， 2-get data from buffer*/
	BYTE		byDataType;		//data type：1-audio type
	BYTE		byDataNum;		//data index
	BYTE		byAudioType;		//audio type，0-wave
	char		sFileName[260];		//path of data file
	char		*lpBuffer;			//data buffer
	DWORD		dwBufferSize;		//length of the buffer
	BYTE		byRes2[128];
}NET_DVR_UPLOAD_PARAM, *LPNET_DVR_UPLOAD_PARAM;

typedef void (CALLBACK *DATADOWNLOAD)(LONG nDownloadHandle, DWORD dwDataType, void* pBuffer, DWORD dwBufSize, void *pUser);
typedef struct tagNET_DVR_DOWNLOAD_PARAM
{
	DWORD 		dwSize;
	BYTE		byDownType;		/*type of saving data，1-save data to the file by path， 2-get data by callaback function*/
	BYTE		byDataType;		//data type：1-audio type
	BYTE		byDataNum;		//data index
	BYTE		byRes1;
	char		sFileName[260];		//path of file
	DATADOWNLOAD lpDataCallBack; //handle of callback function
	void*		pUserData;	//user data
	BYTE		byRes2[128];
}NET_DVR_DOWNLOAD_PARAM, *LPNET_DVR_DOWNLOAD_PARAM;


/*************************************SELF SERVICE BANK V2.0 begin***********************************/
typedef  struct tagNET_DVR_LED_SCREEN_CFG
{
	DWORD 		dwSize;
	BYTE		sLEDName[NAME_LEN/*32*/];	// LED Screen name
	BYTE		byTransMode; 				//  1-seiral port communication
	BYTE		byProtocolType;				// protocol type，LED factories
	BYTE		byLEDColor; 				// 1-one color， 2-two-color， 3-256 grayscale dual color， 4- Full-color
	BYTE		byDataPolarity;				// Data polarity .0-Negative electrode，1-positive electrode
	BYTE		byOEPolarity;				// 0-Active-low 1-Active-high
	BYTE		byScanMode; 				// 1-1/16,  2-1/8,  3-1/4,  4-1/2,  5-static
	BYTE		byRes1[2];
	//Minimum width and height is 16*16，interval is 8 points	
	WORD		wLEDWidth;	 				// 16~2048
	WORD 		wLEDHeight;					// 16~2048
	BYTE		byRes2[64];
}NET_DVR_LED_SCREEN_CFG, *LPNET_DVR_LED_SCREEN_CFG;


#define  MAX_CONTENT_LEN  512
typedef  struct tagNET_DVR_LED_CONTENT_CFG
{
	DWORD 		dwSize;
	BYTE		sLEDContent[MAX_CONTENT_LEN];	// LED content
	BYTE		byContentAct;					// 1-static，2-Quick play，3-Move to the left，4-Move to the right， 5-Move up， 6-Move down
	BYTE		byContentSpeed;					// 1-24（1-The fastest，24-The slowest）	
	BYTE		byContentStayTime; 				// 0-127.5s(Accuracy 0.5s， SDK will Multiply 2 when transmission
	BYTE		byRes[33];
}NET_DVR_LED_CONTENT_CFG, *LPNET_DVR_LED_CONTENT_CFG;

#define 	LED_TIMER_NUM 			3			// LED time which use for turn on and turn off
#define		TIME_SEGMENT_A_DAY		48			// segment in a day , every half hour is a segment

typedef struct tagNET_DVR_SWITCH_TIME
{
	BYTE	byValid;				// enable or disable, time is use in a time-group
	BYTE	byRes[3];
	NET_DVR_TIME_EX struTimeOn; 	// time of turn on
	NET_DVR_TIME_EX struTimeOff; 	// time of turn off
}NET_DVR_SWITCH_TIME, *LPNET_DVR_SWITCH_TIME;


typedef struct tagNET_DVR_LED_SWITCH_TIME
{
	DWORD		dwSize;//time of Timer switch,the  parameter byHour and byMinute is valid, the other parameters is invalid. boot time should earlier than off time
	NET_DVR_SWITCH_TIME  	struTimer[LED_TIMER_NUM /*3*/];
	BYTE		byRes[64];
}NET_DVR_LED_SWITCH_TIME, *LPNET_DVR_LED_SWITCH_TIME;

typedef struct tagNET_DVR_LED_BRIGHTNESS_STEP
{
	DWORD 		dwSize;
	BYTE		byValid;		//use for Time-sharing brightness adjustment
	BYTE		byRes1[3];
	BYTE 		byBrightnessStep[TIME_SEGMENT_A_DAY /*48*/]; 	//total levels is 16，0~15
	BYTE		byRes2[48];
}NET_DVR_LED_BRIGHTNESS_STEP, *LPNET_DVR_LED_BRIGHTNESS_STEP;

typedef struct tagNET_DVR_LED_STATUS
{
	DWORD	dwSize;
	BYTE	bySwitchState;		//1-status of turn on 2-status of turn off
	BYTE	byBrightness;		//brightness，0-15
	BYTE	byRes[62];
}NET_DVR_LED_STATUS, *LPNET_DVR_LED_STATUS;

/*************************************SELF SERVICE BANK V2.0 end***********************************/
/************************************************************************/
/*********************************9000 2.0 begin***************************************/

//Mode A 
typedef struct tagNET_DVR_HOLIDATE_MODEA
{
    BYTE    byStartMonth;	// Start month, starting from 1
    BYTE	byStartDay;		// Start day, starting from 1
    BYTE	byEndMonth;		// End month 
    BYTE	byEndDay;		// End day
    BYTE	byRes[4];		// Reserved
}NET_DVR_HOLIDATE_MODEA, *LPNET_DVR_HOLIDATE_MODEA;

typedef struct tagNET_DVR_HOLIDATE_MODEB
{
    BYTE	byStartMonth;	// Start month, starting from 1
    BYTE	byStartWeekNum;	// Start week, starting from 1 
    BYTE	byStartWeekday;	// Day of the week
    BYTE	byEndMonth;		// End month, starting from 1
    BYTE	byEndWeekNum;	// End week, starting from 1 
    BYTE	byEndWeekday;	// Day of the week	
    BYTE	byRes[2];		// Reserved
}NET_DVR_HOLIDATE_MODEB, *LPNET_DVR_HOLIDATE_MODEB;

typedef struct tagNET_DVR_HOLIDATE_MODEC
{
    WORD	wStartYear;		// Year
    BYTE	byStartMon;		// Month
    BYTE	byStartDay;		// Day
    WORD	wEndYear;		// Year
    BYTE	byEndMon;		// Month
    BYTE	byEndDay;		// Day
}NET_DVR_HOLIDATE_MODEC, *LPNET_DVR_HOLIDATE_MODEC;

typedef union tagNET_DVR_HOLIDATE_UNION
{	
    // Union size: 12 bytes
    DWORD				    dwSize[3];
    NET_DVR_HOLIDATE_MODEA	struModeA;	// Mode A
    NET_DVR_HOLIDATE_MODEB	struModeB;	// Mode B
    NET_DVR_HOLIDATE_MODEC	struModeC;	// Mode C
}NET_DVR_HOLIDATE_UNION, *LPNET_DVR_HOLIDATE_UNION;

typedef enum tagHOLI_DATE_MODE
{
    HOLIDATE_MODEA = 0,
    HOLIDATE_MODEB,
    HOLIDATE_MODEC
}HOLI_DATE_MODE;

typedef struct tagNET_DVR_HOLIDAY_PARAM
{
    BYTE	byEnable;			// Enable or not
    BYTE	byDateMode;			// Date mode: 0- mode A, 1- mode B, 2- mode C
    BYTE	byRes1[2];			// Reserved
    NET_DVR_HOLIDATE_UNION uHolidate;	// Holiday date 
    BYTE	byName[NAME_LEN];	// Holiday name
    BYTE	byRes2[20];			// Reserved
}NET_DVR_HOLIDAY_PARAM, *LPNET_DVR_HOLIDAY_PARAM;

#define  MAX_HOLIDAY_NUM	32

typedef struct tagNET_DVR_HOLIDAY_PARAM_CFG
{
    DWORD	dwSize;			//Structure size
    NET_DVR_HOLIDAY_PARAM struHolidayParam[MAX_HOLIDAY_NUM];	//Holiday parameter
    DWORD	byRes[40];		// Reserved
}NET_DVR_HOLIDAY_PARAM_CFG, *LPNET_DVR_HOLIDAY_PARAM_CFG;

//Holiday alarm handling mode
typedef struct tagNET_DVR_HOLIDAY_HANDLE
{
    DWORD	dwSize;				//Structure size
    NET_DVR_SCHEDTIME              struAlarmTime[MAX_TIMESEGMENT_V30];	//Arming schedule
    BYTE	byRes2[240];		// Reserved
}NET_DVR_HOLIDAY_HANDLE, *LPNET_DVR_HOLIDAY_HANDLE;

typedef struct tagNET_DVR_HOLIDAY_RECORD
{
    DWORD                 dwSize;
    NET_DVR_RECORDDAY     struRecDay;     // Record parameter
    NET_DVR_RECORDSCHED   struRecordSched[MAX_TIMESEGMENT_V30]; // Record schedule
    BYTE                  byRes[20];      //  Reserved
}NET_DVR_HOLIDAY_RECORD, *LPNET_DVR_HOLIDAY_RECORD;

#define  MAX_LINK_V30  128

typedef struct tagNET_DVR_ONE_LINK
{
    NET_DVR_IPADDR  struIP;     // Client IP
    LONG            lChannel;   // Channel number
    BYTE            byRes[32];  // Reserved
}NET_DVR_ONE_LINK, *LPNET_DVR_ONE_LINK;

typedef struct tagNET_DVR_LINK_STATUS
{
    DWORD   dwSize;      //Structure size
    WORD    wLinkNum;    //Total number of connections
    BYTE    byRes1[2];   // Reserved
    NET_DVR_ONE_LINK struOneLink[MAX_LINK_V30];   //Information of the client connecting to the device
    BYTE    byRes[32];   // Reserved
}NET_DVR_LINK_STATUS, *LPNET_DVR_LINK_STATUS;

#define MAX_BOND_NUM  2

typedef struct tagNET_DVR_ONE_BONDING
{
    BYTE    byMode;				//Work mode: 0 - network fault tolerance, 1 - load balancing
    BYTE	byUseDhcp;			//Enable dhcp or not
    BYTE	byMasterCard;	    //Assign which network card to be master card		
    BYTE    byStatus;           //BONDING status: 0 - exception, 1- normal. It is read only, and it is not supported to modify
    BYTE	byBond[MAX_NETWORK_CARD];//byBond[0]== 1 means to use eh0, byBond[0]== 0 means not to use eh0
    NET_DVR_ETHERNET_V30	struEtherNet; //Ethernet parameter
    NET_DVR_IPADDR	struGatewayIpAddr;    //IP address of Gateway
    BYTE	byRes[20];			// Reserved
}NET_DVR_ONE_BONDING, *LPNET_DVR_ONE_BONDING;

typedef struct tagNET_DVR_NETWORK_BONDING
{
    DWORD   dwSize;         //Structure size
    BYTE    byEnable;       //Enable bonding or not
    BYTE    byNum;          //The number of bonding network cards
    BYTE    byRes1[2];      //Reserved
    NET_DVR_ONE_BONDING struOneBond[MAX_BOND_NUM];
    BYTE	byRes2[40];		//Reserved
}NET_DVR_NETWORK_BONDING, *LPNET_DVR_NETWORK_BONDING;


//Disk quota 
typedef struct tagNET_DVR_DISK_QUOTA 
{
	BYTE	byQuotaType;	 //Disk quota: 1- by capacity of disk 
    BYTE    byRes1[7];       //Reserved
    DWORD   dwHCapacity;     //High 32 bits of the allocated disk capacity, unit:MB
    DWORD   dwLCapacity;     //Low 32 bits of the allocated disk capacity, unit:MB
    DWORD   dwHUsedSpace;    //High 32 bits of used disk capacity, unit:MB
    DWORD   dwLUsedSpace;    //Low 32 bits of used disk capacity, unit:MB
    BYTE    byRes2[22];      // Reserved
}NET_DVR_DISK_QUOTA, *LPNET_DVR_DISK_QUOTA;

typedef struct tagNET_DVR_DISK_QUOTA_CFG
{
    DWORD   dwSize;         //Structure size
    NET_DVR_DISK_QUOTA    struPicQuota;       //Picture quota
    NET_DVR_DISK_QUOTA    struRecordQuota;    //Record quota
    BYTE    byRes[60];      //Reserved
}NET_DVR_DISK_QUOTA_CFG, *LPNET_DVR_DISK_QUOTA_CFG;


typedef struct tagNET_DVR_TIMING_CAPTURE
{
    NET_DVR_JPEGPARA  struJpegPara;   //Picture quality of timing capture
    DWORD      dwPicInterval;         //Interval of timing capture, unit: s  
    BYTE       byRes[12];             //Reserved
}NET_DVR_TIMING_CAPTURE, *LPNET_DVR_TIMING_CAPTURE;

typedef struct tagNET_DVR_REL_CAPTURE_CHAN
{
    BYTE    byChan[16];    //Indicated by bit
    BYTE    byRes[20];     //Reserved
}NET_DVR_REL_CAPTURE_CHAN, *LPNET_DVR_REL_CAPTURE_CHAN;

#define MAX_PIC_EVENT_NUM  32
#define MAX_ALARMIN_CAPTURE   16
typedef struct tagNET_DVR_EVENT_CAPTURE
{
    NET_DVR_JPEGPARA  struJpegPara;   //Picture quality of event capture
    DWORD       dwPicInterval;        //Interval of event capture, unit: s
    NET_DVR_REL_CAPTURE_CHAN struRelCaptureChan[MAX_PIC_EVENT_NUM]; //That array subscript = 0 means motion detection triggering capture, array subscript = 1 means video tampering triggering capture,2-video lost capture,3-PIR alarm capture,4-wireless alarm capture,5-callhelp alarm capture
    NET_DVR_REL_CAPTURE_CHAN struAlarmInCapture[MAX_ALARMIN_CAPTURE];    //Alarm in triggering capture. That array subscript = 0 means the NO.1 alarm in, and so forth
	BYTE       byCapTimes; //capture times
    BYTE       byRes[59];
}NET_DVR_EVENT_CAPTURE, *LPNET_DVR_EVENT_CAPTURE;

typedef struct tagNET_DVR_JPEG_CAPTURE_CFG
{
    DWORD      dwSize;         //Structure size
    NET_DVR_TIMING_CAPTURE struTimingCapture;    
    NET_DVR_EVENT_CAPTURE struEventCapture;
    BYTE       byRes3[20];     // Reserved
}NET_DVR_JPEG_CAPTURE_CFG, *LPNET_DVR_JPEG_CAPTURE_CFG;  

typedef struct tagNET_DVR_CAPTURE_DAY
{
    BYTE	byAllDayCapture;	//Enable all-day capture or not
    BYTE	byCaptureType;		//Capture type: 0- scheduled capture, 1- motion detection capture, 2- alarm capture, 3- motion detection | alarm capture, 4- motion detection & alarm capture, 6- intelligent alarm capture
    BYTE	byRes[2];
}NET_DVR_CAPTURE_DAY, *LPNET_DVR_CAPTURE_DAY;

typedef struct tagNET_DVR_CAPTURE_SCHED
{
    NET_DVR_SCHEDTIME struCaptureTime;  //Time segment
    BYTE        byCaptureType;          //Capture type: 0- scheduled capture, 1- motion detection capture, 2- alarm capture, 3- motion detection | alarm capture, 4- motion detection & alarm capture, 6- intelligent alarm capture
    BYTE        byRes[3];               //Reserved
}NET_DVR_CAPTURE_SCHED, *LPNET_DVR_CAPTURE_SCHED;

// Channel capture scheme
typedef struct tagNET_DVR_SCHED_CAPTURECFG
{
    DWORD  dwSize;     //Structure size
    BYTE	byEnable;	//Capture or not
    BYTE	byRes1[3];	// Reserved
    NET_DVR_CAPTURE_DAY	struCaptureDay[MAX_DAYS];	//All-day capture
    NET_DVR_CAPTURE_SCHED	struCaptureSched[MAX_DAYS][MAX_TIMESEGMENT_V30];	//Capture schedule
    NET_DVR_CAPTURE_DAY	struCaptureHoliday;			//Holiday capture schedule
    NET_DVR_CAPTURE_SCHED	struHolidaySched[MAX_TIMESEGMENT_V30];	//Holiday schedule
    DWORD	dwRecorderDuration;	//Max keeping time for captured pictures, unit: day. 0xffffffff means the value is invalid
    BYTE	byRes[40];			// Reserved
}NET_DVR_SCHED_CAPTURECFG, *LPNET_DVR_SCHED_CAPTURECFG;

typedef struct tagNET_DVR_FLOW_TEST_PARAM
{
	DWORD  dwSize;             //Structure size
    LONG   lCardIndex;         //NIC index
    DWORD  dwInterval;         //Uploading time interval, unit: 100 ms
    BYTE   byRes[8];           //Reserved
}NET_DVR_FLOW_TEST_PARAM, *LPNET_DVR_FLOW_TEST_PARAM;

typedef struct tagNET_DVR_FLOW_INFO
{
	DWORD  dwSize;             //Structure size
	DWORD  dwSendFlowSize;     //Size of sending flow, unit: kbps
	DWORD  dwRecvFlowSize;     //Size of receiving flow, unit: kbps
    BYTE   byRes[20];          //Reserved
}NET_DVR_FLOW_INFO, *LPNET_DVR_FLOW_INFO;

//Record label
#define LABEL_NAME_LEN 40
typedef struct tagNET_DVR_RECORD_LABEL
{
    DWORD  dwSize;					    //Structure size
    NET_DVR_TIME  struTimeLabel;		//Label time 
    BYTE	byQuickAdd;				    //Whether quickly add label. Label name is invalid when quickly adding
    BYTE	byRes1[3];				    //Reserved
    BYTE	sLabelName[LABEL_NAME_LEN];	//Label name. Its length is 40 bytes  
    BYTE	byRes2[40];				    //Reserved
}NET_DVR_RECORD_LABEL, *LPNET_DVR_RECORD_LABEL;

#define  LABEL_IDENTIFY_LEN     64
typedef struct tagNET_DVR_LABEL_IDENTIFY
{
    BYTE    sLabelIdentify[LABEL_IDENTIFY_LEN];    // 64 bytes identify
    BYTE    byRes[8];               // Reserved
}NET_DVR_LABEL_IDENTIFY, *LPNET_DVR_LABEL_IDENTIFY;

#define MAX_DEL_LABEL_IDENTIFY  20// Max number of label identifies to be deleted

typedef struct tagNET_DVR_DEL_LABEL_PARAM
{
    DWORD   dwSize;       //Structure size
    BYTE    byMode;		  //Expressed by bit, 0x01 means deleting by identify 
    BYTE    byRes1;
    WORD    wLabelNum;      //Total number of labels      
    NET_DVR_LABEL_IDENTIFY struIndentify[MAX_DEL_LABEL_IDENTIFY]; //Label identify
    BYTE    byRes2[160];   //Reserved   
}NET_DVR_DEL_LABEL_PARAM, *LPNET_DVR_DEL_LABEL_PARAM;

typedef struct tagNET_DVR_LABEL_PARAM
{
	NET_DVR_LABEL_IDENTIFY struIndentify; //Label identify to be modified
	BYTE byRes1[24];
	BYTE sLabelName[LABEL_NAME_LEN];	//Modified label name
	BYTE byRes2[40];				
}NET_DVR_MOD_LABEL_PARAM, *LPNET_DVR_MOD_LABEL_PARAM;

//Record label searching structure
typedef struct tagNET_DVR_FIND_LABEL
{
    DWORD       dwSize;                     //Structure size
    LONG	    lChannel;		            //Searching channel
    NET_DVR_TIME	struStartTime;       	//Start time
    NET_DVR_TIME	struStopTime;	        //End time
    BYTE	    sLabelName[LABEL_NAME_LEN];	//Record label name. If the name is NULL, it will search all labels in the set period
	BYTE		byDrawFrame;		//0:not draw frame，1：draw frame
    BYTE	    byRes[39];		            //Reserved
}NET_DVR_FIND_LABEL, *LPNET_DVR_FIND_LABEL;

//Label information structure
typedef struct tagNET_DVR_FINDLABEL_DATA
{
    BYTE	sLabelName[LABEL_NAME_LEN];	      //Label name
    NET_DVR_TIME struTimeLabel;		          //Label time 
    NET_DVR_LABEL_IDENTIFY struLabelIdentify; //Label identify
    BYTE	byRes1[32];		                  //Reserved
}NET_DVR_FINDLABEL_DATA, *LPNET_DVR_FINDLABEL_DATA;

#define CARDNUM_LEN_V30 40
typedef struct tagNET_DVR_FIND_PICTURE_PARAM
{
    DWORD  dwSize;         //Structure size
    LONG   lChannel;       //Channel number
    BYTE   byFileType;     //Image type to search: 0- scheduled capture, 1- motion detection capture, 2- alarm capture, 3- motion detection or alarm capture, 3-motion detection and alarm capture, 6- manual capture, 0xff- all types
    BYTE   byNeedCard;     //Whether need card number
    BYTE   byRes1[2];      //Reserved
    BYTE   sCardNum[CARDNUM_LEN_V30];     //Card number
    NET_DVR_TIME  struStartTime;//Start time of image search
    NET_DVR_TIME  struStopTime;//End time of image search
    BYTE   byRes2[40];     // Reserved
}NET_DVR_FIND_PICTURE_PARAM, *LPNET_DVR_FIND_PICTURE_PARAM;

#define PICTURE_NAME_LEN 64

typedef struct
{
    char    sFileName[PICTURE_NAME_LEN];//Picture name
    NET_DVR_TIME struTime;              //Time of picture capture
    DWORD dwFileSize;                   //Picture size 
    char    sCardNum[CARDNUM_LEN_V30];	//Card number
    BYTE byRes[32];		//  Reserved
}NET_DVR_FIND_PICTURE,*LPNET_DVR_FIND_PICTURE;

#define MAX_RECORD_PICTURE_NUM  50      //  Max number of backup pictures 

typedef struct tagNET_DVR_BACKUP_PICTURE_PARAM
{
	DWORD  dwSize;         //Structure size
	DWORD  dwPicNum;
	NET_DVR_FIND_PICTURE struPicture[MAX_RECORD_PICTURE_NUM];
	BYTE   byDiskDes[DESC_LEN_32];
	BYTE   byWithPlayer;
	BYTE   byContinue;    /*Whether continue to backup or not: 0-no, 1-yes*/
	BYTE   byRes[34];
}NET_DVR_BACKUP_PICTURE_PARAM, *LPNET_DVR_BACKUP_PICTURE_PARAM;

typedef struct 
{	
	DWORD dwSize;           //Structure size
	DWORD dwChannel;        //Channel number
	BYTE  byCompressType;   //Compression type to be got: 1- main stream, 2- sub stream, 3- event 
	BYTE  byRes[15];        //Reserved
	NET_DVR_COMPRESSIONCFG_V30  struCurrentCfg; //Current compression configuration
}NET_DVR_COMPRESSION_LIMIT, *LPNET_DVR_COMPRESSION_LIMIT;

#define   STEP_RECV_DATA   1    //Receive upgrade package data
#define   STEP_UPGRADE     2    //Upgrade system
#define   STEP_BACKUP      3    //Backup system
#define   STEP_SEARCH      255  //Search upgrade file

typedef struct tagNET_DVR_VIDEO_EFFECT
{
	DWORD dwBrightValue;      //Brightness value[0,255]
	DWORD dwContrastValue;    //Contrast value[0,255]
	DWORD dwSaturationValue;  //Saturation value[0,255]
	DWORD dwHueValue;         //Hue value[0,255]
	DWORD dwSharpness;		  //Sharpness[0,255]
	DWORD dwDenoising;		  //Denoising[0,255]
	BYTE  byRes[12];
}NET_DVR_VIDEO_EFFECT, *LPNET_DVR_VIDEO_EFFECT;

typedef struct tagNET_DVR_VIDEO_INPUT_EFFECT
{	
	DWORD					dwSize;             //Structure size
	WORD					wEffectMode;        //Mode: 0-Standard, 1-In door,  2-Out door, 3-Dim light, 255-customized 
	BYTE					byRes1[146];		//Reserved
	NET_DVR_VIDEO_EFFECT	struVideoEffect;	//Video effect
	BYTE					byRes2[60];         //Reserved
}NET_DVR_VIDEO_INPUT_EFFECT, *LPNET_DVR_VIDEO_INPUT_EFFECT;

typedef struct tagNET_DVR_VIDEOPARA_V40
{
	DWORD	dwChannel;			// Channel number
	DWORD	dwVideoParamType;  	// Video param type 0-bright 1-contrast 2-saturation 3-hue 4-sharpness 5-denoising
	DWORD	dwVideoParamValue;  // Video param value
	BYTE 	byRes[12];
}NET_DVR_VIDEOPARA_V40, *LPNET_DVR_VIDEOPARA_V40;

typedef struct tagNET_DVR_DEFAULT_VIDEO_COND
{
	DWORD	dwSize;			
	DWORD	dwChannel;		
	DWORD	dwVideoMode;	
	BYTE	byRes[32];     
}NET_DVR_DEFAULT_VIDEO_COND, *LPNET_DVR_DEFAULT_VIDEO_COND;

/*********************************9000 2.0 end***************************************/

typedef struct tagNET_DVR_ENCODE_JOINT_PARAM
{
    DWORD	dwSize;			//Structure size
    BYTE	byJointed;		//0- not associated  1- associated
    BYTE	byDevType;		//Associated device type, 1- intelligent device
    BYTE	byRes1[2];		//Reserved
    NET_DVR_IPADDR	struIP;	//IP address of associated device to be taken stream 
    WORD	wPort;			//Port of associated device to be taken stream  
    WORD	wChannel;		//Associated device channel to be taken stream   
    BYTE	byRes2[20];		//Reserved
}NET_DVR_ENCODE_JOINT_PARAM, *LPNET_DVR_ENCODE_JOINT_PARAM;	

typedef struct tagNET_DVR_VCA_CHAN_WORKSTATUS
{
    BYTE	byJointed;				//0- not associated  1- associated
    BYTE	byRes1[3];
    NET_DVR_IPADDR	struIP;	    	//IP address of associated device to take stream 
    WORD	wPort;					//Port of associated device to take stream  
    WORD	wChannel;				//Associated device channel to take stream  
    BYTE	byVcaChanStatus;		//0 - disable, 1 - enable
    BYTE	byRes2[19];				//Reserved
}NET_DVR_VCA_CHAN_WORKSTATUS, *LPNET_DVR_VCA_CHAN_WORKSTATUS;

typedef struct tagNET_DVR_VCA_DEV_WORKSTATUS
{
    DWORD	dwSize;			//Structure size
    BYTE	byDeviceStatus;	//Device status: 0- normal, 1- abnormal
    BYTE	byCpuLoad;		//CPU usage: 0-100 means percentage
    NET_DVR_VCA_CHAN_WORKSTATUS struVcaChanStatus[MAX_VCA_CHAN];
    DWORD	byRes[40];		// Reserved
}NET_DVR_VCA_DEV_WORKSTATUS, *LPNET_DVR_VCA_DEV_WORKSTATUS;

/*****************************65dvs**************************************/
typedef struct tagNET_DVR_HISTORICDATACFG
{
    DWORD dwSize;
	DWORD dwTotalNum;  //History data total number
	BYTE byRes[16];
}NET_DVR_HISTORICDATACFG, *LPNET_DVR_HISTORICDATACFG;
/************************************************************************/

/********************************Thermal Imager********************************/
typedef struct tagNET_DVR_CORRECT_DEADPIXEL_PARAM
{
	DWORD dwSize;
	DWORD dwCommand; //Command: 0- enter bad point  mode, 1- add bad point, 2- save bad point, 3- exit bad point 
	DWORD dwDeadPixelX; //X coordinate of bad point
	DWORD dwDeadPixelY; //Y coordinate of bad point
	BYTE byRes[12]; //Reserved
}NET_DVR_CORRECT_DEADPIXEL_PARAM, *LPNET_DVR_CORRECT_DEADPIXEL_PARAM;

/********************************Thermal Imager end****************************/

/***********************************81 Inquest DVR*****************************/
#define INQUEST_MESSAGE_LEN     44    //Length of inquest key tag message
#define INQUEST_MAX_ROOM_NUM    2     //Max number of inquest rooms
#define MAX_RESUME_SEGMENT      2     //Number of segments supported to resume simultaneously

typedef struct tagNET_DVR_INQUEST_ROOM
{
	BYTE		byRoomIndex;     //Inquest room index
    BYTE		byRes[23];       //Reserved
}NET_DVR_INQUEST_ROOM, *LPNET_DVR_INQUEST_ROOM;

typedef struct tagNET_DVR_INQUEST_MESSAGE
{
	char 	sMessage[INQUEST_MESSAGE_LEN]; //Key marker information
    BYTE	byRes[46];                     //Reserved
}NET_DVR_INQUEST_MESSAGE, *LPNET_DVR_INQUEST_MESSAGE;

typedef struct tagNET_DVR_INQUEST_SENSOR_DEVICE
{
	WORD	wDeviceType;	//Data collection device type: 1: Mera, 2:Leicai, 3:Leicai
	WORD	wDeviceAddr;	//Data collection device address	
	BYTE 	byRes[28];	    //Reserved
}NET_DVR_INQUEST_SENSOR_DEVICE, *LPNET_DVR_INQUEST_SENSOR_DEVICE;

typedef struct tagNET_DVR_INQUEST_SENSOR_INFO
{
	NET_DVR_INQUEST_SENSOR_DEVICE struSensorDevice[INQUEST_MAX_ROOM_NUM];
	DWORD   dwSupportPro;      //Supported protocol type, described by bit
							   //0x1:Mera, 0x2:Leicai, 0x4:Youli
	BYTE    byRes[120];        //Reserved
}NET_DVR_INQUEST_SENSOR_INFO, *LPNET_DVR_INQUEST_SENSOR_INFO;

typedef struct tagNET_DVR_INQUEST_SYSTEM_INFO
{
	DWORD  dwRecordMode;         //Burning mode: 1 Single room and double burned mode, 2- Single room and round burned mode, 3- double room and double burned mode
    DWORD  dwWorkMode;           //Working mode: 0- standard mode, 1- general mode
	DWORD  dwResolutionMode;     //Device resolution, 0: standard definition 1:D1 2:720P 3:1080P
	NET_DVR_INQUEST_SENSOR_INFO struSensorInfo;  //Temperature and humidity sensor configuration	
	BYTE    byRes[120];	
}NET_DVR_INQUEST_SYSTEM_INFO, *LPNET_DVR_INQUEST_SYSTEM_INFO;

typedef struct tagNET_DVR_INQUEST_RESUME_SEGMENT
{
	NET_DVR_TIME  struStartTime; //Start time of event
	NET_DVR_TIME  struStopTime;  //End time of event
	BYTE	byRoomIndex;         //Inquest room index, start from 1
	BYTE    byDriveIndex;        //Burner index, start from 1
	WORD    wSegmetSize;         //Segment size, unit:M 
	DWORD   dwSegmentNo;         //Segment number of this inquest event, start from 1 
	BYTE    byRes[24];           //Reserved
}NET_DVR_INQUEST_RESUME_SEGMENT, *LPNET_DVR_INQUEST_RESUME_SEGMENT;

typedef struct tagNET_DVR_INQUEST_RESUME_EVENT
{
	DWORD   dwResumeNum;       //Number of events requiring to be resumed
	NET_DVR_INQUEST_RESUME_SEGMENT struResumeSegment[MAX_RESUME_SEGMENT];
	BYTE    byRes[200];        //Reserved
}NET_DVR_INQUEST_RESUME_EVENT, *LPNET_DVR_INQUEST_RESUME_EVENT;

typedef struct tagNET_DVR_INQUEST_DEVICE_VERSION
{
	BYTE  byMainVersion;         /* Baseline major version
								   0 : unknown
								   1 : 8000 inquest DVR
								       minor version: 1 : 8000HD-S
								   2 : 8100 inquest DVR 
									   minor version: 1 : inquest 81SNL
											          2 : inquest 81SH
											          3 : inquest 81SFH
								 */
	BYTE  bySubVersion;          //Baseline minor version
    BYTE  byUpgradeVersion;      //Upgrade version, it is 0 if have not upgraded
	BYTE  byCustomizeVersion;    //Customized version, it is 0 if the device is not customized
	BYTE  byRes[60];             //Reserved
}NET_DVR_INQUEST_DEVICE_VERSION, *LPNET_DVR_INQUEST_DEVICE_VERSION;

/***********************************81 Inquest DVR*****************************/


typedef struct tagNET_DVR_DISK_RAID_INFO 
{
    DWORD dwSize;       //Structure length
	BYTE byEnable;      //Is enbale of disk raid.
    BYTE byRes[35];     //reserved
}NET_DVR_DISK_RAID_INFO, *LPNET_DVR_DISK_RAID_INFO; 

typedef struct tagNET_DVR_SYNCHRONOUS_IPC
{
	DWORD dwSize;    //Structure length
	BYTE  byEnable;  //Do synchronize IPC.
	BYTE  byRes[7];  //reserved
}NET_DVR_SYNCHRONOUS_IPC, *LPNET_DVR_SYNCHRONOUS_IPC;

typedef struct tagNET_DVR_IPC_PASSWD
{
	DWORD dwSize;    //Structure length
	char sOldPasswd[PASSWD_LEN];  //the old passward of IPC.
	char sNewPasswd[PASSWD_LEN];  //the new passward of IPC
	BYTE byRes[32];               //reserved
}NET_DVR_IPC_PASSWD, *LPNET_DVR_IPC_PASSWD;

//Get the using information of device net. (bps)
typedef struct tagNET_DEVICE_NET_USING_INFO 
{
	DWORD dwSize;      //Structure length
    DWORD dwPreview;   //preview
    DWORD dwPlayback;  //playback
    DWORD dwIPCModule; //IPC
	DWORD dwNetDiskRW; //net disk reading or writing.
    BYTE res[32];      //reserved
}NET_DVR_DEVICE_NET_USING_INFO, *LPNET_DVR_DEVICE_NET_USING_INFO;

//Set the IP of IPC.
typedef struct tagNET_DVR_IPC_NETCFG
{
	DWORD dwSize;           //Structure length
	NET_DVR_IPADDR struIP;  //IP
	WORD wPort;             //Port
	char res[126];          //reserved
}NET_DVR_IPC_NETCFG, *LPNET_DVR_IPC_NETCFG;

//lock by time
typedef struct tagNET_DVR_TIME_LOCK
{
	DWORD dwSize;      //size
	NET_DVR_TIME strBeginTime;
	NET_DVR_TIME strEndTime;
	DWORD   dwChannel;        //channel no., 0xff: all channel
	DWORD   dwRecordType;     //record type
	DWORD   dwLockDuration;   //duration time, 0xffffffff: always lock
	BYTE    byRes[12];
}NET_DVR_TIME_LOCK, *LPNET_DVR_TIME_LOCK;

typedef struct tagNET_DVR_LOCK_RETURN
{
	DWORD dwSize;      //size
	NET_DVR_TIME strBeginTime; 
	NET_DVR_TIME strEndTime;
	BYTE    byRes[20];
}NET_DVR_LOCK_RETURN, *LPNET_DVR_LOCK_RETURN;

//***channel record state*****//
typedef struct tagNET_DVR_CHANS_RECORD_STATUS
{
	BYTE byValid;       //Enable
	BYTE byRecord;      //(only read)record type:0: not recording; 1: recording
	WORD wChannelNO;    //Channel NO.
	DWORD dwRelatedHD;  //Disk NO.
	BYTE byRes[8];      //Reserved
}NET_DVR_CHANS_RECORD_STATUS, *LPNET_DVR_CHANS_RECORD_STATUS;


typedef struct tagNET_DVR_CHAN_GROUP_RECORD_STATUS
{
	DWORD dwSize; //Structure size
	NET_DVR_CHANS_RECORD_STATUS struChanStatus[MAX_CHANNUM_V30]; //One group has 64 channel
}NET_DVR_CHAN_GROUP_RECORD_STATUS, *LPNET_DVR_CHAN_GROUP_RECORD_STATUS;

/********************************Intelligent Face Recognition****************************/
//Face snapshot rule(single)
typedef struct tagNET_VCA_SINGLE_FACESNAPCFG
{
	BYTE byActive;	   //Whether to activate the rule: 0- no, 1- yes
	BYTE byRes[3];     //Reserved
    NET_VCA_SIZE_FILTER struSizeFilter;   //Size filter
	NET_VCA_POLYGON     struVcaPolygon;	  //Face recognition region
}NET_VCA_SINGLE_FACESNAPCFG, *LPNET_VCA_SINGLE_FACESNAPCFG;

//Face snapshot rules
typedef struct tagNET_VCA_FACESNAPCFG
{
	DWORD dwSize;
	BYTE bySnapTime;					//Total snapshot number of single target face: 0-10
	BYTE bySnapInterval;                //Snapshot interval, unit: frame
	BYTE bySnapThreshold;               //Snapshot threshold: 0-100
	BYTE byGenerateRate; 		        //Target generation speed, value range: [1, 5]	
	BYTE bySensitive;			        //Target detection sensitivity, value range: [1, 5]
	BYTE byReferenceBright; //2012-3-27Reference bright[0,100]
	BYTE byMatchType;         //2012-5-3match alarm type,0-target disappear alarm,1-real time alarm
    BYTE byMatchThreshold;  //2012-5-3real time match threshold,0~100
	NET_DVR_JPEGPARA  struPictureParam; //JPEG picture specification structure
	NET_VCA_SINGLE_FACESNAPCFG struRule[MAX_RULE_NUM]; //Face snapshot rule
	BYTE byRes2[100];
}NET_VCA_FACESNAPCFG, *LPNET_VCA_FACESNAPCFG;

//Face snapshot result
typedef struct tagNET_VCA_FACESNAP_RESULT
{
	DWORD   dwSize;     		//Structure size
	DWORD 	dwRelativeTime;     //Relative time
	DWORD	dwAbsTime;			//Absolute time
    DWORD   dwFacePicID;        //Face picture ID
	DWORD   dwFaceScore;		//Face score: 0-100
	NET_VCA_TARGET_INFO  struTargetInfo;	//Alarm target information
    NET_VCA_RECT         struRect;          //Face subgraph area 
	NET_VCA_DEV_INFO  	 struDevInfo;		//Front-end device information
	DWORD   dwFacePicLen;		//The length of face subgraph: 0- no picture, larger than 0- there is related picture
    DWORD   dwBackgroundPicLen; //The length of background picture: 0- no picture, larger than 0- there is related picture(reserved)
	BYTE    byRes[60];          //Reserved
	BYTE*   pBuffer1;           //Picture data of face subgraph
	BYTE*   pBuffer2;           //Picture data of background picture(reserved)
	                            //(can be got by the API of searching background picture--NET_DVR_FindBackgroundPic)
}NET_VCA_FACESNAP_RESULT, *LPNET_VCA_FACESNAP_RESULT;

typedef struct tagNET_VCA_FD_IMAGE_CFG
{
    DWORD   dwWidth;                  //Width of gray image data
	DWORD   dwHeight;                 //Heigth of gray image
	DWORD   dwImageLen;  //Length of gray image data
	BYTE     byRes[20];  //Reserved
	BYTE     *pImage;    //Gray image data
}NET_VCA_FD_IMAGE_CFG, *LPNET_VCA_FD_IMAGE_CFG;

typedef struct tagNET_VCA_FD_PROCIMG_CFG
{
    DWORD    dwSize;           //Structure size
    BYTE     byEnable;         //Whether to activate the rule
    BYTE     bySensitivity;    //Detection sensitivity, value range: [0,5]
    BYTE     byRes1[22];       //Reserved 
    NET_VCA_SIZE_FILTER  struSizeFilter;  //Size filter
    NET_VCA_POLYGON   struPolygon;        //Polygon
    NET_VCA_FD_IMAGE_CFG struFDImage;     //Image information
    BYTE     byRes2[20];       //Reserved
}NET_VCA_FD_PROCIMG_CFG, *LPNET_VCA_FD_PROCIMG_CFG;

typedef struct tagNET_VCA_SUB_PROCIMG
{
	DWORD dwImageLen;         //Length of image data
	DWORD dwFaceScore;		  //Face score, value range: 0-100
	NET_VCA_RECT struVcaRect; //Face subgraph area
	BYTE  byRes[20];          //Reserved
	BYTE  *pImage;            //Image data
}NET_VCA_SUB_PROCIMG, *LPNET_VCA_SUB_PROCIMG;

typedef struct tagNET_VCA_FD_PROCIMG_RESULT
{
	DWORD dwSize;             //Structure size
	DWORD dwImageId;          //Large picture ID
	BYTE byRes[20];           //Reserved
	DWORD dwSubImageNum;      //The total number of face subgraphs
	NET_VCA_SUB_PROCIMG  struProcImg[MAX_TARGET_NUM];  //Single face subgraph information
}NET_VCA_FD_PROCIMG_RESULT, *LPNET_VCA_FD_PROCIMG_RESULT;

typedef struct tagNET_VCA_PICMODEL_RESULT
{
	DWORD dwImageLen;  //Length of image data
	DWORD dwModelLen;  //Length of model data
	BYTE  byRes[20];   //Reserved
	BYTE  *pImage;     //The pointer to face picture data
	BYTE  *pModel;     ///The pointer to model data
}NET_VCA_PICMODEL_RESULT, *LPNET_VCA_PICMODEL_RESULT;

typedef struct tagNET_VCA_REGISTER_PIC
{
	DWORD dwImageID; //Large picture ID
	DWORD dwFaceScore;		//Face score: 0-100
	NET_VCA_RECT struVcaRect;  //Face subgraph area
	BYTE  byRes[20];  //Reserved
}NET_VCA_REGISTER_PIC, *LPNET_VCA_REGISTER_PIC;

#define MAX_HUMAN_PICTURE_NUM   10   //The total number of pictures
#define MAX_HUMAN_BIRTHDATE_LEN 10   //The max length of birthday

typedef struct tagNET_DVR_AREAINFOCFG
{ 
	WORD wNationalityID; //Nationality
	WORD wProvinceID; //Province
	WORD wCityID; //City
	WORD wCountyID; //County
	BYTE byRes[4]; //Reserved
}NET_DVR_AREAINFOCFG, *LPNET_DVR_AREAINFOCFG;

typedef struct tagNET_VCA_HUMAN_ATTRIBUTE
{
	BYTE   bySex; //Gender: 0- man, 1- woman
	BYTE   byCertificateType; //Certificate type: 0- identity card,1- police certificate
	BYTE   byBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //Birthday, for example: 201106
	BYTE   byName[NAME_LEN]; //Name
	NET_DVR_AREAINFOCFG struNativePlace; //Birthplace parameter
	BYTE   byCertificateNumber[NAME_LEN];  //Certificate number
	BYTE   byRes2[20];
}NET_VCA_HUMAN_ATTRIBUTE, *LPNET_VCA_HUMAN_ATTRIBUTE;

typedef struct tagNET_VCA_HUMANATTRIBUTE_COND
{
	BYTE   bySex; //Gender: 0- disabled, 1- man, 2- woman
	BYTE   byCertificateType; //Certificate type: 0- disabled, 1- identity card, 2- police certificate
	BYTE   byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //Start birthday, for example: 201106
	BYTE   byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //End birthday, for example: 201106
	BYTE   byName[NAME_LEN]; //Name
	NET_DVR_AREAINFOCFG struNativePlace; //Birthplace parameter
	BYTE   byCertificateNumber[NAME_LEN];  //Certificate number
	BYTE   byRes[20];
}NET_VCA_HUMANATTRIBUTE_COND, *LPNET_VCA_HUMANATTRIBUTE_COND;


typedef struct tagNET_VCA_BLACKLIST_INFO
{
	DWORD  dwSize;   //Structure size 
	DWORD  dwRegisterID;  //Register ID (read-only)
	DWORD  dwGroupNo; //Group number
	BYTE   byType; //Black and white list flag: 0- all, 1- white list, 2- black list
	BYTE   byLevel; //Black list level: 0- all, 1- low, 2- middle, 3- high
	BYTE   byRes1[2];  //Reserved
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //Personnel information
	BYTE   byRemark[NAME_LEN]; //Remark information
	BYTE   byRes2[20];
}NET_VCA_BLACKLIST_INFO, *LPNET_VCA_BLACKLIST_INFO;

typedef struct tagNET_VCA_BLACKLIST_PARA
{
    DWORD dwSize;   //Structure size 
	NET_VCA_BLACKLIST_INFO struBlackListInfo;  //Black list information
	DWORD dwRegisterPicNum;  //The total number of blacklist pictures
	NET_VCA_PICMODEL_RESULT struRegisterPic[MAX_HUMAN_PICTURE_NUM];  //blacklist picture information
	BYTE  byRes[40]; //Reserved
}NET_VCA_BLACKLIST_PARA, *LPNET_VCA_BLACKLIST_PARA;

typedef struct tagNET_VCA_BLACKLIST_COND
{
    LONG  lChannel; //Channel number 
	DWORD dwGroupNo; //Group number
	BYTE  byType; //Black and white list flag: 0- all, 1- white list, 2- black list
	BYTE  byLevel; //Black list level: 0- all, 1- low, 2- middle, 3- high
	BYTE  byRes1[2];  //Reserved
	NET_VCA_HUMAN_ATTRIBUTE struAttribute; //Personnel information
	BYTE  byRes[20];
}NET_VCA_BLACKLIST_COND, *LPNET_VCA_BLACKLIST_COND;

typedef struct tagNET_VCA_BLACKLIST_PIC
{
    DWORD dwSize;   //Structure size
	DWORD dwFacePicNum;  //Face picture number
	BYTE  byRes[20]; //Reserved
	NET_VCA_PICMODEL_RESULT  struBlackListPic[MAX_HUMAN_PICTURE_NUM];  //Single picture information
}NET_VCA_BLACKLIST_PIC, *LPNET_VCA_BLACKLIST_PIC;

typedef struct tagNET_VCA_FIND_PICTURECOND
{
    LONG lChannel;//Channel number
    NET_DVR_TIME struStartTime;//Start time
	NET_DVR_TIME struStopTime;//End time
	BYTE byRes[12]; //Reserved
}NET_VCA_FIND_PICTURECOND, *LPNET_VCA_FIND_PICTURECOND;

#define MAX_FACE_PIC_LEN   6144   //The max length of face picture data
typedef struct tagNET_VCA_SUB_SNAPPIC_DATA
{
	DWORD dwFacePicID; //Face picture ID
	DWORD dwFacePicLen;  //Length of face picture data
	NET_DVR_TIME struSnapTime;  //Snapshot time
	DWORD dwSimilarity; //Similarity
	BYTE  byRes[16];  //Reserved
	char  sPicBuf[MAX_FACE_PIC_LEN];  //Picture data
}NET_VCA_SUB_SNAPPIC_DATA, *LPNET_VCA_SUB_SNAPPIC_DATA;

typedef struct tagNET_VCA_ADVANCE_FIND
{
	DWORD dwFacePicID; //Face picture ID
	BYTE  byRes[36];
}NET_VCA_ADVANCE_FIND, *LPNET_VCA_ADVANCE_FIND;

typedef struct tagNET_VCA_NORMAL_FIND
{
	DWORD dwImageID; //Large picture ID
	DWORD dwFaceScore;  //Face score 
	NET_VCA_RECT struVcaRect; //Face subgraph area
	BYTE byRes[20];
}NET_VCA_NORMAL_FIND, *LPNET_VCA_NORMAL_FIND;

typedef union tagNET_VCA_FIND_SNAPPIC_UNION
{
	NET_VCA_NORMAL_FIND  struNormalFind; //Common search
    NET_VCA_ADVANCE_FIND struAdvanceFind; //Advanced search
}NET_VCA_FIND_SNAPPIC_UNION, *LPNET_VCA_FIND_SNAPPIC_UNION;

typedef enum _VCA_FIND_SNAPPIC_TYPE_
{
    VCA_NORMAL_FIND   = 0x00000000,   //Common search
	VCA_ADVANCE_FIND  = 0x00000001    //Advanced search
}VCA_FIND_SNAPPIC_TYPE;

typedef struct tagNET_VCA_FIND_PICTURECOND_ADVANCE
{
    LONG lChannel;//Channel number
    NET_DVR_TIME struStartTime;//Start time
	NET_DVR_TIME struStopTime;//End time
	BYTE byThreshold;  //Threshold: 0-100
	BYTE byRes[23]; //Reserved
	VCA_FIND_SNAPPIC_TYPE dwFindType;//Retrieving type, see to VCA_FIND_SNAPPIC_TYPE
	NET_VCA_FIND_SNAPPIC_UNION uFindParam; //Retrieving parameter
}NET_VCA_FIND_PICTURECOND_ADVANCE, *LPNET_VCA_FIND_PICTURECOND_ADVANCE;

typedef struct tagNET_VCA_FACESNAP_INFO_ALARM
{
	DWORD dwRelativeTime;       //Relative time
	DWORD dwAbsTime;			//Absolute time
    DWORD dwSnapFacePicID;      //Snapshot face picture ID
	DWORD dwSnapFacePicLen;		//Length of face subgraph: 0- no picture, larger than 0- there is related picture
	NET_VCA_DEV_INFO struDevInfo;		//Front-end device information
   	BYTE  byRes[20];              // Reserved
	BYTE  *pBuffer1;  //Snapshot face subgraph data
}NET_VCA_FACESNAP_INFO_ALARM, *LPNET_VCA_FACESNAP_INFO_ALARM;

typedef struct tagNET_VCA_BLACKLIST_INFO_ALARM
{
	NET_VCA_BLACKLIST_INFO struBlackListInfo; //Blacklist basic information
    DWORD dwBlackListPicLen;       //Length of blacklist face subgraph: 0- no picture, larger than 0- there is related picture
   	BYTE  byRes[20];              // Reserved
	BYTE  *pBuffer1;  //Blacklist face subgraph data
}NET_VCA_BLACKLIST_INFO_ALARM, *LPNET_VCA_BLACKLIST_INFO_ALARM;

typedef struct tagNET_VCA_FACESNAP_MATCH_ALARM
{
	DWORD dwSize;     		//Structure size 
    float fSimilarity; //Similarity, value range: [0.001,1]
	NET_VCA_FACESNAP_INFO_ALARM  struSnapInfo; //Snapshot information
    NET_VCA_BLACKLIST_INFO_ALARM struBlackListInfo; //Blacklist information
	BYTE  byRes[60];              // Reserved
}NET_VCA_FACESNAP_MATCH_ALARM, *LPNET_VCA_FACESNAP_MATCH_ALARM;


typedef struct tagNET_VCA_BLACKLIST_INFO_ALARM_LOG
{
	NET_VCA_BLACKLIST_INFO struBlackListInfo; //Blacklist basic information
    DWORD dwBlackListPicID;       //Blacklist face subgraph ID, used to search pictures
   	BYTE  byRes[20];              //Reserved
}NET_VCA_BLACKLIST_INFO_ALARM_LOG, *LPNET_VCA_BLACKLIST_INFO_ALARM_LOG;

typedef struct tagNET_VCA_FACESNAP_INFO_ALARM_LOG
{
	DWORD dwRelativeTime;        //Relative time
	DWORD dwAbsTime;			 //Absolute time
    DWORD dwSnapFacePicID;       //Snapshot face picture ID
	NET_VCA_DEV_INFO  	 struDevInfo;		//Front-end device information
   	BYTE  byRes[20];              // Reserved
}NET_VCA_FACESNAP_INFO_ALARM_LOG, *LPNET_VCA_FACESNAP_INFO_ALARM_LOG;

typedef struct tagNET_VCA_FACESNAP_MATCH_ALARM_LOG
{
	DWORD dwSize;     		//Structure size 
    float fSimilarity;      //Similarity, value range: [0.001,1]
	NET_VCA_FACESNAP_INFO_ALARM_LOG  struSnapInfoLog; //Snapshot information
    NET_VCA_BLACKLIST_INFO_ALARM_LOG struBlackListInfoLog; //Blacklist information
	BYTE  byRes[60];              // Reserved
}NET_VCA_FACESNAP_MATCH_ALARM_LOG, *LPNET_VCA_FACESNAP_MATCH_ALARM_LOG;

typedef struct tagNET_VCA_FACEMATCH_PICCOND
{
	DWORD dwSize;     		// Structure size 
   	DWORD dwSnapFaceID; //Blacklist face subgraph ID
	DWORD dwBlackListID; //Matched blacklist ID
	DWORD dwBlackListFaceID; //Compared blacklist face subgraph ID
	BYTE  byRes[20];              // Reserved
}NET_VCA_FACEMATCH_PICCOND, *LPNET_VCA_FACEMATCH_PICCOND;

typedef struct tagNET_VCA_FACEMATCH_PICTURE
{
	DWORD dwSize;     		//Structure size 
   	DWORD dwSnapFaceLen; //Length of face subgraph
	DWORD dwBlackListFaceLen; //Length of compared blacklist face subgraph
	BYTE  byRes[20];              //Reserved
	BYTE *pSnapFace;  //Picture data of face subgraph
	BYTE *pBlackListFace;  //Picture data of compared blacklist face subgraph
}NET_VCA_FACEMATCH_PICTURE, *LPNET_VCA_FACEMATCH_PICTURE;

typedef struct tagNET_VCA_BLACKLIST_FASTREGISTER_PARA
{
    DWORD dwSize;   //Structure size
	NET_VCA_BLACKLIST_INFO struBlackListInfo;  //Blacklist information
	DWORD dwImageLen;  //Length of image data
	BYTE  byRes[124];  //Reserved
	BYTE  *pImage;    //Image data
}NET_VCA_BLACKLIST_FASTREGISTER_PARA, *LPNET_VCA_BLACKLIST_FASTREGISTER_PARA;

//Single partition configuration
typedef struct tagNET_VCA_SINGLE_PATH
{
	BYTE  byActive;  //Whether it is available: 0- no, 1- yes
	BYTE  byType;    //0- save snapshot, 1- save blacklist comparison alarm, 2- save snapshot and blacklist comparison alarm
	BYTE  byRes1[6]; //Reserved
	DWORD dwDiskDriver;   //Disk sign, start from 0
	DWORD dwLeftSpace;   //Reserved capacity (unit:G)
	BYTE  byRes2[8]; //Reserved
}NET_VCA_SINGLE_PATH, *LPNET_VCA_SINGLE_PATH;

//Set saving path
typedef struct tagNET_VCA_SAVE_PATH_CFG
{ 
	DWORD dwSize;   //Structure size 
	NET_VCA_SINGLE_PATH  struPathInfo[MAX_DISKNUM_V30]; //Single partition
	BYTE  byRes[40]; //Reserved
}NET_VCA_SAVE_PATH_CFG, *LPNET_VCA_SAVE_PATH_CFG;

typedef struct tagNET_DVR_DEV_ACCESS_CFG
{
    DWORD   dwSize;
    NET_DVR_IPADDR 	struIP;		//access device ip
    WORD 	wDevicePort;			 	//port
	BYTE	byEnable;		         //enable,0-no,1-yes
	BYTE 	byRes1;				//
    BYTE	sUserName[NAME_LEN];	//access user name
	BYTE	sPassword[PASSWD_LEN];	//access password
	BYTE	byRes2[60];
}NET_DVR_DEV_ACCESS_CFG,*LPNET_DVR_DEV_ACCESS_CFG;

/********************************Intelligent Face Recognition end****************************/  

typedef struct tagNET_DVR_IP_ALARM_GROUP_NUM
{
	DWORD dwSize; 
	DWORD dwIPAlarmInGroup;      
	DWORD dwIPAlarmInNum;       
	DWORD dwIPAlarmOutGroup;     
	DWORD dwIPAlarmOutNum;     
	BYTE byRes[64];  
}NET_DVR_IP_ALARM_GROUP_NUM, *LPNET_DVR_IP_ALARM_GROUP_NUM;
//****NVR end***//

typedef struct tagNET_DVR_ACCESS_CAMERA_INFO
{
	DWORD dwSize;				// Structure length
   	char  sCameraInfo[32];		// Access camera info
	BYTE  byInterfaceType;		// Access camer type 1:VGA, 2:HDMI, 3:YPbPr 4:SDI 5:FC
	BYTE  byRes1[3];
	DWORD dwChannel;
   	BYTE  byRes[24];
}NET_DVR_ACCESS_CAMERA_INFO, *LPNET_DVR_ACCESS_CAMERA_INFO;

typedef struct tagNET_DVR_AUDIO_INPUT_PARAM
{
    BYTE  byAudioInputType;  //Audio in type,0-mic in,1-line in
	BYTE  byVolume; //volume,[0-100]
	BYTE  byres[6]; 
}NET_DVR_AUDIO_INPUT_PARAM, *LPNET_DVR_AUDIO_INPUT_PARAM;

typedef struct tagNET_DVR_CAMERA_DEHAZE_CFG
{
	DWORD dwSize;
	BYTE byDehazeMode; //0-disenable,1-auto mode
	BYTE byRes[7]; 
}NET_DVR_CAMERA_DEHAZE_CFG, *LPNET_DVR_CAMERA_DEHAZE_CFG;




typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG_V40
{        
    DWORD	dwSize; 
    BYTE   byAudio;			/*Whether the audio is enabled*/
    BYTE   byAudioWindowIdx;      /*Sub window index to enable audio*/
    BYTE 	byVgaResolution;      /*Resolution, got from ability set*/
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL,0-NULL*/
    DWORD	dwWindowMode;		/*Screen mode, got from ability set*/       
    BYTE  	byJoinDecChan[MAX_WINDOWS];/*The decode channel joined with each sub-window*/
    BYTE	byEnlargeStatus;          /*Whether enlarge the window: 0- no, 1- yes*/
    BYTE    byEnlargeSubWindowIndex;//Enlarged sub window index
    BYTE	byScale; /*Display mode: 0--real display，1--scaling display (for BNC)*/
    /*Distinguish between the union: 0- display channel configuration of the decoder inner video integrated platform,
	1- display channel configuration of other decoder*/
    BYTE	byUnionType;
    union
    {
        BYTE byRes[160];
        struct
        {
            /*Decode sub-system slot number corresponded to the decode channel joined with each sub-window(valid for decode sub-system in video integrated platform)*/
            BYTE	byJoinDecoderId[MAX_WINDOWS];
            //Video resolution of display window: 1- D1, 2- 720P, 3- 1080P, 
			//Device set decode channel according to the resolution. For example, if 1 screen is configured to 1080P, the device will set 4 decode channels
			//to the display channel
            BYTE	byDecResolution;
            BYTE	byRes[143];
        }struVideoPlatform;
        struct
        {
            BYTE	byRes[160];
        }struNotVideoPlatform;
    }struDiff;
    BYTE	byRes[120];
}NET_DVR_VGA_DISP_CHAN_CFG_V40,*LPNET_DVR_VGA_DISP_CHAN_CFG_V40;


typedef struct tagNET_DVR_V6SUBSYSTEMPARAM
{
    BYTE		bySerialTrans;//Serial Transport，0-no，1-yes
    BYTE		byRes[35];
}NET_DVR_V6SUBSYSTEMPARAM, *LPNET_DVR_V6SUBSYSTEMPARAM;

// long config status

// pull disk status
#define PULL_DISK_SUCCESS    	1   
#define PULL_DISK_FAIL    		2   
#define PULL_DISK_PROCESSING    3   
#define PULL_DISK_NO_ARRAY 		4 
#define PULL_DISK_NOT_SUPPORT	5 	

// scan raid state
#define SCAN_RAID_SUC			1 	
#define SCAN_RAID_FAIL			2 	
#define SCAN_RAID_PROCESSING	3	
#define SCAN_RAID_NOT_SUPPORT	4 	

// set access camera type status
#define SET_CAMERA_TYPE_SUCCESS    		1   
#define SET_CAMERA_TYPE_FAIL    		2   
#define SET_CAMERA_TYPE_PROCESSING		3


//9000 2.2
typedef struct tagNET_DVR_RECORD_TIME_SPAN_INQUIRY
{
	DWORD	dwSize;    //Structure size
    BYTE    byType;    //0- normal audio and video recording, 1- picture channel recording, 
	                   //2- ANR channel recording, 3- frame extracting channel recording
	BYTE 	byRes[63]; //Reserved
}NET_DVR_RECORD_TIME_SPAN_INQUIRY, *LPNET_DVR_RECORD_TIME_SPAN_INQUIRY;

typedef struct tagNET_DVR_RECORD_TIME_SPAN
{
	DWORD		  dwSize;        //Structure size
	NET_DVR_TIME  strBeginTime;  //Start time
	NET_DVR_TIME  strEndTime;    //End time
    BYTE		  byType;        //0- normal audio and video recording, 1- picture channel recording, 
	                             //2- ANR channel recording, 3- frame extracting channel recording
	BYTE 		  byRes[35];     //Reserved
}NET_DVR_RECORD_TIME_SPAN, *LPNET_DVR_RECORD_TIME_SPAN;

typedef struct tagNET_DVR_DRAWFRAME_DISK_QUOTA_CFG
{
    DWORD    dwSize;					//Structure size
    BYTE     byPicQuota;				//Picture percentage					[0%,  30%]
	BYTE     byRecordQuota;				//Record percentage						[20%, 40%]
	BYTE     byDrawFrameRecordQuota;	//Frame extracting record percentage	[30%, 80%]
    BYTE     byRes[61];				//Reserved
}NET_DVR_DRAWFRAME_DISK_QUOTA_CFG, *LPNET_DVR_DRAWFRAME_DISK_QUOTA_CFG;

typedef struct tagNET_DVR_UPNP_PORT
{
    WORD wEnable;         //Whether the port is enabled to be mapped
    WORD wExtPort;		//External port
	BYTE byRes[12];       //Reserved
}NET_DVR_UPNP_PORT, *LPNET_DVR_UPNP_PORT;

typedef struct  tagNET_DVR_UPNP_CFG
{
	DWORD dwSize;          //Structure size
    WORD wEnableUpnp;     //Whether to enable UPNP
    WORD wEnableNat;		//Whether to enable UPNP port mapping(NAT) function
    NET_DVR_IPADDR  struIpAddr;      //LAN IP address of NAT router
    NET_DVR_UPNP_PORT    struHttpPort;   //mapping configuration of web server http port
    NET_DVR_UPNP_PORT    struServerPort; //mapping configuration of erver port
    NET_DVR_UPNP_PORT    struRtspPort;  //mapping configuration of rtsp port 
	BYTE byFriendName[64]; //Friend name
	BYTE byNatType; //UPNP NAT type,0-manual,1-auto
	BYTE byRes[95];    
}NET_DVR_UPNP_CFG, *LPNET_DVR_UPNP_CFG;

typedef struct
{
    DWORD  dwEnabled;               //Whether enable the port to be mapped
    WORD   wInternalPort;           //internal port
    WORD   wExternalPort;           //External port
	DWORD  dwStatus;				 /*Port mapping state:
									 0 Not effective
									 1 Not effective: mapped source port should be same with destination port 
									 2 Not effective: mapped port has been used
									 3 Effect
									*/
	NET_DVR_IPADDR	struNatExternalIp;       //Mapped external IP address
	NET_DVR_IPADDR	struNatInternalIp;       //LAN IP address of NAT router
	BYTE   byRes[16];               //Reserved
}NET_DVR_UPNP_PORT_STATE, *LPNET_DVR_UPNP_PORT_STATE;

typedef struct
{
	NET_DVR_UPNP_PORT_STATE strUpnpPort[12];     //Port mapping state, array 0- web server port, array 1- management port, array 2- rtsp port
	BYTE   byRes[200];              //Reserved
}NET_DVR_UPNP_NAT_STATE, *LPNET_DVR_UPNP_NAT_STATE;

typedef struct tagNET_DVR_PLAYCOND
{
	DWORD			 dwChannel;
	NET_DVR_TIME     struStartTime;
	NET_DVR_TIME     struStopTime;
	BYTE			 byDrawFrame;  //0- not extract frame, 1- extract frame
	BYTE			 byRes[63];    //Reserved
}NET_DVR_PLAYCOND, *LPNET_DVR_PLAYCOND;

typedef struct tagNET_DVR_FILECOND_V40
{
	LONG           lChannel;
	DWORD          dwFileType;
	DWORD          dwIsLocked;
	DWORD          dwUseCardNo;
	BYTE           sCardNumber[32];
	NET_DVR_TIME   struStartTime;
	NET_DVR_TIME   struStopTime;
	BYTE           byDrawFrame;  //0- not extract frame, 1- extract frame
	BYTE           byRes[63];    //Reserved
}NET_DVR_FILECOND_V40, *LPNET_DVR_FILECOND_V40;

typedef struct 
{
	BYTE	sAESKey[16];        //Stream key
	BYTE	byRes[64];          //Reserved
}NET_DVR_AES_KEY_INFO, *LPNET_DVR_AES_KEY_INFO;

typedef struct
{
	NET_DVR_IPADDR struIP;     //IP address
	BYTE  byRes[128]; //Reserved
}NET_DVR_POE_CFG, *LPNET_DVR_POE_CFG;

#define MAX_PRO_PATH         256    //The max length of protocol path

typedef struct
{
	DWORD dwSize;              //Structure size
	DWORD dwEnabled;           //Whether enable the protocol: 0- no, 1- yes
	char  sProtocalName[DESC_LEN];   //Customized protocol name, 16 bits
	BYTE  byRes1[64];          //Reserved, used for extending protocol name
	DWORD dwEnableSubStream;   //Whether enable the sub stream: 0- no, 1- yes
	
	BYTE  byMainProType;        //Main stream protocol type: 1- RTSP
	BYTE  byMainTransType;	   //Main stream transport type 0：Auto 1：udp 2：rtp over rtsp
	WORD  wMainPort;           //Main stream port
	char  sMainPath[MAX_PRO_PATH];  //Main stream path 
	
	BYTE  bySubProType;         //Sub stream protocol type: 1- RTSP
	BYTE  bySubTransType;	    //Main stream transport type 0：Auto 1：udp 2：rtp over rtsp
	WORD  wSubPort;             //Sub stream port
	char  sSubPath[MAX_PRO_PATH];   //Sub stream path 
	
	BYTE  byRes2[200];          //Reserved
}NET_DVR_CUSTOM_PROTOCAL, *LPNET_DVR_CUSTOM_PROTOCAL;


typedef struct tagNET_DVR_VOD_PARA
{
	DWORD				dwSize;
	NET_DVR_STREAM_INFO struIDInfo; 
    NET_DVR_TIME		struBeginTime;
	NET_DVR_TIME		struEndTime;
	HWND				hWnd;
	BYTE				byDrawFrame;
	BYTE				byRes[31];
}NET_DVR_VOD_PARA, *LPNET_DVR_VOD_PARA;



//B10 can support PSIA.
//cycle to wall
typedef struct  
{
    DWORD dwEnable; //0-disable 1－enable
    BYTE  byType;   //device type 0: DEV_SDK  1:DEV_DAHUA  2:DEV_EHOME	3:DEV_OTHERES
    BYTE byRes[3];  //reserved
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg; 
    NET_DVR_DEV_CHAN_INFO  struDevChanInfo; //the information of cycle decoding channel
    BYTE sRtspUrl[128]; //stream address
}NET_DVR_MATRIX_CHAN_INFO_EX,*LPNET_DVR_MATRIX_CHAN_INFO_EX;

typedef struct
{
    DWORD					dwSize;
    DWORD					dwPoolTime;		//the gap of cycle time
    NET_DVR_MATRIX_CHAN_INFO_EX		struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               	byRes[16];
}NET_DVR_MATRIX_LOOP_DECINFO_EX,*LPNET_DVR_MATRIX_LOOP_DECINFO_EX;

//realtime preview
typedef struct
{
    DWORD dwSize;
    BYTE byType;         //device type: 0: DEV_SDK  1:DEV_DAHUA  2:DEV_EHOME 3:DEV_OTHERES
    BYTE byRes[3];       //reserve
    NET_DVR_STREAM_MEDIA_SERVER_CFG struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO struDevChanInfo;
    BYTE sRtspUrl[128];  //stream address
}NET_DVR_PU_STREAM_CFG_EX,*LPNET_DVR_PU_STREAM_CFG_EX;
/////***********************************64-T decoder*************************************//////
//resolution
#define MAKE_RESOLUTION(_interlace_, _width_, _height_, _fps_) \
	(((_interlace_)<<28) \
	|((((_width_)>>3)&0x1ff)<<19)| \
	((((_height_)>>1)&0x7ff)<<8)| \
((_fps_)&0xff))
#define GET_RES_INTERLACE(_res_) \
(((_res_)>>28)&0x1)
#define GET_RES_WIDTH(_res_) \
((((_res_)>>19)&0x1ff)<<3)
#define GET_RES_HEIGHT(_res_) \
((((_res_)>>8)&0x7ff)<<1)
#define GET_RES_FPS(_res_) \
((_res_)&0xff)

#define NOT_AVALIABLE	MAKE_RESOLUTION (0,0,0,0)
#define SVGA_60HZ 		MAKE_RESOLUTION(0, 800, 600, 60)
#define SVGA_75HZ 		MAKE_RESOLUTION(0, 800, 600, 75)
#define XGA_60HZ 		MAKE_RESOLUTION(0, 1024, 768, 60) 
#define XGA_75HZ 		MAKE_RESOLUTION(0, 1024, 768, 75)
#define SXGA_60HZ  		MAKE_RESOLUTION(0, 1280, 1024, 60)
#define SXGA2_60HZ  	MAKE_RESOLUTION(0, 1280, 960, 60) 
#define _720P_60HZ  	MAKE_RESOLUTION(0, 1280, 720, 60)
#define _720P_50HZ  	MAKE_RESOLUTION(0, 1280, 720, 50) 
#define _1080I_60HZ 	MAKE_RESOLUTION(1, 1920, 1080, 60)
#define _1080I_50HZ  	MAKE_RESOLUTION(1, 1920, 1080, 50)
#define _1080P_60HZ 	MAKE_RESOLUTION(0, 1920, 1080, 60)
#define _1080P_50HZ 	MAKE_RESOLUTION(0, 1920, 1080, 50)
#define _1080P_30HZ 	MAKE_RESOLUTION(0, 1920, 1080, 30)
#define _1080P_25HZ 	MAKE_RESOLUTION(0, 1920, 1080, 25)
#define _1080P_24HZ 	MAKE_RESOLUTION(0, 1920, 1080, 24)
#define UXGA_60HZ  		MAKE_RESOLUTION(0, 1600, 1200, 60)
#define UXGA_30HZ  		MAKE_RESOLUTION(0, 1600, 1200, 30)
#define WSXGA_60HZ 		MAKE_RESOLUTION(0, 1680, 1050, 60)
#define WUXGA_60HZ  	MAKE_RESOLUTION(0, 1920, 1200, 60)
#define WUXGA_30HZ 		MAKE_RESOLUTION(0, 1920, 1200, 30)
#define WXGA_60HZ  		MAKE_RESOLUTION(0, 1360, 768, 60)
#define SXGA_PLUS_60HZ	MAKE_RESOLUTION(0, 1400, 1050, 60)

#define  MAX_WINDOWS_NUM 12		//number of menu partition mode
#define  MAX_SUPPORT_RES 32
#define  MAX_DISPNUM_V41 32

typedef struct tagNET_DVR_DISPWINDOWMODE
{
    BYTE byDispChanType;//Display channel type：0-BNC, 1-VGA, 2-HDMI, 3-DVI
    BYTE byDispChanSeq;//sequence of display channel, if the byDispChanType is VGA, byDispChanSeq mean the sequence of VGA
    BYTE byRes[2];
    BYTE byDispMode[MAX_WINDOWS_NUM/*12*/];
}NET_DVR_DISPWINDOWMODE, *LPNET_DVR_DISPWINDOWMODE;


typedef struct tagNET_DVR_DISPINFO
{
    BYTE  byChanNums;//channel numbers
    BYTE  byStartChan;//start channel
    BYTE  byRes[2];
    DWORD	dwSupportResolution[MAX_SUPPORT_RES/*32*/];//support resolution
}NET_DVR_DISPINFO, *LPNET_DVR_DISPINFO;

typedef struct tagNET_DVR_SCREENINFO
{
	BYTE  bySupportBigScreenNums;//Max numbers of big screen
	BYTE  byStartBigScreenNum;//start index of screen 
	BYTE  byMaxScreenX;//the mode of making up big screen
	BYTE  byMaxScreenY;
	BYTE  byRes[8];
}NET_DVR_SCREENINFO, *LPNET_DVR_SCREENINFO;


typedef struct tagNET_DVR_MATRIX_ABILITY_V41
{
	DWORD dwSize;
	BYTE  byDspNums;//DSP numbers  
    BYTE  byDecChanNums;//decoder channel numbers
	BYTE  byStartChan;//the start index of decoder channels
	BYTE  byRes1[5];
	NET_DVR_DISPINFO struVgaInfo;//information of VGA channels
	NET_DVR_DISPINFO struBncInfo;//information of BNC channels
	NET_DVR_DISPINFO struHdmiInfo;//information of HDMI channels
	NET_DVR_DISPINFO struDviInfo;//information of DVI channels
	NET_DVR_DISPWINDOWMODE struDispMode[MAX_DISPNUM_V41/*32*/];
	NET_DVR_SCREENINFO struBigScreenInfo;
	BYTE  bySupportAutoReboot; //auto reboot:0-not support，1-support
	BYTE  byRes2[119];
} NET_DVR_MATRIX_ABILITY_V41, *LPNET_DVR_MATRIX_ABILITY_V41;

#define  MAX_WINDOWS			    16
#define  MAX_WINDOWS_V41			36

#define  STARTDISPCHAN_VGA		    1
#define  STARTDISPCHAN_BNC		    9
#define  STARTDISPCHAN_HDMI		    25
#define  STARTDISPCHAN_DVI		    29

typedef union _tagNET_DVR_VIDEO_PLATFORM
{
	BYTE byRes[160];
	struct
	{
		BYTE	byJoinDecoderId[MAX_WINDOWS_V41];
		BYTE	byDecResolution[MAX_WINDOWS_V41];
		BYTE	byRes[88];
	}struVideoPlatform;
	struct
	{
		BYTE	byRes[160];
	}struNotVideoPlatform;
}NET_DVR_VIDEO_PLATFORM, LPNET_DVR_VIDEO_PLATFORM;


typedef struct _tagNET_DVR_MATRIX_VOUTCFG
{        
    DWORD	dwSize; 
    BYTE	byAudio;			//is audio value
    BYTE	byAudioWindowIdx;      /*audio window Index*/
    BYTE	byDispChanType;      /*display channel type：0-BNC，1-VGA，2-HDMI，3-DVI，4-YPbPr(DECODER_SERVER device used)*/   
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL，0-NULL*/
	DWORD	dwResolution;
    DWORD	dwWindowMode;		/*the max value get from ability*/       
    BYTE	byJoinDecChan[MAX_WINDOWS_V41];/*the decoder channel of every window conjunction*/
	BYTE	byEnlargeStatus;          /*0：zoom in ，1：zoom out*/
	BYTE	byEnlargeSubWindowIndex;//the index of window which is zoom in
	BYTE	byScale; /*0---realty  show，1---zoom show( BNC )*/
	BYTE	byUnionType;/*0-use for the display channels of decoder in video platform，1-use for the other disp channels of decoders*/
	NET_DVR_VIDEO_PLATFORM		struDiff;
    BYTE	byRes2[80];
}NET_DVR_MATRIX_VOUTCFG,*LPNET_DVR_MATRIX_VOUTCFG;

typedef struct _tagNET_DVR_DISP_CHAN_STATUS_V41
{
    BYTE  byDispStatus;      /*0：unshow，1：show*/
    BYTE  byBVGA;              /*0-BNC，1-VGA， 2-HDMI，3-DVI*/
    BYTE  byVideoFormat;     /*1:NTSC,2:PAL,0-NON*/
    BYTE  byWindowMode;      
    BYTE  byJoinDecChan[MAX_WINDOWS_V41];   /*the decoder channel of every window conjunction*/
    BYTE  byFpsDisp[MAX_WINDOWS_V41];        /*rate of frame*/
    BYTE  byScreenMode;		/*screen mode 0-normal 1-big screen*/
    BYTE  byRes1[31];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}NET_DVR_DISP_CHAN_STATUS_V41, *LPNET_DVR_DISP_CHAN_STATUS_V41;

typedef struct _NET_DVR_DECODER_WORK_STATUS_V41
{
    DWORD dwSize;
	NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[32];     /*status of decoder channels*/
    NET_DVR_DISP_CHAN_STATUS_V41   struDispChanStatus[MAX_DISPNUM_V41/*32*/];   /*status of disp channels*/  
    BYTE byAlarmInStatus[32];         /*status of alarm in*/
    BYTE byAlarmOutStatus[32];       /*status of alarm out*/
    BYTE byAudioInChanStatus;          /*status of audio in*/
    BYTE byRes[127];
}NET_DVR_DECODER_WORK_STATUS_V41,*LPNET_DVR_DECODER_WORK_STATUS_V41;

typedef struct _tagNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41
{
    DWORD	dwSize;
    NET_DVR_IPADDR	struIP;		/* DVR IP*/	
    WORD	wDVRPort;			/* port*/	
    BYTE	byChannel;			/* channels */
    BYTE 	byReserve;
    BYTE	sUserName[NAME_LEN];		
    BYTE	sPassword[PASSWD_LEN];
    DWORD	dwPlayMode;   	/* 0－play by file name 1－play by time*/        	
    NET_DVR_TIME StartTime;
    NET_DVR_TIME StopTime;
    char    sFileName[128];
    BYTE	byRes[64];	
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_V41, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41;

#define		MAX_BIGSCREENNUM	100// Max Screen number

typedef struct tagNET_DVR_SINGLESCREENCFG
{
    BYTE	byScreenSeq;//screen sequence, 0xff means doesn't use this screen，the first screen is main screen  
    BYTE	bySubSystemNum;//slot index in subsystem of decode, this value is unuseful in 64-T decoder
    BYTE	byDispNum;//display channel index in subsystem of decode
    BYTE	byRes[9];
}NET_DVR_SINGLESCREENCFG, *LPNET_DVR_SINGLESCREENCFG;

typedef struct tagNET_DVR_BIGSCREENCFG
{
    DWORD   dwSize;
	BYTE	byEnable;				// 0-Enable，1-Unable
    BYTE	byModeX;				// splice mode :x
    BYTE	byModeY;				// splice mode :y
    BYTE	byMainDecodeSystem;		// slot index of main screen in video platform, decode channel number in 64-T decoder
    BYTE	byMainDecoderDispChan;	// display of main screen，1.1netra decoder has two display channels, each of them can be used as main screen, this value is unuseful in 64-T decoder
	BYTE	byVideoStandard;		// the format of every single screen is same1:NTSC,2:PAL
    BYTE	byRes1[2];
	DWORD  dwResolution;			// the resolution of every single screen is same
    NET_DVR_SINGLESCREENCFG struFollowSingleScreen[MAX_BIGSCREENNUM]; 
    BYTE	byRes2[16];
}NET_DVR_BIGSCREENCFG, *LPNET_DVR_BIGSCREENCFG;
/////***********************************64-Tdecoder end*************************************//////


/********************************video platform scene begin*******************************/
#define  MAX_BIGSCREENNUM_SCENE 100
#define  MAX_LAYERNUMS	32
typedef struct tagNET_DVR_RECTCFG
{
	WORD wXCoordinate; //X Coordinate of upper left corner point in rectangle
	WORD wYCoordinate; //Y Coordinate of upper left corner point in rectangle
	WORD wWidth;       //width of rectangle
	WORD wHeight;      //height of rectangle
}NET_DVR_RECTCFG, *LPNET_DVR_RECTCFG;

typedef struct tagNET_DVR_WINCFG
{
	DWORD dwSize;
	BYTE  byVaild;
	BYTE  byInputIdx;			//input signal index
    BYTE  byLayerIdx;			//picture layer index, 0-the picture on the bottom
	BYTE  byTransparency;		//transparency，0～100 
	NET_DVR_RECTCFG  struWin;	//window location
    WORD wScreenHeight;			//height of screen
    WORD wScreenWidth;			//width of screen
	BYTE  byRes[20];
}NET_DVR_WINCFG, *LPNET_DVR_WINCFG;

typedef struct tagNET_DVR_RECTCFG_SCENE
{
	WORD wXCoordinate; // x Coordinate of the upper left corner
	WORD wYCoordinate; // y Coordinate of the upper left corner
	WORD wWidth;       // width of the box
	WORD wHeight;      // height of the box
}NET_DVR_RECTCFG_SCENE, *LPNET_DVR_RECTCFGSCENE;

typedef struct tagNET_DVR_SCENEDISPCFG
{       
	BYTE	byEnable;				// 0-not used，1-used
	BYTE	bySoltNum;				// slot number
	BYTE	byRes1[2]; 
    BYTE	byDispChanNum; 
    BYTE	byAudio;				// 0-close，1-open
    BYTE	byAudioWindowIdx;       // the index of window which open the audio
	BYTE	byVedioFormat;          // 1:NTSC,2:PAL,0-NULL
	BYTE	byWindowMode;			// window mode，get from the ability   
	BYTE	byEnlargeStatus;        // enlarge status, 0: does not enlarge, 1: enlarge
	BYTE    byEnlargeSubWindowIndex;// index of sub window which enlarge    
	BYTE	byScale;				// display mode，0-the real show，1-zoom display(BNC)
	DWORD   dwResolution;			// resolution
	BYTE	byJoinDecChan[MAX_WINDOWS_V41];	 // join decoder channel of the sub window
	BYTE	byJoinDecoderId[MAX_WINDOWS_V41];// decoder slot
	//resolution 1-D1,2-720P,3-1080P，the device alloc the decode channel according to this parameter
	BYTE	byDecResolution[MAX_WINDOWS_V41];
	BYTE	byRow;					// row of the screen in the whole screen wall
	BYTE	byColumn;				// column of the screen in the whole screen wall
    BYTE	byRes2[5];
	NET_DVR_RECTCFG struDisp;		// location of screen wall
} NET_DVR_SCENEDISPCFG,*LPNET_DVR_SCENEDISPCFG;

typedef struct tagDEV_CHAN_INFO_SCENE
{
	NET_DVR_IPADDR struIP;			// IP address
	WORD 	wDVRPort;			 	// port
	BYTE 	byChannel;				// channel index，the index start from 33 if the device use ip channel as 9000 dvr
	BYTE	byTransProtocol;		// trans protocol 0-TCP，1-UDP ，2-MCAST，3-RTP
	BYTE	byTransMode;			// trans mode 0－main stream 1－sub stream
	BYTE	byFactoryType;			// factory type
	BYTE	byDeviceType;			// device type 1-IPC，2- ENCODER
    BYTE	byRes[5];
	BYTE	sUserName[NAME_LEN];	// user name of the monitor
	BYTE	sPassword[PASSWD_LEN];	// password of the monitor
} NET_DVR_DEV_CHAN_INFO_SCENE,*LPNET_DVR_DEV_CHAN_INFO_SCENE;

typedef struct tagSTREAM_MEDIA_SERVER_CFG_SCENE
{
	BYTE	byValid;			// 1-use stream media 0-does not use stream media
	BYTE	byRes1[3];
	NET_DVR_IPADDR struDevIP;	// ip of stream media server
	WORD	wDevPort;			// port of stream media server
	BYTE	byTransmitType;		// transmit type 0-TCP，1-UDP
	BYTE	byRes2[5];
}NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE;

typedef struct tagPU_STREAM_CFG_SCENE
{
	NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE	streamMediaServerCfg;
	NET_DVR_DEV_CHAN_INFO_SCENE				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG_SCENE,*LPNET_DVR_PU_STREAM_CFG_SCENE;

typedef struct  tagNET_DVR_CYC_SUR_CHAN_ELE_SCENE
{
	BYTE							byEnable;				//enable status: 0－disable 1-enable
	BYTE							byRes[3];
	NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE	struStreamMediaSvrCfg;	
    NET_DVR_DEV_CHAN_INFO_SCENE			struDecChanInfo;	//decoder channel information
}NET_DVR_CYC_SUR_CHAN_ELE_SCENE,*LPNET_DVR_CYC_SUR_CHAN_ELE_SCENE;

//loop decode
typedef struct  tagNET_DVR_MATRIX_LOOP_DECINFO_SCENE
{
	WORD	wPoolTime;		//time interval of loop
	BYTE	byRes1[2];
    NET_DVR_CYC_SUR_CHAN_ELE_SCENE	struChanArray[MAX_CYCLE_CHAN/*16*/];
    BYTE    byRes2[4];
} NET_DVR_MATRIX_LOOP_DECINFO_SCENE,*LPNET_DVR_MATRIX_LOOP_DECINFO_SCENE;

//single decode channel information
typedef struct tagNET_DVR_DECODECHANCFG_SCENE/*struct size : 2064*/
{
	BYTE	byDecodeEnable; //decode mark，0-stop，1-use dynamic decode，2-use loop decode
	BYTE	bySlotNum;		//slot index
	BYTE	byDecChan;		//decoder channel index
	BYTE    byRes[5];
	union
	{
		NET_DVR_PU_STREAM_CFG_SCENE struSceneDynamicDecCfg;		//dynamic decode
		NET_DVR_MATRIX_LOOP_DECINFO_SCENE struSceneCycDecCfg;	//cycle	decode
	 } struDecCfg;
}NET_DVR_DECODECHANCFG_SCENE,*LPNET_DVR_DECODECHANCFG_SCENE;

typedef struct tagNET_DVR_BIGSCREENCFG_SCENE
{
    BYTE byAllValid;			//roam status: 0:disable 1-enable 
    BYTE byAssociateBaseMap;	//base map index，0:does not associate
    BYTE byres[2];
    NET_DVR_WINCFG struWinCfg[MAX_LAYERNUMS];
    NET_DVR_BIGSCREENCFG struBigScreen;
}NET_DVR_BIGSCREENCFG_SCENE, *LPNET_DVR_BIGSCREENCFG_SCENE;

typedef struct tagNET_DVR_MATRIX_SCENECFG
{
    DWORD dwSize;
    BYTE  sSceneName[NAME_LEN];
    BYTE  byBigScreenNums;	//big screen numbers, the max number should get from the ability
    BYTE  byRes1[3];
    WORD  wDecChanNums;		//decode channel numbers
    WORD  wDispChanNums;	//display channel numbers
    BYTE  byRes2[12];
    BYTE  *pBigScreenBuffer;//buffer store big screen struct, byBigScreenNums×sizeof(NET_DVR_BIGSCREENCFG_SCENE)
    BYTE  *pDecChanBuffer;	//buffer store decode channel, wDecChanNums×sizeof(NET_DVR_DECODECHANCFG_SCENE)
    BYTE  *pDispChanBuffer;	//buffer store display channel, wDispChanNums×sizeof(NET_DVR_SCENEDISPCFG)
}NET_DVR_MATRIX_SCENECFG, *LPNET_DVR_MATRIX_SCENECFG;

/********************************video platform scene end*******************************/

/********************************NetAlarmHost begin*******************************/
//////////subsystem config/////////////
#define MAX_ALARMHOSTKEYBOARD 64 //max keyboards of alarmhost
typedef struct tagNET_DVR_ALARMSUBSYSTEMPARAM
{
    DWORD   dwSize;
    WORD    wEnterDelay;//enter delay  uint:s
    WORD	wExitDelay;//exit delay :s
    BYTE 	byJointAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];//Use by byte，associated Alarm in channel，0-not to join，1-join
    BYTE 	byJointKeyboard[MAX_ALARMHOSTKEYBOARD/*64*/];//use by byte ，support keyboard，0-not to join，1-join
    BYTE 	byRes[80];			//res
}NET_DVR_ALARMSUBSYSTEMPARAM, *LPNET_DVR_ALARMSUBSYSTEMPARAM;

//////////GPRS parameter config/////////////
#define	ACCOUNTNUM_LEN 			6
#define	APN_NAME_LEN			32
#define	APN_USERNAME_LEN		24
#define	APN_USERPASSWORD_LEN	16

typedef struct _tagNET_DVR_ALARMHOST_NETPARAM
{ 
	DWORD dwSize;
	NET_DVR_IPADDR struIP;
	WORD	wPort;
	BYTE	byRes1[2];
	BYTE	byDomainName[MAX_DOMAIN_NAME/*64*/]; //domain name, it is valid when config GPRS and it is not be used when config netword
	BYTE	byReportProtocol;		//1-private 2-NAL2300
	BYTE	byDevID[ACCOUNTNUM_LEN/*6*/]; //it is valid while the protocol is NAL2300
	BYTE	byRes2[33]; 
}NET_DVR_ALARMHOST_NETPARAM,  *LPNET_DVR_ALARMHOST_NETPARAM;

typedef struct _tagNET_DVR_ALARMHOST_GPRS_CFG
{
	DWORD	dwSize;
	NET_DVR_ALARMHOST_NETPARAM struNetCenter[MAX_CENTERNUM]; //center parameters 
	BYTE 	byAPNName[APN_NAME_LEN/*32*/];
	BYTE	byAPNUserName[APN_USERNAME_LEN/*24*/];
	BYTE	byAPNPassWord[APN_USERPASSWORD_LEN/*16*/];
	BYTE	byReconnTime;	//Reconnect time, it is started when connecting is failed, unit: 10s range:(1-30)
	BYTE	byOverTime;		//Overtime, if there is no valid data in the OverTime，reconnect range: 1-254，unit :30s
	BYTE	byDetectLinkTime;	// range 1-30，unit:10s
	BYTE	byRes1;
	BYTE	bySIMNum[NAME_LEN/*32*/]; //SIM number
	NET_DVR_IPADDR	struSIMIP;	  //Get only
	BYTE	byRes2[64];
}NET_DVR_ALARMHOST_GPRS_CFG, *LPNET_DVR_ALARMHOST_GPRS_CFG;


//////////net parameter config/////////////
typedef struct _tagNET_DVR_ALARMHOST_NETCFG
{
	DWORD dwSize;
	NET_DVR_ALARMHOST_NETPARAM 	struNetCenter[MAX_CENTERNUM];
	BYTE	byRes1[32];
}NET_DVR_ALARMHOST_NETCFG,  *LPNET_DVR_ALARMHOST_NETCFG;

//////////report mode/////////////
#define	MAX_REPORTCHAN_NUM		4
#define	MAX_CENTERGROUP_NUM		16
typedef struct _tagNET_DVR_ALARMHOST_REPORTCENTER_CFG
{
	DWORD	dwSize;
	BYTE	byValid;  
	BYTE	byRes[3]; 
	BYTE	byChanAlarmMode[MAX_REPORTCHAN_NUM/*4*/];	//alarm channels， 1-T1、2-T2、 3-N1、 4-N2、5-G1、 6-G2
	BYTE	byDealFailCenter[MAX_CENTERGROUP_NUM/*16*/]; //send to these centers while send faile 0-not choose、1-choose
	BYTE	byDataType;	//1-alarm date 2-not alarm data 3-all data
	BYTE	byRes2[15];	//
}NET_DVR_ALARMHOST_REPORTCENTER_CFG, *LPNET_DVR_ALARMHOST_REPORTCENTER_CFG;

/********************************NetAlarmHost end*********************************/

// Stream record status
typedef struct tagNET_DVR_STREAM_RECORD_STATUS
{
	DWORD          dwSize;
	BYTE			byRecord;         //(Read only)record type, 0：not record 1：recording
	BYTE			byRes1[3];        
	DWORD			dwRelatedHD;      //Related hard disk
	BYTE			byRes2[8];        
}NET_DVR_STREAM_RECORD_STATUS, *LPNET_DVR_STREAM_RECORD_STATUS;


typedef struct tagNET_DVR_DIRECT_CONNECT_CHAN_INFO
{
    BYTE		byEnable;					//Enable or not
	BYTE		byProType;					//Protocol type 0-Hik(default), need ability to get
    BYTE		byRes1[2];					
    BYTE		sUserName[NAME_LEN];		//User name
    BYTE		sPassword[PASSWD_LEN];	    //password
    BYTE		byDomain[MAX_DOMAIN_NAME];	//Domain
    NET_DVR_IPADDR  struIP;				        //IP adrress
	WORD		wDVRPort;			 	    //Port
	BYTE		byStreamType;               //Stream type 0:Main stream 1: Sub stream
	BYTE		byRes2;					    
	DWORD		dwChannel;                  //Channel number
	BYTE		byRes3[28];				    
}NET_DVR_DIRECT_CONNECT_CHAN_INFO, *LPNET_DVR_DIRECT_CONNECT_CHAN_INFO;

typedef union tagNET_DVR_STREAM_TYPE_UNION
{
    NET_DVR_DIRECT_CONNECT_CHAN_INFO	struChanInfo;	      //IP Channel information
    NET_DVR_PU_STREAM_URL				struStreamUrl;        //Stream url
}NET_DVR_STREAM_TYPE_UNION, *LPNET_DVR_STREAM_TYPE_UNION;

typedef struct tagNET_DVR_STREAM_MODE_TYPE
{
	BYTE					byGetStreamType;	//Stream type 0-direct get stream from device，1-from stream media、2-From IPServer to device ip to get stream, 3.From IPServer find device，then get stream by stream media 4-From stream media by URL
	BYTE					byRes[3];			
    NET_DVR_STREAM_TYPE_UNION	uGetStream;			
}NET_DVR_STREAM_MODE_TYPE, *LPNET_DVR_STREAM_MODE_TYPE;

// Stream source information
typedef struct tagNET_DVR_STREAM_SRC_INFO
{
	DWORD					dwSize;
	NET_DVR_STREAM_MODE_TYPE	struStreamSrcInfo;
}NET_DVR_STREAM_SRC_INFO,*LPNET_DVR_STREAM_SRC_INFO;

// Stream record information
typedef struct 
{
	DWORD			dwSize;
	NET_DVR_RECORD_V30	struRecordInfo;
}NET_DVR_STREAM_RECORD_INFO, *LPNET_DVR_STREAM_RECORD_INFO;

//  lock record by time and stream id
typedef struct tagNET_DVR_STREAM_TIME_LOCK
{
	DWORD			dwSize;				
	NET_DVR_TIME		strBeginTime;	
	NET_DVR_TIME		strEndTime;			
	NET_DVR_STREAM_INFO struStreamInfo;		// Stream info
	DWORD			dwRecordType;	
	DWORD			dwLockDuration;	  // 0xffffffff: always lock
	BYTE			byRes[12];
}NET_DVR_STREAM_TIME_LOCK, *LPNET_DVR_STREAM_TIME_LOCK;




typedef struct tagNET_DVR_MANUAL_RECORD_PARA
{
	NET_DVR_STREAM_INFO struStreamInfo; 
	DWORD			lRecordType;
	BYTE			byRes[32];
}NET_DVR_MANUAL_RECORD_PARA, *LPNET_DVR_MANUAL_RECORD_PARA;


/*******************************config screen window*******************************/
#define MAX_WIN_COUNT  224 //maximum of windows

typedef struct tagNET_DVR_SCREEN_WINCFG
{
	DWORD	dwSize;
	BYTE	byVaild;
	BYTE	byInputType;		//CAM_MDOE
	WORD	wInputIdx;			//index of input
    DWORD	dwLayerIdx;			//index of layer, 0- layer is on the bottom 
	NET_DVR_RECTCFG  struWin;	//window location, relativity to the display wall
	BYTE	byWndIndex;			//index of window
	BYTE	byCBD;				//0-NULL，1-has background，2-no background
	BYTE	bySubWnd;			//0-yes，1-no
	BYTE	byDeviceID[16];		//device ID
	BYTE	byRes[5];
}NET_DVR_SCREEN_WINCFG, *LPNET_DVR_SCREEN_WINCFG;

typedef struct tagNET_DVR_WINLIST
{
	DWORD	dwSize;
	WORD	wScreenSeq;	//index of screen
	BYTE	byRes[10];
	DWORD	dwWinNum;	//window numbers
	BYTE    *pBuffer;	//buffer used for window information, maximum length is 224*sizeof(NET_DVR_WINCFG)
	DWORD   dwBufLen;	//length of buffer
}NET_DVR_WINLIST,*LPNET_DVR_WINLIST;

/*******************************Config layout*******************************/

#define MAX_LAYOUT_COUNT 16		//maximun of layout
typedef struct tagNET_DVR_LAYOUTCFG
{
	DWORD dwSize;
    BYTE  byValid;								//is the layout valid.  0-not valid , 1-valid
    BYTE  byRes1[3];
    BYTE  byLayoutName[NAME_LEN/*32*/];			//name of layout			
	NET_DVR_SCREEN_WINCFG struWinCfg[MAX_WIN_COUNT/*224*/];	//window parameter in the plan
	BYTE  byRes2[16];
}NET_DVR_LAYOUTCFG, *LPNET_DVR_LAYOUTCFG;

typedef struct tagNET_DVR_LAYOUT_LIST
{
    DWORD dwSize;
    NET_DVR_LAYOUTCFG struLayoutInfo[MAX_LAYOUT_COUNT/*16*/];
    BYTE byRes[4];
}NET_DVR_LAYOUT_LIST, *LPNET_DVR_LAYOUT_LIST;

/*******************************Config signal source of input******************************/
#define MAX_CAM_COUNT  224

typedef enum tagNET_DVR_CAM_MODE
{
	NET_DVR_UNKNOW  = 0,//无效
	NET_DVR_CAM_BNC,
	NET_DVR_CAM_VGA,
	NET_DVR_CAM_DVI,
	NET_DVR_CAM_HDMI,
	NET_DVR_CAM_IP,
	NET_DVR_CAM_RGB,
	NET_DVR_CAM_DECODER
}NET_DVR_CAM_MODE;

typedef struct _NET_DVR_INPUTSTREAMCFG
{
	DWORD	dwSize ;
	BYTE	byValid ;
	BYTE	byCamMode;						//the type of signal source
    WORD	wInputNo;						//the index of signal source0-224
    BYTE	sCamName[NAME_LEN] ;			//the name of signal source
	NET_DVR_VIDEOEFFECT struVideoEffect;	//video parameter
	NET_DVR_PU_STREAM_CFG	struPuStream;	//stream media parameter
	WORD	wBoardNum ;						//index of board which has this signal source 
	WORD	wInputIdxOnBoard;				//station of signal source in the board
	WORD	wResolutionX;					//resolution
	WORD	wResolutionY;
	BYTE	byVideoFormat;					//vedio format，0-NULL，1-NTSC，2-PAL
	BYTE	byNetSignalResolution;			//1-CIF 2-4CIF 3-720P 4-1080P 5-500wp the resolution of net signal，device alloc resource according to this parameter。
	BYTE	sGroupName[NAME_LEN/*32*/];	//group name of net signal
	BYTE	byRes[2];  
}NET_DVR_INPUTSTREAMCFG, *LPNET_DVR_INPUTSTREAMCFG;

typedef struct tagNET_DVR_INPUTSTREAM_LIST
{
    DWORD dwSize;
    NET_DVR_INPUTSTREAMCFG struInputStreamInfo[MAX_CAM_COUNT];
    BYTE byRes[4];
}NET_DVR_INPUTSTREAM_LIST, *LPNET_DVR_INPUTSTREAM_LIST;

/*******************************config output channels*******************************/
typedef struct _NET_DVR_OUTPUTPARAM
{
	DWORD  dwSize;
	BYTE   byMonMode;		//output mode,1-BNC,2-VGA,3-DVI,4-HDMI
	BYTE   byRes1[3];
	DWORD  dwResolution;	//resolution;
	NET_DVR_VIDEOEFFECT  struVideoEffect;	//video parameter
	BYTE	byRes2[32];
}NET_DVR_OUTPUTPARAM, *LPNET_DVR_OUTPUTPARAM;

typedef struct _NET_DVR_OUTPUTCFG
{
	DWORD dwSize;
	BYTE byScreenLayX;						//maximum screen numbers in x coordinate of the layout
	BYTE byScreenLayY;						//maximum screen numbers in x coordinate of the layout
	BYTE byRes1[6];
	NET_DVR_OUTPUTPARAM  struOutputParam;	//video parameter of output channels
	BYTE byRes2[24];
}NET_DVR_OUTPUTCFG, *LPNET_DVR_OUTPUTCFG;

/*******************************ability*******************************/
#define SCREEN_PROTOCOL_NUM  	20    //maximum numbers of screen controller's protocol
//ability of screen server
typedef struct tagNET_DVR_SCREENSERVER_ABILITY
{
    DWORD dwSize;   			
    BYTE byIsSupportScreenNum; //support numbers of screen
    BYTE bySerialNums;			//serial numbers
    BYTE byMaxInputNums;
    BYTE byMaxLayoutNums;
    BYTE byMaxWinNums;
    BYTE byRes1[19];
    BYTE byMaxScreenLayX;//maximum screen numbers in x coordinate of the layout
    BYTE byMaxScreenLayY;//maximum screen numbers in x coordinate of the layout
    WORD wMatrixProtoNum; //protocol numbers of matrix
    NET_DVR_PROTO_TYPE struScreenProto[SCREEN_PROTOCOL_NUM];// maximum protocol lists of screen
    BYTE byRes2[24];
}NET_DVR_SCREENSERVER_ABILITY, *LPNET_DVR_SCREENSERVER_ABILITY;

//ability of screen controller

typedef struct tagNET_DVR_SCREENCONTROL_ABILITY
{
    DWORD dwSize;   		
	BYTE byLayoutNum; 		// numbers of layout
	BYTE byWinNum; 			// numbers of window
	BYTE byOsdNum;  		//numbers of OSD
	BYTE byLogoNum; 		//numbers of Logo
	BYTE byInputStreamNum;  //numbers of input source (local input + net signal)
	BYTE byOutputChanNum;	//numbers of output channel
	BYTE byCamGroupNum;		//numbers of camera group
	BYTE byPlanNum;    		//numbers of plan
    BYTE byIsSupportOSD;	//0-not support OSD,  1-support OSD
    BYTE byIsSupportLogo;   //0-not support logo,  1-support logo
    BYTE byIsSupportPlan;   //0-not support plan, 1-support plan
    BYTE byIsSupportGroup;  //0-not support group, 1-support group
    BYTE byIsSupportLayout; //0-not support layout, 1-support group
    BYTE byIsSupportPlayBack;  //0-not support playback 1-support playback
    BYTE byMatrixInputNum;  //maximum numbers of matrix
    BYTE byMatrixOutputNum; //maximum numbers of output
    NET_DVR_DISPINFO struVgaInfo;//VGA information
	NET_DVR_DISPINFO struBncInfo;//BNC information
	NET_DVR_DISPINFO struHdmiInfo;//HDMI information
	NET_DVR_DISPINFO struDviInfo;//DVI information
	BYTE	byWinLayer;		//window num in a screen
	BYTE	byPicSpan;		//screen number of the picture span
	WORD	wDVCSDevNum;	//max sub device num
	WORD	wNetSignalNum;	//max net signal num
	BYTE	byRes[54];
}NET_DVR_SCREENCONTROL_ABILITY, *LPNET_DVR_SCREENCONTROL_ABILITY; 

/*******************************status of input source*******************************/
typedef struct tagNET_DVR_ANALOGINPUTSTATUS
{
	DWORD	dwLostFrame;		//the number of lost frames
	BYTE	byHaveSignal;		//is there signal? 0-no 1-yes
	BYTE	byVideoFormat;		//video format，1：NTSC,2：PAL,0：null
	BYTE	byRes[46];
} NET_DVR_ANALOGINPUTSTATUS, *LPNET_DVR_ANALOGINPUTSTATUS;

typedef union tagNET_DVR_INPUTSTATUS_UNION
{
	NET_DVR_MATRIX_CHAN_STATUS struIpInputStatus;
	NET_DVR_ANALOGINPUTSTATUS struAnalogInputStatus;
} NET_DVR_INPUTSTATUS_UNION, *LPNET_DVR_INPUTSTATUS_UNION;

typedef struct tagNET_DVR_INPUTSTATUS
{
	WORD	wInputNo;		//index of source
	BYTE	byInputType;	//CAM_MODE
	BYTE	byRes1[9];
	NET_DVR_INPUTSTATUS_UNION struStatusUnion;
	BYTE	byRes2[16];
} NET_DVR_INPUTSTATUS, *LPNET_DVR_INPUTSTATUS;

typedef struct tagNET_DVR_SCREENINPUTSTATUS
{
	DWORD	dwSize;
	BYTE	byRes[12];
	DWORD	dwNums;		//the numbers of input source states
	BYTE    *pBuffer;	//buffer
	DWORD   dwBufLen;	//the len of buffer
}NET_DVR_SCREENINPUTSTATUS,*LPNET_DVR_SCREENINPUTSTATUS;

/*******************************alarm of screen*******************************/
typedef struct _NET_DVR_SCREENALARMCFG
{
	DWORD	dwSize;
    BYTE	byAlarmType;	//alarm type，1-subboard pull out，2-Insert subboard，3-subsystem abnormal，4-subsystem restoration 5-input source abnormal   6-alarm of temperature 7-FPGA version mismatch 8-begin plan 9-plan over
	BYTE	byBoardType;	// 1-input board 2-output board 
	BYTE	bySubException;	//sub exception when input exception occur 1- change resolution normal 2-change interface 3-resolution error 4-resolution change, lead to alloc resource error 5-resolution change, lead to window size is not in the normal range 6-resolution return to normal
	BYTE	byRes1; 
    WORD	wStartInputNum; // input source exception , starting point
	WORD	wEndInputNum;	// input source exception , stopping point 
    BYTE	byRes2[16];	   
}NET_DVR_SCREENALARMCFG, *LPNET_DVR_SCREENALARMCFG;

/*******************************config the screen server*******************************/
typedef struct tagNET_DVR_MATRIX_CFG
{
    BYTE  byValid;				//is the analog platform valid; 0- not valid,  1-valid 
    BYTE  byCommandProtocol;	//the command of platform , 1-MATRIX_COMMAND_V1， 2-MATRIX_COMMAND_V2, 3-MATRIX_COMMAND_V3, 4-MATRIX_COMMAND_V4
    BYTE  byScreenType;			//screen type，1-TCL，2-zhongda
    BYTE  byRes1;
    BYTE  byScreenToMatrix[32];	//relation between screen and analog
    BYTE  byRes2[4];
}NET_DVR_MATRIX_CFG, *LPNET_DVR_MATRIX_CFG;

typedef struct tagNET_DVR_DIGITALSCREEN
{
    NET_DVR_IPADDR  struAddress;//IP if the device is a digital device
    WORD			wPort;		//port
    BYTE			byRes[26];  //
}NET_DVR_DIGITALSCREEN, *LPNET_DVR_DIGITALSCREEN;
typedef struct tagNET_DVR_ANALOGSCREEN
{
    BYTE	byDevSerPortNum;   //serial port numbers
	BYTE    byScreenSerPort;  // the index of serial port
    BYTE	byRes[130];   
    NET_DVR_MATRIX_CFG struMatrixCfg;
}NET_DVR_ANALOGSCREEN, *LPNET_DVR_ANALOGSCREEN;

typedef union tagNET_DVR_SCREEN_UNION
{
    NET_DVR_DIGITALSCREEN struDigitalScreen;
    NET_DVR_ANALOGSCREEN struAnalogScreen;
}NET_DVR_SCREEN_UNION, *LPNET_DVR_SCREEN_UNION;
typedef struct tagNET_DVR_SCREEN_SCREENINFO
{
    DWORD dwSize;
    BYTE byValid;				//Is the struct valid or not? 0-not valid,  1-valid
    BYTE nLinkMode;				//link mode，0-serial work，1-network
    BYTE byDeviceType;			//device type, get from ability
    BYTE byScreenLayX;			//lay of the screen , x coordinate
    BYTE byScreenLayY;			//lay of the screen, y coordinate
    BYTE byRes1[3];
    BYTE sUserName[NAME_LEN];	//User name
    BYTE sPassword[PASSWD_LEN]; //password   
	BYTE sDevName[NAME_LEN];	//device name
    NET_DVR_SCREEN_UNION struScreenUnion;
    BYTE byInputNum;			// input source，used for platform
	BYTE byOutputNum;			// output source , used for platform
	BYTE byCBDNum;				//CBD numbers
	BYTE byRes2[29];
} NET_DVR_SCREEN_SCREENINFO, *LPNET_DVR_SCREEN_SCREENINFO;

/*******************************upload background picture*******************************/
typedef struct _tagNET_DVR_BASEMAP_CFG
{	
    BYTE byScreenIndex;         //screen Index
	BYTE byMapNum;				//map numbers
    BYTE res[2];
	WORD wSour_width;			//source picture width
	WORD wSour_height;			//source picture height
}NET_DVR_BASEMAP_CFG, LPNET_DVR_BASEMAP_CFG;


typedef struct _tagNET_DVR_PICCFG
{
	DWORD	dwSize;		
	BYTE	byUseType;	//1use for background picture
	BYTE    bySequence; //picture index
	BYTE	byRes[2];
	NET_DVR_BASEMAP_CFG	struBasemapCfg;
	BYTE	byRes2[64];
}NET_DVR_PICTURECFG, *LPNET_DVR_PICTURECFG;
/*******************************OSD*******************************/
#define MAX_OSDCHAR_NUM 256
typedef struct _tagNET_DVR_OSDCFG
{
	DWORD   dwSize;
	BYTE    byValid;    //Is the struct valid or not? 0-not valid,  1-valid
    BYTE    	byDispMode;  //Display mode ，1-transparent，2-translucent，3-cover
    BYTE    uByFontColor_y; /*Font color Y    0-255*/
    BYTE    uByFontColor_u; /*Font color U    0-255*/
    BYTE    uByFontColor_v; /*Font color V    0-255*/
    BYTE    uByBackColor_y; /*Back color Y    0-255*/
    BYTE    uByBackColor_u; /*Back color U    0-255*/
	BYTE    uByBackColor_v; /*Back color V    0-255*/
    WORD   wXCoordinate;         /*OSD point coordinate x*/
    WORD   wYCoordinate;        /*OSD point coordinate y*/
    WORD   wWidth;       /*OSD width*/
	WORD   wHeight;      /*OSD height*/
	DWORD  dwCharCnt;     /*OSD numbers*/
    WORD   wOSDChar[MAX_OSDCHAR_NUM];       /*OSD  content*/
	BYTE   byRes[32];
}NET_DVR_OSDCFG, *LPNET_DVR_OSDCFG;

/*******************************Get Serial information*******************************/
typedef struct _tagNET_DVR_SERIAL_CONTROL
{ 
	DWORD	dwSize ;
	BYTE    bySerialNum;        // serial numbers
	BYTE	byRes1[3];
	BYTE    bySerial[32];		//serial name;
	BYTE    byRes2[32];
}NET_DVR_SERIAL_CONTROL, *LPNET_DVR_SERIAL_CONTROL;

/*******************************control screen*******************************/
typedef enum tagINPUT_INTERFACE_TYPE
{
	INTERFACE_VGA = 0,
	INTERFACE_SVIDEO,	// 2046NL does not support，2046NH support
	INTERFACE_YPBPR,
	INTERFACE_DVI ,
	INTERFACE_BNC , 
	INTERFACE_DVI_LOOP,	// (loop through) 2046NH not support，2046NL support
	INTERFACE_BNC_LOOP, // (loop through) 2046NH not support，2046NL.support
}INPUT_INTERFACE_TYPE;
typedef struct tagNET_DVR_INPUT_INTERFACE_CTRL
{
	BYTE	byInputSourceType;	//see the struct INPUT_INTERFACE_TYPE
	BYTE	byRes[15];
}NET_DVR_INPUT_INTERFACE_CTRL, *LPNET_DVR_INPUT_INTERFACE_CTRL;
//control color
typedef struct tagNET_DVR_DISPLAY_COLOR_CTRL
{
	BYTE	byColorType;		//1-brightness 2-contrast 3-saturation 4-definition
	char	byScale;			//-1 、0、+1
	BYTE	byRes[14];
}NET_DVR_DISPLAY_COLOR_CTRL, *LPNET_DVR_DISPLAY_COLOR_CTRL;
//control position
typedef struct tagNET_DVR_DISPLAY_POSITION_CTRL
{
	BYTE	byPositionType;		//1-horizontal position 2-vertical position
	char	byScale;			//-1 、0、+1
	BYTE	byRes[14];
}NET_DVR_DISPLAY_POSITION_CTRL, *LPNET_DVR_DISPLAY_POSITION_CTRL;

typedef  union tagNET_DVR_SCREEN_CONTROL_PARAM
{
	NET_DVR_INPUT_INTERFACE_CTRL 	struInputCtrl;		// choose input signal
	NET_DVR_DISPLAY_COLOR_CTRL 		struDisplayCtrl;	// change display color
	NET_DVR_DISPLAY_POSITION_CTRL 	struPositionCtrl;	// change display position 
	BYTE		byRes[16];
}NET_DVR_SCREEN_CONTROL_PARAM, *LPNET_DVR_SCREEN_CONTROL_PARAM;

typedef struct _tagNET_DVR_SCREEN_CONTROL
{ 	
	DWORD 	dwSize;			 
	DWORD  	dwCommand ;				// control command 1-open 2-close 3-choose input signal 4-control display color 5-control display position
	BYTE   	byProtocol;      		// serial protocol  1-2046NL 2-2046NH 
	BYTE	byRes1[3];
	NET_DVR_SCREEN_CONTROL_PARAM	struControlParam;
	BYTE   	byRes2[52];	
}NET_DVR_SCREEN_CONTROL, *LPNET_DVR_SCREEN_CONTROL;
/*******************************plan manage*******************************/
#define		MAX_PLAN_ACTION_NUM 	32 	//plan action number
#define		DAYS_A_WEEK				7	//7 days a week
#define		MAX_PLAN_COUNT			16	//plan count

typedef enum
{
	NET_DVR_SWITCH_LAYOUT = 1, 		// switch layout
	NET_DVR_SCREEN_POWER_OFF,  		// turn off screen
	NET_DVR_SCREEN_POWER_ON,   		// turn on screen
}NET_DVR_PLAN_OPERATE_TYPE;

/*预案项信息*/
typedef struct  tagNET_DVR_PLAN_INFO
{
	BYTE  	byValid;      	// is the plan valid
	BYTE  	byType;       	// 见定义NET_DVR_PLAN_OPERATE_TYPE
	WORD  	wLayoutNo;  	// layout number
	BYTE	byScreenStyle;    //the type of screen，1-low bright，2-high bright
	BYTE	byRes1[3];
	DWORD  	dwDelayTime;  	// plan delay time， unit /s
	BYTE	byRes2[32];
} NET_DVR_PLAN_INFO, *LPNET_DVR_PLAN_INFO;
typedef struct tagNET_DVR_CYCLE_TIME
{
	BYTE	byValid; 
	BYTE	byRes[3];
	NET_DVR_TIME_EX struTime;
}NET_DVR_CYCLE_TIME, *LPNET_DVR_CYCLE_TIME;
/*预案管理*/
typedef struct tagNET_DVR_PLAN_CFG
{
	DWORD 	dwSize;
	BYTE  	byValid;      	// is the plan valid
	BYTE  	byWorkMode;  	// the plan work mode 1-manual，2-auto，3-cycle
	BYTE	byRes1[2];
	BYTE  	byPlanName[NAME_LEN/*32*/]; //plan name
	NET_DVR_TIME_EX struTime; // time when the work mode is auto
	NET_DVR_CYCLE_TIME struTimeCycle[DAYS_A_WEEK/*7*/]; /*cycle time*/
	DWORD 	dwWorkCount;  	// plan work count，0-keep working else-count
	NET_DVR_PLAN_INFO strPlanEntry[MAX_PLAN_ACTION_NUM/*32*/];  // plan information
	BYTE	byRes2[64];
}NET_DVR_PLAN_CFG, *LPNET_DVR_PLAN_CFG;

/*预案列表*/
typedef struct tagNET_DVR_PLAN_LIST
{
	DWORD		dwSize;
	DWORD		dwPlanNums;			//input signal numbers
	BYTE  		*pBuffer;			//buffer
	BYTE		byRes1[3];
	DWORD 		dwBufLen;			//buffer size
	BYTE		byRes2[64];
} NET_DVR_PLAN_LIST,*LPNET_DVR_PLAN_LIST;

/*******************************plan control*******************************/
typedef struct tagNET_DVR_CONTROL_PARAM
{
	DWORD	dwSize;
	BYTE	sDeviceID[NAME_LEN]; //device ID
	WORD	wChan;				 //channel
	BYTE	byIndex;			 //plan 1-16(use for CVCS)
	BYTE	byRes1;
	DWORD	dwControlParam;
	BYTE	byRes2[32];
}NET_DVR_CONTROL_PARAM, *LPNET_DVR_CONTROL_PARAM;

/*******************************GET DEVICE STATUS*******************************/
typedef struct tagNET_DVR_DEVICE_RUN_STATUS
{
	DWORD 	dwSize;
	DWORD	dwMemoryTotal;		//Total Memory Unit: KByte
	DWORD	dwMemoryUsage;		//Memory Used Unit: KByte
	BYTE	byCPUUsage;			//CPU Used 0-100
	BYTE	byRes[127];
}NET_DVR_DEVICE_RUN_STATUS, *LPNET_DVR_DEVICE_RUN_STATUS;

/*******************************Picture Preview*******************************/

/******************************GET INPUT SIGNAL LIST*******************************/
typedef struct tagNET_DVR_INPUT_SGNAL_LIST
{
	DWORD		dwSize;
	DWORD		dwInputSignalNums;	//input signal numbers
	BYTE  		*pBuffer;			//buffer
	BYTE		byRes1[3];
	DWORD 		dwBufLen;			//buffer size
	BYTE		byRes2[64];
} NET_DVR_INPUT_SIGNAL_LIST,*LPNET_DVR_INPUT_SIGNAL_LIST;
/********************************Screen Controller end****************************/

/********************************ATM Safety Cabin begin *********************************/
typedef  struct tagNET_DVR_ALARMHOST_SAFETYCABINSTATE
{
	DWORD	dwSize;
	BYTE	byEnterButton;	//enter button state 0-the button is not pushed down;  1-the button is pushed down
	BYTE	byExitButton;	//exit button state 0-the button is not pushed down;  1-the button is pushed down
	BYTE	byDoorState;	//door state	0-close  1-open
	BYTE	byLockState;	//locker state 0-locked	1-unlocked
	BYTE	byUrgencyButton;	//Urgency Button state	0-the button is not pushed down;  1-the button is pushed down
	BYTE	byManState; //man state	 0-there is no one in the cabin; 1-there is someone in the cabin
	BYTE	byRes[66];
}NET_DVR_ALARMHOST_SAFETYCABINSTATE,*LPNET_DVR_ALARMHOST_SAFETYCABINSTATE;

typedef  struct tagNET_DVR_ALARMHOST_ALARMOUTSTATUS
{
	DWORD	dwSize;
	BYTE	byName[32];		//the name of Alarm output or siren
	BYTE	byAlarmType;	//1-Alarm output status, 2-SirenStatus
	WORD	wChan;			//if the byAlarmType is alarm output status, this value is 0-511；else if the byAlarmType is siren status, this value is 1-8 (there is only one siren in SAFETYCABIN)
	BYTE	byAlarmStatus; //Alarm status,   0-no alarm 1-alarm
	BYTE	byRes[32];
}NET_DVR_ALARMHOST_ALARMOUTSTATUS,*LPNET_DVR_ALARMHOST_ALARMOUTSTATUS;

//////////audio upload and download/////////////
typedef struct _tagNET_DVR_AUDIO_PARAM
{
	DWORD		dwSize;
	BYTE		byAudioFormat;      //audio format，1-G711，2-OggVorbis 
	BYTE		byRes1;
    WORD		wChannels;          // number of channels (i.e. mono, stereo...)
    DWORD		dwSamplesPerSec;	//samples per second
    BYTE		byRes2[20];			
    DWORD		dwAudioSize;		//length of audio file
}NET_DVR_AUDIO_PARAM,*LPNET_DVR_AUDIO_PARAM;

/********************************ATM Safety Cabin begin *********************************/


typedef struct tagNET_DVR_STREAM_CABAC
{
	DWORD		dwSize;              	
	BYTE 		byCabacEnable;       	//0 enable 1 disable
	BYTE  		byRes1[31];          	
}NET_DVR_STREAM_CABAC, *LPNET_DVR_STREAM_CABAC;

//2012-1-12
/********************************Intelligent HD IPC V3.1*********************************/
#define  MAX_IOSPEED_GROUP_NUM      4  //The total number of IO speed measuring groups
#define  MAX_IOOUT_NUM              4  //The total number of IO output ports
#define  MAX_IOIN_NUM               8  //The total number of IO input ports
#define  MAX_ITC_LANE_NUM           6  //The total number of lanes
#define  MAX_LANEAREA_NUM           2  //The total number of single lane areas
#define  ITC_MAX_POLYGON_POINT_NUM	20 //The max number of polygon points supported by detection area
#define  MAX_ITC_SERIALCHECK_NUM    8  //The max number of serial verification types
#define  MAX_LIGHT_NUM              6  //Max light number
#define  MAX_VIDEO_INTERVAL_NUM     2  //Max video interval number

//IO output parameter (v3.1 or later version)
typedef struct tagNET_ITC_IOOUT_PARAM
{
	DWORD    dwSize;
    BYTE     byDefaultStatus;//IO default status: 0- low level, 1- high level 
	BYTE     byIOOutStatus;//The status when IO takes effect: 0- low level, 1- high level, 2- puls
	BYTE     byRes1[2];
	DWORD    dwTimeDelay;//IO valid duration, unit: us
	WORD     wAheadTime;//Ahead time of output IO, unit: us
	BYTE     byFreqMulti;		//Multi-frequency, range [1,15]
	BYTE     byDutyRate;		//Duty rate, [0,40%]
	BYTE     byDetectBrightness;//Whether auto detect brightness enable flash light or not: 0- not detect, 1- detect
	BYTE     byBrightnessThreld;//Brightness threshold of enable flash light, value range: [0,100], flash when the value higher than the threshold
	BYTE     byFlashLightEnable;	//Enable flash light or not: 0- close, 1- open
	BYTE     byStartHour;		//Starting time, hour, value range: 0-23
	BYTE     byStartMinute;		//Starting time, minute, value range: 0-59
	BYTE     byEndHour;		    //End time, hour, value range: 0-23
	BYTE     byEndMinute;		//End time, minute, value range: 0-59
    BYTE     byRes[9];
}NET_ITC_IOOUT_PARAM, *LPNET_ITC_IOOUT_PARAM;

typedef enum _ITC_TRIGGERMODE_TYPE_
{
	ITC_POST_IOSPEED_TYPE              = 0x1,  //IO speed measuring (traffic gate)
	ITC_POST_SINGLEIO_TYPE             = 0x2,  //Single IO triggering (traffic gate)
	ITC_POST_RS485_TYPE                = 0x4,  //RS485 magnetic vehicle detector triggering (traffic gate)
	ITC_POST_RS485_RADAR_TYPE          = 0x8,  //RS485 radar triggering (traffic gate)
	ITC_POST_VIRTUALCOIL_TYPE          = 0x10,   //Virtual coil triggering (traffic gate)
	ITC_EPOLICE_IO_TRAFFICLIGHTS_TYPE  = 0x100,  //IO traffic lights (electronic police)
	ITC_EPOLICE_RS485_TYPE             = 0x200,  //RS485 magnetic vehicle detector triggering (electronic police)
	ITC_PE_RS485_TYPE                  = 0x10000,  //RS485 magnetic vehicle detector triggering(electronic police of traffic gate mode)
	ITC_VIDEO_EPOLICE_TYPE             = 0x20000  //Video triggering (electronic police of traffic gate mode)
}ITC_TRIGGERMODE_TYPE;

//Output parameter of capability set API, corresponding to pOutBuf
typedef struct tagNET_ITC_TRIGGERMODE_ABILITY
{
	DWORD dwSize;
	DWORD dwTriggerType; //Triggering type, indicated by bit, defining ITC_TRIGGERMODE_ABILITY. 
	                     //The returned triggering type is different if input ability type is different.
    BYTE byRes[16]; 
}NET_ITC_TRIGGERMODE_ABILITY, *LPNET_ITC_TRIGGERMODE_ABILITY;

typedef struct tagNET_ITC_INTERVAL_PARAM    
{
    BYTE byIntervalType;	//Interval type (default by time), 0- take effect by time, 1- take effect by distance
    BYTE byRes1[3];
    WORD wInterval[MAX_INTERVAL_NUM];//Continuous snapping interval time (unit: ms) or continuous snapping interval distance (unit: decimeter).
	                        //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance.
    BYTE byRes[8];
}NET_ITC_INTERVAL_PARAM, *LPNET_ITC_INTERVAL_PARAM;

//Plate recognition parameter
typedef struct tagNET_ITC_PLATE_RECOG_PARAM
{
    BYTE byDefaultCHN[MAX_CHJC_NUM]; //Shortening of province Chinese name
    BYTE byEnable;      //Whether enable plate recognition in this area: 0- no, 1- yes
    DWORD dwRecogMode;  /*Recognition type,
						bit0-recognition direction: 0-from front,1-from back(back plate recognition); 
						bit1-Big plate of little plate: 0-little plate,1-Big plate; 
						bit2-Colour recognition: 0-disable colour recognition,1-Enable colour recognition; 
						bit3-Agricultural car recognition: 0-disable,1-enable; 
						bit4-Blur recognition: 0-disable,1-enable; 
						bit5-Frame location or scene location: 0-Frame location,1-Scene location; 
						bit6-Frame recognition or scene recognition: 0-Frame recognition,1-Scene recognition;
						bit7-Day or night:0- day, 1- night*/
    BYTE  byRes[32];
}NET_ITC_PLATE_RECOG_PARAM, *LPNET_ITC_PLATE_RECOG_PARAM;

//Polygon structure
typedef struct tagNET_ITC_POLYGON
{
	DWORD dwPointNum; //Valid point, >=3, if three points are on a straight line, or the lines cross, it is considered to invalid area 
	NET_VCA_POINT  struPos[ITC_MAX_POLYGON_POINT_NUM]; //Polygon boundary point, the max number is 20 
}NET_ITC_POLYGON, *LPNET_ITC_POLYGON;

typedef struct tagNET_ITC_PLATE_RECOG_REGION_PARAM    
{
	BYTE byMode; //Area type: 0- rectangle, 1- polygon
	BYTE byRes1[3];
	union
	{
		NET_VCA_RECT struRect;  //Rectangle area
		NET_ITC_POLYGON struPolygon; //Polygon area
	}uRegion;
	BYTE  byRes[16];    //Reserved
}NET_ITC_PLATE_RECOG_REGION_PARAM, *LPNET_ITC_PLATE_RECOG_REGION_PARAM;

//Speed measuring parameter of single group IO
typedef struct tagNET_ITC_SINGLE_IOSPEED_PARAM
{
    BYTE byEnable; //Whether enable or not: 0- no, 1- yes
    BYTE byTrigCoil1; //The IO related with the first coil: 0- IO1, 1- IO2, 2- IO3, 3- IO4, 4- IO5, 5- IO6
    BYTE byCoil1IOStatus;//The input status of IO related with the first coil: 0- falling edge(default), 1- rising edge, 2- rising edge and falling edge, 
	                     //3- high level, 4- low level
    BYTE byTrigCoil2; //The IO related with the second coil: 0- IO1, 1- IO2, 2- IO3, 3- IO4, 4- IO5, 5- IO6
    BYTE byCoil2IOStatus;//The input status of IO related with the second coil: 0- falling edge(default), 1- rising edge, 2- rising edge and falling edge, 
	                     //3- high level, 4- low level
    BYTE byRelatedDriveWay;//Related lane number
    BYTE byTimeOut;//Timeout(default: 10), unit: s
	BYTE byRes1;
    DWORD dwDistance;//Coil distance (default: 1000), unit: cm
    BYTE byCapSpeed;//Capturing speed (default: 30), unit: km/h
    BYTE bySpeedLimit;//Speed limit(default: 60), unit: km/h
    BYTE bySpeedCapEn; //Enable speed snap or not: 0- no, 1- yes
    BYTE bySnapTimes1; //Snapshot times of the first coil (default: not snap): 0- not snap, none 0- continuous times: max 5 times  
    BYTE bySnapTimes2; //Snapshot times of the second coil(default: 1): 0- not snap, none 0- continuous times: max 5 times
    BYTE byRes2[2];
    BYTE byIntervalType;	//Interval type(default: by time): 0- take effect by time, 1- take effect by distance
	WORD wInterval1[MAX_INTERVAL_NUM];//The first coil: continuous snapping interval time (unit: ms) or continuous snapping interval distance (unit:decimeter)
	                                  //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance.
	WORD wInterval2[MAX_INTERVAL_NUM];//The second coil: continuous snapping interval time (unit: ms) or continuous snapping interval distance (unit:decimeter)
	                                  //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance.
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port(can associate with multiple ports), array 0 means IO output no.1, array 1 means IO output no.2, and so forth.
	                                  //The value: 0- not related, 1- related
    BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
    BYTE byRes3[3];
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Plate recognition (there is one usable area, one area is reserved)
    BYTE  byRes[32];
}NET_ITC_SINGLE_IOSPEED_PARAM, *LPNET_ITC_SINGLE_IOSPEED_PARAM;

//IO velocimetry parameter of traffic gate
typedef struct tagNET_ITC_POST_IOSPEED_PARAM
{
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //License recognition parameter
    NET_ITC_SINGLE_IOSPEED_PARAM struSingleIOSpeed[MAX_IOSPEED_GROUP_NUM]; //Single IO velocimetry group parameter
    BYTE  byRes[32];
}NET_ITC_POST_IOSPEED_PARAM, *LPNET_ITC_POST_IOSPEED_PARAM;

//Single IO parameter
typedef struct tagNET_ITC_SINGLEIO_PARAM
{
    BYTE byDefaultStatus;//IO default triggering state: 0- low level, 1- high level
    BYTE byRelatedDriveWay;//Related traffic lane
    BYTE bySnapTimes; //Snapshot times (default: 1): 0- not snap, none 0- continuous times: max 5 times
	BYTE byRes1;
    NET_ITC_INTERVAL_PARAM struInterval; //Snapshot interval 
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port (can associate with multiple ports)
    BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
    BYTE byRes2[3];
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Plate recognition parameter
    BYTE  byRes[32];
}NET_ITC_SINGLEIO_PARAM, *LPNET_ITC_SINGLEIO_PARAM;

//Single IO triggering parameter
typedef struct tagNET_ITC_POST_SINGLEIO_PARAM
{
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
    NET_ITC_SINGLEIO_PARAM struSingleIO[MAX_IOIN_NUM]; //Single IO triggering parameter
    BYTE  byRes[32];
}NET_ITC_POST_SINGLEIO_PARAM, *LPNET_ITC_POST_SINGLEIO_PARAM;

typedef struct tagNET_ITC_LANE_PARAM
{
    BYTE byEnable; //Enable the lane or not: 0- no, 1- yes
    BYTE byRelatedDriveWay;//Related lane
    WORD wDistance; //Coil distance, to calculate speed
    WORD wTrigDelayTime; //Triggering delay time (default: 200), unit: ms
    BYTE byTrigDelayDistance; //Triggering delay distance (default: 0), unit: decimeter
    BYTE bySpeedCapEn; //Whether enable speed snap:  0- no, 1- yes
    BYTE bySignSpeed;//Sign speed limit, unit: km/h
	BYTE bySpeedLimit;//Speed limit value, unit: km/h
	BYTE bySnapTimes; //The total snapshot times (default: 1), 0- not snap, none 0- continuous times: max 5 times
	BYTE byRes1;
    NET_ITC_INTERVAL_PARAM struInterval; //Snapping interval parameter 
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port (can associate with multiple ports)
    BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
    BYTE byRes2[3];
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Lane plate recognition parameter
    BYTE  byRes[16];
}NET_ITC_LANE_PARAM, *LPNET_ITC_LANE_PARAM;

//RS485 magnetic-vehicle-detector triggering parameter of traffic gate
typedef struct tagNET_ITC_POST_RS485_PARAM
{
    BYTE byRelatedLaneNum;//The total number of related lanes
    BYTE byRes1[3]; 
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
    NET_ITC_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //Related lane parameter
    BYTE  byRes[32];
}NET_ITC_POST_RS485_PARAM, *LPNET_ITC_POST_RS485_PARAM;

typedef struct tagNET_ITC_RADAR_PARAM
{
	BYTE    byRadarType;	//Radar type: 0- no radar, 1- Andoray radar, 2- Olvia, 3- TransMicrowave, 0xff- other type
	BYTE    byLevelAngle;   //Angle to the horizontal, default: 25°, value range: 0~90°
	WORD    wRadarSensitivity; //Radar sensitivity 
    BYTE    byRes[20];
}NET_ITC_RADAR_PARAM, *LPNET_ITC_RADAR_PARAM;

//RS485 radar triggering parameter of traffic gate
typedef struct tagNET_ITC_POST_RS485_RADAR_PARAM
{
	BYTE byRelatedLaneNum;//The total number of related lanes
	BYTE byRes1[3];
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
    NET_ITC_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //Related lane parameter
    NET_ITC_RADAR_PARAM struRadar;  //Radar parameter
    BYTE  byRes[32];
}NET_ITC_POST_RS485_RADAR_PARAM, *LPNET_ITC_POST_RS485_RADAR_PARAM;

typedef struct tagNET_ITC_VTLANE_PARAM
{
	BYTE byRelatedDriveWay;//Related lane index
	BYTE bySpeedCapEn; //Enable overspeed snapshot or not: 0-no, 1- yes
	BYTE bySignSpeed;  //Sign speed limit, unit: km/h
	BYTE bySpeedLimit; //Speed limit, unit: km/h
	BYTE bySnapTimes;  //Snapshot times (default: 1): 0- not snapshot, none 0- continuous times: max 5 times
	BYTE byRes1[3];
	NET_ITC_INTERVAL_PARAM struInterval; //Snapshot interval
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port (can associate with multiple ports)
	BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
	BYTE byRes2[3];
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Plate recognition parameter
    BYTE  byRes[16];
}NET_ITC_VTLANE_PARAM, *LPNET_ITC_VTLANE_PARAM;

typedef struct tagNET_ITC_VTCOIL_INFO
{
	NET_VCA_RECT struLaneRect;  //Virtual coil region
	BYTE byTrigFlag;       //Triggering flag: : 0- triggered by vehicle head, 1- triggered by vehicle rear,2- triggered by vehicle head or rear
	BYTE byTrigSensitive;  //Triggering sensitivity, value range: 1-100
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port (can associate with multiple ports), array 0 means IO output no.1, array 1 means IO output no.1, and so forth.
	                       //The value: 0- not related, 1- related
	BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
	BYTE byRes3;
	BYTE byEnableRadar; //Whether to enable the radar velocimetry: 0- no, 1- yes
	NET_ITC_VTLANE_PARAM struLane; //Related lane parameter
    BYTE byRes[32];
}NET_ITC_VTCOIL_INFO, *LPNET_ITC_VTCOIL_INFO;

//Virtual coil triggering parameter of traffic gate
typedef struct tagNET_ITC_POST_VTCOIL_PARAM
{
    BYTE byRelatedLaneNum;//The total number of related lanes
    BYTE byIsDisplay; //Whether to display virtual coil on the video: 0- no, 1- yes
    BYTE byLoopPos;   //Triggering coil bias at night, default: 10
    BYTE byPolarLenType; //Polarizer type, 0- without polarizer, 1- add Schneider polarizer 
	BYTE byDayAuxLightMode; //Auxiliary lighting during the day mode, 0- no auxiliary lighting, 1- LED lighting, 2- flash lighting
	BYTE byVideoLaneNO; //Reference lane number of the video reference brightness
	BYTE byVideoLowTh;  //Low threshold initial value of the video reference brightness, default: 40
	BYTE byVideoHighTh; //High threshold initial value of the video reference brightness, default: 55
	BYTE byRecordMode;  //Recording flag: 0- not record, 1- record
	BYTE byRes1[3];
	WORD wResolutionX;  //Width of device current definition
	WORD wResolutionY;  //Height of device current definition
	DWORD   dwDayInitExp; //The initial value of video day exposure time, default: 2000
	DWORD   dwDayMaxExp;  //The max value of video day exposure time, default: 20000
	DWORD   dwNightExp;   //The night video exposure time, default: 3000
	DWORD   dwSnapExp;    //Snapshot exposure time
	BYTE   byDayInitGain; //The initial value of video day gain, default: 200
	BYTE   byDayMaxGain;  //The max value of video day gain, default: 400
	BYTE   byNightGain;   //Night video gain
	BYTE   bySnapGain;    //Snapshot gain
	DWORD dwSceneMode;    //Scene mode, see to SCENE_MODE
	NET_DVR_GEOGLOCATION struGeogLocation; //Address location, default: Zhejiang
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
	NET_ITC_VTCOIL_INFO struVtCoil[MAX_VL_NUM]; //Virtual coil parameter
	NET_ITC_RADAR_PARAM struRadar;  //Radar parameter
    BYTE  byRes[32];
}NET_ITC_POST_VTCOIL_PARAM, *LPNET_ITC_POST_VTCOIL_PARAM;

//IO traffic light parameter of single group
typedef struct tagNET_ITC_SINGLE_IOTL_PARAM
{
    BYTE byEnable;  //Whether to enable or not: 0- no, 1- yes
	BYTE byLightIO; //Traffic light IO, 0- IO1, 1- IO2, 2- IO3, 3- IO4, 4- IO5, 5- IO6
	BYTE byTrafficLight; //Traffic light valid status: 0- high-level voltage corresponding to red light, low-level voltage corresponding to green light, 
        	             //1- high-level voltage corresponding to green light, low-level voltage corresponding to red light
	BYTE byTrigIO;  //Triggered IO number: 0- IO1, 1- IO2, 2- IO3, 3- IO4, 4- IO5, 5- IO6
	BYTE byTrigIOStatus;//The IO status: 0- falling edge(default), 1- rising edge, 2- rising edge and falling edge, 3- high level, 4- low level
	BYTE byRelatedDriveWay;//Related lane index
	BYTE byRecordEnable;//Recording flag of running red light: 0- not record, 1- record
	BYTE byRecordType;//Recording type of running red light: 0- pre-recording, 1- delay recording
	BYTE byPreRecordTime;//Pre-recording time of running red light, default: 0, unit: s
	BYTE byRecordDelayTime;//Recording delay time of running red light, default: 0, unit: s
	BYTE byRecordTimeOut;//Cycle recording timeout of running red light, unit: s
	BYTE byRedSnapTimes; //Red light snapshot times: 0- not snapshot, none 0- continuous times: max 5 times
	BYTE byGreenSnapTimes; //Green light snapshot times: 0- not snapshot, none 0- continuous times: max 5 times
	BYTE byRes1[2];
	BYTE byIntervalType;	//Interval type (default: by time): 0- take effect by time, 1- take effect by distance
	WORD wRedInterval[MAX_INTERVAL_NUM];//Red light continuous snapshot interval time (unit: ms) or continuous snapshot interval distance (unit: decimeter)
	                                    //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance
	WORD wGreenInterval[MAX_INTERVAL_NUM];//Green light continuous snapshot interval time (unit: ms) or continuous snapshot interval distance (unit: decimeter)
	                                    //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //The related IO output port (can associate with multiple ports)
	BYTE byFlashMode;   //Flash mode of flash light: 0- flash at the same time, 1- flash in turn
	BYTE byRes2[3];
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Plate recognition parameter
    BYTE  byRes[32];
}NET_ITC_SINGLE_IOTL_PARAM, *LPNET_ITC_SINGLE_IOTL_PARAM;

//IO traffic light parameter of electronic police
typedef struct tagNET_ITC_EPOLICE_IOTL_PARAM
{
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
	NET_ITC_SINGLE_IOTL_PARAM struSingleIOTL[MAX_IOSPEED_GROUP_NUM]; //IO traffic light parameter of single group
    BYTE  byRes[32];
}NET_ITC_EPOLICE_IOTL_PARAM, *LPNET_ITC_EPOLICE_IOTL_PARAM;

typedef enum _ITC_SERIAL_PROTOCOL_
{
	ITC_PROTOCOL_UNKNOW             =  0x0,  //Unknown
	ITC_SINGLE_COIL_PROTOCOL        =  0x1,  //Single-coil magnetic vehicle detector protocol (Dynamic display: arrival, departure, departure-delay snapshot, departure plate recognition)
	ITC_DOUBLE_COIL_PROTOCOL_MODE1  =  0x2,  //Double-coil magnetic vehicle detector protocol mode no.1
          	                                 //(Dynamic display: arrival no.1, departure no.1, snapshot of departure-delay no.2, plate recognition of departure no.1)
	ITC_DOUBLE_COIL_PROTOCOL_MODE2  =  0x3,  //Double-coil magnetic vehicle detector protocol mode no.2
          	                                 //(Dynamic display: arrival no.1, departure no.2, snapshot of departure-delay no.2, plate recognition of departure no.1, default delay distance is 1m)
	ITC_DOUBLE_COIL_PROTOCOL_MODE3  =  0x4,  //Double-coil magnetic vehicle detector protocol mode no.3
	                                         //(Dynamic display: arrival no.2, departure no.1, snapshot of departure-delay no.2, plate recognition of departure no.1, default delay distance is 1m)
	ITC_OTHER_PROTOCOL              =  0xff  //Other protocol of magnetic vehicle detector
}ITC_SERIAL_PROTOCOL;

//Magnetic vehicle detector parameter
typedef struct tagNET_ITC_SERIAL_INFO
{
	BYTE bySerialProtocol; //Protocol type of magnetic vehicle detector, see to ITC_SERIAL_PROTOCOL
	BYTE byIntervalType;	//Interval type (default: by time): 0- take effect by time, 1- take effect by distance
	WORD wInterval;//Continuous snapping interval time (unit: ms) or continuous snapping interval distance (unit: decimeter)
	               //When byIntervalType is 0, it means interval time, when byIntervalType is 1, it means interval distance
    BYTE  byRes[12];
}NET_ITC_SERIAL_INFO, *LPNET_ITC_SERIAL_INFO;

typedef struct tagNET_ITC_EPOLICE_LANE_PARAM
{
	BYTE byEnable; //Whether enable this traffic lane: 0- no, 1- yes
	BYTE byRelatedDriveWay;//The related lane number
	WORD wDistance; //Coil distance, unit: cm
	BYTE byRecordEnable;//Cycle recording sign of red light running behavior: 0- not record, 1- record
	BYTE byRecordType;//Recording type of red light running behavior: 0- pre-recording，1- delay recording
	BYTE byPreRecordTime;//Pre-recording time of red light running behavior (default: 0), unit: s
	BYTE byRecordDelayTime;//Recording delay time of red light running behavior (default: 0), unit: s
	BYTE byRecordTimeOut;//Recording timeout time of red light running behavior, unit: s
	BYTE bySignSpeed;//Sign speed(Post epolice mode),km/h
	BYTE bySpeedLimit;//Speed limit(Post epolice mode), km/h
	BYTE byRes1;
	NET_ITC_SERIAL_INFO struSerialInfo; //Magnetic vehicle detector parameter
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //Related IO output port, can associating with multiple ports 
	BYTE byFlashMode;   //Flash flashing mode: 0- flash at the same time, 1- flash in turn
	BYTE byRes2[3];
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //Lane license plate recognition parameters
    BYTE  byRes[16];
}NET_ITC_EPOLICE_LANE_PARAM, *LPNET_ITC_EPOLICE_LANE_PARAM;

//RS485 magnetic vehicle detector triggering parameter of electronic police or traffic-gate electronic police 
typedef struct tagNET_ITC_EPOLICE_RS485_PARAM
{
	BYTE byRelatedLaneNum;//The total number of related lanes 
	BYTE byRes1[3]; 
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //Plate recognition parameter
	NET_ITC_EPOLICE_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //Related lane parameter
    BYTE  byRes[32];
}NET_ITC_EPOLICE_RS485_PARAM, *LPNET_ITC_EPOLICE_RS485_PARAM;

typedef union tagNET_ITC_TRIGGER_PARAM_UNION
{
	DWORD  uLen[1070];			// Parameter
	NET_ITC_POST_IOSPEED_PARAM    struIOSpeed; //(traffic gate) IO velocimetry parameter
	NET_ITC_POST_SINGLEIO_PARAM   struSingleIO; //(traffic gate) single IO parameter
	NET_ITC_POST_RS485_PARAM       struPostRs485; //(traffic gate) RS485 vehicle checker
	NET_ITC_POST_RS485_RADAR_PARAM  struPostRadar; //(traffic gate) RS485 Radar parameters
	NET_ITC_POST_VTCOIL_PARAM     struVtCoil; //(traffic gate) Virtual coil
	NET_ITC_EPOLICE_IOTL_PARAM     struIOTL;		//(electronic police) IO traffic light parameters
	NET_ITC_EPOLICE_RS485_PARAM    struEpoliceRs485; //(electronic police) RS485 magnetic vehicle detector triggering parameter
	NET_ITC_EPOLICE_RS485_PARAM  struPERs485;	//(traffic-gate electronic police) RS485 magnetic vehicle detector triggering parameter
}NET_ITC_TRIGGER_PARAM_UNION, *LPNET_ITC_TRIGGER_PARAM_UNION;

//Single triggering parameter structure
typedef struct tagNET_ITC_SINGLE_TRIGGERCFG
{
	BYTE  byEnable;	//Enable the triggering mode: 1- yes, 0- no
    BYTE  byRes1[3];
    DWORD dwTriggerType; //Triggering type, see to ITC_TRIGGERMODE_TYPE
    NET_ITC_TRIGGER_PARAM_UNION uTriggerParam; //Triggering parameter
    BYTE  byRes[64];
}NET_ITC_SINGLE_TRIGGERCFG, *LPNET_ITC_SINGLE_TRIGGERCFG;

//Triggering parameter structure
typedef struct tagNET_ITC_TRIGGERCFG
{
	DWORD   dwSize;			//Structure size
	NET_ITC_SINGLE_TRIGGERCFG  struTriggerParam;  //Single triggering parameter
    BYTE    byRes[32];
}NET_ITC_TRIGGERCFG, *LPNET_ITC_TRIGGERCFG;

//Single IO light access parameter
typedef struct tagNET_ITC_SINGLE_IO_LIGHT_PARAM
{
	BYTE byLightType; //Light type,0-left,1-straight,2-right
	BYTE byRelatedIO; //Related IO
	BYTE byRedLightState; //Red light state,0-high level,1-low level
    BYTE byRes[17];
}NET_ITC_SINGLE_IO_LIGHT_PARAM, *LPNET_ITC_SINGLE_IO_LIGHT_PARAM;

//IO light access parameter
typedef struct tagNET_ITC_IO_LIGHT_PARAM
{
	NET_ITC_SINGLE_IO_LIGHT_PARAM struIOLight[MAX_LIGHT_NUM]; //Single IO light access parameter
    BYTE byRes[8];
}NET_ITC_IO_LIGHT_PARAM, *LPNET_ITC_IO_LIGHT_PARAM;

//Single RS485 access light
typedef struct tagNET_ITC_SINGLE_RS485_LIGHT_PARAM
{
	BYTE byLightType; //Light type,0-left,1-straight,2-right
	BYTE byRelatedLightChan; //Related light channel
	BYTE byInputLight;	//input light type,0-red light,1-green 
    BYTE byRes[17];
}NET_ITC_SINGLE_RS485_LIGHT_PARAM, *LPNET_ITC_SINGLE_RS485_LIGHT_PARAM;

//RS485 access light
typedef struct tagNET_ITC_RS485_LIGHT_PARAM
{
	NET_ITC_SINGLE_RS485_LIGHT_PARAM struRS485Light[MAX_LIGHT_NUM]; //单个485接入信号灯参数
    BYTE byRes[8];
}NET_ITC_RS485_LIGHT_PARAM, *LPNET_ITC_RS485_LIGHT_PARAM;

//Light access parameter
typedef union tagNET_ITC_LIGHT_ACCESSPARAM_UNION
{
	DWORD uLen[122];
	NET_ITC_IO_LIGHT_PARAM struIOLight; //IO access light
	NET_ITC_RS485_LIGHT_PARAM struRS485Light; //485 access light
}NET_ITC_LIGHT_ACCESSPARAM_UNION, *LPNET_ITC_LIGHT_ACCESSPARAM_UNION;

//Traffic light parameter
typedef struct tagNET_ITC_TRAFFIC_LIGHT_PARAM
{
	BYTE bySource; //light source,0-IO access,1-RS485 access
	BYTE byRes1[3];
	NET_ITC_LIGHT_ACCESSPARAM_UNION struLightAccess;//light access parameter
    BYTE byRes[32];
}NET_ITC_TRAFFIC_LIGHT_PARAM, *LPNET_ITC_TRAFFIC_LIGHT_PARAM;

//violation detect type
typedef enum _ITC_VIOLATION_DETECT_TYPE_
{
    ITC_VIOLATION_POST      = 0x01, //post
	ITC_VIOLATION_DRIVELINE = 0x02, //drive line
	ITC_VIOLATION_REVERSE   = 0x04, //reverse
	ITC_VIOLATION_REDLIGHT  = 0x08, //red light
	ITC_VIOLATION_DIRECTION = 0x10, //direction
	ITC_VIOLATION_INTERSECTION_CONGEST = 0x20//intersection congest
}ITC_VIOLATION_DETECT_TYPE;

//Violation detect parameter
typedef struct tagNET_ITC_VIOLATION_DETECT_PARAM
{
	DWORD dwVioDetectType; //violation detect type, bit, see ITC_VIOLATION_DETECT_TYPE ,0-disenable,1-enable
    BYTE byRes[48];
}NET_ITC_VIOLATION_DETECT_PARAM, *LPNET_ITC_VIOLATION_DETECT_PARAM;

//Lane useage type
typedef enum _ITC_LANE_USEAGE_TYPE_
{
	ITC_LANE_USEAGE_UNKNOW     = 0,  //Unknow
	ITC_LANE_CARRIAGEWAY       = 1,   //car lane
	ITC_LANE_BUS			   = 2,   //bus lane
	ITC_LANE_FAST			   = 3,   //fast lane
	ITC_LANE_SLOW			   = 4,   //slow lane
	ITC_LANE_MOTOR			   = 5,   //motor lane
	ITC_LANE_NONMOTOR		   = 6,    //non motor lane
	ITC_LANE_REVERSE_LANE      = 7 //reverse lane
}ITC_LANE_USEAGE_TYPE;

//Lane direction type
typedef enum _ITC_LANE_DIRECTION_TYPE_
{
	ITC_LANE_DIRECTION_UNKNOW     = 0, //Unknow
	ITC_LANE_LEFT			      = 1, //left
	ITC_LANE_STRAIGHT			  = 2, //straight
	ITC_LANE_LEFT_STRAIGHT		  = 3, //left+straight
	ITC_LANE_RIGHT				  = 4, //right
	ITC_LANE_LEFT_RIGHT			  = 5, //left+right
	ITC_LANE_RIGHT_STRAIGHT		  = 6, //right+straight
	ITC_LANE_LEFT_RIGHT_STRAIGHT  = 7, //left+right+straight
	ITC_LANE_LEFT_WAIT			  = 9, //left wait
	ITC_LANE_STRAIGHT_WAIT		  = 10 //straight wait
}ITC_LANE_DIRECTION_TYPE; 

//Lane logic parameter
typedef struct tagNET_ITC_LANE_LOGIC_PARAM
{
	BYTE byUseageType; //Lane useage type,see ITC_LANE_USEAGE_TYPE
	BYTE byDirectionType; //Lane direction type, see ITC_LANE_DIRECTION_TYPE
    BYTE byRes[34];
}NET_ITC_LANE_LOGIC_PARAM, *LPNET_ITC_LANE_LOGIC_PARAM;

//Line type
typedef enum _ITC_LINE_TYPE_
{
	ITC_LINT_UNKNOW        = 0,  //Unknow
	ITC_LINE_WHITE         = 1,  //Lane write line
	ITC_LINE_STOP          = 2,  //Lane stop line
	ITC_LINE_SINGLE_YELLOW = 3,  //Lane single yellow line
	ITC_LINE_DOUBLE_YELLOW = 4,  //Lane double yellow line
	ITC_LINE_GUARD_RAIL    = 5,  //Lane guard rail line
	ITC_LINE_NO_CROSS      = 6   //Lane no cross line
}ITC_LINE_TYPE;

//Video epolice line parameter
typedef struct tagNET_ITC_LINE
{
	NET_VCA_LINE struLine; //Line parameter
	BYTE byLineType; //Line type, see ITC_LINE_TYPE
	BYTE byRes[7];
}NET_ITC_LINE, *LPNET_ITC_LINE;

//Violation detect line
typedef struct tagNET_ITC_VIOLATION_DETECT_LINE
{
	NET_ITC_LINE  struLaneLine; //Lane line
	NET_ITC_LINE  struStopLine; //Stop line
	NET_ITC_LINE  struRedLightLine; //Red light line
	NET_ITC_LINE  struCancelLine; //Cancel line
	NET_ITC_LINE  struWaitLine; //Wait line
    NET_ITC_LINE  struRes[8];
}NET_ITC_VIOLATION_DETECT_LINE, *LPNET_ITC_VIOLATION_DETECT_LINE;

//Single video epolice param
typedef struct tagNET_ITC_LANE_VIDEO_EPOLICE_PARAM
{
	BYTE byLaneNO; //Lane NO.
	BYTE byRes1[3];
	NET_ITC_LANE_LOGIC_PARAM struLane; //Lane logic param
	NET_ITC_VIOLATION_DETECT_PARAM struVioDetect; //violation detect param
	NET_ITC_VIOLATION_DETECT_LINE struLine; //Violation detect line param
	NET_ITC_POLYGON struPlateRecog; //plate recog param
    BYTE  byRes[64];
}NET_ITC_LANE_VIDEO_EPOLICE_PARAM, *LPNET_ITC_LANE_VIDEO_EPOLICE_PARAM;

//Video epolice param
typedef struct tagNET_ITC_VIDEO_EPOLICE_PARAM
{
	BYTE byEnable;	//enable,0-no,1-yes
	BYTE byLaneNum; //Lane number
	BYTE byRes1[2];
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //plate recog
	NET_ITC_TRAFFIC_LIGHT_PARAM struTrafficLight; //traffic light
	NET_ITC_LANE_VIDEO_EPOLICE_PARAM struLaneParam[MAX_ITC_LANE_NUM]; //single lane param
	NET_ITC_LINE  struLaneBoundaryLine; //Lane boundary line(the lane right boundary line
	NET_ITC_LINE  struLeftLine; //left line
	NET_ITC_LINE  struRightLine; //right line
	NET_ITC_LINE  struTopZebraLine; //top zebra line
	NET_ITC_LINE  struBotZebraLine; //bottom zebra line
    BYTE  byRes[32];
}NET_ITC_VIDEO_EPOLICE_PARAM, *LPNET_ITC_VIDEO_EPOLICE_PARAM;

typedef union tagNET_ITC_VIDEO_TRIGGER_PARAM_UNION
{
	DWORD  uLen[1150];			
	NET_ITC_VIDEO_EPOLICE_PARAM struVideoEP; //Video epolice param
}NET_ITC_VIDEO_TRIGGER_PARAM_UNION, *LPNET_ITC_VIDEO_TRIGGER_PARAM_UNION;

typedef struct tagNET_ITC_VIDEO_TRIGGER_PARAM
{
	DWORD dwSize;
	DWORD dwMode; //trigger mode,see ITC_TRIGGERMODE_TYPE
    NET_ITC_VIDEO_TRIGGER_PARAM_UNION uVideoTrigger; //video trigger param
    BYTE  byRes[32];
}NET_ITC_VIDEO_TRIGGER_PARAM, *LPNET_ITC_VIDEO_TRIGGER_PARAM;

typedef struct tagNET_DVR_STATUS_DETECTCFG
{
	DWORD  dwSize;			//Structure size
	BYTE   byEnableTrigIODetect; //Enable the status detection of triggering IO: 1- yes, 0- no
	BYTE   byEnableFlashOutDetect; //Enable the status detection of synchronous output: 1- yes, 0- no
	BYTE   byEnableRS485Detect; //Enable the detection of RS485 receiving status: 1- yes, 0- no
	BYTE   byRes[29];
}NET_DVR_STATUS_DETECTCFG, *LPNET_DVR_STATUS_DETECTCFG;

typedef enum _ITC_STATUS_DETECT_TYPE_
{
	ITC_STATUS_DETECT_NULL = 0,		//Unknown
	ITC_STATUS_DETECT_TRIGGERIO,	//Triggered IO port
	ITC_STATUS_DETECT_FLASHOUT,     //Synchronous output
	ITC_STATUS_DETECT_RS485, //RS485
	ITC_STATUS_DETECT_TRIGGERTYPE //Triggering type(reserved)
}ITC_STATUS_DETECT_TYPE;

typedef struct tagNET_ITC_TRIGGERIO_INFO
{
	BYTE byTriggerIOIndex[MAX_IOIN_NUM]; //Triggered IO port
	BYTE byRes[40]; 
}NET_ITC_TRIGGERIO_INFO, *LPNET_ITC_TRIGGERIO_INFO;

typedef struct tagNET_ITC_FLASHOUT_INFO
{
	BYTE byFlashOutIndex[MAX_IOOUT_NUM]; //Synchronous output number 
	BYTE byRes[44]; 
}NET_ITC_FLASHOUT_INFO, *LPNET_ITC_FLASHOUT_INFO;

typedef struct tagNET_ITC_SERIAL_CHECKINFO
{
	BYTE bySerialIndex[MAX_ITC_SERIALCHECK_NUM]; //RS485 verification result: 0- invalid, 1- valid, 
	                               //bySerialIndex[0] means the correct head, bySerialIndex[1] means the correct rear
	BYTE byRes[40]; 
}NET_ITC_SERIAL_CHECKINFO, *LPNET_ITC_SERIAL_CHECKINFO;

typedef struct tagNET_ITC_TRIGGERTYPE_INFO
{
	BYTE byTrigTypeIndex; //Triggering type value
	BYTE byRes[47]; 
}NET_ITC_TRIGGERTYPE_INFO, *LPNET_ITC_TRIGGERTYPE_INFO;

typedef union tagNET_ITC_STATUS_UNION
{
	BYTE   uLen[48];			//Parameter
	NET_ITC_TRIGGERIO_INFO struTrigIO; //Triggered IO port
	NET_ITC_FLASHOUT_INFO struFlashOut; //Synchronous output
	NET_ITC_SERIAL_CHECKINFO struSerial;  //Serial port
	NET_ITC_TRIGGERTYPE_INFO struTrigType; //Triggering type (reserved)
}NET_ITC_STATUS_UNION, *LPNET_ITC_STATUS_UNION;

typedef struct tagNET_ITC_STATUS_DETECT_RESULT
{
	ITC_STATUS_DETECT_TYPE dwStatusType;//Status detection type, see to ITC_STATUS_DETECT_TYPE
	NET_ITC_STATUS_UNION uStatusParam; //Status detection result
	DWORD dwHoldTime; //Light holding time(reserved), unit: ms
	BYTE byRes[32];
}NET_ITC_STATUS_DETECT_RESULT, *LPNET_ITC_STATUS_DETECT_RESULT;

typedef struct tagNET_DVR_SETUPALARM_PARAM
{
    DWORD dwSize;
	BYTE byLevel; //Arming priority: 0-high, 1-middle, 2-low
	BYTE byRes[15];
}NET_DVR_SETUPALARM_PARAM, *LPNET_DVR_SETUPALARM_PARAM;

typedef struct tagNET_ITC_VIDEO_TRIGGER_COND
{
    DWORD dwSize;
	DWORD dwChannel;
    DWORD dwTriggerMode; //video ep mode,see ITC_TRIGGERMODE_TYPE
    BYTE byRes[16];
}NET_ITC_VIDEO_TRIGGER_COND, *LPNET_ITC_VIDEO_TRIGGER_COND;

/********************************Intelligent HD IPC V3.1 end*********************************/

/********************************Face search*********************************/
typedef enum _VCA_DATABASE_TYPE_
{
	DATABASE_NULL = 0, //unknow
	DATABASE_SNAP,    //snap database
	DATABASE_FACE    //face database
}VCA_DATABASE_TYPE;

typedef struct tagNET_VCA_DATABASE_PARAM
{
	DWORD dwSize;
	DWORD dwDataBaseID; //database ID
	DWORD dwDataBaseType; //database type,see VCA_DATABASE_TYPE
	BYTE byDataBaseName[NAME_LEN]; //database name
	BYTE byAttribute[64]; //attirbute
	BYTE byRes[20];
}NET_VCA_DATABASE_PARAM, *LPNET_VCA_DATABASE_PARAM;

typedef struct tagNET_VCA_FIND_DATABASE_COND
{
	DWORD dwDataBaseType; //database type,see VCA_DATABASE_TYPE
	BYTE byRes[12]; 
}NET_VCA_FIND_DATABASE_COND, *LPNET_VCA_FIND_DATABASE_COND;

typedef struct tagNET_VCA_DELETE_DATABASE_COND
{
	DWORD dwSize;
	DWORD dwDataBaseType; //Database id, see VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //database ID
	BYTE byRes[64]; 
}NET_VCA_DELETE_DATABASE_COND, *LPNET_VCA_DELETE_DATABASE_COND;

typedef struct tagNET_VCA_INQUIRE_SNAPDB_COND
{
	DWORD dwChannel;//channel NO.
    NET_DVR_TIME struStartTime;//start time
	NET_DVR_TIME struStopTime;//stop time
	BYTE bySex; //sex:0-non,1-man,2-woman
	BYTE byRes1[3]; 
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //start birthdate, for:201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //end birthdate,for:201106
	BYTE byAttribute1[NAME_LEN]; //Attribute1
	BYTE byAttribute2[NAME_LEN]; //Attribute2
	BYTE byRes[12]; 
}NET_VCA_INQUIRE_SNAPDB_COND, *LPNET_VCA_INQUIRE_SNAPDB_COND;

typedef struct tagNET_VCA_INQUIRE_SNAPRECORD_RESULT
{ 
	DWORD dwSize; 
	DWORD dwDataBaseID;  //database ID
	DWORD dwRecordID; //record ID
	NET_DVR_TIME struSnapTime;  //Snap Time
	BYTE bySex; //sex:0-non,1-man,2-woman
	BYTE byRes1[3]; 
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //start birthdate, for:201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //end birthdate,for:201106
	BYTE byAttribute1[NAME_LEN]; //Attribute1
	BYTE byAttribute2[NAME_LEN]; //Attribute2
	DWORD dwFacePicID; //face picture ID
	DWORD dwFacePicLen;  //face picture length
	BYTE byRes[80];  
	BYTE *pFacePic;    //face picture data
}NET_VCA_INQUIRE_SNAPRECORD_RESULT, *LPNET_VCA_INQUIRE_SNAPRECORD_RESULT;

typedef union tagNET_VCA_DELETE_SNAPRECORD_COND_UNION
{ 
	NET_VCA_INQUIRE_SNAPDB_COND struAttribute;  //information(bulk delete)
	DWORD dwRecordID; //record ID(single delete)
}NET_VCA_DELETE_SNAPRECORD_COND_UNION, *LPNET_VCA_DELETE_SNAPRECORD_COND_UNION;

typedef enum _VCA_DELETE_RECORD_TYPE_
{
	DELETE_RECORD_SINGLE = 0, //single delete
	DELETE_RECORD_BATCH    //bulk delete
}VCA_DELETE_RECORD_TYPE;

typedef struct tagNET_VCA_DELETE_SNAPRECORD_COND
{ 
    VCA_DELETE_RECORD_TYPE dwDeleteType; //delete type
	NET_VCA_DELETE_SNAPRECORD_COND_UNION uDeleteCond;  //delete condition
	BYTE  byRes[40]; 
}NET_VCA_DELETE_SNAPRECORD_COND, *LPNET_VCA_DELETE_SNAPRECORD_COND;

typedef enum _VCA_SEARCH_DATABASE_TYPE_
{
    VCA_NORMAL_SEARCH_DATABASE   = 0x00000000,   //normal search
	VCA_ADVANCE_SEARCH_DATABASE  = 0x00000001    //advance search
}VCA_SEARCH_DATABASE_TYPE;

typedef struct tagNET_VCA_ADVANCE_SEARCH_DATABASE_COND
{
    DWORD dwDataBaseType; //database type,see VCA_DATABASE_TYPE
    DWORD dwDataBaseID; //database ID
	DWORD dwFacePicID; //face picture ID
	BYTE byRes[36];
}NET_VCA_ADVANCE_SEARCH_DATABASE_COND, *LPNET_VCA_ADVANCE_SEARCH_DATABASE_COND;

typedef union tagNET_VCA_SEARCH_DATABASE_COND_UNION
{
    DWORD uLen[25];
	NET_VCA_REGISTER_PIC struNormalFind; //normal search
	NET_VCA_ADVANCE_SEARCH_DATABASE_COND struAdvanceFind; //advance search
}NET_VCA_SEARCH_DATABASE_COND_UNION, *LPNET_VCA_SEARCH_DATABASE_COND_UNION;

typedef struct tagNET_VCA_SEARCH_DATABASE_PARAM
{
	DWORD dwSearchType; //search type,see VCA_SEARCH_DATABASE_TYPE
	NET_VCA_SEARCH_DATABASE_COND_UNION uSearchCond; //search parameter
	BYTE byRes[16];
}NET_VCA_SEARCH_DATABASE_PARAM, *LPNET_VCA_SEARCH_DATABASE_PARAM;

typedef struct tagNET_VCA_SEARCH_SNAPDB_COND
{ 
	DWORD dwChannel; //channel NO.
    DWORD dwDataBaseID; //database ID
	NET_DVR_TIME struStartTime;//start time
	NET_DVR_TIME struStopTime;//stop time
	BYTE bySex; //sex:0-non,1-man,2-woman
	BYTE byRes1[3]; 
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //start birthdate, for:201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //end birthdate, for:201106
	BYTE byAttribute1[NAME_LEN]; //Attribute1
	BYTE byAttribute2[NAME_LEN]; //Attribute2
	NET_VCA_SEARCH_DATABASE_PARAM struSearchParam;  //Search parameter
	DWORD dwMaxSearchNum; //max seatch number
	WORD wThreshold;  //threshold,0-100
	BYTE  byRes[78]; 
}NET_VCA_SEARCH_SNAPDB_COND, *LPNET_VCA_SEARCH_SNAPDB_COND;

typedef struct tagNET_VCA_SEARCH_SNAPRECORD_RESULT
{ 
	DWORD dwSize; 
	DWORD dwDataBaseID;  //database ID
    DWORD dwRecordID; //record ID
	NET_DVR_TIME struSnapTime;//snap time
	BYTE bySex; //sex:0-non,1-man,2-woman
	BYTE byRes1[3]; 
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //start birthdate, for:201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //end birthdate, for:201106
	BYTE byAttribute1[NAME_LEN]; //Attribute1
	BYTE byAttribute2[NAME_LEN]; //Attribute2
	float fSimilarity; //similarity,[0.001,1]
	DWORD dwFacePicID; //face picture ID
	DWORD dwFacePicLen;  //face picture length
	BYTE byRes[80];  
	BYTE *pFacePic;    //face picture data
}NET_VCA_SEARCH_SNAPRECORD_RESULT, *LPNET_VCA_SEARCH_SNAPRECORD_RESULT;

typedef struct tagNET_VCA_DATARECORD_INFO
{ 
	DWORD dwSize; 
    DWORD dwRecordID; //record ID, update record valid
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //human attribure
	NET_VCA_REGISTER_PIC struRegisterPic;  //human picture information
	BYTE  byRemark1[NAME_LEN]; //remark1
	BYTE  byRemark2[64]; //remark2
	BYTE  byRes[32]; //
}NET_VCA_DATARECORD_INFO, *LPNET_VCA_DATARECORD_INFO;

typedef struct tagNET_VCA_FAST_DATARECORD_INFO
{ 
	DWORD dwSize; 
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //human attribure
	BYTE  byRemark1[NAME_LEN]; //remark1
	BYTE  byRemark2[64]; //remark2
	DWORD dwImageLen;  //image length
	BYTE  byRes[80];  //
	BYTE *pImage;    //image data
}NET_VCA_FAST_DATARECORD_INFO, *LPNET_VCA_FAST_DATARECORD_INFO;

typedef struct tagNET_VCA_INQUIRE_DATARECORD_RESULT
{ 
	DWORD dwSize; //
	DWORD dwDataBaseID;  //database ID
    DWORD dwRecordID; //record ID
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //human attribute
	BYTE  byRemark1[NAME_LEN]; //remark1
	BYTE  byRemark2[64]; //remark2
	DWORD dwFacePicID; //face picture ID
	DWORD dwFacePicLen;  //face picture length
	BYTE byRes[80];  //
	BYTE *pFacePic;    //face picture data
}NET_VCA_INQUIRE_DATARECORD_RESULT, *LPNET_VCA_INQUIRE_DATARECORD_RESULT;

typedef struct tagNET_VCA_SEARCH_DATARECORD_RESULT
{ 
	DWORD dwSize; 
	DWORD dwDataBaseID;  //database ID
    DWORD dwRecordID; //record ID
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //human attribute
	BYTE  byRemark1[NAME_LEN]; //remark1
	BYTE  byRemark2[64]; //remark2
	float fSimilarity; //similarity,[0.001,1]
	DWORD dwFacePicID; //face picture ID
	DWORD dwFacePicLen;  //face picture length
	BYTE byRes[80];  //
	BYTE *pFacePic;    //face picture data
}NET_VCA_SEARCH_DATARECORD_RESULT, *LPNET_VCA_SEARCH_DATARECORD_RESULT;

typedef struct tagNET_VCA_DATARECORD_COND
{ 
	DWORD dwDataBaseID; //database ID
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //human attribute
	BYTE byRes[80];  //
}NET_VCA_DATARECORD_COND, *LPNET_VCA_DATARECORD_COND;

typedef union tagNET_VCA_DELETE_RECORD_COND_UNION
{ 
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //human attribute(batch delete)
	DWORD dwRecordID; //record ID(single delete)
}NET_VCA_DELETE_RECORD_COND_UNION, *LPNET_VCA_DELETE_RECORD_COND_UNION;

typedef struct tagNET_VCA_DELETE_RECORD_COND
{ 
    VCA_DELETE_RECORD_TYPE dwDeleteType; //delete type
	NET_VCA_DELETE_RECORD_COND_UNION uDeleteCond;  //delete parameter
	BYTE  byRes[40]; //
}NET_VCA_DELETE_RECORD_COND, *LPNET_VCA_DELETE_RECORD_COND;

typedef struct tagNET_VCA_SEARCH_FACEDB_COND
{ 
	DWORD dwDataBaseID; //Database ID
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //Human attribute
	NET_VCA_SEARCH_DATABASE_PARAM struSearchParam;  //Search parameter
	DWORD dwMaxSearchNum; //Max search number
	WORD wThreshold;  //threshold, 0-100
	BYTE  byRes[78]; //
}NET_VCA_SEARCH_FACEDB_COND, *LPNET_VCA_SEARCH_FACEDB_COND;

typedef struct tagNET_VCA_FIND_MATCHPIC_COND
{
	DWORD dwSize;
	DWORD dwDataBaseType; //database ID, see VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //database ID
	DWORD dwRecordID; //record ID
	BYTE byRes[64]; //
}NET_VCA_FIND_MATCHPIC_COND, *LPNET_VCA_FIND_MATCHPIC_COND;

typedef struct tagNET_VCA_FIND_MATCHPIC_RESULT
{
	DWORD dwSize;
	DWORD dwDataBaseType; //database ID, see VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //databaseID
	DWORD dwRecordID; //record ID
	DWORD dwPicLen; //picture length
	BYTE byRes[64]; //
	BYTE *pPicBuffer; //picture data
}NET_VCA_FIND_MATCHPIC_RESULT, *LPNET_VCA_FIND_MATCHPIC_RESULT;

/********************************VCA face end*********************************/

/********************************IPC*************************/
typedef struct tagNET_DVR_REMOTECONTROL_ALARM_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //channel
	WORD wDealyTime; //delay time,unit:s
	BYTE  byRes[30]; 
}NET_DVR_REMOTECONTROL_ALARM_PARAM, *LPNET_DVR_REMOTECONTROL_ALARM_PARAM;

typedef struct tagNET_DVR_REMOTECONTROL_STUDY_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //channel
	BYTE  byRes[16]; 
}NET_DVR_REMOTECONTROL_STUDY_PARAM, *LPNET_DVR_REMOTECONTROL_STUDY_PARAM;

typedef struct tagNET_DVR_WIRELESS_ALARM_STUDY_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //channel
	BYTE  byIndex;  //wireless alarm ID,1-8
	BYTE  byRes[15]; 
}NET_DVR_WIRELESS_ALARM_STUDY_PARAM, *LPNET_DVR_WIRELESS_ALARM_STUDY_PARAM;

#define MAX_AUX_ALARM_NUM 8 //max aux alarm number
#define MAX_WIRELESS_ALARM_NUM 8 //max wireless alarm number
typedef enum _IPC_AUX_ALARM_TYPE_
{
    IPC_AUXALARM_UNKNOW   = 0, //Unknow
	IPC_AUXALARM_PIR      = 1, //PIR alarm
	IPC_AUXALARM_WIRELESS = 2,   //Wireless alarm
	IPC_AUXALARM_CALLHELP = 3  //Call help alarm
}IPC_AUX_ALARM_TYPE;

typedef struct tagNET_IPC_PIR_ALARMCFG
{
    BYTE byAlarmName[NAME_LEN];	/* Alarm name */
	BYTE byAlarmHandle;	        /* Handle alarm, 0-disanble,1-enable*/
	BYTE byRes1[3];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* alarm handle type */	
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //record channel, 1-enable
    BYTE byRes[64];
}NET_IPC_PIR_ALARMCFG, *LPNET_IPC_PIR_ALARMCFG;

typedef struct tagNET_IPC_CALLHELP_ALARMCFG
{
	BYTE byAlarmHandle;	        /* Handle alarm, 0-disanble,1-enable*/
	BYTE byRes1[3];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* alarm handle type */	
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //record channel, 1-enable
    BYTE byRes[64];
}NET_IPC_CALLHELP_ALARMCFG, *LPNET_IPC_CALLHELP_ALARMCFG;

typedef struct tagNET_IPC_SINGLE_WIRELESS_ALARMCFG
{
    BYTE byAlarmName[NAME_LEN];	/* Alarm name */
	BYTE byAlarmHandle;	        /* Handle alarm, 0-disanble,1-enable*/
	BYTE byID; //Wireless alarm ID,1-8
	BYTE byRes1[2];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* alarm handle type */
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //record channel, 1-enable	
    BYTE byRes[32];
}NET_IPC_SINGLE_WIRELESS_ALARMCFG, *LPNET_IPC_SINGLE_WIRELESS_ALARMCFG;

typedef struct tagNET_IPC_WIRELESS_ALARMCFG
{
	NET_IPC_SINGLE_WIRELESS_ALARMCFG struWirelessAlarm[MAX_WIRELESS_ALARM_NUM]; //Single Wireless alarm
    BYTE byRes[32];
}NET_IPC_WIRELESS_ALARMCFG, *LPNET_IPC_WIRELESS_ALARMCFG;

typedef union tagNET_IPC_AUX_ALARMCFG_UNION
{
    DWORD uLen[472];
	NET_IPC_PIR_ALARMCFG struPIRAlarm; //PIR alarm
	NET_IPC_WIRELESS_ALARMCFG struWirelessAlarm; //Wireless alarm
	NET_IPC_CALLHELP_ALARMCFG struCallHelpAlarm; //call help alarm
}NET_IPC_AUX_ALARMCFG_UNION, *LPNET_IPC_AUX_ALARMCFG_UNION;

typedef struct tagNET_IPC_SINGLE_AUX_ALARMCFG
{
	BYTE byAlarmType;	   //alarm type,see IPC_AUX_ALARM_TYPE
	BYTE byRes1[3];			
	NET_IPC_AUX_ALARMCFG_UNION uAlarm; //alarm parameter
    BYTE byRes[16];
}NET_IPC_SINGLE_AUX_ALARMCFG, *LPNET_IPC_SINGLE_AUX_ALARMCFG;

typedef struct tagNET_IPC_AUX_ALARMCFG
{
	DWORD dwSize;
    NET_IPC_SINGLE_AUX_ALARMCFG struAlarm[MAX_AUX_ALARM_NUM]; //alarm
    BYTE byRes[64];
}NET_IPC_AUX_ALARMCFG, *LPNET_IPC_AUX_ALARMCFG;

typedef union tagNET_IPC_AUXALARM_UPLOAD_UNION
{
    DWORD uLen[66];
    NET_IPC_PIR_ALARMCFG struPIRAlarm; //PIR alarm
	NET_IPC_SINGLE_WIRELESS_ALARMCFG struWirelessAlarm; //wireless alarm
	NET_IPC_CALLHELP_ALARMCFG struCallHelpAlarm; //call help alarm
}NET_IPC_AUXALARM_UPLOAD_UNION, *LPNET_IPC_AUXALARM_UPLOAD_UNION;

typedef struct tagNET_IPC_AUXALARM_RESULT
{
	DWORD dwSize;
	DWORD dwChannel; //channel
	BYTE byAlarmType;	   //alarm type,see IPC_AUX_ALARM_TYPE
	BYTE byRes1[3];
	NET_IPC_AUXALARM_UPLOAD_UNION struAuxAlarm; //alarm information
    BYTE byRes[64];
}NET_IPC_AUXALARM_RESULT, *LPNET_IPC_AUXALARM_RESULT;

typedef struct tagNET_DVR_PREVIEW_DISPLAYCFG
{
	DWORD  dwSize;         
	BYTE byCorrectMode; //Correction mode, 0 - software calibration, 1 - chip calibration
	BYTE byMountType; //Type of installation - Ceiling, 1 - Desktop 2 - wall
	BYTE byDisplayMode; //Display mode, see PREVIEW_DISPLAY_MODE
	BYTE byRes[61];
}NET_DVR_PREVIEW_DISPLAYCFG, *LPNET_DVR_PREVIEW_DISPLAYCFG;

typedef enum _PREVIEW_DISPLAY_MODE_
{
    PREVIEW_DISPLAY_NONE = 0, 
		PREVIEW_DISPLAY_FISHEYE = 1, //Single window fish-eye
		PREVIEW_DISPLAY_PTZ = 2,   //Single window PTZ
		PREVIEW_DISPLAY_FULL_PANORAMA = 3, //Single window to the four corners of panoramic Expand
		PREVIEW_DISPLAY_TWO_AROUNDPANORAMA = 4,  //Upper and lower split-screen two windows 180 ° (around panorama)
		PREVIEW_DISPLAY_WIDEPANORAMA_TWO_PTZ = 5, //A 360 ° (around panorama) plus two PTZ split screen; three window
		PREVIEW_DISPLAY_ONE_PANORAMA_TWO_PTZ = 6, //Four corners of the panorama (local) +2 PTZ split-screen
		PREVIEW_DISPLAY_FISHEYE_THREE_PTZ = 7 //A ball with three PTZ split screen (picture)
}PREVIEW_DISPLAY_MODE;

typedef struct tagNET_DVR_REMOTECONTROL_PTZ_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //Channel number
	DWORD dwPTZCommand; //PTZ control commands
	NET_VCA_POINT struVcaPoint; //Preview interface point coordinates
	DWORD dwSpeed; //Control the speed, range [0,7]
	DWORD dwStop; //Action to stop or start action: 0 - start; 1 - stop
	BYTE  byRes[32]; 
}NET_DVR_REMOTECONTROL_PTZ_PARAM, *LPNET_DVR_REMOTECONTROL_PTZ_PARAM;

typedef struct tagNET_DVR_PRESET_POINT_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //Channel number
	DWORD dwPTZPresetCmd; //Preset control commands
	NET_VCA_POINT struVcaPoint; //Preview interface point coordinates
	DWORD dwPresetIndex; //Preset number (1), supports up to 255 preset points
	BYTE  byRes[32]; 
}NET_DVR_PRESET_POINT_PARAM, *LPNET_DVR_PRESET_POINT_PARAM;

typedef struct tagNET_DVR_PTZ_CRUISE_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //Channel number
	DWORD dwPTZCruiseCmd; //Cruise control command 
	NET_VCA_POINT struVcaPoint; //Preview interface point coordinates
	WORD wCruiseRoute; //Cruise path, supports up to 32 paths (serial number starting with 1)
	WORD wCruisePoint; //Cruise point supports up to 32 points (numbered from 1)
	WORD wInput; //Different cruise command value preset points (maximum 255), time (maximum 255), speed (maximum 40)
	BYTE  byRes[34]; 
}NET_DVR_PTZ_CRUISE_PARAM, *LPNET_DVR_PTZ_CRUISE_PARAM;

typedef struct tagNET_DVR_WPS_PARAM
{
	DWORD dwSize;
	BYTE byEnableWps; //enable WPS,0-no,1-yes
	BYTE byRes[31]; 
}NET_DVR_WPS_PARAM, *LPNET_DVR_WPS_PARAM;

typedef struct tagNET_DVR_PIN_PARAM
{
	DWORD dwSize;
	BYTE byPIN[8]; //PIN
	BYTE byRes[32]; 
}NET_DVR_PIN_PARAM, *LPNET_DVR_PIN_PARAM;

typedef struct tagNET_DVR_WPS_CONNECT_PARAM_
{
	DWORD dwSize;
	BYTE byConnectType; //WPS connect type,0-PBC,1-AP PIN
	BYTE byRes1[3];
	BYTE byPIN[8]; //PIN(WPS connect type,AP PIN)
	BYTE byEssid[IW_ESSID_MAX_SIZE]; //essid(WPS connect type,AP PIN)
	BYTE byRes[32]; 
}NET_DVR_WPS_CONNECT_PARAM, *LPNET_DVR_WPS_CONNECT_PARAM;

typedef struct tagNET_DVR_CERT_PARAM
{
	DWORD dwSize;
	WORD wCertFunc; //certificate func,0-802.1x,1-HTTPS
	WORD wCertType; //certificate type,0-CA，1-Certificate,2-private key file
	BYTE byFileType; //certificate file type,0-PEM,1-PFX
	BYTE  byRes[35]; 
}NET_DVR_CERT_PARAM, *LPNET_DVR_CERT_PARAM;

#define UPLOAD_CERTIFICATE  1 //upload certificate
NET_DVR_API LONG __stdcall NET_DVR_UploadFile(LONG lUserID, DWORD dwUploadType, LPVOID lpInBuffer, DWORD dwInBufferSize, char* sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_UploadClose(LONG lUploadHandle);
/********************************IPC end*************************/

/**********************pic preview of push mode***************************/
typedef struct tagNET_DVR_PIC_VIEW_PARAM
{
	DWORD	dwSize;
	NET_DVR_IPADDR	struCuIp;	// ip of CU
	WORD	wPort;				// port of CU
	BYTE	bySourceIndex;		// channel index of signal
	BYTE	byRes[29];
}NET_DVR_PIC_VIEW_PARAM, *LPNET_DVR_PIC_VIEW_PARAM;

//2012-03-13  picture preview message callback
typedef struct _tagNET_DVR_PICVIEW_CALLBACKPARAM
{
	DWORD	dwUserID;
	BYTE	sDeviceID[16];	//device ID
	LONG	nPicViewHandle; //picture view handle
	WORD	wSignalIndex;	//signal index
	WORD	wHeadLen;		//head len, the len of private stream is 40
	BYTE	byHeadBuf[100]; //stream head buffer
	BYTE	byRes[32];
}NET_DVR_PICVIEW_CALLBACKPARAM, *LPNET_DVR_PICVIEW_CALLBACKPARAM;

/**********************get sub device list***************************/
#define DEVICEID_LEN		32
#define DVCS_DEVICEID_LEN   16

typedef struct tagNET_DEVICEID_INFO
{
	DWORD		dwSize;
	BYTE		sDeviceID[DEVICEID_LEN/*32*/]; 	//device ID
	DWORD		dwChan;							//channel index，index of BNC processor is1-16，index of RGB processor is 1，index of stream processor1-4
	DWORD		dwInputSignalIndex;				//signal index，used in CVCS
	BYTE		byRes[60];
}NET_DVR_DEVICEID_INFO, *LPNET_DVR_DEVICEID_INFO;

typedef struct tagNET_DVR_SINGLE_NETPARAM
{
	DWORD  dwSize;
	BYTE   byUseDhcp;				 //DHCP 0xff-INVALID 0-not used 1-used
	BYTE   byRes1[3];
	NET_DVR_IPADDR  struDevIP;       // ip address
	NET_DVR_IPADDR  struSubnetMask;  // mask
	NET_DVR_IPADDR  struGateway;     // gate way
	WORD	wDevPort;				 // port
	BYTE	byMACAddr[MACADDR_LEN];  // MAC address(get only)
	BYTE	byRes2[16];
} NET_DVR_SINGLE_NETPARAM, *LPNET_DVR_SINGLE_NETPARAM;

typedef struct tagNET_DVR_CHAN_INFO
{
	DWORD  dwSize;
	BYTE   byValid;					//0-invalid 1-valid
	BYTE   byUsed;					//0-not used，1-used
	BYTE   byRes1[2];
	BYTE   sChanName[NAME_LEN];    //channel name
	NET_DVR_COLOR struVideoColor;  //video color
	BYTE   byRes2[44];	
} NET_DVR_CHAN_INFO, *LPNET_DVR_CHAN_INFO;

//coder information
typedef struct tagNET_DVR_CODEDEV_INFO 
{
	NET_DVR_CHAN_INFO struChanInfo[MAX_CHANNUM/*16*/];//channel information 
} NET_DVR_CODEDEV_INFO, *LPNET_DVR_CODEDEV_INFO;

//decoder information
typedef struct tagNET_DVR_DECODEDEV_INFO 
{
	BYTE	byRes[1408];
} NET_DVR_DECODEDEV_INFO, *LPNET_DVR_DECODEDEV_INFO;

//net signal information
typedef struct tagNET_DVR_NETSIGNAL_INFO
{
	DWORD	dwSize;
	BYTE	byDevName[NAME_LEN/*32*/];		// net signal name
	NET_DVR_PU_STREAM_CFG struPuStream;		// net signal information，if byValid of struStreamMediaSvrCfg is 0, use struDevChanInfo for the param of net signal
	BYTE	byValid;						// 0-invalid，set 0 when delete signal, 1-valid，set 1 when add or mod signal/
	BYTE 	byRes1[3];						// res
	BYTE	sGroupName[NAME_LEN/*32*/];		// group name of net signal
	BYTE	byRes2[28];						// res	
}NET_DVR_NETSIGNAL_INFO, *LPNET_DVR_NETSIGNAL_INFO;

typedef struct tagNET_DVR_NETSIGNALDEV_INFO
{
	NET_DVR_NETSIGNAL_INFO struDevInfo;
	BYTE	byRes1[816];
}NET_DVR_NETSIGNALDEV_INFO, *LPNET_DVR_NETSIGNALDEV_INFO;

typedef union tagNET_DVR_DIFFDEV_INFO 
{
	NET_DVR_CODEDEV_INFO struCodeDevInfo;			//coder information
	NET_DVR_DECODEDEV_INFO struDecodeDevInfo;		//decoder information
	NET_DVR_NETSIGNALDEV_INFO struNetSignalInfo;	//net signal information
} NET_DVR_DIFFDEV_INFO, *LPNET_DVR_DIFFDEV_INFO;

typedef enum tagNET_DVCS_DEVICE_TYPE
{
	NET_DVR_BNC_PROC = 1,                   // BNC processor
	NET_DVR_RGB_PROC,                       // RGB processor
	NET_DVR_STP_PROC,                       // stream processor
	NET_DVR_DISP_PROC,                      // display processor
	NET_DVR_NETSIGNAL,						// net signal
}NET_DVCS_DEVICE_TYPE;

typedef struct  tagNET_DVR_SINGLE_DEV_INFO 
{
	DWORD	dwSize;
	DWORD	dwSoftVersion;			// soft version, the highest 8 bits is main version, other 8bits is sub version. the last 16 bits is repair version
	DWORD	dwSoftwareBuildDate; 	// version Build data, 0xYYYYMMDD
	BYTE	byUseInSys;				// 0-not used in system 1-used in the system
	BYTE	byDevStatus;			// device status，0-offline，1-online 
	BYTE	byDeviceType;			// device type  describe in struct DEVICE_TYPE 
	BYTE	byRes1;
	BYTE	sDeviceID[DVCS_DEVICEID_LEN];				//device id 
	BYTE	sDevName[NAME_LEN];							//device name
	NET_DVR_SINGLE_NETPARAM struEtherNet[MAX_ETHERNET]; //net param of device
	BYTE	sSerialNumber[SERIALNO_LEN];				//device serial
	NET_DVR_DIFFDEV_INFO  struSubDevInfo;				//device information
	BYTE	byRes2[20];
} NET_DVR_SINGLE_DEV_INFO, *LPNET_DVR_SINGLE_DEV_INFO;

typedef struct tagNET_DVR_DEVLIST
{
	DWORD		dwSize;
	DWORD		dwDevNums;//sub device numbers
	BYTE  		*pBuffer;
	BYTE		byRes1[3];
	DWORD 		dwBufLen;//buffer len
	BYTE		byRes2[64];
} NET_DVR_DEVLIST,*LPNET_DVR_DEVLIST;

/********************************base information of sub device****************************/
typedef struct tagNET_DVR_DEV_BASE_INFO
{
	DWORD  dwSize;
	BYTE   byEnable;			// 0-not used in system 1-used in the system
	BYTE   byDeviceType;		// device type 
	BYTE   byRes1[2];
	BYTE   sDevName[NAME_LEN];	// device name 
	BYTE   byRes2[24];
} NET_DVR_DEV_BASE_INFO,*LPNET_DVR_DEV_BASE_INFO;

/********************************net information of sub device****************************/
typedef  struct tagNET_DVR_NETPARAM
{	
	DWORD dwSize;
	NET_DVR_SINGLE_NETPARAM struEtherNet[MAX_ETHERNET];
	BYTE   byRes[64];
} NET_DVR_NETPARAM, *LPNET_DVR_NETPARAM;

/********************************config display unit****************************/
// Binding screen and device(16 bytes)
typedef struct tagNET_DVR_DISP_SCREEN
{
	DWORD dwSize;
	WORD  wScreenID;	// screen ID, start from 1
	BYTE  byRes1[2];    // reverse
	BYTE  sDeviceID[DVCS_DEVICEID_LEN]; //device id 
	BYTE  byRes2[4];    // reverse
}NET_DVR_DISP_SCREEN, *LPNET_DVR_DISP_SCREEN;
// screen control
typedef struct tagNET_DVR_TEXTSHOW
{
	DWORD dwSize;
	BYTE  byShowText;		//0-display text，1-do not display text
	BYTE  byRes[35];
}NET_DVR_TEXTSHOW, *LPNET_DVR_TEXTSHOW;

typedef struct tagNET_DVR_SCREENLIST
{
	DWORD		dwSize;
	BYTE		byRes[12];
	DWORD		dwScreenNums;//screen numbers
	BYTE  		*pBuffer;
	DWORD 		dwBufLen;//buffer length
} NET_DVR_SCREENLIST,*LPNET_DVR_SCREENLIST;

typedef struct tagNET_DVR_OPERATE_DEVICE
{
	DWORD	dwSize;
	DWORD	dwSubCommand;	//1-start upgrade，2-stop upgrade
	BYTE	sDeviceID[DVCS_DEVICEID_LEN];
	BYTE	byRes[32];
}NET_DVR_OPERATE_DEVICE, *LPNET_DVR_OPERATE_DEVICE;

//upgrade
typedef struct tagNET_DVR_UPGRADE_STATE
{
	DWORD	dwProgress; // 0-100
	BYTE 	byState;  //1-upgrade finished 2-upgrading 3-upgrade failed
	BYTE	byRes2[31];
}NET_DVR_UPGRADE_STATE, *LPNET_DVR_UPGRADE_STATE;

//data type of picture preview, the data type is bmp picture in cvcs, the picture data is ps stream in dvcs
typedef enum
{
	NET_DVR_DATA_BMP = 0,
	NET_DVR_START_CALLBACK, 
	NET_DVR_STREAM_SYSHEAD,
	NET_DVR_STREAM_DATA
}PIC_PREVIEW_DATATYPE;

typedef struct tagNET_DVR_START_PIC_VIEW_INFO
{
	DWORD	dwSize;
	DWORD	dwSignalIndex;					// signal index，used in cvcs
	BYTE	sDeviceID[DVCS_DEVICEID_LEN];	// device id
	BYTE	byChanIndex;					// channel index
	BYTE	byRes[31];
}NET_DVR_START_PIC_VIEW_INFO, *LPNET_DVR_START_PIC_VIEW_INFO;

typedef struct tagNET_DVR_DVCS_STATE_ALARM
{
	DWORD  dwSize;
	BYTE   byAlarmType;                //alarm type 1-device online，2-device offline 3-server online 4-server offline
	BYTE   byDeviceType;			   //device type ,see struct NET_DVCS_DEVICE_TYPE
	BYTE   byRes1[2];
	BYTE   sDeviceID[16];
	BYTE   byRes2[80];
}NET_DVR_DVCS_STATE_ALARM, *LPNET_DVR_DVCS_STATE_ALARM;

typedef struct tagNET_DVR_PIC_ADJUST
{
	DWORD		dwSize;
	BYTE		bySubCommand;		//see struct DECODEPIC_LEFTADJUST
	BYTE		byScale;			//scale
	BYTE		byRes[30];			
}NET_DVR_PIC_ADJUST, *LPNET_DVR_PIC_ADJUST;
/********************************dvcs end****************************/

// 76SP device config POE channel add mode
typedef struct tagNET_DVR_POE_ADAPTER_TYPE
{
	DWORD		dwSize;              	
	BYTE 		byAdapterType;     		//Aapter type 0: inter adpter 1: LAN1	
	BYTE  		byRes1[127];         
}NET_DVR_POE_ADAPTER_TYPE, *LPNET_DVR_POE_ADAPTER_TYPE;

// 76SP device config POE channel add mode
typedef struct tagNET_DVR_POE_CHANNEL_ADD_MODE
{
	DWORD		dwSize;              
	BYTE 		byAddMode;     			//0: UPNP 1: add by manual	
	BYTE  		byRes1[127];          	
}NET_DVR_POE_CHANNEL_ADD_MODE, *LPNET_DVR_POE_CHANNEL_ADD_MODE;

#define MAX_ESATA_NUM 16
#define MAX_MINISAS_NUM 96

typedef struct tagNET_DVR_ESATA_MINISAS_USAGE
{
	DWORD		dwSize;
	BYTE	    byESATAUsage[MAX_ESATA_NUM];		// 0：backup 1：record	  
	BYTE	    byMiniSASUsage[MAX_MINISAS_NUM];	// 0：backup 1：record
	BYTE 		byRes[32];
}NET_DVR_ESATA_MINISAS_USAGE, *LPNET_DVR_ESATA_MINISAS_USAGE;

#define MAX_DISK_NUM 128

typedef struct tagNET_DVR_BACKUP_LOG_PARAM
{
	DWORD		dwSize;
	BYTE	    byDiskDesc[DESC_LEN_32];		
	BYTE		byHardDisk[MAX_DISK_NUM];		 
	BYTE		byBackupHardDiskNum;  			
	BYTE	    byContinue;					
	BYTE 		byRes[30];
}NET_DVR_BACKUP_LOG_PARAM, *LPNET_DVR_BACKUP_LOG_PARAM;

typedef struct tagNET_DVR_DIGITAL_CHANNEL_STATE
{
	DWORD dwSize;
	BYTE  byDigitalAudioChanTalkState[MAX_CHANNUM_V30];  //Digital audio talk state 0-not use，1-using, 0xff, not valid
	BYTE  byRes[512];
}NET_DVR_DIGITAL_CHANNEL_STATE, *LPNET_DVR_DIGITAL_CHANNEL_STATE;

/*************************************ITS****************************/
#define VERSION_LEN                 32 //Version length
#define	MAX_OVERLAP_ITEM_NUM		50 //Max character overlap number
#define	ITS_MAX_DEVICE_NUM		    32 //Max device number

//Terminal basic information
typedef struct tagNET_ITS_BASEINFO
{
	DWORD   dwSize;	
	BYTE    byMainVer[VERSION_LEN];	// Terminal Basic information
	BYTE    byMprVer[VERSION_LEN];	// Multiple frame recognize data version
	BYTE    byBvtVer[VERSION_LEN];	// Backward video library version
	BYTE    byLptVer[VERSION_LEN];	// Video tracking data version
	BYTE    byTvdVer[VERSION_LEN];	// Rule-break detection data version
	BYTE    byTldVer[VERSION_LEN];	// Signal light detection data version
	BYTE    byRes[252];		// Reserved
}NET_ITS_BASEINFO,*LPNET_ITS_BASEINFO;

//Photomontage parameters
typedef struct tagNET_ITS_IMGMERGE_CFG
{
    DWORD  dwSize;
	BYTE  byIsMerge;		//Merged needed or not (0:No 1:YES)
	BYTE byRes1[3];
	DWORD  dwOneMergeType;	//Single captured picture merged method (close-up view might be cut out )
	DWORD  dwTwoMergeType;	//Two captured picture merged method
	DWORD  dwThreeMergeType;	//Three captured picture merged method
    DWORD  dwJpegQuality;      //Compression quality(0~100)
    DWORD  dwCloseupIndex;     //The number of close-up picture
	DWORD  dwMerageMaxSize;   //Top limit size of the merged pictures (300~10240KB)
	BYTE   byRes[32];
	/************************************************************************/
	/* 201 merge the upper and the lower pictures, the width of the merged picture is one times, the height is doubled         */
	/* 202 merge the left and the right pictures, the width of the merged picture is doubled, the height is one times.         */
	/* 301 merge the top, the middle and the bottom pictures, the width of the merged picture is one times, the height is tripled */
	/* 302 merge the left, the middle and the right pictures, the width of the merged picture is tripled, the height is one times */
	/* 303 take a license plate from the three pictures as a close-up, and merge with the other three pictures into a 2*2 layout, make the license plate on the lower right. The width of the merged picture is doubled and the height is doubled.*/
	/* 304 take a license plate from the three pictures as a close-up, and merge with the other three pictures into a 2*2 layout, make the license plate on the lower right. The width of the merged picture is one times and the height is one times.*/
	/* 305 take a license plate from the three pictures as a close-up, and merge with the other three pictures into a 2*2 layout, make the license plate on the top left. The width of the merged picture is doubled and the height is doubled.*/
	/* 306 take a license plate from the three pictures as a close-up, and merge with the other three pictures into a 2*2 layout, make the license plate on the top left. Compress the resolution. The width of the merged picture is one times, and the height is one times.*/
    /* 307 merge the three pictures into a 1*2 layout */
	/* 308 merge the three pictures into a 2*1 layout		  */
	/************************************************************************/
}NET_ITS_IMGMERGE_CFG,*LPNET_ITS_IMGMERGE_CFG;

//Transportation data host
typedef	struct	tagNET_ITS_TRAFFIC_DATA_HOST
{
 	NET_DVR_IPADDR	struHostAddr;	// Remote host IP
	WORD			wHostPort;	// Remote host port
	BYTE			byRes1[2];
	DWORD			dwDataType;	// Upload the data type of the remote mainframe (see below definition), indicated by bit
	BYTE			bySuspendUpload;	//Suspend the data uploading or not: 0- upload, 1- suspend
	BYTE			byUploadStrategy;	//Upload strategy: 0- upload the latest data first, 1- upload the data in sequence
	WORD			wUploadInterval;	//The interval of the upload(ms, 1~2000), this parameter only works for historical data
	DWORD			dwUploadTimeOut; //Upload timed-out
	BYTE			byRes[24];
}NET_ITS_TRAFFIC_DATA_HOST,*LPNET_ITS_TRAFFIC_DATA_HOST;

//Data upload parameter
typedef  struct	tagNET_ITS_UPLOAD_CFG
{
  	DWORD              	dwSize;
  	NET_ITS_TRAFFIC_DATA_HOST	struRemoteDataHost1;   	//Host 1 to receive transportation dat
  	NET_ITS_TRAFFIC_DATA_HOST	struRemoteDataHost2;	//Host 2 to receive transportation data 
}NET_ITS_UPLOAD_CFG,*LPNET_ITS_UPLOAD_CFG;

typedef struct tagNET_DVR_SYSTEM_TIME
{
	WORD  wYear;   	    //Year
	WORD  wMonth;  		//Month
	WORD  wDay;    		//Day
	WORD  wHour;   		//Hour
	WORD  wMinute;  	//Minute
	WORD  wSecond;  	//Second
	WORD  wMilliSec;	//Millisecond
	BYTE  byRes[2];
}NET_DVR_SYSTEM_TIME, *LPNET_DVR_SYSTEM_TIME;

//The status of the transportation data host
typedef	struct tagNET_ITS_TRAFFIC_DATA_INFO
{
	DWORD    dwDataQuantity;      //Data amount
	DWORD    dwDataRsendQuantity;     //Undelivered data quantity (needs to be uploaded to the transportation data host)
	NET_DVR_SYSTEM_TIME      struStartTime;      //The earliest time of the undelivered data
	NET_DVR_SYSTEM_TIME      struEndTime;        //The most recent time of the undelivered data
	NET_DVR_IPADDR   struDataHost;    //Host of receiving transportation data
}NET_ITS_TRAFFIC_DATA_INFO, *LPNET_ITS_TRAFFIC_DATA_INFO;

//The terminal work status
typedef  struct tagNET_ITS_WORKSTATE
{ 
	DWORD	  dwSize ;
	BYTE	 byDevName[32];	// Device name
	DWORD  dwRunTime;		// System running time, Unit: second
	NET_ITS_TRAFFIC_DATA_INFO	struTrafficDataInfo[2]; //Tow hosts are supported(The data upload to the configuration hosts)
	DWORD  dwMemoryUsage;	// Memory usage (If the usage is 30%, enter 30 in this field)
	DWORD  dwCpuUsage;		// CPU usage (If the usage is 30%, enter 30 in this field)
	DWORD  dwDevTemperature;	// Temperature
	DWORD  dwDeviceStatic; 	// Device status: 0-normal, 1-CPU usage is more than 85, 2-hardware error, e.g. serial port broken
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];   //Hardware status
	NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30]; //Channel status
	BYTE  byAlarmInStatic[MAX_ALARMIN_V30];  //Alarm input status, 0- no alarm, 1- alarm
	BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30]; //Alarm output status, 0- no alarm, 1- alarm
	DWORD dwLocalDisplay;			//Local view status, 0- normal, 1-abnormal
	BYTE  byAudioInChanStatus[8];  	//Audio channel status, 0-not in use, 1- in use, array 0 means the no.1 voice channel
	BYTE  byRes[36]; 			//Reserved
}NET_ITS_WORKSTATE, *LPNET_ITS_WORKSTATE;

// Picture info
typedef struct tagNET_ITS_PICTURE_INFO
{
	DWORD   dwDataLen;		    //Media data length
	BYTE    byType;		    	//0: license picture, 1: Scene picture, 2: Composite map, 3: stream 
	BYTE    byRes1[3];          //Reserved
	DWORD   dwRedLightTime;		//Time for passing the red traffic light (s)
	BYTE    byAbsTime[32];		//Absolute time, yyyymmddhhmmssxxx,e.g.20090810235959999, The last three numbers mean millisecond
	NET_VCA_RECT   struPlateRect;	//License plate location
	NET_VCA_RECT  struPlateRecgRect;   //License plate region coordinate
	BYTE		*pBuffer;	//Data pointer
	BYTE    byRes2[12];   		//Reserved
}NET_ITS_PICTURE_INFO, *LPNET_ITS_PICTURE_INFO;

//Detection result
typedef struct tagNET_ITS_PLATE_RESULT
{
	DWORD   dwSize;		//Structure size
	DWORD   dwMatchNo;  //Matched Serial Number. (consisting of the vehicle serial number, data type and lane number)
	BYTE    byGroupNum;	//Amount of the picture groups (the amount of pictures captured when one vehicle passing by. The data can be used for the Time Delay Matching.)
	BYTE    byPicNo;	//Continuous captured pictures serial number. (indicating the complete of the receiving.)
	BYTE    bySecondCam;	//Whether set the second camera to snapshot (e.g. prospect camera of far and near scene capture, rear camera of front and rear capture）
	BYTE    byFeaturePicNo; //electric alarm of running red light, which picture taken to be close-up, 0xff- not take
	BYTE	    byDriveChan;	//Triggering lane No.
	BYTE     byRes1[3];			//Reserved
	WORD    wIllegalType;       //Rules broken type adopts the international standard definition
	BYTE    byIllegalSubType[8];   //Rules broken sub-type
	BYTE    byPostPicNo;    //The captured picture number to be traffic mount picture when the rule is broken,0xff- not take
	BYTE     byChanIndex;		//Camera No. (reserved)
	WORD	    wSpeedLimit;		//Speed upper limit(valid when overspeed)
	BYTE		byRes2[2];
	NET_DVR_PLATE_INFO  struPlateInfo; 	//Plate info. structure
	NET_DVR_VEHICLE_INFO struVehicleInfo;	//Vehicle info
	BYTE   byMonitoringSiteID[48];		//Camera No.
	BYTE   byDeviceID[48];				//Device No.
	BYTE    byDir;    		//Monitoring direction; 1- Up, 2- Down, 3- Bi-directional, 4- Westward, 5- Northward, 6-Eastward, 7-Southward, 8-Other directio
	BYTE    byDetectType;	//Detecting methods: 1- Triggered by induction coil, 2- Triggered by video, 3- Triggered by multi-frame detection, 4-Triggered by radar.
	BYTE    byRes3[38];	//Reserved
	DWORD   dwPicNum;		//The picture count (different with picGroupNum, represent the picture count attached by this information, picture info defined by struVehicleInfoEx	
	NET_ITS_PICTURE_INFO struPicInfo[6]; 		//Picture info, check picture, at most 6 pictures at one time
}NET_ITS_PLATE_RESULT, *LPNET_ITS_PLATE_RESULT;

//IPC channel configuration
typedef	struct 	tagNET_ITS_IPC_CHAN_CFG
{
	DWORD		dwSize; 
	BYTE		byCameraType;		//Camera type, 0- surveillance camera, 1- coil triggering camera, 2- camera for video analysis, 3- zoom camera
	BYTE		byRes1[3];		   //Reserved
	BYTE		byMonitoringSiteID[48];		//Camera No.
	BYTE		byDeviceID[48];				//Device No.
	BYTE		byDirectionNo;	     //Monitoring direction; 1-Up, 2-Down, 3-Bi-directional, 4- Westward, 5- Northward, 6-Eastward, 7-Southward, 8-Other direction 
	BYTE		byMonitorInfo[48];  	//Camera information description
	BYTE		byRes2[15];		//Reserved
}NET_ITS_IPC_CHAN_CFG, *LPNET_ITS_IPC_CHAN_CFG;

//Single device info
typedef struct tagNET_ITS_SINGLE_DEVICE_INFO
{
	DWORD  dwDeviceType;          //Device Type, 0- end, 1- camera, 2- compensation light, 3- car checking machine
	DWORD  dwDirID;               //Direction No.
	DWORD  dwLaneID;             //Lane No.
	DWORD  dwDeviceState;         //Device status; 0:normal, others: abnormal
	BYTE     byDeviceName[32];     //Device name
	BYTE 	  byDeviceID[48];	//Device No., normally it should be the serial number and for the car checking machine, address should be used.
	BYTE byRes[16];
}NET_ITS_SINGLE_DEVICE_INFO,*LPNET_ITS_SINGLE_DEVICE_INFO;

//Road junction information
typedef struct tagNET_ITS_ROADINFO
{	
	DWORD	 dwSize;
	DWORD	 dwChannel;		  //Channel No., 0xffffffff means terminal, other value mean the corresponding camera
	BYTE     byTriggerMode;    //0: Triggered  by loop; 1: Triggered by video
	BYTE	 byRes1[3];
	DWORD   dwDeviceNum;       //Actual device count 
	BYTE      byMonitoringSiteID[48];	//Camera No.
	BYTE  	 byRoadInfo[48];       //Camera info
	NET_ITS_SINGLE_DEVICE_INFO		struSingleDevice[ITS_MAX_DEVICE_NUM];
	BYTE byRes[16];
}NET_ITS_ROADINFO,*LPNET_ITS_ROADINFO;

typedef struct tagNET_ITS_OVERLAPCFG_COND
{
    DWORD dwSize;
	DWORD dwChannel;
    DWORD dwConfigMode; //Configuration mode, 0- terminal, 1-front end(Directly connect to front-end or terminal connect to the front end)
    BYTE byRes[16];
}NET_ITS_OVERLAPCFG_COND, *LPNET_ITS_OVERLAPCFG_COND;

typedef enum ITS_OVERLAP_ITEM_TYPE
{
	OVERLAP_ITEM_NULL = 0,	          //0-Unknown
	OVERLAP_ITEM_SITE,                //1-Location
	OVERLAP_ITEM_ROADNUM,             //2-Road Cross No.
	OVERLAP_ITEM_INSTRUMENTNUM,       //3-Device No.
	OVERLAP_ITEM_DIRECTION,           //4-Direction No.
	OVERLAP_ITEM_DIRECTIONDESC,       //5-Direction
	OVERLAP_ITEM_LANENUM,             //6-Lane No.
	OVERLAP_ITEM_LANEDES,             //7-Lane
	OVERLAP_ITEM_CAPTIME,             //8-Captured time(without ms)
	OVERLAP_ITEM_CAPTIME_MILLSECOND,  //9-Captured time(with ms)
	OVERLAP_ITEM_PLATENUM,            //10-License plate number
	OVERLAP_ITEM_CARCOLOR,            //11-Vehicle color
	OVERLAP_ITEM_CARTYPE,             //12-Vehicle type
	OVERLAP_ITEM_CARBRAND,            //13-Car brand
	OVERLAP_ITEM_CARSPEED,            //14-Speed
	OVERLAP_ITEM_SPEEDLIMIT,          //15-Speed limit sign
	OVERLAP_ITEM_CARLENGTH,           //16-Vehicle length: 1~99m
	OVERLAP_ITEM_ILLEGALNUM,          //17-Illegal code(generally it will be not used, it should overlay illegal information, such as normal, low speed, overspeed, retrograde, running red lights, lane and pressure the yellow line)
	OVERLAP_ITEM_MONITOR_INFO,        //18-Vehicle length
	OVERLAP_ITEM_ILLEGALDES,          //19-Illegal action
	OVERLAP_ITEM_OVERSPEED_PERCENT,	  //20-Over-speed ratio
	OVERLAP_ITEM_RED_STARTTIME,       //21-Red light start time
	OVERLAP_ITEM_RED_STOPTIME,	      //22-Red light stop time
	OVERLAP_ITEM_RED_DURATION,        //23-Red light on time
	OVERLAP_ITEM_SECUNITY_CODE,		  //24-Anti-counterfeiting code
	OVERLAP_ITEM_CAP_CODE		      //25-Capture No.                       
}ITS_OVERLAP_ITEM_TYPE;

//Single item of character overlay
typedef struct tagNET_ITS_OVERLAP_SINGLE_ITEM_PARAM
{
	WORD wItemLen;                   // String length for text overlaying
	BYTE byItemType;               //Item type, see to OVERLAP_ITEM_TYPE
	BYTE byChangeLineNum;		   //Line numbers after overlay item[0-10](default: 0)
	BYTE bySpaceNum;				   //Line numbers after overlay item[0-255](default: 0)
	BYTE byRes[15];
}NET_ITS_OVERLAP_SINGLE_ITEM_PARAM, *LPNET_ITS_OVERLAP_SINGLE_ITEM_PARAM;

typedef struct tagNET_ITS_OVERLAP_ITEM_PARAM
{
	NET_ITS_OVERLAP_SINGLE_ITEM_PARAM struSingleItem[MAX_OVERLAP_ITEM_NUM]; //Single string parameter
	DWORD dwLinePercent;  //Overlay percentage(0~100),(default: 100)
	DWORD dwItemsStlye;   //Overlay style: 0- horizontal,1- vertical, (default: horizontal)
	WORD wStartPosTop;    //The starting top coordinate, only effective for the internal overlay of picture[0~2448](default:0)
	WORD wStartPosLeft;   //The starting left coordinate,only effective for the internal overlay of picture[0~2448](default:0)
	WORD wCharStyle;    //Font type: 0- Times New Roman,1- 魏体(default)
	WORD wCharSize;     //Font size: 0--16x16,1--32x32,2-48x48,3--64x64 (default)
	WORD wCharInterval;    //Character spacing: [0～16]，unit: pixel(default)
	BYTE    byRes1[2];
	DWORD dwForeClorRGB; //foreground color RGB value: bit0-1:(B) bit2-3:(G) bit4-5:(G) (default: x00FFFFFF- white)
	DWORD dwBackClorRGB; //Background color RGB value, only effective for the extra overlay of picture: bit0-1:(B) bit2-3:(G) bit4-5:(G) (default: x00000000- black)
	BYTE byColorAdapt;	 //Color self-adaption: 0- no, 1- yes
	BYTE byRes[31];
}NET_ITS_OVERLAP_ITEM_PARAM, *LPNET_ITS_OVERLAP_ITEM_PARAM;

//Overlay specified info
typedef struct tagNET_ITS_OVERLAP_INFO_PARAM
{
	BYTE bySite[128];           //Location description
	BYTE byRoadNum[32];  //Road Cross No.
	BYTE byInstrumentNum[32];				//Device No.
	BYTE byDirection[32];        //Direction No.
	BYTE byDirectionDesc[32];    //Direction
	BYTE byLaneDes[32];        //Lane description
	BYTE byCameraNum[32];     //Camera No.
	BYTE byMonitoringSite1[44];		//Camera 1 info
	BYTE byMonitoringSite2[32];		//Camera 2 info
	BYTE byRes[64];		//Reserved
}NET_ITS_OVERLAP_INFO_PARAM, *LPNET_ITS_OVERLAP_INFO_PARAM;

typedef struct tagNET_ITS_OVERLAP_CFG
{
	DWORD dwSize;	
    BYTE byEnable; //Enable or not: 0- no, 1- yes
    BYTE byRes1[3]; 
	NET_ITS_OVERLAP_ITEM_PARAM		struOverLapItem; //String parameters
	NET_ITS_OVERLAP_INFO_PARAM 	struOverLapInfo;  //String content info
	BYTE byRes[32];
}NET_ITS_OVERLAP_CFG, *LPNET_ITS_OVERLAP_CFG;


#define  MAX_PTZCRUISE_POINT_NUM   32   //Maximum support of 32 cruise points


typedef struct tagNET_DVR_PRESET_INFO
{
	DWORD dwSize;
	DWORD dwPresetNum; 
	DWORD dwGroupNum;  
	BYTE  byRes[8];
}NET_DVR_PRESET_INFO, *LPNET_DVR_PRESET_INFO;


typedef struct tagNET_DVR_PRESET_COND
{
    DWORD dwSize;
	DWORD dwChannel;
	DWORD dwGroupNO; 
    BYTE byRes[8];
}NET_DVR_PRESET_COND, *LPNET_DVR_PRESET_COND;


typedef struct tagNET_DVR_PRESETCFG
{
	DWORD dwSize;
	DWORD dwPresetIndex; 
	NET_VCA_POINT struVcaPoint; 
	BYTE  byRes[32]; 
}NET_DVR_PRESETCFG, *LPNET_DVR_PRESETCFG;

typedef struct tagNET_DVR_PTZCRUISE_INFO
{
    DWORD dwSize;
	DWORD dwPtzCruiseNum; 
    DWORD dwGroupNum; 
    BYTE byRes[8];
}NET_DVR_PTZCRUISE_INFO, *LPNET_DVR_PTZCRUISE_INFO;

typedef struct tagNET_DVR_PTZCRUISE_COND
{
    DWORD dwSize;
	DWORD dwChannel;
	DWORD dwGroupNO; 
    BYTE byRes[8];
}NET_DVR_PTZCRUISE_COND, *LPNET_DVR_PTZCRUISE_COND;


typedef struct tagNET_DVR_PTZCRUISE_POINTCFG
{
	DWORD dwSize;
	DWORD dwPresetIndex;
	NET_VCA_POINT struVcaPoint; 
	BYTE	byDwell;		
	BYTE	bySpeed;		
	BYTE  byRes[30]; 
}NET_DVR_PTZCRUISE_POINTCFG, *LPNET_DVR_PTZCRUISE_POINTCFG;

typedef struct tagNET_DVR_PTZCRUISECFG
{
	DWORD dwSize;
	DWORD dwCruiseRoute; 
	NET_DVR_PTZCRUISE_POINTCFG struCruisePoint[MAX_PTZCRUISE_POINT_NUM]; 
	BYTE  byRes[32]; 
}NET_DVR_PTZCRUISECFG, *LPNET_DVR_PTZCRUISECFG;


typedef struct tagNET_DVR_MOTION_TRACK_CFG
{
	DWORD dwSize; 
	BYTE byEnableTrack;   
	BYTE byRes[63];
}NET_DVR_MOTION_TRACK_CFG, *LPNET_DVR_MOTION_TRACK_CFG;

/*************************************ITS end****************************/

typedef struct tagNET_DVR_REBOOT_TIME
{
	BYTE byDate;   //date,1 to 7 represent Monday to Sunday
	BYTE byHour;   //hour
	BYTE byMinute; //minute
	BYTE byRes[13]; 
}NET_DVR_REBOOT_TIME,*LPNET_DVR_REBOOT_TIME;

typedef struct tagNET_DVR_AUTO_REBOOT_CFG
{
	DWORD dwSize;
	NET_DVR_REBOOT_TIME struRebootTime;
}NET_DVR_AUTO_REBOOT_CFG,*LPNET_DVR_AUTO_REBOOT_CFG;

/*************************************MVA 2.1 begin****************************/
#define NET_DVR_GPS_FINDING       0   //finding
#define NET_DVR_GPS_RECV          1   //receive data
#define NET_DVR_GPS_OVER          2   //finding finish
#define NET_DVR_GPS_EXCEPTION     3   //receive exception
typedef struct tagNET_DVR_MENU_OUTPUT_MODE
{
	DWORD		dwSize;
	BYTE		byMenuOutputMode; //menu output mode. not homologous device：0-Auto 1-main CVBS 2-HDMI 3-VGA homologous device：0-Auto 1-main CVBS 2-HDMI/VGA
	BYTE		byRes[63];
}NET_DVR_MENU_OUTPUT_MODE, *LPNET_DVR_MENU_OUTPUT_MODE;

#define NET_DVR_GET_MB_PLATFORMPARA			1150//get platform parameter
#define NET_DVR_SET_MB_PLATFORMPARA			1151//set platform parameter

typedef struct tagNET_DVR_MB_IPADDR
{
	NET_DVR_IPADDR   struIP;  //IP address
	WORD        wPort;   //port
	BYTE        byRes[2];
}NET_DVR_MB_IPADDR,*LPNET_DVR_MB_IPADDR;

typedef struct tagNET_DVR_MB_WVSPARA
{
	NET_DVR_MB_IPADDR struWVSAddr;
	BYTE byPuid[NAME_LEN];    //pu id
	BYTE byPassword[PASSWD_LEN];  //password
	BYTE byRes[8];
}NET_DVR_MB_WVSPARA, *LPNET_DVR_MB_WVSPARA;

typedef struct tagNET_DVR_MB_EHOMEPARA
{
	NET_DVR_MB_IPADDR struEHomeAddr;
	BYTE byPuid[NAME_LEN];   //pu id
}NET_DVR_MB_EHOMEPARA, *LPNET_DVR_MB_EHOMEPARA;

typedef struct tagNET_DVR_MB_PLATFORMPARA
{   
	DWORD dwSize;
	BYTE byNetEnvironment;/*network,0-wireless,1-3G,2-wLan,3-lan*/
	BYTE byCurPlatForm;   /*current platform,0 - WVS, 1 - E home, 2 - CMS */
	BYTE byRes1[2];	
	NET_DVR_MB_WVSPARA  struWVSPara; /*WVS platform parameter*/
	NET_DVR_MB_EHOMEPARA struMbEHpara;/*E home platform parameter */
	BYTE byRes2[64];
}NET_DVR_MB_PLATFORMPARA, *LPNET_DVR_MB_PLATFORMPARA;

typedef struct tagNET_DVR_MB_GPS_STATUS
{
	BYTE		byGPSModule;      /*gps module, 0: not exist, 1: normal*/
	BYTE		byPositionStatus;	  /*gps position status, 0: fail, 1: success*/
	BYTE		bySignalStrength;    /*signal strength, 0: weak, 1: normal, 2: good*/
	BYTE		byres[5];
}NET_DVR_MB_GPS_STATUS, *LPNET_DVR_MB_GPS_STATUS;

typedef struct tagNET_DVR_MB_GSENSOR_STATUS
{
	BYTE		byGsensorModule;	/*g-sensor module, 0: not exist, 1 build-in: , 2: external*/
	BYTE		byCurAccX[10]; 	/*current acceleration of X*/
	BYTE		byCurAccY[10];	/*current acceleration of Y*/
	BYTE		byCurAccZ[10];	/*current acceleration of Z*/
	BYTE		byRefAccX[10];	/* reference acceleration of X*/
	BYTE		byRefAccY[10];	/* reference acceleration of Y*/
	BYTE		byRefAccZ[10];	/* reference acceleration of Z*/
	BYTE		byres[3];
}NET_DVR_MB_GSENSOR_STATUS, *LPNET_DVR_MB_GSENSOR_STATUS;

#define IP_ADDR_LEN 		16
#define IW_ESSID_MAX_SIZE	32

typedef struct tagNET_DVR_MB_WIFI_STATUS
{
	BYTE		byEnableWiFi; /* WIFI, 0 off, 1 on */
	BYTE 		byWiFiConnectStatus;  /* WIFI status, 0: fail to connect, 1: connect success 2: no module*/
	BYTE		bySignalStrength;             /* signal strength, 0 weak, 1 normal, 2 good */
	BYTE		byIPaddress[IP_ADDR_LEN];   /*WIFI device ip*/
	BYTE		byEssid[IW_ESSID_MAX_SIZE];  /*AP essid*/
	BYTE		byres[5];
}NET_DVR_MB_WIFI_STATUS,*LPNET_DVR_MB_WIFI_STATUS;

typedef struct tagNET_DVR_MB_PLATFORM_STATUS
{
	BYTE		byCurPlat;	  /*current platform, 0: wvs, 1: ivms, 2: CMS*/
	BYTE		byLoginStatus; 	/*login status, 0: login failed, 1: login success*/
	BYTE		byExceptionInfo;  	/*exception*/
/*
WVS :exception info:
	    0: fail to connect server
		1: logining
		2: user name or password error
		3: time out
		4: no heartbeat
		5: success
iVMS :exception info:
	    0: not login
		1: logining
		2: fail to connect
		3: heart beat timeout
		4: connection break
		5: New registration
		6: max device number in CMS
		7: max channel number in CMS
		8: no configuration in web management center
		9: communication to CMS and WEB management center error
		10:login unknown error
		11:login success
CMS  :exception info:	
        0: not login
		1: logining
		2: Duplicate registration
		3: connect fail
		4: server IP change
		5: login success
		6: logput
		7: heart beat timeout
*/						
	BYTE		byres[5];
}NET_DVR_MB_PLATFORM_STATUS, *LPNET_DVR_MB_PLATFORM_STATUS;

					
typedef struct tagNET_DVR_MB_MOBILEDEV_STATUS
{
	DWORD		dwSize;      
	union
	{
		NET_DVR_MB_GPS_STATUS struGPSStatus;
		NET_DVR_MB_GSENSOR_STATUS struGSensorStatus;
		NET_DVR_MB_WIFI_STATUS struWiFiStatus;
		NET_DVR_MB_PLATFORM_STATUS struPlatformStatus;
	}mobileStatus;
}NET_DVR_MB_MOBILEDEV_STATUS, *LPNET_DVR_MB_MOBILEDEV_STATUS;

#define NET_DVR_GPS_STATUS       0
#define NET_DVR_GSENSOR_STATUS   1
#define NET_DVR_WIFI_STATUS      2
#define NET_DVR_PLATFORM_STATUS  3


typedef struct tagNET_DVR_GPS_INFO
{
	BYTE    byDirection[2];		/*direction[0]0or1(east longitude/west longitude), direction[1]:0or1(North latitude/south latitude)  */
    BYTE    bySvs;         /* satellite vehicles：Effective Satellite number */
	BYTE    byLocateMode;  /* location mode：only NMEA0183 3.00 version，0=auto，1=Differential，2=Estimate，3= Invalid data*/
    WORD    wHDOP;  /* horizontal accuracy，0.5-99.9，below 6 represent high accuracy，above 20 need to be abandoned，this value is multipled by 10 */     
	WORD    wHeight;         	/* height */
	DWORD   dwLatitude;	 /*latitude = degree*3600*100+branch*60*100+second*100 */
	DWORD   dwLongitude; /*longitude =degree*3600*100+branch*60*100+second*100 */
	DWORD   dwVehicleSpeed;		/* mobile speed =speed*100000 kph*/
	DWORD	dwVehicleDirection;	/* mobile direction= actual direction*100，colockwise from North, uint:degree */
	BYTE	byRes[8];            
}NET_DVR_GPS_INFO,*LPNET_DVR_GPS_INFO; 

typedef struct tagNTE_DVR_GPS_DATA
{
	NET_DVR_GPS_INFO  struGPSInfo;      //GPS point
	NET_DVR_TIME      struTime;    		//GPS point time
	BYTE	    byRes[12];             
}NET_DVR_GPS_DATA,*LPNET_DVR_GPS_DATA;


typedef struct tagNET_DVR_GET_GPS_DATA_PAPAM
{	
	DWORD dwCmdType;              //0-find by time segment,1-find by time point	
	union
	{
		struct
		{
			NET_DVR_TIME struBeginTime;               //start time       
			NET_DVR_TIME struEndTime;                 //end time
            DWORD dwInterval;                  //interval,unit: second
			BYTE  byRes[76];                    
		}TimeSeg;
		struct
		{
			NET_DVR_TIME struTimePoint;              //time point
			BYTE  byRes[104];
		}TimePoint;	
	}GpsDataParam;
}NET_DVR_GET_GPS_DATA_PARAM,*LPNET_DVR_GET_GPS_DATA_PARAM;
/*************************************MVA 2.1 end****************************/
typedef struct tagNET_DVR_SDKLOCAL_CFG
{
	BYTE	byEnableAbilityParse;	//use ability parse,0-not use,1-use,default 0
	BYTE	byRes[511];
}NET_DVR_SDKLOCAL_CFG, *LPNET_DVR_SDKLOCAL_CFG;

typedef  struct  tagNET_DVR_OPTICAL_CHANNEL_BIND
{
    WORD wChannelIndex;    //optical port num(0-7)
	WORD wSubChannel;      //sub optical channel，get value range from ability set
	BYTE  byBind;      //0-not bind，1-bind
	BYTE  byRes[3];
}NET_DVR_OPTICAL_CHANNEL_BIND,*LPNET_DVR_OPTICAL_CHANNEL_BIND;

typedef struct tagNET_DVR_OPTICAL_CHANNEL_CFG
{
    DWORD dwSize;
	NET_DVR_OPTICAL_CHANNEL_BIND struBindVideo;//video binding configuration
    NET_DVR_OPTICAL_CHANNEL_BIND struBindAudio;//audio binding configuration
    BYTE  byRes[16];              
}NET_DVR_OPTICAL_CHANNEL_CFG,*LPNET_DVR_OPTICAL_CHANNEL_CFG;

typedef struct tagNET_DVR_OPTICAL_INFO
{
    DWORD dwSize;
	BYTE  bySlotNum;//code subsystem slot num
	BYTE  byChannel; //code channel num
	BYTE  byRes[18];
}NET_DVR_OPTICAL_INFO,*LPNET_DVR_OPTICAL_INFO;

//audio switch
typedef struct tagNET_DVR_AUDIO_SURCHAN_CFG
{
	DWORD dwSize;
	DWORD dwDispChan; //display channel num
	DWORD dwSubWinNum; //related sub window number
	DWORD dwSurChanNum;             /*device channel number */   
	NET_DVR_IPADDR struIpaddr;            /*device ip address */
	WORD   wPort;                      	/*device port */ 	
	BYTE   byRes2[14];
}NET_DVR_AUDIO_SURCHAN_CFG, *LPNET_DVR_AUDIO_SURCHAN_CFG;

typedef struct tagNET_DVR_AUDIO_SURCHAN_STATUS
{
	DWORD dwSize;
	BYTE  byStatus;      //switch status，0-no switched,1-switched
	BYTE  byRes1[3];
	//byStatus == 1 valid
	DWORD dwSubWinNum;   //related sub window number
	DWORD dwSurChanNum;     /*device channel number */ 
	NET_DVR_IPADDR  struIpaddr;        /*device ip address */
	WORD  wPort;            /*device port */ 
	BYTE  byRes2[14];
}NET_DVR_AUDIO_SURCHAN_STATUS,*LPNET_DVR_AUDIO_SURCHAN_STATUS;

//ethernet channel
#define MAX_ETHERNET_PORT_NUM       8//max port number in one link
typedef struct tagNET_DVR_ETHERNET_CHANNEL_INFO
{
	DWORD dwSize;
	BYTE byConverge[MAX_ETHERNET_PORT_NUM];
	//byConverge[i] = j represents add port i to link j,j's value range is 1-8,j = 0 means delete port i from the link
	BYTE byRes[32];
}NET_DVR_ETHERNET_CHANNEL_INFO,*LPNET_DVR_ETHERNET_CHANNEL_INFO;
//spartan
typedef struct tagNET_DVR_SPARTAN_INFO
{
	DWORD  dwSize;
	BYTE   bySpartanStatus; //0-off,1-on
	BYTE   byRes[31];
}NET_DVR_SPARTAN_INFO,*LPNET_DVR_SPARTAN_INFO;

typedef struct tagNET_DVR_IPADDR_FILTERCFG
{
	DWORD dwSize;
	BYTE byEnable; //enable,0-no,1-yes
	BYTE byFilterType; //filter type,0-forbit,1-permit
	BYTE byRes1[2];
	BYTE byRes[16];
    BYTE byIPAddr[1024];	//IP address,for 192.168.1.2;192.168.1.3
}NET_DVR_IPADDR_FILTERCFG, *LPNET_DVR_IPADDR_FILTERCFG;

typedef struct tagNET_DVR_LOGO_OVERLAYCFG
{
	DWORD dwSize;
	BYTE byEnable; //enable,0-no,1-yes
	BYTE byRes1[3];
	DWORD dwCoordinateX;	//X coordinate
    DWORD dwCoordinateY;	//Y coordinate
    BYTE byRes[16];		
}NET_DVR_LOGO_OVERLAYCFG,*LPNET_DVR_LOGO_OVERLAYCFG;

typedef struct tagNET_DVR_STRUCTHEAD
{
    WORD	wLength;		//结构长度
    BYTE	byVersion ;	/*高低4位分别代表高低版本，后续根据版本和长度进行扩展，不同的版本的长度进行限制*/
    BYTE	byRes;
}NET_DVR_STRUCTHEAD, *LPNET_DVR_STRUCTHEAD;

typedef struct tagNET_DVR_INVALID_DISK_PARAM
{
	NET_DVR_STRUCTHEAD	struStructHead;
	DWORD				dwDiskNo;			// Disk number
	BYTE				byDelAll;			// 0-Delete dwDiskNo  1-Delete all
	BYTE 				byres[31];
}NET_DVR_INVALID_DISK_PARAM, *LPNET_DVR_INVALID_DISK_PARAM;


typedef struct tagNET_DVR_INVALID_MOUNT_DISK_PARAM
{
	NET_DVR_STRUCTHEAD	struStructHead;
	DWORD				dwDiskNo;			// Disk number
	BYTE 				byres[32];
}NET_DVR_MOUNT_DISK_PARAM, *LPNET_DVR_MOUNT_DISK_PARAM;

// Long config callback type
typedef enum
{
	NET_SDK_CALLBACK_TYPE_STATUS = 0,		// Status
	NET_SDK_CALLBACK_TYPE_PROGRESS,			// Progress
	NET_SDK_CALLBACK_TYPE_DATA				// Data
}NET_SDK_CALLBACK_TYPE;


// Long config status value
typedef enum
{
	NET_SDK_CALLBACK_STATUS_SUCCESS = 1000,		// Success
	NET_SDK_CALLBACK_STATUS_PROCESSING,			// Processing
	NET_SDK_CALLBACK_STATUS_FAILED				// Failed
}NET_SDK_CALLBACK_STATUS_NORMAL;

/*************************************coder server start****************************/
#define MAX_CODE_CARD_SUPPORTDISPNUMS 8//max support display channel for one card
#define MAX_SUPPORT_RES 32

typedef enum _BOARD_TYPE
{
	DS4004HC_BOARD		=2,  //4004HC
	DS4008HC_BOARD		=3,  //4008HC
	DS4016HC_BOARD		=4,  //4016HC
	DS4001HF_BOARD		=5,  //4001HF
	DS4004HF_BOARD		=6,  //4004HF
	DS4002MD_BOARD		=7,  //4002MD
	DS4004MD_BOARD		=8,  //4004MD
	DS4016HCS_BOARD		=9,  //4016HCS
	DS4004HC_PLUS_BOARD	=13, //4004HC+
	DS4008HC_PLUS_BOARD	=14, //4008HC+
	DS4016HC_PLUS_BOARD	=15, //4016HC+
	DS4008HF_BOARD		=16, //4008HF
	DS4008MD_BOARD		=17, //4008MD
	DS4008HS_BOARD		=18, //4008HS
	DS4016HS_BOARD		=19, //4016HS
		
	DS4108HCV_BOARD		=20, //4108HCV
	DS4116HCV_BOARD		=21, //4116HCV
	DS5016HC_BOARD		=22, //5016HC
		
	DS4208HFV_BOARD		=23, //4208HFV
	DS4216HC_BOARD		=24, //4216HC
	DS4216HFV_BOARD		=25, //4216HFV
		
	DS5008HF_BOARD		=26, //5008HF
	DS5116HF_BOARD		=27, //5116HF
		
	DS5216HC_BOARD		=28, //5216HC
	DS5208HF_BOARD		=29, //5208HF
	DS5216HF_BOARD		=30, //5216HF
		
	DS4101HD_BOARD		=31, //4101HD
	DS4102HD_BOARD		=32, //4102HD
	DS4104HD_BOARD		=33, //4104HD
		
	DS4002MD_PLUS_BOARD =34, //4002MD+  
	DS4004MD_PLUS_BOARD =35, //4004MD+
		
	DS4204HFV_BOARD		=36, //4204HFV
	DS4308HCV_BOARD		=37, //4308HCV
	DS4308HFV_BOARD		=38, //4308HFV
	DS4316HCV_BOARD		=39, //4316HCV
	DS4316HFV_BOARD		=40, //4316HFV
	DS4304HD_BOARD		=41, //4304HD
	DS4304HFH_BOARD     =42, //4304HFH
	DS4304HFV_BOARD     =43, //4304HFV
	DS4302HFH_BOARD     =44, //4302HFH
	DS5316HF_BOARD      =45, //5316HF
	UNKNOWN_BOARD_TYPE  =0xffffffff,
}BOARD_TYPE;

typedef struct tagNET_DVR_CODECARD_ABILITY 
{
	BYTE byCardType;      //code card type(enum BOARD_TYPE)
	BYTE byCodeNums;      //code channel nummber 
    BYTE byDispNums;      //display channel number 
    BYTE byCodeStartIdx;     //fisrt code channel index in all code channels 
    BYTE byDispStartIdx;     //first display channel index in all display channels
    BYTE byRes1[3]; 
    DWORD dwVgaSupportResolution[MAX_SUPPORT_RES/*32*/];//supported resolution of VGA
    DWORD dwHdmiSupportResolution[MAX_SUPPORT_RES/*32*/];//supported resolution of HDMI
    DWORD dwDviSupportResolution[MAX_SUPPORT_RES/*32*/];//supported resolution of DVI
    DWORD dwYpbprSupportResolution[MAX_SUPPORT_RES/*32*/];//supported resolution of Ypbpr
    BYTE byDispFormat[MAX_CODE_CARD_SUPPORTDISPNUMS];   //supported display format(enum HD_DISPLAY_FORMAT) 
    BYTE byWindowMode[MAX_CODE_CARD_SUPPORTDISPNUMS][12]; //supported window mode(eg. 1,2,4,9,16))
    BYTE byRes2[36];
}NET_DVR_CODECARD_ABILITY,*LPNET_DVR_CODECARD_ABILITY;

#define		MAX_CODE_CARD_NUM			8   //max code card number
typedef struct tagNET_DVR_CODESVR_ABILITY
{
    DWORD dwSize;      
    BYTE byCardNums;      /* code card number */
    BYTE byStartChan;     /* start channel number */
    BYTE byRes1[2];
    NET_DVR_CODECARD_ABILITY struCodeCardAbility[MAX_CODE_CARD_NUM];
    BYTE byRes2[64];
}NET_DVR_CODESVR_ABILITY, *LPNET_DVR_CODESVR_ABILITY;

typedef struct tagNET_DVR_CODER_SERVER_OUTPUT_CFG
{
	DWORD  dwSize;
	BYTE   byDispChanType;		/*display channel type：0-BNC，1-VGA，2-HDMI，3-DVI*/ 
	BYTE   byVedioFormat;      /*1:NTSC,2:PAL，0-NULL*/
	BYTE   byRes1[2];
	DWORD  dwResolution;       //resolution
	DWORD  dwWindowMode;		/*window mode*/
	BYTE   byRes2[64];
}NET_DVR_CODER_SERVER_OUTPUT_CFG,*LPNET_DVR_CODER_SERVER_OUTPUT_CFG;

typedef struct tagNET_DVR_DISPLAY_START_INFO 
{
	DWORD  dwSize;
	DWORD  dwDisplayChan; //display channel number
	DWORD  dwCodeChan; //code channel number
	DWORD  dwWinNum;   //window number
	BYTE   byEnableAudio; //enable video，0-disable，1-enable
	BYTE   byRes[31];
}NET_DVR_DISPLAY_START_INFO,*LPNET_DVR_DISPLAY_START_INFO;

typedef struct tagNET_DVR_CODER_WINDOW_INFO
{
	DWORD dwSize;
	DWORD dwDisplayChan;//display channel number
	DWORD dwWinNum;     //window number
	BYTE  byRes[16];
}NET_DVR_CODER_WINDOW_INFO,*LPNET_DVR_CODER_WINDOW_INFO;

typedef struct tagNET_DVR_WINDOW_STATUS
{
    DWORD  dwSize;         
    DWORD  dwCodeChan;      /*code channel number*/
    BYTE   byDisplay;        /*enable output，0-disable，1-enable*/
    BYTE   byAudio;			/*enable video，0-disable，1-enable*/   
    BYTE   byRes[30];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}NET_DVR_WINDOW_STATUS,*LPNET_DVR_WINDOW_STATUS;

/*************************************coder server end****************************/


/********************************SDK API definition*********************************/
NET_DVR_API BOOL __stdcall NET_DVR_Init();
NET_DVR_API BOOL __stdcall NET_DVR_Cleanup();

//NET_DVR_SetDVRMessage extension
#ifdef _WIN32
  NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessage(UINT nMessage,HWND hWnd);
  NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT nMessage, HWND hWnd, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
#elif defined(__linux__) || defined(__APPLE__)
  NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT reserved1, void* reserved2, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
  /*Linux*/
  #ifdef __linux__
    #ifdef __cplusplus
	    NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL = 1);
    #else
	     NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL);
    #endif
    NET_DVR_API BOOL NET_DVR_DrawAreaRelease();
  #endif
#endif

NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_EX(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_NEW(BOOL (CALLBACK *fMessCallBack_NEW)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, WORD dwLinkDVRPort));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack(BOOL (CALLBACK *fMessageCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, DWORD dwUser), DWORD dwUser);
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);

#ifdef __cplusplus
	NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime = 3000, DWORD dwTryTimes = 3);
	NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval = 30000, BOOL bEnableRecon = TRUE);
#else
	NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime, DWORD dwTryTimes);
	NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);
#endif
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKVersion();
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKBuildVersion();
NET_DVR_API int __stdcall NET_DVR_IsSupport();
NET_DVR_API BOOL __stdcall NET_DVR_StartListen(char *sLocalIP,WORD wLocalPort);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen();

#ifdef __cplusplus
	NET_DVR_API LONG __stdcall NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData = NULL);
#else
	NET_DVR_API LONG __stdcall NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData);
#endif
NET_DVR_API BOOL __stdcall NET_DVR_StopListen_V30(LONG lListenHandle);
NET_DVR_API LONG __stdcall NET_DVR_Login(const char *sDVRIP, const WORD wDVRPort, const char *sUserName, const char *sPassword, LPNET_DVR_DEVICEINFO lpDeviceInfo);
NET_DVR_API LONG __stdcall NET_DVR_Login_V30(const char *sDVRIP, const WORD wDVRPort, const char *sUserName, const char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
// There's no such function
// NET_DVR_API BOOL __stdcall NET_DVR_Login_Check(const char *sDVRIP, const WORD wDVRPort, const char *sUserName, const char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Logout(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_Logout_V30(LONG lUserID);
NET_DVR_API DWORD __stdcall NET_DVR_GetLastError();
#ifdef __cplusplus
	NET_DVR_API char* __stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo = NULL);
#else
	NET_DVR_API char* __stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo);
#endif
NET_DVR_API BOOL __stdcall NET_DVR_SetShowMode(DWORD dwShowType,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRIPByResolveSvr(char *sServerIP, WORD wServerPort, BYTE *sDVRName,WORD wDVRNameLen,BYTE *sDVRSerialNumber,WORD wDVRSerialLen,char* sGetIP);
NET_DVR_API BOOL  __stdcall NET_DVR_GetDVRIPByResolveSvr_EX(char *sServerIP, WORD wServerPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP, DWORD *dwPort);

//Preview releated interface
#ifdef __cplusplus
	NET_DVR_API LONG __stdcall NET_DVR_PlayDirect(char *sDVRIP, char *sUserName, char *sPassword, \
												  LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
#else
	NET_DVR_API LONG __stdcall NET_DVR_PlayDirect(char *sDVRIP, char *sUserName, char *sPassword, \
												  LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
#endif
NET_DVR_API LONG __stdcall NET_DVR_RealPlay(LONG lUserID,LPNET_DVR_CLIENTINFO lpClientInfo);
#ifdef __cplusplus
	NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
#else
	NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
#endif
NET_DVR_API BOOL __stdcall NET_DVR_StopRealPlay(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayDirect(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_RigisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayerBufNumber(LONG lRealHandle,DWORD dwBufNum);
NET_DVR_API BOOL __stdcall NET_DVR_ThrowBFrame(LONG lRealHandle,DWORD dwNum);
NET_DVR_API BOOL __stdcall NET_DVR_SetAudioMode(DWORD dwMode);
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_Volume(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopSaveRealData(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetRealDataCallBack(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetStandardDataCallBack(LONG lRealHandle,void(CALLBACK *fStdDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture(LONG lRealHandle,char *sPicFileName);//bmp

//Make I frame
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrame(LONG lUserID, LONG lChannel);//main stream
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//sub stream

//PTZ control releated interface
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_Other(LONG lUserID,LONG lChannel,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_Other(LONG lUserID,LONG lChannel,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_EX(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_EX(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_EX(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_EX(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_EX(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZCruise(LONG lUserID,LONG lChannel,LONG lCruiseRoute, LPNET_DVR_CRUISE_RET lpCruiseRet);


//File search and playback
NET_DVR_API LONG __stdcall NET_DVR_FindFile(LONG lUserID,LONG lChannel,DWORD dwFileType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile(LONG lFindHandle,LPNET_DVR_FIND_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V30(LONG lFindHandle, LPNET_DVR_FINDDATA_V30 lpFindData);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V30(LONG lUserID, LPNET_DVR_FILECOND pFindCond);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose_V30(LONG lFindHandle);

NET_DVR_API BOOL __stdcall NET_DVR_LockFileByName(LONG lUserID, char *sLockFileName);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByName(LONG lUserID, char *sUnlockFileName);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByName(LONG lUserID,char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByName(LONG lUserID, char *sPlayBackFileName, HWND hWnd);

NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl(LONG lPlayHandle,DWORD dwControlCode,DWORD dwInValue,DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBack(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack_V40(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack_V40) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,void *pUser),void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackSaveData(LONG lPlayHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBackSave(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlayBackOsdTime(LONG lPlayHandle, LPNET_DVR_TIME lpOsdTime);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackCaptureFile(LONG lPlayHandle,char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByName(LONG lUserID,char *sDVRFileName,char *sSavedFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopGetFile(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadPos(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetPlayBackPos(LONG lPlayHandle);

//Upgrade
NET_DVR_API LONG __stdcall NET_DVR_AdapterUpgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_Upgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_VcalibUpgrade(LONG lUserID, LONG lChannel, char const *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetUpgradeProgress(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);
//Remote format disk
NET_DVR_API LONG __stdcall NET_DVR_FormatDisk(LONG lUserID,LONG lDiskNumber);
NET_DVR_API BOOL __stdcall NET_DVR_GetFormatProgress(LONG lFormatHandle, LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFormatHandle(LONG lFormatHandle);
//Alarm
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan(LONG lAlarmHandle);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
//Voice talk
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_V30(LONG lUserID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_StopVoiceCom(LONG lVoiceComHandle);
//Forward Voice
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR_V30(LONG lUserID, DWORD dwVoiceChan, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceComSendData(LONG lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetCurrentAudioCompress(LONG lUserID, LPNET_DVR_COMPRESSION_AUDIO lpCompressAudio);
//Voice broadcast
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart();
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart_V30(void(CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer, DWORD dwBufSize, void * pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStop();
NET_DVR_API BOOL __stdcall NET_DVR_AddDVR(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_AddDVR_V30(LONG lUserID, DWORD dwVoiceChan);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR_V30(LONG lVoiceHandle);
////////////////////////////////////////////////////////////
//Transparent Channel
NET_DVR_API LONG __stdcall NET_DVR_SerialStart(LONG lUserID,LONG lSerialPort,void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
//If RS485 is used as transparent channel,  please specify the channel No. And different channels can have different RS485 parameters
NET_DVR_API BOOL __stdcall NET_DVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SerialStop(LONG lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SendTo232Port(LONG lUserID, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SendToSerialPort(LONG lUserID, DWORD dwSerialPort, DWORD dwSerialIndex, char *pSendBuf, DWORD dwBufSize);

//Decoding nBitrate = 16000
#ifdef __cplusplus
	NET_DVR_API void* __stdcall NET_DVR_InitG722Decoder(int nBitrate = 16000);
#else
	NET_DVR_API void* __stdcall NET_DVR_InitG722Decoder(int nBitrate);
#endif
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG722Frame(void *pDecHandle, BYTE* pInBuffer, BYTE* pOutBuffer);
//Encoding
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,BYTE* pInBuffer, BYTE* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);

//Decoding
NET_DVR_API void* __stdcall NET_DVR_InitG726Decoder(void** pDecMoudle);
NET_DVR_API void __stdcall NET_DVR_ReleaseG726Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG726Frame(void *pDecMoudle, BYTE* pInBuffer, BYTE* pOutBuffer, BYTE byReset);
//Encoding
NET_DVR_API void* __stdcall NET_DVR_InitG726Encoder(void** pEncMoudle);
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG726Frame(void *pEncMoudle,BYTE* pInBuffer, BYTE* pOutBuffer, BYTE byReset);
NET_DVR_API void __stdcall NET_DVR_ReleaseG726Encoder(void *pEncHandle);
//Control the local preview remotely
NET_DVR_API BOOL __stdcall NET_DVR_ClickKey(LONG lUserID, LONG lKeyIndex);
//Control the manual record remotely
NET_DVR_API BOOL __stdcall NET_DVR_StartDVRRecord(LONG lUserID,LONG lChannel,LONG lRecordType);
NET_DVR_API BOOL __stdcall NET_DVR_StopDVRRecord(LONG lUserID,LONG lChannel);
//Decoding Card
NET_DVR_API BOOL __stdcall NET_DVR_InitDevice_Card(long *pDeviceTotalChan);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDevice_Card();
NET_DVR_API BOOL __stdcall NET_DVR_InitDDraw_Card(HWND hParent,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDraw_Card();
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_Card(LONG lUserID,LPNET_DVR_CARDINFO lpCardInfo,long lChannelNum);
NET_DVR_API BOOL __stdcall NET_DVR_ResetPara_Card(LONG lRealHandle,LPNET_DVR_DISPLAY_PARA lpDisplayPara);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_ClearSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_RestoreSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetVolume_Card(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_AudioPreview_Card(LONG lRealHandle,BOOL bEnable);
NET_DVR_API LONG __stdcall NET_DVR_GetCardLastError_Card();
NET_DVR_API HANDLE __stdcall NET_DVR_GetChanHandle_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture_Card(LONG lRealHandle, char *sPicFileName);
//NET_DVR_GetSerialNum_Card is invalid,  Call GetBoardDetail instead.
NET_DVR_API BOOL __stdcall NET_DVR_GetSerialNum_Card(long lChannelNum,DWORD *pDeviceSerialNo);
//Log
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog(LONG lLogHandle, LPNET_DVR_LOG lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose(LONG lLogHandle);
#ifdef __cplusplus
	NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_V30(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, BOOL bOnlySmart = FALSE);
#else
	NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_V30(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, BOOL bOnlySmart);
#endif
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_V30(LONG lLogHandle, LPNET_DVR_LOG_V30 lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose_V30(LONG lLogHandle);
// Alarmhost log
NET_DVR_API LONG __stdcall NET_DVR_FindAlarmHostLog(LONG lUserID, LONG lSelectMode, NET_DVR_ALARMHOST_SEARCH_LOG_PARAM *lpSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextAlarmHostLog(LONG lFindHandle, NET_DVR_ALARMHOST_LOG_RET *lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindAlarmHostLogClose(LONG lFindHandle);
//ATM DVR
NET_DVR_API LONG __stdcall NET_DVR_FindFileByCard(LONG lUserID,LONG lChannel,DWORD dwFileType, int nFindType, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);

//Encoding
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,BYTE* pInBuffer, BYTE* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);
//2005-09-15
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, const char *sPicFileName);
//Grab JPEG and save to RAM
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture_NEW(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize,  LPDWORD lpSizeReturned);


//2006-02-16
NET_DVR_API LONG __stdcall NET_DVR_GetRealPlayerIndex(LONG lRealHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetPlayBackPlayerIndex(LONG lPlayHandle);

//2006-08-28 704-640 Scale
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG(LONG lUserID, DWORD dwScale);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG(LONG lUserID, DWORD *lpOutScale);
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
//2006- 08- 28 Port of ATM
NET_DVR_API BOOL __stdcall NET_DVR_SetATMPortCFG(LONG lUserID, WORD wATMPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetATMPortCFG(LONG lUserID, WORD *LPOutATMPort);

//2006- 11- 10 Display on Multi displayer
NET_DVR_API BOOL __stdcall NET_DVR_InitDDrawDevice();
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDrawDevice();
NET_DVR_API LONG __stdcall NET_DVR_GetDDrawDeviceTotalNums();
NET_DVR_API BOOL __stdcall NET_DVR_SetDDrawDevice(LONG lPlayPort, DWORD nDeviceNum);

NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn(LONG lRealHandle, LPNET_DVR_POINT_FRAME pStruPointFrame);
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn_EX(LONG lUserID, LONG lChannel, LPNET_DVR_POINT_FRAME pStruPointFrame);
//Decoder DS- 6001D/DS- 6001F
NET_DVR_API BOOL __stdcall NET_DVR_StartDecode(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERINFO lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecode(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecoderState(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERSTATE lpDecoderState);
//2005-08-01
NET_DVR_API BOOL __stdcall NET_DVR_SetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_DecPlayBackCtrl(LONG lUserID, LONG lChannel, DWORD dwControlCode, DWORD dwInValue,DWORD *LPOutValue, LPNET_DVR_PLAYREMOTEFILE lpRemoteFileInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StartDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlDec(LONG lUserID, LONG lChannel, DWORD dwControlCode);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlScreen(LONG lUserID, LONG lChannel, DWORD dwControl);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecCurLinkStatus(LONG lUserID, LONG lChannel, LPNET_DVR_DECSTATUS lpDecStatus);

//Multi- channel decoder
//2007- 11- 30 V211 support the API below //11
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DYNAMIC_DEC lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopDynamic(LONG lUserID, DWORD dwDecChanNum); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecEnable(LONG lUserID, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_STATUS lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetVideoStandard(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwVideoStandard);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetVideoStandard(LONG lUserID, DWORD dwDecChanNum, DWORD dwVideoStandard);

//2007-12-22 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlayControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwControlCode, DWORD dwInValue, DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetRemotePlayStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS lpOuter);
//2009-4-13 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);

NET_DVR_API LONG __stdcall NET_DVR_MatrixStartPassiveDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_PASSIVEMODE lpPassiveMode /*, void(CALLBACK *fPassiveDataCallBack)(LONG lPassiveHandle, char * pSendBuf, DWORD dwBufSize, DWORD dwStatus, DWORD dwUser), DWORD dwUser*/);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSendData(LONG lPassiveHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopPassiveDecode(LONG lPassiveHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UploadLogo(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_DISP_LOGOCFG lpDispLogoCfg, char *sLogoBuffer);
#define	NET_DVR_SHOWLOGO			1		/*Show LOGO*/
#define	NET_DVR_HIDELOGO			2		/*Hide LOGO*/  
NET_DVR_API BOOL __stdcall NET_DVR_LogoSwitch(LONG lUserID, DWORD dwDecChan, DWORD dwLogoSwitch);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus(LONG lUserID,  LPNET_DVR_DECODER_WORK_STATUS lpDecoderCfg);

#define	DISP_CMD_ENLARGE_WINDOW				1	/*Enlarge some region*/
#define	DISP_CMD_RENEW_WINDOW				2	/*Restore the region*/

NET_DVR_API BOOL __stdcall NET_DVR_MatrixDiaplayControl(LONG lUserID, DWORD dwDispChanNum, DWORD dwDispChanCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPassiveDecodeControl(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PASSIVEDECODE_CONTROL lpInter);
NET_DVR_API LONG __stdcall NET_DVR_MatrixGetPassiveDecodeStatus(LONG lPassiveHandle);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshPlay(LONG lPlayHandle);
//Restore default configuration
NET_DVR_API BOOL __stdcall NET_DVR_RestoreConfig(LONG lUserID);
//Save configuration
NET_DVR_API BOOL __stdcall NET_DVR_SaveConfig(LONG lUserID);
//Reboot
NET_DVR_API BOOL __stdcall NET_DVR_RebootDVR(LONG lUserID);
//Shutdown DVR
NET_DVR_API BOOL __stdcall NET_DVR_ShutDownDVR(LONG lUserID);

//config parameter begin
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState_V30(LONG lUserID, LPNET_DVR_WORKSTATE_V30 lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState(LONG lUserID, LPNET_DVR_WORKSTATE lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_SetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmProtocol(LONG lUserID, LPNET_DVR_ATM_PROTOCOL lpAtmProtocol);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut_V30(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS_V30 lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmOut(LONG lUserID, LONG lAlarmOutPort,LONG lAlarmOutStatic);

//Adjust video parameters
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetVideoEffect(LONG lRealHandle,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetVideoEffect(LONG lRealHandle,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);

//Configuration File
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_V30(LONG lUserID, char *sOutBuffer, DWORD dwOutSize, DWORD *pReturnSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_EX(LONG lUserID, char *sOutBuffer, DWORD dwOutSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile_EX(LONG lUserID, char *sInBuffer, DWORD dwInSize);

//write log file
#ifdef __cplusplus
	NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD nLogLevel = 0, char * strLogDir = NULL, BOOL bAutoDel = TRUE);
#else
	NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD nLogLevel, char * strLogDir, BOOL bAutoDel);
#endif
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKState(LPNET_DVR_SDKSTATE pSDKState);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKAbility(LPNET_DVR_SDKABL pSDKAbl);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol(LONG lUserID, NET_DVR_PTZCFG *pPtzcfg);
//Lock Front Panel
NET_DVR_API BOOL __stdcall NET_DVR_LockPanel(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_UnLockPanel(LONG lUserID);

NET_DVR_API BOOL __stdcall NET_DVR_SetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpOutBuffer, DWORD dwOutBufferSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceAbility(LONG lUserID, DWORD dwAbilityType, char* pInBuf, DWORD dwInLength, char* pOutBuf, DWORD dwOutLength);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);

// set/get vca behavior param key
NET_DVR_API BOOL __stdcall NET_DVR_SetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int nValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int *pValue);

//add target API for Get/SetVCA
NET_DVR_API BOOL __stdcall NET_DVR_GetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);
NET_DVR_API BOOL __stdcall NET_DVR_SetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);

//Track mode configuration interface
NET_DVR_API BOOL __stdcall NET_DVR_SetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);

//Restart VCA Lib
NET_DVR_API BOOL __stdcall NET_VCA_RestartLib(LONG lUserID, LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData_V30(LONG lRealHandle, DWORD dwTransType, char *sFileName);

NET_DVR_API BOOL __stdcall NET_DVR_EncodeG711Frame(DWORD iType, BYTE *pInBuffer, BYTE *pOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG711Frame(DWORD iType, BYTE *pInBuffer, BYTE *pOutBuffer);
NET_DVR_API LONG __stdcall NET_DVR_FindFileByEvent(LONG lUserID, LPNET_DVR_SEARCH_EVENT_PARAM  lpSearchEventParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextEvent(LONG lSearchHandle, LPNET_DVR_SEARCH_EVENT_RET lpSearchEventRet);
//NET_DVR_FindClose is invalid

NET_DVR_API LONG __stdcall NET_DVR_FindPDCInfo(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPDCInfo(LONG lFindHandle,LPNET_DVR_PDC_QUERY lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindPDCClose(LONG lFindHandle);

//Calibration 
#define NET_DVR_PDC_VERIFY_CALIBRATION          1  
#define NET_DVR_VERIFY_BEHAVIOR_CALIBRATION     2    
#define NET_DVR_VERIFY_ITS_CALIBRATION		    3 	

NET_DVR_API BOOL __stdcall  NET_DVR_VerifyCalibration(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOuterBuffer, DWORD dwOuterBufferSize);
NET_DVR_API BOOL __stdcall  NET_DVR_ResetCounter(LONG lUserID,LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_MATRIX(LONG lLogHandle, LPNET_DVR_LOG_MATRIX lpLogData);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_Matrix(LONG lUserID, LONG lSelectMode, DWORD dwMajorType, DWORD dwMinorType, LPNET_DVR_VEDIOPLATLOG lpVedioPlatLog, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);

NET_DVR_API BOOL __stdcall NET_DVR_ManualSnap(LONG lUserID, LPNET_DVR_MANUALSNAP lpInter, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol_Ex(LONG lUserID, LONG lChannel, NET_DVR_PTZCFG *pPtzcfg);

NET_DVR_API LONG __stdcall NET_DVR_StartEmailTest(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_StopEmailTest(LONG lEmailTestHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetEmailTestProgress(LONG lEmailTestHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_GetIPCProtoList(LONG lUserID, LPNET_DVR_IPC_PROTO_LIST lpProtoList);
NET_DVR_API LONG __stdcall NET_DVR_SmartSearch(LONG lUserID,  LPNET_DVR_SMART_SEARCH_PARAM lpSmartSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_SearchNextInfo(LONG lSearchHandle, LPNET_DVR_SMART_SEARCH_RET lpSmartSearchRet);
NET_DVR_API BOOL __stdcall NET_DVR_StopSearch(LONG lSearchHandle);

// IP San Directory search
NET_DVR_API LONG __stdcall NET_DVR_FindIpSanDirectory(LONG lUserID, LPNET_DVR_IPSAN_SERACH_PARAM lpIpsanSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDirectory(LONG lFindHandle, LPNET_DVR_IPSAN_SERACH_RET lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindDirectoryClose(LONG lFindHandle);

typedef void (CALLBACK *REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

#ifdef __cplusplus
	NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30 = NULL, void* pUser = NULL, BOOL bBlocked = TRUE);
#else
	NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30, void* pUser, BOOL bBlocked);
#endif

NET_DVR_API BOOL __stdcall NET_DVR_ZeroStopPlay(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroMakeKeyFrame(LONG lUserID, LONG lZeroChan);
#ifdef __cplusplus
	NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle,DWORD dwControlCode, LPVOID lpInBuffer = NULL, DWORD dwInLen = 0, LPVOID lpOutBuffer = NULL, DWORD *lpOutLen = NULL);
#else
	NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle,DWORD dwControlCode, LPVOID lpInBuffer, DWORD dwInLen, LPVOID lpOutBuffer, DWORD *lpOutLen);
#endif
NET_DVR_API BOOL __stdcall NET_DVR_ZeroTurnOver(LONG lUserID, LONG lChannel, BOOL bNextPreview);

NET_DVR_API BOOL __stdcall NET_DVR_GetDiskList(LONG lUserID, LPNET_DVR_DISKABILITY_LIST lpDiskList);
NET_DVR_API LONG __stdcall NET_DVR_Backup(LONG lUserID, DWORD dwBackupType, LPVOID lpBackupBuff, DWORD dwBackupBuffSize);
NET_DVR_API LONG __stdcall NET_DVR_BackupByName(LONG lUserID, LPNET_DVR_BACKUP_NAME_PARAM lpBackupByName);
NET_DVR_API LONG __stdcall NET_DVR_BackupByTime(LONG lUserID, LPNET_DVR_BACKUP_TIME_PARAM lpBackupBytime);
NET_DVR_API BOOL __stdcall NET_DVR_GetBackupProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_StopBackup(LONG lHandle);

NET_DVR_API BOOL __stdcall NET_DVR_GetSadpInfoList(LONG lUserID, LPNET_DVR_SADPINFO_LIST lpSadpInfoList);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateSadpInfo(LONG lUserID, LPNET_DVR_SADP_VERIFY lpSadpVerify, LPNET_DVR_SADPINFO lpSadpInfo);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_SetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestDeleteFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCDWByFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpCdrwFile);
NET_DVR_API LONG __stdcall NET_DVR_InquestUploadFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_InquestUploadClose(LONG lUploadHandle);
NET_DVR_API LONG __stdcall NET_DVR_InquestGetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStartCDW( LONG lUserID, BOOL bPause);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStopCDW(LONG lUserID, BOOL bCancelWrite);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDWState(LONG lUserID, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCheckSecretKey(LONG lUserID, BOOL *bSecretSet);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetSecretKey(LONG lUserID, LPNET_DVR_INQUEST_SECRET_INFO pSecretInfo);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStreamEncrypt(LONG lUserID, LONG lChannel, BOOL bEncrypt);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetEncryptState(LONG  lUserID, LONG lChannel, BOOL *bEncrypt);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindFile(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindNextFile(LONG lFindHandle, LPNET_DVR_INQUEST_FILEINFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_InquestFindClose(LONG lFindHandle);

// 9000RH
NET_DVR_API LONG __stdcall NET_DVR_RaidFastConfig(LONG lUserID, char *sName);
NET_DVR_API BOOL __stdcall NET_DVR_FastConfigProcess(LONG lHandle, DWORD *pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFastConfig(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetArraySpaceAlloc(LONG lUserID, DWORD dwSlot, LPNET_DVR_ARRAY_SPACE_ALLOC_INFO lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DelArray(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_CreateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CalcArraySize(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam, UINT64* lpArraySize);
NET_DVR_API BOOL __stdcall NET_DVR_MigrateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_RebuildArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CreateVD(LONG lUserID, LPNET_DVR_OPERATE_VD_PARAM lpVDParam);
NET_DVR_API BOOL __stdcall NET_DVR_DelVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_RepairVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_SetSpareDisk(LONG lUserID, LPNET_DVR_SPARE_DISK_PARAM lpSpareDisk);
NET_DVR_API BOOL __stdcall NET_DVR_GetPDList(LONG lUserID,  LPNET_DVR_PHY_DISK_LIST lpPDList);
NET_DVR_API BOOL __stdcall NET_DVR_GetArrayList(LONG lUserID, LPNET_DVR_ARRAY_LIST lpArrayList);
NET_DVR_API BOOL __stdcall NET_DVR_GetVDList(LONG lUserID, LPNET_DVR_VD_LIST lpVDList);
NET_DVR_API LONG __stdcall NET_DVR_ExpandDisk(LONG    lUserID,DWORD dwVDSLot);
NET_DVR_API BOOL __stdcall NET_DVR_GetExpandProgress(LONG lExpandHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseExpandHandle(LONG lExpandHandle);
NET_DVR_API LONG __stdcall NET_DVR_AlgoDebugStart(LONG lUserID, LONG lCHannel, void(CALLBACK *fAlgoLibInfoCallBack)(LONG lHandle, LONG lChannel,char *pRecvDataBuffer, DWORD dwBufSize, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugSend(LONG lHandle, LONG lChannel, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugStop(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrint(BOOL bLogPrint);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrintAction(DWORD nLogLevel, DWORD nToDevice, BOOL bEnable, int Reserve1, int Reserve2);

NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule_V41(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG_V41 lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule_V41(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG_V41 lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_SetSceneMode(LONG  lUserID, LONG lChannel, DWORD dwSceneMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetSceneMode(LONG lUserID, LONG lChannel, DWORD  *pSceneMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetVCAVersion(LONG lUserID, LONG lChannel, LPNET_DVR_VCA_VERSION lpVersion);
   
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPicAdjust(LONG lUserID, DWORD dwDispChan, DWORD dwPicAdjust, DWORD dwCmdParam); 
NET_DVR_API BOOL __stdcall NET_DVR_AlarmJoinedRecord(LONG lUserID, DWORD dwChan, DWORD dwAlarmSeq, DWORD dwRecordTime, DWORD dwRes);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetupAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostCloseAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_BypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_UnBypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostAssistantControl(LONG lUserID, DWORD dwType, DWORD dwNumber, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_SetAirCondition(LONG lUserID, LONG l485Index, NET_DVR_AIR_CONDITION_PARAM* lpAirConditionParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceTypeList(LONG lUserID, NET_DVR_DEVICE_TYPE_LIST *lpDeviceTypeList);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceProtoList(LONG lUserID, LONG lDeviceType, NET_DVR_DEVICE_PROTO_LIST *lpDeviceProtoList);
NET_DVR_API BOOL __stdcall NET_DVR_GetBatteryVoltage(LONG lUserID, float *pVoltage);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);
NET_DVR_API BOOL __stdcall NET_DVR_ControlGateway(LONG lUserID, LONG lGatewayIndex, DWORD dwStaic);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmHostOut(LONG lUserID, LONG lAlarmOutPort, LONG lAlarmOutStatic);
typedef void(CALLBACK *fAlarmHostSerialDataCallBack)
(LONG lSerialHandle, LONG lPort, LONG lDateType, char *pRecvDataBuffer, DWORD  dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_AlarmHostSerialStart(LONG lUserID, LONG lSerialType, fAlarmHostSerialDataCallBack cbSerialDataCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialSend(LONG lSerialHandle,LONG lPort,char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialStop(LONG  lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmOffMonitor(LONG lUserID, DWORD dwMonID, DWORD dwCamID);
NET_DVR_API BOOL __stdcall NET_DVR_GetGlobalNum(LONG lUserID, DWORD *dwCamNum, DWORD *dwMonNum); 

typedef void (CALLBACK *FLOWTESTCALLBACK)(LONG lFlowHandle, LPNET_DVR_FLOW_INFO pFlowInfo, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_StartNetworkFlowTest(LONG lUserID, NET_DVR_FLOW_TEST_PARAM* pFlowTest,  FLOWTESTCALLBACK fFlowTestCallback, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_StopNetworkFlowTest(LONG lHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindRecordLabel(LONG lUserID, LPNET_DVR_FIND_LABEL lpFindLabel);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLabel(LONG lFindHandle, LPNET_DVR_FINDLABEL_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_StopFindLabel(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_InsertRecordLabel(LONG lPlayHandle, NET_DVR_RECORD_LABEL* lpRecordLabel, NET_DVR_LABEL_IDENTIFY *lpLableIdentify);
NET_DVR_API BOOL __stdcall NET_DVR_DelRecordLabel(LONG lUserID, NET_DVR_DEL_LABEL_PARAM* lpDelLabelParam);
NET_DVR_API BOOL __stdcall NET_DVR_ModifyRecordLabel(LONG lUserID, NET_DVR_MOD_LABEL_PARAM * lpModLabelParam);
NET_DVR_API LONG __stdcall NET_DVR_FindPicture(LONG lUserID, NET_DVR_FIND_PICTURE_PARAM* pFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPicture(LONG lFindHandle,LPNET_DVR_FIND_PICTURE lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFindPicture(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture(LONG lUserID,char *sDVRFileName,const char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture_V30(LONG lUserID, char *sDVRFileName, char *sSavedFileBuf, DWORD dwBufLen, DWORD *lpdwRetLen);
NET_DVR_API LONG __stdcall NET_DVR_BackupPicture(LONG lUserID, NET_DVR_BACKUP_PICTURE_PARAM *lpBackupPicture);
NET_DVR_API LONG __stdcall NET_DVR_GetUpgradeStep(LONG lUpgradeHandle, LONG *pSubProgress);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetEncodeJoint(LONG lUserID, LONG lChannel, LPNET_DVR_ENCODE_JOINT_PARAM lpEncodeJoint);
NET_DVR_API BOOL  __stdcall NET_DVR_GetLocalIP(char strIP[16][16], DWORD *pValidNum, BOOL *pEnableBind);
NET_DVR_API BOOL  __stdcall NET_DVR_SetValidIP(DWORD dwIPIndex, BOOL bEnableBind);
NET_DVR_API BOOL __stdcall NET_DVR_GetVcaDevWorkState(LONG lUserID, LPNET_DVR_VCA_DEV_WORKSTATUS lpWorkState);
#ifdef __cplusplus
	NET_DVR_API BOOL  __stdcall NET_DVR_SetRecvTimeOut(DWORD nRecvTimeOut = 5000); //最小3000毫秒
#else
	NET_DVR_API BOOL  __stdcall NET_DVR_SetRecvTimeOut(DWORD nRecvTimeOut); //最小3000毫秒
#endif
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg_V40(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG_V40 lpDisplayCfg);			  
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg_V40(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG_V40 lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_ShutterCompensation(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CorrectDeadPixel(LONG lUserID, LONG lChannel, LPNET_DVR_CORRECT_DEADPIXEL_PARAM lpInParam);
NET_DVR_API BOOL __stdcall NET_DVR_CustomConfig(LONG lUserID, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_GetHistoricDataInfo(LONG lUserID, LONG lChannel, LPNET_DVR_HISTORICDATACFG lpHisData);
NET_DVR_API BOOL __stdcall NET_DVR_GetHistoricData(LONG lUserID, LONG lChannel, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ClearHistoricData(LONG lUserID, LONG lChannel);
NET_DVR_API LONG  __stdcall NET_DVR_InquestUploadFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom,  char *sFileName);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestDeleteFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetPIPStatus_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS lpStatus);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSetPIPStatus_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS lpStatus);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetSystemInfo(LONG lUserID, LPNET_DVR_INQUEST_SYSTEM_INFO lpSystemInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSetSystemInfo(LONG lUserID, LPNET_DVR_INQUEST_SYSTEM_INFO lpSystemInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSendMessage(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_MESSAGE lpInquestMessage);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStartCDW_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, BOOL bPause);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStopCDW_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, BOOL bCancelWrite);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetCDWState_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API LONG  __stdcall NET_DVR_InquestResumeEvent(LONG lUserID, LPNET_DVR_INQUEST_RESUME_EVENT lpResumeEvent);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetResumeProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStopResume(LONG lHandle);
NET_DVR_API LONG  __stdcall NET_DVR_InquestFindFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM pInquestRoom);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetDeviceVersion(LONG lUserID, LPNET_DVR_INQUEST_DEVICE_VERSION lpVersionInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_SetSDKSecretKey(LONG lUserID, char *sSecretKey);
NET_DVR_API BOOL __stdcall NET_DVR_LockFileByTime(LONG lUserID, LPNET_DVR_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByTime(LONG lUserID, LPNET_DVR_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddCamera(LONG lUserID, DWORD dwCameraNum, BYTE *pBuffer, DWORD dwBufLength);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelCamera(LONG lUserID, DWORD dwCameraId);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddMonitor(LONG lUserID, DWORD dwMonitorNum, BYTE *pBuffer, DWORD dwBufLength);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelMonitor(LONG lUserID, DWORD dwMonitorId);
NET_DVR_API BOOL __stdcall NET_DVR_DelMatrix(LONG lUserID, DWORD dwMatrixId);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelUser(LONG lUserID, DWORD dwUserNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelResourceInfo(LONG lUserID, DWORD dwResourceNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelUserGroup (LONG lUserID, DWORD dwUserGroupNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixTrunkCtrl(LONG lUserID, DWORD dwTrunkNum, BYTE byCtrlMode);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixTrunkStatusQuery(LONG lUserID, DWORD dwTrunkNum, BYTE *byTrunkStatus);

NET_DVR_API BOOL __stdcall NET_DVR_FindBackgroundPic(LONG lUserID, DWORD dwPicID, BYTE *pPicBuffer, DWORD *lpPicLen);
NET_DVR_API BOOL __stdcall NET_DVR_DetectImage(LONG lUserID, LPNET_VCA_FD_PROCIMG_CFG lpFDProcImg,LPNET_VCA_FD_PROCIMG_RESULT lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_GetPictureModel(LONG lUserID, LPNET_VCA_REGISTER_PIC lpInBuf, LPNET_VCA_PICMODEL_RESULT lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_AddBlackList(LONG lUserID,LONG lChannel,LPNET_VCA_BLACKLIST_PARA lpInter);
NET_DVR_API LONG __stdcall NET_DVR_FindBlackList(LONG lUserID, LPNET_VCA_BLACKLIST_COND lpBlackListCond);
NET_DVR_API LONG __stdcall NET_DVR_FindNextBlackList(LONG lFindHandle,LPNET_VCA_BLACKLIST_INFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindBlackListClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetBlackListPicture(LONG lUserID, DWORD dwRegisterID, LPNET_VCA_BLACKLIST_PIC lpOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateBlackList(LONG lUserID,LONG lChannel, LPNET_VCA_BLACKLIST_PARA lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_DelBlackList(LONG lUserID,LONG lChannel, DWORD dwRegisterID);
NET_DVR_API LONG __stdcall NET_DVR_FindSnapPicture(LONG lUserID, LPNET_VCA_FIND_PICTURECOND lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextSnapPic(LONG lFindHandle,LPNET_VCA_SUB_SNAPPIC_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindSnapPicClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_AdvanceFindSnapPicture(LONG lUserID, LPNET_VCA_FIND_PICTURECOND_ADVANCE lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindFaceMatchAlarm(LONG lUserID, LPNET_VCA_FIND_PICTURECOND lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFaceMatchAlarm(LONG lFindHandle, LPNET_VCA_FACESNAP_MATCH_ALARM_LOG lpFaceMatchAlarmLog);
NET_DVR_API BOOL __stdcall NET_DVR_FindFaceMatchAlarmClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetFaceMatchPic(LONG lUserID, LPNET_VCA_FACEMATCH_PICCOND lpMatchCond, LPNET_VCA_FACEMATCH_PICTURE lpMatchPic);
NET_DVR_API BOOL __stdcall NET_DVR_FastAddBlackList(LONG lUserID,LONG lChannel,LPNET_VCA_BLACKLIST_FASTREGISTER_PARA lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg_V41(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_MATRIX_VOUTCFG lpVoutCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg_V41(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_MATRIX_VOUTCFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus_V41(LONG lUserID, LPNET_DVR_DECODER_WORK_STATUS_V41 lpDecoderCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSceneCfg(LONG lUserID, DWORD dwSceneNum, LPNET_DVR_MATRIX_SCENECFG lpSceneCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSceneCfg(LONG lUserID, DWORD dwSceneNum, LPNET_DVR_MATRIX_SCENECFG lpSceneCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSceneControl(LONG lUserID, DWORD dwSceneNum, DWORD dwCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCurrentSceneMode(LONG lUserID, DWORD *dwSceneNum);
NET_DVR_API BOOL __stdcall NET_DVR_GetAllValidWinInfo(LONG lUserID, LPNET_DVR_WINLIST lpWinListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_ScreenWinCtrl(LONG lUserID, DWORD dwWinIndex, DWORD dwCommand, LPNET_DVR_SCREEN_WINCFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetScreenInputStatus(LONG lUserID, LPNET_DVR_SCREENINPUTSTATUS lpStatus);
NET_DVR_API LONG __stdcall NET_DVR_PicUpload(LONG lUserID, char const *sFileName, LPNET_DVR_PICTURECFG lpPictureCfg);
NET_DVR_API LONG __stdcall NET_DVR_GetPicUploadProgress(LONG lUploadHandle);
NET_DVR_API BOOL CALLBACK  NET_DVR_CloseUploadHandle(LONG lUploadHandle);		
NET_DVR_API BOOL __stdcall NET_DVR_PicControl(LONG lUserID, BYTE byUseType, BYTE byPicIndex, BYTE byCtrlCmd);
NET_DVR_API LONG __stdcall NET_DVR_GetPicUploadState(LONG lUploadHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ScreenCtrl(LONG lUserID, DWORD dwDeviceNum, LPNET_DVR_SCREEN_CONTROL lpStruScreenCtrl);
typedef void (CALLBACK *SCREENPICDATACB)(LONG nScreenPicHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_StartScreenPic(LONG nUserID, DWORD nInputNum, SCREENPICDATACB PicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_StopScreenPic(LONG nScreenPicHandle);
NET_DVR_API BOOL __stdcall NET_DVR_FocusOnePush(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_ResetLens(LONG lUserID, LONG lChannel);



typedef void(CALLBACK *fRemoteConfigCallback)(LONG nHandle, DWORD dwStatus, void* lpBuffer, DWORD dwBufLen, void* pUserData);
NET_DVR_API LONG CALLBACK NET_DVR_StartRemoteConfig(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwInBufferLen, fRemoteConfigCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API BOOL CALLBACK NET_DVR_StopRemoteConfig(LONG lHandle);


typedef void(CALLBACK *fLongCfgStateCallback)(LONG lHandle,  DWORD dwState, LPVOID pUserData);
NET_DVR_API BOOL CALLBACK NET_DVR_CloseLongCfgHandle(LONG lHandle);
NET_DVR_API LONG CALLBACK NET_DVR_RaidPullDiskStart(LONG lUserID, LONG lRaidID, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API LONG CALLBACK NET_DVR_ScanRaidStart(LONG lUserID, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API LONG CALLBACK NET_DVR_SetAccessCameraInfo(LONG lUserID, DWORD dwChannel, LPNET_DVR_ACCESS_CAMERA_INFO lpCameraInfo, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);


NET_DVR_API BOOL __stdcall NET_DVR_InquiryRecordTimeSpan(LONG lUserID, DWORD dwChannel,  NET_DVR_RECORD_TIME_SPAN_INQUIRY const *lpInquiry, LPNET_DVR_RECORD_TIME_SPAN lpResult);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateRecordIndex(LONG lUserID, DWORD dwChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetUpnpNatState(LONG lUserID, LPNET_DVR_UPNP_NAT_STATE lpState);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_EX lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_EX lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG_EX lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSubSystemSetupAlarmChan(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSubSystemCloseAlarmChan(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostClearAlarm(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostArrayBypass(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostArrayBypassResume (LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetReportMode(LONG lUserID, LONG lCenterNum, LPVOID lpInputBuf, DWORD dwInputBufLen);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostGetReportMode(LONG lUserID, LPVOID lpOutputBuf, DWORD dwOutputBufLen);
NET_DVR_API LONG __stdcall NET_DVR_StartUploadAudio(LONG lUserID, DWORD dwAudioNum, DWORD dwAudioType, char const *sAudioFileName);
NET_DVR_API LONG __stdcall NET_DVR_StartDownloadAudio(LONG lUserID, DWORD dwAudioNum, char const *sAudioFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopAudioOperate(LONG lAudioHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetAudioProgress(LONG lAudioHandle);
NET_DVR_API BOOL __stdcall NET_DVR_AudioCtrl(LONG lUserID, DWORD dwAudioNum, DWORD dwCtrlParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceConfig(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpOutBuffer, DWORD dwOutBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetDeviceConfig(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpInParamBuffer, DWORD dwInParamBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_LockStreamFileByTime(LONG lUserID, LPNET_DVR_STREAM_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockStreamFileByTime(LONG lUserID, LPNET_DVR_STREAM_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_StartManualRecord(LONG lUserID, LPNET_DVR_MANUAL_RECORD_PARA lpManualRecPara);
NET_DVR_API BOOL __stdcall NET_DVR_StopManualRecord(LONG lUserID, LPNET_DVR_STREAM_INFO pIDInfo);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByName(LONG lUserID, char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime_V40(LONG lUserID, NET_DVR_VOD_PARA const* pVodPara);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByTime_V40(LONG lUserID, HWND hWnd, LPNET_DVR_PLAYCOND pPlayCond);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime_V40(LONG lUserID, char *sSavedFileName, LPNET_DVR_PLAYCOND  pDownloadCond);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V40(LONG lUserID, LPNET_DVR_FILECOND_V40 pFindCond);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V41(LONG lUserID, LPNET_DVR_SETUPALARM_PARAM lpSetupParam);
NET_DVR_API BOOL __stdcall NET_DVR_AddDataBase(LONG lUserID, LPNET_VCA_DATABASE_PARAM lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_FindDataBase(LONG lUserID, LPNET_VCA_FIND_DATABASE_COND lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDataBase(LONG lFindHandle, LPNET_VCA_DATABASE_PARAM lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_FindDataBaseClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateDataBase(LONG lUserID, LPNET_VCA_DATABASE_PARAM lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteDataBase(LONG lUserID, LPNET_VCA_DELETE_DATABASE_COND lpCond);
typedef void(CALLBACK *fSearchDBCallBack)(LONG lHandle, DWORD dwType, DWORD dwResultNum, BYTE* pBuffer, DWORD dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_InquireSnapDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_INQUIRE_SNAPDB_COND lpInBuf, fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetInquireSnapDBProgress(LONG lInquireHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteSnapDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DELETE_SNAPRECORD_COND lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_SearchSnapDB(LONG lUserID, LPNET_VCA_SEARCH_SNAPDB_COND lpInBuf, fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetSearchSnapDBProgress(LONG lSearchHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_AddFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DATARECORD_INFO lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_FastAddFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_FAST_DATARECORD_INFO lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_InquireFaceDBRecord(LONG lUserID, LPNET_VCA_DATARECORD_COND lpInBuf,fSearchDBCallBack cbInquireDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetInquireFaceDBProgress(LONG lInquireHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DATARECORD_INFO lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DELETE_RECORD_COND lpInBuf);
typedef void(CALLBACK *fSearchDBCallBack)(LONG lSearchHandle, DWORD dwType, DWORD dwResultNum, BYTE* pBuffer, DWORD dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_SearchFaceDB(LONG lUserID, LPNET_VCA_SEARCH_FACEDB_COND lpInBuf,fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetSearchFaceDBProgress(LONG lSearchHandle, DWORD* pState);
NET_DVR_API LONG __stdcall NET_DVR_StopSearchDB(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_FindMatchPicture(LONG lUserID, LPNET_VCA_FIND_MATCHPIC_COND lpFindCond, LPNET_VCA_FIND_MATCHPIC_RESULT lpFindResult);
NET_DVR_API BOOL __stdcall NET_DVR_RemoteControl(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwInBufferSize);

NET_DVR_API BOOL __stdcall NET_DVR_PicViewRequest(LONG lUserID, NET_DVR_PIC_VIEW_PARAM *lpPicViewParam);
typedef LONG (CALLBACK *PicViewCallBack)(LPNET_DVR_PICVIEW_CALLBACKPARAM pStruPicViewParam, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPicViewResponseCallBack(PicViewCallBack fPicViewResponseCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPicViewDataCallBack(LONG lPicViewHandle, SCREENPICDATACB fPicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_GetDevList(LONG lUserID, LPNET_DVR_DEVLIST lpDevListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetScreenList(LONG lUserID, LPNET_DVR_SCREENLIST lpScreenListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetScreenRelation(LONG lUserID, NET_DVR_DISP_SCREEN const* lpScreenInfo);
NET_DVR_API BOOL __stdcall NET_DVR_TextShowCtrl(LONG lUserID, char const *sDeviceID, LPNET_DVR_TEXTSHOW lpText);
NET_DVR_API LONG __stdcall NET_DVR_StopUpgrade(LONG lUserID, LPNET_DVR_OPERATE_DEVICE lpStruOperate, LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_AddNetSignal(LONG lUserID, LPNET_DVR_NETSIGNAL_INFO lpStruSignal, void* lpOutBuf , DWORD dwBufLen);
NET_DVR_API LONG __stdcall NET_DVR_StartPicPreview(LONG lUserID, NET_DVR_START_PIC_VIEW_INFO const* lpStruStartPicView, SCREENPICDATACB PicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceStatus(LONG iUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpOutBuffer, DWORD dwOutBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlanList(LONG lUserID, DWORD dwDevNum, LPNET_DVR_PLAN_LIST lpPlanList);
NET_DVR_API BOOL __stdcall NET_DVR_GetInputSignalList(LONG lUserID, DWORD dwDevNum, LPNET_DVR_INPUT_SIGNAL_LIST lpInputSignalList);

NET_DVR_API LONG __stdcall NET_DVR_UploadFile(LONG lUserID, DWORD dwUploadType, LPVOID lpInBuffer, DWORD dwInBufferSize, char* sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_UploadClose(LONG lUploadHandle);

NET_DVR_API BOOL __stdcall NET_DVR_CommandDevice(LONG lUserID, DWORD dwOutCommand,  void const* lpInBuffer, DWORD dwInLen);

NET_DVR_API LONG __stdcall NET_DVR_StartUploadFile(LONG lUserID, LPNET_DVR_UPLOAD_PARAM  lpStruUploadParam);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadFileProgress(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadFileState(LONG lFileHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopUploadFile (LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_StartDownloadFile(LONG lUserID, LPNET_DVR_DOWNLOAD_PARAM lpStruDownloadParam);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadFileProgress(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadFileState(LONG lFileHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopDownloadFile (LONG lFileHandle);


NET_DVR_API BOOL __stdcall NET_DVR_GetMobileDevStatus(LONG lUserID, DWORD dwStatusType, LPNET_DVR_MB_MOBILEDEV_STATUS lpstruMobileDevStatus);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceDataCallBack(LONG lVoiceComHandle, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);

NET_DVR_API LONG __stdcall NET_DVR_OpticalUpgrade(LONG lUserID, char const *sFileName, LPNET_DVR_OPTICAL_INFO lpOpticalInfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetAudioChan(LONG lUserID, LPNET_DVR_AUDIO_SURCHAN_CFG lpStruAudioSurChanCfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetAudioChanStatus(LONG lUserID, DWORD dwDispChan, LPNET_DVR_AUDIO_SURCHAN_STATUS lpAudioSurChanStatus);
NET_DVR_API BOOL __stdcall NET_DVR_SetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);
#endif
