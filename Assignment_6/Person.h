#ifndef __PERSON__12378QTA
#define __PERSON__12378QTA
#include "Rating.h"
#include <string>
#include <list>
using std::string;
using std::list;

class Rating;

class Person {
public: 
     Person(const string& name): name(name) {}
     Person(): name("free") {}	// used for the case when a value is free
     string name; 
     list<Rating> preferences;

     /* Overloaded so that key/value pairs when work in map */
     bool operator <(const Person&) const; 
};

#endif