/**
    \file CentralPowers.h
    \brief Creates the specific Central Powers Participant
    \details Implements primitive operations atBack() and Retreat() defined by Participants
    Template: ConcreteClass
    \ingroup Participants
    \author Megan Hugo
*/
#ifndef CENTRALPOWERS_H
#define CENTRALPOWERS_H

#include "Participants.h"
#include <vector>

class CentralPowers : public Participants {
    public:
        void retreat();
        std::vector<Cell*> atBack();
        CentralPowers();
};


#endif
