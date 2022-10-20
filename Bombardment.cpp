#include "Bombardment.h"

Bombardment::Bombardment(){}

Bombardment::Bombardment(Cell * targetedCell){
    IDAttack = new InfantryDamage(targetedCell);
    TDAttack = new TankDamage(targetedCell);

    add(IDAttack);
    add(TDAttack);

}

void Bombardment::add(Bombardment * a){
    if(next){
        next->add(a);
    }
    else{
        next = a;
    }
}

void Bombardment::execute(){
    if(!targetedCell->getOccupyingForce().empty()){
        for(int i = 0; i < targetedCell->getOccupyingForce().capacity(); i++){
            IDAttack->damageMember(targetedCell->getOccupyingForce().at(i));
        }
    }
}
