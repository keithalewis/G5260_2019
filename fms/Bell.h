// Bell.h - Bell polynomials
// The complete Bell polynomials, B_n_(x_1_,...,x_n_), are defined by
// exp(&sum;_n&gt;0_ x_n_ s^n^/n!) = &sum;_n&ge;0_ B_n_(x_1_,...,x_n_) s^n^/n!
// Taking a derivative with respect to s and equating powers of s shows
// B_n+1_(x_1_,...,x_n+1_) = &sum;_k = 0_^n^ choose(n,k) B_n-k_(x_1_,...,x_n-k_) x_k+1_.
#pragma once
#include <map>

namespace fms {

    template<class X, class S>
    class Bell {
        S kappa;
        std::map<size_t,X> B;
    public:
        Bell(S kappa)
            : kappa(kappa)
        { }
        X operator()(size_t n)
        {
            auto i = B.find(n);
            if (i != B.end()) {
                return *i;
            }
            X Bn = 0;
            // Bn = ...
            B[n] = Bn;

            return Bn;
        }
    };
}
