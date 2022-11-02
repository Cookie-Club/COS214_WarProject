
#include "Defensive.h"
Defensive::Defensive() {
    state="Defensive";
}

int Defensive::handleChange(Squad* s) {
    attackStrategy* strat=new Frontline();
    s->setStrategy(strat);
}