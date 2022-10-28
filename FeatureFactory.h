#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "CellFeatures.h"

class FeatureFactory {

public:
   virtual CellFeatures* createFeature(CellFeatures* component) = 0;
};

#endif
