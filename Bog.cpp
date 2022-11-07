#include "Bog.h"

Bog::Bog() : Cell("bog") {
    resourceUseMultiplier = 1.5;
    std::cout << "Bog\n";
}

void Bog::execute(MilitaryUnit *m) {
    ((Squad *) m)->setFuel(((Squad *) m)->getFuel() - (5 * resourceUseMultiplier));
    ((Squad *) m)->setRations(
            ((Squad *) m)->getRations() - (5 * ((Squad *) m)->getMembers().size() * resourceUseMultiplier));
}

<<<<<<< Updated upstream
void Bog::printSymbol(std::string s) {
    int code = 39;
    if (owner) code = (int) owner->getParticipant();
=======
void Bog::execute(std::vector<MilitaryUnit *> m) {
    std::vector<MilitaryUnit *>::iterator it;
    for (it = m.begin(); it < m.end(); it++) {
        ((Squad *) *it)->setFuel(((Squad *) *it)->getFuel() - (5 * resourceUseMultiplier));
        ((Squad *) *it)->setRations(
                ((Squad *) *it)->getRations() - (5 * ((Squad *) *it)->getMembers().size() * resourceUseMultiplier));
    }
}


void Bog::printSymbol(std::string s) {
    int code = 39;
    if (owner) code = (int) owner->getParticipantType();
>>>>>>> Stashed changes
    std::cout << "\033[" << code << "m|\033[0m\033[45mBog" << s << occupyingForce.size() << "\033[39m\033[" << code
              << "m\033[0m|";
}
