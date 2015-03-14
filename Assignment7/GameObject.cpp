#include "GameObject.h"

GameObject::GameObject(int y, int x, int ch) : yPos(y), xPos(x), shape(ch) {}

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