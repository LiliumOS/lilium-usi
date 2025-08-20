AC_INIT([lilium-usi], [0.1], [https://github.com/LiliumOS/lilium-usi])

AC_CANONICAL_HOST

case ["$host_os"] in
    "lilium-std" | "lilium" )
        ;;
    "lilium-kernel" )
        AC_MSG_WARN([Suspicious attempt to build userspace libraries for a kernelspace target.])
        if [ "$LILIUM_USI_SURPRESS_SUSPICIOUS_TARGET_ERROR" \= "" ]
        then
            AC_MSG_FAILURE([Target lilium-kernel is not buildable. Set "LILIUM_USI_SURPRESS_SUSPICIOUS_TARGET_ERROR" to a non-empty value if this is intentional.])
        fi
        ;;
    "lilium-*" )
        AC_MSG_WARN([Target $host_os is not supported. ABI may be incorrect. Add support for this environment, use a third-party USI, or use lilium-std to ensure support])
        ;;
    * )
        AC_MSG_FAILURE([Target $host_os is not supported.])
        ;;
esac


AC_PROG_CC
AC_PROG_CXX

AC_ARG_VAR([AS])
AC_ARG_VAR([ASFLAGS])
AC_PATH_TOOL([AS], [as])

if [[ "$AS" = "" ]]
then
    AC_MSG_FAILURE([Could not find assembler for $host. Set AS to the assembler to use, or add $host-as to PATH])
fi

AC_SUBST([ASFLAGS])

AC_PROG_AR

AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_LN_S

AC_ARG_WITH([sysroot], [Sets the sysroot for institation], [], [])

SYSROOT="$with_sysroot"

AC_SUBST([SYSROOT])


AC_ARG_ENABLE([subsystems], [Sets the subsystems to be built], [
    case "$enableval" in
        yes )
            enabled_subsystems="base thread io process debug kmgmt"
            ;;
        no  )
            enabled_subsystems=""
            ;;
        * )
            enabled_subsystems="$(echo "$enableval" | sed "s/,/ /g")"
            ;;
    esac
], [
    enabled_subsystems="base thread io process debug kmgmt"
])

AC_SUBST([enabled_subsystems])

AC_ARG_ENABLE([libraries], [Sets the userspace libraries to be built], [
    case "$enableval" in
        yes )
            enabled_libraries="c usi-unwind dl usi-rtld usi-init usi-support usi"
            ;;
        no  )
            enabled_libraries=""
            ;;
        * )
            enabled_libraries="$(echo "$1" | sed "s/,/ /g")"
            ;;
    esac
], [
    enabled_libraries="c usi-unwind dl usi-rtld usi-init usi-support usi"
])

AC_SUBST([enabled_libraries])

AC_ARG_ENABLE([shared], [Sets shared library support], [], [enable_shared=yes])
AC_ARG_ENABLE([static], [Sets static library support], [], [enable_static=yes])

AC_SUBST([enable_shared])
AC_SUBST([enable_static])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT