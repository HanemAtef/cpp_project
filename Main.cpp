#include "Manager.h"
#include <iostream>

using namespace std;

void showMenu() {
    //cout << "\n===== Student Course Management System ===== \n" ;
    //cout << "1. Add Student \n";
    //cout << "2. Remove Student \n";
    //cout << "3. Search Student \n";
    //cout << "4. Display All Students \n";
    //cout << "5. Enroll Student in Course \n";
    //cout << "6. Show Student Courses \n";
    //cout << "7. Sort Students by GPA \n";
    //cout << "8. Exit \n";
    //cout << "============================================ \n";
    cout << "Enter your choice: ";
}

int main()
{
    Manager admin;
    int choice;
    bool running = true;
    while (running) {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1: admin.addStudent();            break;
        case 2: admin.removeStudent();         break;
        case 3: admin.searchStudent();         break;
        case 4: admin.displayAll();            break;
        case 5: admin.enrollStudentInCourse(); break;
        case 6: admin.showStudentCourses();    break;
        case 7: admin.sortStudentsByGPA();     break;
        case 8:
            running = false;
            cout << "Goodbye! \n";
            break;
        default:
            cout << "Invalid choice! Please enter 1-8. \n";
        }
    }
        return 0;
}