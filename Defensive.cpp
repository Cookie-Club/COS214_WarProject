
#include "Defensive.h"
Defensive::Defensive() {
    state="Defensive";
}

int Defensive::handleChange(int dam) {
    return dam/2;
}