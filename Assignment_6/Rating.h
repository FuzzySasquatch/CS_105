#ifndef __RATING__12378QTA
#define __RATING__12378QTA
#include "Person.h"

class Person;

class Rating {
public:
    Rating(Person* p, int rating) : person(p), rating(rating) {}
    Rating(int rating) : rating(rating) {}
    Person* person;
    int rating; 

    bool operator >(const Rating&) const; 
    bool operator <(const Rating&) const; 
    bool operator <=(const Rating&) const; 
    bool operator >=(const Rating&) const; 
    bool operator ==(const Rating&) const; 
};

#endif