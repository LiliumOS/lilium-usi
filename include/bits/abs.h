
// expect bits/lang-version.h to be included already
// Also expect bits/noexcept.h to be included :P

#ifdef __LILIUM_USI_DEF_ABS
#define __LILIUM_USI_INLINE_DEFS
#endif

#include <bits/inline.h>

#if __LILIUM_USI_HAS_INLINE

__LILIUM_USI_INLINE double fabs(double __val) __LILIUM_USI_NOEXCEPT
{
    if (__val < 0.0)
        return -__val;
    else if (__val == 0.0)
        return 0.0;
    else
        return __val;
}

#if __USE_C99 || __USE_CXX98 || __LILIUM_USI_DEF_ABS
__LILIUM_USI_INLINE float fabsf(float __val) __LILIUM_USI_NOEXCEPT
{
    if (__val < 0.0)
        return -__val;
    else if (__val == 0.0)
        return 0.0;
    else
        return __val;
}

__LILIUM_USI_INLINE long double fabsl(long double __val) __LILIUM_USI_NOEXCEPT
{
    if (__val < 0.0)
        return -__val;
    else if (__val == 0.0)
        return 0.0;
    else
        return __val;
}

#endif
#else

double fabs(double __val) __LILIUM_USI_NOEXCEPT;

#if __USE_C99 || __USE_CXx98
float fabsf(float __val) __LILIUM_USI_NOEXCEPT;
long double fabsl(long double __val) __LILIUM_USI_NOEXCEPT;
#endif

#endif