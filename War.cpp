#include "War.h"

War::War(WorldMap* world, std::vector<Participants*> participants) {
	// TODO - implement War::War
	//throw "Not yet implemented";
}

SaveState* War::createSave() { // create m
	SaveState* save = new SaveState();
	save->setState(state);
	return save;
}

WorldMap* War::getWorld() { // get img
	return World;
}

std::vector<Participants*> War::getParticipants() {// get real
	return Participants;
}

void War::createWorld(int worldSize) {
	// TODO - implement War::createWorld
	//throw "Not yet implemented";
	return ;
}

void War::setWar(SaveState state) { // reinstate mem
	 World=save.getWorld;
	 Participants = save.getParticipants
}

void War::startMenu() {
	// TODO - implement War::startMenu
	// throw "Not yet implemented";
	return;
}
