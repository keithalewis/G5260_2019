// test.h - simple test class
#pragma once
#include <cstdio>
#include <functional>

namespace fms {

// test object constructor calls function
// e.g. `fms::test my_test([](){ test_things(); });`
struct test {
    test(const std::function<void(void)>& _)
    {
        try {
            _();
        } catch (const std::exception& ex) {
            fputs(ex.what(), stderr);
        }
    }
};

}

#define FMS_TEST(f) fms::test f##_test([]() { f(); });