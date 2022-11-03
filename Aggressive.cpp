#include "Aggressive.h"

Aggressive::Aggressive() {
    type = Agg;
}

void Aggressive::handle(Squad* s) {
    s->setStrategy(new Mining());
}
