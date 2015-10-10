#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>
#include <utility>

using namespace std;

class Enemy{
  public:
     Enemy(const char input, const pair<int,int> &startLoc);
     char getType() const;
     pair<int,int> getLocation() const;
     pair<int,int> move();

  private:
    char type;
    pair<int,int> location;
    int movesMade;
};

#endif
