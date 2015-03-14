#ifndef GAMEOBJECT_1223455111
#define GAMEOBJECT_1223455111

class GameObject {
protected:
	GameObject(int,int,int);
	int xPos;
	int yPos;
	int shape;
	virtual void timeStep() {} // logic when the time increments
public:
	char getShape() const; // what is the shape of this object
	void setX(const int); // getter and setter for the x value
	int getX() const;
	void setY(const int); // getter and setter for the y value
	int getY() const; 	
};

#endif