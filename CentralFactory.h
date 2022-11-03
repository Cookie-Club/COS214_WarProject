/**
    \file CentralFactory.h
    \class CentralFactory
    \brief Concrete factory in the Abstract factory pattern
    \details implements the abstract operations to produce concrete product objects
    \ingroup Factory
    \author Kaitlyn Sookdhew
*/
#ifndef AXISFACTORY_H
#define AXISFACTORY_H

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
    Infantry* createInfantry();

    /**
* \fn CentralFactory::createTank
* \return Tank*
* \brief produces concrete tank product
*/
    Tank* createTank();
};



#endif //AXISFACTORY_H
