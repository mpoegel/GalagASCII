#include "Player.h"
#include <utility>
#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;

Player :: Player(const string &input){
  name = input;
  madeMove = false;
}

string Player :: getName() const{
  return name;
}

pair<int,int> Player :: getLocation() const{
  return location;
}

unsigned char Player :: getInput() const{
  return input;
}

bool Player :: moveMade() const{
  return madeMove;
}

void Player :: takeMove(){
  madeMove = false;
}

void Player :: setLocation(pair<int,int> &loc){
  location = loc;
}

void Player :: runPlayer(){
  struct termios old_tio, new_tio;
  unsigned char c;

  /* get the terminal settings for stdin */
  tcgetattr(STDIN_FILENO,&old_tio);

  /* we want to keep the old setting to restore them a the end */
  new_tio=old_tio;

  /* disable canonical mode (buffered i/o) and local echo */
  new_tio.c_lflag &=(~ICANON & ~ECHO);

  /* set the new settings immediately */
  tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

  for(int i = 0; i < 10; i++){
    input=getchar();
    madeMove = true;
    cout << input << endl;
  }
  /* restore the former settings */
  tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}
