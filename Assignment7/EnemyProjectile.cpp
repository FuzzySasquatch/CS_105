#include "EnemyProjectile.h"


EnemyProjectile::EnemyProjectile(int y, int x, int ch) : GameObject(y, x, ch) {}


void EnemyProjectile::timeStep(EnemyProjectile* projectiles[], int NUM_PROJECTILES, int ticks) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(1);
		}
	}
}