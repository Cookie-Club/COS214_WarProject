#include "Participants.h"

void Participants::armyMove() {
	// TODO - implement Participants::armyMove
	throw "Not yet implemented";
}

void Participants::setState(Action *state) {
    delete this->state;
    this->state=state;

}

void Participants::templateMethod(){
    //If not at the back of the board then retreat
    // how to know if it is at the back -> function for each side?
    std::vector<Cell> vector = atBack();
    for (int i; i < vector.size(); i++){
        retreat(vector.at(i));
    }

}

Action * Participants::getState(){
    return state;
}


int Participants::getTotalHealthPoints() const {
    return totalHealthPoints;
}

void Participants::setTotalHealthPoints() {

}

int Participants::getTotalDamage() const {
    return totalDamage;
}

void Participants::setTotalDamage() {
}