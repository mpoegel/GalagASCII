#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <map>

#include "controller.h"

using namespace std;

int main() {
	
	Controller c;
	c.run();
	c.endThreads();
	
	// Screen s(10,300);
	// Screen::graphic g;
	// for	(unsigned int i=0; i<10; i++) {
	// 	g.push_back( vector<pair<string, char> >(300, make_pair("white", ' ')) );
	// }
	
	// s.updateAll(g);
	
	// for (unsigned int i=0; i<10; i++) {
	// 	s.updateOne(make_pair(i, i*2), "green", 'A');
	// 	cout.flush();
	// 	this_thread::sleep_for(chrono::milliseconds(100));
	// 	s.updateOne(make_pair(i, i*2), "white", ' ');		
	// }
	
	cout << endl;
	return 0;
}