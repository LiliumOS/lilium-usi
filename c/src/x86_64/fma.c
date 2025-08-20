
#include <fenv.h>


static double fma_avx(double x, double y, double z) __attribute__((__naked__)) {
    __asm__("vfmadd213ss xmm0, xmm1, xmm2\nret");
}

typedef float __m128 __attribute__((__vector_size__(16)));
typedef double __m128d __attribute__((__vector_size__(16)));

union double_bits {
    double __val;
    struct {
        long __mant: 52;
        long __exp: 11;
        int __sign: 1;
    };
};

static double fma_basic(double x, double y, double z){
    #pragma FENV_ACCESS ON
    fenv_t f;
    fegetenv(&f);
    feclearexcept(FE_INEXACT);
    double base_product = x*y;
    if(!fetestexcept(FE_INEXACT))
        return base_product + z; // This is the exact result

    return (double)((__float80)x * (__float80) y + (__float80)z);
}


static void* resolve_fma(void) {
    if(__builtin_cpu_supports("fma"))
        return fma_avx;
    else
        return fma_basic;
}

double fma(double x, double y, double z) __attribute__((__ifunc__("resolve_fma")));


long double fmal(long double x, long double y, long double z) {
    return fma(x, y, z);
}