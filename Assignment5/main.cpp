/** 
Name: Phoenix Bishea
Eid: pnb338
*/

// #include "LinkedList.h"
#include "PriorityQueue.h" /// make sure we include our PriorityQueue

using namespace std;

void useLinkedList() {
    LinkedList<double> list;
    double value;
    char input;

    // double a = 1.1;
    // cout << a;

    while (cin.get(input)) {
        switch(input) {
            case '+':
                cin >> value;
                // cout << value << std::fixed;
                list.push(value);
                break;
            case '-':
                list.pop();
                break;
            case 'p':
                list.print();
                break;
            case 'q':
                return;
            default:
                break;
        }
    }
}

void usePriorityQueue() {
    PriorityQueue<double> list;
    double value;
    char input;

    // bool f;

    while (cin.get(input)) {
        switch(input) {
            case '+':
                cin >> value;
                // f = (value == 1.1);
                // cout << value << endl;
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
            case 'q':
                return;
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
    } else if (c == 'q') {
        usePriorityQueue();
    } else

    return 0;
}