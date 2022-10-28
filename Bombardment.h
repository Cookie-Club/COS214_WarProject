/**
    \file Bombardment.h
    \brief Parent handler for Chain of Responsibilty Pattern
    \details The Bombardment class is in charge of receiving the intial request and then determining. The parent of this class is the Order class.
    \author Robert Officer
    \class Bombardment
*/

#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Order.h"
#include "Cell.h"
#include "SquadDamage.h"
#include "InfantryDamage.h"
#include "TankDamage.h"

class Bombardment : public Order {

    public:
        Bombardment();
        Bombardment(Cell* targetedCell);
        void add(Bombardment * a);
        void execute();
        virtual void damageMember(MilitaryUnit * currentUnit);
    protected:
        Bombardment * next;
        Cell * targetedCell;
        Bombardment * IDAttack;
        Bombardment * TDAttack;
        Bombardment * SquadAttack;

};


#endif //BOMBARDMENT_H
