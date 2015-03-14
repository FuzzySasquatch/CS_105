#ifndef GAMEOBJECT_1223455111
#define GAMEOBJECT_1223455111

#include <iostream>
using namespace std;


class GameObject {
protected:
	int xPos;
	int yPos;
	int shape;

	GameObject(int,int,int);

	virtual void timeStep() {} // logic when the time increments

	typedef void (*enqueueFunc)(GameObject*);
	typedef void (*dequeueFunc)(GameObject*);
public:
	GameObject() {}
	
	static enqueueFunc myEnqueue;
	static dequeueFunc myDequeue;

	static void addObject(GameObject* obj) {
		myEnqueue(obj);
	}
	static void removeObject(GameObject* obj) {
		myDequeue(obj);
	}

	
	char getShape() const; // what is the shape of this object
	virtual void setX(const int); 
	int getX() const; // getter and setter for the x value
	virtual void setY(const int); 
	int getY() const; // getter and setter for the y value
	// virtual bool isCollision(const GameObject& obj) const = 0; // Does the object collide with another

	// GameObject() {}

	
};

#endif