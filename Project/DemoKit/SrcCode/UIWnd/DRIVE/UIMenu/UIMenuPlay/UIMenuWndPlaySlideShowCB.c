//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPlaySlideShowCBRes.c"
#include "UIMenuWndPlaySlideShowCB.h"
#include "UIFlowWndPlay.h"
#include "UIPlayObj.h"
#include "UIFlowPlayFuncs.h"
#include "UIMenuWndPlaySlideShow.h"
#include "UISystemObj.h"
#include "MenuCommonItem.h"
#include "PlaybackTsk.h"

typedef enum {
  Playback_FileFmt_JPG,
  Playback_FileFmt_VIDEO,
} Playback_FileFmt;

//---------------------UIMenuWndPlaySlideShowCBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySlideShowCB)
CTRL_LIST_END

//----------------------UIMenuWndPlaySlideShowCBCtrl Event---------------------------
INT32 UIMenuWndPlaySlideShowCB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnSlideKeep(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySlideShowCB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPlaySlideShowCB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPlaySlideShowCB_OnClose)
EVENT_ITEM(NVTEVT_CB_SLIDE_KEEP,UIMenuWndPlaySlideShowCB_OnSlideKeep)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPlaySlideShowCB_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPlaySlideShowCB_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPlaySlideShowCB_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPlaySlideShowCB_OnKeyShutter2)
EVENT_END


static void UIMEnuWndPlaySlideShowCB_SetFileFmt(Playback_FileFmt PB_FileFmt)
{
 PPLAY_OBJ   pPlayObj;
 UINT        PBFileFmt;

    // get playback object
    pPlayObj = PB_GetPBObject();

    FilesysWaitCmdFinish(FST_TIME_INFINITE);
    //step1. close current active file
    FilesysCloseActFile();
    //step2. rescan file format
    switch(PB_FileFmt)
    {
      case Playback_FileFmt_JPG:
      default:
        PBFileFmt = FST_FMT_JPG;
        pPlayObj->usPlayFileFormat = PLAYFMT_JPG;
        break;
      case Playback_FileFmt_VIDEO:
#if (_WAVSTUDIO_MODE_ == ENABLE)
        PBFileFmt = FST_FMT_JPG|FST_FMT_AVI|FST_FMT_WAV;
        pPlayObj->usPlayFileFormat = PLAYFMT_JPG | PLAYFMT_WAV | PLAYFMT_AVI;
#else
        PBFileFmt = FST_FMT_JPG|FST_FMT_AVI;
        pPlayObj->usPlayFileFormat = PLAYFMT_JPG | PLAYFMT_AVI;
#endif
        break;
    }
    FilesysSetValidFileFormat(PBFileFmt);
    FilesysScanDCFObj();

    // slide show only for jpg file format
    PB_SetPBObject(pPlayObj);
    PB_WaitCommandFinish(PB_WAIT_INFINITE);

}
INT32 UIMenuWndPlaySlideShowCB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/03#Chris Chung -begin
    UINT32 uiSlideInterval;
    PPLAY_OBJ   pPlayObj;

    if (paramNum == 1)
    {
        uiSlideInterval = paramArray[0];
    }
    else
    {
        uiSlideInterval = 2000; // default slide show time interval is 2sec
    }

    UIMEnuWndPlaySlideShowCB_SetFileFmt(Playback_FileFmt_JPG);
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYINIT,0);

    if (UIPlay_GetData(PLAY_FILENUM) > 0)
    {
        // play next if current file format is video
        while (UIPlay_GetData(PLAY_FILEFORMAT)&PLAYFMT_AVI)
        {
           Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYNEXT,0);
        }
        if (UIPlay_GetData(PLAY_FILEFORMAT)&PLAYFMT_JPG)
        {
           UIPlay_SetData(PLAY_SLIDERTIME,uiSlideInterval);
           Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDEINIT,1,&FlowPB_SliderCBFunc);
        }
    } else {
            Ux_PostEvent(NVTEVT_KEY_ENTER,1,NVTEVT_KEY_PRESS);
    }
    //#NT#2009/08/03#Chris Chung -end
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnSlideKeep(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDEKEEP,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDESTOP,0);
    // restore for all legal playback file formats
    UIMEnuWndPlaySlideShowCB_SetFileFmt(Playback_FileFmt_VIDEO);

    Ux_CloseWindow(&UIMenuWndPlaySlideShowCBCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UIMEnuWndPlaySlideShowCB_SetFileFmt(Playback_FileFmt_VIDEO);
    Ux_CloseWindow(&MenuCommonItemCtrl,0); // close whole tab menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_CHANGE_DSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}