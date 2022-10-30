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
    retreat();
}

Action * Participants::getState(){
    return state;
}