//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDUSBRES_H
#define UIMENUWNDUSBRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,319,239,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Skin2Rect,0,0,295,169,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(Skin2Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,295,169)

SHOW_MAP_BEGIN(UIMenuWndUSB_Background)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_Background)
DECLARE_CTRL_LIST(UIMenuWndUSB_Background)
CREATE_CTRL(UIMenuWndUSB_Background,UIMenuWndUSB_Background,CTRL_WND,NULL,0 ,12,44,307,213)
SHOW_ITEM_IMAGE(CMD_Image,Image4, 118, 0, 178,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image5, 176, 0, 236,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image6, 235, 0, 295,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image7, 0, 0, 60,39, ICON_MENU_SETUP_ON,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image8, 60, 0, 120,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Image4)
SHOW_MAP_BODY(Image5)
SHOW_MAP_BODY(Image6)
SHOW_MAP_BODY(Image7)
SHOW_MAP_BODY(Image8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,295,39)

SHOW_ITEM_IMAGE(CMD_Image,Image11, 2, 0, 48,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image12, 48, 0, 94,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_BODY(Image11)
SHOW_MAP_BODY(Image12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,108,39)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text14,6,6,99,30,STRID_NULL,0,0,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Text14)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal9,197,5,305,44)

CREATE_STATE_ITEM_DATA(STRID_USB15,STRID_USB,ICONID_NULL,NULL)
SHOW_MAP_BEGIN(UIMenuWndUSB_TitleName)
SHOW_MAP_BODY(Normal9)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_TitleName)
STATE_LIST_BEGIN(UIMenuWndUSB_TitleName)
STATE_LIST_ITEM(STRID_USB15)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndUSB_TitleName,0)
CREATE_STATE_CTRL(UIMenuWndUSB_TitleName,0,185,0,293,39)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndUSB_TitleBar)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_TitleBar)
DECLARE_CTRL_LIST(UIMenuWndUSB_TitleBar)
CREATE_CTRL(UIMenuWndUSB_TitleBar,UIMenuWndUSB_TitleBar,CTRL_WND,NULL,0 ,12,5,307,44)
SHOW_ITEM_IMAGE(CMD_Image,Image17, 0, 0, 31,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image18, 31, 0, 62,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image19, 62, 0, 93,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image20, 93, 0, 124,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image21, 124, 0, 155,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image22, 155, 0, 186,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image23, 186, 0, 217,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image24, 217, 0, 248,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image25, 248, 0, 279,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image26, 264, 0, 295,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin16)
SHOW_MAP_BODY(Image17)
SHOW_MAP_BODY(Image18)
SHOW_MAP_BODY(Image19)
SHOW_MAP_BODY(Image20)
SHOW_MAP_BODY(Image21)
SHOW_MAP_BODY(Image22)
SHOW_MAP_BODY(Image23)
SHOW_MAP_BODY(Image24)
SHOW_MAP_BODY(Image25)
SHOW_MAP_BODY(Image26)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin16,0,0,295,22)

SHOW_ITEM_IMAGE(CMD_Image,Image28, 14, 5, 28,24, ICON_DIR_UP,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image29, 31, 6, 45,22, ICON_DIR_DOWN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image30, 68, 2, 82,18, ICON_OK,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin27)
SHOW_MAP_BODY(Image28)
SHOW_MAP_BODY(Image29)
SHOW_MAP_BODY(Image30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin27,0,0,110,27)

SHOW_MAP_BEGIN(UIMenuWndUSB_UDOKTips)
SHOW_MAP_BODY(Skin27)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_UDOKTips)
DECLARE_CTRL_LIST(UIMenuWndUSB_UDOKTips)
CREATE_CTRL(UIMenuWndUSB_UDOKTips,UIMenuWndUSB_UDOKTips,CTRL_WND,NULL,0 ,148,0,258,27)
SHOW_MAP_BEGIN(UIMenuWndUSB_TipsBar)
SHOW_MAP_BODY(Skin16)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_TipsBar)
DECLARE_CTRL_LIST(UIMenuWndUSB_TipsBar)
CREATE_CTRL(UIMenuWndUSB_TipsBar,UIMenuWndUSB_TipsBar,CTRL_WND,NULL,0 ,12,214,307,236)
SHOW_ITEM_RECT(CMD_Rectangle,Skin32Rect,0,0,284,40,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin32)
SHOW_MAP_BODY(Skin32Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin32,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon33, 6, 5, 33,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text35,40,7,284,31,STRID_NULL,0,0,0,0,2,1,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal31)
SHOW_MAP_BODY(Skin32)
SHOW_MAP_BODY(Icon33)
SHOW_MAP_BODY(Text35)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal31,18,49,302,89)

