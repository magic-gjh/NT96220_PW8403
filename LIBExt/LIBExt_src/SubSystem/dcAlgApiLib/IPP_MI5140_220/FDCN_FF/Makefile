#----------------------------------------------------------------------
# set the library name here
#----------------------------------------------------------------------
PRJ_NAME = IPP_MI5140_FDCN_FF

#----------------------------------------------------------------------
# add/delete source files here
#----------------------------------------------------------------------
SRC = \
      dzoomTable_MI5140_220.c \
      IQSetting_MI5140_220.c \
      SensorFlowFunc_MI5140_220.c \
      isr_MI5140_220.c \
      SensorSys_MI5140_220.c \
      ../Alg_IPLMode_MI5140_220.c
ASM =

#----------------------------------------------------------------------
# set the include directory here
#----------------------------------------------------------------------
INC_DIR = .. \
	../../../../../../Include \
	../../IPP_COMMON \

#----------------------------------------------------------------------
# set the image output directory here
#----------------------------------------------------------------------
IMG_BASE_DIR = ../../../../../

#----------------------------------------------------------------------
# add additional C and assembly flags here
#----------------------------------------------------------------------
CFLAGS_D = -Otime -DMI5140_220=1
ASMFLAGS_D =

CFLAGS_R = -Otime -DMI5140_220=1
ASMFLAGS_R =

#----------------------------------------------------------------------
# include common parts of the makefile
#----------------------------------------------------------------------
MAKE_COMMON_DIR = ../../../../../../MakeCommon
include $(MAKE_COMMON_DIR)/OutputLib.txt


