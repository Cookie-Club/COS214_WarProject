
#include "Defensive.h"
Defensive::Defensive() {
    type=Def;
}

void Defensive::handle(Squad* s) {
    s->setStrategy(new Frontline());
}