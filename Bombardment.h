#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Order.h"

class Bombardment : public Order {

public:
    Bombardment * next;
    Bombardment();
    void add();
    void dispense();
    void execute();
};


#endif //BOMBARDMENT_H
