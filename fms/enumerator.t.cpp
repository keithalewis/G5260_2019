// enumerator.t.cpp - test enumertors
#include <cassert>
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