# lilium-usi

Default USI for LiliumOS.

The USI Provides the following interfaces:
* Wrapper libraries for SCI functions (syscalls) exposed by the kernel,
* Functions from the ISO 9899 (C99 through C23),
* Unwind utilities, including the default exception handler,
* Interfaces with the runtime linker, and
* Additional API Support for interacting with the userspace.

## Build instructions

### Simple Build

If you have lilium build tools installed, you can just build using `make`. 
This builds the default configuration (see below).
The configuration can then be installed with `make install` or `make install-strip` (`SYSROOT` may be set here to modify the base of the install directory)

Make builds can be customized by setting various variables on the command line. However, for more complex setups, it is recommended to use the autotools build instead.

Variables that can be set:

* `ARCH`: The architecture to build for. Defaults to the x86_64 (Note: In the future, the host architecture will be detected)
* `TARGET`: The full target to build for. Defaults to `$(ARCH)-lilium-std`. Note that overriding this does not override ARCH, which can cause constitency issues. It is recommended not to set this unless you want to change the build type.
* `CC`: Path to the C compiler (expected to be compatible with gcc or clang). Defaults to `$(TARGET)-cc`, which must be found in `$PATH`
* `CXX`: Path to the C++ compiler (expected to be compatible with gcc or clang). Defaults to `$(TARGET)-c++`, which must be found in `$PATH`
* `AS`: Path to the assembler (expected to be compatible with GNU AS). Defaults to `$(TARGET)-as`, which must be found in `$PATH`
* `AR`: Path to the archiver. Defaults to `$(TARGET)-ar`, which must be found in `$PATH`
* `CFLAGS`: Additional flags for the C compiler. Defaults to `-O2 -g`
* `CXXFLAGS`: Additional flags to the C++ compiler.  Defaults to `-O2 -g`
* `CPPFLAGS`: Additional flags to the C Preprocessor (for both C and C++ source files)
* `ASFLAGS`: Additional flags to the assembler.
* `LDFLAGS`: Additional flags to the link wrapper (when building shared objects)
* `enabled_subsystems`: Subsystem wrapper libraries to build. Can be used to select subsystems without disabling userspace libraries. Defaults to all USI libraries
* `enabled_libraries`: All libraries to build. Note that overriding this will ignore the `enabled_subsystems` variable. Defaults to all subsystems set in `enabled_subsystems` plus all userspace libraries
* `build_shared`: Builds shared objects and dynamic linking support.
* `build_static`: Builds static libraries
    * Set `build_static=pic` to build static libraries with Position Independnt Code. Otherwise, static libraries are built with PIC if shared libraries are enabled, and PIE if shared libraries are disabled
* `SYSROOT`: Modifies the base directory for installs. Defaults to empty
* `prefix`: Install prefix (inside SYSROOT). Defaults to `/usr`
  * Other variables for the installdirs spec are provided and can be overriden.

### Autotools

When considerable configuration is used, it is recommended to use autotools to build instead of `make`. When running `configure`, the build directory must not be the same as the source directory, and must not be a parent directory. It must either be a subdirectory like `build` or an unrelated directory.

Note that the target for autotools must be specified explicitly when cross-compiling. Only lilium targets are supported. 
An error is issued for non-lilium kernels, and a warning is issued for non-standard environments.

All of the variables above can be set when building for makefile, and additionally can be configured for `./configure`:
* `CC`, `CXX`, `AS`, `AR`, `CFLAGS`, `CXXFLAGS`, `CPPFLAGS`, `ASFLAGS`, and `LDFLAGS` can all be set as environment variables for `./configure`
* `--with-sysroot` sets the default sysroot
* `--enable-subsystems=list` sets the subsystem wrapper libraries to build
    * `--disable-subsystems` disables all subsystems
* `--enable-libraries` sets the userspace libraries to build excluding subsystem wrapper libraries
    * `--disable-libraries` disables all userspace libraries and only builds subsystems
* `--enable-shared`/`--disable-shared` controls whether or not shared libraries and dynamic linking support should be built by default
* `--enable-static`/`--disabale-static` controls whether or not static libraries should be built by default:
    `--enable-static=pic` causes static libraries to be built with PIC enabled, even if shared libraries are disabled