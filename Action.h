#ifndef ACTION_H
#define ACTION_H
#include "Participants.h"
#include <iostream>
using namespace std;
class Action {
protected:
    string state;
public:
    const string &getBattleState() const;
    virtual void handleChange(Participants* p) = 0;
};

#endif
