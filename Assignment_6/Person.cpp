#include "Person.h"

bool Person::operator <(const Person& other) const{
    return this->name < other.name;
}