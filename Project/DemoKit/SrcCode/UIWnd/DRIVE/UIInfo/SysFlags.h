#ifndef __SYSFLAGS_H
#define __SYSFLAGS_H

#define PS_CHECK_DATA   0xa5
#define SYS_DATA_SIZE   0x50

enum _SYS_FLAGS {
    // << system setting flags region (should be stored in PStore and read back while system initial) >>
    FL_NULL,

    // Photo
    FL_PHOTO_CAPTURE,           // Photo capture
    FL_PHOTO_SIZE,              // Photo size
    FL_QUALITY,                 // Photo quality
    FL_COLOR_EFFECT,            // Photo color
    FL_SCENE,                   // Scene mode
    FL_EV,                      // Exposure value
    FL_ISO,                     // ISO value
    FL_WB,                      // White balance mode
    FL_METERING,                // Exposure metering
    FL_SHARPNESS,               // Image sharpness
    FL_SATURATION,              // Image saturation
    FL_FACE,                    // Face detection
    FL_SMILE,                   // Smile detection
    FL_FD,                     // FD/SD detection
    FL_ANTISHAKE,               // Anti-shaking on/off
    FL_EXIT,                    // EXIT
    FL_QUICK_REVIEW,            // Quick review time
    FL_DATE_STAMP,              // Date-time stamp OFF/DATE/DATE TIME
    FL_SELFTIMER,               // Self-timer time
    FL_FLASH_MODE,              // Flash light mode
    FL_PHOTO_VIVILINK,          // Photo mode Vivilink setting
    FL_CONTINUE_SHOT,           // Continue shot on/off
    FL_QUICKVIEW,

    // Movie
    FL_MOVIE_SIZE,              // Movie size
    FL_MOVIE_EV,                // Movie size
    FL_MOVIE_FRAMERATE,         // Movie frame rate  15fps, 30fps
    FL_MOVIE_QUALITY,           // Movie quality
    FL_MOVIE_COLOR,             // Movie color
    FL_MOVIE_SELFTIMER,         // Movie mode self-timer time
    FL_MOVIE_VIVILINK,          // Movie mode Vivilink setting
    FL_MOVIE_LOOP_REC,          // Movie loop record
    FL_MOVIE_MOTION_DET,        // Movie motion detect
    FL_MOVIE_AUDIO,             // Movie audio enable
    FL_MOVIE_DATEIMPRINT,       // Movie dateimprint
    FL_GSENSOR,          // 
    FL_MOVIE_TIMESHRINK,
    FL_MOVIE_PARKING,
    // Playback
    FL_DELETE_PHOTO,            // Delete Still
    FL_DELETE_MOVIE,            // Delete Video
    FL_PROTECT,                 // File protect operation (pseudo flag)
    FL_SLIDE_SHOW,              // Slide show time
    FL_PLAY_STILL_VIVILINK,     // Playback mode Vivilink value (depends on file content)
    FL_PLAY_VIDEO_VIVILINK,     // Playback mode Vivilink value (depends on file content)
    FL_CROP,
    FL_ROTATE,
    FL_PHOTO_PROTECT,
    FL_MOVIE_PROTECT,
    FL_PICTBRIDGE,

    // System
    FL_AUTO_POWER_OFF,          // Auto power off time
    FL_DATE_TIME,
    FL_BEEP,                    // Beep sound on/off
    FL_LED_SETTING,    
    FL_SILENT,                  // definition is opposite with FL_BEEP,
    FL_LANGUAGE,                // Language
    FL_FREQUENCY,               // Frequency (50Hz/60Hz)
    FL_LCD_BACKLIGHT,           // Lcd backlight
    FL_TV_MODE,                 // TV mode (NTSC/PAL)
    FL_FORMAT,                  // Format storage
    FL_DEFAULT,                 // Reset Default
    FL_DATE_FORMAT,             // Date format (DD/MM/YY, MM/DD/YY, YY/MM/DD)
    FL_TIME_FORMAT,             // Time format (AM/PM)
    FL_HOUR_FORMAT,             // Hour format (12 Hours/24 Hours)
    FL_DATE_TIME_SETUP,
    FL_OPENING_LOGO,            // Opening logo display (on/off)
    FL_SENSOR_ROTATE,           // Sensor Roate on/off
    FL_PLATENUMBER,
    FL_SETUP,                   // Setup menu

