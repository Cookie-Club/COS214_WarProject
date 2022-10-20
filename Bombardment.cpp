#include "Bombardment.h"

Bombardment::Bombardment(Cell * targetedCell){

}

void Bombardment::dispense(){
    
}

void Bombardment::add(){

}

void Bombardment::execute(){
    targetedCell->recieveAttack(this);
}
