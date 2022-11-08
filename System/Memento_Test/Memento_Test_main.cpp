/**
    \file
    \brief
    \details
    \author
*/
#include "gtest/gtest.h"
#include "Test_Config.h"

//Test1
TEST_F(Memento_Fixture, Restoring_Saved_States){
    careTaker->addMemento(s1);
    careTaker->addMemento(s2);
    ASSERT_EQ(careTaker->getMemento(0), s2);
}