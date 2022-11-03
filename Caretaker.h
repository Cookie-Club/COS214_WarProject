#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"
#include <vector>

class Caretaker {

private:
	vector<SaveState*> mementos;
	int indexes=0;

public:
	
	Caretaker();
	SaveState* getMemento(int index);
	void addMemento(SaveState* newState);
	
};

#endif
