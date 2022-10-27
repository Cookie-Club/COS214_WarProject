
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
//#include "Participants.h"
#include "Aggressive.h"

class Defensive : public Action {
public:
    Defensive();
    void handleChange(Participants* p);
};


#endif //DEFENSIVE_H
