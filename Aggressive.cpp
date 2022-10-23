#include "Aggressive.h"

Aggressive::Aggressive() {
    state="Aggressive";
}

void Aggressive::handleChange(Participants *p) {
    p->setState(new Defensive());
}
