#ifndef _NT99143_H
#define _NT99143_H
#include "sensor.h"
#define Token(n)    #n
typedef enum _NT99143_MODE
{
    NT99143_INIT         = 0,
    NT99143_1280X720    = SENSOR_MODE_1280X720,
    NT99143_1280X960    = SENSOR_MODE_1280X960,
    NT99143_1440X1080    = SENSOR_MODE_1440X1080,
    NT99143_1920X1080    = SENSOR_MODE_1920X1080,
    NT99143_STILL        = SENSOR_MODE_FULL,
    ENUM_DUMMY4WORD(NT99143_MODE)
}NT99143_MODE;

extern void NT99143_GetRegInfo(NT99143_MODE mode,UINT32* addr,UINT32* size);
extern void NT99143_GetSigInfo(NT99143_MODE mode,UINT32* addr,UINT32* size);
extern void NT99143_GetDataInfo(NT99143_MODE mode,UINT32* addr,UINT32* size);
extern void NT99143_GetISOInfo(UINT32 *ISOBase,UINT32 *AGCBase);

#endif