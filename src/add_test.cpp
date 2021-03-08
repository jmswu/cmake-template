#include "gtest/gtest.h"
#include "add.hpp"

namespace
{
    TEST(AddTest, positiveNumber)
    {
        ASSERT_EQ(100, add(10, 90));
        ASSERT_EQ(123, add(100, 23));
    }
}