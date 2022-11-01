#ifndef ACTION_H
#define ACTION_H
#include "Participants.h"
#include <iostream>
using namespace std;

enum ActionType {Agg, Def};

class Action {
    protected:
        ActionType type;
    public:
        Action();
        virtual int handleChange() = 0;
        ActionType getType();
        void setType(ActionType aT);
};

#endif
