#include <stdio.h>
#include "UIFlow.h"
#include "GPIOMapping.h"
#include "UIMenuWndSetupCarNumConfirm.h"
#include "UIMenuWndSetupCommonCarNumber.h"
// --------------------------------------------------------------------------
// OPTIONS
// --------------------------------------------------------------------------
// Power Saving Options
TMDEF_BEGIN_OPTIONS(AUTO_POWER_OFF)
    TMDEF_OPTION_TEXT(OFF)
    TMDEF_OPTION_TEXT(3MIN)
    TMDEF_OPTION_TEXT(5MIN)
TMDEF_END_OPTIONS()


// Beep Options
TMDEF_BEGIN_OPTIONS(BEEP)
    TMDEF_OPTION_TEXT(BEEP_OFF)
    TMDEF_OPTION_TEXT(BEEP_ON)
TMDEF_END_OPTIONS()


// Led Options
TMDEF_BEGIN_OPTIONS(LED_SETTING)
    TMDEF_OPTION_TEXT(SILENT_OFF)
    TMDEF_OPTION_TEXT(SILENT_ON)
TMDEF_END_OPTIONS()
// Language Options
#if (UPDATE_CFG == UPDATE_CFG_YES)
TM_OPTION gTM_OPTIONS_LANGUAGE[LANG_ID_MAX] = {0};
#else
TMDEF_BEGIN_OPTIONS(LANGUAGE)
    TMDEF_OPTION_TEXT(LANG_EN)
    TMDEF_OPTION_TEXT(LANG_FR)
    TMDEF_OPTION_TEXT(LANG_ES)
    TMDEF_OPTION_TEXT(LANG_PO)
    TMDEF_OPTION_TEXT(LANG_DE)
    TMDEF_OPTION_TEXT(LANG_IT)
    TMDEF_OPTION_TEXT(LANG_SC)
    TMDEF_OPTION_TEXT(LANG_TC)
    TMDEF_OPTION_TEXT(LANG_RU)
    TMDEF_OPTION_TEXT(LANG_JP)
    TMDEF_OPTION_TEXT(LANG_KR)
TMDEF_END_OPTIONS()
#endif

// TV Mode Options
TMDEF_BEGIN_OPTIONS(TV_MODE)
    TMDEF_OPTION_TEXT(TV_PAL)
    TMDEF_OPTION_TEXT(TV_NTSC)
TMDEF_END_OPTIONS()


// Frequency Options
TMDEF_BEGIN_OPTIONS(FREQUENCY)
    TMDEF_OPTION_TEXT(50HZ)
    TMDEF_OPTION_TEXT(60HZ)
TMDEF_END_OPTIONS()

