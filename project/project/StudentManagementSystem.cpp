#include "StudentManagementSystem.h"


int StudentManagementSystem::findStudentById(int id) {
    auto it = find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        return distance(students.begin(), it);
    }
    return -1;
}


void StudentManagementSystem::addStudent() {
    int id;
    string name;
    double gpa;

    cout << "\n=== Add New Student ===" << endl;
    cout << "Enter Student ID: ";
    cin >> id;

    if (findStudentById(id) != -1) {
        cout << "Error: Student with ID " << id << " already exists!" << endl;
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter GPA (0.0 - 4.0): ";
    cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        cout << "Error: GPA must be between 0.0 and 4.0!" << endl;
        return;
    }

    Student newStudent(id, name, gpa);
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}


void StudentManagementSystem::removeStudent() {
    int id;
    cout << "\n=== Remove Student ===" << endl;
    cout << "Enter Student ID to remove: ";
    cin >> id;

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Error: Student with ID " << id << " not found!" << endl;
        return;
    }

    students.erase(students.begin() + index);
    cout << "Student removed successfully!" << endl;
}


void StudentManagementSystem::searchStudent() {
    int id;
    cout << "\n=== Search Student ===" << endl;
    cout << "Enter Student ID: ";
    cin >> id;

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "\nStudent Found:" << endl;
    students[index].display();
}


void StudentManagementSystem::displayAllStudents() {
    cout << "\n=== All Students ===" << endl;

    if (students.empty()) {
        cout << "No students in the system." << endl;
        return;
    }

    cout << "\nTotal Students: " << students.size() << endl;
    cout << "----------------------------------------" << endl;

    for (const Student& student : students) {
        student.display();
        cout << "----------------------------------------" << endl;
    }
}


void StudentManagementSystem::enrollStudentInCourse() {
    int id;
    string courseName;

    cout << "\n=== Enroll Student in Course ===" << endl;
    cout << "Enter Student ID: ";
    cin >> id;

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Error: Student not found!" << endl;
        return;
    }

    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, courseName);

    if (students[index].addCourse(courseName)) {
        cout << "Student enrolled in " << courseName << " successfully!" << endl;
    }
    else {
        cout << "Error: Student is already enrolled in " << courseName << "!" << endl;
    }
}


void StudentManagementSystem::showStudentCourses() {
    int id;
    cout << "\n=== Show Student Courses ===" << endl;
    cout << "Enter Student ID: ";
    cin >> id;

    int index = findStudentById(id);
    if (index == -1) {
        cout << "Error: Student not found!" << endl;
        return;
    }

    students[index].displayCourses();
}


void StudentManagementSystem::sortStudentsByGPA() {
    if (students.empty()) {
        cout << "\nNo students to sort." << endl;
        return;
    }

    sort(students.begin(), students.end());

    cout << "\n=== Students Sorted by GPA (Highest First) ===" << endl;
    displayAllStudents();
}


void StudentManagementSystem::showMenu() {

    cout << "1. Add Student" << endl;
    cout << "2. Remove Student" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Display All Students" << endl;
    cout << "5. Enroll Student in Course" << endl;
    cout << "6. Show Student Courses" << endl;
    cout << "7. Sort Students by GPA" << endl;
    cout << "8. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-8): ";
}


void StudentManagementSystem::run() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            displayAllStudents();
            break;
        case 5:
            enrollStudentInCourse();
            break;
        case 6:
            showStudentCourses();
            break;
        case 7:
            sortStudentsByGPA();
            break;
        case 8:
            cout << "\nThank you for using the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    } while (choice != 8);
}