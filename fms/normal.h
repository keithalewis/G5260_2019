// normal.h - standard normal distribution
#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

namespace fms {

struct normal {
    static constexpr const double M_1_SQRT2PI = M_2_SQRTPI * M_SQRT1_2/2;

    template <class X = double>
    static X pdf(const X& x)
    {
        return exp(-x * x / 2) * M_1_SQRT2PI;
    }
    template <class X = double>
    static X cdf(const X& x)
    {
        return erfc(-x / M_SQRT2) / 2;
    }
};

} // namespace fms
