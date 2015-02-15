#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class

/* your class */
class PriorityQueue : public LinkedList {
public:
	void push(int);
	int peek();
};

#endif