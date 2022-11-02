/**
    \file Aggressive.h
    \class Aggressive
    \brief Concrete State class of the State Pattern
    \details The Aggressive class Implements a behaviour associated with the state of the squad context
    State: ConcreteState
    \ingroup Action
    \author Kaitlyn Sookdhew
*/
#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"
#include "Mining.h"

class Aggressive : public Action {
public:
    Aggressive();
    int handle(Squad* s);
};


#endif //AGGRESSIVE_H