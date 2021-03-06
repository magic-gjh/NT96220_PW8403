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

SHOW_ITEM_RECT(CMD_Rectangle,Skin14Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin14)
SHOW_MAP_BODY(Skin14Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin14,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon15, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal13)
SHOW_MAP_BODY(Skin14)
SHOW_MAP_BODY(Icon15)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal13,12,71,39,98)

CREATE_STATE_ITEM_DATA(ICONID_NULL16,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_REC17,STRID_NULL,ICON_FLASH_REC,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MotionDet)
SHOW_MAP_BODY(Normal13)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_ITEM(ICONID_NULL16)
STATE_LIST_ITEM(ICON_FLASH_REC17)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MotionDet,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MotionDet,0,12,71,39,98)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin19Rect,0,0,33,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin19)
SHOW_MAP_BODY(Skin19Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin19,0,0,33,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon20, 0, -1, 31,26, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal18)
SHOW_MAP_BODY(Skin19)
SHOW_MAP_BODY(Icon20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal18,276,208,309,235)

CREATE_STATE_ITEM_DATA(ICON_BATTERY_FULL21,STRID_NULL,ICON_BATTERY_FULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_MED22,STRID_NULL,ICON_BATTERY_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_LOW23,STRID_NULL,ICON_BATTERY_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_EMPTY24,STRID_NULL,ICON_BATTERY_EMPTY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_ZERO25,STRID_NULL,ICON_BATTERY_ZERO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_CHARGE26,STRID_NULL,ICON_BATTERY_CHARGE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_battery)
SHOW_MAP_BODY(Normal18)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_battery)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_battery)
STATE_LIST_ITEM(ICON_BATTERY_FULL21)
STATE_LIST_ITEM(ICON_BATTERY_MED22)
STATE_LIST_ITEM(ICON_BATTERY_LOW23)
STATE_LIST_ITEM(ICON_BATTERY_EMPTY24)
STATE_LIST_ITEM(ICON_BATTERY_ZERO25)
STATE_LIST_ITEM(ICON_BATTERY_CHARGE26)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_battery,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_battery,0,276,208,309,235)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin28Rect,0,0,120,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_BODY(Skin28Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,120,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text30,2,-1,119,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Text30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal27,56,214,176,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_YMD_Static)
SHOW_MAP_BODY(Normal27)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_YMD_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_YMD_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_YMD_Static,0,56,214,176,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin33Rect,0,0,86,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin33)
SHOW_MAP_BODY(Skin33Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin33,0,0,86,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text35,1,2,84,18,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal32)
SHOW_MAP_BODY(Skin33)
SHOW_MAP_BODY(Text35)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal32,182,214,268,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_HMS_Static)
SHOW_MAP_BODY(Normal32)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_HMS_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_HMS_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_HMS_Static,0,182,214,268,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_ELLIPSE(CMD_Ellipse,Ellipse39,0,1,17,16,16,0,0,3,0,0,0)
SHOW_MAP_BEGIN(Skin37)
SHOW_MAP_BODY(Ellipse39)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin37,0,0,17,17)

SHOW_MAP_BEGIN(UIFlowWndMovie_Panel)
SHOW_MAP_BODY(Skin37)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Panel)
DECLARE_CTRL_LIST(UIFlowWndMovie_Panel)
CREATE_CTRL(UIFlowWndMovie_Panel,UIFlowWndMovie_Panel,CTRL_WND,NULL,0 ,52,11,69,28)
SHOW_ITEM_RECT(CMD_Rectangle,Skin41Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin41)
SHOW_MAP_BODY(Skin41Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin41,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon42, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal40)
SHOW_MAP_BODY(Skin41)
SHOW_MAP_BODY(Icon42)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal40,280,170,307,197)

