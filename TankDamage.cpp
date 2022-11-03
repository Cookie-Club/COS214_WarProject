/**
    \todo Finish coding else if statement 
*/
#include "TankDamage.h"

TankDamage::TankDamage(){};

void TankDamage::damageMember(MilitaryUnit * currentUnit){
    if(currentUnit->getType() == tank){
        int receivedDamage = std::rand() % 51;
        //Random number generated for the amount of damage done and then passed to the 
        // specific tank unit. Returns a bool of the tank's state of living and if 
        // false removes the tank unit from the squad and deletes it.
        if(!currentUnit->receiveDamage(receivedDamage))
        {
            ((TeamMembers*)currentUnit)->getSquad()->removeSquadMember(currentUnit);
            delete currentUnit;
        }
    }
    else if (next)
    {
        next->damageMember(currentUnit);
    }
};