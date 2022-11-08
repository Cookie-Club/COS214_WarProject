#include "Bombardment.h"

Bombardment::Bombardment() {}

Bombardment::Bombardment(Cell *targetedCell) {
    SquadAttack = new SquadDamage();
    IDAttack = new InfantryDamage();
    TDAttack = new TankDamage();
    this->targetedCell = targetedCell;

    add(SquadAttack);
    add(IDAttack);
    add(TDAttack);

}

void Bombardment::add(Bombardment *a) {
    if (next) {
        next->add(a);
    } else {
        next = a;
    }
}

void Bombardment::damageMember(MilitaryUnit *currentUnit) {}

void Bombardment::execute(){
    std::cout << "Bombardment incoming" << endl;
    if(!(targetedCell->getOccupyingForce())->empty()){
        for(int i = 0; i < (targetedCell->getOccupyingForce())->size(); i++){
            next->damageMember((targetedCell->getOccupyingForce())->at(i));
        }
    }
}

Bombardment::~Bombardment() {
    delete SquadAttack;
    delete IDAttack;
    delete TDAttack;
    std::cout << "Bombardment has finished obliterating the enemy" << endl;
}
