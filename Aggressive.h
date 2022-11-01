#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"
class Aggressive : public Action {
public:
    Aggressive();
    int handleChange(Squad* s);
};


#endif //AGGRESSIVE_H
