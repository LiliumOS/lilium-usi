## Build Defs
# Do not edit below this line
all: stamp
stamp: $(TARGETS:%=$(builddir)/%)
	touch stamp

.PHONY: all clean $(TARGETS:%=install-strip-%) $(TARGETS:%=install-%) install install-strip

.PRECIOUS: $(builddir)/%.so $(builddir)/%.a $(builddir)/$(output_name)/%.o

$(builddir)/%.so: $(OBJECTS:%.o=$(builddir)/$(output_name)/%.o) $(SHARED_OBJECTS:%.o=$(builddir)/$(output_name)/%.o)
	$(CC) $(ALL_LDFLAGS) -shared -nodefaultlibs -o$@ $^ 

$(builddir)/%.a: $(OBJECTS:%.o=$(builddir)/$(output_name)/%.o) $(STATIC_OBJECTS:%.o=$(builddir)/$(output_name)/%.o)
	$(AR) rcs $@ $^

$(builddir)/$(output_name)/%.o: src/%.c $(builddir)/$(output_name)
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) -c -o$@ $<

$(builddir)/$(output_name)/%.o: src/%.s $(builddir)/$(output_name)
	$(AS) $(ALL_ASFLAGS) -o$@ $<

$(builddir)/$(output_name)/%.o: src/$(ARCH)/%.c $(builddir)/$(output_name)
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) -c -o$@ $<

$(builddir)/$(output_name)/%.o: src/$(ARCH)/%.s $(builddir)/$(output_name)
	$(AS) $(ALL_ASFLAGS) -o$@ $<

$(builddir)/$(output_name):
	mkdir -p $@

clean:
	rm -f stamp

install-strip-%.a: install-%.a

INSTALL_DIR ?= $(SYSROOT)/$(libdir)

install-%.a:
	$(INSTALL) -m644 -D -t $(INSTALL_DIR) $(builddir)/$*.a

install-strip-%.so:
	$(INSTALL) -m644 --strip --strip-program=$(STRIP) -D -t $(INSTALL_DIR) $(builddir)/$*.so

install-%.so:
	$(INSTALL) -m644 -D -t $(INSTALL_DIR) $(builddir)/$*.so

install: $(TARGETS:%=install-%)

install-strip: $(TARGETS:%=install-strip-%)