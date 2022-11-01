
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
//#include "Participants.h"
//#include "Aggressive.h"
#include "Frontline.h"

class Defensive : public Action {
public:
    Defensive();
    int handleChange(Squad* s);
};


#endif //DEFENSIVE_H
