#include "Participants.h"

void Participants::armyMove() {
	// TODO - implement Participants::armyMove
	throw "Not yet implemented";
}

void Participants::setState(Action *state) {
    delete this->state;
    this->state=state;

}