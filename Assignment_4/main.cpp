/** 
Name: Phoenix Bishea
Eid: pnb338
*/

#include "PriorityQueue.h" /// make sure we include our PriorityQueue
using namespace std;

void useLinkedList() {
    LinkedList list;
    int value;
    char input;

    while (cin.get(input)) {
        switch(input) {
            case '+':
                cin >> value;
                list.push(value);
                break;
            case '-':
                list.pop();
                break;
            case 'p':
                list.print();
                break;
            default:
                break;
        }
    }
}

void usePriorityQueue() {
    PriorityQueue list;
    int value;
    char input;

    while (cin.get(input)) {
        switch(input) {
            case '+':
                cin >> value;
                list.push(value);
                break;
            case '-':
                list.pop();
                break;
            case '=':
                list.peek();
                break;
            case 'p':
                list.print();
                break;
            default:
                break;
        }
    }
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