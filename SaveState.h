
/**
	\file SaveState.h
	\class SaveState
	\brief **  Documentation Pending **
	\todo Documentation
*/
#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "WorldMap.h"
#include "Participants.h"

class SaveState {
	private:
		WorldMap* World;
		vector<Participants*> participants;
		int id;

	public:
		SaveState(WorldMap * world, vector<Participants*> participants, int id);
		WorldMap* getWorld();
		vector<Participants*> getParticipants();
		int getID();
		// void setState(SaveState *);
};

#endif
