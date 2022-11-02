    /**
    \file SquadDamage.h
    \class SquadDamage
    \brief Child of Bombardment. Deals with entire Squad.
    \details The first child handler in the Chain of Responsibility. Divides a Squad into the individual Team Members and passes the command to each of the members.
    Chain of Responsibilty: ConcreteHandler
    \ingroup Bombardment
    \author Robert Officer
*/
#ifndef SQUADDAMAGE_H
#define SQUADDAMAGE_H

#include "Bombardment.h"

class SquadDamage : public Bombardment{
    public:
        /**
            \fn SquadDamage::SquadDamage
            \brief Constructor for making SquadDamage objects
        */
        SquadDamage();
        /**
            \fn SquadDamage::iterateThroughSquad
            \brief Breaks down the squad into individual team members
            \details Checks to see if the military unit passed in is of type "Squad". If it is not of type Squad then object is 
            passed onto the next link in the chain. If it is of type Squad, the squad is broken down into the individual team members.
            Each member is then dealt with seperatley by passing the individual team member to the next link in the chain.
            \param[in] currentUnit The unit the is to have damage dealt to them
        */
        void damageMember(MilitaryUnit * currentUnit);
};

#endif