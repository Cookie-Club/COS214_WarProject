#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"
#include "Defensive.h"

class Aggressive : public Action {
public:
    Aggressive();
    void handleChange(Participants* p);
};


#endif //AGGRESSIVE_H
