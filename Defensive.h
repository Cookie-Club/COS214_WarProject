
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
//#include "Participants.h"
// #include "Aggressive.h"

class Defensive : public Action {
public:
    Defensive();
    int handleChange(int dam);
};


#endif //DEFENSIVE_H
