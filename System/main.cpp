/**
    \file main.cpp
    \todo figure out a way to decide how big the map should be
    \todo figure out creative mode
*/
#include <iostream>
#include "War.h"
#include "Caretaker.h"
#include "AlliedPowers.h"
#include "CentralPowers.h"
#include "CentralFactory.h"
#include "AlliedFactory.h"
#include "Squad.h"

using namespace std;

bool findLoser(vector<Participants *> sides){
    std::vector<Participants *>:: iterator it;
    Cell*** map = sides[0]->getMap()->getGrid();
    for (it = sides.begin(); it != sides.end(); ++it)
    {
        if((*it)->getTotalHealthPoints() <= 0){
            return *it;
        }
    }

    bool alliedWon = false;
    bool centralWon = false;

    for (int x = 0; x < 9; ++x)
    {
        if (map[x][0]->getOwner() == sides[1]) centralWon = true;
    }
    for (int x = 0; x < 9; ++x)
    {
        if (map[x][9]->getOwner() == sides[0]) alliedWon = true;
    }
    if (alliedWon == centralWon && alliedWon == false) return false;

    if (alliedWon == true && centralWon == true)
    {
        if (sides[0]->getTotalHealthPoints() < sides[1]->getTotalHealthPoints()){
            std::cout << "Allied health: " << sides[0]->getTotalHealthPoints() << "\nCentral health: " << sides[1]->getTotalHealthPoints() << "\nAllied Powers";
            return true;
        }
        else if(sides[0]->getTotalHealthPoints() > sides[1]->getTotalHealthPoints()){
            std::cout << "Allied health: " << sides[0]->getTotalHealthPoints() << "\nCentral health: " << sides[1]->getTotalHealthPoints() << "\nCentral Powers";
            return true;
        }
        else{
            std::cout << "Allied health: " << sides[0]->getTotalHealthPoints() << "\nCentral health: " << sides[1]->getTotalHealthPoints() << "\nNo one";
            return true;
        }
        
    }
    if (alliedWon){
        std::cout << "Central Powers";
        return true;
    } 
    else{
        std::cout << "Allied Powers";
        return true;
    }
    
}

void printMap(War * war){
    string key[9] = {"[                    \033[4mKEY:\033[0m                    ]",
                    "[          \033[45mPink Highlighting\033[0m = Bog           ]", 
                    "[      \033[43mYellow Highlighting\033[0m = Flatlands       ]",
                    "[       No Highlighting = Normal Cell        ]",
                    "[ Numbers on RHS = Number of friendly squads ]",
                    "[    Green Borders(\033[32m|\033[0m) = Allied Owned Cell    ]",
                    "[     Red Borders(\033[31m|\033[0m) = Allied Owned Cell     ]",
                    "[    'A' char in position 5 = AmmoDeposit    ]",
                    "[    'F' char in position 5 = FuelDeposit    ]"};
    for(int i = 0; i < war->getWorld()->getSize(); i++){
        std::cout << "[  ";
        for(int j = 0; j < war->getWorld()->getSize(); j++){
            war->getWorld()->getCell(i, j)->printSymbol();
            std::cout << "   ";
        }

        std::cout << "]";
        if(i < 9){
            std::cout << "     " << key[i] << endl;
        }
        else{
            std::cout << endl;
        }
    }
}

int main(){
    
    //Size of map
    int size = 10;

    //Creating map
    WorldMap * map = new WorldMap(size);
    std::vector<Participants*> parties;

    //Creating Allied and Central powers
    parties.push_back(new AlliedPowers(Allied));
    parties.push_back(new CentralPowers(Central));

    //Giving participants visibility of map
    parties.at(0)->setMap(map);
    parties.at(1)->setMap(map);

    //Creating War
    War * war = new War(map, parties);
    Caretaker * STORAGE = new Caretaker(war->createSave());

    //Creating abstract factories that will create military units
    Factory * aFactory = new AlliedFactory();
    Factory * cFactory = new CentralFactory();

    //Creating 20 ally squads
    for(int i = 0; i < 20; i++){
        //Adding squad to ally
        Squad * temp = new Squad(war->getParticipants().at(0));
        //Adding 10 infantry to squad
        for(int j = 0; j < 10; j++){
            temp->addMember(aFactory->createInfantry(war->getParticipants().at(0)));
        }
        //Adding 5 tanks to squad
        for(int q = 0; q < 5; q++){
            temp->addMember(aFactory->createTank(war->getParticipants().at(0)));
        }
    }

    //Creating 20 central squads
    for(int i = 0; i < 20; i++){
        //Adding squad to central
        Squad * temp = new Squad(war->getParticipants().at(1));
        //Adding 10 infantry to squad
        for(int j = 0; j < 10; j++){
            temp->addMember(cFactory->createInfantry(war->getParticipants().at(1)));
        }
        //Adding 5 tanks to squad
        for(int q = 0; q < 5; q++){
            temp->addMember(cFactory->createTank(war->getParticipants().at(1)));
        }
    }

    std::cout << "Placing allied troops" << endl; 
    int counter = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 2; j++){
            ((Squad*)war->getParticipants().at(0)->getArmy()->at(counter))->setOccupyingCell(war->getWorld()->getCell(i, j));
            war->getParticipants().at(0)->getOwnedTerritories()->push_back(war->getWorld()->getCell(i, j));
            counter++;
        }
    }

    std::cout << "Placing central troops" << endl;
    counter = 0;
    for(int i = 0; i < size; i++){
        for(int j = size - 2; j < size; j++){
            ((Squad*)war->getParticipants().at(1)->getArmy()->at(counter))->setOccupyingCell(war->getWorld()->getCell(i, j));
            war->getParticipants().at(1)->getOwnedTerritories()->push_back(war->getWorld()->getCell(i, j));
            counter++;
        }
    }

    printMap(war);

    int turn = 0;
    bool loser = false;
    
        char starter;
        std::cout << "Press any key to begin war..." << endl;
        std::cin.get();

    while(!loser){
        system("clear");
        war->getParticipants().at(turn % war->getParticipants().size())->armyMove();
        printMap(war);
            char ans;
            std::cout << "Would you like to continue in real mode? (Y/N) or create a new save point (S)";
            std::cin >> ans;
            while(true){
                if(ans == 'Y'){
                    turn++;
                break;
                }
                else if(ans == 'N'){
                    break;
                }
                else if(ans == 'S'){
                    std::cout << "New save being created" << endl;
                    STORAGE->addMemento(war->createSave());
                    break;
                }
                else
                {
                    std::cout << "Please enter a valid answer\n";
                    std::cout << "Would you like to continue in real mode? (Y/N)";
                    std::cin >> ans;
                }

                
            }

            if (turn %2 == 0)
            {
                loser = findLoser(war->getParticipants());
            }
    }
    std::cout << " lost the war\n";
    printMap(war);

    return 0;
}