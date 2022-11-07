/**
<<<<<<< Updated upstream
 * \file Caretake.h
 * \class Caretaker
 * \brief **  Documentation Pending **
 * \todo Documentation
=======
   \file Caretaker.h
   \class Caretaker
   \brief Caretaker class of the Memento Pattern
   \details The Caretaker class is responsible for the safekeeping of the states of the war at a certain times
   \author Latasha Friend
>>>>>>> Stashed changes
*/
#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"
#include <vector>

class Caretaker {
private:
    std::vector<SaveState *> mementos;

public:
    Caretaker();

    Caretaker(SaveState *newState);

    SaveState *getMemento(int index);

    void addMemento(SaveState *newState);
};

#endif
