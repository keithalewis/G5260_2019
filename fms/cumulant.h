// cumulant.h - Functions involving cumulants.
// If X is a random variable, its _cumulant_ is $kappa(s) = log E exp(sX)$.
// The _cumulants_, $kappa_n$, are defined by $kappa(s) = sum_n > 0_ kappa_n s^n/n!$.
#pragma once
#include "bell.h"
#include "normal.h"
#include "hermite.h"

namespace fms {

    template <class X = double>
    class cumulant {
        // K kappa
        inline X cdf(const X& x)
        {
            return x;
        }
    };

}
