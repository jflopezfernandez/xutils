AC_PREREQ([2.69])
AC_INIT([xutils], [1.0], [jflopezfernandez@gmail.com])
AM_INIT_AUTOMAKE([-Wall gnu])

# Define project language.
AC_LANG([C])

# Check for programs.
AC_PROG_CC
AC_PROG_MKDIR_P
AC_PROG_LN_S
AC_PROG_INSTALL

# Check for header files.
AC_CHECK_HEADERS([stdio.h stdlib.h])

# Configuration options.
AC_ARG_ENABLE([bin2dec],
    [AS_HELP_STRING([--disable-bin2dec],
        [disable bin2dec conversion utility (default is enabled)])],
    [bin2dec_enabled="$enableval"],
    [bin2dec_enabled=yes])

if test "x$bin2dec_enabled" = xyes
then
    AC_CONFIG_SUBDIRS([bin2dec])
fi

AC_ARG_ENABLE([crc32],
    [AS_HELP_STRING([--disable-crc32],
        [disable crc32 utility (default is enabled)])],
    [crc32_enabled="$enableval"],
    [crc32_enabled=yes])

if test "x$crc32_enabled" = xyes
then
    AC_CONFIG_SUBDIRS([crc32])
fi

# Define configuration files to be generated.
AC_CONFIG_FILES([
    Makefile
])

# Finish up configuration.
AC_OUTPUT
