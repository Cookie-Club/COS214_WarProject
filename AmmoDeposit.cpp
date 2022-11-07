#include "AmmoDeposit.h"

AmmoDeposit::AmmoDeposit() {
    attribute = AmmoDepo;
}

void AmmoDeposit::setOccupyingForce(MilitaryUnit *m) {
<<<<<<< Updated upstream
    occupyingForce.push_back(m);
    ((Squad *) m)->setAmmo(100);
    ((Squad *) m)->setRations(100);

=======
    std::cout << "Occupying force of cell " << x << " " << y << " is now " << occupyingForce.size() << endl;
>>>>>>> Stashed changes

    if (feature != 0) {
        feature->execute(m);
    }
<<<<<<< Updated upstream
=======

    ((Squad *) m)->setAmmo(100);
    ((Squad *) m)->setRations(100);
>>>>>>> Stashed changes
}

void AmmoDeposit::setOccupyingForce(std::vector<MilitaryUnit *> m) {
    std::vector<MilitaryUnit *>::iterator it;
    for (it = m.begin(); it < m.end(); it++) {
<<<<<<< Updated upstream
        occupyingForce.push_back(*it);
        ((Squad *) *it)->setAmmo(100);
        ((Squad *) *it)->setRations(100);
        if (feature != 0) {
            feature->execute(*it);
        }
=======
        feature->execute(*it);
        ((Squad *) *it)->setAmmo(100);
        ((Squad *) *it)->setRations(100);
>>>>>>> Stashed changes
    }
}

void AmmoDeposit::printSymbol(std::string s) {
    s = s.replace(0, 1, "A");
    feature->printSymbol(s);
}