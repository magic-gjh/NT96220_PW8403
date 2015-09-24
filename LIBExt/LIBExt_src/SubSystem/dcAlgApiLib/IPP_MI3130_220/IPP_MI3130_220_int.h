/**
    Internal header file for IPP_MI3130

    Header files for differnt IPP_sensor

    @sensor     Micron MI3130
    @file               IPP_MI3130_220_int.h
    @ingroup        IPP_MI3130_220
    @note           Nothing

    Porting by Randy Ho 2012/03/08

    Copyright   Novatek Microelectronics Corp. 2011.  All rights reserved.
*/

#ifndef _IPP_MI3130_220_INT_H
#define _IPP_MI3130_220_INT_H

#include <string.h>
#include <stdio.h>
#include "Type.h"

#include "sie_lib.h"
#include "ipe_lib.h"
#include "ife_lib.h"
#include "ime_lib.h"
#include "aaa_lib.h"
#include "sra_lib.h"
#include "IPPManager.h"
#include "sen_common.h"
#include "ImageAlgInfor.h"
#include "Alg_IPLMode.h"
#include "IPPBuffer.h"
#include "IPP_Debug.h"
#include "prv_common.h"
#include "dzoom.h"
#include "SensorFlowFunc.h"
#include "Lens.h"
#include "Sensor.h"
#include "ippctrl.h"
#include "Calibration.h"
#include "SensorSys.h"
//#NT#2011/08/22#Ethan Lau -begin
//#NT#move to IQSetting_MI3130_220.c
//#include "IQSetting_MI3130_220.h"
//#NT#2011/08/22#Ethan Lau -end
#include "isr_MI3130_220.h"
#include "af_api.h"

#endif // EOF
