#ifndef ENEMY_SHIP_0000433191238374
#define ENEMY_SHIP_0000433191238374

#include "Ship.h"
// #include "EnemyProjectile.h"


class EnemyShip : public Ship {
private:
	static int movements;
	static int direction;
	static int moveDown;
	static double uFireRate;
	static double WFireRate;
public:
	
	EnemyShip(int,int,int);
	static void timeStep(int*, EnemyShip*[], int);//, EnemyProjectile*[], int*); // logic when the time increments
	void fireProjectile() const {}
	
	// virtual void timeStep() = 0; // logic when the time increments
	// virtual char getShape() const = 0; // what is the shape of this object
	// virtual void setX(const int x); int getX() const; // getter and setter for the x value
	// virtual void setY(const int y); int getY() const; // getter and setter for the y value
	// bool isCollision(const GameObject& obj) const; // Does the object collide with another

	// GameObject() {}

	
};

#endif