CREATE_STATE_ITEM_DATA(ICON_INTERNAL_FLASH43,STRID_NULL,ICON_INTERNAL_FLASH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_CARD44,STRID_NULL,ICON_SD_CARD,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_LOCK45,STRID_NULL,ICON_SD_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_Storage)
SHOW_MAP_BODY(Normal40)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_Storage)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_Storage)
STATE_LIST_ITEM(ICON_INTERNAL_FLASH43)
STATE_LIST_ITEM(ICON_SD_CARD44)
STATE_LIST_ITEM(ICON_SD_LOCK45)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_Storage,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_Storage,0,280,170,307,197)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin47Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin47)
SHOW_MAP_BODY(Skin47Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin47,0,0,97,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text49,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal46)
SHOW_MAP_BODY(Skin47)
SHOW_MAP_BODY(Text49)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal46,210,5,307,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_time)
SHOW_MAP_BODY(Normal46)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_time)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_time,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_time,0,210,5,307,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin52Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin52)
SHOW_MAP_BODY(Skin52Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin52,0,0,97,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text54,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal51)
SHOW_MAP_BODY(Skin52)
SHOW_MAP_BODY(Text54)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal51,210,5,307,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_maxtime)
SHOW_MAP_BODY(Normal51)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_maxtime)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_maxtime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_maxtime,0,210,5,307,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin57Rect,0,0,97,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin57)
SHOW_MAP_BODY(Skin57Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin57,0,0,97,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text59,0,0,97,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal56)
SHOW_MAP_BODY(Skin57)
SHOW_MAP_BODY(Text59)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal56,210,40,307,69)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_resolution)
SHOW_MAP_BODY(Normal56)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_resolution)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_resolution,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_resolution,0,210,40,307,69)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin62Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin62)
SHOW_MAP_BODY(Skin62Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin62,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text64,0,0,59,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal61)
SHOW_MAP_BODY(Skin62)
SHOW_MAP_BODY(Text64)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal61,76,168,135,195)

SHOW_MAP_BEGIN(UIFlowWndMovie_Zoom_Static)
SHOW_MAP_BODY(Normal61)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Zoom_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_Zoom_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Zoom_Static,0,76,168,135,195)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin67Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin67)
SHOW_MAP_BODY(Skin67Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin67,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon68, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal66)
SHOW_MAP_BODY(Skin67)
SHOW_MAP_BODY(Icon68)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal66,12,104,39,131)

CREATE_STATE_ITEM_DATA(ICON_EV_P2P069,STRID_NULL,ICON_EV_P2P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P670,STRID_NULL,ICON_EV_P1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P371,STRID_NULL,ICON_EV_P1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P072,STRID_NULL,ICON_EV_P1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P673,STRID_NULL,ICON_EV_P0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P374,STRID_NULL,ICON_EV_P0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P075,STRID_NULL,ICON_EV_P0P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P376,STRID_NULL,ICON_EV_M0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P677,STRID_NULL,ICON_EV_M0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P078,STRID_NULL,ICON_EV_M1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P379,STRID_NULL,ICON_EV_M1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P680,STRID_NULL,ICON_EV_M1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M2P081,STRID_NULL,ICON_EV_M2P0,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_EV)
SHOW_MAP_BODY(Normal66)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_ITEM(ICON_EV_P2P069)
STATE_LIST_ITEM(ICON_EV_P1P670)
STATE_LIST_ITEM(ICON_EV_P1P371)
STATE_LIST_ITEM(ICON_EV_P1P072)
STATE_LIST_ITEM(ICON_EV_P0P673)
STATE_LIST_ITEM(ICON_EV_P0P374)
STATE_LIST_ITEM(ICON_EV_P0P075)
STATE_LIST_ITEM(ICON_EV_M0P376)
STATE_LIST_ITEM(ICON_EV_M0P677)
STATE_LIST_ITEM(ICON_EV_M1P078)
STATE_LIST_ITEM(ICON_EV_M1P379)
STATE_LIST_ITEM(ICON_EV_M1P680)
STATE_LIST_ITEM(ICON_EV_M2P081)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_EV,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_EV,0,12,104,39,131)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin83Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin83)
SHOW_MAP_BODY(Skin83Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin83,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon84, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal82)
SHOW_MAP_BODY(Skin83)
SHOW_MAP_BODY(Icon84)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal82,160,5,187,32)

CREATE_STATE_ITEM_DATA(ICON_IRLED_OFF85,STRID_NULL,ICON_IRLED_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_IRLED_ON86,STRID_NULL,ICON_IRLED_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_LedLight)
SHOW_MAP_BODY(Normal82)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_LedLight)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_LedLight)
STATE_LIST_ITEM(ICON_IRLED_OFF85)
STATE_LIST_ITEM(ICON_IRLED_ON86)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_LedLight,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_LedLight,0,160,5,187,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin88Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin88)
SHOW_MAP_BODY(Skin88Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin88,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon89, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal87)
SHOW_MAP_BODY(Skin88)
SHOW_MAP_BODY(Icon89)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal87,12,137,39,164)

