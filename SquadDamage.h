#ifndef SQUADDAMAGE_H
#define SQUADDAMAGE_H

#include "Bombardment.h"
#include "MilitaryUnit.h"

class SquadDamage : public Bombardment{
    public:
        SquadDamage();
        void iterateThroughSquad(MilitaryUnit * currentUnit);
};

#endif