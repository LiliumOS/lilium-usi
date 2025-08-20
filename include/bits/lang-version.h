#ifndef __LILIUM_USI_BITS_LANG_VERSION_H_205_05_19_02_40_10
#define __LILIUM_USI_BITS_LANG_VERSION_H_205_05_19_02_40_10

#define __USE_CXX98 (defined(__cplusplus))
#define __USE_CXX11 (__cplusplus >= 201103L)
#define __USE_CXX14 (__cplusplus >= 201402L)
#define __USE_CXX17 (__cplusplus >= 201703L)
#define __USE_CXX20 (__cplusplus >= 202002L)
#define __USE_CXX23 (__cplusplus >= 202302L)

#define __USE_C95 (defined(__STDC__))
#define __USE_C99 (defined(__STDC__))
#define __USE_C11 (__STDC_VERSION__ >= 201112L)
#define __USE_C17 (__STDC_VERSION__ >= 201710L)
#define __USE_C23 (__STDC_VERSION__ >= 202311L)

#ifdef __cplusplus
#define __LILIUM_USI_BEGIN_CDECLS \
    extern "C"                    \
    {
#define __LILIUM_USI_END_CDECLS }
#else
#define __LILIUM_USI_BEGIN_CDECLS
#define __LILIUM_USI_END_CDECLS
#endif

#if __USE_CXX11
#define __LILIUM_USI_CONSTEXPR_CXX11 constexpr
#else
#define __LILIUM_USI_CONSTEXPR_CXX11
#endif

#if __USE_CXX14
#define __LILIUM_USI_CONSTEXPR_CXX14 constexpr
#else
#define __LILIUM_USI_CONSTEXPR_CXX14
#endif

#if __USE_CXX17
#define __LILIUM_USI_CONSTEXPR_CXX17 constexpr
#else
#define __LILIUM_USI_CONSTEXPR_CXX17
#endif

#if __USE_CXX23
#define __LILIUM_USI_CONSTEXPR_CXX23 constexpr
#else
#define __LILIUM_USI_CONSTEXPR_CXX23
#endif

#endif /* __LILIUM_USI_BITS_LANG_VERSION_H_205_05_19_02_40_10 */