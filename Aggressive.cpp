#include "Aggressive.h"

Aggressive::Aggressive() {
    state="Aggressive";
}

int Aggressive::handle(Squad* s) {
    s->setStrategy(new Mining());
}