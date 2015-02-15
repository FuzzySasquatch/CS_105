#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class
/* your includes */

/* your class */
class PriorityQueue : public LinkedList {
public:
	void push(int);
	int pop();
	int peek();
	void print();
	int size();
// private:
// 	Node* head;
// 	Node* tail;
};

#endif