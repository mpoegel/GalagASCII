#include "Enemy.h"
#include <iostream>
#include <utility>

Enemy :: Enemy(const char input, const pair<int,int> &startLoc){
  type = input;
  location = startLoc;
  movesMade = 0;
}
char Enemy :: getType() const{
  return type;
}
pair<int,int> Enemy :: getLocation() const{
  return location;
}
pair<int,int> Enemy :: move(){
  if(movesMade < 2){
    location.first = location.first-1;
  }
  else{
    location.first = location.first+1;
  }
  movesMade++;
  if(movesMade == 4){
    movesMade = 0;
  }
  return location;
}
