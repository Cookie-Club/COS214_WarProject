/**
    \file AlliedPowers.h
    \brief Creates the specific AlliedPowers Participant
    \details Implements atBack() and Retreat() defined by Participants
    Template: ConcreteClass
    \ingroup Participants
    \author Megan Hugo
*/
#ifndef ALLIEDPOWERS_H
#define ALLIEDPOWERS_H

#include "Participants.h"
#include <vector>

class AlliedPowers : public Participants {
    public:
        void retreat();
        AlliedPowers();
        std::vector<Cell *> atBack();
};


#endif //ALLIEDPOWERS_H
