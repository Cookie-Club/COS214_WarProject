
#include "AlliedFactory.h"

Infantry *AlliedFactory::createInfantry() {
    return new AlliedInfantry();
}

Tank *AlliedFactory::createTank() {
    return new AlliedTank();
}
