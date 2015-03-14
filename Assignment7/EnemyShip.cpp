#include "EnemyShip.h"
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
using std::cout;
using std::endl;

int EnemyShip::movements = 0;
int EnemyShip::moveDown = 0;
int EnemyShip::direction = -2;
int EnemyShip::uFireRate = 50;
int EnemyShip::WFireRate = 100;
int EnemyShip::enemiesLeft = 0;

EnemyShip::EnemyShip(int y, int x, int ch) : GameObject(y, x, ch) {}

void EnemyShip::timeStep(int* ticks, EnemyShip* enemies[], int NUM_ENEMIES, EnemyProjectile* projectiles[], int* index) {
	/// Seeds random number generator
	srand (time(NULL));
	int random = rand() % 1000;

	if (*ticks >= 20) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				random = rand() % 1000;
				char shape = enemies[i]->getShape();
				if (shape == 'u' && random <= uFireRate) {
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				} else if (shape == 'W' && random <= WFireRate) {
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				}
			}
		}
	}
	mvprintw(15, 1, "index is %i", *index);

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
}