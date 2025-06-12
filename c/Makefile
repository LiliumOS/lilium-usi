
OBJECTS := exit.o at_exit.o ctype.o div.o malloc.o malloc-helpers.o sqrt.o sqrtf.o sqrtld.o

SHARED_OBJECTS := 
STATIC_OBJECTS :=

TARGETS := 

output_name := c

LIBS := -lusi -lusi-support

ifeq ($(build_shared),yes)
	TARGETS += lib$(output_name).so
endif

ifeq ($(build_static),yes)
	TARGETS += lib$(output_name).a
endif


## Build Defs
# Do not edit below this line
include ../lib.mk