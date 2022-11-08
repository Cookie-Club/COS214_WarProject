#include "AlliedFactory.h"

Infantry *AlliedFactory::createInfantry(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    //random damage assigned to AlliedInfantry
    int damage = std::rand() % 10 + 10;
    return new AlliedInfantry(damage, 100, belongsTo, 10);
}

Tank *AlliedFactory::createTank(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    //random damage assigned to AlliedInfantry
    int damage = std::rand() % 30 + 10;
    return new AlliedTank(damage, 100, belongsTo, 10);
}
