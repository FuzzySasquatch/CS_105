#include "LinkedList.h" /// include the header file for the linked list
using namespace std;
/* your class implementation*/
void LinkedList::push(int value) {
	// If at least one node has been placed
	if (head && tail) {
		cout << "At least one node." << endl;

		Node* newNode = new Node(value);
		/* For the second node, the value of tail is changed to the newest node.
		   Because head is also equal to the first node, head's next node is changed as well.
		   Afterwards, tail is set to newNode */
		tail->next = newNode;
		tail = newNode;
	}
	else {
		cout << "Adding first node." << endl;
		/* Creates the first node and sets head and tail equal to it */
		Node* firstNode = new Node(value);
		tail = firstNode;
		head = firstNode;
	}
}

int LinkedList::pop() {

	return 1;
}

void LinkedList::print() {
	std::cout << "Value at node = " << head->next->value << std::endl;
}

int LinkedList::size() {
	return 1;
}
