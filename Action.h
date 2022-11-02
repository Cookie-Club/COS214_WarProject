/**
    \file Action.h
    \class Action
    \brief State class of the State Pattern
    \details The Action class defines an interface for encapsulating the behaviour associated with a particular state,
    either Aggressive or defensive, of the Squad (context of the state pattern)
    State: state
    \author Kaitlyn Sookdhew
*/
#ifndef ACTION_H
#define ACTION_H
#include "Enumerations.h"
#include <iostream>
using namespace std;

class Squad;

class Action {
protected:
    ActionType type;
public:
    Action();
    virtual int handle(Squad* s) = 0;
    ActionType getType();
    void setType(ActionType aT);
};

#endif

#include "Squad.h"