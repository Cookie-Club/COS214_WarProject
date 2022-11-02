#include "Aggressive.h"

Aggressive::Aggressive() {
    type=Agg;
}

int Aggressive::handle(Squad* s) {
    s->setStrategy(new Mining());
}
