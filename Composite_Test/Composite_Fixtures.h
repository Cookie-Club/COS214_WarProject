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
            ally = new AlliedPowers();
            central = new CentralPowers();
            units.push_back(new AlliedInfantry(A_I_DAMAGE, A_I_HP, ally, A_I_RATIONS));
            units.push_back(new CentralInfantry(C_I_DAMAGE, C_I_HP, central, C_I_RATIONS));
            units.push_back(new AlliedTank(A_T_DAMAGE, A_T_HP, ally, A_T_FUEL));
            units.push_back(new CentralTank(C_T_DAMAGE, C_T_HP, central, C_T_FUEL));
            aSquad = new Squad(ally);
            cSquad = new Squad(central);
            aSquad->addMember(units.at(0)); //Add anonymous AlliedInfantry object
            cSquad->addMember(units.at(1)); //Add anonymous CentralInfantry object
        };

        void TearDown()
        {
            //Delegate object deletion do Squad destructor
            aSquad->addMember(units.at(2));
            cSquad->addMember(units.at(3));
            delete aSquad;
            delete cSquad;
            aSquad = nullptr;
            cSquad = nullptr;
            delete ally;
            delete central;
        };

        std::vector<MilitaryUnit*> units;
        Squad* aSquad; //Allied squad
        Squad* cSquad; //Central squad
        Participants* ally;
        Participants* central;
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