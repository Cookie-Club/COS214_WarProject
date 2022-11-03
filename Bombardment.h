/**
    \file Bombardment.h
    \class Bombardment
    \brief Parent handler for Chain of Responsibilty Pattern
    \details The Bombardment class is in charge of receiving the intial request and then determining. The parent of this class is the Order class.
    If the targeted cell has multiple squads on it, the Bombardment class is used to handle this responsibility.
    Chain of Responsibility: Handler
    Command: ConcreteCommand
    \defgroup Bombardment
    \author Robert Officer
*/

#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Order.h"
//Forward Declarations
class Cell;
class MilitaryUnit;

class Bombardment : public Order {
    public:
        /**
            \fn Bombardment::Bombardment
            \brief Defualt constructor
        */
        Bombardment();
        /**
            \fn Bombardment::Bombardment
            \brief Constructor Overloader
            \details Has a parameter pointer that knows which cell to bombard
            \param[in] targetedCell The cell on which bombardment is being called on
        */
        Bombardment(Cell* targetedCell);
        /**
            \fn Bombardment::add
            \brief Adds a child to the parent
            \details Checks if the next attribute has been added. If next has not been set then it
            sets next to the parameter passed in. If yes then continues down the next chain until the 
            next attribute is not set and then sets the current classes next to the parameter passed in.
            \param[in] x Adds additional links to the end of the chain of the Chain of Responsibility Pattern 
        */
        void add(Bombardment * x);
        /**
            \fn Bombardment::execute
            \brief Seperates the different squads.
            \details Checks to see if the targeted cells occupying force is there. If there is then
            the indivisual squads are seperated and the order is passed onto the next attribute to deal with dealing damage
            properly.
        */
        void execute();
        /**
            \fn Bombardment::damageMember
            \brief A virtual function to deal damage to military units.
            \details Function that deals damage on individual military units by calling receive damage of the current unit 
            parameter that is passed in. Overriden in the children class.
            \param[in] currentUnit The unit that is to have damage dealt to them
        */
        virtual void damageMember(MilitaryUnit * currentUnit);

        ~Bombardment();
    protected:
        Bombardment * next;
        Cell * targetedCell;
        Bombardment * IDAttack;
        Bombardment * TDAttack;
        Bombardment * SquadAttack;

};


#endif //BOMBARDMENT_H
#include "Cell.h"
#include "Squad.h"
#include "SquadDamage.h"
#include "InfantryDamage.h"
#include "TankDamage.h"
