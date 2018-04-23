// author Trevor Fountain
// author Johannes Buchner
// author Erik Garrison
// date 2010-2014
// copyright BSD 3-Clause


#include "progress/progress.h"

#include "gtest/gtest.h"

#include <stdint.h>
#include <thread>

namespace
{
    TEST(Progress, InitializerList)
    {
        for (auto i : Progress({ 1, 2, 3, 4 }))
        {
            (void)i;
            //std::cout << i;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    TEST(Progress, Vector)
    {
        for (volatile size_t j = 0; j < 100; ++j)
        {
            std::vector< uint32_t > vec = { 1, 2, 3, 4 };

            for (auto i : Progress(vec))
            {
                (void)i;
                //std::cout << i;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    }

    TEST(Progress, Nested)
    {
        for (auto j : Progress({ 1, 2, 3, 4 }))
        {
            for (auto i : Progress({ 1, 2, 3 }))
            {
                for (auto k : Progress({ 1, 2, 3}))
                {
                    (void)i, (void)j, (void)k;
                    //std::cout << i;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
            }
        }
    }
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    int32_t result = RUN_ALL_TESTS();

    return result;
}