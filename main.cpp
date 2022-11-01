/**
    \todo figure out a way to decide how big the map should be
    \todo figure out creative mode
*/
#include <iostream>
#include "War.h"
#include "AlliedPowers.h"
#include "CentralPowers.h"

using namespace std;

int main(){
    //Creating the participants for the War
    vector<Participants *> sides;
    Participants * allied = new AlliedPowers();
    Participants * central = new CentralPowers();

    sides.push_back(allied);
    sides.push_back(central);

    //Creating the world map
    int size = 10;
    WorldMap * map = new WorldMap(size);
    War * war = new War(map, sides);

    //Run the war - squiggles ignored for getHealthPoints
    int turn = 0;
    Participants * loser;
    while(!(loser == findLoser(sides))){
        sides.get(turn % side.size())->armyMove();
        for(int i = 0; i < size; i++){
            cout << "[  ";
            for(int j = 0; j < size; j++){
                cout << map->grid[i][j]->getOccupyingForce() << "   ";
            }
            cout << "]\n";
        }
        char ans;
        while(true){
            std::cout << "Would you like to continue in real mode? (Y/N)";
            cin << ans;
            if(ans == 'Y'){
                turn++;
                break;
            }
            else if(ans == 'N'){
                break;
            }
            else{
                cout << "Please enter a valid answer";
            }
        }
    }

    std::cout << loser->getName() << " has lost the war";
}

bool findLoser(vector<Participants *> sides){
    Participants * temp;
    std::vector<Participants *>:: iterator it;
    for (it = sides.begin(); it != sides.end(); ++it)
    {
        if(sides.get(it)->getTotalHealthPoints() <= 0){
            return false;
        }
    }

    return true;
}