/**
    \file TankDamage.h
    \class TankDamage
    \brief Child of Bombardment. Deals with Tank memebers.
    \details The last link in the Chain of Responsibilty. Deals dealing damage to Tank type team members of a Squad.
    Chain of Responsibility: ConcreteHandler
    \ingroup Bombardment
    \author Robert Officer
*/
#ifndef TANKDAMAGE_H
#define TANKDAMAGE_H

#include "Bombardment.h"

using namespace std;

class TankDamage : public Bombardment{
    public:
        /**
            \fn TankDamage::TankDamage
            \brief Constructor for making TankDamage objects
        */
        TankDamage();
        /**
            \fn TankDamage::damageMember
            \brief Deals damage to Tank type team members
            \details First a check to see if the current military unit passed in is of type Tank. If not,
            the military unit is passed onto the next link in the chain. If it is of type Tank then damage is dealt randomly between 0 and 50
            to the individual unit by calling its receiveDamage method. If the unit has died during the receiveDamage method call, 
            it is removed from its squad and deleted from the program.
            \param[in] currentUnit The unit the is to have damage dealt to them
        */
        void damageMember(MilitaryUnit * currentUnit);
};

#endif