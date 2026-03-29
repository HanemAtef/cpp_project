#include "Manager.h"
#include <iostream>

using namespace std;

bool compareByGPA(pair<int, Student>& a, pair<int, Student>& b) {
	return a.second.getGpa() > b.second.getGpa();
}

void Manager::addStudent() {

	int id;
	string name;
	float gpa;

	cout << "Enter Student ID: ";
	cin >> id;

	if (students.count(id)) {
		cout << "Student with id: " << id << " already exists! \n";
		return;
	}

	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter GPA:";
	cin >> gpa;

	if (gpa < 0.0 || gpa > 4.0) {
		cout << "Invalid GPA! \n";
		return;
	}

	students[id] = Student(id, name, gpa);
	cout << "Student  " << name << "  added successfully!\n";

}
void Manager::removeStudent() {
	int id;
	cout << "Enter Student ID:";
	cin >> id;

	if (students.count(id) == 0) {
		cout << "Student not found!\n";
		return;
	}

	students.erase(id);
	cout << "Student removed successfully!\n";
}

void Manager::searchStudent() {
	int id;
	cout << "Enter Student ID:";
	cin >> id;

	vector<pair<int, Student>> temp(students.begin(), students.end());
	vector<pair<int, Student>>::iterator it = find_if(
		temp.begin(), temp.end(),
		[id](pair<int, Student>& element) {
			return element.first == id;
		});
	if (it != temp.end()) {       
		it->second.display();
	}
	else {
		cout << "Student not found!\n";
	}


}
void Manager::displayAll() {
	if (students.empty()) {
		cout << "No students found!\n";
		return;
	}
	cout << "All Students: \n";
	for (pair<int, Student> element : students) {
		element.second.display();
	}

}
void Manager::enrollStudentInCourse() {
	int id;
	string course;

	cout << "Enter Student ID:";
	cin >> id;

	map<int, Student>::iterator it = students.find(id);

	if (it == students.end()){
		cout << "Invalid Student! \n";
		return;
	}
	cout << "Enter Course Name:";
	cin.ignore();
	getline(cin, course);

	if (it->second.enrollCourse(course)) {
		cout << "Enrolled to Course Successfully! \n";
	}
	else {
		cout << "Already Enrolled in this Course! \n";
	}

}
void Manager::showStudentCourses() {
	int id;
	cout << "Enter Student ID:";
	cin >> id;

	map<int, Student>::iterator it = students.find(id);

	if (it == students.end()) {
		cout << "Invalid Student! \n";
		return;
	}
	set<string> courses = it->second.getCourses();
	if (courses.empty()) {
		cout << "No Courses Enrolled! \n";
		return;
	}
	cout << "Courses for " << it->second.getName() << ": \n";

	for (string course : courses) {
		cout << "- " << course << "\n";
	}

}
void Manager::sortStudentsByGPA() {
	if (students.empty()) {
		cout << "No students found!\n";
		return;
	}
	vector<pair<int, Student>> temp(students.begin(), students.end());
	
	sort(temp.begin(), temp.end(), compareByGPA);
	
	cout << "Students From Highest to Lowest GPA: \n";

	for (pair<int, Student> element : temp) {
		element.second.display();
	}
}
