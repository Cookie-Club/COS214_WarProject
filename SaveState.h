#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "WorldMap.h"
#include "Participants.h"

class SaveState {
	private:
		WorldMap* World;
		vector<Participants*> participants;
		static int counter;
		const int id;
	public:
		SaveState(WorldMap * world, vector<Participants*> participants);
		WorldMap* getWorld();
		vector<Participants*> getParticipants();
		int getID();
		// void setState(SaveState *);
};

#endif
