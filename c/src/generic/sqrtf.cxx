#include "math-impls.ixx"

extern "C"
{
    float sqrtf(float x) noexcept
    {
        return __usi_math_impls::sqrt(x);
    }
}