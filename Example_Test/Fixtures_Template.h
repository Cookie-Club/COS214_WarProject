#include "gtest/gtest.h"

class FixtureClassName: public ::testing::Test
{
    protected:
        void SetUp()
        {
            //Do stuff
        };
        void TearDown()
        {
            //Undo stuff
        };

        //Member variables go here
}