#ifndef FRONTLINE_H
#define FRONTLINE_H

#include "attackStrategy.h"

class Frontline : public attackStrategy {

public:
    void execute(Squad* s);
};

#endif //FRONTLINE_H
