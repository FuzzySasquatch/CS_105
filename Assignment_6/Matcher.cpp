#include "Matcher.h"
#include <iostream>
#include <typeinfo>
using std::list;
using std::map;
using std::pair;
using std::cout;
using std::endl;

bool isFree(Person& p) {
	return p.name == "free";
}

map<Person,Person> Matcher::stableMatch(const list<Person>& proposors, const list<Person>& acceptors) {
	map<Person,Person> proposorMap;
	map<Person,Person> acceptorMap;
	Person unattached;
	/* free proposors and acceptors */
	for(int i = 1; i <= 2; i++) {
        const list<Person>& group = (i == 1) ? proposors : acceptors;
        map<Person,Person>& map = (i == 1) ? proposorMap : acceptorMap;
		for (list<Person>::const_iterator iter = group.begin(); iter != group.end(); ++iter) {
			Person p = *iter;
			map.insert( pair<Person, Person>(p, unattached));
		}
	}


	/* Create something to keep track of each proposors proposals */
    map< Person,list<Rating> > preferencePtr;
	for (list<Person>::const_iterator iter = proposors.begin(); iter != proposors.end(); ++iter) {
		Person p = *iter;
		list<Rating> rptr = p.preferences;
		preferencePtr.insert( pair< Person, list<Rating> >(p, rptr));
	}

	map<string,Person> accMap;
	for (list<Person>::const_iterator iter = acceptors.begin(); iter != acceptors.end(); ++iter) {
		Person p = *iter;
		string name = p.name;
		accMap.insert( pair<string,Person>(name, p));
	}

	/* How to keep track of who has be proposed to */
	// list<Rating> rptr = proposors.front().preferences;
	// cout << rptr.front().person->name << endl;
	// rptr.pop_front();
	// cout << rptr.front().person->name << endl;

	/* Keep track of who has been proposed to with a temp alias */
	list<Rating>& rptr = preferencePtr.begin()->second;
	// cout << rptr.front().person->name << endl;
	// rptr.pop_front();
	// cout << preferencePtr.begin()->second.front().person->name << endl;



	cout << endl;
	// /* print proposorMap */
	// for (map<Person, Person>::iterator iter = proposorMap.begin(); iter != proposorMap.end(); ++iter) {
	// 	cout << iter->first.name << " " << iter->second.name << endl;
	// }
	// cout << "-------------------" << endl;
	// /* print acceptorMap */
	// for (map<Person, Person>::iterator iter = acceptorMap.begin(); iter != acceptorMap.end(); ++iter) {
	// 	cout << iter->first.name << " " << iter->second.name << endl;
	// }



	// Rating r = proposorMap.begin()->first.preferences.front();
	// cout << proposorMap.begin()->first.name << " " << r.person->name << endl;

	/* if acceptor is free the two become engaged */


	// if (isFree(acceptorMap.begin()->second)) {
	// 	cout << acceptorMap.begin()->first.name << " is free" << endl;
	// 	proposorMap.begin()->second = acceptorMap.begin()->first;
	// 	cout << proposorMap.begin()->first.name << " " << proposorMap.begin()->second.name << endl;
	// } else {
	// 	if (w.Rating m > w.Rating!m) {
	// 		proposorMap.begin()->second = acceptorMap.begin()->first;
	// 		!m is free
	// 	}
	// }

	map<Person,Person>::iterator m = proposorMap.begin();
	// map<Person,Person>::iterator 
	map<string,Person>::iterator finder;// w = acceptorMap.begin();
	map<Person,Person>::iterator w;// = acceptorMap.begin();
	map< Person,list<Rating> >::iterator prefs = preferencePtr.begin();

	bool freeProposors = true;
	while (freeProposors) {

		/* Retrieve current proposor's highest rated */
		string wName = prefs->second.front().person->name;
		finder = accMap.find(wName);
		w = acceptorMap.find(finder->second);
		// cout << w->first.name << endl;

		if (!prefs->second.empty())
			prefs->second.pop_front();		// Account for one proposal by removing person proposed to

		/* Assign a proposor to an acceptor if the acceptor is free */
		if (isFree(w->second)) {
			m->second = w->first;
			w->second = m->first;
			cout << m->first.name << " engaged to " << m->second.name << endl;
		}
		/* If acceptor is not free */
		else {
			
			Person partner = w->second;
			Person newPartner = m->first;
			list<Rating> wComparison;
			list<Rating> temp = w->first.preferences;
			
			/* Create a comparison preference list for the current acceptor */
			for (list<Rating>::iterator iter = temp.begin(); iter != temp.end(); ++iter) {
				Person* p = iter->person;
				
				if (p->name == partner.name || p->name == newPartner.name) {
					Rating r = *iter;
					wComparison.push_front(r);
					// cout << r.person->name << endl;
				}
			}
			/* Sort the list and retrieve the first element */
			wComparison.sort();
			Person* p = wComparison.front().person;	// don't need to deref
			cout << endl << w->first.name << " prefers " << p->name << endl;

			/* If acceptor rates the new proposor higher than its current partner */
			if (p->name == newPartner.name) {
				cout << "made it to comparison" << endl;
				cout << proposorMap.find(w->second)->second.name << endl; //= unattached;
				w->second = newPartner;
				// free the old partner
			}
			/* If acceptor rates the new proposor lower than its current partner */
			else {
				cout << partner.name << " and " << w->first.name << " remain engaged" << endl;
				// (m', w) remain engaged
			}
		}

		/* Increment current proposor and his/her preferences */
		++m;
		++prefs;

		/* Check to see if each proposor is free */
		freeProposors = false;
		for (map<Person, Person>::iterator iter = proposorMap.begin(); iter != proposorMap.end(); ++iter) {
			if (isFree(iter->second)) {
				freeProposors = true;
			}
		}
		cout << "current proposor = " << m->first.name << endl;
	}


	// function stableMatching {
	//     Initialize all m ∈ M and w ∈ W to free
	//     while ∃ free man m who still has a woman w to propose to {
	//        w = highest ranked woman to whom m has not yet proposed
	//        if w is free
	//          (m, w) become engaged
	//        else some pair (m', w) already exists
	//          if w prefers m to m'
	//            (m, w) become engaged
	//            m' becomes free
	//          else
	//            (m', w) remain engaged
	//     }
	// }
	
	return proposorMap;
}