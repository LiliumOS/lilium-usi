
#include <lilium-sci/types/int.h>

#include <bits/bool.h>

typedef __u16 fexcept_t;

#define FE_INVALID (1)
#define FE_DENORMAL (2)
#define FE_DIVBYZERO (4)
#define FE_OVERFLOW (8)
#define FE_UNDERFLOW (16)
#define FE_PRECISION (32)

#define FE_ALL_EXCEPT (0x3F)

#define FE_TONEAREST (0)
#define FE_DOWNWARD (1)
#define FE_UPWARD (2)
#define FE_TOWARDZERO (3)

typedef struct __fenv_t
{
    union
    {
        struct
        {
            fexcept_t __except : 6;
            __bool __daz : 1;
            fexcept_t __emask : 6;
            unsigned __rc : 2;
            __bool __ftz : 1;
            unsigned __reserved16 : 16;
        };
        __u32 __mxcsr_val;
    };
#if 0
    union
    {
        struct
        {
            fexcept_t __except : 7;
            __bool __except_status : 1;
            unsigned __cond0 : 3;
            unsigned __reserved_tos : 3;
            unsigned __cond3 : 1;
            __bool __fpu_busy : 1;
        } __fpsw;
        __u16 __fpsw_val;
    };
    union
    {
        struct
        {
            fexcept_t __emask : 6;
            unsigned __reserved6 : 6;
            unsigned __precision : 2;
            unsigned __rc : 2;
            __bool __infx : 1;
            unsigned __reserved13 : 1;
        } __fpcw;
        __u16 __fpcw_val;
    };
#endif
} fenv_t;
