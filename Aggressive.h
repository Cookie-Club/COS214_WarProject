/**
    \file Aggressive.h
    \class Aggressive
    \brief Concrete State class of the State Pattern
    \details The Aggressive class Implements a behaviour associated with the state of the squad context
    State: ConcreteState
    \author Kaitlyn Sookdhew
*/
#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"
#include "Mining.h"

class Aggressive : public Action {
public:
    Aggressive();
    void handle(Squad* s);
};


#endif //AGGRESSIVE_H