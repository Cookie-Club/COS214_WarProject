/**
    \file FuelDepoFactory.h
    \brief Creates the specific FuelDeposit product
    \details Is in charge of creating the FuelDeposit specific object. It overrides the factory method in FeatureFactory
    and returns an instance of the product
    Factory: ConcreteCreator
    \ingroup FeatureFactory
    \author Megan Hugo
*/
#ifndef FUELDEPOFACTORY_H
#define FUELDEPOFACTORY_H

#include "FeatureFactory.h"
#include "FuelDeposit.h"

class FuelDepoFactory : public FeatureFactory {
    public:
        FuelDepoFactory();
        FuelDeposit* createFeature(); 
};

#endif //FUELDEPOFACTORY_H
