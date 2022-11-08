#include "CareTaker.h"
#include "gtest/gtest.h"

class Memento_Fixture: public ::testing::Test
{
    protected:
        void SetUp()
        {
            careTaker = new Caretaker();
            map = new WorldMap();
            s1 = new SaveState(map, sides);
            s2 = new SaveState(map, sides);
        };
        void TearDown()
        {
            //Undo stuff
        };

        //Member variables go here
        Caretaker * careTaker;
        SaveState * s1;
        SaveState * s2;
        WorldMap * map;
        std::vector<Participants*> * sides;
}