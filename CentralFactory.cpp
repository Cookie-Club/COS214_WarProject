#include "CentralFactory.h"

Infantry *CentralFactory::createInfantry(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    int damage = std::rand() % 10 + 10;
    return new CentralInfantry(damage,100,belongsTo,10);
}

Tank *CentralFactory::createTank(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    int damage = std::rand() % 30 + 10;
    return new CentralTank(damage,100,belongsTo,10);
}