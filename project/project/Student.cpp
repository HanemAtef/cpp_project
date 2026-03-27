#include "Student.h"

Student::Student() : Person(), id(0), gpa(0.0) {}

Student::Student(int i, string n, double g) : Person(n), id(i), gpa(g) {}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}
bool Student::setGpa(double g) {
    if (g >= 0.0 && g <= 4.0) {
        gpa = g;
        return true;
    }
    return false;
}

bool Student::addCourse(string courseName) {
    if (courses.find(courseName) != courses.end()) {
        return false; 
    }
    courses.insert(courseName);
    return true;
}

const set<string>& Student::getCourses() const {
    return courses;
}

void Student::displayCourses() const {
    if (courses.empty()) {
        cout << "No courses enrolled." << endl;
        return;
    }

    cout << "Courses for " << name << " (ID: " << id << "):" << endl;
    for (const string& course : courses) {
        cout << "  - " << course << endl;
    }
}

void Student::display() const {
    cout << "ID: " << id << " | Name: " << name
        << " | GPA: " << fixed << setprecision(2) << gpa << endl;
    displayCourses();
}

bool Student::operator<(const Student& other) const {
    return gpa > other.gpa;  
}