#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <map>
#include <signal.h>
#include "Controller.h"

using namespace std;

void handle_control_c(int s) {
    Screen::fullCleanup();
    exit(0);
}

int main() {
    signal(SIGINT, &handle_control_c);
    Controller c;
    c.run();
    c.endThreads();
    
    cout << endl;
    return 0;
}
