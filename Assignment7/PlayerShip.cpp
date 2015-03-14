#include "PlayerShip.h"
// #include "PlayerProjectile.h"
#include <iostream>
using std::cout;
using std::endl;

PlayerShip::PlayerShip(int y, int x, int ch) : Ship(y, x, ch) {
	cout << "PlayerShip" << endl;
}

void PlayerShip::fireProjectile() const {
// 	int y = this->getX();
// 	int x = this->getY() - 1;
// 	PlayerProjectile* proj = new PlayerProjectile(y, x, '|');
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