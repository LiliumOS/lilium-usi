#ifndef __LILIUM_BITS_THREAD_LOCAL_H_2025_05_14_00_12_52
#define __LILIUM_BITS_THREAD_LOCAL_H_2025_05_14_00_12_52

#include <bits/lang-version.h>

#if __USE_CXX11 || __USE_C23
#define __LILIUM_USI_HAS_THREAD_LOCAL 1
#define __LILIUM_USI_THREAD_LOCAL thread_local
#elif __USE_C11
#define __LILIUM_USI_HAS_THREAD_LOCAL 1
#define __LILIUM_USI_THREAD_LOCAL _Thread_local
#elif defined(__GNUC__)
#define __LILIUM_USI_HAS_THREAD_LOCAL 1
#define __LILIUM_USI_THREAD_LOCAL __thread
#else
#define __LILIUM_USI_HAS_THREAD_LOCAL 0
#endif

#endif /* __LILIUM_BITS_THREAD_LOCAL_H_2025_05_14_00_12_52 */