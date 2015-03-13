#include "GameObject.h"

GameObject::enqueueFunc GameObject::myEnqueue = 0;
GameObject::dequeueFunc GameObject::myDequeue = 0;

GameObject::GameObject(int y, int x, int ch) : yPos(y), xPos(x), shape(ch) {
		// cout << "GameObject" << endl;
}

int GameObject::getX() const {
	return this->xPos;
} 

int GameObject::getY() const {
	return this->yPos;
} 

char GameObject::getShape() const {
	return this->shape;
} 

void GameObject::setX(const int x) {
	this->xPos += x;
} 

void GameObject::setY(const int y) {
	this->yPos += y;
} 