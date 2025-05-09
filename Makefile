
## Variables from autotools
# Add or remove substituted variables only
srcdir ::= $(shell pwd)
builddir ::= $(shell pwd)/build

prefix = /usr/local
exec_prefix = $(prefix)

libdir = $(prefix)/lib
includedir = $(prefix)/include
syslibdir = /lib
sysconfdir = $(prefix)/etc
sharedstatedir = $(prefix)/com
localstatedir = $(prefix)/var
runstatedir = $(localstatedir)/run
datarootdir = $(prefix)/usr
datadir = $(datarootdir)

ARCH = x86_64

TARGET = $(ARCH)-lilium-std

SYSROOT = 


build_shared = yes
build_static = yes

CFLAGS = -O2 -g
LDFLAGS = 
CPPFLAGS = 
ASFLAGS = 

CC = $(TARGET)-cc
AR = $(TARGET)-ar
AS = $(TARGET)-as

INSTALL = install
MKDIR_P = mkdir -p
LN_S = ln -s

enabled_subsystems = base thread io process debug kmgmt

enabled_libs = $(enabled_subsystems:%=usi-%) c usi-unwind dl usi-rtld usi-init


## Build Configuration 
# 

ALL_CPPFLAGS := $(CPPFLAGS) -isystem $(srcdir)/lilium-knums/include -isystem $(srcdir)/include -I$(srcdir)/include-local -nostdinc

ALL_CFLAGS := $(CFLAGS) -ffreestanding -masm=intel -std=gnu11 -ftls-model=initial-exec

ALL_LDFLAGS := $(LDFLAGS) -nodefaultlibs -nostartfiles

ALL_ASFLAGS := $(ASFLAGS) -msyntax=intel -mnaked-reg

ifeq ($(build_shared),yes)
	ALL_CFLAGS += -fPIC
	ALL_ASFLAGS += -mshared
else
	ALL_CFLAGS += -fPIE
endif

ALL_LDFLAGS = $(LDFLAGS)


## Build Rules
# Do not Edit below this line

export CC AR AS ALL_CFLAGS ALL_CPPFLAGS ALL_LDFLAGS ALL_ASFLAGS INSTALL prefix exec_prefix libdir syslibdir includedir sysconfidr sharedstatedir runstatedir localstatedir datarootdir datadir ARCH TARGET build_shared build_static SYSROOT srcdir builddir

.PHONY: all install clean distclean install-strip $(enabled_libs:%-clean-%) 

all: stamp

stamp: $(enabled_libs:%=%/stamp) lilium-knums/include/stamp
	touch stamp

include $(enabled_libs:%=%/build.d)

$(enabled_libs:%=%/stamp): %/stamp: %/Makefile lib.mk lilium-knums/include/stamp
	+$(MAKE) -C $* stamp

lilium-knums/include/stamp:
	+$(MAKE) -C lilium-knums include/stamp

distclean: clean

clean: $(enabled_libs:%=clean-%)
	rm -f stamp
	rm -rf build/

clean-%:
	+$(MAKE) -C $* clean
	