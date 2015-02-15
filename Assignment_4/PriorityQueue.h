#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class
/* your includes */

/* your class */
class PriorityQueue : public LinkedList {
public:
	// PriorityQueue() : head(0), tail(0) {}
	// ~PriorityQueue() {
	// 	std::cout << "Deconstructor queue" << std::endl;
	// 	while (head->next) {
	// 		Node* garbage = head;
	// 		head = head->next;
	// 		delete garbage;
	// 	}
	// 	delete head;
	// }
	void push(int);
	// int pop();
	int peek();
	// void print();
	// int size();
// private:
// 	Node* head;
// 	Node* tail;
};

#endif