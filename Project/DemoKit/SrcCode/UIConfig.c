/**
    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.

    @file       CalibrationTsk.c
    @ingroup    mIPRJAPTest

    @brief      Calibration task API
                Calibration task API

    @note       Nothing.

    @date       2006/01/02
*/

/** \addtogroup mIPRJAPTest */
//@{

#include <ctype.h>
#include "Kernel.h"
#include "SysCfg.h"
#include "CalibrationTsk.h"
#include "CalibrationInt.h"
#include "PrimaryTsk.h"
#include "KeyScanTsk.h"
#include "UIFramework.h"
#include "UIFlow.h"
#include "FileSysTsk.h"
#include "UICtrlMenuLib.h"
#include "UIConfig.h"
#include "UICustomer.h"
#include "Utility.h"
#include "KeySCanInt.h"
#include "SystemInit.h"
#include "Nor.h"

#define MAKE_WORD(l, h)     ((UINT16)(((UINT8)(l)) | ((UINT16)((UINT8)(h))) << 8))
#define MAKE_LONG(l, h)     ((UINT32)(((UINT16)(l)) | ((UINT32)((UINT16)(h))) << 16))
#define LO_LONG(x)          ((UINT32)(x))
#define HI_LONG(x)          ((UINT32)((x>>32) & ((1ULL<<32) - 1)))
#define LO_WORD(l)          ((UINT16)(l))
#define HI_WORD(l)          ((UINT16)(((UINT32)(l) >> 16) & 0xFFFF))
#define LO_BYTE(w)          ((UINT8)(w))
#define HI_BYTE(w)          ((UINT8)(((UINT16)(w) >> 8) & 0xFF))

#define KEY_LEN         (0X20)
#define VALUE_LEN       (0X30)
#define KEY_VALUE_LEN   (0X50)

#define SYSPARAM_LOGO_LEN    (0X6000)
#define SYSPARAM_SYSFLAG_LEN (0X1000)
#define LOGO_MAX_FILESIZE   (SYSPARAM_LOGO_LEN-4)
#define CFG_MAX_FILESIZE    (SYSPARAM_SYSFLAG_LEN-4)

#define SPI_SYSFLAG_PARAM_MAGIC     0x9582AB15

#if 1
#define USE_MSG(msg)    debug_msg msg
#else
#define USE_MSG(msg)    debug_ind (msg)
#endif

    /*--- Setup Default value---*/
static UIConfigInfo gUIConfigInfo;

CHAR *GetUIConfigSoftwareVer(void)
{
    return gUIConfigInfo.strSoftwareVer;
}
CHAR *GetUIConfigMakerString(void)
{
    return gUIConfigInfo.strMakerString;
}
CHAR *GetUIConfigModelString(void)
{
    return gUIConfigInfo.strModelString;
}
CHAR *GetUIConfigMakeNote(void)
{
    return gUIConfigInfo.strMakeNote;
}
CHAR *GetUIConfigImageDescription(void)
{
    return gUIConfigInfo.strImageDescription;
}
void UI_SetSizeDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiSizeDefaultIndex = index;
}
UINT32 UI_GetSizeDefaultIndex(void)
{
    if (gUIConfigInfo.uiSizeDefaultIndex >= PHOTO_SIZE_ID_MAX)
    {
        gUIConfigInfo.uiSizeDefaultIndex = 0;
    }
    return gUIConfigInfo.uiSizeDefaultIndex;
}
void UI_SetRamSizeDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiRamSizeDefaultIndex = index;
}
UINT32 UI_GetRamSizeDefaultIndex(void)
{
    if (gUIConfigInfo.uiRamSizeDefaultIndex >= PHOTO_SIZE_ID_MAX)
    {
        gUIConfigInfo.uiRamSizeDefaultIndex = 0;
    }
    return gUIConfigInfo.uiRamSizeDefaultIndex;
}
void UI_SetMovieSizeDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiMovieSizeDefaultIndex = index;
}
UINT32 UI_GetMovieSizeDefaultIndex(void)
{
    if (gUIConfigInfo.uiMovieSizeDefaultIndex >= MOVIE_SIZE_ID_MAX)
    {
        gUIConfigInfo.uiMovieSizeDefaultIndex = 0;
    }
    return gUIConfigInfo.uiMovieSizeDefaultIndex;
}

void UI_SetLanguageDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiLanguageDefaultIndex = index;
}
UINT32 UI_GetLanguageDefaultIndex(void)
{
    if (gUIConfigInfo.uiLanguageDefaultIndex >= LANG_ID_MAX)
    {
        gUIConfigInfo.uiLanguageDefaultIndex = 0;
    }
    return gUIConfigInfo.uiLanguageDefaultIndex;
}
void UI_SetFreqDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiFreqDefaultIndex = index;
}
UINT32 UI_GetFreqDefaultIndex(void)
{
    if (gUIConfigInfo.uiFreqDefaultIndex >= FREQUENCY_ID_MAX)
    {
        gUIConfigInfo.uiFreqDefaultIndex = 0;
    }
    return gUIConfigInfo.uiFreqDefaultIndex;
}
void UI_SetAntiShakeDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiAntiShakeDefaultIndex = index;
}
UINT32 UI_GetAntiShakeDefaultIndex(void)
{
    if (gUIConfigInfo.uiAntiShakeDefaultIndex >= ANTISHAKE_ID_MAX)
    {
        gUIConfigInfo.uiAntiShakeDefaultIndex = 0;
    }
    return gUIConfigInfo.uiAntiShakeDefaultIndex;
}
void UI_SetTVModeDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiTVModeDefaultIndex = index;
}
UINT32 UI_GetTVModeDefaultIndex(void)
{
    if (gUIConfigInfo.uiTVModeDefaultIndex >= TV_MODE_ID_MAX)
    {
        gUIConfigInfo.uiTVModeDefaultIndex = 0;
    }
    return gUIConfigInfo.uiTVModeDefaultIndex;
}
void UI_SetDateImprintDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiDateImprintDefaultIndex = index;
}
UINT32 UI_GetDateImprintDefaultIndex(void)
{
    if (gUIConfigInfo.uiDateImprintDefaultIndex >= (DATE_TIME_ID_MAX-1))
    {
        gUIConfigInfo.uiDateImprintDefaultIndex = 0;
    }
    return gUIConfigInfo.uiDateImprintDefaultIndex;
}
void UI_SetAutoPowerOffDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiAutoPowerOffDefaultIndex = index;
}
UINT32 UI_GetAutoPowerOffDefaultIndex(void)
{
    if (gUIConfigInfo.uiAutoPowerOffDefaultIndex >= AUTO_POWER_OFF_ID_MAX)
    {
        gUIConfigInfo.uiAutoPowerOffDefaultIndex = 0;
    }
    return gUIConfigInfo.uiAutoPowerOffDefaultIndex;
}
void UI_SetLcdOffDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiLcdOffDefaultIndex = index;
}
UINT32 UI_GetLcdOffDefaultIndex(void)
{
    if (gUIConfigInfo.uiLcdOffDefaultIndex >= LCD_AUTO_POWER_OFF_ID_MAX)
    {
        gUIConfigInfo.uiLcdOffDefaultIndex = 0;
    }
    return gUIConfigInfo.uiLcdOffDefaultIndex;
}
void UI_SetBeepDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiBeepDefaultIndex = index;
}
UINT32 UI_GetBeepDefaultIndex(void)
{
    if (gUIConfigInfo.uiBeepDefaultIndex >= (BEEP_ID_MAX))
    {
        gUIConfigInfo.uiBeepDefaultIndex = 0;
    }
    return gUIConfigInfo.uiBeepDefaultIndex;
}

