#ifndef FUELDEPOFACTORY_H
#define FUELDEPOFACTORY_H

#include "FeatureFactory.h"

class FuelDepoFactory : public FeatureFactory {
    FuelDepoFactory();
    CellFeatures* createFeature(CellFeatures* component); 
};

#endif //FUELDEPOFACTORY_H