    //Init Setup flag after reset default
    FL_INIT_SETUP,

    FL_DCF_DIR_ID,              // DCF directory ID
    FL_DCF_FILE_ID,             // DCF file ID
    FL_LCD_DISPLAY,             // LCD display status (OSD normal, full, off, LCD power down)
    FL_MACRO,                   // Macro mode on/off
    FL_LCD_BRIGHTNESS,          // LCD brightness level      
    FL_LCD_AUTOOFF,
    FL_POWEROFF_DELAY,
    FL_USB_MODE                 // USB mode (MSDC, PCC, PictBridge, ...)

    /*
    // << system control flags region (should not be stored in PStore; reset while system initial) >>
    FL_MEDIA = SYS_DATA_SIZE,   // Int, Ext
    */
};

//-----------------------------------------------------------------------------
// Scene Mode
//-----------------------------------------------------------------------------
enum _SCENE_MODE
{
    SCENE_AUTO,
    SCENE_SCENERY,
    SCENE_PORTRAIT,
    SCENE_NIGHTSCENERY,
    SCENE_NIGHTPORTRAIT,
    SCENE_HIGHSENSITIVITY,
    SCENE_BEACH,
    SCENE_ID_MAX,
    SCENE_SPORT,
    SCENE_PARTY
};

//-----------------------------------------------------------------------------
// Photo Size
//-----------------------------------------------------------------------------
#if (0)//(UPDATE_CFG == UPDATE_CFG_YES)
enum _PHOTO_SIZE
{
    PHOTO_SIZE_15M,
    PHOTO_SIZE_14M,
    PHOTO_SIZE_12M,
    PHOTO_SIZE_10M,
    PHOTO_SIZE_8M,
    PHOTO_SIZE_7M,
    PHOTO_SIZE_7MHD,
    PHOTO_SIZE_5M,
    PHOTO_SIZE_4M,
    PHOTO_SIZE_3M,
    PHOTO_SIZE_2M,
    PHOTO_SIZE_2MHD,
    PHOTO_SIZE_VGA,
    PHOTO_SIZE_ID_MAX
};
#else
enum _PHOTO_SIZE
{
    PHOTO_SIZE_12M,
    PHOTO_SIZE_10M,
    PHOTO_SIZE_8M,
    PHOTO_SIZE_5M,
    PHOTO_SIZE_3M,
    PHOTO_SIZE_2MHD,
    PHOTO_SIZE_VGA,
    PHOTO_SIZE_1M,
    PHOTO_SIZE_ID_MAX,

    PHOTO_SIZE_15M,
    PHOTO_SIZE_14M,
//    PHOTO_SIZE_10M,
    PHOTO_SIZE_7M,
    PHOTO_SIZE_7MHD,
    PHOTO_SIZE_4M,
    PHOTO_SIZE_2M,
//    PHOTO_SIZE_2MHD,
//    PHOTO_SIZE_VGA
};
#endif

//-----------------------------------------------------------------------------
// Photo Quality
//-----------------------------------------------------------------------------
enum _QUALITY
{
    QUALITY_FINE,
    QUALITY_NORMAL,
    QUALITY_ECONOMY,
    QUALITY_ID_MAX
};

//-----------------------------------------------------------------------------
// Photo Selftimer Time
//-----------------------------------------------------------------------------
enum _SELFTIMER
{
    SELFTIMER_SINGLE,
    SELFTIMER_2SEC,
    SELFTIMER_5SEC,
    SELFTIMER_10SEC,
    SELFTIMER_ID_MAX
};