//ERIC EDIT 0901 BEGIN
void UI_SetSilentDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiLEDDefaultIndex = index;
}
UINT32 UI_GetSilentDefaultIndex(void)
{
    if (gUIConfigInfo.uiLEDDefaultIndex >= (SILENT_ID_MAX))
    {
        gUIConfigInfo.uiLEDDefaultIndex = 0;
    }
    return gUIConfigInfo.uiLEDDefaultIndex;
}
//ERIC EDIT 0901 END
void UI_SetGsensorDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiGsensorDefaultIndex = index;
}
UINT32 UI_GetGsensorDefaultIndex(void)
{
    if (gUIConfigInfo.uiGsensorDefaultIndex >= (GSENSOR_ID_MAX))
    {
        gUIConfigInfo.uiGsensorDefaultIndex = 0;
    }
    return gUIConfigInfo.uiGsensorDefaultIndex;
}
void UI_SetParkingDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiParkingDefaultIndex = index;
}
UINT32 UI_GetParkingDefaultIndex(void)
{
    if (gUIConfigInfo.uiParkingDefaultIndex >= (MOVIE_PARKING_MAX))
    {
        gUIConfigInfo.uiParkingDefaultIndex = 0;
    }
    return gUIConfigInfo.uiParkingDefaultIndex;
}
void UI_SetCyclicRecDefaultIndex(UINT32 index)
{
    gUIConfigInfo.uiCyclicRecDefaultIndex = index;
}
UINT32 UI_GetCyclicRecDefaultIndex(void)
{
    if (gUIConfigInfo.uiCyclicRecDefaultIndex >= (MOVIE_CYCLICREC_ID_MAX))
    {
        gUIConfigInfo.uiCyclicRecDefaultIndex = 0;
    }
    return gUIConfigInfo.uiCyclicRecDefaultIndex;
}

BOOL get_key_value (char *cfgbuf,char *flgbuf)
{
    char* current;
    char* tail;
    char* value;
    char* key;
    UINT8 index=0;
    UINT8 count=0;
    if (!cfgbuf)
        return FALSE;

    current = cfgbuf;
    //remove first " "
    while (*current == ' ' && count < 0x80)
    {
          current++;
          count++;
    }

    while(TRUE)
    {
        count=0;
        tail = current;
        key = current;
        //key=value
        //first,find key(=)
        while (*tail != '=' && count < 0x80)
        {
              if (*tail == '\0' || *tail == '#') return TRUE;
              tail++;
              count++;
        }
        if (count >= 0x79) break;

        *tail = '\0';

        value = tail+1;

        count=0;

        tail++;
        while ( *tail != '\r' && *tail != '\n' && *tail != '\0' && count < 0x80)
        {
            tail++;
            count++;
        }
        if (count >= 0x79) break;
        *tail = '\0';
        tail++;
        while(TRUE)
        {
            if (*tail == '\r' || *tail == '\n')
            {
                tail++;
            }else
            {
                break;
            }
        }
        current = tail;
        if ((strlen(key) > KEY_LEN) || (strlen(value) > VALUE_LEN))
        {
            return FALSE;
        }
        strcpy(flgbuf+index*KEY_VALUE_LEN,key);
        strcpy(flgbuf+index*(KEY_VALUE_LEN)+KEY_LEN,value);
        index++;
    }
    return TRUE;
}

