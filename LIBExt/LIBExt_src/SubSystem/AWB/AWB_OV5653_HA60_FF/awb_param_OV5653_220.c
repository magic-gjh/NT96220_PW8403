/**
    Auto Exposure parameter.

    ae parameter.

    @file       ae_sample_param.c
    @ingroup    mISYSAlg
    @note       Nothing (or anything need to be mentioned).

    Copyright   Novatek Microelectronics Corp. 2011.  All rights reserved.
*/
#include "type.h"
#include "Awb_alg.h"
#include "Awb_OV5653_220_int.h"

#define GRAYWORLD DISABLE//ENABLE//

#if (GRAYWORLD == ENABLE)

AWBALG_ELEMET element1[] =
{
    {AWBALG_TYPE_Y,   0xffffffff,   0},
    {AWBALG_TAB_END,           0,   0}
};

AWBALG_ELEMET element2[] =
{
    {AWBALG_TYPE_Y,   0xffffffff,   0},
    {AWBALG_TAB_END,           0,   0}
};


AWBALG_TAB AwbTAB[AWB_TAB_CNT] =
{
    {((1 << 9) * 10), ((1 << 1) * 10), element1},
    {((1 << 20) * 10), ((1 << 9) * 10), element2}
};


#else

AWBALG_ELEMET element1[] =
{
    {AWBALG_TYPE_Y,      185,  16},
    {AWBALG_TYPE_RG,     200,  100},
    {AWBALG_TYPE_BG,     153, 100},
    {AWBALG_TYPE_RBG,    321,  38},
    {AWBALG_TYPE_SAT,     54,  13},
    {AWBALG_TYPE_RBGSUM, 422, 208},
    {AWBALG_TYPE_RXBG,   456, 158},
    {AWBALG_TYPE_USER,     0,   0},
    {AWBALG_TAB_END,       0,   0}
};

AWBALG_ELEMET element2[] =
{
    {AWBALG_TYPE_Y,      185,  16},
    {AWBALG_TYPE_RG,     204, 123},
    {AWBALG_TYPE_BG,     166, 100},
    {AWBALG_TYPE_RBG,    110,  52},
    {AWBALG_TYPE_SAT,     31,  13},
    {AWBALG_TYPE_RBGSUM, 320, 248},
    {AWBALG_TYPE_RXBG,   240, 171},
    {AWBALG_TYPE_USER,     0,   0},
    {AWBALG_TAB_END,       0,   0}
};

AWBALG_TAB AwbTAB[AWB_TAB_CNT] =
{
    {((1 << 9) * 10), ((1 << 4) * 10), element1},
    {((1 << 17) * 10), ((1 << 9) * 10), element2}
};
#endif

const UINT32 MwbTAB[AWB_MODE_MAX][2] =
{
    { 256, 256},
    { 442, 308},//AWB_MODE_DAYLIGHT
    { 405, 340},//AWB_MODE_CLOUDY
    { (197*12/10), (583*83/100)},//AWB_MODE_TUNGSTEN
    { 327, 418},//AWB_MODE_FLUORESCENT1
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256}
};


