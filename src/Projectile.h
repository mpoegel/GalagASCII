#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include <string>
#include <utility>

using namespace std;

class Projectile{
  public:
     Projectile(const bool dir,const pair<int,int> &startLoc);
     bool up() const;
     pair<int,int> getLocation() const;
     pair<int,int> move();

  private:
    bool direction;
    pair<int,int> location;
};

#endif
