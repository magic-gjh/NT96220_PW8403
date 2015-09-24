//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDMOVIERES_H
#define UIFLOWWNDMOVIERES_H

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

SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,29,29)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon4, 1, 1, 11,15, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Icon4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,12,5,41,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_camera)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_camera)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_camera,ICON_MODE_VIDEO)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_camera,0,12,5,41,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin7Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin7)
SHOW_MAP_BODY(Skin7Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin7,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon8, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal6)
SHOW_MAP_BODY(Skin7)
SHOW_MAP_BODY(Icon8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal6,12,38,39,65)

CREATE_STATE_ITEM_DATA(ICONID_NULL9,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_1MIN10,STRID_NULL,ICON_CYCLIC_REC_1MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_3MIN11,STRID_NULL,ICON_CYCLIC_REC_3MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_5MIN12,STRID_NULL,ICON_CYCLIC_REC_5MIN,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_CyclicRec)
SHOW_MAP_BODY(Normal6)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_ITEM(ICONID_NULL9)
STATE_LIST_ITEM(ICON_CYCLIC_REC_1MIN10)
STATE_LIST_ITEM(ICON_CYCLIC_REC_3MIN11)
STATE_LIST_ITEM(ICON_CYCLIC_REC_5MIN12)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_CyclicRec,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_CyclicRec,0,12,38,39,65)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin17Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin17)
SHOW_MAP_BODY(Skin17Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin17,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon18, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal16)
SHOW_MAP_BODY(Skin17)
SHOW_MAP_BODY(Icon18)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal16,12,71,39,98)

CREATE_STATE_ITEM_DATA(ICONID_NULL19,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_REC20,STRID_NULL,ICON_FLASH_REC,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MotionDet)
SHOW_MAP_BODY(Normal16)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_ITEM(ICONID_NULL19)
STATE_LIST_ITEM(ICON_FLASH_REC20)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MotionDet,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MotionDet,0,12,71,39,98)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin22Rect,0,0,33,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin22)
SHOW_MAP_BODY(Skin22Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin22,0,0,33,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon23, 0, -1, 31,26, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal21)
SHOW_MAP_BODY(Skin22)
SHOW_MAP_BODY(Icon23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal21,276,208,309,235)

CREATE_STATE_ITEM_DATA(ICON_BATTERY_FULL24,STRID_NULL,ICON_BATTERY_FULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_MED25,STRID_NULL,ICON_BATTERY_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_LOW26,STRID_NULL,ICON_BATTERY_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_EMPTY27,STRID_NULL,ICON_BATTERY_EMPTY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_ZERO28,STRID_NULL,ICON_BATTERY_ZERO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_CHARGE29,STRID_NULL,ICON_BATTERY_CHARGE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_battery)
SHOW_MAP_BODY(Normal21)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_battery)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_battery)
STATE_LIST_ITEM(ICON_BATTERY_FULL24)
STATE_LIST_ITEM(ICON_BATTERY_MED25)
STATE_LIST_ITEM(ICON_BATTERY_LOW26)
STATE_LIST_ITEM(ICON_BATTERY_EMPTY27)
STATE_LIST_ITEM(ICON_BATTERY_ZERO28)
STATE_LIST_ITEM(ICON_BATTERY_CHARGE29)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_battery,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_battery,0,276,208,309,235)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin31Rect,0,0,120,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin31)
SHOW_MAP_BODY(Skin31Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin31,0,0,120,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text33,2,-1,119,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal30)
SHOW_MAP_BODY(Skin31)
SHOW_MAP_BODY(Text33)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal30,56,214,176,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_YMD_Static)
SHOW_MAP_BODY(Normal30)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_YMD_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_YMD_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_YMD_Static,0,56,214,176,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin36Rect,0,0,86,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin36)
SHOW_MAP_BODY(Skin36Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin36,0,0,86,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text38,1,2,84,18,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal35)
SHOW_MAP_BODY(Skin36)
SHOW_MAP_BODY(Text38)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal35,182,214,268,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_HMS_Static)
SHOW_MAP_BODY(Normal35)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_HMS_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_HMS_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_HMS_Static,0,182,214,268,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_ELLIPSE(CMD_Ellipse,Ellipse42,0,1,17,16,16,0,0,3,0,0,0)
SHOW_MAP_BEGIN(Skin40)
SHOW_MAP_BODY(Ellipse42)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin40,0,0,17,17)

