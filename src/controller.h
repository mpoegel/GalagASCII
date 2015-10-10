#include <list>
#include <thread>
#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include <functional>
#include "enemy.h"
#include "projectile.h"
#include "player.h"
#include "screen.h"

using namespace std;

class Controller {
public:
	typedef pair<unsigned int, unsigned int> location;
	
	Controller();
	void run();
	
	void endThreads();

private:
	// REPRESENTATION
	Screen screen_;
	Player player_;
	thread p_thread_;
	thread wp_thread_;
	list<Enemy> enemies_;
	list<Projectile> projectiles_;
	
	// HELPERS
	static void runPlayer(Controller& c);
	static void watchPlayer(Controller& c);
};