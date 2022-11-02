#include "Caretaker.h"

Caretaker::Caretaker() {
	// TODO - implement Caretaker::Caretaker
	//throw "Not yet implemented";
}

SaveState* Caretaker::getMemento(int index) {
	for (auto it = begin (mementos); it != end (mementos); ++it) {
    if (it.id== index){
		return it;
	}
}
	
}

void Caretaker::addMemento(SaveState* newState) {
	vector::iterator p = mementos.end();
	indexes++;
	mementos.insert(p, mementos);
}
