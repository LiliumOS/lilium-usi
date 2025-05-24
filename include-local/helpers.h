#pragma once

#include <lilium-sci/types/uuid.h>
#include <lilium-sci/types/int.h>
#include <lilium-sci/types/str.h>
#include <lilium-sci/types/slice.h>
#include <lilium-sci/syscall.h>

#define UUID_EQ(a, b) ({                                  \
    Uuid __a = (a);                                       \
    Uuid __b = (b);                                       \
    (__a.minor == __b.minor) && (__a.major == __b.major); \
})

#define __EVAL0(x) x

#define EVAL(x) EVAL0(x)

#define __STRINGIFY0(...) #__VA_ARGS__

#define STRINGIFY(...) __STRINGIFY0(__VA_ARGS__)

#define NULL ((void*)0)


#define TRY_FILL_STR_CONST(ptr, val) ({\
    const char __val[sizeof(val)-1] = (val);\
    KStrPtr* __ptr = &(ptr);\
    __ilong __res = 0;\
    for(__ulong __i = 0; __i<sizeof(__val); __i++) {\
        if(__i > __ptr->len){__res = __LILIUM_ERRNO(SUBSYS_BASE, INSUFFICIENT_LENGTH); break;}\
        __ptr->str_ptr[__i] = __val[__i];\
    }\
    __ptr->len = sizeof(__val);\
    __res;\
})

#define CSLICE_EMPTY(__TY) ((KCSlice){.buf_ptr = (void*)(_Alignof(__TY)), .len = 0})
#define CSTR_EMPTY ((KStrCPtr){.str_ptr = (void*)1, .len = 0})