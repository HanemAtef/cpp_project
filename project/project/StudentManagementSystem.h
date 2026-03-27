#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include "Student.h"
#include <vector>
#include <algorithm>

using namespace std;


class StudentManagementSystem {
private:
    vector<Student> students;  


    int findStudentById(int id);

public:
    void addStudent();
    void removeStudent();
    void searchStudent();
    void displayAllStudents();

    void enrollStudentInCourse();
    void showStudentCourses();

    void sortStudentsByGPA();

    void showMenu();
    void run();
};

#endif