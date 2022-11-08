#include "FuelDeposit.h"

FuelDeposit::FuelDeposit() {
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit * m){    
    //first calling it's features execute on each individual MilitaryUnits
    //causing the fuel attribute to be updated and then setting the values to 100 for fuel
    if (feature != 0) {
        feature->execute(m);
    }
    ((Squad*)m)->setFuel(100);
    feature->setOccupyingForce(m);
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    //iterates through the vector passed in, first calling it's features execute on each individual MilitaryUnits
    //causing the fuel attribute to be updated and then setting the value to 100 for fuel
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it != m.end(); it++){  
        feature->execute(*it);
        ((Squad*)*it)->setFuel(100);
    }
    feature->setOccupyingForce(m);
}

void FuelDeposit::printSymbol(std::string s) {
    s.replace(1, 1, "F");
    feature->printSymbol(s);
}