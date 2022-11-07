#include "FuelDeposit.h"

FuelDeposit::FuelDeposit() {
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit * m){    
    std::cout << "Occupying force of cell " << x << " " << y << " is now " << occupyingForce.size() << endl; 

    if (feature != 0) {
        feature->execute(m);
    }
    ((Squad*)m)->setFuel(100);
    feature->setOccupyingForce(m);
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it < m.end(); it++){  
        feature->execute(*it);
        ((Squad*)*it)->setFuel(100);
    }
    feature->setOccupyingForce(m);
}

void FuelDeposit::printSymbol(std::string s) {
    s.replace(1, 1, "F");
    feature->printSymbol(s);
}