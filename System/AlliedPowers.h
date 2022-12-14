/**
    \file AlliedPowers.h
    \class AlliedPowers
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
    * \param[in] cells Vector for cells that need to be retreated
    * \brief moves squads currently on cells one cell back
    */
    void retreat(std::vector<Cell *> cells);

        /**
         * \fn AlliedPowers::AlliedPowers
         * \brief Default constructor
         */
        AlliedPowers(ParticipantType pT);

    /**
     * \fn AlliedPowers::atBack
     * \return std::vector<Cell*>
     * \brief returns a vector of Cells with all cells not on the edge of the world map
     */
    std::vector<Cell *> atBack();

    /**
    * \fn AlliedPowers::armyMove
    * \brief move entire army (Military units vector) to new cell
    */
    void armyMove();
};


#endif //ALLIEDPOWERS_H
