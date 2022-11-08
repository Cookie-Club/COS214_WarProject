#include "gtest/gtest.h"
#include "War.h"
#include  "Caretaker.h"
#include "AlliedPowers.h"
#include "CentralPowers.h"
#include "CentralFactory.h"
#include "AlliedFactory.h"
#include "Squad.h"

class ParticipantsFixture: public ::testing::Test
{
    protected:
        void SetUp()
        {
            map = new WorldMap(10);
            ally = new AlliedPowers(Allied);
            central = new CentralPowers(Central);
            aSquad = new Squad(ally);
            cSquad = new Squad(central);
        };
        void TearDown()
        {
            delete map;
            delete ally;
            delete central;
        };

        //Member variables go here
        Squad* aSquad; //Allied squad
        Squad* cSquad; //Central squad
        Participants* ally;
        Participants* central;
        WorldMap* map;
};