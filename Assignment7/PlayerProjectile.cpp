#include "PlayerProjectile.h"
#include <ncurses.h>

PlayerProjectile::PlayerProjectile(int y, int x, int ch) : GameObject(y, x, ch) {}

void PlayerProjectile::isCollision(PlayerProjectile* projectiles[], int NUM_PROJECTILES) {
	int y; 
	int x;

	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			y = projectiles[i]->getY();
			x = projectiles[i]->getX();
			if (y < 0) {
				delete projectiles[i];
				projectiles[i] = 0;
			}
		}
	}
}

void PlayerProjectile::timeStep(PlayerProjectile* projectiles[], int NUM_PROJECTILES) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(-1);
		}
	}
}