//-----------------------------------------------------------------------------
// AntiShaking State
//-----------------------------------------------------------------------------
enum _ANTISHAKING
{
    ANTISHAKE_OFF,
    ANTISHAKE_ON,
    ANTISHAKE_ID_MAX
};

//-----------------------------------------------------------------------------
// Face Detection State
//-----------------------------------------------------------------------------
enum _FACE_DETECTION
{
    FD_OFF,
    FD_ON,
    FD_SMILE,
    FD_ID_MAX
};

//-----------------------------------------------------------------------------
// White Balance Mode
//-----------------------------------------------------------------------------
enum _WB_MODE
{
    WB_AUTO,
    WB_DAYLIGHT,
    WB_CLOUDY,
    WB_TUNGSTEN,
    WB_FLUORESCENT,
    WB_ID_MAX
};

//-----------------------------------------------------------------------------
// Photo Color
//-----------------------------------------------------------------------------
enum _PHOTO_COLOR
{
    COLOR_EFFECT_STANDARD,
    COLOR_EFFECT_MONOCHROME,
    COLOR_EFFECT_SEPIA,
    COLOR_EFFECT_ID_MAX,
    COLOR_EFFECT_VIVID
};

//-----------------------------------------------------------------------------
// Continue shot State
//-----------------------------------------------------------------------------
enum
{
    CONTINUE_SHOT_OFF,
    CONTINUE_SHOT_ON,
    CONTINUE_SHOT_SETTING_MAX
};

//-----------------------------------------------------------------------------
// Sharpness Level
//-----------------------------------------------------------------------------
enum _SHARPNESS
{
    SHARPNESS_SHARP,
    SHARPNESS_NORMAL,
    SHARPNESS_SOFT,
    SHARPNESS_ID_MAX
};

//-----------------------------------------------------------------------------
// Exposure Value
//-----------------------------------------------------------------------------
enum _EXPOSURE
{
    EV_P20,
    EV_P16,
    EV_P13,
    EV_P10,
    EV_P06,
    EV_P03,
    EV_00,
    EV_N03,
    EV_N06,
    EV_N10,
    EV_N13,
    EV_N16,
    EV_N20,
    EV_ID_MAX,

    EV_P30,
    EV_P15,
    EV_N15,
    EV_N30
};

//-----------------------------------------------------------------------------
// ISO Value
//-----------------------------------------------------------------------------
enum _ISO
{
    ISO_AUTO,
    ISO_100,
    ISO_200,
    ISO_400,
    ISO_ID_MAX,
    ISO_800,
    ISO_1600,
    ISO_3200
} ;

//-----------------------------------------------------------------------------
// Exposure Metering Method
//-----------------------------------------------------------------------------
enum _METERING
{
    METERING_CENTER,
    METERING_MULTI,
    METERING_SPOT,
    METERING_ID_MAX
};

//-----------------------------------------------------------------------------
// Saturation Level
//-----------------------------------------------------------------------------
enum _SATURATION
{
    SATURATION_HIGH,
    SATURATION_NORMAL,
    SATURATION_LOW,
    SATURATION_ID_MAX
};

//-----------------------------------------------------------------------------
// Quick Review Time
//-----------------------------------------------------------------------------
enum _QUICK_REVIEW
{
    QUICK_REVIEW_0SEC,
    QUICK_REVIEW_2SEC,
    QUICK_REVIEW_5SEC,
    QUICK_REVIEW_ID_MAX
};

//-----------------------------------------------------------------------------
// Date Imprint Mode
//-----------------------------------------------------------------------------
enum _DATE_STAMP
{
    DATE_STAMP_OFF,
    DATE_STAMP_DATE,
    DATE_STAMP_DATETIME,
    DATE_STAMP_ID_MAX
};

