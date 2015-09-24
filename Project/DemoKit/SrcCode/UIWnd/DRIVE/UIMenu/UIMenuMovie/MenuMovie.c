#include <stdio.h>
#include "UIFlow.h"

// --------------------------------------------------------------------------
// OPTIONS
// --------------------------------------------------------------------------
// Movie Size Options
#if (UPDATE_CFG == UPDATE_CFG_YES)
TM_OPTION gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_ID_MAX] = {0};
#else
    TMDEF_BEGIN_OPTIONS(MOVIE_SIZE)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_1080FHD)
    //TMDEF_OPTION_TEXT(MOVIE_SIZE_1080P)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_720P)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_WVGA)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_VGA)
    //TMDEF_OPTION_TEXT(MOVIE_SIZE_QVGA)
TMDEF_END_OPTIONS()
#endif


// Cyclic recroding Options
TMDEF_BEGIN_OPTIONS(MOVIE_EV)
    TMDEF_OPTION_TEXT(MOVIE_EV_P20)
    TMDEF_OPTION_TEXT(MOVIE_EV_P16)
    TMDEF_OPTION_TEXT(MOVIE_EV_P13)
    TMDEF_OPTION_TEXT(MOVIE_EV_P10)
    TMDEF_OPTION_TEXT(MOVIE_EV_P06)
    TMDEF_OPTION_TEXT(MOVIE_EV_P03)
    TMDEF_OPTION_TEXT(MOVIE_EV_00)
    TMDEF_OPTION_TEXT(MOVIE_EV_N03)
    TMDEF_OPTION_TEXT(MOVIE_EV_N06)
    TMDEF_OPTION_TEXT(MOVIE_EV_N10)
    TMDEF_OPTION_TEXT(MOVIE_EV_N13)
    TMDEF_OPTION_TEXT(MOVIE_EV_N16)
    TMDEF_OPTION_TEXT(MOVIE_EV_N20)
TMDEF_END_OPTIONS()

// Cyclic recroding Options
TMDEF_BEGIN_OPTIONS(MOVIE_LOOP_REC)
    TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_OFF)
    TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_1MIN)
    //TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_2MIN)    
    TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_3MIN)
    TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_5MIN)
    //TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_10MIN)
    //TMDEF_OPTION_TEXT(MOVIE_LOOP_REC_15MIN)    
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_MOTION_DET)
    TMDEF_OPTION_TEXT(MOVIE_MOTION_DET_OFF)
    TMDEF_OPTION_TEXT(MOVIE_MOTION_DET_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_AUDIO)
    TMDEF_OPTION_TEXT(MOVIE_AUDIO_OFF)
    TMDEF_OPTION_TEXT(MOVIE_AUDIO_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_DATEIMPRINT)
    TMDEF_OPTION_TEXT(MOVIE_DATEIMPRINT_OFF)
    TMDEF_OPTION_TEXT(MOVIE_DATEIMPRINT_ON)
TMDEF_END_OPTIONS()

// Gsensor Rotate Options
TMDEF_BEGIN_OPTIONS(GSENSOR)
    TMDEF_OPTION_TEXT(GSENSOR_OFF)
    TMDEF_OPTION_TEXT(GSENSOR_LOW)
    TMDEF_OPTION_TEXT(GSENSOR_NORMAL)
    TMDEF_OPTION_TEXT(GSENSOR_HIGH)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_TIMESHRINK)
    TMDEF_OPTION_TEXT(MOVIE_TIMESHRINK_OFF)
    TMDEF_OPTION_TEXT(MOVIE_TIMESHRINK_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_PARKING)
    TMDEF_OPTION_TEXT(MOVIE_PARKING_OFF)
    TMDEF_OPTION_TEXT(MOVIE_PARKING_ON)
TMDEF_END_OPTIONS()
// --------------------------------------------------------------------------
// ITEMS
// --------------------------------------------------------------------------
// Movie Menu Items
TMDEF_BEGIN_ITEMS(MOVIE)
    TMDEF_ITEM_TEXTID(MOVIE_SIZE)
    TMDEF_ITEM_TEXTID(MOVIE_LOOP_REC)
    TMDEF_ITEM_TEXTID(MOVIE_EV)
    TMDEF_ITEM_TEXTID(MOVIE_MOTION_DET)
    TMDEF_ITEM_TEXTID(MOVIE_AUDIO)
    TMDEF_ITEM_TEXTID(MOVIE_DATEIMPRINT)
#if (_GSENSOR_FUNC_ == ENABLE)
    TMDEF_ITEM_TEXTID(GSENSOR)
#endif
    TMDEF_ITEM_TEXTID(MOVIE_TIMESHRINK)
    TMDEF_ITEM_TEXTID(MOVIE_PARKING)
TMDEF_END_ITEMS()

// --------------------------------------------------------------------------
// PAGES
// --------------------------------------------------------------------------
// Movie Menu Pages
TMDEF_BEGIN_PAGES(MOVIE)
    TMDEF_PAGE_TEXT_ICON(MOVIE)
    TMDEF_PAGE_TEXT_ICON(SETUP)
TMDEF_END_PAGES()

TMDEF_EMNU(gMovieMenu, MOVIE, Movie_MenuCallback)

// --------------------------------------------------------------------------
// Menu Callback
// --------------------------------------------------------------------------
int Movie_MenuCallback(UINT32 uiMessage, UINT32 uiParam)
{
    UINT16  uwItemId;
    UINT16  uwOption;

    if (uiMessage == TMM_CONFIRM_OPTION)
    {
        uwItemId = LO_WORD(uiParam);
        uwOption = HI_WORD(uiParam);

        switch (uwItemId)
        {
        case IDM_MOVIE_SIZE:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_MOVIESIZE, 1, uwOption);
            break;

        case IDM_MOVIE_QUALITY:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_QUALITY, 1, uwOption);
            break;

        case IDM_MOVIE_EV:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_EV, 1, uwOption);
            break;

        case IDM_MOVIE_LOOP_REC:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_CYCLIC_REC, 1, uwOption);
            break;

        case IDM_MOVIE_MOTION_DET:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_MOTION_DET, 1, uwOption);
            break;

        case IDM_MOVIE_AUDIO:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_VIDEO_AUDIO, 1, uwOption);
            break;

        case IDM_MOVIE_DATEIMPRINT:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_DATEIMPRINT, 1, uwOption);
            break;

	 case IDM_GSENSOR:
            Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_GSENSOR, 1, uwOption);
            break;

	case IDM_MOVIE_PARKING:
	     Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_MOVIEPARKING, 1, uwOption);
            break;
			
	case IDM_MOVIE_TIMESHRINK:
		Ux_SendEvent(&UIMovieObjCtrl, NVTEVT_EXE_MOVIETIMESHRINK, 1, uwOption);
		break;
        default:
            Setup_MenuCallback(uiMessage, uiParam);
            break;
        }
    }

    return TMF_PROCESSED;
}
