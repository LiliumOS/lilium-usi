#ifndef __LILIUM_USI_CTYPE_H_2025_05_23_00_12_43
#define __LILIUM_USI_CTYPE_H_2025_05_23_00_12_43

#include <bits/lang-version.h>

#ifdef __LILIUM_USI_IMPL_CTYPE_H
#define __LILIUM_USI_INLINE_DEFS
#endif

#include <bits/inline.h>

#undef __LILIUM_USI_INLINE_DEFS

__LILIUM_USI_BEGIN_CDECLS
#ifdef __LILIUM_USI_HAS_INLINE
__LILIUM_USI_INLINE int islower(int __c)
{
    return ('a' <= __c && __c <= 'z');
}
__LILIUM_USI_INLINE int isupper(int __c)
{
    return ('A' <= __c && __c <= 'Z');
}
__LILIUM_USI_INLINE int isalpha(int __c)
{
    return isupper(__c) || islower(__c);
}
__LILIUM_USI_INLINE int isdigit(int __c)
{
    return '0' <= __c && __c <= '9';
}
__LILIUM_USI_INLINE int isalnum(int __c)
{
    return isalpha(__c) || isdigit(__c);
}

__LILIUM_USI_INLINE int isxdigit(int __c)
{
    return isdigit(__c) || ('A' <= __c && __c <= 'F') || ('a' <= __c && __c <= 'f');
}
__LILIUM_USI_INLINE int iscntrl(int __c)
{
    return 0 <= __c && (__c < ' ' || __c == 0x7F);
}
__LILIUM_USI_INLINE int isgraph(int __c)
{
    return ' ' < __c && __c < 0x7F;
}
__LILIUM_USI_INLINE int isspace(int __c)
{
    return (__c == ' ') || (__c == '\f') || (__c == '\n') || (__c == '\r') || (__c == '\t') || (__c == '\v');
}
__LILIUM_USI_INLINE int isprint(int __c)
{
    return isgraph(__c) || __c == ' ';
}
__LILIUM_USI_INLINE int ispunct(int __c)
{
    return isgraph(__c) && !isalnum(__c);
}
__LILIUM_USI_INLINE int tolower(int __c)
{
    if (isupper(__c))
        return __c + 0x20;
    else
        return __c;
}
__LILIUM_USI_INLINE int toupper(int __c)
{
    if (islower(__c))
        return __c - 0x20;
    else
        return __c;
}

#ifdef __USE_C99 || __USE_C11
__LILIUM_USI_INLINE int isblank(int __c)
{
    return (__c == ' ') || (__c == '\t');
}
#endif
#else
int isalpha(int __c);
int isdigit(int __c);
int isalnum(int __c);
int islower(int __c);
int isxdigit(int __c);
int iscntrl(int __c);
int isgraph(int __c);
int isspace(int __c);
int isprint(int __c);
int ispunct(int __c);
int tolower(int __c);
int toupper(int __c);

#ifdef __USE_C99 || __USE_C11
int isblank(int __c);
#endif
#endif
__LILIUM_USI_END_CDECLS

#endif /* __LILIUM_USI_CTYPE_H_2025_05_23_00_12_43 */