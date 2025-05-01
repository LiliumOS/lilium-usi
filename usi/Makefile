
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

$(builddir)/libusi.so:
	echo 'INPUT(libusi-base.so libusi-thread.so libusi-io.so libusi-process.so libusi-debug.so libusi-kmgmt.so libusi-unwind.so libusi-rtld.so)' > $@

$(builddir)/libusi.a:
	echo 'INPUT(libusi-base.a libusi-thread.a libusi-io.a libusi-process.a libusi-debug.a libusi-kmgmt.a libusi-unwind.a)' > $@