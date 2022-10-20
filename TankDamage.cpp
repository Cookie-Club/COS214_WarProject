#include "TankDamage.h"

TankDamage::TankDamage(Cell * targetedCell){

};

void TankDamage::damageMember(MilitaryUnit * currentUnit){
    currentUnit->receiveDamage(damage);
};