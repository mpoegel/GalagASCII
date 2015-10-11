#include "Controller.h"

Controller::Controller() {
    screen_ = Screen(20, 200);
    enemies_ = list<Enemy>();
    projectiles_ = list<Projectile>();
    player_ = Player("name", make_pair(50, 20));

    string buffer;
    // initial enemies
    for (unsigned int x=0; x<10; x++) {
        for (unsigned int y=1; y<4; y++) {
            Enemy enemy('A', make_pair(x*2 + 50, y));
            screen_.updateOne(buffer, enemy.getLocation(), "red", enemy.getType());
            enemies_.push_back(enemy);
        }
    }
    screen_.setCursorVisible(false);
    screen_.clearFull();

    // draw initial position of player
    screen_.updateOne(buffer, player_.getLocation(), "green", '^');
    cout << buffer;
    cout.flush();

    p_thread_ = thread(&Controller::runPlayer, ref(*this));
}

void Controller::run() {
    unsigned int i=0;
    while (true) {
        // if (i > 20) break;
        // loop over projectiles
        string buffer;
        for (list<Projectile>::iterator p_itr = projectiles_.begin(); p_itr != projectiles_.end(); p_itr++) {
          screen_.updateOne(buffer, p_itr->getLocation(), "white", ' ');
          p_itr->move();
          location loc = p_itr->getLocation();
          bool hit = false;
          for (list<Enemy>::iterator e_itr = enemies_.begin(); e_itr != enemies_.end(); e_itr++) {
              location e_loc = e_itr->getLocation();
              if(loc.first == e_loc.first && loc.second == e_loc.second){
                  hit = true;
                  screen_.updateOne(buffer,loc, "white", ' ');
                  e_itr = enemies_.erase(e_itr)--;
              }
          }
          if (loc.second >= 0 && loc.second < screen_.height + 1 && !hit) {
              screen_.updateOne(buffer, p_itr->getLocation(), "white", '*');
          }
          else {
              p_itr = projectiles_.erase(p_itr)--;
          }
        }

        if(enemies_.empty()) {
            Screen::fullCleanup();
            puts("You win!");
            exit(0);
        }

        // loop over enemies for moves
        for (list<Enemy>::iterator e_itr = enemies_.begin(); e_itr != enemies_.end(); e_itr++) {
            screen_.updateOne(buffer, e_itr->getLocation(), "red", ' ');
            e_itr->move();
            bool hit = false;
            location e_location = e_itr->getLocation();
            if (e_location.second > screen_.height) {
                e_itr->stopAttack();
                e_location = e_itr->getLocation();
            }
            list<Projectile>::iterator p_itr = projectiles_.begin();
            while(!hit && p_itr != projectiles_.end()) {
                location p_location = p_itr->getLocation();
                if(p_location.first == e_location.first && p_location.second == e_location.second) {
                    hit = true;
                    screen_.updateOne(buffer, p_location, "white", ' ');
                    projectiles_.erase(p_itr);
                    e_itr = enemies_.erase(e_itr)--;
                }
                else {
                    p_itr++;
                }
            }
            if(!hit) {
                screen_.updateOne(buffer, e_location, "red", e_itr->getType());
            }
        }
        if(player_.cooldown > 0) {
            player_.cooldown--;
        }
        if (player_.pendingMove()) {
            location loc = player_.getLocation();
            char move = player_.takeMove();
            if (move == 'w') {
                loc.second--;
                if(player_.cooldown == 0) {
                    projectiles_.push_back( Projectile(false, loc) );
                    player_.cooldown = Player::TICKS_PER_SHOT;
                }
            }
            else {
                screen_.updateOne(buffer, loc, "green", ' ');
                screen_.updateOne(buffer, player_.getLocation(), "green", '^');
            }
        }
        cout << buffer;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
        i++;

    }
    player_.endPlayer();
}

void Controller::runPlayer(Controller& c) {
  c.player_.runPlayer();
}

void Controller::endThreads() {
    p_thread_.join();
}
