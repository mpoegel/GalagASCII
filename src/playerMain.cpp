#include "Player.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <functional>
#include <unistd.h>
#include <termios.h>

using namespace std;

void runPlayer(Player &p){
  p.runPlayer();
}

void hasPlayed(Player &p){
  while(true){
    if(p.pendingMove()){
      cout << "Move Made" << endl;
      return;
    }
  }
}

int main(int argc, char* argv[]) {
  Player player("name");
  int numThreads = 2;
  thread t1(runPlayer, ref(player));
  thread t2(hasPlayed, ref(player));
  t1.join();
  t2.join();
  return 0;
}
