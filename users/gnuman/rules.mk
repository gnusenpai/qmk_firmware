SRC += gnuman.c \
	   keys.c

RGB_MATRIX_ENABLE ?= no
ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
    SRC += rgb.c
endif

ifndef LINK_TIME_OPTIMIZATION_ENABLE
    LINK_TIME_OPTIMIZATION_ENABLE = yes
endif