//-----------------------------------------------------------------------------
// Flash Light Mode
//-----------------------------------------------------------------------------
enum _FLASH_MODE
{
    FLASH_AUTO,
    FLASH_ON,
    FLASH_RED_EYE,
    FLASH_OFF,
    FLASH_ID_MAX
};

//-----------------------------------------------------------------------------
// Movie Size
//-----------------------------------------------------------------------------
enum _MOVIE_SIZE
{
    MOVIE_SIZE_1080FHD,
    MOVIE_SIZE_720P,
    MOVIE_SIZE_WVGA,
    MOVIE_SIZE_VGA,
    MOVIE_SIZE_ID_MAX,
    MOVIE_SIZE_1080P,
    MOVIE_SIZE_QVGA
};

//-----------------------------------------------------------------------------
// Movie Gsensor
//-----------------------------------------------------------------------------
enum _GSENSOR{
	GSENSOR_OFF,
	GSENSOR_LOW,
	GSENSOR_NORMAL,
	GSENSOR_HIGH,
	GSENSOR_ID_MAX
};

enum _MOVIE_TIMESHRINK
{
	MOVIE_TIMESHRINK_OFF,
	MOVIE_TIMESHRINK_ON,
	MOVIE_TIMESHRINK_MAX
};

enum _MOVIE_PARKING
{
    MOVIE_PARKING_OFF,
    MOVIE_PARKING_ON,
    MOVIE_PARKING_MAX
};
//-----------------------------------------------------------------------------
// Movie frame rate
//-----------------------------------------------------------------------------
enum _MOVIE_FRAMERATE
{
    MOVIE_FRAMERATE_15FPS,
    MOVIE_FRAMERATE_30FPS,
    MOVIE_FRAMERATE_ID_MAX
};

//-----------------------------------------------------------------------------
// Movie cyclic record
//-----------------------------------------------------------------------------
enum _MOVIE_CYCLICREC
{
    MOVIE_CYCLICREC_OFF,
    MOVIE_CYCLICREC_1MIN,	
    MOVIE_CYCLICREC_3MIN,
    MOVIE_CYCLICREC_5MIN,
    MOVIE_CYCLICREC_ID_MAX,    
    MOVIE_CYCLICREC_2MIN,
    MOVIE_CYCLICREC_10MIN,
    MOVIE_CYCLICREC_15MIN  
};

//-----------------------------------------------------------------------------
// Movie Audio enable State
//-----------------------------------------------------------------------------
enum
{
    MOVIE_AUDIOENABLE_OFF = 0,
    MOVIE_AUDIOENABLE_ON,
    MOVIE_AUDIOENABLE_SETTING_MAX
};

//-----------------------------------------------------------------------------
// Movie Motion Detect State
//-----------------------------------------------------------------------------
enum
{
    MOVIE_MOTIONDET_OFF = 0,
    MOVIE_MOTIONDET_ON,
    MOVIE_MOTIONDET_SETTING_MAX
};

//-----------------------------------------------------------------------------
// Movie DateImprint State
//-----------------------------------------------------------------------------
enum
{
    MOVIE_DateImprint_OFF = 0,
    MOVIE_DateImprint_ON,
    MOVIE_DateImprint_SETTING_MAX
};

//-----------------------------------------------------------------------------
// Movie Quality
//-----------------------------------------------------------------------------
enum _MOVIE_QUALITY
{
    MOVIE_QUALITY_FINE,
    MOVIE_QUALITY_STANDARD,
    MOVIE_QUALITY_ECONOMY,
    MOVIE_QUALITY_ID_MAX
};

//-----------------------------------------------------------------------------
// Movie Color
//-----------------------------------------------------------------------------
enum _MOVIE_COLOR
{
    MOVIE_COLOR_NORMAL,
    //MOVIE_COLOR_VIVID,
    MOVIE_COLOR_MONO,
    MOVIE_COLOR_SEPIA,
    MOVIE_COLOR_ID_MAX
};

