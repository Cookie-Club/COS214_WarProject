/**
    \file Bog.h
    \brief Defines a Bog cell type
    \author Robert Officer
    \date 03/11/22
*/
/**
	\class Bog
	\brief Class definition of a Bog cell type
    Decorator: ConcreteComponent
	\authors Robert Officer
*/

#ifndef BOG_H
#define BOG_H

#include "Cell.h"

class Bog : public Cell {
    public:
        /**
            \fn Bog::Bog
            \brief Constructor
        */
        Bog();
        /**
            \fn Bog::execute
            \brief Tells the Bog cell to perform specific actiosn
            \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
            on how many team members are in the squad and adding a resourceUsemultiplier to the calculated answer
            \param[in] m  A MilitaryUnit pointer that points to the squad being added into the cells occupying force
        */
        void execute(MilitaryUnit * m);
    private:
        double resourceUseMultiplier;
};


#endif //BOG_H
