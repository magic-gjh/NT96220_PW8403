include ../../PanelDef.txt

DISPLCDSEL_PARAMETER += -DDISPLCDSEL_IF8BITS_TYPE=DISPLCDSEL_IF8BITS_LCD1
DISPDEV_PARAMETER += -DDISPDEV_IF8BITS_TYPE=DISPDEV_IF8BITS_TXDT270C_8961_6A6

#----------------------------------------------------------------------
# set the library name here
#----------------------------------------------------------------------
PRJ_NAME = LCDTV_TXDT270C_8961_6A6

#----------------------------------------------------------------------
# add/delete source files here
#----------------------------------------------------------------------
SRC = \
	../../dispdev_IF8bits.c \
	TXDT270C.c

ASM =

#----------------------------------------------------------------------
# set the include directory here
#----------------------------------------------------------------------
INC_DIR = ../../../ \
	../../../../../../../../Include \

#----------------------------------------------------------------------
# set the image output directory here
#----------------------------------------------------------------------
IMG_BASE_DIR = ../../../../../../..

#----------------------------------------------------------------------
# add additional C and assembly flags here
#----------------------------------------------------------------------
CFLAGS_D = -Otime
CFLAGS_D += $(DISPDEV_PARAMETER)
CFLAGS_D += $(DISPLCDSEL_PARAMETER)
ASMFLAGS_D =

CFLAGS_R = -Otime
CFLAGS_R += $(DISPDEV_PARAMETER)
CFLAGS_R += $(DISPLCDSEL_PARAMETER)
ASMFLAGS_R =

#----------------------------------------------------------------------
# include common parts of the makefile
#----------------------------------------------------------------------
MAKE_COMMON_DIR = ../../../../../../../../MakeCommon
include $(MAKE_COMMON_DIR)/OutputLib.txt
