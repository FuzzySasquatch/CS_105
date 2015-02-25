/** 
Name: Phoenix Bishea
Eid: pnb338
*/

// #include "LinkedList.h"
#include "PriorityQueue.h" /// make sure we include our PriorityQueue

using namespace std;

void useLinkedList() {
    LinkedList<int> list;
    int value;
    char input;

    bool eof = false;
    // int a = 1.1;
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
    Node<int>* a = ;
    Node<int>* b = ;

    // cout << a->value <<endl;
    // cout << b->value << endl;
    // cout << list << endl;
    bool one = a < b;
    bool two = a > b;
    bool three = a > b;
    bool four = a > b;

    cout << one << endl;;
    cout << two << endl;
    cout << three << endl;
    cout << four << endl;
    // cin >>
    // eof = false;
    // LinkedList<int> list2;

    // while (cin.get(input) && !eof) {
    //     switch(input) {
    //         case '+':
    //             cin >> value;
    //             // cout << value << std::fixed;
    //             list2.push(value);
    //             break;
    //         case '-':
    //             list2.pop();
    //             break;
    //         case 'p':
    //             list2.print();
    //             break;
    //         case 'q':
    //             eof = true;
    //         default:
    //             break;
    //     }
    // }

  
    // list2 = list2 - list;

    // LinkedList<int> list3;
    // list3.push(3.0);
    // list3 = list3 + 3.1 + 5.5 + 7.3;
    // LinkedList<int> list4 = list + list2 + list3;
    // list2.print();
    // cout << result << endl;
}

void usePriorityQueue() {
    PriorityQueue<int> list;
    int value;
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