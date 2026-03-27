#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <iomanip>

using namespace std;


class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses; 

public:
    Student();
    Student(int i, string n, double g);

    int getId() const;
    double getGpa() const;

    bool setGpa(double g);

    bool addCourse(string courseName);
    const set<string>& getCourses() const;
    void displayCourses() const;

    void display() const override;

    bool operator<(const Student& other) const;
};

#endif