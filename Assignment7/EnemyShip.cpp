#include "EnemyShip.h"
#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

int EnemyShip::movements = 0;
int EnemyShip::moveDown = 0;
int EnemyShip::direction = -2;
int EnemyShip::movementSpeed = 20;
int EnemyShip::totalMovements = 0;

int EnemyShip::uFireRate = 50;
int EnemyShip::WFireRate = 100;

EnemyShip::EnemyShip(int y, int x, int ch) : GameObject(y, x, ch) {}

bool EnemyShip::isCollision(EnemyShip* enemies[], PlayerShip* player, int NUM_ENEMIES, PlayerProjectile* p, int* score, bool* deleteP) {
	int y; 
	int x;
	int pY = p->getY();
	int pX = p->getX();
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		if (enemies[i]) {
			y = enemies[i]->getY();
			x = enemies[i]->getX();
			if ((y == player->getY() && x == player->getX()) || y >= 22) {
				return true;
			}
			if (y >= 22) {
				return true;
			}
			if (p) {
				if (y == pY && x == pX) {
					mvaddch(y,x,'*');
					*score += 1;
					delete enemies[i];
					*deleteP = true;
					// delete p;
					// if (p)
						// delete p;
					enemies[i] = 0;
					// p = 0;
				}
			}
		}
	}
	return false;
}

void EnemyShip::timeStep(int* ticks, EnemyShip* enemies[], int NUM_ENEMIES, EnemyProjectile* projectiles[], int* index) {
	/// Seeds random number generator
	srand (time(NULL));
	int random = rand() % 1000;

	if (*ticks >= movementSpeed) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				random = rand() % 1000;
				char shape = enemies[i]->getShape();
				if (shape == 'u' && random <= uFireRate) {
					std::cout << '\a';
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				} else if (shape == 'W' && random <= WFireRate) {
					std::cout << '\a';
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				}
			}
		}
	}

	// mvprintw(2, 0, "%i\n", totalMovements);

	/// Increase difficulty
	if (totalMovements >= 40) {
		movementSpeed = 10;
	}
	if (totalMovements >= 80) {
		movementSpeed = 5;
	}

	/// Count 20 ticks and move enemies horizontally
	if (*ticks >= movementSpeed) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				enemies[i]->setX(direction);
			}
		}
		*ticks = 0;
		movements++;
		totalMovements++;
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