#include "TeamMembers.h"

void TeamMembers::receiveDamage(int damage){
    int newHealth = healthpoints - damage;
}

string TeamMembers::getType(){
    return type;
}
