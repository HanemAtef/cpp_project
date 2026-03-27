#include "Person.h"

Person::Person() : name("") {}

Person::Person(string n) : name(n) {}

string Person::getName() const {
    return name;
}

void Person::setName(string n) {
    name = n;
}