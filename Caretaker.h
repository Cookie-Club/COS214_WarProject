#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"

class Caretaker {

private:
	vector<SaveState*> mementos;
	indexes=0;

public:
	
	Caretaker();
	SaveState* getMemento(int index);
	void addMemento(SaveState* newState);
	
};

#endif
