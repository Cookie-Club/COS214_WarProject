/**
    \todo figure out a way to decide how big the map should be
    \todo figure out creative mode
*/
#include <iostream>
#include "War.h"
#include "AlliedPowers.h"
#include "CentralPowers.h"

using namespace std;

Participants* findLoser(vector<Participants *> sides){
    Participants * temp;
    std::vector<Participants *>:: iterator it;
    for (it = sides.begin(); it != sides.end(); ++it)
    {
        if((*it)->getTotalHealthPoints() <= 0){
            return *it;
        }
    }

    return nullptr;
}

int main(){
    std::cout << "1\n";
    //Creating the participants for the War
    vector<Participants *> sides;
    Participants * allied = new AlliedPowers();
    Participants * central = new CentralPowers();
    std::cout << "2\n";

    sides.push_back(allied);
    sides.push_back(central);
    std::cout << "3\n";

    //Creating the world map
    int size = 10;
    WorldMap * map = new WorldMap(size);
    War * war = new War(map, sides);
    std::cout << "4\n";

    int turn = 0;
    Participants * loser;
    std::cout << "5\n";
    while(!(loser == findLoser(sides))){
        sides.at(turn % sides.size())->armyMove();
        for(int i = 0; i < size; i++){
            std::cout << "[  ";
            for(int j = 0; j < size; j++){
                // cout << map->getGrid()[i][j]->getOccupyingForce() << "   ";
            }
            std::cout << "]\n";
        }
        char ans;
        while(true){
            std::cout << "Would you like to continue in real mode? (Y/N)";
            std::cin >> ans;
            if(ans == 'Y'){
                turn++;
                system("clear");
                break;
            }
            else if(ans == 'N'){
                system("clear");
                break;
            }
            else{
                std::cout << "Please enter a valid answer";
            }
        }
    }
    std::cout << loser->getName() << " has lost the war\n";
    return 0;
}