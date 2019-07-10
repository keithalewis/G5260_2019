// enumerator.h - forward iterator with operator bool() const when done
#pragma once
#include <compare>

namespace enumerator {

    template<class I>
    class counted {
        I i;
        size_t n;
    public:
        counted(I i, size_t n)
            : i(i), n(n)
        { }

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

    template<class I>
    class null {
        I i;
    public:
        null(I i)
            : i(i)
        { }

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

    template<class I>
    class epsilon {
        I i;
    public:
        epsilon(I i)
            : i(i)
        { }

        auto operator<=>(const epsilon&) const = default;
        
        operator bool() const
        {
            return *i + 1 != 1; // false if *i greater than machine epsilon
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
    template<class T>
    class sequence {
        T t, dt;
    public:
        sequence(T t = 0, T dt = 1)
            : t(t), dt(dt)
        { }
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

    template<class I>
    inline constexpr auto sum(I i)
    {
        return i ? *i + sum(++i) : 0;
    }

}