// Sensor Rotate Options
TMDEF_BEGIN_OPTIONS(SENSOR_ROTATE)
    TMDEF_OPTION_TEXT(SENSOR_ROTATE_OFF)
    TMDEF_OPTION_TEXT(SENSOR_ROTATE_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(PLATENUMBER)
    TMDEF_OPTION_TEXT(PLATENUMBER_OFF)
    TMDEF_OPTION_TEXT(PLATENUMBER_ON)
TMDEF_END_OPTIONS()

// LCD AUTO OFF Options
TMDEF_BEGIN_OPTIONS(LCD_AUTOOFF)
    TMDEF_OPTION_TEXT(LCD_AUTOOFF_OFF)
    TMDEF_OPTION_TEXT(LCD_AUTOOFF_1MIN)
    TMDEF_OPTION_TEXT(LCD_AUTOOFF_2MIN)
TMDEF_END_OPTIONS()
    
// POWER OFF DELAY Options
TMDEF_BEGIN_OPTIONS(POWEROFF_DELAY)
    TMDEF_OPTION_TEXT(POWEROFF_DELAY_OFF)
    TMDEF_OPTION_TEXT(POWEROFF_DELAY_1MIN)
    TMDEF_OPTION_TEXT(POWEROFF_DELAY_2MIN)
    TMDEF_OPTION_TEXT(POWEROFF_DELAY_3MIN)
    TMDEF_OPTION_TEXT(POWEROFF_DELAY_5MIN) 
TMDEF_END_OPTIONS()

// --------------------------------------------------------------------------
// ITEMS
// --------------------------------------------------------------------------
static int MenuCustom_DateTime(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupDateTimeCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_Format(UINT32 uiMessage, UINT32 uiParam)
{
    //Ux_OpenWindow(&UIMenuWndSetupFormatCtrl, 0);
    Ux_OpenWindow(&UIMenuWndSetupFormatConfirmCtrl, 0);
	
    return TMF_PROCESSED;
}

static int MenuCustom_Default(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupDefaultSettingCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_Version(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupVersionCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_PlateNumber(UINT32 uiMessage, UINT32 uiParam)
{
    //Ux_OpenWindow(&UIMenuWndSetupCarNumCtrl, 0);
    Ux_OpenWindow(&UIMenuWndSetupCarNumConfirmCtrl, 0);
    return TMF_PROCESSED;
}

// Setup Menu Items
TMDEF_BEGIN_ITEMS(SETUP)
    TMDEF_ITEM_CUSTOM(DATE_TIME, MenuCustom_DateTime)
    TMDEF_ITEM_TEXTID(AUTO_POWER_OFF)
    TMDEF_ITEM_TEXTID(BEEP)
    //TMDEF_ITEM_TEXTID(LED_SETTING)
    TMDEF_ITEM_TEXTID(LANGUAGE)
    TMDEF_ITEM_TEXTID(TV_MODE)
    TMDEF_ITEM_TEXTID(FREQUENCY)
    TMDEF_ITEM_TEXTID(LCD_AUTOOFF)
    TMDEF_ITEM_TEXTID(SENSOR_ROTATE)//ERIC EDIT 0901
    //TMDEF_ITEM_CUSTOM(PLATENUMBER, MenuCustom_PlateNumber)
    //TMDEF_ITEM_TEXTID(PLATENUMBER)//henry 20150422
    TMDEF_ITEM_CUSTOM(FORMAT, MenuCustom_Format)
    TMDEF_ITEM_CUSTOM(DEFAULT, MenuCustom_Default)
    //TMDEF_ITEM_TEXTID(POWEROFF_DELAY)    
    TMDEF_ITEM_CUSTOM(VERSION, MenuCustom_Version)
TMDEF_END_ITEMS()

// --------------------------------------------------------------------------
// Menu Callback
// --------------------------------------------------------------------------
int Setup_MenuCallback(UINT32 uiMessage, UINT32 uiParam)
{
    UINT16  uwItemId;
    UINT16  uwOption;

    if (uiMessage == TMM_CONFIRM_OPTION)
    {
        uwItemId = LO_WORD(uiParam);
        uwOption = HI_WORD(uiParam);

        switch (uwItemId)
        {
        case IDM_AUTO_POWER_OFF:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_POWEROFF, 1, uwOption);
            break;

        case IDM_BEEP:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_BEEP, 1, uwOption);
            break;

        case IDM_LED_SETTING:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_LEDLIGHT, 1, uwOption);
            break;
			
        case IDM_LANGUAGE:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_LANGUAGE, 1, uwOption);
            break;

        case IDM_TV_MODE:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_TVMODE, 1, uwOption);
            break;

        case IDM_FREQUENCY:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_FREQ, 1, uwOption);
            break;

        case IDM_SENSOR_ROTATE:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_SENSOR_ROTATE, 1, uwOption);
            break;

        case IDM_OPENING_LOGO:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_OPENING, 1, uwOption);
            break;
       			
        case IDM_LCD_AUTOOFF:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_LCD_AUTOOFF, 1, uwOption);
            break;	

	case IDM_PLATENUMBER:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_CAR_NUMBER, 1, uwOption);
            break;	
			
        case IDM_POWEROFF_DELAY:
            Ux_SendEvent(&UISystemObjCtrl, NVTEVT_EXE_POWEROFF_DELAY, 1, uwOption);
            break;				
        }
    }

    return TMF_PROCESSED;
}
