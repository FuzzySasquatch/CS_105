#include "Rating.h"

bool Rating::operator >(const Rating& other) const{
    return !(this->rating > other.rating);
}
bool Rating::operator <(const Rating& other) const{
    return !(this->rating < other.rating);
}
bool Rating::operator <=(const Rating& other) const{
    return !(this->rating <= other.rating);
}
bool Rating::operator >=(const Rating& other) const{
    return !(this->rating >= other.rating);
}
bool Rating::operator ==(const Rating& other) const{
    return !(this->rating == other.rating);
}