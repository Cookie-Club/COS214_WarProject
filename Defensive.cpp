
#include "Defensive.h"
Defensive::Defensive() {
    type=Def;
}

int Defensive::handle(Squad* s) {
    s->setStrategy(new Frontline());
}