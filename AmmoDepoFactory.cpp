#include "AmmoDepoFactory.h"
#include "AmmoDeposit.h"

AmmoDepoFactory::AmmoDepoFactory(){};

CellFeatures* AmmoDepoFactory::createFeature(){
    CellFeatures* ad;
    ad = new AmmoDeposit();
    return ad;
}