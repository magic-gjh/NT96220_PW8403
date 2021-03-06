#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIFlow.h"
#include "SieCapTsk.h"
#include "AviRecAPI.h"
#include "AviPlayAPI.h"
#include "PrimaryTsk.h"
#include "PlaybackTsk.h"
#include "MovieInterface.h"
#include "JpgEnc.h"
#include "GPIOMapping.h"
#include "MediaRecAPI.h"
#if (_MOVIE_DATE_STAMP_ == ENABLE)
#include "GenDateImprintData.h"
#include "DataStamp.h"
#endif
extern  GPSDATA gpsdata;

extern void UIFlowMoviePlayCBFunc(UINT32 event_id);
extern void AppInit_AviGetAddr(UINT32 *pAddr, UINT32 *pSize);//2011/06/15 Meg

static UINT32 uiMovieSizeTable[][4]=
{   //Width,Height, FR,     TBR
    {1920,  1080,   24,     95*1024},   // 120KB/frame, for YUV420
    //{1440,  1080,   30,     95*1024},   // 120KB/frame, for YUV420
#if (_SENSORLIB_ == _SENSORLIB_OV5653_)
    {1280,  720,    60,     70*1024},   // 70KB/frame, for YUV420
#else
    {1280,  720,    30,     70*1024},   // 70KB/frame, for YUV420
#endif
    {848,   480,    30,     60*1024},   // 50KB/frame, for YUV420
    {640,   480,    30,     50*1024}  // 50KB/frame, for YUV420
    //{320,   240,    30,     40*1024}    // 40KB/frame, for YUV420
};

static UINT32 uiMovieSizeTable_Low[][4]=
{
	//Width,Height, FR,     TBR
    {1920,  1080,   10,     50*1024},   // 120KB/frame, for YUV420
    //{1440,  1080,   10,     50*1024},   // 120KB/frame, for YUV420
    {1280,  720,    10,     50*1024},   // 70KB/frame, for YUV420
    {848,   480,    10,     50*1024},   // 50KB/frame, for YUV420
    {640,   480,    10,     50*1024}   // 50KB/frame, for YUV420
    //{320,   240,    5,     40*1024}    // 40KB/frame, for YUV420
};

static UINT32 uiMovieQuaTable[3]=
{
    AVIREC_QUALITY_BEST,
    AVIREC_QUALITY_NORMAL,
    AVIREC_QUALITY_DRAFT
};


UINT32 GetMovieQualityValue(UINT16 uhIndex)
{
    return uiMovieQuaTable[uhIndex];
}
UINT32 GetMovieSizeWidth(UINT32 ubIndex)
{
    return uiMovieSizeTable[ubIndex][0];
}

UINT32 GetMovieSizeHeight(UINT32 ubIndex)
{
    return uiMovieSizeTable[ubIndex][1];
}
UINT32 GetMovieFrameRate(UINT32 ubIndex)
{
    return uiMovieSizeTable[ubIndex][2];
}
void   SetMovieFrameRate(UINT32 value)
{
    uiMovieSizeTable[SysGetFlag(FL_MOVIE_SIZE)][2] = value;
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_VFR, value,0,0);
}
UINT32 GetMovieTargetBitrate(UINT16 ubIndex)
{
    return uiMovieSizeTable[ubIndex][3];
}


UINT32 GetMovieSizeWidth_Low(UINT32 ubIndex)
{
    return uiMovieSizeTable_Low[ubIndex][0];
}
UINT32 GetMovieSizeHeight_Low(UINT32 ubIndex)
{
    return uiMovieSizeTable_Low[ubIndex][1];
}
UINT32 GetMovieFrameRate_Low(UINT32 ubIndex)
{
    return uiMovieSizeTable_Low[ubIndex][2];
}

UINT32 GetMovieTargetBitrate_Low(UINT16 ubIndex)
{
    return uiMovieSizeTable_Low[ubIndex][3];
}

