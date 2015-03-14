#include "EnemyShip.h"
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
using std::cout;
using std::endl;

int EnemyShip::movements = 0;
int EnemyShip::moveDown = 0;
int EnemyShip::direction = -2;
// double EnemyShip::uFireRate = 0.75;
// double EnemyShip::WFireRate = 1.5;

EnemyShip::EnemyShip(int y, int x, int ch) : Ship(y, x, ch) {
	// cout << "EnemyShip" << endl;
}

void EnemyShip::timeStep(int* ticks, EnemyShip* enemies[], int NUM_ENEMIES) {//, EnemyProjectile* projectiles[], int* index) {
	/// Generate a random double
	srand (time(NULL));
	for (int i = 0; i < NUM_ENEMIES; ++i) {
			double random = (double)rand() / RAND_MAX;
			random = random * (100 - 0);
			// if (enemies[i]) {
			// 	EnemyShip* enemy = enemies[i];

			// 	char shape = enemy->getShape();
			// 	bool uFiring = shape == 'u' && random <= uFireRate;
			// 	bool WFiring = shape == 'W' && random <= WFireRate;

			// 	if (uFiring || WFiring) 
			// 	{
			// 		// projectiles[*index] = new EnemyProjectile(enemy->getY(), enemy->getX(), '|');
			// 		// *index++;
			// 		mvprintw(15, 1, "u or W firing");
			// 	} 
			// }
	}

	/// Count 20 ticks and move enemies horizontally
	if (*ticks >= 20) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				enemies[i]->setX(direction);
			}
		}
		*ticks = 0;
		movements++;
    }
    /// Change horizontal direction
    if (movements / 7) {
		direction = - direction;
		moveDown+= movements;
		movements = 0;
	}
	/// Vertical movement
	if (moveDown == 14) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				enemies[i]->setY(2);
			}
		}
		moveDown = 0;
	}
	// cout << "timeStep" << endl;
}