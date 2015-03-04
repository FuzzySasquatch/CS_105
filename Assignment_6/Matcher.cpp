#include "Matcher.h"
#include <iostream>
#include <typeinfo>
using std::list;
using std::map;
using std::pair;
using std::cout;
using std::endl;

/* Test to see if a value is free */
bool isFree(Person& p) {
	return p.name == "free";
}

map<Person,Person> Matcher::stableMatch(const list<Person>& proposors, const list<Person>& acceptors) {
	map<Person,Person> proposorMap;
	map<Person,Person> acceptorMap;
	Person unattached;	// default member name = "free"

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
    map< Person,list<Rating> > preferenceMap;
	for (list<Person>::const_iterator iter = proposors.begin(); iter != proposors.end(); ++iter) {
		Person p = *iter;
		list<Rating> rptr = p.preferences;
		preferenceMap.insert( pair< Person, list<Rating> >(p, rptr));
	}

	/* Iterator for the current proposor, acceptor, and proposor preferences */
	map<Person,Person>::iterator prop = proposorMap.begin();
	map<Person,Person>::iterator acc;
	map< Person,list<Rating> >::iterator prefs = preferenceMap.begin();

	/* Loops while free proposors exist */
	bool freeProposors = true;
	while (freeProposors) {
		/* Retrieve current proposor's highest rated acceptor */
		acc = acceptorMap.find(*(prefs->second.front().person));

		/* Remove current acceptor from current proposor's preference list */
		if (!prefs->second.empty())
			prefs->second.pop_front();		

		/* Assign a proposor to an acceptor if the acceptor is free */
		if (isFree(acc->second)) {
			prop->second = acc->first;
			acc->second = prop->first;
		}
		/* If acceptor is not free */
		else {
			/* Retrieve partners in question */
			Person oldPartner = acc->second;
			Person newPartner = prop->first;

			/* Create a comparison preference list for the current acceptor */
			list<Rating> accPrefComparision;
			list<Rating> temp = acc->first.preferences;

			for (list<Rating>::iterator iter = temp.begin(); iter != temp.end(); ++iter) {
				Person* p = iter->person;
				/* Add people matching old and new partner to the list */
				if (p->name == oldPartner.name || p->name == newPartner.name) {
					Rating r = *iter;
					accPrefComparision.push_front(r);
				}
			}

			/* Sort the list and retrieve the first person */
			accPrefComparision.sort();
			Person* p = accPrefComparision.front().person;

			/* If acceptor rates the new proposor higher than its current partner */
			if (p->name == newPartner.name) {
				proposorMap.find(acc->second)->second = unattached;		// free the old partner
				/* Match acc and the new partner */
				acc->second = newPartner;
				prop->second = acc->first;
			}
			/* If acceptor rates the new proposor lower than its current partner */
			/* Current acceptor and oldPartner remain engaged */
		}

		/* Increment current proposor and current preferences */
		++prop;
		++prefs;

		/* If the end of the map is reached return to the beginning */
		if (prop == proposorMap.end()) {
			prop = proposorMap.begin();
			prefs = preferenceMap.begin();
		}

		/* Check to see if each proposor is free */
		freeProposors = false;
		for (map<Person, Person>::iterator iter = proposorMap.begin(); iter != proposorMap.end(); ++iter) {
			if (isFree(iter->second)) {
				freeProposors = true;
			}
		}
		/* If there are free proposors increment until one is found */
		if (freeProposors) {
			while (!isFree(prop->second)) {
				++prop;
				++prefs;
			}
		}
	}
	
	return proposorMap;
}