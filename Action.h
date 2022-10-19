#ifndef ACTION_H
#define ACTION_H
#include "Participants.h"

class Action {
public:
	virtual void handleChange(Participants* p) = 0;
};

#endif
