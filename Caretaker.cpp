#include "Caretaker.h"

Caretaker::Caretaker() {
	// TODO - implement Caretaker::Caretaker
	//throw "Not yet implemented";
}

SaveState* Caretaker::getMemento(int index) {
	return mementos.at(index);
}

void Caretaker::addMemento(SaveState* newState) {
	mementos.push_back(newState);
}
