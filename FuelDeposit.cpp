#include "FuelDeposit.h"

FuelDeposit::FuelDeposit(){
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit * m){
    occupyingForce.push_back(m);
    ((Squad*)m)->setFuel(100);

    if(feature != 0){
        feature->execute(m);
    }
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it < m.end(); it++){
        occupyingForce.push_back(*it);
        ((Squad*)*it)->setFuel(100);
        if(feature != 0){
            feature->execute(*it);
        }
    }
}