#include "SquadDamage.h"

SquadDamage::SquadDamage() {}

void SquadDamage::damageMember(MilitaryUnit * currentUnit){
    std::cout << "Checking if squad member" << endl;
    if(currentUnit->getType() == squad){
        std::cout << "Squad Damage" << endl;
        for(int i = 0; i < ((Squad*)currentUnit)->getMembers().size(); i++){
            if(currentUnit && next){
                std::cout << "Attempting" << endl;
                if(((Squad*)currentUnit)->getMembers()[i]){
                    next->damageMember(((Squad*)currentUnit)->getMembers()[i]);
                }
            }  
        }
    } 
    else if (next) {
        std::cout << "Not a squad" << endl;
        next->damageMember(currentUnit);
    }
}
