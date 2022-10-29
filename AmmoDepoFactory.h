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
    AmmoDepoFactory();  
    CellFeatures* createFeature(CellFeatures* component);          
};


#endif //AMMODEPOFACTORY_H
