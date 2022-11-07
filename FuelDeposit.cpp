#include "FuelDeposit.h"

FuelDeposit::FuelDeposit(){
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit * m){
    ((Squad*)m)->setFuel(100);
    std::vector<MilitaryUnit*>::iterator it = occupyingForce.begin();
    while (it != occupyingForce.end())
    {
        if ((*it) == m) 
            return;

        ++it;
    }
    occupyingForce.push_back(m);
    std::cout << "Occupying force of cell " << x << " " << y << " is now " << occupyingForce.size() << endl; 

    if(feature != 0){
        feature->execute(m);
    }
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    // std::vector<MilitaryUnit*>::iterator it;
    // for(it = m.begin(); it < m.end(); it++){
    //     ((Squad*)*it)->setFuel(100);
    //     if(feature != 0){
    //         feature->execute(*it);
    //     }
    // }
    //Iterates through m
    std::vector<MilitaryUnit*>::iterator it;
    //Iterates through OccupyingForce
    std::vector<MilitaryUnit*>::iterator occIt;
    bool found = false;
    for(it = m.begin(); it < m.end(); it++){
        found = false;
        while (occIt != occupyingForce.end())
        {
            if ((*it) == (*occIt)) 
            {
                found = true;
                break;
            }

            ++occIt;
        }
        if (!found)occupyingForce.push_back(*it);
        feature->execute(*it);
    }
}

void FuelDeposit::printSymbol(std::string s){
    s.replace(1,1,"F");
    feature->printSymbol(s);
}

//from here
void FuelDeposit::removeOccupyingForce(std::vector<MilitaryUnit*> m) {
    std::vector<MilitaryUnit*>::iterator it = m.begin();
    for (; it != m.begin(); ++it)
    {
        std::vector<MilitaryUnit*>::iterator it2 = occupyingForce.begin();
        for (; it2 != occupyingForce.end(); ++it2)
            if (*it2 == *it)
            {
                occupyingForce.erase(it2);
                if(feature){
                    feature->removeOccupyingForce(*it);
                }
                return;
            }
    }
}

void FuelDeposit::removeOccupyingForce(MilitaryUnit* m) {
    std::vector<MilitaryUnit*>::iterator it = occupyingForce.begin();
    for (; it != occupyingForce.end(); ++it)
        if (*it == m)
        {
            occupyingForce.erase(it);
            if(feature){
                feature->removeOccupyingForce(m);
            }
            return;
        }

    std::cout << "Remaining squads fo cell " << x << " " << y << ": " << occupyingForce.size() << endl;
}