// enumerator.t.cpp - test enumerators
#include <cassert>
#include <limits>
#include <vector>
#include "test.h"
#include "enumerator.h"

using namespace fms;
using namespace enumerator;

test test_counted([]()
{
    std::vector<int> i{1,2,3};
    counted ci(&i[0], i.size());
    counted ci2{ ci };
    assert(ci2 == ci);
    ci = ci2;
    assert(!(ci != ci2));
    assert (ci);
    assert (*ci == 1);
    ++ci;
    assert(*ci == 2);
    assert(*++ci == 3);
    assert(!++ci);
    assert(!++ci);
});

test test_null([]()
    {
        std::vector<int> i{ 1, 2, 3, 0 };
        null ci(&i[0]);
        null ci2{ ci };
        assert(ci2 == ci);
        ci = ci2;
        assert(!(ci != ci2));
        assert(ci);
        assert(*ci == 1);
        ++ci;
        assert(*ci == 2);
        assert(*++ci == 3);
        assert(!++ci);
        assert(!++ci);
    });

test test_epsilon([]()
    {
        double constexpr eps = std::numeric_limits<double>::epsilon();
        assert(1 + eps != 1);
        assert(1 + eps / 2 == 1);
        std::vector<double> i{ 1, 2, eps, eps/2 };
        epsilon ci(&i[0]);
        epsilon ci2{ ci };
        assert(ci2 == ci);
        ci = ci2;
        assert(!(ci != ci2));
        assert(ci);
        assert(*ci == 1);
        ++ci;
        assert(*ci == 2);
        assert(*++ci == eps);
        assert(!++ci);
        assert(!++ci);
    });