//-----------------------------------------------------------------------------
// Movie Selftimer
//-----------------------------------------------------------------------------
enum _MOVIE_SELFTIMER
{
    MOVIE_SELFTIMER_OFF,
    MOVIE_SELFTIMER_ON_2S,
    MOVIE_SELFTIMER_ON_10S,
    MOVIE_SELFTIMER_ON_10_2S,
    MOVIE_SELFTIMER_ID_MAX
};

//-----------------------------------------------------------------------------
// Delete
//-----------------------------------------------------------------------------
enum _DELETE
{
   DELETE_THIS,
   DELETE_ALL,
   DELETE_CANCEL,
   DELETE_ID_MAX
};

enum _DELETE_PHOTO
{
   DELETE_PHOTO_THIS   = DELETE_THIS,
   DELETE_PHOTO_ALL    = DELETE_ALL ,
   DELETE_PHOTO_CANCEL = DELETE_CANCEL,
   DELETE_PHOTO_ID_MAX = DELETE_ID_MAX
};

enum _DELETE_MOVIE
{
   DELETE_MOVIE_THIS   = DELETE_THIS,
   DELETE_MOVIE_ALL    = DELETE_ALL,
   DELETE_MOVIE_CANCEL = DELETE_CANCEL,
   DELETE_MOVIE_ID_MAX = DELETE_ID_MAX
};

//-----------------------------------------------------------------------------
// Vivilink
//-----------------------------------------------------------------------------
// Photo mode Vivilink items
enum _PHOTO_VIVILINK
{
    PHOTO_VIVILINK_FACEBOOK,
    PHOTO_VIVILINK_TWITGOO,
    PHOTO_VIVILINK_TWITPIC,
    PHOTO_VIVILINK_PHOTOBUCKET,
    PHOTO_VIVILINK_FLICKR,
    PHOTO_VIVILINK_MYSPACE,
    PHOTO_VIVILINK_PICASA_ALBUMS,
    PHOTO_VIVILINK_NONE,
    PHOTO_VIVILINK_ID_MAX
};

// Movie mode Vivilink items
enum _MOVIE_VIVILINK
{
    MOVIE_VIVILINK_YOUTUBE,
    MOVIE_VIVILINK_PHOTOBUCKET,
    MOVIE_VIVILINK_FLICKR,
    MOVIE_VIVILINK_NONE,
    MOVIE_VIVILINK_ID_MAX
};

// Playback mode Vivilink items for still
enum _PLAY_STILL_VIVILINK
{
    PLAY_STILL_VIVILINK_FACEBOOK,
    PLAY_STILL_VIVILINK_TWITGOO,
    PLAY_STILL_VIVILINK_TWITPIC,
    PLAY_STILL_VIVILINK_PHOTOBUCKET,
    PLAY_STILL_VIVILINK_FLICKR,
    PLAY_STILL_VIVILINK_MYSPACE,
    PLAY_STILL_VIVILINK_PICASA_ALBUMS,
    PLAY_STILL_VIVILINK_NONE,
    PLAY_STILL_VIVILINK_ID_MAX
};

// Playback mode Vivilink items for video
enum _PLAY_VIDEO_VIVILINK
{
    PLAY_VIDEO_VIVILINK_YOUTUBE,
    PLAY_VIDEO_VIVILINK_PHOTOBUCKET,
    PLAY_VIDEO_VIVILINK_FLICKR,
    PLAY_VIDEO_VIVILINK_NONE,
    PLAY_VIDEO_VIVILINK_ID_MAX
};

// real Vivilink value
enum _VIVILINK
{
    VIVILINK_NONE,
    VIVILINK_FACEBOOK,
    VIVILINK_TWITGOO,
    VIVILINK_TWITPIC,
    VIVILINK_PHOTOBUCKET,
    VIVILINK_FLICKR,
    VIVILINK_MYSPACE,
    VIVILINK_PICASA_ALBUMS,
    VIVILINK_YOUTUBE,
    VIVILINK_ID_MAX
};

