
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
#include "Frontline.h"

class Defensive : public Action {
public:
    Defensive();
    int handle(Squad* s);
};


#endif //DEFENSIVE_H