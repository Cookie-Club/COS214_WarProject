#ifndef INFANTRYDAMAGE_H
#define INFANTRYDAMAGE_H

#include "Bombardment.h.h"

class InfantryDamage : public Bombardment {

public:
    int damage;
    InfantryDamage();
    void dispense();
};


#endif //INFANTRYDAMAGE_H
