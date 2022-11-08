#include "TankDamage.h"

TankDamage::TankDamage() {};

void TankDamage::damageMember(MilitaryUnit * currentUnit){
    if(currentUnit->getType() == tank){
        int receivedDamage = std::rand() % 51;
        //Random number generated for the amount of damage done and then passed to the 
        // specific tank unit. Returns a bool of the tank's state of living and if 
        // false removes the tank unit from the squad and deletes it.
        if(!currentUnit->receiveDamage(receivedDamage))
        {
            //if the Tank unit has died, unit is removed from its corresponding squad
            std::cout << "Tank has been destroyed" << endl;
            ((TeamMembers*)currentUnit)->getSquad()->removeSquadMember(currentUnit);
            // delete currentUnit;
        }
        else{
            //if tank unitis still alive display it's current health
            std::cout << "Tank health: " << currentUnit->getHealthpoints() << endl;
        }
    }
    else if (next)
    {
        //if not of type tank, currentUnit is passed onto the tanks next attribute
        next->damageMember(currentUnit);
    }
};