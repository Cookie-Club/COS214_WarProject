/**
    \file Composite_Test_main.cpp
    \brief Contains testing for functions of Composite Participants
    \author Wian Koekemoer
*/

#include "Test_Config.h"
// Test 1
//Test that constructors function correctly. using ASSERT_EQ as carrying on with the test
// after failure would be pointless
TEST_F(CompositeFixture, TeamMembers_Initial_State)
{
    // Test AlliedInfantry object at units[0]
    ASSERT_EQ(units.at(0)->getType(), infantry) << "First unit is not of type Infantry";
    ASSERT_EQ(units.at(0)->getParticipant(), Allied) << "First unit does not belong to Allies";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getDamage(), A_I_DAMAGE) << "Value of damage variable is incorrect in the AlliedInfantry object";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getHealthpoints(), A_I_HP) << "Value of healthpoints variable is incorrect in the AlliedInfantry object";
    ASSERT_EQ(((AlliedInfantry*)units.at(0))->getRationConsumption(), A_I_RATIONS) << "Value of rationConsumption variable is incorrect in the AlliedInfantry object";
    
    // Test CentralInfantry object at units[1]
    ASSERT_EQ(units.at(1)->getType(), infantry) << "First unit is not of type infantry";
    ASSERT_EQ(units.at(1)->getParticipant(), Central) << "First unit does not belong to Central";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getDamage(), C_I_DAMAGE) << "Value of damage variable is incorrect in the CentralInfantry object";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getHealthpoints(), C_I_HP) << "Value of healthpoints variable is incorrect in the CentralInfantry object";
    ASSERT_EQ(((CentralInfantry*)units.at(1))->getRationConsumption(), C_I_RATIONS) << "Value of rationConsumption variable is incorrect in the CentralInfantry object";

    // Test AlliedTank object at units[2]
    ASSERT_EQ(units.at(2)->getType(), tank) << "First unit is not of type tank";
    ASSERT_EQ(units.at(2)->getParticipant(), Allied) << "First unit does not belong to Allies";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getDamage(), A_T_DAMAGE) << "Value of damage variable is incorrect in the AlliedTank object";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getHealthpoints(), A_T_HP) << "Value of healthpoints variable is incorrect in the AlliedTank object";
    ASSERT_EQ(((AlliedTank*)units.at(2))->getFuelConsumption(), A_T_FUEL) << "Value of rationConsumption variable is incorrect in the AlliedTank object";

    // Test CentralTank object at units[3]
    ASSERT_EQ(units.at(3)->getType(), tank) << "First unit is not of type tank";
    ASSERT_EQ(units.at(3)->getParticipant(), Central) << "First unit does not belong to Central";
    ASSERT_EQ(((CentralTank*)units.at(3))->getDamage(), C_T_DAMAGE) << "Value of damage variable is incorrect in the CentralTank object";
    ASSERT_EQ(((CentralTank*)units.at(3))->getHealthpoints(), C_T_HP) << "Value of healthpoints variable is incorrect in the CentralTank object";
    ASSERT_EQ(((CentralTank*)units.at(3))->getFuelConsumption(), C_T_FUEL) << "Value of rationConsumption variable is incorrect in the CentralTank object";
}

// Test 2
TEST_F(CompositeFixture, Squad_Initial_State)
{
    std::vector<MilitaryUnit*> squad1 = aSquad->getMembers();
    std::vector<MilitaryUnit*> squad2 = cSquad->getMembers();
    ASSERT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    ASSERT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
    ASSERT_EQ(squad1[0], units[0]) << "Allied squad has incorrect unit";
    ASSERT_EQ(squad2[0], units[1]) << "Central squad has incorrect unit";
}

// Test 3
TEST_F(CompositeFixture, setMap_Functions)
{
    EXPECT_EQ(units[0]->getMap(),nullptr);
    EXPECT_EQ(units[1]->getMap(),nullptr);
    EXPECT_EQ(units[2]->getMap(),nullptr);
    EXPECT_EQ(units[3]->getMap(),nullptr);
    units[0]->setMap(map);
    EXPECT_EQ(units[0]->getMap(),map);
    EXPECT_EQ(units[1]->getMap(),nullptr);
    EXPECT_EQ(units[2]->getMap(),nullptr);
    EXPECT_EQ(units[3]->getMap(),nullptr);
    aSquad->addMember(units[2]);
    aSquad->setMap(map);
    EXPECT_EQ(units[0]->getMap(),map);
    EXPECT_EQ(units[1]->getMap(),nullptr);
    EXPECT_EQ(units[2]->getMap(),map);
    EXPECT_EQ(units[3]->getMap(),nullptr);
    cSquad->addMember(units[3]);
    central->setMap(map);
    EXPECT_EQ(units[0]->getMap(),map);
    EXPECT_EQ(units[1]->getMap(),map);
    EXPECT_EQ(units[2]->getMap(),map);
    EXPECT_EQ(units[3]->getMap(),map);
}