CREATE_STATE_ITEM_DATA(ICON_VOICE_OFF90,STRID_NULL,ICON_VOICE_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOICE_ON91,STRID_NULL,ICON_VOICE_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MovieAudio)
SHOW_MAP_BODY(Normal87)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MovieAudio)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MovieAudio)
STATE_LIST_ITEM(ICON_VOICE_OFF90)
STATE_LIST_ITEM(ICON_VOICE_ON91)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MovieAudio,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MovieAudio,0,12,137,39,164)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin93Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin93)
SHOW_MAP_BODY(Skin93Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin93,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon94, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal92)
SHOW_MAP_BODY(Skin93)
SHOW_MAP_BODY(Icon94)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal92,75,5,102,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL95,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_LOCK96,STRID_NULL,ICON_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_LOCK)
SHOW_MAP_BODY(Normal92)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_LOCK)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_LOCK)
STATE_LIST_ITEM(ICONID_NULL95)
STATE_LIST_ITEM(ICON_LOCK96)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_LOCK,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_LOCK,0,75,5,102,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin98Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin98)
SHOW_MAP_BODY(Skin98Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin98,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon99, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal97)
SHOW_MAP_BODY(Skin98)
SHOW_MAP_BODY(Icon99)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal97,75,5,102,32)

CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL0100,STRID_NULL,ICON_GPS_LEVEL0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL1101,STRID_NULL,ICON_GPS_LEVEL1,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL2102,STRID_NULL,ICON_GPS_LEVEL2,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL3103,STRID_NULL,ICON_GPS_LEVEL3,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GPS)
SHOW_MAP_BODY(Normal97)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GPS)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GPS)
STATE_LIST_ITEM(ICON_GPS_LEVEL0100)
STATE_LIST_ITEM(ICON_GPS_LEVEL1101)
STATE_LIST_ITEM(ICON_GPS_LEVEL2102)
STATE_LIST_ITEM(ICON_GPS_LEVEL3103)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GPS,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GPS,0,75,5,102,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin105Rect,0,0,44,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin105)
SHOW_MAP_BODY(Skin105Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin105,0,0,44,29)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon106, 0, 0, 39,25, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal104)
SHOW_MAP_BODY(Skin105)
SHOW_MAP_BODY(Icon106)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal104,159,5,203,34)

CREATE_STATE_ITEM_DATA(ICON_GSENSOR_OFF107,STRID_NULL,ICON_GSENSOR_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_L108,STRID_NULL,ICON_GSENSOR_L,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_M109,STRID_NULL,ICON_GSENSOR_M,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GSENSOR_H110,STRID_NULL,ICON_GSENSOR_H,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GSENSOR)
SHOW_MAP_BODY(Normal104)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_ITEM(ICON_GSENSOR_OFF107)
STATE_LIST_ITEM(ICON_GSENSOR_L108)
STATE_LIST_ITEM(ICON_GSENSOR_M109)
STATE_LIST_ITEM(ICON_GSENSOR_H110)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GSENSOR,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GSENSOR,0,159,5,203,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin112Rect,0,0,31,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin112)
SHOW_MAP_BODY(Skin112Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin112,0,0,31,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon113, 0, 0, 31,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal111)
SHOW_MAP_BODY(Skin112)
SHOW_MAP_BODY(Icon113)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal111,280,135,311,162)

CREATE_STATE_ITEM_DATA(ICONID_NULL114,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_MENU_PARK115,STRID_NULL,ICON_MENU_PARK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_Parking)
SHOW_MAP_BODY(Normal111)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_Parking)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_Parking)
STATE_LIST_ITEM(ICONID_NULL114)
STATE_LIST_ITEM(ICON_MENU_PARK115)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_Parking,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_Parking,0,280,135,311,162)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin117Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin117)
SHOW_MAP_BODY(Skin117Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin117,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon118, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal116)
SHOW_MAP_BODY(Skin117)
SHOW_MAP_BODY(Icon118)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal116,107,5,134,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL119,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_REC120,STRID_NULL,ICON_FLASH_REC,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_TimeLapesRec)
SHOW_MAP_BODY(Normal116)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_TimeLapesRec)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_TimeLapesRec)
STATE_LIST_ITEM(ICONID_NULL119)
STATE_LIST_ITEM(ICON_FLASH_REC120)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_TimeLapesRec,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_TimeLapesRec,0,107,5,134,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_ELLIPSE(CMD_Ellipse,Ellipse123,0,1,17,16,16,0,0,14,0,0,0)
SHOW_MAP_BEGIN(Skin121)
SHOW_MAP_BODY(Ellipse123)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin121,0,0,17,17)

