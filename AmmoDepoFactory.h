/**
    \file AmmoDepoFactory.h
    \brief Creates the specific AmmoDeposit product
    \details Is in charge of creating the AmmoDeposit specific object. It overrides the factory method in FeatureFactory
    and returns an instance of the product
    Factory: ConcreteCreator
    \ingroup FeatureFactory
    \author Megan Hugo
*/
#ifndef AMMODEPOFACTORY_H
#define AMMODEPOFACTORY_H

#include "FeatureFactory.h"

class AmmoDepoFactory : public FeatureFactory {
    public:
    /**
     * \fn AmmoDepoFactory::AmmoDepoFactory
     * \brief default constructor
     */
        AmmoDepoFactory();

        /**
         * \fnAmmoDepoFactory::createFeature
         * \return CellFeatures*
         * \brief produces AmmoDeposit product
         */
        CellFeatures* createFeature();          
};


#endif //AMMODEPOFACTORY_H

#include "AmmoDeposit.h"