#include "debug.h"
#include "sensor.h"
#include "string.h"

#if S5K3E2_220
const UINT32 VDOZOOM_INFOR_TABLE[61][6] =
{
    //sie_in        sie_out
    {640,  480,  640,  480,  640,  480},
    {624,  464,  624,  464,  620,  464},
    {608,  448,  608,  448,  596,  448},
    {576,  432,  576,  432,  576,  432},
    {560,  416,  560,  416,  556,  416},
    {544,  404,  544,  404,  540,  404},
    {528,  388,  528,  388,  520,  388},
    {512,  376,  512,  376,  504,  376},
    {496,  364,  496,  364,  484,  364},
    {480,  352,  480,  352,  468,  352},
    {464,  340,  464,  340,  452,  340},
    {448,  328,  448,  328,  436,  328},
    {432,  316,  432,  316,  424,  316},
    {416,  304,  416,  304,  408,  304},
    {400,  296,  400,  296,  392,  296},
    {384,  284,  384,  284,  380,  284},
    {368,  276,  368,  276,  368,  276},
    {368,  268,  368,  268,  356,  268},
    {352,  256,  352,  256,  344,  256},
    {336,  248,  336,  248,  332,  248},
    {320,  240,  320,  240,  320,  240},
    {320,  232,  320,  232,  308,  232},
    {304,  224,  304,  224,  300,  224},
    {288,  216,  288,  216,  288,  216},
    {288,  208,  288,  208,  280,  208},
    {272,  200,  272,  200,  268,  200},
    {272,  196,  272,  196,  260,  196},
    {256,  188,  256,  188,  252,  188},
    {256,  180,  256,  180,  244,  180},
    {240,  176,  240,  176,  236,  176},
    {240,  168,  240,  168,  228,  168},
    {224,  164,  224,  164,  220,  164},
    {224,  160,  224,  160,  212,  160},
    {208,  152,  208,  152,  204,  152},
    {208,  148,  208,  148,  196,  148},
    {192,  144,  192,  144,  192,  144},
    {192,  136,  192,  136,  184,  136},
    {176,  132,  176,  132,  176,  132},
    {176,  128,  176,  128,  172,  128},
    {176,  124,  176,  124,  164,  124},
    {160,  120,  160,  120,  160,  120},
    {160,  116,  160,  116,  156,  116},
    {160,  112,  160,  112,  148,  112},
    {144,  108,  144,  108,  144,  108},
    {144,  104,  144,  104,  140,  104},
    {144,  100,  144,  100,  136,  100},
    {128,  96,   128,  96,   128,  96},
    {128,  96,   128,  96,   124,  96},
    {128,  92,   128,  92,   120,  92},
    {128,  88,   128,  88,   116,  88},
    {112,  84,   112,  84,   112,  84},
    {112,  80,   112,  80,   108,  80},
    {112,  80,   112,  80,   104,  80},
    {112,  76,   112,  76,   100,  76},
    {112,  72,   112,  72,   100,  72},
    {96,   72,   96,   72,   96,   72},
    {96,   68,   96,   68,   92,   68},
    {96,   68,   96,   68,   88,   68},
    {96,   64,   96,   64,   84,   64},
    {96,   64,   96,   64,   84,   64},
    {80,   60,   80,   60,   80,   60},
};

