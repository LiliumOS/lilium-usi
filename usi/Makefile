
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
	echo 'INPUT(AS_NEEDED(=$(libdir)/libusi-base.so =$(libdir)/libusi-thread.so =$(libdir)/libusi-io.so =$(libdir)/libusi-process.so =$(libdir)/libusi-debug.so =$(libdir)/libusi-kmgmt.so =$(libdir)/libusi-unwind.so =$(libdir)/libusi-rtld.so))' > $@

$(builddir)/libusi.a:
	echo 'INPUT(=$(libdir)/libusi-base.a =$(libdir)/libusi-thread.a =$(libdir)/libusi-io.a =$(libdir)/libusi-process.a =$(libdir)/libusi-debug.a =$(libdir)/libusi-kmgmt.a =$(libdir)/libusi-unwind.a)' > $@

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