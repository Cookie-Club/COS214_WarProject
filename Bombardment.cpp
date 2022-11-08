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
    else{
        std::cout << "*Cricket Noises* No one is in that cell" << endl;
    }

    std::cout << "The last shells fall" << endl;
}

Bombardment::~Bombardment() {
    std::cout << "Calling delete from Bombardment:43\n";
    delete SquadAttack;
    std::cout << "Calling delete from Bombardment:45\n";
    delete IDAttack;
    std::cout << "Calling delete from Bombardment:47\n";
    delete TDAttack;
    std::cout << "Bombardment has finished obliterating the enemy" << endl;
}
