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
#include "Squad.h"
#include <iostream>
using namespace std;

enum ActionType {Aggressive, Defensive};

class Action {
protected:
    ActionType type;
public:
    Action(ActionType);
    virtual int handleChange(Squad* s) = 0;
    ActionType getType();
};

#endif