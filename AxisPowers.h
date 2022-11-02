/**
    \file CentralPowers.h
    \brief Creates the specific Central Powers Participant
    \details Implements primitive operations atBack() and Retreat() defined by Participants
    Template: ConcreteClass
    \ingroup Participants
    \author Megan Hugo
*/

#ifndef AXISPOWERS_H
#define AXISPOWERS_H

#include "Participants.h"

class AxisPowers : public Participants {
public:
    void retreat();
    std::vector<Cell> atBack();
};


#endif //AXISPOWERS_H
