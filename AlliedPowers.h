#ifndef ALLIEDPOWERS_H
#define ALLIEDPOWERS_H

#include "Participants.h"

class AlliedPowers : public Participants {
    public:
        void retreat();
        bool atBack();
        AlliedPowers();
};


#endif //ALLIEDPOWERS_H