UINT32 Get_MovieEVValue(void)
{
    _IMGEVValue_sel val;

    switch(SysGetFlag(FL_MOVIE_EV))
    {
        case EV_N30:
            val = _IMGEVValue_N3;
            break;
        case EV_N20:
            val = _IMGEVValue_N2;
            break;
        case EV_N16:
            val = _IMGEVValue_N5_3;
            break;
        case EV_N15:
            val = _IMGEVValue_N3_2;
            break;
        case EV_N13:
            val = _IMGEVValue_N4_3;
            break;
        case EV_N10:
            val = _IMGEVValue_N1;
            break;
        case EV_N06:
            val = _IMGEVValue_N2_3;
            break;
        case EV_N03:
            val = _IMGEVValue_N1_3;
            break;
        case EV_00:
            val = _IMGEVValue_00;
            break;
        case EV_P03:
            val = _IMGEVValue_P1_3;
            break;
        case EV_P06:
            val = _IMGEVValue_P2_3;
            break;
        case EV_P10:
            val = _IMGEVValue_P1;
            break;
        case EV_P13:
            val = _IMGEVValue_P4_3;
            break;
        case EV_P15:
            val = _IMGEVValue_P3_2;
            break;
        case EV_P16:
            val = _IMGEVValue_P5_3;
            break;
        case EV_P20:
            val = _IMGEVValue_P2;
            break;
        case EV_P30:
            val = _IMGEVValue_P3;
            break;
        default:
            val = _IMGEVValue_00;
            break;
    }
    return val;
}

