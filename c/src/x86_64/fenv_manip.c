#include <fenv.h>

int fetestexcept(int __excepts) {
    fenv_t f;
    fegetenv(&f);
    return f.__except & __excepts;
}

int feclearexcept(int __excepts) {
    fenv_t f;
    fegetenv(&f);
    f.__excepts &= ~__excepts;
    return fesetenv(&f);
}