BOOL UI_LoadCfgFile(void)
{
    ER erReturn;
    UINT32 i;

    char *SysParam_Sector;
    UINT32      uiFileSize;
    UINT8       *BgBuf;
    PSTORE_SECTION_HANDLE* pSecHdl;

    strcpy(gUIConfigInfo.strMakerString, (CHAR *)GetMakerString());
    strcpy(gUIConfigInfo.strModelString,(CHAR *)GetModelString());
    strcpy(gUIConfigInfo.strSoftwareVer,(CHAR *)GetUIConfigSoftwareVer());

    gUIConfigInfo.uiSizeDefaultIndex        = DEFAULT_PHOTO_SIZE;
    gUIConfigInfo.uiMovieSizeDefaultIndex   = DEFAULT_MOVIE_SIZE;
    gUIConfigInfo.uiLanguageDefaultIndex    = DEFAULT_LANGUAGE;
    gUIConfigInfo.uiFreqDefaultIndex        = DEFAULT_FREQUENCY;
    gUIConfigInfo.uiAntiShakeDefaultIndex   = DEFAULT_ANTISHAKING;
    gUIConfigInfo.uiTVModeDefaultIndex      = DEFAULT_TV_MODE;
    gUIConfigInfo.uiDateImprintDefaultIndex = DEFAULT_DATE_TIME;

    //get_blk((void *)&BgBuf,  POOL_ID_SICD);
    //rel_blk(POOL_ID_SICD, BgBuf);
    SysGetSICDAddr((UINT32*)&BgBuf);

    //PStore_EnablePS();
    pSecHdl = PStore_OpenSection(PS_BG_CFG, PS_RDONLY);

    if (pSecHdl == E_PS_SECHDLER)
    {
        debug_err(("UserPS_ReadCfgFile: Section open fail\r\n"));
        goto err_ret;
    }

    erReturn = PStore_ReadSection(BgBuf, 0, 4, pSecHdl);

    if (erReturn != E_PS_OK)
    {
        debug_err(("UserPS_ReadCfgFile: PStore read error\r\n"));
        goto err_ret;
    }

    uiFileSize = MAKE_LONG(MAKE_WORD(BgBuf[0],BgBuf[1]),MAKE_WORD(BgBuf[2],BgBuf[3]));

    USE_MSG(("UserPS_ReadCfgFile: cfg filesize=%d\r\n", uiFileSize));

    if (uiFileSize > CFG_MAX_FILESIZE)
    {
        debug_err(("UserPS_ReadCfgFile: file size error\n\r"));
        goto err_ret;
    }

    erReturn = PStore_ReadSection(BgBuf, 0, (uiFileSize+4), pSecHdl);
    if (erReturn != E_PS_OK)
    {
        debug_err(("UserPS_ReadCfgFile: PStore read error\r\n"));
        goto err_ret;
    }
    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();

    SysParam_Sector = (char *)(BgBuf + ((uiFileSize+4+4-1)/4)*4);

    memset((UINT8 *)SysParam_Sector,0,SYSPARAM_SYSFLAG_LEN);
    if (!get_key_value((char *)&BgBuf[4],(char*)SysParam_Sector))
    {
        debug_err(("UserPS_ReadCfgFile: Read cfg file error\r\n"));
        return FALSE;//goto err_ret;
    }

    i = 0;
    while(TRUE)
    {
        if (SysParam_Sector[0] == '\0')
        {
             debug_err(("sysflag is null\r\n"));
             break;
        }
        if (i*KEY_VALUE_LEN >= SYSPARAM_SYSFLAG_LEN)
        {
            break;
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "audio"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
            {
                USE_MSG(("audio yes\r\n"));
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
            {
                USE_MSG(("audio no\r\n"));
            }
        }

        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "hz"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "50hz"))
            {
                USE_MSG(("50hz\r\n"));
                UI_SetFreqDefaultIndex(FREQUENCY_50HZ);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "60hz"))
            {
                USE_MSG(("60hz\r\n"));
                UI_SetFreqDefaultIndex(FREQUENCY_60HZ);
            }
        }
         if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "shake"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
            {
                USE_MSG(("shake yes\r\n"));
                UI_SetAntiShakeDefaultIndex(ANTISHAKE_ON);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
            {
                USE_MSG(("shake no\r\n"));
                UI_SetAntiShakeDefaultIndex(ANTISHAKE_OFF);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "tvmode"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "pal"))
            {
                USE_MSG(("tvmode pal\r\n"));
                UI_SetTVModeDefaultIndex(TV_MODE_PAL);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "ntsc"))
            {
                USE_MSG(("tvmode  ntsc\r\n"));
                UI_SetTVModeDefaultIndex(TV_MODE_NTSC);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "date"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
            {
                USE_MSG(("date_time on\r\n"));
                UI_SetDateImprintDefaultIndex(DATE_TIME_ON);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
            {
                USE_MSG(("date_time off\r\n"));
                UI_SetDateImprintDefaultIndex(DATE_TIME_OFF);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "moviesize"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "ffhd"))
            {
                USE_MSG(("moviesize-ffhd\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_1080FHD].TextId = IDS_MOVIE_SIZE_1080FHD;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_1080FHD].IconId = IDI_MOVIE_SIZE_1080FHD;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "fhd"))
            {
                USE_MSG(("moviesize-fhd\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_1080P].TextId = IDS_MOVIE_SIZE_1080P;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_1080P].IconId = IDI_MOVIE_SIZE_1080P;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "hd"))
            {
                USE_MSG(("moviesize-hd\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_720P].TextId = IDS_MOVIE_SIZE_720P;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_720P].IconId = IDI_MOVIE_SIZE_720P;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "wvga"))
            {
                USE_MSG(("moviesize-wvga\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_WVGA].TextId = IDS_MOVIE_SIZE_WVGA;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_WVGA].IconId = IDI_MOVIE_SIZE_WVGA;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "vga"))
            {
                USE_MSG(("moviesize-vga\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_VGA].TextId = IDS_MOVIE_SIZE_VGA;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_VGA].IconId = IDI_MOVIE_SIZE_VGA;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "qvga"))
            {
                USE_MSG(("moviesize-qvga\r\n"));
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_QVGA].TextId = IDS_MOVIE_SIZE_QVGA;
                gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_QVGA].IconId = IDI_MOVIE_SIZE_QVGA;
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "photosize"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "15m"))
            {
                USE_MSG(("photosize-15m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_15M].TextId = IDS_PHOTO_SIZE_15M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_15M].IconId = IDI_PHOTO_SIZE_15M;

            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "14m"))
            {
                USE_MSG(("photosize-14m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_14M].TextId = IDS_PHOTO_SIZE_14M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_14M].IconId = IDI_PHOTO_SIZE_14M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "12m"))
            {
                USE_MSG(("photosize-12m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_12M].TextId = IDS_PHOTO_SIZE_12M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_12M].IconId = IDI_PHOTO_SIZE_12M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "10m"))
            {
                USE_MSG(("photosize-10m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_10M].TextId = IDS_PHOTO_SIZE_10M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_10M].IconId = IDI_PHOTO_SIZE_10M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "9m"))
            {
                USE_MSG(("photosize-9m\r\n"));
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "8m"))
            {
                USE_MSG(("photosize-8m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_8M].TextId = IDS_PHOTO_SIZE_8M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_8M].IconId = IDI_PHOTO_SIZE_8M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "7m169"))
            {
                USE_MSG(("photosize-7m9\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_7MHD].TextId = IDS_PHOTO_SIZE_7MHD;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_7MHD].IconId = IDI_PHOTO_SIZE_7MHD;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "7m"))
            {
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_7M].TextId = IDS_PHOTO_SIZE_7M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_7M].IconId = IDI_PHOTO_SIZE_7M;
                USE_MSG(("photosize-7m\r\n"));
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "5m"))
            {
                USE_MSG(("photosize-5m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_5M].TextId = IDS_PHOTO_SIZE_5M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_5M].IconId = IDI_PHOTO_SIZE_5M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "4m"))
            {
                USE_MSG(("photosize-4m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_4M].TextId = IDS_PHOTO_SIZE_4M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_4M].IconId = IDI_PHOTO_SIZE_4M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "3m"))
            {
                USE_MSG(("photosize-3m\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_3M].TextId = IDS_PHOTO_SIZE_3M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_3M].IconId = IDI_PHOTO_SIZE_3M;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2m169"))
            {
                USE_MSG(("photosize-2m9\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_2MHD].TextId = IDS_PHOTO_SIZE_2MHD;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_2MHD].IconId = IDI_PHOTO_SIZE_2MHD;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2m"))
            {
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_2M].TextId = IDS_PHOTO_SIZE_2M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_2M].IconId = IDI_PHOTO_SIZE_2M;
                USE_MSG(("photosize-2m\r\n"));
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "1.3m"))
            {
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_1M].TextId = IDS_PHOTO_SIZE_1M;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_1M].IconId = IDI_PHOTO_SIZE_1M;
                USE_MSG(("photosize-2m\r\n"));
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "vga"))
            {
                USE_MSG(("photosize-vgam\r\n"));
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_VGA].TextId = IDS_PHOTO_SIZE_VGA;
                gTM_OPTIONS_PHOTO_SIZE[PHOTO_SIZE_VGA].IconId = IDI_PHOTO_SIZE_VGA;
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "defaultmoviesize"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "ffhd"))
            {
                USE_MSG(("defaultmoviesize-ffhd\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_1080FHD);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "fhd"))
            {
                USE_MSG(("defaultmoviesize-fhd\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_1080P);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "hd"))
            {
                USE_MSG(("defaultmoviesize-hd\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_720P);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "wvga"))
            {
                USE_MSG(("defaultmoviesize-wvga\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_WVGA);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "vga"))
            {
                USE_MSG(("defaultmoviesize-vga\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_VGA);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "qvga"))
            {
                USE_MSG(("defaultmoviesize-qvga\r\n"));
                UI_SetMovieSizeDefaultIndex(MOVIE_SIZE_QVGA);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "ramphotosize"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "vga"))
            {
                USE_MSG(("ramphotosize-vga\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_VGA);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "1m"))
            {
                USE_MSG(("ramphotosize-1m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_1M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2m169"))
            {
                USE_MSG(("ramphotosize-2m169\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_2MHD);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "3m"))
            {
                USE_MSG(("ramphotosize-3m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_3M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "5m"))
            {
                USE_MSG(("ramphotosize-5m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_5M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "8m"))
            {
                USE_MSG(("ramphotosize-8m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_8M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "10m"))
            {
                USE_MSG(("ramphotosize-10m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_10M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "12m"))
            {
                USE_MSG(("ramphotosize-12m\r\n"));
                UI_SetRamSizeDefaultIndex(PHOTO_SIZE_12M);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "defaultphotosize"))
        {
            #if (UPDATE_CFG == UPDATE_CFG_YES)
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "vga"))
            {
                USE_MSG(("defaultphotosize-vga\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_VGA);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2m169"))
            {
                USE_MSG(("defaultphotosize-2m169\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_2MHD);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2m"))
            {
                USE_MSG(("defaultphotosize-2m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_2M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "3m"))
            {
                USE_MSG(("defaultphotosize-3m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_3M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "5m"))
            {
                USE_MSG(("defaultphotosize-5m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_5M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "7m169"))
            {
                USE_MSG(("defaultphotosize-7m169\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_7MHD);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "7m"))
            {
                USE_MSG(("defaultphotosize-7m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_7M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "8m"))
            {
                USE_MSG(("defaultphotosize-8m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_8M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "9m"))
            {
                USE_MSG(("defaultphotosize-9m\r\n"));
                //UI_SetSizeDefaultIndex(PHOTO_SIZE_10M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "10m"))
            {
                USE_MSG(("defaultphotosize-10m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_10M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "12m"))
            {
                USE_MSG(("defaultphotosize-12m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_12M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "14m"))
            {
                USE_MSG(("defaultphotosize-14m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_14M);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "15m"))
            {
                USE_MSG(("defaultphotosize-15m\r\n"));
                UI_SetSizeDefaultIndex(PHOTO_SIZE_15M);
            }
            #endif
        }

        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "language"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "en"))
            {
                USE_MSG(("language-en\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_EN].TextId = IDS_LANG_EN;
                gTM_OPTIONS_LANGUAGE[LANG_EN].IconId = IDI_LANG_EN;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "de"))
            {
                USE_MSG(("language-de\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_DE].TextId = IDS_LANG_DE;
                gTM_OPTIONS_LANGUAGE[LANG_DE].IconId = IDI_LANG_DE;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "es"))
            {
                USE_MSG(("language-es\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_ES].TextId = IDS_LANG_ES;
                gTM_OPTIONS_LANGUAGE[LANG_ES].IconId = IDI_LANG_ES;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "it"))
            {
                USE_MSG(("language-it\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_IT].TextId = IDS_LANG_IT;
                gTM_OPTIONS_LANGUAGE[LANG_IT].IconId = IDI_LANG_IT;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "du"))
            {
                USE_MSG(("language-du\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_DU].TextId = IDS_LANG_DU;
                gTM_OPTIONS_LANGUAGE[LANG_DU].IconId = IDI_LANG_DU;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "ru"))
            {
                USE_MSG(("language-ru\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_RU].TextId = IDS_LANG_RU;
                gTM_OPTIONS_LANGUAGE[LANG_RU].IconId = IDI_LANG_RU;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "pb"))
            {
                USE_MSG(("language-pb\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_PB].TextId = IDS_LANG_PB;
                gTM_OPTIONS_LANGUAGE[LANG_PB].IconId = IDI_LANG_PB;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "tu"))
            {
                USE_MSG(("language-tu\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_TU].TextId = IDS_LANG_TU;
                gTM_OPTIONS_LANGUAGE[LANG_TU].IconId = IDI_LANG_TU;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "fr"))
            {
                USE_MSG(("language-fr\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_FR].TextId = IDS_LANG_FR;
                gTM_OPTIONS_LANGUAGE[LANG_FR].IconId = IDI_LANG_FR;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "sc"))
            {
                USE_MSG(("language-sc\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_SC].TextId = IDS_LANG_SC;
                gTM_OPTIONS_LANGUAGE[LANG_SC].IconId = IDI_LANG_SC;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "tc"))
            {
                USE_MSG(("language-tc\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_TC].TextId = IDS_LANG_TC;
                gTM_OPTIONS_LANGUAGE[LANG_TC].IconId = IDI_LANG_TC;
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "jp"))
            {
                USE_MSG(("language-jp\r\n"));
                gTM_OPTIONS_LANGUAGE[LANG_JP].TextId = IDS_LANG_JP;
                gTM_OPTIONS_LANGUAGE[LANG_JP].IconId = IDI_LANG_JP;
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "defaultlanguage"))
        {
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "en"))
            {
                USE_MSG(("defaultlanguage-en\r\n"));
                UI_SetLanguageDefaultIndex(LANG_EN);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "fr"))
            {
                USE_MSG(("defaultlanguage-fr\r\n"));
                UI_SetLanguageDefaultIndex(LANG_FR);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "de"))
            {
                USE_MSG(("defaultlanguage-de\r\n"));
                UI_SetLanguageDefaultIndex(LANG_DE);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "es"))
            {
                USE_MSG(("defaultlanguage-es\r\n"));\
                UI_SetLanguageDefaultIndex(LANG_ES);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "ru"))
            {
                USE_MSG(("defaultlanguage-ru\r\n"));
                UI_SetLanguageDefaultIndex(LANG_RU);
            }
			if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "du"))
            {
                USE_MSG(("defaultlanguage-du\r\n"));
                UI_SetLanguageDefaultIndex(LANG_DU);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "pb"))
            {
                USE_MSG(("defaultlanguage-pb\r\n"));
                UI_SetLanguageDefaultIndex(LANG_PB);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "it"))
            {
                USE_MSG(("defaultlanguage-it\r\n"));
                UI_SetLanguageDefaultIndex(LANG_IT);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "tu"))
            {
                USE_MSG(("defaultlanguage-tu\r\n"));
                UI_SetLanguageDefaultIndex(LANG_TU);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "sc"))
            {
                USE_MSG(("defaultlanguage-sc\r\n"));
                UI_SetLanguageDefaultIndex(LANG_SC);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "tc"))
            {
                USE_MSG(("defaultlanguage-tc\r\n"));
                UI_SetLanguageDefaultIndex(LANG_TC);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yi"))
            {
                USE_MSG(("defaultlanguage-yi\r\n"));
                UI_SetLanguageDefaultIndex(LANG_YI);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "de_jay"))
            {
                USE_MSG(("defaultlanguage-de_jay\r\n"));
                UI_SetLanguageDefaultIndex(LANG_DE_JAY);
            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "jp"))
            {
                USE_MSG(("defaultlanguage-jp\r\n"));
                UI_SetLanguageDefaultIndex(LANG_JP);
            }
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "autopoweroff"))
               {
            
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("autopoweroff off\r\n"));
                       UI_SetAutoPowerOffDefaultIndex(AUTO_POWER_OFF_DISABLE);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "3min"))
                   {
                       USE_MSG(("autopoweroff 3min\r\n"));
                       UI_SetAutoPowerOffDefaultIndex(AUTO_POWER_OFF_3MIN);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "5min"))
                   {
                       USE_MSG(("autopoweroff 5min\r\n"));
                       UI_SetAutoPowerOffDefaultIndex(AUTO_POWER_OFF_5MIN);
                   }
                   
               }
               if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "lcdoff"))
               {
             
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("lcdoff off\r\n"));
                       UI_SetLcdOffDefaultIndex(LCD_AUTO_POWER_OFF_DISABLE);
                   }
                   
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "1min"))
                   {
                       USE_MSG(("lcdoff 1min\r\n"));
                       UI_SetLcdOffDefaultIndex(LCD_AUTO_POWER_OFF_1MIN);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "2min"))
                   {
                       USE_MSG(("lcdoff 2min\r\n"));
                       UI_SetLcdOffDefaultIndex(LCD_AUTO_POWER_OFF_2MIN);
                   }
               }
               if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "cyclicrec"))
               {
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "off"))
                   {
                       USE_MSG(("beep yes\r\n"));
                       UI_SetCyclicRecDefaultIndex(MOVIE_CYCLICREC_OFF);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "1min"))
                   {
                       USE_MSG(("beep yes\r\n"));
                       UI_SetCyclicRecDefaultIndex(MOVIE_CYCLICREC_1MIN);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "3min"))
                   {
                       USE_MSG(("beep yes\r\n"));
                       UI_SetCyclicRecDefaultIndex(MOVIE_CYCLICREC_3MIN);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "5min"))
                   {
                       USE_MSG(("beep no\r\n"));
                       UI_SetCyclicRecDefaultIndex(MOVIE_CYCLICREC_5MIN);
                   }
                  
               }
               if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "gsensor"))
               {
        
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("gsensor no\r\n"));
                       UI_SetGsensorDefaultIndex(GSENSOR_OFF);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "gl"))
                   {
                       USE_MSG(("gsensor low\r\n"));
                       UI_SetGsensorDefaultIndex(GSENSOR_LOW);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "gm"))
                   {
                       USE_MSG(("gsensor middle\r\n"));
                       UI_SetGsensorDefaultIndex(GSENSOR_NORMAL);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "gh"))
                   {
                       USE_MSG(("gsensor high\r\n"));
                       UI_SetGsensorDefaultIndex(GSENSOR_HIGH);
                   }
               }
               if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "parking"))
               {
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
                   {
                       USE_MSG(("parking on\r\n"));
                       UI_SetParkingDefaultIndex(MOVIE_PARKING_ON);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("parking off\r\n"));
                       UI_SetParkingDefaultIndex(MOVIE_PARKING_OFF);
                   }
               }
               //menu movie -end
               //menu setup -begin
               if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "beep"))
               {
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
                   {
                       USE_MSG(("beep yes\r\n"));
                       UI_SetBeepDefaultIndex(BEEP_ON);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("beep no\r\n"));
                       UI_SetBeepDefaultIndex(BEEP_OFF);
                   }
               }
		 //eric edit 0901 begin
		   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "SILENT"))
               {
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "yes"))
                   {
                       USE_MSG(("SILENT yes\r\n"));
                       UI_SetSilentDefaultIndex(SILENT_ON);
                   }
                   if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "no"))
                   {
                       USE_MSG(("SILENT no\r\n"));
                       UI_SetSilentDefaultIndex(SILENT_OFF);
                   }
               }
		    //eric edit 0901 end
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "lcdtype"))
        {

            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "wd_F4823V5"))
            {
                //Set_LcdtypeIndex(LCD_WD_F4823V5);
                //USE_MSG(("wd_F4823V5\r\n"));
                //USE_MSG(("Get_LcdtypeIndex()=%d\r\n",Get_LcdtypeIndex()));

            }
            if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN, "alt024csln"))
            {
                //Set_LcdtypeIndex(LCD_ALT024CSLN);
                //USE_MSG(("LCD_ALT024CSLN\r\n"));
                //USE_MSG(("Get_LcdtypeIndex()=%d\r\n",Get_LcdtypeIndex()));
            }
        }

        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "maker"))
        {

            USE_MSG(("maker:%s\r\n",SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN));
            strcpy(gUIConfigInfo.strMakerString,SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN);
        }

        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "model"))
        {

            USE_MSG(("model:%s\r\n",SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN));
            strcpy(gUIConfigInfo.strModelString,SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN);
        }

        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "version"))
        {

            USE_MSG(("verion:%s\r\n",SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN));
            strcpy(gUIConfigInfo.strSoftwareVer,SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN);
        }
        if (!strcmp(SysParam_Sector+i*KEY_VALUE_LEN, "ImageDescription"))
        {

            USE_MSG(("sImageDescription:%s\r\n",SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN));
            strcpy(gUIConfigInfo.strImageDescription,SysParam_Sector+i*KEY_VALUE_LEN+KEY_LEN);
        }

        i++;
    }

    return TRUE;
err_ret:

    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();
    return FALSE;
}


void UI_UpdateCfgFile(void)
{
    UINT32      uiKeyAct, uiKeyCode;
    FLGPTN     uiFlag;

    char*       str;
    HNVT_FILE   *pFile;
    UINT32      uiFileSize;
    UINT8       *BgBuf;
    char        *fileName;
    RECT      Rect = {0, 0, 320, 240};
    BOOL      Ret  =TRUE ;
    ER          erReturn;

    PSTORE_SECTION_HANDLE* pSecHdl; // to save the handle of PStore section

    fileName = "A:\\NTCONFIG.bin";

    FilesysWaitInitFinish(FST_TIME_INFINITE);
    FilesysWaitCmdFinish(FST_TIME_INFINITE);

    pFile = Filesys_fopen(fileName, "R");

    if (pFile == NULL)
    {
        debug_err(("open file error\r\n"));
        Ret  =FALSE;
    }

    uiFileSize = pFile->fileSize;     // for small page nand

    FilesysCloseActFile();

    USE_MSG(("file size = %d\r\n",uiFileSize));

    //if file is null
    if (uiFileSize == 0)
    {
        USE_MSG(("file size is 0\r\n"));
        Ret  =FALSE;
    }

    if (uiFileSize > CFG_MAX_FILESIZE)
    {
        USE_MSG(("file size is bigger = %d\r\n",uiFileSize));
        Ret  =FALSE;
    }

    //get_blk((void *)&BgBuf,  POOL_ID_SICD);
    //rel_blk(POOL_ID_SICD, BgBuf);
    SysGetSICDAddr((UINT32*)&BgBuf);

    FilesysReadWriteByName2(FST_CMD_READ_BY_NAME, fileName, (UINT8 *)(BgBuf+4),
                            &uiFileSize, 0, FST_TIME_INFINITE);
    FilesysWaitCmdFinish(FST_TIME_INFINITE);

    *BgBuf = LO_BYTE(LO_WORD(uiFileSize));
    *(BgBuf+1) = HI_BYTE(LO_WORD(uiFileSize));
    *(BgBuf+2) = LO_BYTE(HI_WORD(uiFileSize));
    *(BgBuf+3) = HI_BYTE(HI_WORD(uiFileSize));

    //PStore_EnablePS();
    pSecHdl = PStore_OpenSection(PS_BG_CFG, PS_RDWR | PS_CREATE);

    if (pSecHdl == E_PS_SECHDLER)
    {
        debug_err(("Section open fail\r\n"));
        PStore_CloseSection(pSecHdl);
        //PStore_DisablePS();
        Ret  =FALSE;
    }

    //erReturn = PStore_WriteSection(BgBuf, 0, uiFileSize+4, pSecHdl);
    erReturn = PStore_WriteSection(BgBuf, 0, SYSPARAM_SYSFLAG_LEN, pSecHdl);

    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();

    if (erReturn != E_PS_OK)
    {
        debug_err(("PStore program error\r\n"));
        Ret  =FALSE;
    }


    Cal_FillRect(&Rect, _OSD_INDEX_BLACK);

    Rect.uiLeft   = 56;
    Rect.uiTop    = 108;
    Rect.uiWidth  = 212;
    Rect.uiHeight = 24;

    if (Ret  == FALSE)
    {
        str =  "Update Cfg file error";
        Cal_ShowStringByColor(str, &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
    }else
    {
        str = "Update Cfg file ok";
        Cal_ShowStringByColor(str, &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
    }
    TimerDelayMs(1000);

    if (Ret)
    {
       KeyScan_PoweroffFlow();
    }

    /*while (1)
    {
        wai_flg(&uiFlag, FLG_ID_KEY, 0xffffffff, TWF_ORW | TWF_CLR);

        uiKeyAct = uiFlag & FLGKEY_ACT_MASK;
        uiKeyCode = uiFlag & FLGKEY_KEY_MASK;

        // check key
        if (uiKeyCode && uiKeyAct == FLGKEY_PRESSED)
            break;
    }*/
}

#define LOGO_MAX_FILESIZE   (SYSPARAM_LOGO_LEN-4)


BOOL UI_WriteLogoFileName(UINT32 logoId)
{
    HNVT_FILE   *pFile;
    UINT32      uiFileSize;
    UINT8       *BgBuf;
    char        *fileName;
    RECT      Rect = {0, 0, 320, 240};
    ER      erReturn = E_OK;
    PSTORE_SECTION_HANDLE* pSecHdl; // to save the handle of PStore section
    PS_SECNAME_ID secnameId;

    if (logoId == UI_LOGO_POWERON)
    {
        fileName = "A:\\logo.jpg";
        secnameId = PS_BG_LOGO;
    }
    else //if (logoId == UI_LOGO_POWEROFF)
    {
        fileName = "A:\\logo2.jpg";
        secnameId = PS_BG_LOGO2;
    }

    FilesysWaitInitFinish(FST_TIME_INFINITE);
    FilesysWaitCmdFinish(FST_TIME_INFINITE);

    pFile = Filesys_fopen(fileName, "R");

    if (pFile == NULL)
    {
        debug_err(("open file error\r\n"));
        return FALSE;
    }

    uiFileSize = pFile->fileSize;     // for small page nand

    FilesysCloseActFile();

    USE_MSG(("file size = %d\r\n",uiFileSize));

    //MBX_DrawMsgIdFixedPos(STRID_UpdateBG);
    if ((uiFileSize < 1024) || (uiFileSize > LOGO_MAX_FILESIZE))
    {
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        Cal_ShowStringByColor("jpg size is too big or too small\n", &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
        TimerDelayMs(2000);
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        debug_err(("Write logo error\n\r"));
        return FALSE;
    }

    //get_blk((void *)&BgBuf,  POOL_ID_SICD);
    //rel_blk(POOL_ID_SICD, BgBuf);
    SysGetSICDAddr((UINT32*)&BgBuf);

    FilesysReadWriteByName2(FST_CMD_READ_BY_NAME, fileName, (UINT8 *)(BgBuf+4),
                            &uiFileSize, 0, FST_TIME_INFINITE);
    FilesysWaitCmdFinish(FST_TIME_INFINITE);

    *BgBuf = LO_BYTE(LO_WORD(uiFileSize));
    *(BgBuf+1) = HI_BYTE(LO_WORD(uiFileSize));
    *(BgBuf+2) = LO_BYTE(HI_WORD(uiFileSize));
    *(BgBuf+3) = HI_BYTE(HI_WORD(uiFileSize));

    //PStore_EnablePS();
    //pSecHdl = PStore_OpenSection(PS_BG_LOGO, PS_RDWR | PS_CREATE);
    pSecHdl = PStore_OpenSection(secnameId, PS_RDWR | PS_CREATE);

    if (pSecHdl == E_PS_SECHDLER)
    {
        debug_err(("Section open fail\r\n"));
        goto err_ret;
    }

    erReturn = PStore_WriteSection(BgBuf, 0, SYSPARAM_LOGO_LEN, pSecHdl);

    if (erReturn != E_PS_OK)
    {
        debug_err(("PStore program error\r\n"));
        goto err_ret;
    }
    //#PIC#2010/07/23#Creator -begin
    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();
    //#PIC#2010/07/23#Creator -end
    return TRUE;

err_ret:
    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();
    return FALSE;
}

BOOL UI_ShowLogoFile(UINT32 logoId)
{
    UINT32      uiFileSize;
    UINT8       *BgBuf;
    ER          erReturn;
    PSTORE_SECTION_HANDLE* pSecHdl; // to save the handle of PStore section
    PS_SECNAME_ID psSectID;

    if (logoId == UI_LOGO_POWERON)
    {
        psSectID = PS_BG_LOGO;
    }
    else //if (logoId == UI_LOGO_POWEROFF)
    {
        psSectID = PS_BG_LOGO2;
    }

    //get_blk((void *)&BgBuf,  POOL_ID_SICD);
    //rel_blk(POOL_ID_SICD, BgBuf);
    SysGetSICDAddr((UINT32*)&BgBuf);


    //PStore_EnablePS();
    //pSecHdl = PStore_OpenSection(PS_BG_LOGO, PS_RDONLY);
    pSecHdl = PStore_OpenSection(psSectID, PS_RDONLY);

    if (pSecHdl == E_PS_SECHDLER)
    {
        debug_err(("Section PS_BG_LOGO open fail\r\n"));
        PStore_CloseSection(pSecHdl);
        //PStore_DisablePS();

        return FALSE;
    }

    erReturn = PStore_ReadSection(BgBuf, 0, 4, pSecHdl);

    if (erReturn != E_PS_OK)
    {
        debug_err(("PStore read error\r\n"));
    }
    uiFileSize = MAKE_LONG(MAKE_WORD(BgBuf[0],BgBuf[1]),MAKE_WORD(BgBuf[2],BgBuf[3]));

    USE_MSG(("UserPS_ShowLogoFile: logo uiFileSize %d\r\n",uiFileSize));
    //check file size logo size:  1k---20k
    if ((uiFileSize < 1024) || (uiFileSize > LOGO_MAX_FILESIZE))
    {
        USE_MSG(("Show logo error\n\r"));
        PStore_CloseSection(pSecHdl);
        //PStore_DisablePS();

        return FALSE;
    }
    erReturn = PStore_ReadSection(BgBuf, 0, (uiFileSize+4), pSecHdl);

    if (erReturn != E_PS_OK)
    {
        debug_err(("PStore read error\r\n"));
        PStore_CloseSection(pSecHdl);
        //PStore_DisablePS();
        return FALSE;
    }
    PStore_CloseSection(pSecHdl);
    //PStore_DisablePS();

    SysInit_DisplaySplashScreen(LOGO_CUSTOM,(UINT8 *)(BgBuf+4), uiFileSize);
    return TRUE;
}

void UI_UpdateLogoFile(void)
{
    UINT32    uiKeyAct, uiKeyCode;
    FLGPTN    uiFlag;
    RECT      Rect = {0, 0, 320, 240};
    BOOL      ret, ret2;

    ret  = UI_WriteLogoFileName(UI_LOGO_POWERON);
    ret2 = UI_WriteLogoFileName(UI_LOGO_POWEROFF);

    if (ret == TRUE)
    {
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        Cal_ShowStringByColor("Update bootup logo  OK!\n", &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
        TimerDelayMs(2000);
    }
    else
    {
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        Cal_ShowStringByColor("Update bootup logo  failed!\n", &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
        TimerDelayMs(2000);
    }

    if (ret2 == TRUE)
    {
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        Cal_ShowStringByColor("Update shutdown logo  OK!\n", &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
        TimerDelayMs(2000);
    }
    else
    {
        Cal_FillRect(&Rect, _OSD_INDEX_BLACK);
        Cal_ShowStringByColor("Update shutdown logo  failed!\n", &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
        TimerDelayMs(2000);
    }

    if (TRUE != KeyScan_CheckUpdateCfgTextFile())
    {
    		TimerDelayMs(1000);
		KeyScan_PoweroffFlow();
    }

    /*while (1)
    {
        wai_flg(&uiFlag, FLG_ID_KEY, 0xffffffff, TWF_ORW | TWF_CLR);

        uiKeyAct = uiFlag & FLGKEY_ACT_MASK;
        uiKeyCode = uiFlag & FLGKEY_KEY_MASK;

        // check key
        if (uiKeyCode && uiKeyAct == FLGKEY_PRESSED)
            break;
    }*/
}

/**
    Pause FAT system and get the access right to access the NAND flash.
*/
static BOOL NOR_GetAccessRight()
{

    #if (_PSTOREDEVICE_ == _PSTOREDEVICE_SPIFLASH_)
    PSTRG_TAB   pWhichObj;

    FilesysPause();
    FilesysWaitPaused();

    FilesysGetStrgObj(&pWhichObj);

    {
        if (pWhichObj != NULL && pWhichObj->CloseMemBus !=NULL)
        {
            pWhichObj->CloseMemBus();
        }
    }
    #endif
    return TRUE;
}

/**
    Release the access right to NAND flash and resume the FAT system.
*/
static BOOL NOR_ReleaseAccessRight()
{
    #if (_PSTOREDEVICE_ == _PSTOREDEVICE_SPIFLASH_)
    PSTRG_TAB   pWhichObj;

    FilesysGetStrgObj(&pWhichObj);

    //#Fix the crash probelm when using MS card and want to save Pstore settings
    if (pWhichObj != NULL && pWhichObj->OpenMemBus !=NULL)
    {
            pWhichObj->OpenMemBus();
    }

    FilesysResume();
    #endif
    return TRUE;
}

//#PIC#Creator 20090518--end

#define SECTOR_LEN  0X1000
#define NOR_LEN  0X200000  //2*1024*1024

static BOOL SPI_ReadAllNorFlash(void)
{
    ER eReturn;
    UINT32 i;
    UINT32 uiPoolAddr;
    UINT8  *tmpbuf;
    UINT32 buffsize = NOR_LEN;
    BOOL ret = FALSE;

    get_blk((VP *)&uiPoolAddr, POOL_ID_CAPTURE);
    rel_blk(POOL_ID_CAPTURE, (VP)uiPoolAddr);

    tmpbuf = (UINT8 *)uiPoolAddr;

    NOR_GetAccessRight();
    nor_open();

    //eReturn = nor_readByBytes(0,buffsize,(UINT8 *)tmpbuf);
    for(i=0;i<NOR_LEN;i=i+SECTOR_LEN)
    {
        eReturn = nor_readByBytes(i,SECTOR_LEN,(UINT8 *)(tmpbuf+i));
        if (eReturn == FALSE)
        {
            //Cal_PStoreOutString("read error!");
        }
    }
    if (eReturn == FALSE)
    {
        debug_err(("SPI_ReadAllNorFlash!\r\n"));
        goto err_ret;
    }
    nor_close();
    NOR_ReleaseAccessRight();

    FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,"A:\\NORFLASH.bin", (UINT8 *)tmpbuf,&buffsize, 0, FST_TIME_INFINITE);
    ret = TRUE;
    return ret;

err_ret:
    nor_close();

    NOR_ReleaseAccessRight();

    return ret;
}

void UI_ReadNorFlash(void)
{
    UINT32      uiKeyAct, uiKeyCode;
    FLGPTN     uiFlag;
    char*       str;

    RECT    Rect = {0, 0, 320, 240};

    Cal_FillRect(&Rect, _OSD_INDEX_BLACK);

    Rect.uiLeft   = 56;
    Rect.uiTop    = 80;
    Rect.uiWidth  = 212;
    Rect.uiHeight = 24;

    if (FALSE == SPI_ReadAllNorFlash())
    {
        str = "ReadAllNorFlash error";
        Cal_ShowStringByColor(str, &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
    }else
    {
        str = "ReadAllNorFlash ok";
        Cal_ShowStringByColor(str, &Rect, _OSD_INDEX_YELLOW, _OSD_INDEX_BLACK);
    }

    while (1)
    {
        wai_flg(&uiFlag, FLG_ID_KEY, 0xffffffff, TWF_ORW | TWF_CLR);

        uiKeyAct = uiFlag & FLGKEY_ACT_MASK;
        uiKeyCode = uiFlag & FLGKEY_KEY_MASK;

        // check key
        if (uiKeyCode && uiKeyAct == FLGKEY_PRESSED)
            break;
    }
}
