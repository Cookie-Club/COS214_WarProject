/**
    \file AmmoDeposit.h
    \brief Contains the definition of the class AmmoDeposit
    \author Robert Officer
    \date 03/11/22
*/
/**
	\class AmmoDeposit
	\brief AmmoDeposit type of cell
    \details Child of cellFeatures this class inherits two functions, getAttribute() and add() as well as the attributes feature and attribute
    Decorator: ConcreteDecorator
    Factory: Product
    \ingroup CellFeatures
    \ingroup Cell
	\author Robert Officer
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
            \param[in] m A MilitaryUnit pointer that points to the unitneeding to be added to the cells occupyingForce
        */   
        void setOccupyingForce(MilitaryUnit * m);
        /**
            \fn AmmoDeposit::setOccupyingForce
            \brief Ovverloaded setOccupyingForce
            \details Takes in a vector and adds each index to the occupyingForce one by one using the pre-defined vector function push_back() and resets the Ration 
            and Ammo attributes of the militaryUnit. Passes the militaryUnit onto the feature attribute to have resources deducted for movement.
            \param[in] m A a vector of MilitaryUnit pointers that point to the unit needing to be added to the cells occupyingForce
        */   
        void setOccupyingForce(std::vector<MilitaryUnit*> m);
        /**
            \fn AmmoDeposit::~AmmoDeposit
            \brief Destructor
        */ 
        ~AmmoDeposit();
        void printSymbol(std::string s = "  ");
};


#endif //AMMODEPOSIT_H
