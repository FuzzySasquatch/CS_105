#ifndef __MATCHER__12378QTA
#define __MATCHER__12378QTA
#include "Person.h"
#include "Rating.h"
#include <string>
#include <list>
#include <map>
using std::string;
using std::list;
using std::map;

class Matcher {
public:
	map<Person,Person> stableMatch(const list<Person>&, const list<Person>&);
};

#endif