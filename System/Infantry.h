
/**
    \file Infantry.h
	\class Infantry
	\brief Abstract interface for infantry objects
    \details Prototype pattern: AbstractProduct
    \ingroup MilitaryUnit
	\author Wian Koekemoer, Kaitlyn Sookdhew
*/

#ifndef INFANTRY_H
#define INFANTRY_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Infantry : public TeamMembers {
public:
    /**
        \fn Infantry::Infantry
        \brief Constructor
        \param[in] damage               The total damage the Infantry object should deal to other units
        \param[in] healthpoints         The number of healthpoints the Infantry object should have
        \param[in] belongsTo            Pointer to Participants object that owns the Infantry object
        \param[in] rationConsumption    An integer value denoting the total rations consumed when traveling
    */
    Infantry(int damage, int healthpoints, Participants *belongsTo, int rationConsumption);

    /**
        \fn Infantry::~Infantry
        \brief Virtual destructor
     */
    virtual ~Infantry() {};

    /**
        \fn Infantry::clone
        \brief Pure virtual function inherited from MilitaryUnit
    */
    virtual MilitaryUnit *clone() = 0;

    /**
        \fn Tank::getRationConsumption
        \brief Getter for rationConsumption
    */
    int getRationConsumption();

    /**
        \fn Tank::setRationConsumption
        \brief Setter for rationConsumption
        \param[in] rationConsumption    Sets the total rations consumed when traveling
    */
    void setRationConsumption(int rationConsumption);

protected:
    int rationConsumption;
};


#endif
