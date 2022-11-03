#include "Flatlands.h"

void Flatlands::execute(MilitaryUnit * m){
    ((Squad*)m)->setFuel(((Squad*)m)->getFuel() - 5);
    ((Squad*)m)->setRations(((Squad*)m)->getRations() - (5 * ((Squad*)m)->getMembers().size()));
}
/*
void Flatlands::add(Cell * addition)
{ 
    /// @todo Implement properly
    std::cout << "Cannot add anymore additional resources to this Flatland cell" << endl;
}
*/