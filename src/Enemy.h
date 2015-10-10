#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;


class Enemy {
    public:
    const static int ENEMY_TICKS_PER_MOVE = 8;
    const static int MAX_LATERAL_MOVE = 10;

    Enemy(const char input, const pair<int,int> &startLoc);
    char getType() const;
    void setLocation(pair<int,int>);
    pair<int,int> getLocation() const;
    void move();
    void attack();
    void stopAttack();

    private:
    char type;
    pair<int,int> starting_loc;
    pair<int,int> location;
    int movesMade;
    int ticksTillNextMove;
    bool inAttack;
};

#endif
