// enumerator.h - forward iterator with operator bool() const when done
#pragma once
#include <compare>

namespace enumerator {

    template <class I>
    class counted {
        I i;
        size_t n;

    public:
        counted(I i, size_t n)
            : i(i)
            , n(n)
        {
        }

        auto operator<=>(const counted&) const = default;

        operator bool() const
        {
            return n != 0;
        }
        auto operator*()
        {
            return *i;
        }
        counted& operator++()
        {
            if (operator bool()) {
                ++i;
                --n;
            }

            return *this;
        }
    };

    template <class I>
    class null {
        I i;

    public:
        null(I i)
            : i(i)
        {
        }

        auto operator<=>(const null&) const = default;

        operator bool() const
        {
            return *i != 0;
        }
        auto operator*()
        {
            return *i;
        }
        null& operator++()
        {
            if (operator bool()) {
                ++i;
            }

            return *this;
        }
    };

    template <class I>
    class epsilon {
        I i;

    public:
        epsilon(I i)
            : i(i)
        {
        }

        auto operator<=>(const epsilon&) const = default;

        operator bool() const
        {
            return *i + 1 != 1; // true if *i greater than machine epsilon
        }
        auto operator*()
        {
            return *i;
        }
        epsilon& operator++()
        {
            if (operator bool()) {
                ++i;
            }

            return *this;
        }
    };

    // t, t + dt, t + 2 dt, ...
    template <class T>
    class sequence {
        T t, dt;

    public:
        sequence(T t = 0, T dt = 1)
            : t(t)
            , dt(dt)
        {
        }
        operator bool() const
        {
            return true;
        }
        T operator*()
        {
            return t;
        }
        sequence& operator++()
        {
            t += dt;

            return *this;
        }
    };

    template<class T = double>
    class factorial {
        T n, n_; // n, n!
    public:
        factorial()
            : n(1), n_(1)
        { }
        auto operator<=>(const factorial&) const = default;
        operator bool() const
        {
            return true;
        }
        T operator*()
        {
            return n_;
        }
        factorial& operator++()
        {
            n_ *= n;
            ++n;

            return *this;
        }
    };

#ifdef _DEBUG
}
inline void test_enumerator_factorial()
{
    enumerator::factorial<long> f;
    assert(*f == 1);
    ++f;
    assert(*f == 1);
    ++f;
    assert(*f == 2);
    assert(*++f == 2*3);
    assert(f && *++f == 2 * 3 * 4);
}
namespace enumerator {
#endif // _DEBUG

    template<class I, class J, class BinOp>
    class binop {
        I i;
        J j;
        BinOp op;
    public:
        binop(I i, J j)
            : i(i), j(j), op(BinOp{})
        { }
        auto operator<=>(const binop&) const = default;
        operator bool() const
        {
            return i && j;
        }
        auto operator*()
        {
            return op(*i, *j);
        }
        binop& operator++()
        {
            ++i;
            ++j;

            return *this;
        }
    };

    template <class I, class J>
    class concatenate {
        I i;
        J j;

    public:
        concatenate(I i, J j)
            : i(i)
            , j(j)
        {
        }
        operator bool() const
        {
            return j;
        }
        auto operator*()
        {
            return i ? *i : *j;
        }
        concatenate& operator++()
        {
            if (i)
                ++i;
            else if (j)
                ++j;

            return *this;
        }
    };

    template<class I, class X>
    inline constexpr auto poly(I i, X x)
    {
        return i ? *i + x * poly(++i, x) : 0;
    }

    template <class I>
    inline constexpr auto sum(I i)
    {
        return i ? *i + sum(++i) : 0;
    }

}