SHOW_MAP_BEGIN(UIFlowWndMovie_Panel)
SHOW_MAP_BODY(Skin40)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Panel)
DECLARE_CTRL_LIST(UIFlowWndMovie_Panel)
CREATE_CTRL(UIFlowWndMovie_Panel,UIFlowWndMovie_Panel,CTRL_WND,NULL,0 ,52,11,69,28)
SHOW_ITEM_RECT(CMD_Rectangle,Skin44Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin44)
SHOW_MAP_BODY(Skin44Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin44,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon45, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal43)
SHOW_MAP_BODY(Skin44)
SHOW_MAP_BODY(Icon45)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal43,280,170,307,197)

CREATE_STATE_ITEM_DATA(ICON_INTERNAL_FLASH46,STRID_NULL,ICON_INTERNAL_FLASH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_CARD47,STRID_NULL,ICON_SD_CARD,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_LOCK48,STRID_NULL,ICON_SD_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_Storage)
SHOW_MAP_BODY(Normal43)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_Storage)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_Storage)
STATE_LIST_ITEM(ICON_INTERNAL_FLASH46)
STATE_LIST_ITEM(ICON_SD_CARD47)
STATE_LIST_ITEM(ICON_SD_LOCK48)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_Storage,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_Storage,0,280,170,307,197)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin50Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin50)
SHOW_MAP_BODY(Skin50Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin50,0,0,97,29)

//SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text52,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,17,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text52,0,0,97,29,STRID_NULL,0,1280,0,0,3,1,1,0,0,18,0,0,0,0)//18right //17middle
SHOW_MAP_BEGIN(Normal49)
SHOW_MAP_BODY(Skin50)
SHOW_MAP_BODY(Text52)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal49,210,5,307,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_time)
SHOW_MAP_BODY(Normal49)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_time)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_time,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_time,0,210,5,307,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin55Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin55)
SHOW_MAP_BODY(Skin55Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin55,0,0,97,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text57,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,1,0,0,18,0,0,0,0)//18right //17middle
SHOW_MAP_BEGIN(Normal54)
SHOW_MAP_BODY(Skin55)
SHOW_MAP_BODY(Text57)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal54,210,5,307,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_maxtime)
SHOW_MAP_BODY(Normal54)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_maxtime)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_maxtime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_maxtime,0,210,5,307,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin60Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin60)
SHOW_MAP_BODY(Skin60Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin60,0,0,97,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text62,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal59)
SHOW_MAP_BODY(Skin60)
SHOW_MAP_BODY(Text62)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal59,210,40,307,69)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_resolution)
SHOW_MAP_BODY(Normal59)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_resolution)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_resolution,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_resolution,0,210,40,307,69)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin65Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin65)
SHOW_MAP_BODY(Skin65Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin65,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text67,0,0,59,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal64)
SHOW_MAP_BODY(Skin65)
SHOW_MAP_BODY(Text67)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal64,76,168,135,195)

SHOW_MAP_BEGIN(UIFlowWndMovie_Zoom_Static)
SHOW_MAP_BODY(Normal64)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Zoom_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_Zoom_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Zoom_Static,0,76,168,135,195)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin70Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin70)
SHOW_MAP_BODY(Skin70Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin70,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon71, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal69)
SHOW_MAP_BODY(Skin70)
SHOW_MAP_BODY(Icon71)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal69,12,104,39,131)

