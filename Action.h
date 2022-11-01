#ifndef ACTION_H
#define ACTION_H
#include "Participants.h"
#include <iostream>
using namespace std;

enum ActionType {Aggressive, Defensive};

class Action {
    protected:
        ActionType type;
    public:
        Action(ActionType);
        virtual int handleChange() = 0;
        ActionType getType();
};

#endif
