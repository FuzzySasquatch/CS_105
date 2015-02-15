#ifndef __LINKED_LIST_CPP_9F4861BC
#define __LINKED_LIST_CPP_9F4861BC

/* your includes */
#include <iostream>

/* your class */
struct Node {
	int value;
	Node* next;

	Node(int v) : value(v), next(0) {}
};

class LinkedList {
public:
	LinkedList() : head(0), tail(0) {}
	virtual void push(int);
	virtual int pop();
	virtual void print();
	virtual int size();
	~LinkedList() {

	}
private:
	Node* head;
	Node* tail;
};

#endif