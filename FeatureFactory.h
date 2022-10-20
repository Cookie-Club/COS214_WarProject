#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "CellFeatures.h"

class FeatureFactory {

public:
    CellFeatures* createFeature(CellFeatures* component);
};

#endif
