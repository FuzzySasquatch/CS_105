/** 
Name: <your name>
Eid: <your id>
*/

#include "LinkedList.h"
// #include "PriorityQueue.h" /// make sure we include our PriorityQueue

using namespace std;

int main (int argc, char const **argv)
{
    /* your program */
    LinkedList list;
    int value;


    while (!cin.eof()) {
    	cin >> value;
    	list.push(value);
		
    }
    list.print();
	
    return 0;
}