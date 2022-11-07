/**
    \file CentralPowers.h
    \class CentralPowers
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
        /**
         * \fn CentralPowers::retreat
         * \param cells Vector for cells that need to be retreated
         * \brief moves squads currently on cells one cell back
         */
        void retreat(std::vector<Cell*> cells);

        /**
        * \fn CentralPowers::CentralPowers
        * \brief Default constructor
        */
        CentralPowers(ParticipantType pT);

        /**
         * \fn CentralPowers::atBack
         * \return std::vector<Cell*>
         * \brief returns a vector of Cells with all cells not on the edge of the world map
         */
        std::vector<Cell*> atBack();

        void armyMove();
};


#endif
