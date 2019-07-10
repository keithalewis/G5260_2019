// option.h - Forward value for put and call options.
// Forward F = f exp(sX - kappa(s)) where E[X] = 0, Var(X) = 1, kappa(s) = log E[exp(sX)].
#pragma once
#include <cmath>
#include <functional>

namespace fms::option {

    template<class Kappa, class S = double> 
    class cumulant {
        std::function<S(S)> kappa;
        Kappa kappas;
    };

    // Solve F = f exp(sX - kappa(s)) = k for X.
    template<class F = double, class S = double, class K = double>
    inline auto moneyness(const F& f, const S& s, const K& k, const std::function<S(S)>& kappa)
    {
        return (kappa(s) + log(k/f))/s;
    }

    // E max{k - F, 0} = k P(F <= k) - f P^s(F <= k) where dP^s/dP = exp(sX - kappa(s))
    template<class F = double, class S = double, class K = double>
    inline auto put(const F& f, const S& s, const K& k, const std::function<S(S)>& kappa)
    {
        auto x = moneyness(f, s, k, kappa);

        return k * P(0,x) - f * P(s,x);
    }

}