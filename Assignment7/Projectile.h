#ifndef PROJECTILE_581924911123415
#define PROJECTILE_581924911123415

#include "GameObject.h"

class Projectile : public GameObject {
protected:
	Projectile(int,int,int);
	virtual void timeStep();
	// virtual void fireLaser() const = 0;
	// virtual void timeStep() = 0; // logic when the time increments
	// virtual char getShape() const = 0; // what is the shape of this object
	// virtual void setX(const int x); 
	// virtual int getX() const = 0; // getter and setter for the x value
	// virtual void setY(const int y); int getY() const; // getter and setter for the y value
	// virtual bool isCollision(const GameObject& obj) const; // Does the object collide with another
	
	// GameObject() {}

	
};

#endif