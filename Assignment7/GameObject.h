#ifndef GAMEOBJECT_1223455111
#define GAMEOBJECT_1223455111

class GameObject {
protected:
	int xPos;
	int yPos;
	int shape;

	GameObject(int,int,int);

	virtual void timeStep() {} // logic when the time increments

public:
	char getShape() const; // what is the shape of this object
	virtual void setX(const int); 
	int getX() const; // getter and setter for the x value
	virtual void setY(const int); 
	int getY() const; // getter and setter for the y value	
};

#endif