const UINT32 VDOZOOM_INFOR_MODE_2_TABLE[61][6] =
{
    //sie_in        sie_out
    {1264,  948,  1264,  948,   1264,  948},
    {1232,  916,  1232,  916,   1220,  916},
    {1184,  884,  1184,  884,   1180,  884},
    {1152,  856,  1152,  856,   1140,  856},
    {1104,  824,  1104,  824,   1100,  824},
    {1072,  796,  1072,  796,   1064,  796},
    {1040,  772,  1040,  772,   1028,  772},
    {992,   744,  992,   744,   992,   744},
    {960,   720,  960,   720,   956,   720},
    {928,   692,  928,   692,   924,   692},
    {896,   672,  896,   672,   892,   672},
    {864,   648,  864,   648,   864,   648},
    {832,   624,  832,   624,   832,   624},
    {816,   604,  816,   604,   804,   604},
    {784,   584,  784,   584,   780,   584},
    {752,   564,  752,   564,   752,   564},
    {736,   544,  736,   544,   724,   544},
    {704,   524,  704,   524,   700,   524},
    {688,   508,  688,   508,   676,   508},
    {656,   492,  656,   492,   656,   492},
    {640,   476,  640,   476,   632,   476},
    {624,   456,  624,   456,   612,   456},
    {592,   444,  592,   444,   588,   444},
    {576,   428,  576,   428,   568,   428},
    {560,   412,  560,   412,   552,   412},
    {544,   400,  544,   400,   532,   400},
    {512,   384,  512,   384,   512,   384},
    {496,   372,  496,   372,   496,   372},
    {480,   360,  480,   360,   480,   360},
    {464,   348,  464,   348,   464,   348},
    {448,   336,  448,   336,   448,   336},
    {432,   324,  432,   324,   432,   324},
    {416,   312,  416,   312,   416,   312},
    {416,   304,  416,   304,   404,   304},
    {400,   292,  400,   292,   388,   292},
    {384,   280,  384,   280,   376,   280},
    {368,   272,  368,   272,   364,   272},
    {352,   264,  352,   264,   352,   264},
    {352,   256,  352,   256,   340,   256},
    {336,   244,  336,   244,   328,   244},
    {320,   236,  320,   236,   316,   236},
    {304,   228,  304,   228,   304,   228},
    {304,   220,  304,   220,   296,   220},
    {288,   212,  288,   212,   284,   212},
    {288,   208,  288,   208,   276,   208},
    {272,   200,  272,   200,   264,   200},
    {256,   192,  256,   192,   256,   192},
    {256,   184,  256,   184,   248,   184},
    {240,   180,  240,   180,   240,   180},
    {240,   172,  240,   172,   232,   172},
    {224,   168,  224,   168,   224,   168},
    {224,   160,  224,   160,   216,   160},
    {208,   156,  208,   156,   208,   156},
    {208,   152,  208,   152,   200,   152},
    {208,   144,  208,   144,   196,   144},
    {192,   140,  192,   140,   188,   140},
    {192,   136,  192,   136,   180,   136},
    {176,   132,  176,   132,   176,   132},
    {176,   128,  176,   128,   168,   128},
    {176,   124,  176,   124,   164,   124},
    {160,   120,  160,   120,   160,   120},
};

