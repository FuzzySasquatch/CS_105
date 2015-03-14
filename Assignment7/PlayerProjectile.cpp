#include "PlayerProjectile.h"
#include <iostream>
#include <ncurses.h>
using std::cout;
using std::endl;

PlayerProjectile::PlayerProjectile(int y, int x, int ch) : GameObject(y, x, ch) {}

void PlayerProjectile::timeStep(PlayerProjectile* projectiles[], int NUM_PROJECTILES) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(-1);
		}
	}
}