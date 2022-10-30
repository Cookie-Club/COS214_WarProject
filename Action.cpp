//
// Created by kaisoo on 2022/10/23.
//

#include "Action.h"

Action::Action(ActionType aT){
    type = aT;
}

ActionType Action::getType(){
    return type;
}