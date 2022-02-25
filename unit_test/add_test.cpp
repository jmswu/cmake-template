#include "gtest/gtest.h"
#include "add.hpp"

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

    TEST_F(AddTest, positiveNumber)
    {
        ASSERT_EQ(100, add(10, 90));
        ASSERT_EQ(123, add(100, 23));
    }
}
