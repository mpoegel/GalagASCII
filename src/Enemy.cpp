#include "Enemy.h"

Enemy :: Enemy(const char input, const pair<int,int> &startLoc) {
    type = input;
    location = startLoc;
    starting_loc = startLoc;
    movesMade = 0;
    inAttack = false;
    ticksTillNextMove = 0;
}
char Enemy :: getType() const {
    return type;
}
pair<int,int> Enemy :: getLocation() const {
    return location;
}
void Enemy :: move() {
    if (ticksTillNextMove > 0) {
        ticksTillNextMove--;
    } else {
        if (inAttack) {
          attack();
        }
        else {
            if (rand() % 100 == 10) {
                inAttack = true;
            }
            if (movesMade < MAX_LATERAL_MOVE / 2) {
                location.first = location.first-1;
            }
            else {
                location.first = location.first+1;
            }
            movesMade++;
            if (movesMade == MAX_LATERAL_MOVE) {
                movesMade = 0;
            }
        }
        ticksTillNextMove = ENEMY_TICKS_PER_MOVE;
    }
}

void Enemy :: setLocation(pair<int, int> loc) {
  location = loc;
}

void Enemy :: attack() {
  location.second++;
}

void Enemy :: stopAttack() {
  inAttack = false;
  location = starting_loc;
}