// Vivilink setting operation
enum _VIVILINK_SETTING
{
    VIVILINK_SET_ONE,
    VIVILINK_SET_ALL,
    VIVILINK_SET_ID_MAX
};

//-----------------------------------------------------------------------------
// Rotate
//-----------------------------------------------------------------------------
enum _ROTATE
{
    ROTATE_90C,
    ROTATE_180C,
    ROTATE_270C,
    ROTATE_CANCEL,
    ROTATE_ID_MAX
};

//-----------------------------------------------------------------------------
// CROP
//-----------------------------------------------------------------------------
enum _CROP
{
    CROP_ENTER,
    CROP_CANCEL,
    CROP_ID_MAX
};


//-----------------------------------------------------------------------------
// File Protect
//-----------------------------------------------------------------------------
enum _FILE_PROTECT
{
    PROTECT_ONE = 0,
    UNPROTECT_ONE,
    PROTECT_ALL,
    UNPROTECT_ALL,
    FILE_PROTECT_ID_MAX
};

enum PHOTO_FILE_PROTECT
{
    PHOTO_LOCK_THIS   = PROTECT_ONE,
    PHOTO_UNLOCK_THIS = UNPROTECT_ONE,
    PHOTO_LOCK_ALL    = PROTECT_ALL,
    PHOTO_UNLOCK_ALL  = UNPROTECT_ALL,
    PHOTO_PROTECT_ID_MAX = FILE_PROTECT_ID_MAX
};

enum MOVIE_FILE_PROTECT
{
    MOVIE_LOCK_THIS   = PROTECT_ONE,
    MOVIE_UNLOCK_THIS = UNPROTECT_ONE,
    MOVIE_LOCK_ALL    = PROTECT_ALL,
    MOVIE_UNLOCK_ALL  = UNPROTECT_ALL,
    MOVIE_PROTECT_ID_MAX = FILE_PROTECT_ID_MAX
};

//-----------------------------------------------------------------------------
// Print
//-----------------------------------------------------------------------------
enum _PRINT
{
    PRINT_THIS_PHOTO,
    PRINT_CANCEL,
    PRINT_ID_MAX
};

//-----------------------------------------------------------------------------
// Slide Show Time
//-----------------------------------------------------------------------------
enum _SLIDE_SHOW
{
    SLIDE_SHOW_2SEC,
    SLIDE_SHOW_5SEC,
    SLIDE_SHOW_8SEC,
    SLIDE_SHOW_ID_MAX
};

//-----------------------------------------------------------------------------
// Language Setting
//-----------------------------------------------------------------------------
#if (0)//(UPDATE_CFG == UPDATE_CFG_YES)
enum _LANGUAGE
{
    LANG_EN,
    LANG_TC,
    LANG_SC,
    LANG_JP,
    LANG_RU,
    LANG_DE,
    LANG_ES,
    LANG_FR,
    LANG_IT,
    LANG_PO,
    LANG_PB,
    LANG_DU,
    LANG_TU,
    LANG_YI,
    LANG_PL,
    LANG_DE_JAY,
    LANG_ID_MAX
};
#else
enum _LANGUAGE
{
    LANG_EN,
    LANG_FR,
    LANG_ES,
    LANG_PO,
    LANG_DE,
    LANG_IT,
    LANG_SC,
    LANG_TC,
    LANG_RU,
    LANG_JP,
    LANG_KR,
    LANG_ID_MAX,

    LANG_DU,
    LANG_TU,
    LANG_PB,
    LANG_YI,
    LANG_PL,
    LANG_DE_JAY
};
#endif

//-----------------------------------------------------------------------------
// Date Time Setting
//-----------------------------------------------------------------------------
enum _DATE_TIME
{
    DATE_TIME_ON ,
    DATE_TIME_OFF,
    DATE_TIME_SETUP,
    DATE_TIME_ID_MAX
};

