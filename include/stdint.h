#ifndef __LILIUM_USI_STDINT_H_2025_05_24_14_05_19
#define __LILIUM_USI_STDINT_H_2025_05_24_14_05_19

#include <lilium-sci/types/int.h>

#include <bits/lang-version.h>

typedef __u8 uint8_t;
typedef __i8 int8_t;
typedef __u16 uint16_t;
typedef __i16 int16_t;
typedef __u32 uint32_t;
typedef __i32 int32_t;
typedef __u64 uint64_t;
typedef __i64 int64_t;

typedef __ulong uintptr_t;
typedef __ilong intptr_t;

typedef __u64 uintmax_t;
typedef __i64 intmax_t;

#define __LILIUM_USI_DEF_LEAST_FAST(__N) \
    typedef uint##__N##_t uint_least##__N##_t;\
    typedef int##__N##_t int_least##__N##_t;\
    typedef uint##__N##_t uint_fast##__N##_t;\
    typedef int##__N##_t int_fast##__N##_t

__LILIUM_USI_DEF_LEAST_FAST(8);
__LILIUM_USI_DEF_LEAST_FAST(16);
__LILIUM_USI_DEF_LEAST_FAST(32);
__LILIUM_USI_DEF_LEAST_FAST(64);


#define UINT8_C(__x) ((__u8)(__x ## U))
#define UINT16_C(__x) ((__u16)(__x ## U))
#define UINT32_C(__x) ((__u32)(__x ## U))
#define UINT64_C(__x) ((__u64)(__x ## ULL))

#define UINTMAX_C(__x) ((__u64)(x ## ULL))

#define INT8_C(__x) ((__i8)(__x))
#define INT16_C(__x) ((__i16)(__x))
#define INT32_C(__x) ((__i32)(__x))
#define INT64_C(__x) ((__i64)(__x ## LL))

#define INTMAX_C(__x) ((__i64)(x ## LL))

#define INT8_MIN INT8_C(0x80)
#define INT8_MAX INT8_C(0x7F)
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST8_MAX INT8_MAX
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST8_MAX INT8_MAX

#define INT16_MIN INT16_C(0x8000)
#define INT16_MAX INT16_C(0x7FFF)
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST16_MAX INT16_MAX
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST16_MAX INT16_MAX

#define INT32_MIN INT32_C(0x80000000)
#define INT32_MAX INT32_C(0x7FFFFFFF)
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST32_MAX INT32_MAX
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST32_MAX INT32_MAX

#define INT64_MIN INT64_C(0x8000000000000000)
#define INT64_MAX INT64_C(0x7FFFFFFFFFFFFFFF)
#define INT_LEAST64_MIN INT64_MIN
#define INT_LEAST64_MAX INT64_MAX
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST64_MAX INT64_MAX


#define UINT8_MIN UINT8_C(0)
#define UINT8_MAX UINT8_C(0xFF)
#define UINT_LEAST8_MIN UINT8_MIN
#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_FAST8_MIN UINT8_MIN
#define UINT_FAST8_MAX UINT8_MAX

#define UINT16_MIN UINT16_C(0)
#define UINT16_MAX UINT16_C(0xFFFF)
#define IINT_LEAST16_MIN IINT16_MIN
#define IINT_LEAST16_MAX IINT16_MAX
#define IINT_FAST16_MIN IINT16_MIN
#define IINT_FAST16_MAX IINT16_MAX

#define UINT32_MIN UINT32_C(0)
#define UINT32_MAX UINT32_C(0xFFFFFFFF)
#define UINT_LEAST32_MIN UINT32_MIN
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_FAST32_MIN UINT32_MIN
#define UINT_FAST32_MAX UINT32_MAX

#define UINT64_MIN UINT64_C(0)
#define UINT64_MAX UINT64_C(0xFFFFFFFFFFFFFFFF)
#define UINT_LEAST64_MIN UINT64_MIN
#define UINT_LEAST64_MAX UINT64_MAX
#define UINT_FAST64_MIN UINT64_MIN
#define UINT_FAST64_MAX UINT64_MAX

#define UINTPTR_MIN 0UL
#if __SIZEOF_POINTER__==4
#define UINTPTR_MAX 0xFFFFFFFFUL

#define INTPTR_MIN 0x80000000L
#define INTPTR_MAX 0x7FFFFFFFL
#else
#define UINTPTR_MAX 0xFFFFFFFFFFFFFFFFUL

#define INTPTR_MIN 0x8000000000000000L
#define INTPTR_MAX 0x7FFFFFFFFFFFFFFFL
#endif 

#define UINTMAX_MIN UINT64_MIN
#define UINTMAX_MAX UINT64_MAX 

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX

#ifdef __USE_C23
#define INT8_WIDTH 8
#define INT16_WIDTH 16
#define INT32_WIDTH 32
#define INT64_WIDTH 64
#define UINT8_WIDTH 8
#define UINT16_WIDTH 16
#define UINT32_WIDTH 32
#define UINT64_WIDTH 64

#define INT_LEAST8_WIDTH INT8_WIDTH
#define INT_LEAST16_WDITH INT16_WIDTH 
#define INT_LEAST32_WIDTH INT32_WIDTH
#define INT_LEAST64_WIDTH INT64_WIDTH
#define UINT_LEAST8_WIDTH UINT8_WIDTH
#define UINT_LEAST16_WIDTH UINT16_WIDTH
#define UINT_LEAST32_WIDTH UINT32_WIDTH
#define UINT_LEAST64_WIDTH UINT64_WIDTH

#define INT_FAST8_WIDTH INT8_WIDTH
#define INT_FAST16_WDITH INT16_WIDTH 
#define INT_FAST32_WIDTH INT32_WIDTH
#define INT_FAST64_WIDTH INT64_WIDTH
#define UINT_FAST8_WIDTH UINT8_WIDTH
#define UINT_FAST16_WIDTH UINT16_WIDTH
#define UINT_FAST32_WIDTH UINT32_WIDTH
#define UINT_FAST64_WIDTH UINT64_WIDTH
#endif



#if __USE_C23 || __USE_CXX23
typedef __u128 uint128_t;
typedef __i128 int128_t;
__LILIUM_USI_DEF_LEAST_FAST(128);
#endif

#endif /* __LILIUM_USI_STDINT_H_2025_05_24_14_05_19 */