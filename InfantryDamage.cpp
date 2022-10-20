#include "InfantryDamage.h"

InfantryDamage::InfantryDamage(Cell * targetedCell){
    this->targetedCell = targetedCell;
}

//figure out how to deal with dead soldiers, should they be removed from the Squad here or in the next level
void InfantryDamage::damageMember(MilitaryUnit * currentUnit){
    if(currentUnit->getType().compare("infantry") == 0){
        currentUnit->receiveDamage(damage);
    }
    else{
        next->damageMember(currentUnit);
    }   
}


