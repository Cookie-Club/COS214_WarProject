#include "War.h"
War::War(WorldMap *world, std::vector<Participants *> participants) {
    this->world = world;
    this->participants = participants;
}

SaveState *War::createSave() {
    SaveState *save = new SaveState(world, participants);
    return save;
}

WorldMap *War::getWorld() {
    return world;
}

std::vector<Participants *> War::getParticipants() {
    return participants;
}

void War::setWar(SaveState *state) {
    world = state->getWorld();
    participants = state->getParticipants();
}

void War::sendMap() {
    participants.at(0)->setMap(getWorld());
}