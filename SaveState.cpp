#include "SaveState.h"

int SaveState::counter = 0;

SaveState::SaveState(WorldMap *world, vector<Participants *> participants) : id(counter++) {
    this->World = world;
    this->participants = participants;
}

WorldMap *SaveState::getWorld() {
    return World;
}

vector<Participants *> SaveState::getParticipants() {
    return this->participants;
}

int SaveState::getID() {
    return id;
}