//-----------------------------------------------------------------------------
// Date Format
//-----------------------------------------------------------------------------
enum _DATE_FORMAT
{
    DATE_FORMAT_YMD,
    DATE_FORMAT_DMY,
    DATE_FORMAT_MDY,
    DATE_FORMAT_ID_MAX
};

//-----------------------------------------------------------------------------
// Time Format
//-----------------------------------------------------------------------------
enum _TIME_FORMAT
{
    TIME_FORMAT_AM,
    TIME_FORMAT_PM,
    TIME_FORMAT_ID_MAX
};

//-----------------------------------------------------------------------------
// Hour Format
//-----------------------------------------------------------------------------
enum _HOUR_FORMAT
{
    HOUR_FORMAT_12H,
    HOUR_FORMAT_24H,
    HOUR_FORMAT_NONE,
    HOUR_FORMAT_ID_MAX
};

//-----------------------------------------------------------------------------
// Date Time Setup
//-----------------------------------------------------------------------------
enum _DATE_TIME_SETUP
{
    DATE_TIME_SETUP_YES,
    DATE_TIME_SETUP_NO,
    DATE_TIME_SETUP_ID_MAX
};

//-----------------------------------------------------------------------------
// Beep Sound
//-----------------------------------------------------------------------------
enum _BEEP
{
    BEEP_OFF,
    BEEP_ON,
    BEEP_ID_MAX
};

//-----------------------------------------------------------------------------
// Silent Mode
//-----------------------------------------------------------------------------
enum _SILENT
{
    SILENT_ON,
    SILENT_OFF,
    SILENT_ID_MAX
};

//-----------------------------------------------------------------------------
// Auto Power Off Time
//-----------------------------------------------------------------------------
enum _AUTO_POWER_OFF
{
    AUTO_POWER_OFF_DISABLE,
    AUTO_POWER_OFF_3MIN,
    AUTO_POWER_OFF_5MIN,
    AUTO_POWER_OFF_ID_MAX
};

//-----------------------------------------------------------------------------
// LCD Power Off Time
//-----------------------------------------------------------------------------
enum _LCD_AUTO_POWER_OFF
{
    LCD_AUTO_POWER_OFF_DISABLE,
    LCD_AUTO_POWER_OFF_1MIN,
    LCD_AUTO_POWER_OFF_2MIN, 
    LCD_AUTO_POWER_OFF_ID_MAX    
};

//-----------------------------------------------------------------------------
// Power Off Delay Time
//-----------------------------------------------------------------------------
enum _POWER_OFF_DELAY
{
    POWER_OFF_DELAY_DISABLE,
    POWER_OFF_DELAY_1MIN,
    POWER_OFF_DELAY_2MIN,
    POWER_OFF_DELAY_3MIN,
    POWER_OFF_DELAY_5MIN,
    POWER_OFF_DELAY_10MIN,
    POWER_OFF_DELAY_15MIN,    
    POWER_OFF_DELAY_ID_MAX    
};
//-----------------------------------------------------------------------------
// Power Frequency
//-----------------------------------------------------------------------------
enum _FREQUENCY
{
    FREQUENCY_50HZ,
    FREQUENCY_60HZ,
    FREQUENCY_ID_MAX
};

//-----------------------------------------------------------------------------
// LCD Backlight
//-----------------------------------------------------------------------------
enum _LCD_BACKLIGHT
{
    LCD_BACKLIGHT_OFF,
    LCD_BACKLIGHT_3MIN,
    LCD_BACKLIGHT_5MIN,
    LCD_BACKLIGHT_10MIN,
    LCD_BACKLIGHT_ID_MAX
};


// Sensor rotate Mode
//-----------------------------------------------------------------------------
enum _SENSOR_ROTATE_MODE
{
    SEN_ROTATE_OFF,
    SEN_ROTATE_ON,
    SEN_ROTATE_MAX
};

