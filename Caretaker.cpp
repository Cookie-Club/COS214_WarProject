#include "Caretaker.h"

Caretaker::Caretaker() {
	// TODO - implement Caretaker::Caretaker
	//throw "Not yet implemented";
}

SaveState* Caretaker::getMemento(int index) {
	return mementos[index];
}

void Caretaker::addMemento(SaveState* newState) {
	vector::iterator p = mementos.end();
	mementos.insert(p, mementos);
}
