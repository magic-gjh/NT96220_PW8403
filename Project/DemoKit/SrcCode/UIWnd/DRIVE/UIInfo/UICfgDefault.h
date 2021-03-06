#ifndef UI_CFG_DEFAULT_H
#define UI_CFG_DEFAULT_H

#include "UIFlow.h"


#if (UI_STYLE == UI_STYLE_DRIVE)
// Photo
#define DEFAULT_PHOTO_CAPTURE           SELFTIMER_SINGLE
#define DEFAULT_PHOTO_SIZE              PHOTO_SIZE_5M
#define DEFAULT_PHOTO_QUALITY           QUALITY_FINE
#define DEFAULT_PHOTO_COLOR             COLOR_EFFECT_STANDARD
#define DEFAULT_SCENE                   SCENE_AUTO
#define DEFAULT_EV                      EV_00
#define DEFAULT_ISO                     ISO_AUTO
#define DEFAULT_WB                      WB_AUTO
#define DEFAULT_METERING                METERING_MULTI
#define DEFAULT_SHARPNESS               SHARPNESS_NORMAL
#define DEFAULT_SATURATION              SATURATION_NORMAL
#define DEFAULT_FD                      FD_ON
#define DEFAULT_ANTISHAKING             ANTISHAKE_OFF
#define DEFAULT_QUICK_REVIEW            QUICK_REVIEW_0SEC
#define DEFAULT_DATE_STAMP              DATE_STAMP_DATETIME
#define DEFAULT_SELFTIMER               SELFTIMER_SINGLE
#define DEFAULT_FLASH_MODE              FLASH_OFF
#define DEFAULT_PHOTO_VIVILINK          VIVILINK_NONE
#define DEFAULT_CONTINUE_SHOT           CONTINUE_SHOT_OFF

// Movie
#define DEFAULT_MOVIE_SIZE              MOVIE_SIZE_1080FHD
#define DEFAULT_MOVIE_QUALITY           MOVIE_QUALITY_FINE
#define DEFAULT_MOVIE_COLOR             MOVIE_COLOR_NORMAL
#define DEFAULT_MOVIE_SELFTIMER         MOVIE_SELFTIMER_OFF
#define DEFAULT_MOVIE_EV                EV_00
#define DEFAULT_MOVIE_VIVILINK          VIVILINK_NONE

#define DEFAULT_MOVIE_CYCLICREC         MOVIE_CYCLICREC_1MIN//MOVIE_CYCLICREC_3MIN
#define DEFAULT_MOVIE_MOTION_DET        MOVIE_MOTIONDET_OFF
#define DEFAULT_MOVIE_AUDIO             MOVIE_AUDIOENABLE_ON
#define DEFAULT_MOVIE_DATEIMPRINT       MOVIE_DateImprint_ON
#define DEFAULT_MOVIE_PARKING               MOVIE_PARKING_OFF
#define DEFAULT_MOVIE_TIMESHRINK        MOVIE_TIMESHRINK_OFF
#define DEFAULT_MOVIE_GSENSOR             GSENSOR_NORMAL
#define DEFAULT_MOVIE_CARNUMBER             PLATENUMBER_ON
// Playback
#define DEFAULT_PROTECT                 PROTECT_ONE
#define DEFAULT_SLIDE_SHOW              SLIDE_SHOW_2SEC

// System
#if (_PROJECT_TUOBU_ == ENABLE)
#define DEFAULT_AUTO_POWER_OFF          AUTO_POWER_OFF_DISABLE
#else
#define DEFAULT_AUTO_POWER_OFF          AUTO_POWER_OFF_3MIN
#endif
#define DEFAULT_LCD_AUTO_OFF               LCD_AUTO_POWER_OFF_1MIN
#define DEFAULT_BEEP                    BEEP_ON
#define DEFAULT_SILENT                  SILENT_OFF
#define DEFAULT_LANGUAGE                LANG_SC//LANG_RU//LANG_SC
#define DEFAULT_FREQUENCY               FREQUENCY_50HZ
#define DEFAULT_TV_MODE                 TV_MODE_PAL
#define DEFAULT_SENSOR_ROTATE           SEN_ROTATE_ON
#define DEFAULT_DATE_FORMAT             DATE_FORMAT_YMD
#define DEFAULT_OPENING_LOGO            OPENING_LOGO_ON
#define DEFAULT_LCD_DISPLAY             DISPLAY_NORMAL
#define DEFAULT_LCD_BRIGHTNESS          LCDBRT_LVL_05
#define DEFAULT_MACRO                   MACRO_OFF
#define DEFAULT_USB_MODE                USB_MODE_MSDC
#define DEFAULT_DATE_TIME               DATE_TIME_ON

