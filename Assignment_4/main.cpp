/** 
Name: <your name>
Eid: <your id>
*/

#include "LinkedList.h"
// #include "PriorityQueue.h" /// make sure we include our PriorityQueue

using namespace std;

void useLinkedList() {
    LinkedList list;
    int value;
    char input;

    while (cin.get(input)) {
        // cout << input << " ";
        switch(input) {
            case '+':
                // cout << "push ";
                cin >> value;
                // cout << value << " ";
                list.push(value);
                break;
            case '-':
                // cout << "pop ";
                list.pop();
                break;
            case 'p':
                // cout << "print ";
                list.print();
                break;
            default:
                break;
        }
    }




}

void usePriorityQueue() {
    // PriorityQueue queue;
}

int main (int argc, char const **argv)
{
    /* your program */
    char c;
    cin >> c;
    
    if (c == 'l') {
        useLinkedList();
    } else {
        usePriorityQueue();
    }
	
    return 0;
}