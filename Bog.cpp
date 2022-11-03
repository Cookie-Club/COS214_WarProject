#include "Bog.h"

Bog::Bog () {
    resourceUseMultiplier = 1.5;
}

void Bog::execute(MilitaryUnit * m){
    ((Squad*)m)->setFuel(((Squad*)m)->getFuel() - (5 * resourceUseMultiplier));
    ((Squad*)m)->setRations(((Squad*)m)->getRations() - (5 * ((Squad*)m)->getMembers().size() * resourceUseMultiplier));
}