#ifndef __LILIUM_USI_STDDEF_H_2025_05_19_02_18_36
#define __LILIUM_USI_STDDEF_H_2025_05_19_02_18_36

#include <bits/lang-version.h>

#if __USE_CXX11 || __USE_C23
#define NULL nullptr
#elif __USE_CXX98
#define NULL 0
#else
#define NULL ((void*)0)
#endif

#if __USE_C23
typedef typeof(nullptr) nullptr_t;
#elif __USE_CXX11
typedef decltype(nullptr) nullptr_t;
#endif

typedef unsigned long size_t;
typedef signed long ptrdiff_t;

#ifdef __USE_C11 || __USE_CXX11
typedef union {
    long double __m_float;
    long long __m_int;
#ifdef __SIZEOF_INT128__
    __int128 __m_int128;
#endif
} max_align_t;
#endif 


#define offsetof(st, id) __builtin_offsetof(st, id)

#endif /* __LILIUM_USI_STDDEF_H_2025_05_19_02_18_36 */