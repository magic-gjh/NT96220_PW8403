#ifndef _OV5633_H
#define _OV5633_H
#include "sensor.h"
#define Token(n)    #n
typedef enum _OV5633_MODE
{
    OV5633_INIT     = 0,
    OV5633_VGA      = SENSOR_MODE_640X480,
    OV5633_1280X720 = SENSOR_MODE_1280X720,
    OV5633_1280X960 = SENSOR_MODE_1280X960,
    OV5633_1280X480 = SENSOR_MODE_1280X480,
    OV5633_2560X960 = SENSOR_MODE_2560X960,
    OV5633_STILL    = SENSOR_MODE_FULL,
    ENUM_DUMMY4WORD(OV5633_MODE)
}OV5633_MODE;

extern void OV5633_GetRegInfo(OV5633_MODE mode,UINT32* addr,UINT32* size);
extern void OV5633_GetSigInfo(OV5633_MODE mode,UINT32* addr,UINT32* size);
extern void OV5633_GetDataInfo(OV5633_MODE mode,UINT32* addr,UINT32* size);
extern void OV5633_GetISOInfo(UINT32 *ISOBase,UINT32 *AGCBase);

#endif
