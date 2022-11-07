/**
   \file Caretake.h
   \class Caretaker
   \brief Caretaker class of the Memento Pattern
   \details The Caretaker class is responsible for the safekeeping of the states of the war at a certain times
   \author Latasha Friend
*/
#ifndef CARETAKER_H
#define CARETAKER_H

#include "SaveState.h"
#include <vector>

class Caretaker {
private:
    std::vector<SaveState *> mementos;

public:
    /**
        \fn Caretaker::Caretaker
        \brief Constructor
    */
    Caretaker();
    /**
        \fn Caretaker::Caretaker
        \brief Constructor
        \param[in] newState 		The state to be saved for later use by the Caretaker

    */
    Caretaker(SaveState *newState);
    /**
        \fn Caretaker::getMemento
        \brief Method of getting a state that was saved by the Caretaker
        \param[in] index 	    The index at which the required saved state should be found
        \return The the requested state
    */
    SaveState *getMemento(int index);
    /**
        \fn Caretaker::addMemento
        \brief Method of adding a state that should be saved by the Caretaker
        \param[in] newState 	    The object (state) that should be stored by the Caretaker
    */
    void addMemento(SaveState *newState);
};

#endif
