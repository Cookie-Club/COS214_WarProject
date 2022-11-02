#include "FuelDepoFactory.h"
#include "FuelDeposit.h"

FuelDepoFactory::FuelDepoFactory(){}

CellFeatures* FuelDepoFactory::createFeature(){
    CellFeatures* fd = new FuelDeposit();
    return fd;
}