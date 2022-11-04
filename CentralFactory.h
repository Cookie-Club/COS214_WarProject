/**
    \file CentralFactory.h
    \class CentralFactory
    \brief Concrete factory in the Abstract factory pattern
    \details implements the abstract operations to produce concrete product objects
    \ingroup Factory
    \author Kaitlyn Sookdhew
*/
#ifndef CENTRALFACTORY_H
#define CENTRALFACTORY_H

#include "Factory.h"
#include "CentralInfantry.h"
#include "CentralTank.h"

class CentralFactory : public Factory {
public:
    /**
 * \fn CentralFactory::createInfantry
 * \return Infantry*
 * \brief produces concrete infantry product
 */
    Infantry* createInfantry(Participants * belongsTo);

    /**
* \fn CentralFactory::createTank
* \return Tank*
* \brief produces concrete tank product
*/
    Tank* createTank(Participants * belongsTo);
};



#endif //CENTRALFACTORY_H
