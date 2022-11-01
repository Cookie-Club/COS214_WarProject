
#include "Defensive.h"
Defensive::Defensive() {
    type = Def;
}

int Defensive::handleChange(int dam) {
    return dam/2;
}