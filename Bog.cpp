#include "Bog.h"

Bog::Bog () {
    resourceUseMultiplier = 1.5;
}

Bog::execute(MilitaryUnit * m){
    ((Squad*)m)->setFuel(((Squad*)m)->getFuel - (5 * resourceUseMultiplier));
    ((Squad*)m)->setRations(((Squad*)m)->getRations() - (5 * ((Squad*)m)->getMembers().size() * resourceUseMultiplier));
}

Added fuel and ammo updating when the occupying force of a cell is set. This includes reducing fuel and rations 