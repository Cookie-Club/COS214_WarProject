#ifndef CENTRALPOWERS_H
#define CENTRALPOWERS_H

#include "Participants.h"

class CentralPowers : public Participants {
    public:
        void retreat();
        bool atBack();
        CentralPowers();
};


#endif