// Test 4
TEST_F(CompositeFixture, Squad_Add_And_Remove_Members)
{
    MilitaryUnit* temp1 = units[2];
    MilitaryUnit* temp2 = units[3];
    
    //units[2] and units[3] get deleted, so they must be removed 
    // from the vector to avoid segfaults
    std::vector<MilitaryUnit*>::iterator it = units.begin();
    while (*it != temp1)++it;
    units.erase(it);
    it = units.begin();
    while (*it != temp2)++it;
    units.erase(it);

    aSquad->addMember(temp1);
    std::vector<MilitaryUnit*> squad1 = aSquad->getMembers();
    std::vector<MilitaryUnit*> squad2 = cSquad->getMembers();
    EXPECT_EQ(squad1.size(), 2) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 1) << "Central squad has incorrect size";

    cSquad->addMember(temp2);
    squad2 = cSquad->getMembers();//Need to get it again because getMembers returns a copy of the vector
    EXPECT_EQ(squad1.size(), 2) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 2) << "Central squad has incorrect size";

    aSquad->removeSquadMember(temp1);
    squad1 = aSquad->getMembers();
    EXPECT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 2) << "Central squad has incorrect size";

    cSquad->removeSquadMember(temp2);
    squad2 = cSquad->getMembers();//Need to get it again because getMembers returns a copy of the vector
    EXPECT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
}

// Test 5
TEST_F(CompositeFixture, setOccupyingCell_setOppcupyingForce_getOccupyingForce)
{
    Cell* tempCell = map->getGrid()[1][1];
    aSquad->setOccupyingCell(tempCell);
    EXPECT_EQ(aSquad->getOccupyingCell(), tempCell) << "Allied squad should be occupying tempCell";
    EXPECT_EQ(cSquad->getOccupyingCell(), nullptr) << "Central squad should not be occupying cell";
    std::vector<MilitaryUnit*> tempVect = tempCell->getOccupyingForce();
    EXPECT_EQ(aSquad, tempVect[0]) << "Allied squad should be in vector of tempCell";

    Cell* tempCell2 = map->getGrid()[1][2];
    aSquad->setOccupyingCell(tempCell2);
    cSquad->setOccupyingCell(tempCell);
    EXPECT_EQ(aSquad->getOccupyingCell(), tempCell2) << "Allied squad should be occupying tempCell2";
    EXPECT_EQ(cSquad->getOccupyingCell(), tempCell) << "Central squad should be occupying tempCell";
    
    tempVect = tempCell->getOccupyingForce();
    std::vector<MilitaryUnit*> tempVect2 = tempCell2->getOccupyingForce();
    EXPECT_EQ(aSquad, tempVect2[0]) << "Allied squad should be in vector of tempCell2";
    EXPECT_EQ(cSquad, tempVect[0]) << "Allied squad should be in vector of tempCell";
}

// Test 6
TEST_F(CompositeFixture, receiveDamage)
{
    EXPECT_EQ(aSquad->isAlive(), true) << "Shouldn't be dead yet"; 
    aSquad->receiveDamage(A_I_HP); 
    EXPECT_EQ(aSquad->isAlive(), false) << "Should be dead"; 
    if (!aSquad->isAlive()) units.erase(units.begin());
}

// Test 7
TEST_F(CompositeFixture, Prototype)
{
    Squad* clone = aSquad->clone();
    std::vector<MilitaryUnit*> memS = aSquad->getMembers(), memC = clone->getMembers();
    ASSERT_NE(aSquad, clone) << "Squad should not be shallow copy";
    ASSERT_NE(memS[0], memC[0]) << "Squad members should not be shallow copy";
    EXPECT_EQ(memS.size(), memC.size()) << "Squad sizes should be equal";

    EXPECT_EQ(aSquad->getDamage(), clone->getDamage()) << "Squad total damage should be equal";
    EXPECT_EQ(aSquad->getHealthpoints(), clone->getHealthpoints()) << "Squad total healthpoints should be equal";

    EXPECT_EQ(memS[0]->getDamage(), memC[0]->getDamage()) << "Unit damage should be equal";
    EXPECT_EQ(memS[0]->getHealthpoints(), memC[0]->getHealthpoints()) << "Unit damage should be equal";

    aSquad->addMember(units[2]);
    memS = aSquad->getMembers();
    memC = clone->getMembers();
    EXPECT_NE(memS.size(), memC.size()) << "Squad sizes should not be equal";
    EXPECT_NE(aSquad->getDamage(), clone->getDamage()) << "Squad total damage should not be equal";
    EXPECT_NE(aSquad->getHealthpoints(), clone->getHealthpoints()) << "Squad total healthpoints should not be equal";
    
    delete clone;
}

TEST_F(CompositeFixture, Squad_battle)
{
    //Set initial state
    aSquad->removeSquadMember(units[0]);
    cSquad->removeSquadMember(units[1]);
    //Clean up units vector
    units.erase(units.begin());
    units.erase(units.begin());

    aSquad->addMember(new AlliedInfantry(50, 100, ally, 1));
    aSquad->addMember(new AlliedInfantry(50, 100, ally, 1));
    aSquad->addMember(new AlliedInfantry(50, 100, ally, 1));
    aSquad->addMember(new AlliedInfantry(50, 100, ally, 1));

    cSquad->addMember(new AlliedInfantry(50, 100, central, 1));
    cSquad->addMember(new AlliedInfantry(50, 100, central, 1));
    cSquad->addMember(new AlliedInfantry(50, 100, central, 1));
    cSquad->addMember(new AlliedInfantry(50, 100, central, 1));

    std::vector<MilitaryUnit*> victim;
    victim.push_back(cSquad);
    EXPECT_EQ(!aSquad->battle(victim), true) << "aSquad should lose";
    EXPECT_EQ(aSquad->getMembers().size(), 0) << "aSquad lost and should have 0 remaining members";
    EXPECT_EQ(cSquad->getMembers().size(), 4) << "cSquad should not have lost members";

}