// test.h - simple test class
#pragma once
#include <functional>
#include <iostream>

namespace fms {

    // test object constructor calls function
    struct test {
        test(const std::function<void(void)>& f) 
        {
            try {
                f();
            }
            catch (const std::exception& ex) {
                std::cerr << ex.what() << std::endl;
            }
        }
    };

}