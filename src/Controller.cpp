#include "Controller.h"

Controller::Controller() {
    screen_ = Screen(40, 200);
    enemies_ = list<Enemy>();
    projectiles_ = list<Projectile>();
    player_ = Player("name", make_pair(50, 40));

    // initial enemies
    for (unsigned int x=0; x<10; x++) {
        for (unsigned int y=0; y<3; y++) {
            Enemy enemy('A', make_pair(x*2 + 50, y));
            screen_.updateOne(enemy.getLocation(), "red", enemy.getType());
            enemies_.push_back(enemy);
        }
    }
    screen_.setCursorVisible(false);
    screen_.clearFull();

    // draw initial position of player
    screen_.updateOne(player_.getLocation(), "green", '^');

    p_thread_ = thread(&Controller::runPlayer, ref(*this));
}

void Controller::run() {
    unsigned int i=0;
    while (true) {
        // if (i > 20) break;
        // loop over projectiles
        for (list<Projectile>::iterator p_itr = projectiles_.begin(); p_itr != projectiles_.end(); p_itr++) {
            screen_.updateOne(p_itr->getLocation(), "white", ' ');
            p_itr->move();
            location loc = p_itr->getLocation();
            if (loc.second > 0 && loc.second < screen_.height + 1) {
                screen_.updateOne(p_itr->getLocation(), "white", '*');
            }
            else {
                p_itr = projectiles_.erase(p_itr)--;
            }
        }
        // loop over enemies for moves
        for (list<Enemy>::iterator e_itr = enemies_.begin(); e_itr != enemies_.end(); e_itr++) {
            screen_.updateOne(e_itr->getLocation(), "red", ' ');
            e_itr->move();
            bool hit = false;
            location e_location = e_itr->getLocation();
            list<Projectile>::iterator p_itr = projectiles_.begin();
            while(!hit && p_itr != projectiles_.end()){
                location p_location = p_itr->getLocation();
                if(p_location.first == e_location.first && p_location.second == e_location.second){
                    hit = true;
                    screen_.updateOne(p_location, "white", ' ');
                    projectiles_.erase(p_itr);
                    e_itr = enemies_.erase(e_itr)--;
                }
                else{
                    p_itr++;
                }
            }
            if(!hit){
                screen_.updateOne(e_location, "red", e_itr->getType());
            }
        }
        if (player_.pendingMove()) {
            location loc = player_.getLocation();
            char move = player_.takeMove();
            if (move == 'w') {
                loc.second--;
                projectiles_.push_back( Projectile(false, loc) );
            }
            else {
                screen_.updateOne(loc, "green", ' ');
                screen_.updateOne(player_.getLocation(), "green", '^');
            }
        }
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
        i++;

    }
    player_.endPlayer();
}

void Controller::watchPlayer(Controller& c) {
    while (true) {
        if (c.player_.pendingMove()) {
            location loc = c.player_.getLocation();
            char move = c.player_.takeMove();
            if (move == 'w') {
                loc.second--;
                c.projectiles_.push_back( Projectile(true, c.player_.getLocation()) );
            }
            else {
                c.screen_.updateOne(loc, "green", ' ');
                c.screen_.updateOne(c.player_.getLocation(), "green", '^');
            }
        }
      }
}

void Controller::runPlayer(Controller& c) {
  c.player_.runPlayer();
}

void Controller::endThreads() {
    p_thread_.join();
}
