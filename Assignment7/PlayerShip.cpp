#include "PlayerShip.h"
#include <iostream>
using std::cout;
using std::endl;

PlayerShip::PlayerShip(int y, int x, int ch) : Ship(y, x, ch) {
	cout << "PlayerShip" << endl;
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