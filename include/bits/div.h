

#ifdef __LILIUM_USI_IMPL_DIV
#define __LILIUM_USI_INLINE_DEFS 1
#endif

#include <bits/inline.h>
#include <bits/lang-version.h>
#ifdef __LILIUM_USI_HAS_INLINE
#define __LILIUM_USI_DEF_DIV(__prefix, __ty)                                                           \
    typedef struct __##__prefix##div_t                                                                 \
    {                                                                                                  \
        __ty quot;                                                                                     \
        __ty rem;                                                                                      \
    } __prefix##div_t;                                                                                 \
    __LILIUM_USI_INLINE __LILIUM_USI_CONSTEXPR_CXX23 __prefix##div_t __prefix##div(__ty __x, __ty __y) \
    {                                                                                                  \
        __prefix##div_t __val = {__x / __y, __x % __y};                                                \
        return __val;                                                                                  \
    }
#else
#define __LILIUM_USI_DEF_DIV(__prefix, __ty) \
    typedef struct __##__prefix##div_t       \
    {                                        \
        __ty quot;                           \
        __ty rem;                            \
    } __prefix##div_t;                       \
    __prefix##div_t __prefix##div(__ty __x, __ty __y);
#endif

#undef __LILIUM_USI_INLINE_DEFS
