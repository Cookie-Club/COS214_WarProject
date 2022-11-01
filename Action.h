#ifndef ACTION_H
#define ACTION_H
#include "Participants.h"
#include <iostream>
#include "Enumerations.h"
using namespace std;


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
