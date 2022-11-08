#include "SquadDamage.h"

SquadDamage::SquadDamage() {}

void SquadDamage::damageMember(MilitaryUnit * currentUnit){
    if(currentUnit->getType() == squad){
        for(int i = 0; i < ((Squad*)currentUnit)->getMembers().size(); i++){
            next->damageMember(((Squad*)currentUnit)->getMembers()[i]);
        }
    } 
    else if (next) {
        next->damageMember(currentUnit);
    }
}
