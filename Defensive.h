
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"

class Defensive : public Action {
public:
    Defensive();
    int handleChange(int dam);
};


#endif //DEFENSIVE_H
