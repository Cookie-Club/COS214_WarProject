
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
#include "Participants.h"

class Defensive : public Action {
public:
    void handleChange(Participants* p);
};


#endif //DEFENSIVE_H
