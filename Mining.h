#ifndef MINING_H
#define MINING_H

#include "attackStrategy.h"

class Mining : public attackStrategy {
public:
    void execute(Squad* s);
};

#endif //MINING_H
