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
		// std::cout << "Deconstructor" << std::endl;
		while (head->next) {
			Node* garbage = head;
			head = head->next;
			delete garbage;
		}
		delete head;
	}
	void push(int);
	int pop();
	void print();
	int size();
private:
	Node* head;
	Node* tail;
};

#endif