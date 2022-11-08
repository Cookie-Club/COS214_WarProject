/**
    \file AmmoDeposit.h
    \class AmmoDeposit
    \brief Contains the definition of the AmmoDeposit type of cell
     \details Child of cellFeatures this class inherits two functions, getAttribute() and add() as well as the attributes feature and attribute
    Decorator: ConcreteDecorator
    Factory: Product
    \ingroup CellFeatures
    \ingroup Cell
    \author Robert Officer
    \date 03/11/22
*/

#ifndef AMMODEPOSIT_H
#define AMMODEPOSIT_H

#include "CellFeatures.h"

class AmmoDeposit : public CellFeatures {
public:
    /**
        \fn AmmoDeposit::AmmoDeposit
        \brief Constructor
        \details Sets the attribute , attribute equal to the enumeration AmmoDepo
    */
    AmmoDeposit();

    /**
        \fn AmmoDeposit::setOccupyingForce
        \brief Adds a military unit to the occupyingForce
        \details Adds using the pre-defined vector function push_back() and resets the Ration and Ammo attributes of the militaryUnit. Passes the militaryUnit
        onto the feature attribute to have resources deducted for movement.
        \param[in] m A MilitaryUnit pointer that points to the unit needing to be added to the cells occupyingForce
    */
    void setOccupyingForce(MilitaryUnit *m);

    /**
        \fn AmmoDeposit::setOccupyingForce
        \brief Overloaded setOccupyingForce
        \details Takes in a vector and adds each index to the occupyingForce one by one using the pre-defined vector function push_back() and resets the Ration
        and Ammo attributes of the militaryUnit. Passes the militaryUnit onto the feature attribute to have resources deducted for movement.
        \param[in] m A a vector of MilitaryUnit pointers that point to the unit needing to be added to the cells occupyingForce
    */
    void setOccupyingForce(std::vector<MilitaryUnit *> m);

    /**
        \fn AmmoDeposit::~AmmoDeposit
        \brief Destructor
    */
    ~AmmoDeposit();

    /**
        \fn AmmoDeposit::printSymbol
        \param[in] s     String input to print
        \brief Method to format output
     */
    void printSymbol(std::string s = "  ");
};


#endif //AMMODEPOSIT_H
