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
