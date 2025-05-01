AC_INIT([lilium-usi], [0.1], [https://github.com/LiliumOS/lilium-usi])

AC_CANONICAL_HOST

AC_ARG_VAR([CFLAGS])
AC_ARG_VAR([CC])

if [[ "$CC" \= "" ]]
then
    if [[ x$host_alias != x ]]
    then
        CC="$host_alias-cc"
    else
        CC="cc"
    fi
fi

if [[ "$CFLAGS" \= "" ]]
then
    CFLAGS="-g -O2"
fi

_OLD_CFLAGS="$CFLAGS"

AC_SUBST([CFLAGS])
AC_SUBST([CC])
AC_PROG_AR

AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_LN_S

AC_ARG_WITH([sysroot])

AC_ARG_VAR([LDFLAGS])
AC_ARG_VAR([CPPFLAGS])

AC_SUBST([LDFLAGS])
AC_SUBST([CPPFLAGS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT