#include "Caretaker.h"

Caretaker::Caretaker() {}

Caretaker::Caretaker(SaveState *newState) {
    mementos.push_back(newState);
}

SaveState *Caretaker::getMemento(int index) {
    return mementos.at(index);
}

void Caretaker::addMemento(SaveState *newState) {
    mementos.push_back(newState);
}
