/**
    \file FuelDepoFactory.h
    \class FuelDepoFactory
    \brief Creates the specific FuelDeposit product
    \details Is in charge of creating the FuelDeposit specific object. It overrides the factory method in FeatureFactory
    and returns an instance of the product
    Factory: ConcreteCreator
    \ingroup FeatureFactory
    \author Megan Hugo
*/
///\todo Function Documentation
#ifndef FUELDEPOFACTORY_H
#define FUELDEPOFACTORY_H

#include "FeatureFactory.h"

class FuelDepoFactory : public FeatureFactory {
    public:
        FuelDepoFactory();
        CellFeatures* createFeature(); 
};

#endif //FUELDEPOFACTORY_H

#include "FuelDeposit.h"
