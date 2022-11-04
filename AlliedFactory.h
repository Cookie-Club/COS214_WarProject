/**
    \file AlliedFactory.h
    \class AlliedFactory
    \brief Concrete factory in the Abstract factory pattern
    \details implements the abstract operations to produce concrete product objects
    \ingroup Factory
    \author Kaitlyn Sookdhew
*/
#ifndef ALLIEDFACTORY_H
#define ALLIEDFACTORY_H

#include "Factory.h"
#include "AlliedInfantry.h"
#include "AlliedTank.h"

class AlliedFactory : public Factory {
public:
    /**
     * \fn AlliedFactory::createInfantry
     * \return Infantry*
     * \brief produces concrete infantry product
     */
    Infantry* createInfantry(Participants * belongsTo);
    /**
   * \fn AlliedFactory::createTank
   * \return Tank*
   * \brief produces concrete tank product
   */
    Tank* createTank(Participants * belongsTo);
};


#endif //ALLIEDFACTORY_H
