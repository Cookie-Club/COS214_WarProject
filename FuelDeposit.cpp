#include "FuelDeposit.h"

FuelDeposit::FuelDeposit() {
    attribute = FuelDepo;
}

void FuelDeposit::setOccupyingForce(MilitaryUnit *m) {
<<<<<<< Updated upstream
    occupyingForce.push_back(m);
    ((Squad *) m)->setFuel(100);
=======
    std::cout << "Occupying force of cell " << x << " " << y << " is now " << occupyingForce.size() << endl;
>>>>>>> Stashed changes

    if (feature != 0) {
        feature->execute(m);
    }
<<<<<<< Updated upstream
=======
    ((Squad *) m)->setFuel(100);
    feature->setOccupyingForce(m);
>>>>>>> Stashed changes
}

void FuelDeposit::setOccupyingForce(std::vector<MilitaryUnit *> m) {
    std::vector<MilitaryUnit *>::iterator it;
    for (it = m.begin(); it < m.end(); it++) {
<<<<<<< Updated upstream
        occupyingForce.push_back(*it);
        ((Squad *) *it)->setFuel(100);
        if (feature != 0) {
            feature->execute(*it);
        }
=======
        feature->execute(*it);
        ((Squad *) *it)->setFuel(100);
>>>>>>> Stashed changes
    }
}

void FuelDeposit::printSymbol(std::string s) {
    s.replace(1, 1, "F");
    feature->printSymbol(s);
}