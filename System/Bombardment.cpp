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
    //Check to see if Bombardment object already has a handler
    if (next) {
        next->add(a);
    } else {
        //if no handler detected, Bombardment objects next attribute is set to the in coming parameter
        next = a;
    }
}

void Bombardment::damageMember(MilitaryUnit *currentUnit) {}

void Bombardment::execute(){
    std::cout << "Bombardment incoming" << endl;
    //Check to see if the targeted cell is empty, no point in wasting Ammo if it is
    if(!(targetedCell->getOccupyingForce())->empty()){
        //get the targeted cell's occupying force and iterate through it, using the overridden functions that conform to the type the MilitaryUnit is
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
