/** 
Name: Phoenix Bishea
Eid: pnb338
*/

// #include "LinkedList.h"
#include "PriorityQueue.h" /// make sure we include our PriorityQueue

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
            // case '=':
            //     // cout << "print ";
            //     list.peek();
            //     break;
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
    PriorityQueue list;
    // cout << "Made the PriorityQueue." << endl;
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
            case '=':
                // cout << "peek ";
                list.peek();
                break;
            case 'p':
                // cout << "print ";
                list.print();
                break;
            default:
                break;
        }
    }
    // cout << "through input" << endl;
}

int main (int argc, char const **argv)
{
    /* your program */
    char c;
    cin >> c;
    // cout << c << endl;
    
    if (c == 'l') {
        useLinkedList();
    } else {
        // cout << "Reached use PriorityQueue." << endl;
        usePriorityQueue();
    }

    
    return 0;
}