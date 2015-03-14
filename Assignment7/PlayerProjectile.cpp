#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile(int y, int x, int ch) : GameObject(y, x, ch) {}

void PlayerProjectile::isCollision(PlayerProjectile* projectiles[], int NUM_PROJECTILES) {
	int y; 
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			y = projectiles[i]->getY();
			if (y < 0) {
				if (projectiles[i]) {
					delete projectiles[i];
					projectiles[i] = 0;
				}
			}
		}
	}
}

/// Move projectile upwards
void PlayerProjectile::timeStep(PlayerProjectile* projectiles[], int NUM_PROJECTILES) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(-1);
		}
	}
}