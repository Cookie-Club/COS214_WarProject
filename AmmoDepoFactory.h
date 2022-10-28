#ifndef AMMODEPOFACTORY_H
#define AMMODEPOFACTORY_H

#include "FeatureFactory.h"

class AmmoDepoFactory : public FeatureFactory {
    AmmoDepoFactory();  
    CellFeatures* createFeature(CellFeatures* component);          

};


#endif //AMMODEPOFACTORY_H
