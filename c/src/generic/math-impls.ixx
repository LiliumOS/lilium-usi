#include <math.h>
#include <stdint.h>
#include <float.h>

namespace __usi_math_impls
{

    template <typename __T>
    struct __float_repr
    {
    };

    template <typename __T>
    using __int_ty = typename __float_repr<T>::__int_ty;

    template <typename __T>
    struct __split_float
    {
        __int_ty<__T> exp;
        __int_ty
    };

    template <>
    struct __float_repr<float>
    {
        using __int_ty = int32_t;
    };

    template <>
    struct __float_repr<double>
    {
        using __int_ty = int64_t;
    };

    template <>
    struct __float_repr<long double>
    {
        using __int_ty = __int128;
    };

    template <typename T>
    T sqrt(T val) noexcept
    {
        if (val < 0.0)
            return

                auto N =
    }
}
