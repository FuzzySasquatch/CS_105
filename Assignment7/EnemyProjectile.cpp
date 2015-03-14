#include "EnemyProjectile.h"
#include <ncurses.h>


EnemyProjectile::EnemyProjectile(int y, int x, int ch) : GameObject(y, x, ch) {}


bool EnemyProjectile::isCollision(EnemyProjectile* projectiles[], PlayerShip* player, int NUM_PROJECTILES) {
	int y; 
	int x;
	int playerY = player->getY();
	volatile int playerX = player->getX();
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			y = projectiles[i]->getY();
			x = projectiles[i]->getX();
			/// Projectile hit player
			if (y == playerY && x == (playerX = player->getX())) {
				mvaddch(y-1,x,'*'); /// Prints explosion
				return true;
			/// Projectile off screen
			} else if (y > playerY) {
				mvaddch(y-1,x,'*'); // Prints explosion
				delete projectiles[i];
				projectiles[i] = 0;
			}
		}
	}
	return false;
}

/// Move projectiles downwards
void EnemyProjectile::timeStep(EnemyProjectile* projectiles[], int NUM_PROJECTILES, int ticks) {
	for (int i = 0; i < NUM_PROJECTILES; ++i) {
		if (projectiles[i]) {
			projectiles[i]->setY(1);
		}
	}
}