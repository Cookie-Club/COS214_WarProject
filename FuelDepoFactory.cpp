#include "FuelDepoFactory.h"
#include "FuelDeposit.h"

FuelDepoFactory::FuelDepoFactory(){}

FuelDeposit* FuelDepoFactory::createFeature(){
    FuelDeposit * fd = new FuelDeposit();
    return fd;
}