INT32 OnExe_MovieSize(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIREC_VIDEO_OBJ      AVIEncObj;

    AVIRec_GetVideo(&AVIEncObj);
	if(SysGetFlag(FL_MOVIE_TIMESHRINK) == MOVIE_TIMESHRINK_OFF)
	{
		AVIEncObj.uiHeight = GetMovieSizeHeight(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiWidth = GetMovieSizeWidth(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiVidFrameRate = GetMovieFrameRate(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiTargetBitrate = GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE));
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_WIDTH, GetMovieSizeWidth(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
    		MovRec_ChangeParam(MOVIEREC_CHGTYPE_HEIGHT, GetMovieSizeHeight(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_VFR, GetMovieFrameRate(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_TBR, GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
	}
	else
	{
		//debug_err(("henry------------2222222\r\n"));
		AVIEncObj.uiHeight = GetMovieSizeHeight_Low(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiWidth = GetMovieSizeWidth_Low(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiVidFrameRate = GetMovieFrameRate_Low(SysGetFlag(FL_MOVIE_SIZE));
		AVIEncObj.uiTargetBitrate = GetMovieTargetBitrate_Low(SysGetFlag(FL_MOVIE_SIZE));
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_WIDTH, GetMovieSizeWidth_Low(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
    		MovRec_ChangeParam(MOVIEREC_CHGTYPE_HEIGHT, GetMovieSizeHeight_Low(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_VFR, GetMovieFrameRate_Low(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
		MovRec_ChangeParam(MOVIEREC_CHGTYPE_TBR, GetMovieTargetBitrate_Low(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
	}
	/*
    AVIEncObj.uiHeight = GetMovieSizeHeight(SysGetFlag(FL_MOVIE_SIZE));
    AVIEncObj.uiWidth = GetMovieSizeWidth(SysGetFlag(FL_MOVIE_SIZE));
    AVIEncObj.uiVidFrameRate = GetMovieFrameRate(SysGetFlag(FL_MOVIE_SIZE));
    AVIEncObj.uiTargetBitrate = GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE));
    //AVIRec_SetVideo(&AVIEncObj);
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_WIDTH, GetMovieSizeWidth(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_HEIGHT, GetMovieSizeHeight(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_VFR, GetMovieFrameRate(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_TBR, GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);
	*/
    //#NT#2011/08/24#KS Hung -begin
    //Test condition for Slow Stop. If this method is OK, will Ben check in to VSS?
    JpegEncSetData(JPG_MAX_VALID_FRAME_SIZE_RATIO,  150);
    JpegEncSetData(JPG_BRC_WEIGHTING,  50);
    //#NT#2011/08/24#KS Hung -end

    // Be careful, the following codes will set image pipeline
    if (Primary_GetCurrentMode() == PRIMARY_MODE_MOVIE)
    {
        switch (SysGetFlag(FL_MOVIE_SIZE))
        {
        case MOVIE_SIZE_1080FHD:
            UI_SetParameter(_ImageRatio, _Ratio_16_9);
            UI_SetParameter(_Vid_Resolution, _Resolution_1920x1080);
            break;
        case MOVIE_SIZE_1080P:
            UI_SetParameter(_ImageRatio, _Ratio_4_3);
            UI_SetParameter(_Vid_Resolution, _Resolution_1440x1080);
            break;
        case MOVIE_SIZE_720P:
            UI_SetParameter(_ImageRatio, _Ratio_16_9);
#if (_SENSORLIB_ == _SENSORLIB_OV5653_)
            UI_SetParameter(_Vid_Resolution, _Resolution_1280x720P60);
#else
            UI_SetParameter(_Vid_Resolution, _Resolution_1280x720);
#endif
            break;

        case MOVIE_SIZE_WVGA:
            UI_SetParameter(_ImageRatio, _Ratio_4_3);
            UI_SetParameter(_Vid_Resolution, _Resolution_848x480);
            break;

        case MOVIE_SIZE_VGA:
            UI_SetParameter(_ImageRatio, _Ratio_4_3);
            UI_SetParameter(_Vid_Resolution, _Resolution_640x480);
            break;

        case MOVIE_SIZE_QVGA:
            UI_SetParameter(_ImageRatio, _Ratio_4_3);
            UI_SetParameter(_Vid_Resolution, _Resolution_320x240);
            break;

        default:
            UI_SetParameter(_ImageRatio, _Ratio_16_9);
            UI_SetParameter(_Vid_Resolution, _Resolution_1280x720);
            break;
        }
    }

    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieFPS(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIREC_VIDEO_OBJ      AVIEncObj;

    AVIRec_GetVideo(&AVIEncObj);
    AVIEncObj.uiTargetBitrate = GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE));

    switch(SysGetFlag(FL_MOVIE_FRAMERATE))
    {
    case MOVIE_FRAMERATE_15FPS:
        AVIEncObj.uiVidFrameRate = 15;
        break;
    case MOVIE_FRAMERATE_30FPS:
        AVIEncObj.uiVidFrameRate = 30;
        break;
    default:
        AVIEncObj.uiVidFrameRate = 30;
        break;
    }

    AVIRec_SetVideo(&AVIEncObj);

    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieQuality(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIREC_VIDEO_OBJ      AVIEncObj;

    AVIRec_GetVideo(&AVIEncObj);
    AVIEncObj.uiRecQuality = GetMovieQualityValue(SysGetFlag(FL_MOVIE_QUALITY));
    AVIEncObj.uiTargetBitrate = GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE));
    //AVIRec_SetVideo(&AVIEncObj);
    MovRec_ChangeParam(MOVIEREC_CHGTYPE_TBR, GetMovieTargetBitrate(SysGetFlag(FL_MOVIE_SIZE)), 0, 0);

    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieSelftimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uiSelect = 0;

    if(paramNum>0)
        uiSelect = paramArray[0];

    //SysSetFlag(FL_MOVIE_SELFTIMER, uiSelect); // This is performed at Menu System.
    return NVTEVT_CONSUME;
}

INT32 OnExe_Gsensor(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uiSelect = 0;
    if(paramNum>0)
        uiSelect= paramArray[0];
	
    debug_err(("---OnExe_Gsensor : %d---\r\n",uiSelect));
    SysSetFlag(FL_GSENSOR, uiSelect);
    //GSensorSensitivity(uiSelect);    
    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieTimeShrink(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	UINT32 uiSelect = 0;

    if (paramNum != 0)
    {
        uiSelect = paramArray[0];
    }

    SysSetFlag(FL_MOVIE_TIMESHRINK, uiSelect);
    Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_MOVIESIZE, 1, SysGetFlag(FL_MOVIE_SIZE));

    return NVTEVT_CONSUME;	
}


INT32 OnExe_MovieParkingMonitor(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	UINT32 uiSelect = 0;

    if (paramNum != 0)
    {
        uiSelect = paramArray[0];
    }

    SysSetFlag(FL_MOVIE_PARKING, uiSelect);

    return NVTEVT_CONSUME;	
}

INT32 OnExe_MovieSocialNetwork(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiSelect = 0;

    if (paramNum)
        uiSelect = paramArray[0];

    //#NT#2011/08/17#KS Hung -begin
    switch (uiSelect)
    {
    case MOVIE_VIVILINK_YOUTUBE:
        SysSetSocialNetworkData(VIVILINK_YOUTUBE);
        break;
    case MOVIE_VIVILINK_PHOTOBUCKET:
        SysSetSocialNetworkData(VIVILINK_PHOTOBUCKET);
        break;
    case MOVIE_VIVILINK_FLICKR:
        SysSetSocialNetworkData(VIVILINK_FLICKR);
        break;
    case MOVIE_VIVILINK_NONE:
        SysSetSocialNetworkData(VIVILINK_NONE);
        break;
    }
    //#NT#2011/08/17#KS Hung -end

    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieLedLight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    if(paramNum != 0)
        uhSelect= paramArray[0];

    if (paramNum == 0)
    {
        if (GPIOMap_IsFloodLightOn())
        {
            GPIOMap_TurnOffFloodLight();
        }
        else
        {
            GPIOMap_TurnOnFloodLight();
        }
    }
    else
    {
        if (uhSelect)
        {
            GPIOMap_TurnOnFloodLight();
        }
        else
        {
            GPIOMap_TurnOffFloodLight();
        }
    }
    //debug_msg("OnExe_MovieLedLight*********************************ERIC_DEBUG\n\r");//ERIC_DEBUG
   /* if (GPIOMap_IsFloodLightOn())
        {
            GPIOMap_TurnOffFloodLight();
        }
        else
        {
            GPIOMap_TurnOnFloodLight();
        }*/
    return NVTEVT_CONSUME;
}

static void OnExe_MovieRecordSetting(void)
{
  #if (_MOVIE_DATE_STAMP_ == ENABLE)
    UINT32 uiDateFormat;

        switch(SysGetFlag(FL_DATE_FORMAT))
        {
          case DATE_FORMAT_DMY:
            uiDateFormat = STAMP_DD_MM_YY;
            break;
          case DATE_FORMAT_MDY:
            uiDateFormat = STAMP_MM_DD_YY;
            break;
          case DATE_FORMAT_YMD:
          default:
            uiDateFormat = STAMP_YY_MM_DD;
            break;
        }

        // Generate date imprint
        switch (SysGetFlag(FL_MOVIE_DATEIMPRINT))
        {
        case MOVIE_DateImprint_ON:
            {
                //Photo_VidstampEnable(TRUE);
                // use STAMP_AUTO to set position automatically
                GenMovieDID_Setup(
                    STAMP_ON |
                    STAMP_AUTO |
                    STAMP_DATE_TIME |
                    STAMP_BOTTOM_LEFT |
                    uiDateFormat, DS_YCCFORMAT_420);

                GenMovieDID_ReFresh();
            }
            break;

        case MOVIE_DateImprint_OFF:
        default:
            GenMovieDID_Setup(STAMP_OFF, DS_YCCFORMAT_420);
            //Photo_VidstampEnable(FALSE);
            break;
        }

  #endif
}

INT32 UIRecMovie_Start(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2011/06/15#Meg Lin -begin
    //UINT32 aviAddr, aviSize;
    //AppInit_AviGetAddr(&aviAddr, &aviSize);
    //MovRec_ResetMemoryValue(aviAddr, aviSize);
    //#NT#2011/06/15#Meg Lin -end

#if (_MOVIE_AVI_USERDATA_ == ENABLE)
    if (AVIRec_SetUserData((UINT8 *)SysGetSocialNetworkData(), SysGetSocialNetworkDataSize()) == 0)
    {
        debug_err(("User data overflow!\r\n"));
        return NVTEVT_CONSUME;
    }
#endif


#if (UI_STYLE == UI_STYLE_DRIVE)
    OnExe_MovieRecordSetting();

    /* update DCF filename while capturing one photo and sync with RTC date/time */
    Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_UPDATE_DCF, 1, FALSE);

    // force enable file recovery in power lost
    //MediaRec_ChangeParameter(MEDIAREC_RECPARAM_PWROFFPT, 1, 0, 0);
    MediaRec_ChangeParameter(MEDIAREC_RECPARAM_PWROFFPT, 0, 0, 0);//jack lan 
	
    // disable Golf_shot/Flash recording
    MediaRec_ChangeParameter(MEDIAREC_RECPARAM_GOLFSHOT_ON, 0, 0, 0);
    MediaRec_ChangeParameter(MEDIAREC_RECPARAM_FLASH_ON, 0, 0, 0);
    #if (_GPS_RECEIVER_ == ENABLE)
    MediaRec_ChangeParameter(MEDIAREC_RECPARAM_GPSON, 1, 0, 0);
    MediaRec_SetGPSData((UINT32)&gpsdata,sizeof(GPSDATA));	
    #endif
#if (_GPS_RECEIVER_LOG_ == ENABLE)
        GPSRec_EnableGPSLog(TRUE);
#endif		
#if (_MOVIE_REC_SEAMLESS_ == ENABLE)
    if (SysGetFlag(FL_MOVIE_LOOP_REC) != MOVIE_CYCLICREC_OFF) {
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUTOVERLAP, 0, 0);
    } else {
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_CUTSEC, 600, 0, 0);
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUT_TILLCARDFULL, 0, 0);
#if 0
        //#NT#2011/11/21#Philex Lin - begin
        // don't cyclic record while pluging TV
        if (KeyScan_IsTVPlugIn()==FALSE)
        {
            // cylic recording must do in AC IN condition
            if (KeyScan_IsACIn())
            {
                MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUTOVERLAP, 0, 0);
            }else
            {
                MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUT_TILLCARDFULL, 0, 0);
    //            MediaRec_ChangeParameter(MEDIAREC_RECPARAM_CUTSEC, 900, 0, 0); // 15min
            }
        } else {
            //MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUT_TILLCARDFULL, 0, 0);
        }
        //#NT#2011/11/21#Philex Lin - end
#endif
    }
#endif
#endif

#if 1//(PRJ == APC3)
    KeyScan_EnableLEDToggle(KEYSCAN_LED_GREEN, TRUE);
#endif

    MovRec_Record();//AVIRec_Record();
    return NVTEVT_CONSUME;
}

INT32 UIRecMovie_Stop(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if (PRJ == APC3)
    KeyScan_EnableLEDToggle(KEYSCAN_LED_GREEN, FALSE);
    if(paramNum > 0 && paramArray[0] == 1)
    {
        MediaRec_StopAndReadOnly();
    }
    else
#endif
    KeyScan_EnableLEDToggle(KEYSCAN_LED_GREEN, FALSE);
    KeyScan_TurnOnLED(KEYSCAN_LED_GREEN);

    MovRec_Stop(TRUE);//AVIRec_Stop(AVIREC_WAIT_END);
#if (_GPS_RECEIVER_LOG_ == ENABLE)	
        GPSRec_EnableGPSLog(FALSE);    
#endif	    
    return NVTEVT_CONSUME;
}
INT32 OnExe_MovieCyclicRec(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
 UINT32 uhSelect = 0;
 UINT32 uiCycleRecTime=0;

    if(paramNum != 0)
        uhSelect= paramArray[0];

    debug_ind(("OnExe_MovieCyclicRec\n\r"));

    SysSetFlag(FL_MOVIE_LOOP_REC, uhSelect);
    switch (uhSelect)
    {
    case MOVIE_CYCLICREC_OFF:
        if (KeyScan_IsACIn())
            uiCycleRecTime=0;
        break;
    case MOVIE_CYCLICREC_1MIN:
           uiCycleRecTime=58;//60
        break;
    case MOVIE_CYCLICREC_3MIN:
           uiCycleRecTime=178;// 180
        break;
    case MOVIE_CYCLICREC_5MIN:
           uiCycleRecTime=298;// 300
        break;
    case MOVIE_CYCLICREC_10MIN:
           uiCycleRecTime=598; // 600
        break;      
      default:
        uiCycleRecTime=180;
        break;
    }
    debug_msg("^R######uiCycleRecTime = %d",uiCycleRecTime);
    if (uhSelect != MOVIE_CYCLICREC_OFF) {
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_CUTSEC,uiCycleRecTime,0,0);
    } else {
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_CUTSEC, 600, 0, 0); // 10 min
        MediaRec_ChangeParameter(MEDIAREC_RECPARAM_ENDTYPE, MEDIAREC_ENDTYPE_CUT_TILLCARDFULL, 0, 0);
    }

    return NVTEVT_CONSUME;
}



UINT32 Get_MovieCyclicRecTime(void)
{
    UINT32 uiCycleRecTime=0;
    switch (SysGetFlag(FL_MOVIE_LOOP_REC))
    {
    // cyclic recording handling
      case MOVIE_CYCLICREC_1MIN:
           uiCycleRecTime=60;
        break;
      case MOVIE_CYCLICREC_2MIN:
           uiCycleRecTime=120;
        break;		
      case MOVIE_CYCLICREC_3MIN:
           uiCycleRecTime=180;
        break;
      case MOVIE_CYCLICREC_5MIN:
           uiCycleRecTime=300;
        break;
      case MOVIE_CYCLICREC_10MIN:
           uiCycleRecTime=600;
        break;
      case MOVIE_CYCLICREC_15MIN:
           uiCycleRecTime=900;
        break;		
    }
    return uiCycleRecTime;
}
INT32 OnExe_MovieMotionDet(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    if(paramNum != 0)
        uhSelect= paramArray[0];

    debug_ind(("OnExe_MovieMotionDet\n\r"));
    SysSetFlag(FL_MOVIE_MOTION_DET, uhSelect);
    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieAudio(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
 AUDIO_DEVICE_OBJ AudioDevObj;
 AUDIO_GAIN Gain;
 UINT32 uhSelect = 0;

    if(paramNum != 0)
        uhSelect= paramArray[0];

    debug_ind(("OnExe_MovieAudio\n\r"));

    SysSetFlag(FL_MOVIE_AUDIO, uhSelect);
    switch(uhSelect)
    {
        case MOVIE_AUDIOENABLE_OFF:
            Gain = AUDIO_GAIN_MUTE;
            break;
        case MOVIE_AUDIOENABLE_ON:
        default:
            Gain = AUDIO_GAIN_7;
            break;
    }

    if (aud_getLockStatus() == TASK_LOCKED)
    {
        aud_setGain(Gain);
    }
    else
    {
        aud_getDeviceObject(&AudioDevObj);
        aud_open(&AudioDevObj);
        aud_setGain(Gain);
        aud_close();
    }

    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieDateImprint(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    if(paramNum != 0)
        uhSelect= paramArray[0];

    debug_ind(("OnExe_MovieDateImprint\n\r"));
    SysSetFlag(FL_MOVIE_DATEIMPRINT, uhSelect);
    return NVTEVT_CONSUME;
}

INT32 OnExe_MovieEV(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    ImgCapture_SetParameter(_AEEV,(UINT8)Get_MovieEVValue());
    return NVTEVT_CONSUME;
}

UINT32 UIRecMovie_GetData(RECMOVIE_GET_DATATYPE dataType)
{
    UINT32 retV = 0;
    switch(dataType)
    {
        case RECMOVIE_MAXSECOND:
        #if (_MEDIA_REC_ == _APPMEDIAREC_)
            MediaRec_ChangeParameter(MEDIAREC_RECPARAM_PWROFFPT, 1, 0, 0);
            MediaRec_SetDisk2SecRestriction(MEDIAREC_RESTR_INDEXBUF,0);
            retV = MediaRec_Disk2SecondWithType(MEDIAREC_COUNTTYPE_FS,0);//AVIRec_Disk2Second();
        #else
            retV = MovRec_Disk2Second();//AVIRec_Disk2Second();
        #endif
            break;
        default:
            break;
    }
    return retV;
}
/*
INT32 UIPlayMovie_Init(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    static AVIPLAY_OBJ aviPlayObj;
    PLAY_OBJ    playObj;
    INT32       retV;

    AVIPlay_Close();
    PB_Close(PB_WAIT_INFINITE);
    memset((void *)&playObj, 0, sizeof(PLAY_OBJ));
    memset((void *)&aviPlayObj, 0, sizeof(AVIPLAY_OBJ));
    aviPlayObj.CallBackFunc = PlayFlowMoviePlayCBFunc;
    aviPlayObj.bHWVideo = TRUE;
    aviPlayObj.bHWAudio = FALSE;
    aviPlayObj.bPlayAllFiles = FALSE ;

    //#NT#2010/03/12#Chris Chung -begin
    //#NT#add to set data buffer size by project
    #if (DRAM_END == 0x01000000)
    aviPlayObj.uiPlayDataBufferSize = 0x200000; // 2MB
    #else
    aviPlayObj.uiPlayDataBufferSize = 0x300000; // 3MB
    #endif
    //#NT#2010/03/12#Chris Chung -end

    retV = AVIPlay_Open(&aviPlayObj);
    return retV;
}
*/
/*
INT32 UIPlayMovie_Close(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 retV;
    static PLAY_OBJ playObj;
    memset((void *)&playObj,0,sizeof(PLAY_OBJ));

    AVIPlay_Stop();
    AVIPlay_Close();
    playObj.ui1stPlayMode = PLAYMODE_AVI;
    retV = PB_Open(&playObj);
    PB_WaitCommandFinish(PB_WAIT_INFINITE);
    return retV;
}
*/
/*
INT32 UIPlayMovie_ForewardPlay(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_FWD();
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_BackwardPlay(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_BWD();
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_ForewardStepPlay(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_FWDStep();
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_BackwardStepPlay(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_BWDStep();
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_PausePlay(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_Pause();
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_SetSpeedL1(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X1_IDX);
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_SetSpeedL2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X2_IDX);
    return NVTEVT_CONSUME;
}
*/
/*
INT32 UIPlayMovie_SetSpeedL4(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X4_IDX);
    return NVTEVT_CONSUME;
}
*/
/*
UINT32 UIPlayMovie_GetData(PLAYMOVIE_GET_DATATYPE dataType)
{
    PAVIHEAD_INFO puiMovieInfo = 0;
    UINT32 retV = 0;
    switch(dataType)
    {
        case PLAYMOVIE_DIRID:
            retV = PB_GetCurFileDirId();
            break;
        case PLAYMOVIE_FILEID:
            retV = PB_GetCurFileNameId();
            break;
        case PLAYMOVIE_TOTAL_FRAME:
            retV = AVIPlay_GetCurrTotalVideoFrame();
            break;
        case PLAYMOVIE_TOTAL_SECOND:
            puiMovieInfo = PB_GetCurrAVIInfo();
            retV = puiMovieInfo->uiToltalSecs;
            break;
        case PLAYMOVIE_CURR_FRAME:
            retV = AVIPlay_GetCurrCurrVideoFrame();
            break;
        case PLAYMOVIE_CURR_SECOND:
            retV = AVIPlay_GetCurrPlaySecs();
            break;
        case PLAYMOVIE_LOCKSTATUS:
            retV = PB_GetFILELock();
            break;
        case PLAYMOVIE_FILENUM:
            retV = PB_GetCurrFileSysInfo(PLAYFILEINFO_FILENUMS);
            break;
        default:
            debug_msg("UIPlayMovie_GetData:Unknown type=%d\r\n", dataType);
            break;
    }
    return retV;
}
*/
/*
void UIPlayMovie_SetData(PLAYMOVIE_SET_DATATYPE dataType)
{
    switch(dataType)
    {
        case PLAYMOVIE_SPEEDL1:
            AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X1_IDX);
            break;
        case PLAYMOVIE_SPEEDL2:
            AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X2_IDX);
            break;
        case PLAYMOVIE_SPEEDL4:
            AVIPlay_SpeedUp(UIPLAYAVI_SPEED_X4_IDX);
            break;
        default:
            debug_msg("UIPlayMovie_SetData:Unknown type=%d\r\n", dataType);
            break;
    }
    return;
}
*/
////////////////////////////////////////////////////////////

EVENT_ENTRY UIMovieObjCtrlCmdMap[] =
{
    {NVTEVT_EXE_MOVIESIZE,          OnExe_MovieSize},
    {NVTEVT_EXE_MOVIEFPS,           OnExe_MovieFPS},
    {NVTEVT_EXE_QUALITY,            OnExe_MovieQuality},
    //{NVTEVT_EXE_COLOR,              OnExe_MovieColor},
    {NVTEVT_EXE_SELFTIMER,          OnExe_MovieSelftimer},
    {NVTEVT_EXE_SOCIALNETWORK,      OnExe_MovieSocialNetwork},
    {NVTEVT_START_RECAVI,           UIRecMovie_Start},
    {NVTEVT_STOP_RECAVI,            UIRecMovie_Stop},
    {NVTEVT_EXE_LEDLIGHT,           OnExe_MovieLedLight},
    {NVTEVT_EXE_CYCLIC_REC,         OnExe_MovieCyclicRec},
    {NVTEVT_EXE_MOTION_DET,         OnExe_MovieMotionDet},
    {NVTEVT_EXE_DATEIMPRINT,        OnExe_MovieDateImprint},
    {NVTEVT_EXE_VIDEO_AUDIO,        OnExe_MovieAudio},
    {NVTEVT_EXE_EV,                 OnExe_MovieEV},
    {NVTEVT_EXE_GSENSOR,                 OnExe_Gsensor},   
    {NVTEVT_EXE_MOVIEPARKING, OnExe_MovieParkingMonitor},
    {NVTEVT_EXE_MOVIETIMESHRINK,OnExe_MovieTimeShrink},
    //{NVTEVT_INIT_PLAYAVI,           UIPlayMovie_Init},
    //{NVTEVT_CLOSE_PLAYAVI,          UIPlayMovie_Close},
    //{NVTEVT_FWDPLAY_PLAYAVI,        UIPlayMovie_ForewardPlay},
    //{NVTEVT_BWDPLAY_PLAYAVI,        UIPlayMovie_BackwardPlay},
    //{NVTEVT_FWDSTEPPLAY_PLAYAVI,    UIPlayMovie_ForewardStepPlay},
    //{NVTEVT_BWDSTEPPLAY_PLAYAVI,    UIPlayMovie_BackwardStepPlay},
    //{NVTEVT_PAUSE_PLAYAVI,          UIPlayMovie_PausePlay},
    {NVTEVT_NULL,                   0},  //End of Command Map
};

VControl UIMovieObjCtrl={
    "UIMovieObj",
    UIMovieObjCtrlCmdMap,
    0,
    CTRL_SYS,
    0,  //data
    0,
    0,
    {0,0,0,0},
    0,
    0
};

