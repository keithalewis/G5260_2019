// bell.t.cpp - test Bell polynomials
#include <cassert>
#include "test.h"
#include "bell.h"

using namespace fms;

test test_bell([]()
{
    double a[] = { 1, 1, 1, 1, 1 };
    {
        Bell<double*> B(a);
        assert(B[5] == 52);
        assert(B[4] == 15);
        assert(B[3] == 5);
        assert(B[2] == 2);
        assert(B[1] == 1);
        assert(B[0] == 1);
    }
    {
        Bell<double*> B(a);
        assert(B[0] == 1);
        assert(B[1] == 1);
        assert(B[2] == 2);
        assert(B[3] == 5);
        assert(B[4] == 15);
    }
}
);