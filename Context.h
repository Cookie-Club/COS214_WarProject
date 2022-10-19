#ifndef CONTEXT_H
#define CONTEXT_H

#include "attackStrategy.h"

class Context {
private:
	attackStrategy* strategy;

public:
	Context(attackStrategy* strategy);
	~Context();
	void attack();
};

#endif
