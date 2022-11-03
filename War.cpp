#include "War.h"

War::War(WorldMap* world, std::vector<Participants*> participants) {
	// TODO - implement War::War
	//throw "Not yet implemented";
}

SaveState* War::createSave(int id) { // create m
	SaveState* save = new SaveState(World,participants, id);
	// save->setState(state);
	return save;
}

WorldMap* War::getWorld() { // get img
	return World;
}

std::vector<Participants*> War::getParticipants() {
	//needs to change
	vector<Participants*> p;
	return p;
}

void War::createWorld(int worldSize) {
	// TODO - implement War::createWorld
	//throw "Not yet implemented";
	return ;
}

void War::setWar(SaveState * state) { // reinstate mem
	 World = state->getWorld();
	 participants = state->getParticipants();
}

void War::startMenu() {
	// TODO - implement War::startMenu
	// throw "Not yet implemented";
	return;
}
