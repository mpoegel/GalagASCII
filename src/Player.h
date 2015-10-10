#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

class Player{
  public:
     Player(const string &input);
     string getName() const;
     pair<int,int> getLocation() const;
     bool pendingMove() const;

     char takeMove();
     void runPlayer();
     void setLocation(pair<int,int> &loc);

  private:
    string name;
    pair<int,int> location;
    unsigned char input;
    bool madeMove;

};

#endif
