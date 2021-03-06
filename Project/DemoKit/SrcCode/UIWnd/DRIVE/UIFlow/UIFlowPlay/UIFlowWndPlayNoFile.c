//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIFlowWndPlayNoFileRes.c"
#include "PrimaryTsk.h"
#include "UIFlow.h"

//---------------------UIFlowWndPlayNoFileCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayNoFile)
CTRL_LIST_ITEM(UIFlowWndPlayNoFile_StaticTxt_NoFile)
CTRL_LIST_END

//----------------------UIFlowWndPlayNoFileCtrl Event---------------------------
INT32 UIFlowWndPlayNoFile_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnKeyPlayback(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnBattery(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnStorageInit(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayNoFile_OnStorageChange(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndPlayNoFile)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndPlayNoFile_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndPlayNoFile_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIFlowWndPlayNoFile_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_MODE,UIFlowWndPlayNoFile_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_PLAYBACK,UIFlowWndPlayNoFile_OnKeyPlayback)
EVENT_ITEM(NVTEVT_BATTERY,UIFlowWndPlayNoFile_OnBattery)
EVENT_ITEM(NVTEVT_STORAGE_INIT,UIFlowWndPlayNoFile_OnStorageInit)
EVENT_ITEM(NVTEVT_STORAGE_CHANGE,UIFlowWndPlayNoFile_OnStorageChange)
EVENT_END

INT32 UIFlowWndPlayNoFile_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    if (KeyScan_IsHDMIPlugIn() == TRUE)
    {
        return NVTEVT_CONSUME;
    }

    uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        if (Primary_GetCurrentMode() == PRIMARY_MODE_PLAYBACK)
        {
            Primary_ChangeMode(PRIMARY_MODE_MOVIE);
        }
        break;
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_MODE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnKeyPlayback(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_PLAYBACK,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnBattery(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnStorageInit(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayNoFile_OnStorageChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndPlayNoFile_StaticTxt_NoFileCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayNoFile_StaticTxt_NoFile)
EVENT_END

