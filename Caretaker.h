/**
 * \file Caretake.h
 * \class Caretaker
 * \brief **  Documentation Pending **
 * \todo Documentation
*/
#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"
#include <vector>

class Caretaker {
	private:
		std::vector<SaveState*> mementos;

	public:	
		Caretaker();
		SaveState* getMemento(int index);
		void addMemento(SaveState* newState);
};

#endif
