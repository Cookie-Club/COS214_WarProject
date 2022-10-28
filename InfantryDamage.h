#ifndef INFANTRYDAMAGE_H
#define INFANTRYDAMAGE_H

#include "Bombardment.h"
#include "MilitaryUnit.h"

using namespace std;

class InfantryDamage : public Bombardment{

    public:
        InfantryDamage();
        void damageMember(MilitaryUnit * currentUnit);
    private:
        int damage;
};


#endif
