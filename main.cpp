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

Participants* findLoser(vector<Participants *> sides){
    cout << "here";
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
    //Creating War
    int size = 10;
    std::vector<Participants*> parties;
    parties.push_back(new AlliedPowers());
    parties.push_back(new CentralPowers());
    War * war = new War(new WorldMap(size), parties);
    Caretaker * STORAGE = new Caretaker(war->createSave());

    //Creating armies
    Factory * aFactory = new AlliedFactory();
    Factory * cFactory = new CentralFactory();
    for(int i = 0; i < 20; i++){
        Squad * temp = new Squad(war->getParticipants().at(0));
        for(int j = 0; j < 10; j++){
            temp->addMember(aFactory->createInfantry(war->getParticipants().at(0)));
        }
        for(int q = 0; q < 5; q++){
            temp->addMember(aFactory->createTank(war->getParticipants().at(0)));
        }
    }

    for(int i = 0; i < 20; i++){
        Squad * temp = new Squad(war->getParticipants().at(1));
        for(int j = 0; j < 10; j++){
            temp->addMember(cFactory->createInfantry(war->getParticipants().at(1)));
        }
        for(int q = 0; q < 5; q++){
            temp->addMember(cFactory->createTank(war->getParticipants().at(1)));
        }
    }

    // int counter = 0;
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 2; j++){
    //         //std::cout << counter++;
    //         //war->getWorld()->getCell(i, j)->setOccupyingForce(war->getParticipants().at(0)->getArmy().at(counter++));
    //     }
    // }

    // for(int i = 0; i < size; i++){
    //     for(int j = size - 2; j < size; j++){
    //         war->getWorld()->getCell(i, j)->setOccupyingForce(war->getParticipants().at(1)->getArmy().at(i));
    //     }
    // }

    int turn = 0;
    Participants * loser;

    cout << "Pink = Bog\nYellow = Flatlands\nPlain = Normal Cell\n";
    while(!(loser == findLoser(war->getParticipants()))){
        std::cout << "Participants " << turn % war->getParticipants().size() << " turn" << endl;
        war->getParticipants().at(turn % war->getParticipants().size())->armyMove();
        for(int i = 0; i < size; i++){
            std::cout << "[   ";
            for(int j = 0; j < size; j++){
                war->getWorld()->getCell(i, j)->printSymbol();
                cout << "   ";
            }
            std::cout << "]\n";
        }
        char ans;
        std::cout << "Would you like to continue in real mode? (Y/N)";
        std::cin >> ans;
        while(true){
            if(ans == 'Y'){
            turn++;
            system("clear");
            break;
            }
            else if(ans == 'N'){
                system("clear");
                break;
            }
            {
                std::cout << "Please enter a valid answer\n";
                std::cout << "Would you like to continue in real mode? (Y/N)";
                std::cin >> ans;
            }
        }
        
    }
    std::cout << loser->getName() << " has lost the war\n";


    return 0;
}