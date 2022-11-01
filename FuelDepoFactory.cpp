#include "FuelDepoFactory.h"
#include "FuelDeposit.h"

CellFeatures* FuelDepoFactory::createFeature(CellFeatures* component){
    CellFeatures* fd = new FuelDeposit();
    fd->setState(component->getState());
    return fd;
}