CREATE_STATE_ITEM_DATA(ICON_EV_P2P072,STRID_NULL,ICON_EV_P2P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P673,STRID_NULL,ICON_EV_P1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P374,STRID_NULL,ICON_EV_P1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P075,STRID_NULL,ICON_EV_P1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P676,STRID_NULL,ICON_EV_P0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P377,STRID_NULL,ICON_EV_P0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P078,STRID_NULL,ICON_EV_P0P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P379,STRID_NULL,ICON_EV_M0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P680,STRID_NULL,ICON_EV_M0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P081,STRID_NULL,ICON_EV_M1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P382,STRID_NULL,ICON_EV_M1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P683,STRID_NULL,ICON_EV_M1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M2P084,STRID_NULL,ICON_EV_M2P0,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_EV)
SHOW_MAP_BODY(Normal69)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_ITEM(ICON_EV_P2P072)
STATE_LIST_ITEM(ICON_EV_P1P673)
STATE_LIST_ITEM(ICON_EV_P1P374)
STATE_LIST_ITEM(ICON_EV_P1P075)
STATE_LIST_ITEM(ICON_EV_P0P676)
STATE_LIST_ITEM(ICON_EV_P0P377)
STATE_LIST_ITEM(ICON_EV_P0P078)
STATE_LIST_ITEM(ICON_EV_M0P379)
STATE_LIST_ITEM(ICON_EV_M0P680)
STATE_LIST_ITEM(ICON_EV_M1P081)
STATE_LIST_ITEM(ICON_EV_M1P382)
STATE_LIST_ITEM(ICON_EV_M1P683)
STATE_LIST_ITEM(ICON_EV_M2P084)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_EV,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_EV,0,12,104,39,131)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin86Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin86)
SHOW_MAP_BODY(Skin86Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin86,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon87, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal85)
SHOW_MAP_BODY(Skin86)
SHOW_MAP_BODY(Icon87)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal85,160,5,187,32)

CREATE_STATE_ITEM_DATA(ICON_IRLED_OFF88,STRID_NULL,ICON_IRLED_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_IRLED_ON89,STRID_NULL,ICON_IRLED_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_LedLight)
SHOW_MAP_BODY(Normal85)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_LedLight)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_LedLight)
STATE_LIST_ITEM(ICON_IRLED_OFF88)
STATE_LIST_ITEM(ICON_IRLED_ON89)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_LedLight,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_LedLight,0,160,5,187,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin91Rect,0,0,19,23,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin91)
SHOW_MAP_BODY(Skin91Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin91,0,0,19,23)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon92, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal90)
SHOW_MAP_BODY(Skin91)
SHOW_MAP_BODY(Icon92)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal90,14,137,34,160)

CREATE_STATE_ITEM_DATA(ICON_VOICE_OFF93,STRID_NULL,ICON_VOICE_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOICE_ON94,STRID_NULL,ICON_VOICE_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MovieAudio)
SHOW_MAP_BODY(Normal90)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MovieAudio)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MovieAudio)
STATE_LIST_ITEM(ICON_VOICE_OFF93)
STATE_LIST_ITEM(ICON_VOICE_ON94)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MovieAudio,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MovieAudio,0,14,137,34,160)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin96Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin96)
SHOW_MAP_BODY(Skin96Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin96,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon97, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal95)
SHOW_MAP_BODY(Skin96)
SHOW_MAP_BODY(Icon97)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal95,75,5,102,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL98,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_LOCK99,STRID_NULL,ICON_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_LOCK)
SHOW_MAP_BODY(Normal95)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_LOCK)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_LOCK)
STATE_LIST_ITEM(ICONID_NULL98)
STATE_LIST_ITEM(ICON_LOCK99)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_LOCK,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_LOCK,0,75,5,102,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin101Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin101)
SHOW_MAP_BODY(Skin101Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin101,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon102, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal100)
SHOW_MAP_BODY(Skin101)
SHOW_MAP_BODY(Icon102)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal100,88,4,115,31)

CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL0103,STRID_NULL,ICON_GPS_LEVEL0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL1104,STRID_NULL,ICON_GPS_LEVEL1,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL2105,STRID_NULL,ICON_GPS_LEVEL2,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL3106,STRID_NULL,ICON_GPS_LEVEL3,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GPS)
SHOW_MAP_BODY(Normal100)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GPS)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GPS)
STATE_LIST_ITEM(ICON_GPS_LEVEL0103)
STATE_LIST_ITEM(ICON_GPS_LEVEL1104)
STATE_LIST_ITEM(ICON_GPS_LEVEL2105)
STATE_LIST_ITEM(ICON_GPS_LEVEL3106)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GPS,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GPS,0,88,4,115,31)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin107Rect,0,0,39,25,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin107)
SHOW_MAP_BODY(Skin107Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin107,0,0,39,25)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon108, 0, 0, 39,25, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal106)
SHOW_MAP_BODY(Skin107)
SHOW_MAP_BODY(Icon108)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal106,161,7,200,32)

CREATE_STATE_ITEM_DATA(ICON_GSENSOR_OFF109,STRID_NULL,ICON_GSENSOR_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_L110,STRID_NULL,ICON_GSENSOR_L,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_M111,STRID_NULL,ICON_GSENSOR_M,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_H112,STRID_NULL,ICON_GSENSOR_H,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GSENSOR)
SHOW_MAP_BODY(Normal106)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_ITEM(ICON_GSENSOR_OFF109)
STATE_LIST_ITEM(ICON_GSENSOR_L110)
STATE_LIST_ITEM(ICON_GSENSOR_M111)
STATE_LIST_ITEM(ICON_GSENSOR_H112)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GSENSOR,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GSENSOR,0,161,7,200,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin138Rect,0,0,28,28,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin138)
SHOW_MAP_BODY(Skin138Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin138,0,0,28,28)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon139, 0, 0, 28,28, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal137)
SHOW_MAP_BODY(Skin138)
SHOW_MAP_BODY(Icon139)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal137,280,135,308,163)

CREATE_STATE_ITEM_DATA(ICONID_NULL140,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_MENU_PARK141,STRID_NULL,ICON_MENU_PARK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_Parking)
SHOW_MAP_BODY(Normal137)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_Parking)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_Parking)
STATE_LIST_ITEM(ICONID_NULL140)
STATE_LIST_ITEM(ICON_MENU_PARK141)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_Parking,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_Parking,0,280,135,308,163)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
SHOW_ITEM_RECT(CMD_Rectangle,Skin143Rect,0,0,28,28,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin143)
SHOW_MAP_BODY(Skin143Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin143,0,0,28,28)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon144, 0, 0, 28,28, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal142)
SHOW_MAP_BODY(Skin143)
SHOW_MAP_BODY(Icon144)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal142,107,5,135,33)

CREATE_STATE_ITEM_DATA(ICONID_NULL145,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_DATE_TIME146,STRID_NULL,ICON_DATE_TIME,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_SHRINK)
SHOW_MAP_BODY(Normal142)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_SHRINK)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_SHRINK)
STATE_LIST_ITEM(ICONID_NULL145)
STATE_LIST_ITEM(ICON_DATE_TIME146)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_SHRINK,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_SHRINK,0,107,5,135,33)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
SHOW_ITEM_ELLIPSE(CMD_Ellipse,Ellipse149,0,1,17,16,16,0,0,14,0,0,0)//14 blue //13 yellow
SHOW_MAP_BEGIN(Skin147)
SHOW_MAP_BODY(Ellipse149)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin147,0,0,17,17)

SHOW_MAP_BEGIN(UIFlowWndMovie_PanelYellow)
SHOW_MAP_BODY(Skin147)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_PanelYellow)
DECLARE_CTRL_LIST(UIFlowWndMovie_PanelYellow)
CREATE_CTRL(UIFlowWndMovie_PanelYellow,UIFlowWndMovie_PanelYellow,CTRL_WND,NULL,0 ,52,11,69,28)
SHOW_ITEM_RECT(CMD_Rectangle,Skin151Rect,0,0,120,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin151)
SHOW_MAP_BODY(Skin151Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin151,0,0,120,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text153,2,-1,119,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal150)
SHOW_MAP_BODY(Skin151)
SHOW_MAP_BODY(Text153)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal150,56,191,176,211)

