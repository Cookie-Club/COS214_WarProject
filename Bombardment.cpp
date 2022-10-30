#include "Bombardment.h"

Bombardment::Bombardment(){}

Bombardment::Bombardment(Cell * targetedCell){
    SquadAttack = new SquadDamage();
    IDAttack = new InfantryDamage();
    TDAttack = new TankDamage();

    add(SquadAttack);
    add(IDAttack);
    add(TDAttack);

    this->targetedCell = targetedCell;
}

void Bombardment::add(Bombardment * a){
    if(next){
        next->add(a);
    }
    else{
        next = a;
    }
}

void Bombardment::damageMember(MilitaryUnit * currentUnit){}

void Bombardment::execute(){
    if(!targetedCell->getOccupyingForce().empty()){
        for(int i = 0; i < targetedCell->getOccupyingForce().capacity(); i++){
            next->damageMember(targetedCell->getOccupyingForce().at(i));
        }
    }
}
