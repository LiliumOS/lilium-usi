#ifndef __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19
#define __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19

#include <bits/lang-version.h>

#ifdef __USE_CXX11 || __USE_C23
#define __LILIUM_NORETURN__ [[noreturn]]
#elif __USE_C11
#define __LILIUM_NORETURN__ _Noreturn
#elif __has_attribute(__noreturn__)
#define __LILIUM_NORETURN__ __attribute__((__noreturn__))
#else
#define __LILIUM_NORETURN
#endif

#endif /* __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19 */