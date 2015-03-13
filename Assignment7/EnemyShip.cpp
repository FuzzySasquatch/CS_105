#include "EnemyShip.h"
#include <iostream>
#include <ncurses.h>
using std::cout;
using std::endl;

int EnemyShip::movements = 0;
int EnemyShip::moveDown = 0;
int EnemyShip::direction = -2;

EnemyShip::EnemyShip(int y, int x, int ch) : Ship(y, x, ch) {
	cout << "EnemyShip" << endl;
}

void EnemyShip::timeStep(int* ticks, EnemyShip* enemies[], int NUM_ENEMIES) {
	// mvprintw(12, 5, "Movements: %i   Direction: %i.\n", movements, direction);
	
	if (*ticks >= 20) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			enemies[i]->setX(direction);
		}
		*ticks = 0;
		movements++;
    }
    /// Horizonal movement
    if (movements / 7) {
		direction = - direction;
		moveDown+= movements;
		movements = 0;
	}
	/// Vertical movement
	if (moveDown == 14) {
		for (int i = 0; i < NUM_ENEMIES; ++i) {
			enemies[i]->setY(2);
		}
		moveDown = 0;
	}
	// cout << "timeStep" << endl;
}

// int PlayerShip::getX() const {
// 	return this->x;
// } 

// int PlayerShip::getY() const {
// 	return this->y;
// } 

// bool PlayerShip::isCollision(const GameObject& obj) const {
// 	if (1) {
// 		GameObject::removeObject(this);
// 	}
// }