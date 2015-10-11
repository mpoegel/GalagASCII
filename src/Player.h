#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

class Player {
  public:
    const static int TICKS_PER_SHOT = 4;
    Player(const string &input, const pair<int,int> startLoc);
    Player(): name(""), location(make_pair(0,0)) {}

    string getName() const;
    pair<int,int> getLocation() const;
    bool pendingMove() const;

    char takeMove();
    void runPlayer();
    void setLocation(pair<int,int> &loc);
    void endPlayer();

    int cooldown;
  private:
    string name;
    pair<int,int> location;
    unsigned char input;
    bool madeMove;
    bool end;
};

#endif
