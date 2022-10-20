#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "Cell.h"

class FeatureFactory {

public:
    Cell* createFeature(Cell* component);
};

#endif
