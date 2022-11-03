#include "AmmoDepoFactory.h"

AmmoDepoFactory::AmmoDepoFactory(){};

AmmoDeposit* AmmoDepoFactory::createFeature(){
    AmmoDeposit* ad;
    ad = new AmmoDeposit();
    return ad;
}