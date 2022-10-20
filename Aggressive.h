#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"

class Aggressive : public Action {
public:
    void handleChange(Participants* p);
};


#endif //AGGRESSIVE_H
