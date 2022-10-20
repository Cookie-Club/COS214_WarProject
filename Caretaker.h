#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"

class Caretaker {

private:
	vector<SaveState*> mementos;

public:
	Caretaker();
	SaveState* getMemento(int index);
	void addMemento(SaveState* newState);
};

#endif
