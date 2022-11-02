#include "Aggressive.h"

Aggressive::Aggressive() {
    type=Agg;
}

int Aggressive::handle(Squad* s) {
    s->setStrategy(new Mining());
    //changed just to get compilation - needs to be fixed properly
    return 0;
}
