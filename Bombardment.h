#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Order.h"
#include "Cell.h"

class Bombardment : public Order {

    public:
        Bombardment(Cell* targetedCell);
        void add();
        void dispense();
        void execute();
    private:
        Bombardment * next;
        Cell * targetedCell;
};


#endif //BOMBARDMENT_H
