#ifndef __LINKED_LIST_CPP_9F4861BC
#define __LINKED_LIST_CPP_9F4861BC

/* your includes */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* your class */
template <class T> 
struct Node {
	T value;
	Node<T>* next;

	bool operator < (const Node<T>& node) const{
		cout << "this " << this->value << endl;
		cout << "other " << node.value << endl;
	    return this->value < node.value;
	}  
	bool operator <= (const Node<T>& node) const{
	    return this->value <= node.value;    
	}
	bool operator > (const Node<T>& node) const{
	    return this->value > node.value;
	}
	bool operator >= (const Node<T>& node) const{
	    return this->value >= node.value;
	}

	Node(T v) : value(v), next(0) {}
};

template<class T>
class LinkedList {
public:
	LinkedList() : head(0), tail(0) {}
	~LinkedList() {
		clean();
	}

	LinkedList<T>& operator =(const LinkedList<T>& list) {
		if (this == &list)
        	return *this;
        /* Cleans the original list for the next step */
    	clean();
    	/* Starts at the other list's head and moves through it, methodically 
    	   pushing list's values onto this */
    	for (Node<T>* current = list.head; current; current = current->next)
        	push(current->value);
        // cout << "used operator" << endl;
    	return *this;
	}

	bool operator ==(const LinkedList<T>& list) const {
		/* Temporary nodes to iterate through each list */
		Node<T>* one = head;
		Node<T>* two = list.head;

		/* Moves through the lists while at least one list is not null */
		while (one || two) {
			/* False if only one list is null or the list's values do not equal one another */
			if ((!one || !two) || !(one->value == two->value)) {
				return false;
			}
			/* Progress movement */
			one = one->next;
			two = two->next;
		}
		/* True if both lists are null */
		return true;
	}

	/* Returns opposite of == operator */
	bool operator !=(const LinkedList<T>& list) const {
		return !(*this == list);
	}

	LinkedList<T> operator +(const T v) const {
		LinkedList<T> newList;// = *this;
		for (Node<T>* current = head; current; current = current->next)
        	newList.push(current->value);
		// cout << newList.head << endl;
		newList.push(v);
		// newList.print();
		return newList;
	}

	LinkedList<T> operator +(const LinkedList<T>& list) const {
	    LinkedList<T> newList;// = *this;
	    if (head) {
			for (Node<T>* current = head; current; current = current->next)
	        	newList.push(current->value);
   		}

	    for (Node<T>* current = list.head; current; current = current->next)
        	newList.push(current->value);
	    return newList;
	}
	// Returns a new list object that is the equivalent of removing v from the List 
	// object (if it exists). This should remove all matching occurrences within the list.
	LinkedList operator - (const int v) const {
		if (!head) /// removing from an empty list is an error
        	throw "Exception: subtraction from empty list";
		LinkedList<T> newList;// = *this;
		for (Node<T>* current = head; current; current = current->next) {
        	if (current->value != v)
        		newList.push(current->value);
		}
		// cout << newList.head << endl;
		// newList.print();
		return newList;
	}

	LinkedList operator -(const LinkedList& list) const {

		if (!head)
        	throw "Exception: subtraction from empty list";
        /* Create a new list object and copy old values to it */
		LinkedList<T> newList;// = *this;
		for (Node<T>* current = head; current; current = current->next)
	        		newList.push(current->value);
	    /* Subtract elements from list from newList */
		T v;
		for (Node<T>* subList = list.head; subList; subList = subList->next) {
        	v = subList->value;
        	newList = newList - v;
		}
		return newList;
	}

	T& operator [](const int x) const {
		Node<T>* current = head;
		int count = 0;
		while (current && (count < x)) {
			if (!current->next) 
				throw "Exception: out of bounds";
			current = current->next;
			// cout << count << endl;
			count++;
		}
		return current->value;
	}

	friend ostream& operator << (ostream& out, const LinkedList<T>& list) {
			// Node<T>* current = list.head;
   // 		while (current){
   //      	cout << current->value << " ";
   //      	current = current->next;
   //  	}
   //  	return out;
    	/* Iterates through each node printing the node's value */
		if (list.head) {
			Node<T>* current = list.head;
			while (current->next) {
				cout << current->value << " ";
				current = current->next;
			}
			/* Account for off by one 'space' */
			cout << current->value;
		} else {
			throw "Exception: empty list";
		}
		return out;
	}
//Output the list. This cannot be a member function, it is a friend instead.

	// istream& operator >> (istream& in, LinkedList& list) {
	//     int v;
	//     std::string line;
	//     getline(in, line); 
	//     std::istringstream lis(line); /// get an input stream over our line
	    
	//     while (lis >> v){
	//         list.push(v);
	//     }
	//     return in;
	// }

	void clean() {
		while (head && head->next) {
			Node<T>* garbage = head;
			head = head->next;
			// cout << head << endl;
			delete garbage;
		}
		if (head) {
			delete head;
			head = 0;
		}
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
		cout << *this << endl;
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