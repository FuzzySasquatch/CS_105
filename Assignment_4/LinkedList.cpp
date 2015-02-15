#include "LinkedList.h" /// include the header file for the linked list
using namespace std;
/* your class implementation*/
void LinkedList::push(int value) {
	/* At least one node has been placed */
	if (head && tail) {
		Node* newNode = new Node(value);
		/* For the second node, the value of tail is changed to the newest node.
		   Because head is also equal to the first node, head's next node is changed as well.
		   Afterwards, tail is set to newNode */
		tail->next = newNode;
		tail = newNode;
	}

	/* Creates the first node and sets head and tail equal to it */
	else {
		Node* firstNode = new Node(value);
		tail = firstNode;
		head = firstNode;
	}
}

int LinkedList::pop() {
	int value = 0;
	/* Creates a temporary node, moves head to the next node and deletes the temporary */
	if (head) {
		value = head->value; // pop value
		Node* pop = head;
		head = head->next;
		delete pop;
	}
	return value;
}

void LinkedList::print() {
	/* Iterates through each node printing the node's value */
	Node* current = head;
	while (current->next) {
		cout << current->value << " ";
		current = current->next;
	}
	/* Account for off by one 'space' */
	cout << current->value << endl;
	return;
}

int LinkedList::size() {
	int count = 0;
	/* Iterates through each node, tallying each node */
	Node* current = head;
	while (current->next) {
		current = current->next;
		count++;
	}
	return count;
}
