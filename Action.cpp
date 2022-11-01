//
// Created by kaisoo on 2022/10/23.
//

#include "Action.h"

Action::Action(){}

ActionType Action::getType(){
    return type;
}

void Action::setType(ActionType aT){
    type = aT;
}