#include "Aggressive.h"

Aggressive::Aggressive() {
    state="Aggressive";
}

int Aggressive::handleChange( int dam) {
     return dam*2;
}
