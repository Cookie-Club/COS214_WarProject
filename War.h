#ifndef WAR_H
#define WAR_H

#include "WorldMap.h"
#include "Participants.h"
#include "SaveState.h"

class War {

private:
    WorldMap* world;
    std::vector<Participants*> participants;
    void createWorld(int worldSize);
    SaveState * lastSave;

public:
    War(WorldMap* world, std::vector<Participants *> participants);
    SaveState* createSave();
    WorldMap* getWorld();
    std::vector<Participants *> getParticipants();
    //void setParticipants();
    void setWar(SaveState * ss);
    void sendMap();
};

#endif
