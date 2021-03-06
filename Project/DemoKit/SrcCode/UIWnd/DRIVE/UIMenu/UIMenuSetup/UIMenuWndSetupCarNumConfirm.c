//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndSetupCarNumConfirmRes.c"
#include "UIMenuWndSetupCarNumConfirm.h"
#include "UIMenuWndSetupCommonCarNumber.h"
#include "UIFlow.h"
//---------------------UIMenuWndSetupCarNumConfirmCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupCarNumConfirm)
CTRL_LIST_ITEM(UIMenuWndSetupCarNumConfirm_Panel)
CTRL_LIST_END

//----------------------UIMenuWndSetupCarNumConfirmCtrl Event---------------------------
INT32 UIMenuWndSetupCarNumConfirm_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupCarNumConfirm_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupCarNumConfirm_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupCarNumConfirm_OnChildClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupCarNumConfirm)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndSetupCarNumConfirm_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndSetupCarNumConfirm_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndSetupCarNumConfirm_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndSetupCarNumConfirm_OnKeyMenu)
EVENT_END

INT32 UIMenuWndSetupCarNumConfirm_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UxMenu_SetData(&UIMenuWndSetupCarNumConfirmCtrl, MNU_CURITM, SysGetFlag(FL_PLATENUMBER));
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupCarNumConfirm_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}

INT32 UIMenuWndSetupCarNumConfirm_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndSetupCarNumConfirmCtrl, 0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupCarNumConfirm_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndSetupCarNumConfirm_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupCarNumConfirm_Panel)
CTRL_LIST_ITEM(UIMenuWndSetupCarNumConfirm_menu)
CTRL_LIST_END

//----------------------UIMenuWndSetupCarNumConfirm_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndSetupCarNumConfirm_Panel)
EVENT_END

//----------------------UIMenuWndSetupCarNumConfirm_menuCtrl Event---------------------------
INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupCarNumConfirm_menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndSetupCarNumConfirm_menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndSetupCarNumConfirm_menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndSetupCarNumConfirm_menu_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
        break;
    }
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
        break;
    }
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupCarNumConfirm_menu_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        if(UxList_GetData(pCtrl,LST_CURITM)==UIMenuWndSetupCarNumConfirm_menu_STRID_ON)
        {
            SysSetFlag(FL_PLATENUMBER,PLATENUMBER_ON);
	     Ux_OpenWindow(&UIMenuWndSetupCommonCarNumberCtrl, 1, 0);
            /*if (SysGetFlag(FL_LANGUAGE) == LANG_SC) 
            {
                Ux_OpenWindow(&UIMenuWndSetupCarNumberCtrl, 1, 0);
            }
            else
            {
                Ux_OpenWindow(&UIMenuWndSetupCommonCarNumberCtrl, 1, 0);
            }*/
        }
        else
        {
            SysSetFlag(FL_PLATENUMBER,PLATENUMBER_OFF);
            Ux_CloseWindow(&UIMenuWndSetupCarNumConfirmCtrl, 0);
        }
        break;
    }
    return NVTEVT_CONSUME;
}
