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

/// Player projectile collisions
bool EnemyShip::isCollision(EnemyShip* enemies[], int NUM_ENEMIES, PlayerProjectile* p, int* score, bool* deleteP) {
	int y; 
	int x;
	int pY = p->getY();
	int pX = p->getX();
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		if (enemies[i]) {
			y = enemies[i]->getY();
			x = enemies[i]->getX();
			if (p) {
				/// Checks for collisions with player
				if (y == pY && x == pX) {
					mvaddch(y,x,'*'); // Prints explosion
					*score += 1;
					delete enemies[i];
					*deleteP = true;
					enemies[i] = 0;
				}
			}
		}
	}
	return false;
}

/// Reached bottom collisions
bool EnemyShip::isCollision(EnemyShip* enemies[], PlayerShip* player, int NUM_ENEMIES) {
	int y; 
	int x;
	int playerY = player->getY();
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		if (enemies[i]) {
			y = enemies[i]->getY();
			x = enemies[i]->getX();
			/// Tests for collisions with the player or below the player
			if ((y == playerY && x == player->getX()) || y > playerY) {
				mvaddch(y,x,'*'); // Prints explosion
				return true;
			}
		}
	}
	return false;
}

void EnemyShip::timeStep(int* ticks, EnemyShip* enemies[], int NUM_ENEMIES, EnemyProjectile* projectiles[], int* index) {
	/// Seeds random number generator
	srand (time(NULL));
	int random = rand() % 1000;

	/// Creates new projectiles with a 1% change for 'W' and a 0.5% chance for 'u'
	if (*ticks >= movementSpeed) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			if (enemies[i]) {
				random = rand() % 1000;
				char shape = enemies[i]->getShape();
				if (shape == 'u' && random <= uFireRate) {
					/// Makes a beep sound
					std::cout << '\a';
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				} else if (shape == 'W' && random <= WFireRate) {
					/// Makes a beep sound
					std::cout << '\a';
					projectiles[*index] = new EnemyProjectile(enemies[i]->getY()+1, enemies[i]->getX(), '|');
					*index += 1;
				}
			}
		}
	}

	/// Increase difficulty as time progresses
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