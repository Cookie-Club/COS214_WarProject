#include "AmmoDepoFactory.h"
#include "AmmoDeposit.h"

AmmoDepoFactory::AmmoDepoFactory(){};

CellFeatures* AmmoDepoFactory::createFeature(CellFeatures* component){
    CellFeatures* ad;
    ad = new AmmoDeposit(); 
    ad->setState(component->getState());
    return ad;
}