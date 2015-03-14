#ifndef PLAYER_SHIP_0448482727224
#define PLAYER_SHIP_0448482727224

#include "Ship.h"


class PlayerShip : public Ship {
private:

public:
	PlayerShip(int,int,int);
	void timeStep() {} // logic when the time increments
	void fireProjectile() const;
	// virtual void timeStep() = 0; // logic when the time increments
	// virtual char getShape() const = 0; // what is the shape of this object
	// virtual void setX(const int x); int getX() const; // getter and setter for the x value
	// virtual void setY(const int y); int getY() const; // getter and setter for the y value
	// bool isCollision(const GameObject& obj) const; // Does the object collide with another

	// GameObject() {}

	
};

#endif