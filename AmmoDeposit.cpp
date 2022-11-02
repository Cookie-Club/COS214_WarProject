#include "AmmoDeposit.h"

AmmoDeposit::AmmoDeposit(){}

void AmmoDeposit::setOccupyingForce(MilitaryUnit * m){
    occupyingForce.push_back(m);
    ((Squad*)m)->setAmmo(100);
    ((Squad*)m)->setRations(100);


    if(feature != 0){
        feature->execute(m);
    }
}