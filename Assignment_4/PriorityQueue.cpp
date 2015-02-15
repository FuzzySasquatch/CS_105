#include "PriorityQueue.h" /// include the header file for the priority queue


/* your class implementation*/
void PriorityQueue::push(int value) {
	// LinkedList::push(value);


	if (head && tail) {
		/* For the second node, the value of tail is changed to the newest node.
		   Because head is also equal to the first node, head's next node is changed as well.
		   Afterwards, tail is set to newNode */

		Node* newNode = new Node(value);
		Node* current = head;

		while (current->next) {
			current->value;
		}

		tail->next = newNode;
		tail = newNode;
	}


	else {
		/* Creates the first node and sets head and tail equal to it */
		Node* firstNode = new Node(value);
		tail = firstNode;
		head = firstNode;
	}
}

int PriorityQueue::pop() {
	int value = LinkedList::pop();
	return value;
}

int PriorityQueue::peek() {
	return head->value;
}

void PriorityQueue::print() {
	LinkedList::print();
}

int PriorityQueue::size() {
	int size = LinkedList::size();
	return size;
}
