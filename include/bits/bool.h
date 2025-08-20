#ifndef __LILIUM_USI_BITS_BOOL_H_2025_07_22_20_04_34
#define __LILIUM_USI_BITS_BOOL_H_2025_07_22_20_04_34
#include <bits/lang-version.h>

#if __USE_CXX98 || __USE_C23
#define __bool bool
#elif __USE_C99
#define __bool _Bool
#else
#define __bool int
#endif

#endif /* __LILIUM_USI_BITS_BOOL_H_2025_07_22_20_04_34 */