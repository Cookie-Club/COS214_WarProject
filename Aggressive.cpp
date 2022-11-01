#include "Aggressive.h"

Aggressive::Aggressive(){
    type = Agg;
}

int Aggressive::handleChange( int dam) {
     return dam*2;
}
