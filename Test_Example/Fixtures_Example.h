#include "gtest/gtest.h"
/**
    \file Fixtures_Example.h
    \brief Example file for how to create Test Fixtures to be used by googletest
    \details Declares an example Test Fixtures and also contains a brief 
    summary of how Test Fixtures work
    \author Wian Koekemoer
    \date 3/11/22
*/
/*
    Summary:

    Declare Fixture classes in a <PatternName>Fixtures.h file

    Fixture classes are basically objects that construct a template data configuration
    that can be used by multiple tests

    The TEST method simply declares and instantiates all of the objects that it will 
    use inside of its method scope

    The TEST_F method uses a fixture object to create variables that may be used in the test.
    Multiple TEST_F methods may share a Ficture class such that multiple tests may be
    performed on objects with the exact same states. 

        NB!: Take note that the changes in a Fixture object's state do not persist between 
        TEST_F methods, because Fixture objects are constructed when a test begins and 
        deconstructed when the it ends.

    TEST and TEST_F methods both take two parameters:

        1. TestSuiteName: A common namae that tests may share such that they may be grouped 
        together by googletest

        2. TestName: A unique name by which the test may be identified within the TestSuite
        A test's full name consists of <TestSuiteName>.<TestName>
            Note: Tests within different TestSuites may share TestNames
            Example: 
                TEST(SquadDamage, damageMember_test) and 
                TEST(InfantryDamage, damageMember_test)
                are both legal method signatures

    TEST_F() uses a Fixture class by declaring its TestSuiteName to be the name of the Fixture class
    Example: The TEST_F(MilitaryUnitFixture, getType_test) method uses the MilitaryUnitFixture Fixture class

    Fixture classes must inherit publicly from ::testing::Test in order to be used by TEST_F methods

    Member variables declared inside the Fixtures classes may be referenced inside TEST_F methods
    without a reference to the Fixture object
*/

class FixtureExample: public ::testing::Test {
    protected:
    // You may omit any methods that would have an empty body
        FixtureExample(){};
        ~FixtureExample(){};
        //Called right before each test
        void SetUp() override {
            // Do some stuff to instantiate member variables
            x_Fixt = new int(1);
            y_Fixt = new int(2);
        }
        //Called immediately after each test
        void TearDown() override {
            // Do some stuff to clean up member variables
            delete x_Fixt;
            delete y_Fixt;
        }

        //Member variables may be used by al tests in the TestSuite
        int* x_Fixt;
        int* y_Fixt;
};
