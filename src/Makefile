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

#------------------------------------------------------------------------------
# Makefile for Course 1 Intro to Microcontrollers Module 2/Week 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      HOST: Linux on x86_64
#      MSP432: ARM Cortex-M4 on TI MSP432
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

# Platform Overrides, we default to HOST somewhat arbitrarily
ifeq ($(PLATFORM),)
$(info "Defaulting to PLATFORM HOST!!!!")
PLATFORM = HOST
endif

# put include after the line above so if PLATFORM isn't set it defaults to HOST
include sources.mk

# common for builds for all target platforms:
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) 

ifeq ($(PLATFORM),HOST)
# Architectures Specific Flags nothing on Linux host I think
LINKER_FILE = 
CPU = 
ARCH = 
SPECS =

# Compiler Flags and Defines
CC = gcc
LD = ld
OBJDUMP = objdump
LDFLAGS = -Wl,-Map=c1m2.map
# no HOST-specific additional CFLAGS, only the common ones
# CFLAGS += 
CPPFLAGs = 

else ifeq ($(PLATFORM),MSP432)
# Architectures Specific Flags
LINKER_FILE =  ../msp432p401r.lds
CPU = cortex-m4
ARCH = arm
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
CC = /usr/bin/arm-none-eabi-gcc
LD = /usr/bin/arm-none-eabi-ld
OBJDUMP = /usr/bin/arm-none-eabi-objdump
LDFLAGS = -Wl,-Map=c1m2.map -T $(LINKER_FILE) -nostdlib -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard \
  -mfpu=fpv4-sp-d16 $(SPECS)
CPPFLAGs = 
else
echo "FATAL: Value of PLATFORM must be either MSP432 or HOST"
endif

# The Professor showed us this one
OBJS := $(SOURCES:.c=.o)
DEPS := $(SOURCES:.c=.d)
# we want a -I prefix for each include directory
# This clever trick is kind of similar to the one above but much trickier
INCLUDE_FLAGS = $(addprefix -I,$(INCLUDES))

# Now our different build targets.  all/c1m2.out is the first and default target
.PHONY: all
all: c1m2.out
c1m2.out: $(OBJS) $(DEPS)
	$(CC) -o c1m2.out $(LDFLAGS) $(OBJS)
	size c1m2.out

%.o: %.c
	$(CC) $(INCLUDE_FLAGS) -c $(CFLAGS) $^
%.d: %.c
	$(CC) $(INCLUDE_FLAGS) -c $(CFLAGS) -MM -MF $@ $^

%.i: %.c
	$(CC) $(INCLUDE_FLAGS) -E $(CFLAGS) -o $@ $^

%.asm: %.c
	$(CC) $(INCLUDE_FLAGS) -S $(CFLAGS) -o $@ $^
	
%.asm: %.out
	$(OBJDUMP) --disassemble $^ >$@

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $(INCLUDE_FLAGS) $(CFLAGS) $(SOURCES)

.PHONY: build
build: c1m2.out

.PHONY: clean
clean:
	rm -f c1m2.map *.o c1m2.out *.asm *.i *.d

debug:
	#@echo "The contents of INC_DIRS is: [$(INC_DIRS)]"
	@echo "The contents of INCLUDES is: [$(INCLUDES)]"
	@echo "The contents of INCLUDE_FLAGS is: [$(INCLUDE_FLAGS)]"
	@echo "The full CC command would be: $(CC) -c $(INCLUDE_FLAGS) $(CFLAGS) $(SOURCES)"
