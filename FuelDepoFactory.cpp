#include "FuelDepoFactory.h"

FuelDepoFactory::FuelDepoFactory(){}

CellFeatures* FuelDepoFactory::createFeature(){
    FuelDeposit * fd = new FuelDeposit();
    return fd;
}