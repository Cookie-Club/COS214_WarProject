#ifndef TANKDAMAGE_H
#define TANKDAMAGE_H

#include "Bombardment.h"

using namespace std;

class TankDamage : public Bombardment{
    public:
        TankDamage();
        void dispense();
    protected:
        int damage;
};

#endif