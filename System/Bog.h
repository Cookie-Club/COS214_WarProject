/**
    \file Bog.h
        \class Bog
	\brief Class definition of a Bog cell type
    Decorator: ConcreteComponent
    \ingroup Cell
    \author Robert Officer
    \date 03/11/22
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
        \brief Tells the Bog cell to perform specific action
        \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
        on how many team members are in the squad and adding a resourceUse-multiplier to the calculated answer
        \param[in] m  A MilitaryUnit pointer that points to the squad being added into the cells occupying force
    */
    void execute(MilitaryUnit *m);

    /**
        \fn Bog::printSymbol
        \param[in] s     String input to print
        \brief Method to format output
    */
    virtual void printSymbol(std::string s = "  ");

    /**
        \fn Bog::execute
        \brief Tells the Bog cell to perform specific action
        \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
        on how many team members are in the squad and adding a resourceUse-multiplier to the calculated answer
        \param[in] m  A MilitaryUnit vector that represents the squad being added into the cells occupying force
    */
    void execute(std::vector<MilitaryUnit *> m);

private:
    double resourceUseMultiplier;

};


#endif //BOG_H
