//This source code is generated by UI Designer Studio.

#include <stdio.h>
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPlaySetDPOFRes.c"
#include "UIMenuWndPlaySetDPOF.h"
#include "UIPlayObj.h"
#include "UIMenuWndPlayDPOF.h"
#include "Utility.h"
#include "UISystemStatusSettings.h"
#include "UISystemObj.h"
#include "MenuCommonItem.h"
#include "UIFlow.h"

#define  UI_DPOF_MAX_NUM    99
#define  UI_DPOF_MIN_NUM     0

static UINT32   g_u32DPOFAll = 0;
static UINT32   g_u32OriDPOFNum = 0;
static UINT32   g_u32TempDPOFNum = 0;
static char     item1_Buf[32] = "00";

//---------------------UIMenuWndPlaySetDPOFCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySetDPOF)
CTRL_LIST_ITEM(UIMenuWndPlaySetDPOF_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPlaySetDPOFCtrl Event---------------------------
INT32 UIMenuWndPlaySetDPOF_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySetDPOF)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPlaySetDPOF_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPlaySetDPOF_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndPlaySetDPOF_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPlaySetDPOF_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPlaySetDPOF_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPlaySetDPOF_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPlaySetDPOF_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/05#Chris Chung -begin
    if(paramNum > 0)
    {
        g_u32DPOFAll = paramArray[0];
    }
    else
    {
        UIPLAY_ERR(("UIMenuWndPlaySetDPOF_OnOpen: param error\r\n"));
    }

    g_u32TempDPOFNum = g_u32OriDPOFNum = UIPlay_GetData(PLAY_DPOFQTY);

    snprintf(item1_Buf, 32, "%2ld", g_u32TempDPOFNum);

    UxButton_SetItemData(&UIMenuWndPlaySetDPOF_ButtonCtrl, 0, BTNITM_STRID, Txt_Pointer(item1_Buf));
    //#NT#2009/08/05#Chris Chung -end
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_RedrawAllWind();
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&MenuCommonItemCtrl,0); // close whole tab menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_CHANGE_DSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPlaySetDPOF_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySetDPOF_Panel)
CTRL_LIST_ITEM(UIMenuWndPlaySetDPOF_Button)
CTRL_LIST_ITEM(UIMenuWndPlaySetDPOF_Static)
CTRL_LIST_ITEM(UIMenuWndPlaySetDPOF_Static2)
CTRL_LIST_END

//----------------------UIMenuWndPlaySetDPOF_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlaySetDPOF_Panel)
EVENT_END

//----------------------UIMenuWndPlaySetDPOF_ButtonCtrl Event---------------------------
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyEnter(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySetDPOF_Button)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPlaySetDPOF_Button_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPlaySetDPOF_Button_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPlaySetDPOF_Button_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIMenuWndPlaySetDPOF_Button_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPlaySetDPOF_Button_OnKeyEnter)
EVENT_END

//#NT#2009/08/20#Chris Chung -begin
static INT32 UIMenuWndPlaySetDPOF_SaveDPOF(void)
{
    if(g_u32TempDPOFNum != g_u32OriDPOFNum)
    {
        if(UI_Validate_Storage(STORAGE_CHECK_LOCKED, NULL) == FALSE)
        {
            Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,FLOWWRNMSG_ISSUE_CARD_LOCKED,FLOWWRNMSG_TIMER_2SEC);
            return -1;
        }
        if(UI_Validate_Storage(STORAGE_CHECK_SPACE_FULL, NULL) == FALSE)
        {
            Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,FLOWWRNMSG_ISSUE_CARD_FULL,FLOWWRNMSG_TIMER_2SEC);
            return -1;
        }
        if(UIPlay_GetData(PLAY_CURRMODE) != PLAYMODE_PRIMARY)
        {
            Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,FLOWWRNMSG_ISSUE_NOT_JPEG,FLOWWRNMSG_TIMER_2SEC);
            return -1;
        }

        Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_EXE_DPOF,3,g_u32DPOFAll,g_u32TempDPOFNum,0);
    }

    return 0;
}
//#NT#2009/08/20#Chris Chung -end

INT32 UIMenuWndPlaySetDPOF_Button_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/05#Chris Chung -begin
    if(g_u32TempDPOFNum < UI_DPOF_MAX_NUM)
    {
        g_u32TempDPOFNum++;

        snprintf(item1_Buf, 32, "%2ld", g_u32TempDPOFNum);

        UxButton_SetItemData(&UIMenuWndPlaySetDPOF_ButtonCtrl, 0, BTNITM_STRID, Txt_Pointer(item1_Buf));
    }
    //#NT#2009/08/05#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/05#Chris Chung -begin
    static char item1_Buf[32] = "00";

    if(g_u32TempDPOFNum > UI_DPOF_MIN_NUM)
    {
        g_u32TempDPOFNum--;

        snprintf(item1_Buf, 32, "%2ld", g_u32TempDPOFNum);

        UxButton_SetItemData(&UIMenuWndPlaySetDPOF_ButtonCtrl, 0, BTNITM_STRID, Txt_Pointer(item1_Buf));
    }
    //#NT#2009/08/05#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/20#Chris Chung -begin
    /* Save DPOF */
    if(UIMenuWndPlaySetDPOF_SaveDPOF() != 0)
        return NVTEVT_CONSUME;

    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYPREV,0);

    g_u32TempDPOFNum = g_u32OriDPOFNum = UIPlay_GetData(PLAY_DPOFQTY);

    snprintf(item1_Buf, 32, "%2ld", g_u32TempDPOFNum);

    UxButton_SetItemData(&UIMenuWndPlaySetDPOF_ButtonCtrl, 0, BTNITM_STRID, Txt_Pointer(item1_Buf));
    //#NT#2009/08/20#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/20#Chris Chung -begin
    /* Save DPOF */
    if(UIMenuWndPlaySetDPOF_SaveDPOF() != 0)
        return NVTEVT_CONSUME;

    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYNEXT,0);

    g_u32TempDPOFNum = g_u32OriDPOFNum = UIPlay_GetData(PLAY_DPOFQTY);

    snprintf(item1_Buf, 32, "%2ld", g_u32TempDPOFNum);

    UxButton_SetItemData(&UIMenuWndPlaySetDPOF_ButtonCtrl, 0, BTNITM_STRID, Txt_Pointer(item1_Buf));
    //#NT#2009/08/20#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySetDPOF_Button_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/20#Chris Chung -begin
    /* Save DPOF */
    if(UIMenuWndPlaySetDPOF_SaveDPOF() != 0)
        return NVTEVT_CONSUME;

    Ux_CloseWindow(&UIMenuWndPlayDPOFCtrl,0);
    //#NT#2009/08/20#Chris Chung -end

    return NVTEVT_CONSUME;
}
//----------------------UIMenuWndPlaySetDPOF_StaticCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlaySetDPOF_Static)
EVENT_END

//----------------------UIMenuWndPlaySetDPOF_Static2Ctrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlaySetDPOF_Static2)
EVENT_END

