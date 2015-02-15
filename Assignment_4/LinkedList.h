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
	~LinkedList() {
		while (head && head->next) {
			Node* garbage = head;
			head = head->next;
			delete garbage;
		}
		if (head) delete head;
	}
	virtual void push(int);
	int pop();
	void print();
	int size();
/* Dervived classes have access to protected variables */
protected:
	Node* head;
	Node* tail;
};

#endif