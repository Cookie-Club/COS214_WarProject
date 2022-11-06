#include "FuelDeposit.h"

FuelDeposit::FuelDeposit(){
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit * m){
    ((Squad*)m)->setFuel(100);

    if(feature != 0){
        feature->execute(m);
    }
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it < m.end(); it++){
        ((Squad*)*it)->setFuel(100);
        if(feature != 0){
            feature->execute(*it);
        }
    }
}

void FuelDeposit::printSymbol(std::string s){
    s.replace(1,1,"F");
    feature->printSymbol(s);
}