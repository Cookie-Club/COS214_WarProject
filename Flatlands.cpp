#include "Flatlands.h"

void Flatlands::execute(MilitaryUnit * m){
    ((Squad*)m)->setFuel(((Squad*)m)->getFuel() - 5);
    ((Squad*)m)->setRations(((Squad*)m)->getRations() - (5 * ((Squad*)m)->getMembers().size()));
    type = "flatlands";
}

void Flatlands::printSymbol(std::string s)
{
    int code = 39;
    if (owner) code = (int)owner->getParticipant();
    std::cout << "\033[" << code<< "m|\033[0m\033[43mFla" << s << occupyingForce.size() << "\033[0\033[" << code<< "m\033[0m|";
}