const UINT32 VDOZOOM_INFOR_MODE_3_TABLE[61][6] =
{
    //sie_in        pre_out
    {1264,  948,  1264,  948,   1264,  948},
    {1232,  916,  1232,  916,   1220,  916},
    {1184,  884,  1184,  884,   1180,  884},
    {1152,  856,  1152,  856,   1140,  856},
    {1104,  824,  1104,  824,   1100,  824},
    {1072,  796,  1072,  796,   1064,  796},
    {1040,  772,  1040,  772,   1028,  772},
    {992,   744,  992,   744,   992,   744},
    {960,   720,  960,   720,   956,   720},
    {928,   692,  928,   692,   924,   692},
    {896,   672,  896,   672,   892,   672},
    {864,   648,  864,   648,   864,   648},
    {832,   624,  832,   624,   832,   624},
    {816,   604,  816,   604,   804,   604},
    {784,   584,  784,   584,   780,   584},
    {752,   564,  752,   564,   752,   564},
    {736,   544,  736,   544,   724,   544},
    {704,   524,  704,   524,   700,   524},
    {688,   508,  688,   508,   676,   508},
    {656,   492,  656,   492,   656,   492},
    {640,   476,  640,   476,   632,   476},
    {624,   456,  624,   456,   612,   456},
    {592,   444,  592,   444,   588,   444},
    {576,   428,  576,   428,   568,   428},
    {560,   412,  560,   412,   552,   412},
    {544,   400,  544,   400,   532,   400},
    {512,   384,  512,   384,   512,   384},
    {496,   372,  496,   372,   496,   372},
    {480,   360,  480,   360,   480,   360},
    {464,   348,  464,   348,   464,   348},
    {448,   336,  448,   336,   448,   336},
    {432,   324,  432,   324,   432,   324},
    {416,   312,  416,   312,   416,   312},
    {416,   304,  416,   304,   404,   304},
    {400,   292,  400,   292,   388,   292},
    {384,   280,  384,   280,   376,   280},
    {368,   272,  368,   272,   364,   272},
    {352,   264,  352,   264,   352,   264},
    {352,   256,  352,   256,   340,   256},
    {336,   244,  336,   244,   328,   244},
    {320,   236,  320,   236,   316,   236},
    {304,   228,  304,   228,   304,   228},
    {304,   220,  304,   220,   296,   220},
    {288,   212,  288,   212,   284,   212},
    {288,   208,  288,   208,   276,   208},
    {272,   200,  272,   200,   264,   200},
    {256,   192,  256,   192,   256,   192},
    {256,   184,  256,   184,   248,   184},
    {240,   180,  240,   180,   240,   180},
    {240,   172,  240,   172,   232,   172},
    {224,   168,  224,   168,   224,   168},
    {224,   160,  224,   160,   216,   160},
    {208,   156,  208,   156,   208,   156},
    {208,   152,  208,   152,   200,   152},
    {208,   144,  208,   144,   196,   144},
    {192,   140,  192,   140,   188,   140},
    {192,   136,  192,   136,   180,   136},
    {176,   132,  176,   132,   176,   132},
    {176,   128,  176,   128,   168,   128},
    {176,   124,  176,   124,   164,   124},
    {160,   120,  160,   120,   160,   120},
};
//848*480
const UINT32 VDOZOOM_INFOR_MODE_4_TABLE[61][6] =
{
    //sie_in        pre_out
    {1264,  948,  1264,  948,   1264,  948},
    {1232,  916,  1232,  916,   1220,  916},
    {1184,  884,  1184,  884,   1180,  884},
    {1152,  856,  1152,  856,   1140,  856},
    {1104,  824,  1104,  824,   1100,  824},
    {1072,  796,  1072,  796,   1064,  796},
    {1040,  772,  1040,  772,   1028,  772},
    {992,   744,  992,   744,   992,   744},
    {960,   720,  960,   720,   956,   720},
    {928,   692,  928,   692,   924,   692},
    {896,   672,  896,   672,   892,   672},
    {864,   648,  864,   648,   864,   648},
    {832,   624,  832,   624,   832,   624},
    {816,   604,  816,   604,   804,   604},
    {784,   584,  784,   584,   780,   584},
    {752,   564,  752,   564,   752,   564},
    {736,   544,  736,   544,   724,   544},
    {704,   524,  704,   524,   700,   524},
    {688,   508,  688,   508,   676,   508},
    {656,   492,  656,   492,   656,   492},
    {640,   476,  640,   476,   632,   476},
    {624,   456,  624,   456,   612,   456},
    {592,   444,  592,   444,   588,   444},
    {576,   428,  576,   428,   568,   428},
    {560,   412,  560,   412,   552,   412},
    {544,   400,  544,   400,   532,   400},
    {512,   384,  512,   384,   512,   384},
    {496,   372,  496,   372,   496,   372},
    {480,   360,  480,   360,   480,   360},
    {464,   348,  464,   348,   464,   348},
    {448,   336,  448,   336,   448,   336},
    {432,   324,  432,   324,   432,   324},
    {416,   312,  416,   312,   416,   312},
    {416,   304,  416,   304,   404,   304},
    {400,   292,  400,   292,   388,   292},
    {384,   280,  384,   280,   376,   280},
    {368,   272,  368,   272,   364,   272},
    {352,   264,  352,   264,   352,   264},
    {352,   256,  352,   256,   340,   256},
    {336,   244,  336,   244,   328,   244},
    {320,   236,  320,   236,   316,   236},
    {304,   228,  304,   228,   304,   228},
    {304,   220,  304,   220,   296,   220},
    {288,   212,  288,   212,   284,   212},
    {288,   208,  288,   208,   276,   208},
    {272,   200,  272,   200,   264,   200},
    {256,   192,  256,   192,   256,   192},
    {256,   184,  256,   184,   248,   184},
    {240,   180,  240,   180,   240,   180},
    {240,   172,  240,   172,   232,   172},
    {224,   168,  224,   168,   224,   168},
    {224,   160,  224,   160,   216,   160},
    {208,   156,  208,   156,   208,   156},
    {208,   152,  208,   152,   200,   152},
    {208,   144,  208,   144,   196,   144},
    {192,   140,  192,   140,   188,   140},
    {192,   136,  192,   136,   180,   136},
    {176,   132,  176,   132,   176,   132},
    {176,   128,  176,   128,   168,   128},
    {176,   124,  176,   124,   164,   124},
    {160,   120,  160,   120,   160,   120},
};
//2560*960
const UINT32 VDOZOOM_INFOR_MODE_5_TABLE[61][6] =
{
    //sie_in        pre_out
    {2528,  1896,  2528,  1896,  2528,  1896},
    {2448,  1832,  2448,  1832,  2440,  1832},
    {2368,  1768,  2368,  1768,  2360,  1768},
    {2288,  1708,  2288,  1708,  2280,  1708},
    {2208,  1652,  2208,  1652,  2200,  1652},
    {2128,  1596,  2128,  1596,  2124,  1596},
    {2064,  1540,  2064,  1540,  2052,  1540},
    {1984,  1488,  1984,  1488,  1984,  1488},
    {1920,  1436,  1920,  1436,  1916,  1436},
    {1856,  1388,  1856,  1388,  1852,  1388},
    {1792,  1340,  1792,  1340,  1788,  1340},
    {1728,  1296,  1728,  1296,  1728,  1296},
    {1680,  1252,  1680,  1252,  1668,  1252},
    {1616,  1208,  1616,  1208,  1612,  1208},
    {1568,  1168,  1568,  1168,  1556,  1168},
    {1504,  1128,  1504,  1128,  1504,  1128},
    {1456,  1088,  1456,  1088,  1452,  1088},
    {1408,  1052,  1408,  1052,  1404,  1052},
    {1360,  1016,  1360,  1016,  1356,  1016},
    {1312,  980,   1312,  980,   1308,  980},
    {1264,  948,   1264,  948,   1264,  948},
    {1232,  916,   1232,  916,   1220,  916},
    {1184,  884,   1184,  884,   1180,  884},
    {1152,  856,   1152,  856,   1140,  856},
    {1104,  824,   1104,  824,   1100,  824},
    {1072,  796,   1072,  796,   1064,  796},
    {1040,  772,   1040,  772,   1028,  772},
    {992,   744,   992,   744,   992,   744},
    {960,   720,   960,   720,   956,   720},
    {928,   692,   928,   692,   924,   692},
    {896,   672,   896,   672,   892,   672},
    {864,   648,   864,   648,   864,   648},
    {832,   624,   832,   624,   832,   624},
    {816,   604,   816,   604,   804,   604},
    {784,   584,   784,   584,   780,   584},
    {752,   564,   752,   564,   752,   564},
    {736,   544,   736,   544,   724,   544},
    {704,   524,   704,   524,   700,   524},
    {688,   508,   688,   508,   676,   508},
    {656,   492,   656,   492,   656,   492},
    {640,   476,   640,   476,   632,   476},
    {624,   456,   624,   456,   612,   456},
    {592,   444,   592,   444,   588,   444},
    {576,   428,   576,   428,   568,   428},
    {560,   412,   560,   412,   552,   412},
    {544,   400,   544,   400,   532,   400},
    {512,   384,   512,   384,   512,   384},
    {496,   372,   496,   372,   496,   372},
    {480,   360,   480,   360,   480,   360},
    {464,   348,   464,   348,   464,   348},
    {448,   336,   448,   336,   448,   336},
    {432,   324,   432,   324,   432,   324},
    {416,   312,   416,   312,   416,   312},
    {416,   304,   416,   304,   404,   304},
    {400,   292,   400,   292,   388,   292},
    {384,   280,   384,   280,   376,   280},
    {368,   272,   368,   272,   364,   272},
    {352,   264,   352,   264,   352,   264},
    {352,   256,   352,   256,   340,   256},
    {336,   244,   336,   244,   328,   244},
    {320,   236,   320,   236,   316,   236},
};
//full resolution
const UINT32 VDOZOOM_INFOR_MODE_FULL_TABLE[61][6] =
{
    {2528,  1896,  2528,  1896,  2528,  1896},
    {2448,  1832,  2448,  1832,  2440,  1832},
    {2368,  1768,  2368,  1768,  2360,  1768},
    {2288,  1708,  2288,  1708,  2280,  1708},
    {2208,  1652,  2208,  1652,  2200,  1652},
    {2128,  1596,  2128,  1596,  2124,  1596},
    {2064,  1540,  2064,  1540,  2052,  1540},
    {1984,  1488,  1984,  1488,  1984,  1488},
    {1920,  1436,  1920,  1436,  1916,  1436},
    {1856,  1388,  1856,  1388,  1852,  1388},
    {1792,  1340,  1792,  1340,  1788,  1340},
    {1728,  1296,  1728,  1296,  1728,  1296},
    {1680,  1252,  1680,  1252,  1668,  1252},
    {1616,  1208,  1616,  1208,  1612,  1208},
    {1568,  1168,  1568,  1168,  1556,  1168},
    {1504,  1128,  1504,  1128,  1504,  1128},
    {1456,  1088,  1456,  1088,  1452,  1088},
    {1408,  1052,  1408,  1052,  1404,  1052},
    {1360,  1016,  1360,  1016,  1356,  1016},
    {1312,  980,   1312,  980,   1308,  980},
    {1264,  948,   1264,  948,   1264,  948},
    {1232,  916,   1232,  916,   1220,  916},
    {1184,  884,   1184,  884,   1180,  884},
    {1152,  856,   1152,  856,   1140,  856},
    {1104,  824,   1104,  824,   1100,  824},
    {1072,  796,   1072,  796,   1064,  796},
    {1040,  772,   1040,  772,   1028,  772},
    {992,   744,   992,   744,   992,   744},
    {960,   720,   960,   720,   956,   720},
    {928,   692,   928,   692,   924,   692},
    {896,   672,   896,   672,   892,   672},
    {864,   648,   864,   648,   864,   648},
    {832,   624,   832,   624,   832,   624},
    {816,   604,   816,   604,   804,   604},
    {784,   584,   784,   584,   780,   584},
    {752,   564,   752,   564,   752,   564},
    {736,   544,   736,   544,   724,   544},
    {704,   524,   704,   524,   700,   524},
    {688,   508,   688,   508,   676,   508},
    {656,   492,   656,   492,   656,   492},
    {640,   476,   640,   476,   632,   476},
    {624,   456,   624,   456,   612,   456},
    {592,   444,   592,   444,   588,   444},
    {576,   428,   576,   428,   568,   428},
    {560,   412,   560,   412,   552,   412},
    {544,   400,   544,   400,   532,   400},
    {512,   384,   512,   384,   512,   384},
    {496,   372,   496,   372,   496,   372},
    {480,   360,   480,   360,   480,   360},
    {464,   348,   464,   348,   464,   348},
    {448,   336,   448,   336,   448,   336},
    {432,   324,   432,   324,   432,   324},
    {416,   312,   416,   312,   416,   312},
    {416,   304,   416,   304,   404,   304},
    {400,   292,   400,   292,   388,   292},
    {384,   280,   384,   280,   376,   280},
    {368,   272,   368,   272,   364,   272},
    {352,   264,   352,   264,   352,   264},
    {352,   256,   352,   256,   340,   256},
    {336,   244,   336,   244,   328,   244},
    {320,   236,   320,   236,   316,   236},
};

