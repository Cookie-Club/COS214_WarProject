#ifndef TANKDAMAGE_H
#define TANKDAMAGE_H

#include "Bombardment.h"
#include "MilitaryUnit.h"

using namespace std;

class TankDamage : public Bombardment{
    public:
        TankDamage(Cell * targetedCell);
        void damageMember(MilitaryUnit * currentUnit);
    protected:
        int damage;
};

#endif