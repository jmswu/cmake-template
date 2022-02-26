#include "gtest/gtest.h"
#include "add.hpp"
#include "add.h"

namespace 
{
    class AddTest : public::testing::Test
    {
    public:
    private:
        
    protected:
        AddTest(){}

        virtual void SetUp()
        {

        }

        virtual void TearDown()
        {

        }
    };

    // testing CPP code
    TEST_F(AddTest, positiveNumber_cpp)
    {
        ASSERT_EQ(100, my::add(10, 90));
        ASSERT_EQ(123, my::add(100, 23));
    }

    // testing C code
    TEST_F(AddTest, positiveNumber_c)
    {
        ASSERT_EQ(100, add_c_code(10, 90));
        ASSERT_EQ(123, add_c_code(100, 23));
    }
}
