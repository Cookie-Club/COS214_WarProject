
#include "Defensive.h"
Defensive::Defensive() {
    state="Defensive";
}

void Defensive::handleChange(Participants *p) {
    p->setState(new Aggressive());
}