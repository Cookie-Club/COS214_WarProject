/**
    \file
    \brief
    \details
    \author
*/
#include "gtest/gtest.h"
#include "Test_Config.h"

TEST_F(ParticipantsFixture, Squads_Removed_From_Army_On_Deletion){
    delete aSquad;
    ASSERT_EQ(ally->getArmy()->size(), 0);
}