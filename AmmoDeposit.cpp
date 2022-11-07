#include "AmmoDeposit.h"

AmmoDeposit::AmmoDeposit(){
    attribute = AmmoDepo;
}

void AmmoDeposit::setOccupyingForce(MilitaryUnit * m){
    ((Squad*)m)->setAmmo(100);
    ((Squad*)m)->setRations(100);

    //Ensure unit not already in cell
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

void AmmoDeposit::setOccupyingForce(std::vector<MilitaryUnit*> m){
    // std::vector<MilitaryUnit*>::iterator it;
    // for(it = m.begin(); it < m.end(); it++){
    //     ((Squad*)*it)->setAmmo(100);
    //     ((Squad*)*it)->setRations(100);
    //     if(feature != 0){
    //         feature->execute(*it);
    //     }
    // }

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

void AmmoDeposit::printSymbol(std::string s){
    s = s.replace(0,1,"A");
    feature->printSymbol(s);
}

//from here
void AmmoDeposit::removeOccupyingForce(std::vector<MilitaryUnit*> m) {
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

void AmmoDeposit::removeOccupyingForce(MilitaryUnit* m) {
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