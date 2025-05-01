## Build Defs
# Do not edit below this line
all: stamp
stamp: $(TARGETS:%=$(builddir)/%)
	touch stamp


$(builddir)/%.so: $(OBJECTS:%.o=$(builddir)/$(output_name)/%.o) $(SHARED_OBJECTS:%.o=$(builddir)/$(output_name)/%.o)
	$(CC) $(ALL_LDFLAGS) -shared -nodefaultlibs -o$@ $^ 

$(builddir)/%.a: $(OBJECTS:%.o=$(builddir)/$(output_name)/%.o) $(STATIC_OBJECTS:%.o=$(builddir)/$(output_name)/%.o)
	$(AR) rcs $@ $^

$(builddir)/$(output_name)/%.o: stc/%.c $(builddir)/$(output_name)
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) -c -o$@ $<

$(builddir)/$(output_name):
	mkdir -p $@

clean:
	rm -f stamp