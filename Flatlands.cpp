#include "Flatlands.h"

Flatlands::execute(MilitaryUnit * m){
    ((Squad*)m)->setFuel(((Squad*)m)->getFuel() - 5);
    ((Squad*)m)->setRations(((Squad*)m)->getRations() - (5 * (Squad*)m)->getMemebers().size());
}