SHOW_MAP_BEGIN(UIFlowWndMovie_CarNo_Static)
SHOW_MAP_BODY(Normal150)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_CarNo_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_CarNo_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_CarNo_Static,0,56,191,176,211)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin156Rect,0,0,20,24,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin156)
SHOW_MAP_BODY(Skin156Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin156,0,0,20,24)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text158,0,0,20,24,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal155)
SHOW_MAP_BODY(Skin156)
SHOW_MAP_BODY(Text158)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal155,53,188,73,212)

CREATE_STATE_ITEM_DATA(STRID_NULL_159,STRID_NULL_,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4E91160,STRID_4E91,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4EAC161,STRID_4EAC,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5B81162,STRID_5B81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5DDD163,STRID_5DDD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6CAA164,STRID_6CAA,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D25165,STRID_6D25,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D59166,STRID_6D59,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E1D167,STRID_6E1D,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E58168,STRID_6E58,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7CA4169,STRID_7CA4,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8C6B170,STRID_8C6B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D35171,STRID_8D35,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D63172,STRID_8D63,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8FBD173,STRID_8FBD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9C81174,STRID_9C81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9ED1175,STRID_9ED1,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_65B0176,STRID_65B0,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_82CF177,STRID_82CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_85CF178,STRID_85CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_95FD179,STRID_95FD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_664B180,STRID_664B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_743C181,STRID_743C,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5180182,STRID_5180,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5409183,STRID_5409,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6842184,STRID_6842,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7518185,STRID_7518,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7696186,STRID_7696,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8499187,STRID_8499,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9102188,STRID_9102,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9655189,STRID_9655,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9752190,STRID_9752,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
SHOW_MAP_BODY(Normal155)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_ITEM(STRID_NULL_159)
STATE_LIST_ITEM(STRID_4E91160)
STATE_LIST_ITEM(STRID_4EAC161)
STATE_LIST_ITEM(STRID_5B81162)
STATE_LIST_ITEM(STRID_5DDD163)
STATE_LIST_ITEM(STRID_6CAA164)
STATE_LIST_ITEM(STRID_6D25165)
STATE_LIST_ITEM(STRID_6D59166)
STATE_LIST_ITEM(STRID_6E1D167)
STATE_LIST_ITEM(STRID_6E58168)
STATE_LIST_ITEM(STRID_7CA4169)
STATE_LIST_ITEM(STRID_8C6B170)
STATE_LIST_ITEM(STRID_8D35171)
STATE_LIST_ITEM(STRID_8D63172)
STATE_LIST_ITEM(STRID_8FBD173)
STATE_LIST_ITEM(STRID_9C81174)
STATE_LIST_ITEM(STRID_9ED1175)
STATE_LIST_ITEM(STRID_65B0176)
STATE_LIST_ITEM(STRID_82CF177)
STATE_LIST_ITEM(STRID_85CF178)
STATE_LIST_ITEM(STRID_95FD179)
STATE_LIST_ITEM(STRID_664B180)
STATE_LIST_ITEM(STRID_743C181)
STATE_LIST_ITEM(STRID_5180182)
STATE_LIST_ITEM(STRID_5409183)
STATE_LIST_ITEM(STRID_6842184)
STATE_LIST_ITEM(STRID_7518185)
STATE_LIST_ITEM(STRID_7696186)
STATE_LIST_ITEM(STRID_8499187)
STATE_LIST_ITEM(STRID_9102188)
STATE_LIST_ITEM(STRID_9655189)
STATE_LIST_ITEM(STRID_9752190)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_ZHCarNo,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_ZHCarNo,0,53,188,73,212)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin171)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin171,0,0,319,239)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon172, 1, 1, 320,240, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal170)
SHOW_MAP_BODY(Skin171)
SHOW_MAP_BODY(Icon172)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal170,0,0,319,239)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_DAOCHE)
SHOW_MAP_BODY(Normal170)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_DAOCHE)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_DAOCHE,ICON_BAOCHE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_DAOCHE,0,0,0,319,239)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndMovie)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie)
DECLARE_CTRL_LIST(UIFlowWndMovie)
CREATE_CTRL(UIFlowWndMovie,UIFlowWndMovie,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
