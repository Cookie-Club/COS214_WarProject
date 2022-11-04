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
    /**
     * \fn AlliedPowers::retreat
     * \param cells Vector for cells that need to be retreated
     * \brief moves squads currently on cells one cell back
     */
        void retreat(std::vector<std::vector<Cell*>> cells);

        /**
         * \fn AlliedPowers::AlliedPowers
         * \brief Default constructor
         */
        AlliedPowers();

        /**
         * \fn AlliedPowers::atBack
         * \return std::vector<Cell*>
         * \brief returns a vector of Cells with all cells not on the edge of the world map
         */
        std::vector<Cell*> atBack();
};


#endif //ALLIEDPOWERS_H