SHOW_MAP_BEGIN(UIFlowWndMovie_PanelMotionRec)
SHOW_MAP_BODY(Skin121)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_PanelMotionRec)
DECLARE_CTRL_LIST(UIFlowWndMovie_PanelMotionRec)
CREATE_CTRL(UIFlowWndMovie_PanelMotionRec,UIFlowWndMovie_PanelMotionRec,CTRL_WND,NULL,0 ,52,11,69,28)
SHOW_ITEM_RECT(CMD_Rectangle,Skin125Rect,0,0,149,19,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin125)
SHOW_MAP_BODY(Skin125Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin125,0,0,149,19)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text127,0,0,149,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal124)
SHOW_MAP_BODY(Skin125)
SHOW_MAP_BODY(Text127)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal124,56,192,205,211)

SHOW_MAP_BEGIN(UIFlowWndMovie_CarNo_Static)
SHOW_MAP_BODY(Normal124)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_CarNo_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_CarNo_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_CarNo_Static,0,56,192,205,211)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin130)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin130,0,0,19,19)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text132,0,0,19,19,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal129)
SHOW_MAP_BODY(Skin130)
SHOW_MAP_BODY(Text132)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal129,37,192,56,211)

CREATE_STATE_ITEM_DATA(STRID_NULL_133,STRID_NULL_,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4E91134,STRID_4E91,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4EAC135,STRID_4EAC,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5B81136,STRID_5B81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5DDD137,STRID_5DDD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6CAA138,STRID_6CAA,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D25139,STRID_6D25,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D59140,STRID_6D59,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E1D141,STRID_6E1D,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E58142,STRID_6E58,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7CA4143,STRID_7CA4,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8C6B144,STRID_8C6B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D35145,STRID_8D35,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D63146,STRID_8D63,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8FBD147,STRID_8FBD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9C81148,STRID_9C81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9ED1149,STRID_9ED1,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_65B0150,STRID_65B0,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_82CF151,STRID_82CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_85CF152,STRID_85CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_95FD153,STRID_95FD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_664B154,STRID_664B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_743C155,STRID_743C,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5180156,STRID_5180,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5409157,STRID_5409,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6842158,STRID_6842,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7518159,STRID_7518,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7696160,STRID_7696,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8499161,STRID_8499,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9102162,STRID_9102,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9655163,STRID_9655,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9752164,STRID_9752,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
SHOW_MAP_BODY(Normal129)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_ITEM(STRID_NULL_133)
STATE_LIST_ITEM(STRID_4E91134)
STATE_LIST_ITEM(STRID_4EAC135)
STATE_LIST_ITEM(STRID_5B81136)
STATE_LIST_ITEM(STRID_5DDD137)
STATE_LIST_ITEM(STRID_6CAA138)
STATE_LIST_ITEM(STRID_6D25139)
STATE_LIST_ITEM(STRID_6D59140)
STATE_LIST_ITEM(STRID_6E1D141)
STATE_LIST_ITEM(STRID_6E58142)
STATE_LIST_ITEM(STRID_7CA4143)
STATE_LIST_ITEM(STRID_8C6B144)
STATE_LIST_ITEM(STRID_8D35145)
STATE_LIST_ITEM(STRID_8D63146)
STATE_LIST_ITEM(STRID_8FBD147)
STATE_LIST_ITEM(STRID_9C81148)
STATE_LIST_ITEM(STRID_9ED1149)
STATE_LIST_ITEM(STRID_65B0150)
STATE_LIST_ITEM(STRID_82CF151)
STATE_LIST_ITEM(STRID_85CF152)
STATE_LIST_ITEM(STRID_95FD153)
STATE_LIST_ITEM(STRID_664B154)
STATE_LIST_ITEM(STRID_743C155)
STATE_LIST_ITEM(STRID_5180156)
STATE_LIST_ITEM(STRID_5409157)
STATE_LIST_ITEM(STRID_6842158)
STATE_LIST_ITEM(STRID_7518159)
STATE_LIST_ITEM(STRID_7696160)
STATE_LIST_ITEM(STRID_8499161)
STATE_LIST_ITEM(STRID_9102162)
STATE_LIST_ITEM(STRID_9655163)
STATE_LIST_ITEM(STRID_9752164)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_ZHCarNo,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_ZHCarNo,0,37,192,56,211)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin166Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin166)
SHOW_MAP_BODY(Skin166Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin166,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon167, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal165)
SHOW_MAP_BODY(Skin166)
SHOW_MAP_BODY(Icon167)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal165,107,5,134,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL168,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_WDR169,STRID_NULL,ICON_WDR,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_WDR)
SHOW_MAP_BODY(Normal165)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_WDR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_WDR)
STATE_LIST_ITEM(ICONID_NULL168)
STATE_LIST_ITEM(ICON_WDR169)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_WDR,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_WDR,0,107,5,134,32)

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
