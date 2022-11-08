/**
    \file AlliedInfantry.h
    \class AlliedInfantry
    \brief Concrete Product in the Abstract factory pattern. Concrete Infantry military unit of Allies
    \details Implements the abstract operations that produce product objects that are created
    by the corresponding ConcreteFactories
    Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
    \ingroup MilitaryUnit
    \author Kaitlyn Sookdhew, Wian Koekemoer
*/

#ifndef ALLIEDINFANTRY_H
#define ALLIEDINFANTRY_H

#include "Infantry.h"

class AlliedInfantry : public Infantry {
public:
    /**
        \fn AlliedInfantry::AlliedInfantry
        \brief Constructor
        \param[in] damage               The total damage the AlliedInfantry object should deal to other units
        \param[in] healthpoints         The number of healthpoints the AlliedInfantry object should have
        \param[in] belongsTo            Pointer to Participants object that owns the AlliedInfantry object
        \param[in] rationConsumption    An integer value denoting the total rations consumed when traveling
    */
    AlliedInfantry(int damage, int healthpoints, Participants *belongsTo, int rationConsumption);

    /**
     * \fn AlliedInfactry::~AlliedInfactry
     * \brief virtual destructor
     */
    virtual ~AlliedInfantry() {};

    /**
        \fn AlliedInfantry::clone
        \brief Returns copy of the MilitaryUnit object
    */
    MilitaryUnit *clone();
};


#endif //ALLIEDINFANTRY_H
