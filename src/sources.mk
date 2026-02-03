#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

ifeq ($(PLATFORM),MSP432)
# This includes 3 platform sources necessary on the bare metal with no STDLIB
SOURCES = interrupts_msp432p401r_gcc.c  main.c  memory.c \
	  startup_msp432p401r_gcc.c  system_msp432p401r.c
# We need the platform specific includes for CMSIS and this processor model
INCLUDES = ../include/common ../include/CMSIS ../include/msp432

else
# we don't need the sources specific to the embedded platform, we use STDLIB
SOURCES = main.c memory.c

# Linux host doesn't need the platform specific includes, we have STDLIB
INCLUDES = ../include/common

endif
