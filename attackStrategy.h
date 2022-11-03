#ifndef ATTACKSTRATEGY_H
#define ATTACKSTRATEGY_H

class Squad;

class attackStrategy{
	public:
		virtual void execute(Squad* s) = 0;
};

#endif

#include "Squad.h"
