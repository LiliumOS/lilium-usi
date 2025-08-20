
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

SYSROOT = 


build_shared = yes
build_static = yes

CFLAGS = -O2 -g
CXXFLAGS = -O2 -g
LDFLAGS = 
CPPFLAGS = 
ASFLAGS = 

ARCH = x86_64
TARGET = $(ARCH)-lilium-std

CC = $(TARGET)-cc
CXX = $(TARGET)-c++
AR = $(TARGET)-ar
AS = $(TARGET)-as

INSTALL = install
MKDIR_P = mkdir -p
LN_S = ln -s

enabled_subsystems = base thread io process debug kmgmt

enabled_libs = $(enabled_subsystems:%=usi-%) c usi-unwind dl usi-rtld usi-init usi-support usi


## Build Configuration 
# 

ALL_CPPFLAGS := $(CPPFLAGS) -isystem $(srcdir)/lilium-knums/include -isystem $(srcdir)/include -isystem $(srcdir)/arch-include/$(ARCH) -I$(srcdir)/include-local -nostdinc

ALL_CFLAGS := $(CFLAGS) -Wno-overflow -ffreestanding -masm=intel -std=gnu23 -ftls-model=initial-exec

ALL_CXXFLAGS := $(CXXFLAGS) -Wno-ovverflow -ffrestanding -masm=intel -std=gnu++23 -ftls-model=initial-exec

ALL_LDFLAGS := $(LDFLAGS) -nodefaultlibs -nostartfiles -L$(builddir)/

ALL_ASFLAGS := $(ASFLAGS) -msyntax=intel -mnaked-reg

ifeq ($(build_shared),yes)
	ALL_CFLAGS += -fPIC
	ALL_CXXFLAGS += -fPIC
	ALL_ASFLAGS += -mshared
else
	ALL_CFLAGS += -fPIE
	ALL_CXXFLAGS += -fPIE
endif


## Build Rules
# Do not Edit below this line

export CC CXX AR AS ALL_CFLAGS ALL_CXXFLAGS ALL_CPPFLAGS ALL_LDFLAGS ALL_ASFLAGS INSTALL prefix exec_prefix libdir syslibdir includedir sysconfidr sharedstatedir runstatedir localstatedir datarootdir datadir ARCH TARGET build_shared build_static SYSROOT srcdir builddir

.PHONY: all install clean distclean install-strip

all: stamp

stamp: $(enabled_libs:%=%/stamp) lilium-knums/include/stamp
	touch stamp

include $(enabled_libs:%=%/build.d)

$(enabled_libs:%=%/stamp): %/stamp: %/Makefile lib.mk lilium-knums/include/stamp
	+$(MAKE) -C $* stamp

lilium-knums/include/stamp:
	+$(MAKE) -C lilium-knums include/stamp

distclean: clean

clean: clean-usi-base clean-usi-thread clean-usi-io clean-usi-process clean-usi-debug clean-usi-kmgmt clean-c clean-dl clean-usi-unwind clean-usi-rtld clean-usi-init
	rm -f stamp
	rm -rf build/

clean-%:
	+$(MAKE) -C $* clean

do-install-strip-%:
	+$(MAKE) -C $* install-strip

do-install-normal-%:
	+$(MAKE) -C $* install

do-install-include: lilium-knums/include/stamp
	cd include/ && find . \( -name '*.h' -o -name '*.hpp' -o -name '*.hxx' \) -exec $(INSTALL) -Dm755 {} $(SYSROOT)$(includedir)/{} \;
	cd arch-include/$(ARCH)/ && find . \( -name '*.h' -o -name '*.hpp' -o -name '*.hxx' \) -exec $(INSTALL) -Dm755 {} $(SYSROOT)$(includedir)/{} \;
	cd lilium-knums/include/ && find . -name '*.h' -exec $(INSTALL) -Dm755 {} $(SYSROOT)$(includedir)/{} \;

install: $(enabled_libs:%=do-install-normal-%) do-install-include

install-strip: $(enabled_libs:%=do-install-strip-%) 

