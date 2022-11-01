#include "Participants.h"

void Participants::armyMove() {
	// TODO - implement Participants::armyMove
	// throw "Not yet implemented";
    std::cout << "Army has moved\n";
}

void Participants::setState(Action *state) {
    delete this->state;
    this->state=state;

}

void Participants::templateMethod(){
    //If not at the back of the board then retreat
    // how to know if it is at the back -> function for each side?
    if (atBack() != true)
        retreat();
}

Action * Participants::getState(){
    return state;
}


int Participants::getTotalHealthPoints(){
    return totalHealthPoints;
}

void Participants::setTotalHealthPoints() {
}

int Participants::getTotalDamage(){
    return totalDamage;
}

void Participants::setTotalDamage() {}

string Participants::getName(){
    return name;
}


std::vector<MilitaryUnit*> Participants::getArmy()
{
    return army;
}