#include "Enemy.h"
#include <iostream>
#include <utility>

Enemy :: Enemy(const char input, const pair<int,int> &startLoc) {
    type = input;
    location = startLoc;
    movesMade = 0;
    ticksTillNextMove = 0;
}
char Enemy :: getType() const {
    return type;
}
pair<int,int> Enemy :: getLocation() const {
    return location;
}
void Enemy :: move() {
    if(ticksTillNextMove > 0) {
        ticksTillNextMove--;
    } else {
        if(movesMade < 5) {
            location.first = location.first-1;
        }
        else {
            location.first = location.first+1;
        }
        movesMade++;
        if(movesMade == 10) {
            movesMade = 0;
        }
        ticksTillNextMove = ENEMY_TICKS_PER_MOVE;
    }
}
