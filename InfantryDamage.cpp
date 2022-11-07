#include "InfantryDamage.h"

InfantryDamage::InfantryDamage() {}

//figure out how to deal with dead soldiers, should they be removed from the Squad here or in the next level
void InfantryDamage::damageMember(MilitaryUnit *currentUnit) {
    if (currentUnit->getType() == infantry) {
        int receivedDamage = std::rand() % 96 + 5;
        std::cout << "Infantry Damage" << endl;
        //Random number generated for the amount of damage done and then passed to the 
        // specific infantry unit. Returns a bool of the infantry's state of living and if 
        // false removes the infantry unit from the squad and deletes it
        if(!currentUnit->receiveDamage(receivedDamage))
        {
            std::cout << "Infantry has died" << endl;
            ((TeamMembers*)currentUnit)->getSquad()->removeSquadMember(currentUnit);
            // delete currentUnit;
        }
        else{
            std::cout << "Infantry health: " << currentUnit->getHealthpoints() << endl;
        }
    } else if (next) {
        next->damageMember(currentUnit);
    }
}
