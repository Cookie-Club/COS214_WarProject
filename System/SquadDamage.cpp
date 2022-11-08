#include "SquadDamage.h"

SquadDamage::SquadDamage() {}

void SquadDamage::damageMember(MilitaryUnit * currentUnit){
    //check if the incoming unit is of type squad
    if(currentUnit->getType() == squad){
        //iterate through each squad, passing the object onto the squad objects next attribute 
        for(int i = 0; i < ((Squad*)currentUnit)->getMembers().size(); i++){
            next->damageMember(((Squad*)currentUnit)->getMembers()[i]);
        }
    } 
    else if (next) {//if not of type squad, currentUnit is passed onto the squads next attribute
        next->damageMember(currentUnit);
    }
}
