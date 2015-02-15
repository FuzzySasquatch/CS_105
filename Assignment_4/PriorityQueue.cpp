#include "PriorityQueue.h" /// include the header file for the priority queue
using namespace std;

/* your class implementation*/
void PriorityQueue::push(int value) {
	/* At least one node has been placed */
	if (head && tail) {
		Node* newNode = new Node(value);
		Node* current = head;
		Node* previous;

		/* The new value is less than or equal to the first node */
		if (value <= peek()) {

			newNode->next = head;
			head = newNode;

		/* The new node is greater than at least the first node */
		} else {
			while (current->next && (value > current->value)) {
				previous = current;
				current = current->next;
			}

			/* The new node is greater than the last node */
			if (!current->next && value > current->value) {
				tail->next = newNode;
				tail = newNode;

			/* The new node is less than or equal to the last node 
			   and greater than the first node */
			} else {
				newNode->next = current;
				previous->next = newNode;
			}
		}	

	/* Creates the first node and sets head and tail equal to it */	
	} else {
		Node* firstNode = new Node(value);
		tail = firstNode;
		head = firstNode;
	}
}

/* Returns head's value */
int PriorityQueue::peek() {
	return head->value;
}
