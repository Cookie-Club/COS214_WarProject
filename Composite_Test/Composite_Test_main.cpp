
/**
    \file Composite_Testing_main.cpp
    \brief Contains unit tests for Composite pattern participants
    \author Wian Koekemoer
*/
#include "Composite_Fixtures.h"

//Test that constructors function correctly. 
//Using ASSERT_EQ, because carrying on with the test after failure would be pointless
TEST_F(CompositeFixture, TeamMembers_Initial_State)
{
    // Test AlliedInfantry object at units[0]
    ASSERT_EQ(units.at(0)->getType(), infantry) << "Unit is not of type Infantry";
    ASSERT_EQ(units.at(0)->getOwner(), ally) << "Unit does not belong to ally Participant";
    ASSERT_EQ(units.at(0)->getParticipant(), Allied) << "Unit does not belong to Allies";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getDamage(), A_I_DAMAGE) << "Value of damage variable is incorrect in the AlliedInfantry object";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getHealthpoints(), A_I_HP) << "Value of healthpoints variable is incorrect in the AlliedInfantry object";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getRationConsumption(), A_I_RATIONS) << "Value of rationConsumption variable is incorrect in the AlliedInfantry object";
    
    // Test CentralInfantry object at units[1]
    ASSERT_EQ(units.at(1)->getType(), infantry) << "Unit is not of type infantry";
    ASSERT_EQ(units.at(1)->getOwner(), central) << "Unit does not belong to central Participant";
    ASSERT_EQ(units.at(1)->getParticipant(), Central) << "First unit does not belong to Central";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getDamage(), C_I_DAMAGE) << "Value of damage variable is incorrect in the CentralInfantry object";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getHealthpoints(), C_I_HP) << "Value of healthpoints variable is incorrect in the CentralInfantry object";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getRationConsumption(), C_I_RATIONS) << "Value of rationConsumption variable is incorrect in the CentralInfantry object";

    // Test AlliedTank object at units[2]
    ASSERT_EQ(units.at(2)->getType(), tank) << "Unit is not of type tank";
    ASSERT_EQ(units.at(2)->getOwner(), ally) << "Unit does not belong to Allies";
    ASSERT_EQ(units.at(2)->getParticipant(), Allied) << "Unit does not belong to Allies";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getDamage(), A_T_DAMAGE) << "Value of damage variable is incorrect in the AlliedTank object";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getHealthpoints(), A_T_HP) << "Value of healthpoints variable is incorrect in the AlliedTank object";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getFuelConsumption(), A_T_FUEL) << "Value of rationConsumption variable is incorrect in the AlliedTank object";

    // Test CentralTank object at units[3]
    ASSERT_EQ(units.at(3)->getType(), tank) << "Unit is not of type tank";
    ASSERT_EQ(units.at(3)->getOwner(), central) << "Unit does not belong to central Participant";
    ASSERT_EQ(units.at(3)->getParticipant(), Central) << "Unit does not belong to Central";
    ASSERT_EQ(((CentralTank*)units.at(3))->getDamage(), C_T_DAMAGE) << "Value of damage variable is incorrect in the CentralTank object";
    ASSERT_EQ(((CentralTank*)units.at(3))->getHealthpoints(), C_T_HP) << "Value of healthpoints variable is incorrect in the CentralTank object";
    ASSERT_EQ(((CentralTank*)units.at(3))->getFuelConsumption(), C_T_FUEL) << "Value of rationConsumption variable is incorrect in the CentralTank object";
}

//Testing Squad constructor, addMember, and getMembers()
//Using ASSERT_EQ,because carrying on with the test after failure would be pointless
TEST_F(CompositeFixture, Squad_Initial_State)
{
    std::vector<MilitaryUnit*> squad1 = aSquad->getMembers();
    std::vector<MilitaryUnit*> squad2 = cSquad->getMembers();
    ASSERT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    ASSERT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
    ASSERT_EQ(squad1.at(0), units.at(0)) << "Allied squad has incorrect unit";
    ASSERT_EQ(squad2.at(0), units.at(1)) << "Central squad has incorrect unit";
}

//Testing TeamMembers functions
TEST_F(CompositeFixture, TeamMembers_Methods)
{
    EXPECT_EQ(((TeamMembers*)units.at(0))->getSquad(), aSquad) << "Unit squad variable not set correctly";
    EXPECT_EQ(((TeamMembers*)units.at(1))->getSquad(), cSquad) << "Unit squad variable not set correctly";
    EXPECT_EQ(((TeamMembers*)units.at(2))->getSquad(), nullptr) << "Unit squad variable not set correctly";
    EXPECT_EQ(((TeamMembers*)units.at(3))->getSquad(), nullptr) << "Unit squad variable not set correctly";
}