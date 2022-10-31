#include "FuelDepoFactory.h"
#include "FuelDeposit.h"

CellFeatures* FuelDepoFactory::createFeature(CellFeatures* component){
    CellFeatures* FD = new FuelDeposit();
    FD->setState(component->getState());

    return FD;
}