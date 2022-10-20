#ifndef WAR_H
#define WAR_H

#include "WorldMap.h"
#include "Participants.h"
#include "SaveState.h"

class War {

private:
	WorldMap* World;
	vector<Participants*> Participants;
    void createWorld(int worldSize);
    void startMenu();

public:
	War(WorldMap* world, vector<Participants*> participants);
	SaveState* createSave();
	WorldMap* getWorld();
	vector<Participants*> getParticipants();
	void setParticipants();

};

#endif
