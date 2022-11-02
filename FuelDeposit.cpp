#include "FuelDeposit.h"

FuelDeposit::FuelDeposit(){}

FuelDeposit::setOccupyingForce(MilitaryUnit * m){
    occupyingForce.push_back(m);
    ((Squad*)m)->setFuel(100);

    if(feature != 0){
        feature->execute(m);
    }
}