#ifndef __LILIUM_USI_BITS_NOEXCEPT_H_2025_06_05_17_19_07
#define __LILIUM_USI_BITS_NOEXCEPT_H_2025_06_05_17_19_07

#include <bits/lang-version.h>
#include <bits/has-builtin.h>

#if __USE_CXX11
#define __LILIUM_USI_NOEXCEPT noexcept
#elif __USE_CXX98
#define __LILIUM_USI_NOEXCEPT throw()
#elif __lilium_usi_has_attribute(__nothrow__)
#define __LILIUM_USI_NOEXCEPT __attribute__((__nothrow__))
#else
#define __LILIUM_USI_NOEXCEPT
#endif

#endif /* __LILIUM_USI_BITS_NOEXCEPT_H_2025_06_05_17_19_07 */