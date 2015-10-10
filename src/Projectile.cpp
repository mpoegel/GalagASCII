#include "Projectile.h"
#include <iostream>
#include <utility>

Projectile::Projectile(const bool dir, const pair<int,int> &startLoc) {
    direction = dir;
    location = startLoc;
}
bool Projectile::up() const {
    return direction;
}
pair<int,int> Projectile::getLocation() const {
    return location;
}
pair<int,int> Projectile::move() {
    if(direction) {
        location.second += 1;
    }
    else {
        location.second -= 1;
    }
    return location;
}
