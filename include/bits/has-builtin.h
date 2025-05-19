#ifndef __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19
#define __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19

#ifdef __has_builtin
#define __lilium_usi_has_builtin(x) __has_builtin(x)
#elif
#define __lilium_usi_has_builtin(x) (0)
#endif

#ifdef __has_attribute
#define __lilium_usi_has_attribute(x) __has_attribute(x)
#elif
#define __lilium_usi_has_attribute(x)
#endif

#endif /* __LILIUM_BITS_HAS_BUILTIN_H_2025_05_19 */