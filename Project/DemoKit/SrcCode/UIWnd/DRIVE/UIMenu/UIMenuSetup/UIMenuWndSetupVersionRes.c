//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDSETUPVERSIONRES_H
#define UIMENUWNDSETUPVERSIONRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Rect3,56,50,304,208,272,0,5,255,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Rect3)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_MAP_BEGIN(Skin5)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin5,0,0,219,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text7,0,0,219,27,STRID_NULL,0,0,0,0,2,0,0,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal4)
SHOW_MAP_BODY(Skin5)
SHOW_MAP_BODY(Text7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal4,70,90,289,117)

SHOW_MAP_BEGIN(UIMenuSetupVersionText)
SHOW_MAP_BODY(Normal4)
SHOW_MAP_END

DECLARE_EVENT(UIMenuSetupVersionText)
CREATE_STATIC_DATA(UIMenuSetupVersionText,STRID_MODE)
CREATE_STATIC_CTRL(UIMenuSetupVersionText,0,70,90,289,117)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,219,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text12,0,0,219,27,STRID_NULL,0,0,0,0,2,0,0,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Text12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal9,70,120,289,147)

SHOW_MAP_BEGIN(UIMenuSetupVersionText2)
SHOW_MAP_BODY(Normal9)
SHOW_MAP_END

DECLARE_EVENT(UIMenuSetupVersionText2)
CREATE_STATIC_DATA(UIMenuSetupVersionText2,STRID_MODE)
CREATE_STATIC_CTRL(UIMenuSetupVersionText2,0,70,120,289,147)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndSetupVersion)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupVersion)
DECLARE_CTRL_LIST(UIMenuWndSetupVersion)
CREATE_CTRL(UIMenuWndSetupVersion,UIMenuWndSetupVersion,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
