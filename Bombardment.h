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
