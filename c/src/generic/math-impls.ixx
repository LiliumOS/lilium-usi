#include <math.h>
#include <stdint.h>
#include <float.h>
#include <fenv.h>

namespace __usi_math_impls
{

    template <typename __T>
    struct __float_repr
    {
    };

    template <typename __T>
    using __int_ty = typename __float_repr<T>::__int_ty;

    template <typename __T>
    constexpr inline __int_ty<__T> __exp_bits = typename __float_repr<T>::__exp_bits;
    template <typename __T>
    constexpr inline __int_ty<__T> __mant_bits = typename __float_repr<T>::__mant_bits;

    template <typename __T>
    struct __split_float
    {
        bool _M_sign;
        __int_ty<__T> _M_exp;
        __int_ty<__T> _M_mant;
    };

    template <>
    struct __float_repr<float>
    {
        using __int_ty = int32_t;
        static constexpr int32_t __exp_bits = 8;
        static constexpr int32_t __mant_bits = 23;
    };

    template <>
    struct __float_repr<double>
    {
        using __int_ty = int64_t;
        static constexpr int64_t __exp_bits = 8;
        static constexpr int64_t __mant_bits = 23;
    };

    template <typename __T, size_t __Sz = sizeof(__T)>
    struct __long_double_repr;

    template <>
    struct __long_double_repr<long double, 8>
    {
        using __int_ty = int64_t;
    };

    template <>
    struct __long_double_repr<long double, 16>
    {
        using __int_ty = __int128;
    };

    template <>
    struct __float_repr<long double> : __long_double_repr<long double>
    {
        static constexpr typename __float_repr::__int_ty __mant_bits = __LDBL_MANT_DIG__ - 1;
        static constexpr typename __float_repr::__int_ty __exp_bits = ((sizeof(long double) * 8) - __LDBL_MANT_DIG__);
    };

    template <typename U, typename T>
    constexpr U __bit_cast(const T &__x) noexcept
    {
#if __has_builtin(__builtin_bit_cast)
        return __builtin_bit_cast(U, x);
#else
        union __imp
        {
            T __x;
            U __y;
        };
        __impl __cast{__x};
        return __cast.__y;
#endif
    }

    template <typename T>
    constexpr __split_float<T> __split(T x) noexcept
    {
        auto __x_bits = __bit_cast::<__int_ty<T>>(x);

        constexpr auto __exp_mask = (static_cast<__int_ty<T>>(1) << __exp_bits<T>)-1;
        constexpr auto __mant_mask = (static_cast<__int_ty<T>>(1) << __mant_bits<T>)-1;

        auto __exp_val = (__x_bits >> __mant_bits<T>)&__exp_mask;
        auto __mant_val = (__x_bits)&__mant_mask;

        auto __sign_bit = static_cast<bool>(__x_bits >> (__exp_bits<T> + __mant_bits<T>));

        return __split_float<T>{__sign_bit, __exp_val, __mant_val};
    }

    template <typename T>
    constexpr T __sqrt(T __val) noexcept
    {

        if (__val < 0.0)
        {
            if (!__builtin_is_constant_evaluated())
                feraiseexcept(FE_INVALID);
            return NAN;
        }

        auto [__sign_bit, __exp_val, __mant_val] = __split(__val);
    }
}
