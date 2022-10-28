
#include "AmmoDepoFactory.h"
#include "AmmoDeposit.h"

AmmoDepoFactory::AmmoDepoFactory(){};

CellFeatures* AmmoDepoFactory::createFeature(CellFeatures* component){
    return new AmmoDeposit();
}