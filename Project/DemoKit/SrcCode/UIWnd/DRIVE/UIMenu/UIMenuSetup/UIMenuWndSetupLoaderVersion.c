//This source code is generated by UI Designer Studio.

#include <stdio.h>
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndSetupLoaderVersionRes.c"
#include "UIMenuWndSetupLoaderVersion.h"
#include "UIMenuWndSetupVersion.h"
#include "MenuCommonItem.h"
#include "UISystemObj.h"

//---------------------UIMenuWndSetupLoaderVersionCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupLoaderVersion)
CTRL_LIST_ITEM(UIMenuSetupLoaderNameText)
CTRL_LIST_ITEM(UIMenuSetupFWNameText)
CTRL_LIST_ITEM(UIMenuSetupLoaderVersionText)
CTRL_LIST_ITEM(UIMenuSetupBuildDateText)
CTRL_LIST_ITEM(UIMenuSetupBuildTimeText)
CTRL_LIST_END

//----------------------UIMenuWndSetupLoaderVersionCtrl Event---------------------------
INT32 UIMenuWndSetupLoaderVersion_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLoaderVersion_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupLoaderVersion)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndSetupLoaderVersion_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndSetupLoaderVersion_OnClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndSetupLoaderVersion_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIMenuWndSetupLoaderVersion_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndSetupLoaderVersion_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndSetupLoaderVersion_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndSetupLoaderVersion_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndSetupLoaderVersion_OnKeyShutter2)
EVENT_END

static char g_LoaderName[32];
static char g_FWName[32];
static char g_LoaderVersion[32];
static char g_BuildDate[32];
static char g_BuildTime[32];

INT32 UIMenuWndSetupLoaderVersion_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    PBLINFO_OBJ pLoaderInfo = Get_BLInfo();

    memset(&g_LoaderName[0], 0, sizeof(g_LoaderName));
    sprintf(&g_LoaderName[0], "LD Name: %s", pLoaderInfo->strBLName);
    UxStatic_SetData(&UIMenuSetupLoaderNameTextCtrl, STATIC_VALUE, Txt_Pointer(&g_LoaderName[0]));

    memset(&g_FWName[0], 0, sizeof(g_FWName));
    sprintf(&g_FWName[0], "FW Name: %s", pLoaderInfo->strFWName);
    UxStatic_SetData(&UIMenuSetupFWNameTextCtrl, STATIC_VALUE, Txt_Pointer(&g_FWName[0]));

    memset(&g_LoaderVersion[0], 0, sizeof(g_LoaderVersion));
    sprintf(&g_LoaderVersion[0], "LD Version: %s", pLoaderInfo->strBLVer);
    UxStatic_SetData(&UIMenuSetupLoaderVersionTextCtrl, STATIC_VALUE, Txt_Pointer(&g_LoaderVersion[0]));

    memset(&g_BuildDate[0], 0, sizeof(g_BuildDate));
    sprintf(&g_BuildDate[0], "LD Date: %s", pLoaderInfo->strBLDate);
    UxStatic_SetData(&UIMenuSetupBuildDateTextCtrl, STATIC_VALUE, Txt_Pointer(&g_BuildDate[0]));

    memset(&g_BuildTime[0], 0, sizeof(g_BuildTime));
    sprintf(&g_BuildTime[0], "LD Time: %s", pLoaderInfo->strBLTime);
    UxStatic_SetData(&UIMenuSetupBuildTimeTextCtrl, STATIC_VALUE, Txt_Pointer(&g_BuildTime[0]));

    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndSetupVersionCtrl, 0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndSetupVersionCtrl, 0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&MenuCommonItemCtrl,0); // close whole tab menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_CHANGE_DSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLoaderVersion_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
//----------------------UIMenuSetupLoaderNameTextCtrl Event---------------------------
EVENT_BEGIN(UIMenuSetupLoaderNameText)
EVENT_END

//----------------------UIMenuSetupFWNameTextCtrl Event---------------------------
EVENT_BEGIN(UIMenuSetupFWNameText)
EVENT_END

//----------------------UIMenuSetupLoaderVersionTextCtrl Event---------------------------
EVENT_BEGIN(UIMenuSetupLoaderVersionText)
EVENT_END

//----------------------UIMenuSetupBuildDateTextCtrl Event---------------------------
EVENT_BEGIN(UIMenuSetupBuildDateText)
EVENT_END

//----------------------UIMenuSetupBuildTimeTextCtrl Event---------------------------
EVENT_BEGIN(UIMenuSetupBuildTimeText)
EVENT_END

