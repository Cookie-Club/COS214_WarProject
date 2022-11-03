#include "AmmoDepoFactory.h"

AmmoDepoFactory::AmmoDepoFactory(){};

CellFeatures* AmmoDepoFactory::createFeature(){
    AmmoDeposit* ad;
    ad = new AmmoDeposit();
    return ad;
}