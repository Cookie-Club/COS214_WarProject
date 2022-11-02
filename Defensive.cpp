
#include "Defensive.h"
Defensive::Defensive() {
    type=Def;
}

int Defensive::handle(Squad* s) {
    s->setStrategy(new Frontline());

    //placed here to to try to compile, needs to be fixed
    return 0;
}