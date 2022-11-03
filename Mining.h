#ifndef MINING_H
#define MINING_H

#include "attackStrategy.h"

class Mining : public attackStrategy {
public:
    Mining();
    void execute(Squad* s);
};

#endif //INFILTRATE_H
