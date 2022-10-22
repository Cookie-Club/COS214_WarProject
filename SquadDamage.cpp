#include "SquadDamage.h"

SquadDamage::SquadDamage(){}

void SquadDamage::iterateThroughSquad(MilitaryUnit * currentUnit){
    if(currentUnit->getType().compare("squad") == 0){
        for(int i = 0; i < currentUnit->getMembers().capacity(); i++){
            next->damageMember(currentUnit->getMembers().at(i));
        }
    }
}