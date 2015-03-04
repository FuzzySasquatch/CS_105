#include <iostream>
#include <sstream>
#include <map>
#include <list>
#include "Person.h"
#include "Rating.h"
#include "readgraph.h"
#include "Matcher.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;

int main (int argc, char const *argv[])
{
    list<Person> capulets; /// capulets
    list<Person> montagues; /// montagues
    readIn(capulets, montagues); /// will fill in the provided lists
    
    /// print it all out to see it all worked
    for(int i=1; i <= 2; i++){
        list<Person>& group = i==1 ? capulets : montagues;
        cout << "Group : " << i << endl;
        for(list<Person>::iterator iter = group.begin(); iter != group.end(); ++iter){
            Person& p = *iter;
            p.preferences.sort();
            cout << p.name << " : " ;
            for (list<Rating>::iterator iter = p.preferences.begin() ; iter != p.preferences.end(); ++iter){
                cout << "(" << iter->person->name << ":" << iter->rating << ") ";
            }
            cout << endl;
        }        
    }

    cout << endl;

    Matcher m;
    map<Person,Person> result = m.stableMatch(capulets, montagues);

    /* Print the results */
    for (map<Person,Person>::iterator iter = result.begin(); iter != result.end(); ++iter) {
        string personA = iter->first.name;
        string personB = iter->second.name;
        cout << personA << " " << personB << endl;
    }

    return 0;
}