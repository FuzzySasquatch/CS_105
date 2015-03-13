#ifndef SHIP_0494993111
#define SHIP_0494993111

#include "GameObject.h"

class Ship : public GameObject {
protected:
	Ship(int,int,int);
	virtual void timeStep();
	// virtual void timeStep() = 0; // logic when the time increments
	// virtual char getShape() const = 0; // what is the shape of this object
	// virtual void setX(const int x); 
	// virtual int getX() const = 0; // getter and setter for the x value
	// virtual void setY(const int y); int getY() const; // getter and setter for the y value
	// virtual bool isCollision(const GameObject& obj) const; // Does the object collide with another
	
	// GameObject() {}

	
};

#endif