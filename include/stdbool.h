#ifndef __LILIUM_USI_STDBOOL_H_2025_07_22_20_06_33
#define __LILIUM_USI_STDBOOL_H_2025_07_22_20_06_33

#include <bits/lang-version.h>

#if !__USE_CXX98 && !__USE_C23
#if __USE_C99
#define bool _Bool
#else
#define bool int
#endif
#define true 1
#define false 0
#endif

#endif /* __LILIUM_USI_STDBOOL_H_2025_07_22_20_06_33 */