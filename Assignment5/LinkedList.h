#ifndef __LINKED_LIST_CPP_9F4861BC
#define __LINKED_LIST_CPP_9F4861BC

/* your includes */
#include <iostream>
using namespace std;

/* your class */
template <class T> 
struct Node {
	T value;
	Node<T>* next;

	Node(T v) : value(v), next(0) {}
};

template<class T>
class LinkedList {
public:
	LinkedList() : head(0), tail(0) {}
	~LinkedList() {
		while (head && head->next) {
			Node<T>* garbage = head;
			head = head->next;
			delete garbage;
		}
		if (head) delete head;
	}

	virtual void push(T value) {
		/* At least one node has been placed */
		if (head && tail) {
			Node<T>* newNode = new Node<T>(value);
			/* For the second node, the value of tail is changed to the newest node.
			   Because head is also equal to the first node, head's next node is changed as well.
			   Afterwards, tail is set to newNode */
			tail->next = newNode;
			tail = newNode;
		}

		/* Creates the first node and sets head and tail equal to it */
		else {
			Node<T>* firstNode = new Node<T>(value);
			tail = firstNode;
			head = firstNode;
		}
	}

	T pop() {
		T value = 0;
		/* Creates a temporary node, moves head to the next node and deletes the temporary */
		if (head) {
			value = head->value; // pop value
			Node<T>* pop = head;
			head = head->next;
			delete pop;
		} else {
			cout << "There is currently no data in the list." << endl;
		}
		return value;
	}

	void print() {
		/* Iterates through each node printing the node's value */
		if (head) {
			Node<T>* current = head;
			while (current->next) {
				cout << current->value << " ";
				current = current->next;
			}
			/* Account for off by one 'space' */
			cout << current->value << endl;
		} else {
			cout << "There is currently no data in the list." << endl;
		}
	}

	T size() {
		T count = 0;
		/* Iterates through each node, tallying each node */
		Node<T>* current = head;
		while (current->next) {
			current = current->next;
			count++;
		}
		return count;
	}
/* Dervived classes have access to protected variables */
protected:
	Node<T>* head;
	Node<T>* tail;
};

#endif