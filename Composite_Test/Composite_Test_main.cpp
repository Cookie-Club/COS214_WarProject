#include "Test_Config.h"

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

TEST_F(CompositeFixture, Squad_Initial_State)
{
    std::vector<MilitaryUnit*> squad1 = aSquad->getMembers();
    std::vector<MilitaryUnit*> squad2 = cSquad->getMembers();
    ASSERT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    ASSERT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
    ASSERT_EQ(squad1[0], units[0]) << "Allied squad has incorrect unit";
    ASSERT_EQ(squad2[0], units[1]) << "Central squad has incorrect unit";
}

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
    aSquad->removeSquadMember(units[2]);
    cSquad->removeSquadMember(units[3]);
}

TEST_F(CompositeFixture, Squad_Add_And_Remove_Members)
{
    aSquad->addMember(units[2]);
    std::vector<MilitaryUnit*> squad1 = aSquad->getMembers();
    std::vector<MilitaryUnit*> squad2 = cSquad->getMembers();
    EXPECT_EQ(squad1.size(), 2) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
    cSquad->addMember(units[3]);
    squad2 = cSquad->getMembers();//Need to get it again because getMembers returns a copy of the vector
    EXPECT_EQ(squad1.size(), 2) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 2) << "Central squad has incorrect size";

    aSquad->removeSquadMember(units[2]);
    squad1 = aSquad->getMembers();
    EXPECT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 2) << "Central squad has incorrect size";
    cSquad->removeSquadMember(units[3]);
    squad2 = cSquad->getMembers();//Need to get it again because getMembers returns a copy of the vector
    EXPECT_EQ(squad1.size(), 1) << "Allied squad has incorrect size";
    EXPECT_EQ(squad2.size(), 1) << "Central squad has incorrect size";
}

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