enum _PLATENUMBER
{
    PLATENUMBER_OFF,
    PLATENUMBER_ON,
    PLATENUMBER_ID_MAX
};
//-----------------------------------------------------------------------------
// TV Mode
//-----------------------------------------------------------------------------
enum _TV_MODE
{
    TV_MODE_PAL,
    TV_MODE_NTSC,
    TV_MODE_ID_MAX
};

//-----------------------------------------------------------------------------
// Format
//-----------------------------------------------------------------------------
enum _FORMAT
{
    FORMAT_YES,
    FORMAT_CANCEL,
    FORMAT_ID_MAX
};

//-----------------------------------------------------------------------------
// Default
//-----------------------------------------------------------------------------
enum _DEFAULT
{
    DEFAULT_FACTORY,
    DEFAULT_ID_MAX
};

//-----------------------------------------------------------------------------
// Opening Logo Display
//-----------------------------------------------------------------------------
enum _OPENING_LOGO
{
    OPENING_LOGO_OFF,
    OPENING_LOGO_ON,
    OPENING_LOGO_ID_MAX
};

//-----------------------------------------------------------------------------
// LCD Display Status
//-----------------------------------------------------------------------------
enum _LCD_DISPLAY
{
    DISPLAY_NORMAL,
    DISPLAY_ALL,
    DISPLAY_OFF,
    DISPLAY_ID_MAX,
    DISPLAY_OFFPANEL
};

//-----------------------------------------------------------------------------
// Macro State
//-----------------------------------------------------------------------------
enum _MACRO
{
    MACRO_OFF,
    MACRO_ON,
    MACRO_ID_MAX
};

//-----------------------------------------------------------------------------
// LCD Brightness Adjust Level
//-----------------------------------------------------------------------------
enum _LCD_BRIGHTNESS_LEVEL
{
    LCDBRT_LVL_01 = 1,
    LCDBRT_LVL_02,
    LCDBRT_LVL_03,
    LCDBRT_LVL_04,
    LCDBRT_LVL_05,
    LCDBRT_LVL_06,
    LCDBRT_LVL_07,
    LCDBRT_LVL_08,
    LCDBRT_LVL_09,
    LCDBRT_LVL_ID_MAX
};

//-----------------------------------------------------------------------------
// USB Mode
//-----------------------------------------------------------------------------
enum _USB_MODE
{
    USB_MODE_MSDC = 0,
    USB_MODE_PCC,
    USB_MODE_RECORD,
    USB_MODE_ID_MAX,
    USB_MODE_CHARGE // for future use
};


//-----------------------------------------------------------------------------
// INIT Setup Mode
//-----------------------------------------------------------------------------
enum _INIT_SETUP
{
    INIT_SETUP_YES,
    INIT_SETUP_NO,
    INIT_SETUP_ID_MAX
};

//-----------------------------------------------------------------------------
// Default
//-----------------------------------------------------------------------------
enum _EXIT
{
    EXIT_YES,
    EXIT_ID_MAX
};

enum _SETUP_TURNKEY
{
    SETUP_DATE_TIME,
    SETUP_AUTO_POWER_OFF,
    SETUP_BEEP,
    SETUP_LANGUAGE,
    SETUP_FREQUENCY,
    SETUP_TV_MODE,
    SETUP_FORMAT,
    SETUP_DEFAULT,
    SETUP_ID_MAX
};

enum _DELAY_POWER_OFF {
	DELAY_POWER_OFF_DISABLE,
	DELAY_POWER_OFF_1MIN,
	DELAY_POWER_OFF_2MIN,
	DELAY_POWER_OFF_3MIN,
	DELAY_POWER_OFF_5MIN,
	DELAY_POWER_OFF_ID_MAX,
	DELAY_POWER_OFF_10MIN,
	DELAY_POWER_OFF_15MIN
};


#endif // __SYSFLAGS_H

