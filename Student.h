#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <string>

using namespace std;

class Student : public Person {
private:
    int id;
    float gpa;
    set<string> courses;

public:
    Student() : Person(""), id(0), gpa(0.0) {}
    Student(int id, string name, float gpa) : Person(name) {
        this->id = id;
        this->gpa = gpa;
    }

    int getId();
    float getGpa();
    set<string> getCourses();
    bool enrollCourse(string course);
    void display();
};

#endif