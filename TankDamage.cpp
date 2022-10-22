#include "TankDamage.h"

TankDamage::TankDamage(){};

void TankDamage::damageMember(MilitaryUnit * currentUnit){
    currentUnit->receiveDamage(damage);
};