#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>
#include <utility>

using namespace std;


class Enemy {
    public:
    const static int ENEMY_TICKS_PER_MOVE = 8;

    Enemy(const char input, const pair<int,int> &startLoc);
    char getType() const;
    pair<int,int> getLocation() const;
    void move();

    private:
    char type;
    pair<int,int> location;
    int movesMade;
    int ticksTillNextMove;
};

#endif
