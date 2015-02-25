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

    bool eof = false;
    // double a = 1.1;
    // cout << a;

    while (cin.get(input) && !eof) {
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
                eof = true;
            default:
                break;
        }
    }

    eof = false;
    LinkedList<double> list2;

    while (cin.get(input) && !eof) {
        switch(input) {
            case '+':
                cin >> value;
                // cout << value << std::fixed;
                list2.push(value);
                break;
            case '-':
                list2.pop();
                break;
            case 'p':
                list2.print();
                break;
            case 'q':
                eof = true;
            default:
                break;
        }
    }

    list2 = 1.0 + list + 25.6;
    list2.print();
    // cout << result << endl;
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