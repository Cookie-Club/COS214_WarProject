/**
    \file Flatlands.h
    \class Flatlands
    \brief Class definition of a flatlands cell type
    Decorator: ConcreteComponent
    \ingroup Cell
	\authors Robert Officer
    \date 03/11/22
*/

#ifndef FLATLANDS_H
#define FLATLANDS_H

#include "Cell.h"

class Flatlands : public Cell {
    public:
        /**
            \fn Flatlands::Flatlands
            \brief Constructor
            \details Prints creation message and sets type variable to "flatlands"
        */
        Flatlands();
        /**
            \fn Flatlands::execute
            \brief Tells the Flatland cell to perform specific actions
            \details For the Flatlands class, the specific actions include reducing the incoming squads rations and fuel reserves based
            on how many team members are in the squad
            \param[in] m  A MilitaryUnit pointer that points to the squad being added into the cells occupying force
        */
        void execute(MilitaryUnit * m);

    /**
        \fn Flatlands::execute
        \brief Tells the Flatland cell to perform specific actions
        \details For the Flatlands class, the specific actions include reducing the incoming squads rations and fuel reserves based
        on how many team members are in the squad
        \param[in] m  A MilitaryUnit vector that represents the squad being added into the cells occupying force
    */
        void execute(std::vector<MilitaryUnit*>  m);

    /**
        \fn Flatlands::printSymbol
        \param[in] s     String input to print
        \brief Method to format output
    */
        void printSymbol(std::string s = "  ");

//  void add(Cell *addition);
};


#endif //FLATLANDS_H
