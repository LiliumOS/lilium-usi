
OBJECTS := 

TARGETS := 

output_name := usi

LIBS := 

ifeq ($(build_shared),yes)
	TARGETS += lib$(output_name).so
endif

ifeq ($(build_static),yes)
	TARGETS += lib$(output_name).a
endif


## Build Defs
# Do not edit below this line

stamp: $(TARGETS:%=$(builddir)/%)

$(builddir)/libusi.so:
	echo 'INPUT(AS_NEEDED(libusi-base.so libusi-thread.so libusi-io.so libusi-process.so libusi-debug.so libusi-kmgmt.so libusi-unwind.so libusi-rtld.so))' > $@

$(builddir)/libusi.a:
	echo 'INPUT(libusi-base.a libusi-thread.a libusi-io.a libusi-process.a libusi-debug.a libusi-kmgmt.a libusi-unwind.a)' > $@

clean:
	rm -f stamp

INSTALL_DIR ?= $(SYSROOT)$(libdir)

do-install-strip-%.a: do-install-%.a

do-install-%.a: $(builddir)/%.a
	$(INSTALL) -m644 -D -t $(INSTALL_DIR) $(builddir)/$*.a

do-install-strip-%.so: $(builddir)/%.so
	$(INSTALL) -m644 --strip --strip-program=$(STRIP) -D -t $(INSTALL_DIR) $(builddir)/$*.so

do-install-%.so: $(builddir)/%.so
	$(INSTALL) -m644 -D -t $(INSTALL_DIR) $(builddir)/$*.so

install: $(TARGETS:%=do-install-%)

install-strip: $(TARGETS:%=do-install-strip-%)