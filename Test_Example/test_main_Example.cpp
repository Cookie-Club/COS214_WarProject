/**
    \file test_main_Example.cpp
    \brief Basic examples of googletest testing
    \details Briefly explains googlest assertions, provides links to googletest guides, and provides a simple example
    \author Wian Koekemoer
    \date 3/11/22
*/
#include "gtest/gtest.h"
#include "Fixtures_Example.h"
/*
    All test methods work by using Assertions. Assertions basically declare that you expect a certain 
    condition to be fulfilled by two objects, and it notifies you when that declaration is false.
    For example, if you expect to string variables should be the same, you would assert; EXPECT_STRE(str1, str2)

    Assertions have two forms:
        EXPECT_*: If an assertion of this form fails, the remaining test will continue
        ASSERT_*: This confusingly named method halts the test entirely if it fails.

        EXPECT_* is usually preffered, unless the failure of a certain assertion would mean that any further 
        testing is pointless such as testing whether an object is not nullptr; ASSERT_NE(obj, nullptrptr)

    Documentation on the kinds of assertions: http://google.github.io/googletest/reference/assertions.html
    GoogleTest's user Guide: http://google.github.io/googletest/
    GoogleTest code samples: http://google.github.io/googletest/samples.html

*/
TEST(BasicTestSuite, BasicAssertions){
    //Strings not equal
    EXPECT_STRNE("hello", "world");
    //Numbers Equal
    EXPECT_EQ(7*6, 42);
}
//Uses the FixtureExample test fixture
TEST_F(FixtureExample, DataModification)
{
    *x_Fixt += 1;
    EXPECT_NE(*x_Fixt, 1);
    EXPECT_EQ(*x_Fixt, *y_Fixt);
    *y_Fixt -= 1;
    EXPECT_NE(*y_Fixt, 2);
}
//The state of FixtureExample did not persist after the FixtureExample.DataModification test
// as evidenced by the test on line 42 passing
TEST_F(FixtureExample, InitialState)
{
    // Assert that *x_Fixt == 1, and fail the test completely if that is not the case, because 
    // there would be no point in continuing if the initial state of the test isn't correct
    ASSERT_EQ(*x_Fixt, 1); 

    // Assert that *y_Fixt == 2, for same reason as above
    ASSERT_EQ(*y_Fixt, 2); // *y_Fixt == 2

    EXPECT_NE(*x_Fixt, *y_Fixt); // *x_Fixt != *y_Fix
    EXPECT_NE(x_Fixt, y_Fixt); // x_Fixt != y_Fix
}