const UINT32 VDOZOOM_INFOR_MODE_6_TABLE[61][6] =
{
    //sie_in        pre_out
    {1264,  476,   1264,  476,   1264,  476},
    {1232,  460,   1232,  460,   1220,  460},
    {1184,  444,   1184,  444,   1180,  444},
    {1152,  428,   1152,  428,   1140,  428},
    {1104,  416,   1104,  416,   1100,  416},
    {1072,  400,   1072,  400,   1064,  400},
    {1040,  388,   1040,  388,   1028,  388},
    {992,   372,   992,   372,   992,   372},
    {960,   360,   960,   360,   956,   360},
    {928,   348,   928,   348,   924,   348},
    {896,   336,   896,   336,   892,   336},
    {864,   324,   864,   324,   864,   324},
    {832,   316,   832,   316,   832,   316},
    {816,   304,   816,   304,   804,   304},
    {784,   292,   784,   292,   780,   292},
    {752,   284,   752,   284,   752,   284},
    {736,   272,   736,   272,   724,   272},
    {704,   264,   704,   264,   700,   264},
    {688,   256,   688,   256,   676,   256},
    {656,   248,   656,   248,   656,   248},
    {640,   240,   640,   240,   632,   240},
    {624,   228,   624,   228,   612,   228},
    {592,   224,   592,   224,   588,   224},
    {576,   216,   576,   216,   568,   216},
    {560,   208,   560,   208,   552,   208},
    {544,   200,   544,   200,   532,   200},
    {512,   192,   512,   192,   512,   192},
    {496,   188,   496,   188,   496,   188},
    {480,   180,   480,   180,   480,   180},
    {464,   176,   464,   176,   464,   176},
    {448,   168,   448,   168,   448,   168},
    {432,   164,   432,   164,   432,   164},
    {416,   156,   416,   156,   416,   156},
    {416,   152,   416,   152,   404,   152},
    {400,   148,   400,   148,   388,   148},
    {384,   140,   384,   140,   376,   140},
    {368,   136,   368,   136,   364,   136},
    {352,   132,   352,   132,   352,   132},
    {352,   128,   352,   128,   340,   128},
    {336,   124,   336,   124,   328,   124},
    {320,   120,   320,   120,   316,   120},
    {304,   116,   304,   116,   304,   116},
    {304,   112,   304,   112,   296,   112},
    {288,   108,   288,   108,   284,   108},
    {288,   104,   288,   104,   276,   104},
    {272,   100,   272,   100,   264,   100},
    {256,   96,    256,   96,    256,   96},
    {256,   92,    256,   92,    248,   92},
    {240,   92,    240,   92,    240,   92},
    {240,   88,    240,   88,    232,   88},
    {224,   84,    224,   84,    224,   84},
    {224,   80,    224,   80,    216,   80},
    {208,   80,    208,   80,    208,   80},
    {208,   76,    208,   76,    200,   76},
    {208,   72,    208,   72,    196,   72},
    {192,   72,    192,   72,    188,   72},
    {192,   68,    192,   68,    180,   68},
    {176,   68,    176,   68,    176,   68},
    {176,   64,    176,   64,    168,   64},
    {176,   60,    176,   60,    164,   60},
    {160,   60,    160,   60,    160,   60},
};

