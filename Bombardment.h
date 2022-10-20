#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Order.h"
#include "Cell.h"
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

};


#endif //BOMBARDMENT_H
