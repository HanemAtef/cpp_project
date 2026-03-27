#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    string name;  

public:
    Person();
    Person(string n);

    string getName() const;
    void setName(string n);
    virtual void display() const = 0;

    virtual ~Person() {}
};

#endif