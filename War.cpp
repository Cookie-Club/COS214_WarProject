#include "War.h"
/**
    \file War.cpp
    \todo implement War::War
    \todo implement War::createWorld
	\todo implement War::startMenu

*/
War::War(WorldMap* world, std::vector<Participants*> participants) {

	//throw "Not yet implemented";
}

SaveState* War::createSave(int id) { // create m
    SaveState* save = new SaveState(world, participants, id);
    // save->setState(state);
    return save;
}

WorldMap* War::getWorld() { // get img
    return world;
}

std::vector<Participants*> War::getParticipants() {
    //needs to change
    vector<Participants*> p;
    return p;
}

void War::createWorld(int worldSize) {
	//throw "Not yet implemented";
	return ;
}

void War::setWar(SaveState * state) { // reinstate mem
    world = state->getWorld();
    participants = state->getParticipants();
}

void War::startMenu() {
	// throw "Not yet implemented";
	return;
}

void War::sendMap() {
    participants.at(0)->setMap(getWorld());
}