SHOW_ITEM_IMAGE(CMD_Image,Image38, 0, 5, 32,36, ICON_SEL_BAR_BEGIN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image39, 32, 5, 64,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image40, 64, 5, 96,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image41, 96, 5, 128,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image42, 126, 5, 158,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image43, 157, 5, 189,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image44, 189, 5, 221,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image45, 220, 5, 252,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image46, 252, 5, 284,36, ICON_SEL_BAR_END,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin37Rect,0,0,284,40,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin37)
SHOW_MAP_BODY(Skin37Rect)
SHOW_MAP_BODY(Image38)
SHOW_MAP_BODY(Image39)
SHOW_MAP_BODY(Image40)
SHOW_MAP_BODY(Image41)
SHOW_MAP_BODY(Image42)
SHOW_MAP_BODY(Image43)
SHOW_MAP_BODY(Image44)
SHOW_MAP_BODY(Image45)
SHOW_MAP_BODY(Image46)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin37,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon47, 6, 5, 34,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text49,40,7,284,31,STRID_NULL,0,0,0,0,14,5,0,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused36)
SHOW_MAP_BODY(Skin37)
SHOW_MAP_BODY(Icon47)
SHOW_MAP_BODY(Text49)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused36,18,49,302,89)

SHOW_ITEM_RECT(CMD_Rectangle,Skin51Rect,0,0,284,40,0,0,98,98,0,0,0)
SHOW_MAP_BEGIN(Skin51)
SHOW_MAP_BODY(Skin51Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin51,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon52, 6, 5, 34,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text54,40,7,284,31,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable50)
SHOW_MAP_BODY(Skin51)
SHOW_MAP_BODY(Icon52)
SHOW_MAP_BODY(Text54)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable50,18,49,302,89)

SHOW_ITEM_RECT(CMD_Rectangle,Skin56Rect,0,0,284,40,0,0,98,98,0,0,0)
SHOW_MAP_BEGIN(Skin56)
SHOW_MAP_BODY(Skin56Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin56,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon57, 6, 5, 34,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text59,40,7,284,31,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable55)
SHOW_MAP_BODY(Skin56)
SHOW_MAP_BODY(Icon57)
SHOW_MAP_BODY(Text59)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable55,18,49,302,89)

SHOW_MAP_BEGIN(Skin61)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin61,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon62, 6, 5, 34,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text64,40,7,284,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed60)
SHOW_MAP_BODY(Skin61)
SHOW_MAP_BODY(Icon62)
SHOW_MAP_BODY(Text64)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed60,18,49,302,89)

CREATE_MENU_ITEM_DATA(STRID_MSDC65,STRID_MSDC,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_PCC66,STRID_PCC,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_RECORD67,STRID_RECORD,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndUSB_Item)
SHOW_MAP_BODY(Normal31)
SHOW_MAP_BODY(Focused36)
SHOW_MAP_BODY(Normal_Disable50)
SHOW_MAP_BODY(Focused_Disable55)
SHOW_MAP_BODY(Pressed60)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB_Item)
MENU_LIST_BEGIN(UIMenuWndUSB_Item)
MENU_LIST_ITEM(STRID_MSDC65)
MENU_LIST_ITEM(STRID_PCC66)
MENU_LIST_ITEM(STRID_RECORD67)
MENU_LIST_END

CREATE_MENU_DATA(UIMenuWndUSB_Item,0,3,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_CYCLE|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|MENU_DRAW_IMAGE)

CREATE_MENU_CTRL(UIMenuWndUSB_Item,UIMenuWndUSB_Item,0,18,49,302,89)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndUSB)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndUSB)
DECLARE_CTRL_LIST(UIMenuWndUSB)
CREATE_CTRL(UIMenuWndUSB,UIMenuWndUSB,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
