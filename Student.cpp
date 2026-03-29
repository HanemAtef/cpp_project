#include "Student.h"
#include <iostream>

using namespace std;

int Student::getId() {
	return id;
}
float Student::getGpa() {
	return gpa;
}
set<string> Student::getCourses() {
	return courses;
}
bool Student::enrollCourse(string course) {
	if (courses.count(course)) {
		return false;
	}
	courses.insert(course);
	return true;
}
void Student::display() {
	cout << "ID: " << id << "\n";
	cout << "Name: " << name << "\n";
	cout << "GPA: " << gpa << "\n";
}