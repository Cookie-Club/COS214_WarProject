#include "SquadDamage.h"

SquadDamage::SquadDamage(){}

void SquadDamage::iterateThroughSquad(MilitaryUnit * currentUnit){
    if(currentUnit->getType() == squad){
        for(int i = 0; i < ((Squad*)currentUnit)->getMembers().capacity(); i++){
            next->damageMember(((Squad*)currentUnit)->getMembers().at(i));
        }
    }
}