const UINT32 VDOZOOM_INFOR_MODE_7_TABLE[61][6] =
{
    //sie_in        pre_out
    {1264,  236,   1264,  236,   1264,  236},
    {1232,  228,   1232,  228,   1220,  228},
    {1184,  220,   1184,  220,   1180,  220},
    {1152,  212,   1152,  212,   1140,  212},
    {1104,  204,   1104,  204,   1100,  204},
    {1072,  200,   1072,  200,   1064,  200},
    {1040,  192,   1040,  192,   1028,  192},
    {992,   184,   992,   184,   992,   184},
    {960,   180,   960,   180,   956,   180},
    {928,   172,   928,   172,   924,   172},
    {896,   168,   896,   168,   892,   168},
    {864,   160,   864,   160,   864,   160},
    {832,   156,   832,   156,   832,   156},
    {816,   152,   816,   152,   804,   152},
    {784,   144,   784,   144,   780,   144},
    {752,   140,   752,   140,   752,   140},
    {736,   136,   736,   136,   724,   136},
    {704,   132,   704,   132,   700,   132},
    {688,   128,   688,   128,   676,   128},
    {656,   124,   656,   124,   656,   124},
    {640,   120,   640,   120,   632,   120},
    {624,   116,   624,   116,   612,   116},
    {592,   112,   592,   112,   588,   112},
    {576,   108,   576,   108,   568,   108},
    {560,   104,   560,   104,   552,   104},
    {544,   100,   544,   100,   532,   100},
    {512,    96,   512,    96,   512,   96},
    {496,    92,   496,    92,   496,   92},
    {480,    88,   480,    88,   480,   88},
    {464,    88,   464,    88,   464,   88},
    {448,    84,   448,    84,   448,   84},
    {432,    80,   432,    80,   432,   80},
    {416,    76,   416,    76,   416,   76},
    {416,    76,   416,    76,   404,   76},
    {400,    72,   400,    72,   388,   72},
    {384,    72,   384,    72,   376,   72},
    {368,    68,   368,    68,   364,   68},
    {352,    64,   352,    64,   352,   64},
    {352,    64,   352,    64,   340,   64},
    {336,    60,   336,    60,   328,   60},
    {320,    60,   320,    60,   316,   60},
    {304,    56,   304,    56,   304,   56},
    {304,    56,   304,    56,   296,   56},
    {288,    52,   288,    52,   284,   52},
    {288,    52,   288,    52,   276,   52},
    {272,    48,   272,    48,   264,   48},
    {256,    48,   256,    48,   256,   48},
    {256,    48,   256,    48,   248,   48},
    {240,    44,   240,    44,   240,   44},
    {240,    44,   240,    44,   232,   44},
    {224,    40,   224,    40,   224,   40},
    {224,    40,   224,    40,   216,   40},
    {208,    40,   208,    40,   208,   40},
    {208,    36,   208,    36,   200,   36},
    {208,    36,   208,    36,   196,   36},
    {192,    36,   192,    36,   188,   36},
    {192,    32,   192,    32,   180,   32},
    {176,    32,   176,    32,   176,   32},
    {176,    32,   176,    32,   168,   32},
    {176,    32,   176,    32,   164,   32},
    {160,    28,   160,    28,   160,   28},
};

