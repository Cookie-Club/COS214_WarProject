/**
    \file Composite_Test_Fixtures.h
    \brief Defines and Implements test fixture used in Composite_Test_main.cpp
    \author Wian Koekemoer
*/

#include "gtest/gtest.h"
#include "AlliedInfantry.h"
#include "CentralInfantry.h"
#include "AlliedTank.h"
#include "CentralTank.h"
#include "Squad.h"
#include "AlliedPowers.h"
#include "CentralPowers.h"
#include <vector>
class CompositeFixture: public ::testing::Test
{
    protected:
        void SetUp()
        {
            map = new WorldMap(10);
            ally = new AlliedPowers();
            central = new CentralPowers();
            units.push_back(new AlliedInfantry(A_I_DAMAGE, A_I_HP, ally, A_I_RATIONS));
            units.push_back(new CentralInfantry(C_I_DAMAGE, C_I_HP, central, C_I_RATIONS));
            units.push_back(new AlliedTank(A_T_DAMAGE, A_T_HP, ally, A_T_FUEL));
            units.push_back(new CentralTank(C_T_DAMAGE, C_T_HP, central, C_T_FUEL));
            aSquad = new Squad(ally);
            cSquad = new Squad(central);
            ally->addUnit(aSquad);
            central->addUnit(cSquad);
            std::cout << "before adding members to squads\n";
            aSquad->addMember(units.at(0)); //Add anonymous AlliedInfantry object
            cSquad->addMember(units.at(1)); //Add anonymous CentralInfantry object
            std::cout << "Finished StartUp\n";
        };

        void TearDown()
        {
            std::cout << "Starting TearDown\n";
            //Delegate TeamMember deletion do Squad destructor
            while (units.size() > 0) 
            {
                switch (units[units.size()-1]->getParticipantType())
                {
                    case Allied: 
                    {
                        aSquad->addMember(units[units.size()-1]);
                        break;
                    };
                    default: 
                    {
                        cSquad->addMember(units[units.size()-1]);
                    };
                };
                //Resets units vector back to initial state
                units.pop_back();
            }
            //Participants desctructor handles deletion of squad objects
            std::cout << "before ally deletion\n";
            delete ally;
            std::cout << "before central deletion\n";
            delete central;
            std::cout << "before map deletion\n";
            delete map;
            std::cout << "TearDown Completed\n";
        };

        std::vector<MilitaryUnit*> units;
        Squad* aSquad; //Allied squad
        Squad* cSquad; //Central squad
        Participants* ally;
        Participants* central;
        WorldMap* map;
        const int A_I_DAMAGE = 100;
        const int C_I_DAMAGE = 101;
        const int A_T_DAMAGE = 102;
        const int C_T_DAMAGE = 103;
        const int A_I_HP = 104;
        const int C_I_HP = 105;
        const int A_T_HP = 106;
        const int C_T_HP = 107;
        const int A_I_RATIONS = 108;
        const int C_I_RATIONS = 109;
        const float A_T_FUEL = 110;
        const float C_T_FUEL = 111;
};