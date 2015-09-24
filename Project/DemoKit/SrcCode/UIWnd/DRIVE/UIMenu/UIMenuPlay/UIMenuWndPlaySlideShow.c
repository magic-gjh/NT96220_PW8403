//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPlaySlideShowRes.c"
#include "UIMenuWndPlaySlideShow.h"
#include "UIMenuWndPlaySlideShowCB.h"
#include "UISystemObj.h"
#include "MenuCommonItem.h"

//---------------------UIMenuWndPlaySlideShowCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySlideShow)
CTRL_LIST_ITEM(UIMenuWndPlaySlideShow_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPlaySlideShowCtrl Event---------------------------
INT32 UIMenuWndPlaySlideShow_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySlideShow)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPlaySlideShow_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPlaySlideShow_OnClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPlaySlideShow_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPlaySlideShow_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPlaySlideShow_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPlaySlideShow_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPlaySlideShow_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UxMenu_SetData(&UIMenuWndPlaySlideShow_MenuCtrl, MNU_CURITM, 0);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPlaySlideShowCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&MenuCommonItemCtrl,0); // close whole tab menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_CHANGE_DSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPlaySlideShow_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySlideShow_Panel)
CTRL_LIST_ITEM(UIMenuWndPlaySlideShow_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPlaySlideShow_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlaySlideShow_Panel)
EVENT_END

//----------------------UIMenuWndPlaySlideShow_MenuCtrl Event---------------------------
INT32 UIMenuWndPlaySlideShow_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShow_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySlideShow_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPlaySlideShow_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPlaySlideShow_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPlaySlideShow_Menu_OnKeyEnter)
EVENT_END

INT32 UIMenuWndPlaySlideShow_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShow_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/03#Chris Chung -begin
    UINT32 uiTimeInterval;

    switch (UxMenu_GetData(pCtrl,MNU_CURITM))
    {
    case UIMenuWndPlaySlideShow_Menu_STRID_5SEC:
        uiTimeInterval = 5000;
        break;
    case UIMenuWndPlaySlideShow_Menu_STRID_8SEC:
        uiTimeInterval = 8000;
        break;
    case UIMenuWndPlaySlideShow_Menu_STRID_2SEC:
    default:
        uiTimeInterval = 2000;
        break;
    }

    Ux_OpenWindow(&UIMenuWndPlaySlideShowCBCtrl,1,uiTimeInterval);
    //#NT#2009/08/03#Chris Chung -end
    return NVTEVT_CONSUME;
}
