#ifndef WAR_H
#define WAR_H

#include "WorldMap.h"
#include "Participants.h"
#include "SaveState.h"

class War {

private:
	WorldMap* World;
	vector<Participants*> participants;
    void createWorld(int worldSize);
    void startMenu();

public:
	War(WorldMap* world, std::vector<Participants *> participants);
	SaveState* createSave();
	WorldMap* getWorld();
	std::vector<Participants *> getParticipants();
	void setParticipants();

};

#endif
