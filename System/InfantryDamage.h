/**
    \file InfantryDamage.h
    \class InfantryDamage
    \brief Child of Bombardment. Deals with Infantry members.
    \details The second link in the Chain of Responsibilty. Deals with the Infantry members of a Squad.
    Chain of Responsibility: ConcreteHandler
    \ingroup Bombardment
    \author Robert Officer
*/
#ifndef INFANTRYDAMAGE_H
#define INFANTRYDAMAGE_H

#include "Bombardment.h"

using namespace std;

class InfantryDamage : public Bombardment {

public:
    /**
        \fn InfantryDamage::InfantryDamage
        \brief Constructor for making InfantryDamage objects
    */
    InfantryDamage();

    /**
        \fn InfantryDamage::damageMember
        \param[in] currentUnit      The unit the is to have damage dealt to them
        \brief Deals damage to infantry type team members
        \details First a check to see if the current military unit passed in is of type Infantry. If not,
        the military unit is passed onto the next link in the chain. If it is of type Infantry then damage is dealt randomly,
        between 5 and 100, to the individual unit by calling its receiveDamage method. If the unit has died during the receiveDamage method call,
        it is removed from its squad and deleted from the program.
    */
    void damageMember(MilitaryUnit *currentUnit);
};


#endif
