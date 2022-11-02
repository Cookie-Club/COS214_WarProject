
#include "Defensive.h"
Defensive::Defensive() {
    state="Defensive";
}

int Defensive::handle(Squad* s) {
    s->setStrategy(new Frontline());
}