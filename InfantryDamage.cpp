#include "InfantryDamage.h"

InfantryDamage::InfantryDamage(){}

//figure out how to deal with dead soldiers, should they be removed from the Squad here or in the next level
void InfantryDamage::damageMember(MilitaryUnit * currentUnit){
    if(currentUnit->getType() == infantry){
        currentUnit->receiveDamage(damage);
    }
    else{
        next->damageMember(currentUnit);
    }   
}


