
OBJECTS := posix.o

TARGETS := 

output_name := dl

LIBS := 

ifeq ($(build_shared),yes)
	TARGETS += lib$(output_name).so
endif

ifeq ($(build_static),yes)
	TARGETS += lib$(output_name).a
endif


## Build Defs
# Do not edit below this line
include ../lib.mk