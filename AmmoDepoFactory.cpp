#include "AmmoDepoFactory.h"

AmmoDepoFactory::AmmoDepoFactory(){};

CellFeatures* AmmoDepoFactory::createFeature(){
    CellFeatures * ad = new AmmoDeposit();
    return ad;
}