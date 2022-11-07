#include "SquadDamage.h"

SquadDamage::SquadDamage() {}

void SquadDamage::damageMember(MilitaryUnit *currentUnit) {
    if (currentUnit->getType() == squad) {
<<<<<<< Updated upstream
        for (int i = 0; i < ((Squad *) currentUnit)->getMembers().capacity(); i++) {
            next->damageMember(((Squad *) currentUnit)->getMembers().at(i));
=======
        std::cout << "Squad Damage" << endl;
        for (int i = 0; i < ((Squad *) currentUnit)->getMembers().size(); i++) {
            next->damageMember(((Squad *) currentUnit)->getMembers()[i]);
>>>>>>> Stashed changes
        }
    } else if (next) {
        next->damageMember(currentUnit);
    }
}