const UINT32 VDOZOOM_INFOR_MODE_8_TABLE[61][6] =
{
    {1904,  1068,   1904,   1068,   1904,   1068},
    {1840,  1032,   1840,   1032,   1840,   1032},
    {1776,  996,    1776,   996,    1776,   996},
    {1728,  964,    1728,   964,    1716,   964},
    {1664,  928,    1664,   928,    1656,   928},
    {1600,  900,    1600,   900,    1600,   900},
    {1552,  868,    1552,   868,    1548,   868},
    {1504,  836,    1504,   836,    1492,   836},
    {1456,  808,    1456,   808,    1444,   808},
    {1392,  780,    1392,   780,    1392,   780},
    {1360,  756,    1360,   756,    1348,   756},
    {1312,  728,    1312,   728,    1300,   728},
    {1264,  704,    1264,   704,    1256,   704},
    {1216,  680,    1216,   680,    1212,   680},
    {1184,  656,    1184,   656,    1172,   656},
    {1136,  636,    1136,   636,    1132,   636},
    {1104,  612,    1104,   612,    1092,   612},
    {1056,  592,    1056,   592,    1056,   592},
    {1024,  572,    1024,   572,    1020,   572},
    {992,   552,    992,    552,    984,    552},
    {960,   536,    960,    536,    952,    536},
    {928,   516,    928,    516,    920,    516},
    {896,   500,    896,    500,    888,    500},
    {864,   480,    864,    480,    856,    480},
    {832,   464,    832,    464,    828,    464},
    {800,   448,    800,    448,    800,    448},
    {784,   432,    784,    432,    772,    432},
    {752,   420,    752,    420,    748,    420},
    {720,   404,    720,    404,    720,    404},
    {704,   392,    704,    392,    696,    392},
    {672,   376,    672,    376,    672,    376},
    {656,   364,    656,    364,    652,    364},
    {640,   352,    640,    352,    628,    352},
    {608,   340,    608,    340,    608,    340},
    {592,   328,    592,    328,    588,    328},
    {576,   316,    576,    316,    568,    316},
    {560,   308,    560,    308,    548,    308},
    {528,   296,    528,    296,    528,    296},
    {512,   288,    512,    288,    512,    288},
    {496,   276,    496,    276,    492,    276},
    {480,   268,    480,    268,    476,    268},
    {464,   256,    464,    256,    460,    256},
    {448,   248,    448,    248,    444,    248},
    {432,   240,    432,    240,    428,    240},
    {416,   232,    416,    232,    416,    232},
    {400,   224,    400,    224,    400,    224},
    {400,   216,    400,    216,    388,    216},
    {384,   208,    384,    208,    372,    208},
    {368,   204,    368,    204,    360,    204},
    {352,   196,    352,    196,    348,    196},
    {336,   188,    336,    188,    336,    188},
    {336,   184,    336,    184,    324,    184},
    {320,   176,    320,    176,    316,    176},
    {304,   172,    304,    172,    304,    172},
    {304,   164,    304,    164,    292,    164},
    {288,   160,    288,    160,    284,    160},
    {272,   152,    272,    152,    272,    152},
    {272,   148,    272,    148,    264,    148},
    {256,   144,    256,    144,    256,    144},
    {256,   140,    256,    140,    248,    140},
    {240,   132,    240,    132,    240,    132},
};

UINT32 gDzoomTbl[61][6];
UINT32*  SenMode2Tbl(UINT32 SenMode,UINT32 *DzMaxidx)
{
    switch(SenMode)
    {
        //senmode,follow sensor driver,return corresponding dzoom tbl
        case SENSOR_MODE_320X240:
        case SENSOR_MODE_320X240P60:
        case SENSOR_MODE_320X240P120:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_7_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_640X480:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_640X480P60:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_6_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_1280X720:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_2_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_1280X960:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_3_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_1280X480:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_4_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_2560X960:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_5_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_1920X1080:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_8_TABLE,sizeof(UINT32)*61*6);
            break;
        case SENSOR_MODE_FULL:
            memcpy(gDzoomTbl,VDOZOOM_INFOR_MODE_FULL_TABLE,sizeof(UINT32)*61*6);
            break;
        default:
            debug_err(("%d %s\r\n",__LINE__,__func__));
        break;
    }
    *DzMaxidx = (42 -1 +10);//(61 -1+10);
    return gDzoomTbl[0];
}
#endif

