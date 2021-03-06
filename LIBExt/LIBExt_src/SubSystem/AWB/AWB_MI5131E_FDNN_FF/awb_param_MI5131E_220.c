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
#include "Awb_MI5131E_220_int.h"

#define GRAYWORLD DISABLE

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
    {AWBALG_TYPE_Y,      185,  18},
    {AWBALG_TYPE_RG,     202,  64},
    {AWBALG_TYPE_BG,     346,  99},
    {AWBALG_TYPE_RBG,    502,  65},
    {AWBALG_TYPE_SAT,     70,  14},
    {AWBALG_TYPE_RBGSUM, 370, 235},
    {AWBALG_TYPE_RXBG,   340, 147},
    {AWBALG_TYPE_USER,     0,   0},
    {AWBALG_TAB_END,       0,   0}
};

AWBALG_ELEMET element2[] =
{
    {AWBALG_TYPE_Y,      185,  20},
    {AWBALG_TYPE_RG,     193, 118},
    {AWBALG_TYPE_BG,     173, 108},
    {AWBALG_TYPE_RBG,    145,  76},
    {AWBALG_TYPE_SAT,     30,  14},
    {AWBALG_TYPE_RBGSUM, 345, 235},
    {AWBALG_TYPE_RXBG,   323, 147},
    {AWBALG_TYPE_USER,     0,   0},
    {AWBALG_TAB_END,       0,   0}
};

AWBALG_TAB AwbTAB[AWB_TAB_CNT] =
{
    {((1 << 10) * 10), ((1 << 4) * 10), element1},
    {((1 << 17) * 10), ((1 << 10) * 10), element2}
};
#endif

const UINT32 MwbTAB[AWB_MODE_MAX][2] =
{
    { 256, 256},
    { 369, 323},//AWB_MODE_DAYLIGHT
    { (322*11/10), (381*93/100)},//AWB_MODE_CLOUDY
    { 187, 735},//AWB_MODE_TUNGSTEN
    { 300, 524},//AWB_MODE_FLUORESCENT1
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256},
    { 256, 256}
};


