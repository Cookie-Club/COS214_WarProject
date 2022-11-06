#include "AmmoDeposit.h"

AmmoDeposit::AmmoDeposit(){
    attribute = AmmoDepo;
}

void AmmoDeposit::setOccupyingForce(MilitaryUnit * m){
    ((Squad*)m)->setAmmo(100);
    ((Squad*)m)->setRations(100);


    if(feature != 0){
        feature->execute(m);
    }
}

void AmmoDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it < m.end(); it++){
        ((Squad*)*it)->setAmmo(100);
        ((Squad*)*it)->setRations(100);
        if(feature != 0){
            feature->execute(*it);
        }
    }
}

void AmmoDeposit::printSymbol(std::string s){
    s = s.replace(0,1,"A");
    feature->printSymbol(s);
}