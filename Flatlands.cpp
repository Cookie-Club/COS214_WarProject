#include "Flatlands.h"

Flatlands::Flatlands() : Cell("flatlands") {
    std::cout << "Flatlands\n";
}

void Flatlands::execute(MilitaryUnit *m) {
    ((Squad *) m)->setFuel(((Squad *) m)->getFuel() - 5);
    ((Squad *) m)->setRations(((Squad *) m)->getRations() - (5 * ((Squad *) m)->getMembers().size()));
}

<<<<<<< Updated upstream
void Flatlands::printSymbol(std::string s) {
    int code = 39;
    if (owner) code = (int) owner->getParticipant();
=======
void Flatlands::execute(std::vector<MilitaryUnit *> m) {
    std::vector<MilitaryUnit *>::iterator it;
    for (it = m.begin(); it < m.end(); it++) {
        ((Squad *) *it)->setFuel(((Squad *) *it)->getFuel() - 5);
        ((Squad *) *it)->setRations(((Squad *) *it)->getRations() - (5 * ((Squad *) *it)->getMembers().size()));
    }

    type = "flatlands";
}

void Flatlands::printSymbol(std::string s) {
    int code = 39;
    if (owner) code = (int) owner->getParticipantType();
>>>>>>> Stashed changes
    std::cout << "\033[" << code << "m|\033[0m\033[43mFla" << s << occupyingForce.size() << "\033[0\033[" << code
              << "m\033[0m|";
}
