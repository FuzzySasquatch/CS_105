#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class
using namespace std;

/* your class */
template<class T>
class PriorityQueue : public LinkedList<T> {
public:
	void push(T value) {
		/* At least one node has been placed */
		if (LinkedList<T>::head && LinkedList<T>::tail) {
			Node<T>* newNode = new Node<T>(value);
			Node<T>* current = LinkedList<T>::head;
			Node<T>* previous;

			/* The new value is less than or equal to the first node */
			if (value <= peek()) {

				newNode->next = LinkedList<T>::head;
				LinkedList<T>::head = newNode;

			/* The new node is greater than at least the first node */
			} else {
				while (current->next && (value > current->value)) {
					previous = current;
					current = current->next;
				}

				/* The new node is greater than the last node */
				if (!current->next && value > current->value) {
					LinkedList<T>::tail->next = newNode;
					LinkedList<T>::tail = newNode;

				/* The new node is less than or equal to the last node 
				   and greater than the first node */
				} else {
					newNode->next = current;
					previous->next = newNode;
				}
			}	

		/* Creates the first node and sets head and tail equal to it */	
		} else {
			Node<T>* firstNode = new Node<T>(value);
			LinkedList<T>::tail = firstNode;
			LinkedList<T>::head = firstNode;
		}
	}
	T peek() {
		if (LinkedList<T>::head)
			return LinkedList<T>::head->value;
		else
			cout << "There is currently no data in the list." << endl;
		return 0;
	}
};

#endif