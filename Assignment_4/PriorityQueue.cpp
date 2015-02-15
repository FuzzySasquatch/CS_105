#include "PriorityQueue.h" /// include the header file for the priority queue

using namespace std;

/* your class implementation*/
void PriorityQueue::push(int value) {
	
	/* At least one node has been placed */

	if (LinkedList::head && tail) {
		// cout << "This node is "<< value << " ";

		Node* newNode = new Node(value);
		Node* current = head;
		Node* previous;

		/* The new value is less than or equal to the first node */
		if (value <= head->value) {
			// cout << "and it is less than or equal to the first." << endl;
			newNode->next = head;
			head = newNode;

		/* The new node is greater than at least the first node */
		} else {
			// cout << "and it is greater than at least the first. ";
			while (current->next && (value > current->value)) {
				previous = current;
				current = current->next;
			}

			/* The new node is greater than the last node */
			if (!current->next && value > current->value) {
				// cout << "This node is greater than the last node." << endl;
				tail->next = newNode;
				tail = newNode;

			/* The new node is less than or equal to the last node 
			   and greater than the first node */
			} else {
				// cout << "This node is less than or equal to the last node." << endl;
				newNode->next = current;
				previous->next = newNode;
			}
		}	

	/* Creates the first node and sets head and tail equal to it */	
	} else {
		Node* firstNode = new Node(value);
		// cout << "First node is " << value << endl;
		tail = firstNode;
		head = firstNode;
		// cout << tail << " " << head << endl;
	}
}

// int PriorityQueue::pop() {
// 	int value = head->value; // pop value
// 	Node* pop = head;
// 	head = head->next;
// 	delete pop;
// 	return value;
// }

int PriorityQueue::peek() {
	return head->value;
}

// void PriorityQueue::print() { 
// 	Node* current = head;
// 	// cout << "Current = " << current << endl;

// 	while (current->next) {
// 		cout << current->value << " ";
// 		current = current->next;
// 	}
// 	/* Account for off by one 'space' */
// 	cout << current->value << endl;
// 	return;
// }

// int PriorityQueue::size() {
// 	int size = LinkedList::size();
// 	return size;
// }
