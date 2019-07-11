// normal.t.cpp - test the normal distribution
#include <cassert>
#include "normal.h"
#include "test.h"

using namespace fms;

test test_normal([]() {
    assert(normal::cdf<double>(0) == 0.5);
    assert(normal::pdf<double>(0) == normal::M_1_SQRT2PI);
});