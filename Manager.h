#ifndef Manager_H
#define Manager_H

#include "Student.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compareByGPA(pair<int, Student>& a, pair<int, Student>& b);

class Manager
{
private:
	map<int, Student> students;
public:
	void addStudent();
	void removeStudent();
	void searchStudent();
	void displayAll();
	void enrollStudentInCourse();
	void showStudentCourses();
	void sortStudentsByGPA();
};

#endif



