#include "EnemyProjectile.h"
#include <iostream>
#include <ncurses.h>
using std::cout;
using std::endl;

EnemyProjectile::EnemyProjectile(int y, int x, int ch) : Projectile(y, x, ch) {}

void EnemyProjectile::timeStep(EnemyProjectile* projectiles[], int NUM_PROJECTILES) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(1);
		}
	}
}