//-----------------------------------------------------------------------------
// System
//-----------------------------------------------------------------------------
//#define UIDFT_DSC_MODE                  DSC_MODE_PHOTO_AUTO
//#define UIDFT_DSC_MODE_TRANS_PARAM      DSCMODE_SWITCH_FORCE
//#define UIDFT_DSC_MODE_TRANS_DIR        DSCMODE_SWITCHDIR_DONT_CARE
#define UIDFT_FS_STATUS                 FS_NOT_INIT
#define UIDFT_CARD_STATUS               CARD_REMOVED
#define UIDFT_BATTERY_LVL               0
#define UIDFT_MP3FTB_RENEW              MP3FTB_RENEW_ON
#define UIDFT_AUDIO_VOLUME              AUDIO_VOL_7
#else
// Photo
#define DEFAULT_PHOTO_SIZE              PHOTO_SIZE_3M
#define DEFAULT_PHOTO_QUALITY           QUALITY_FINE
#define DEFAULT_PHOTO_COLOR             COLOR_EFFECT_STANDARD
#define DEFAULT_SCENE                   SCENE_AUTO
#define DEFAULT_EV                      EV_00
#define DEFAULT_ISO                     ISO_AUTO
#define DEFAULT_WB                      WB_AUTO
#define DEFAULT_METERING                METERING_MULTI
#define DEFAULT_SHARPNESS               SHARPNESS_NORMAL
#define DEFAULT_SATURATION              SATURATION_NORMAL
#if (UI_STYLE == UI_STYLE_FDO6)
#define DEFAULT_FD                      FD_ON
#else
#define DEFAULT_FD                      FACE_DET_ON
#endif
#define DEFAULT_SD                      SMILE_DET_ON
#define DEFAULT_ANTISHAKING             ANTISHAKE_ON
#define DEFAULT_QUICK_REVIEW            QUICK_REVIEW_2SEC
#define DEFAULT_DATE_STAMP              DATE_STAMP_DATETIME
#define DEFAULT_SELFTIMER               SELFTIMER_SINGLE
#define DEFAULT_FLASH_MODE              FLASH_OFF
#define DEFAULT_PHOTO_VIVILINK          PHOTO_VIVILINK_FACEBOOK
#define DEFAULT_CONTINUE_SHOT           CONTINUE_SHOT_OFF

// Movie
#define DEFAULT_MOVIE_SIZE              MOVIE_SIZE_720P
#define DEFAULT_MOVIE_FRAMERATE         MOVIE_FRAMERATE_30FPS
#define DEFAULT_MOVIE_QUALITY           MOVIE_QUALITY_FINE
#define DEFAULT_MOVIE_COLOR             MOVIE_COLOR_NORMAL
#define DEFAULT_MOVIE_SELFTIMER         MOVIE_SELFTIMER_OFF
#define DEFAULT_MOVIE_VIVILINK          MOVIE_VIVILINK_YOUTUBE

// Playback
#define DEFAULT_PROTECT                 PROTECT_ONE
#define DEFAULT_SLIDE_SHOW              SLIDE_SHOW_3SEC
#define DEFAULT_DELETE_PHOTO            DELETE_PHOTO_THIS
#define DEFAULT_DELETE_MOVIE            DELETE_MOVIE_THIS
#define DEFAULT_PLAY_STILL_VIVILINK     PLAY_STILL_VIVILINK_NONE
#define DEFAULT_PLAY_VIDEO_VIVILINK     PLAY_VIDEO_VIVILINK_NONE
#define DEFAULT_CROP                    CROP_CANCEL
#define DEFAULT_ROTATE                  ROTATE_CANCEL
#define DEFAULT_PHOTO_PROTECT           PHOTO_LOCK_THIS
#define DEFAULT_MOVIE_PROTECT           MOVIE_LOCK_THIS
#define DEFAULT_PRINT                   PRINT_THIS_PHOTO

// System
#define DEFAULT_AUTO_POWER_OFF          AUTO_POWER_OFF_DISABLE//AUTO_POWER_OFF_3MIN
#define DEFAULT_LCD_AUTO_OFF               LCD_AUTO_POWER_OFF_1MIN
#define DEFAULT_BEEP                    BEEP_ON
#define DEFAULT_SILENT                  SILENT_OFF
#define DEFAULT_LANGUAGE                LANG_EN
#define DEFAULT_FREQUENCY               FREQUENCY_60HZ
#define DEFAULT_TV_MODE                 TV_MODE_NTSC
#define DEFAULT_STORAGE_FORMAT          FORMAT_YES
#define DEFAULT_DATE_FORMAT             DATE_FORMAT_MDY
#define DEFAULT_OPENING_LOGO            OPENING_LOGO_ON
#define DEFAULT_LCD_DISPLAY             DISPLAY_NORMAL
#define DEFAULT_LCD_BRIGHTNESS          LCDBRT_LVL_05
#define DEFAULT_MACRO                   MACRO_OFF
#define DEFAULT_USB_MODE                USB_MODE_MSDC
#define DEFAULT_INIT_SETUP              INIT_SETUP_NO
#define DEFAULT_DATE_TIME               DATE_TIME_ON
#define DEFAULT_DEFAULT_SETTING         DEFAULT_FACTORY

//-----------------------------------------------------------------------------
// System
//-----------------------------------------------------------------------------
//#define UIDFT_DSC_MODE                  DSC_MODE_PHOTO_AUTO
//#define UIDFT_DSC_MODE_TRANS_PARAM      DSCMODE_SWITCH_FORCE
//#define UIDFT_DSC_MODE_TRANS_DIR        DSCMODE_SWITCHDIR_DONT_CARE
#define UIDFT_FS_STATUS                 FS_NOT_INIT
#define UIDFT_CARD_STATUS               CARD_REMOVED
#define UIDFT_BATTERY_LVL               0
#define UIDFT_MP3FTB_RENEW              MP3FTB_RENEW_ON
#define UIDFT_AUDIO_VOLUME              AUDIO_VOL_7
#endif

#endif
