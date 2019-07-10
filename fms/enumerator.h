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
            if (n != 0) {
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
            ++i;

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
            ++i;

            return *this;
        }
    };

    template<class I>
    inline constexpr auto sum(I i)
    {
        return i ? *i + sum(++i) : 0;
    }

}
