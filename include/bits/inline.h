
#include <bits/lang-version.h>

#undef __LILIUM_USI_HAS_INLINE
#undef __LILIUM_USI_INLINE

#ifdef __LILIUM_USI_INLINE_DEFS
#define __LILIUM_USI_HAS_INLINE 1
#define __LILIUM_USI_INLINE extern inline
#elif __USE_C99 || __USE_CXX98
#define __LILIUM_USI_HAS_INLINE 1
#define __LILIUM_USI_INLINE inline
#elif __GNUC__
#define __LILIUM_USI_HAS_INLINE 1
#define __LILIUM_USI_INLINE __inline__
#else
#define __LILIUM_USI_HAS_INLINE 0
#endif
