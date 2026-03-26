// Student Course Management System
// Author: Student
// Description: A console application to manage students and their course enrollments

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

// Base class Person - demonstrating inheritance
class Person {
protected:
    string name;
    
public:
    Person() : name("") {}
    Person(string n) : name(n) {}
    
    string getName() const { return name; }
    void setName(string n) { name = n; }
    
    virtual void display() const = 0; // Pure virtual function
};

// Student class inheriting from Person
class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses; // Using set to automatically avoid duplicates
    
public:
    // Constructor
    Student() : Person(), id(0), gpa(0.0) {}
    
    Student(int i, string n, double g) : Person(n), id(i), gpa(g) {}
    
    // Getters
    int getId() const { return id; }
    double getGpa() const { return gpa; }
    
    // Setters with validation
    bool setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
            return true;
        }
        return false;
    }
    
    // Course management
    bool addCourse(string courseName) {
        // Check if course already exists (set handles duplicates)
        if (courses.find(courseName) != courses.end()) {
            return false; // Course already exists
        }
        courses.insert(courseName);
        return true;
    }
    
    const set<string>& getCourses() const {
        return courses;
    }
    
    void displayCourses() const {
        if (courses.empty()) {
            cout << "No courses enrolled." << endl;
            return;
        }
        
        cout << "Courses for " << name << " (ID: " << id << "):" << endl;
        for (const string& course : courses) {
            cout << "  - " << course << endl;
        }
    }
    
    // Override display function
    void display() const override {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << fixed << setprecision(2) << gpa << endl;
        displayCourses();
    }
    
    // For sorting by GPA
    bool operator<(const Student& other) const {
        return gpa > other.gpa; // Sort descending
    }
};

// Comparator for sorting students by GPA
bool compareByGPA(const Student& a, const Student& b) {
    return a.getGpa() > b.getGpa();
}

// Main management system class
class StudentManagementSystem {
private:
    vector<Student> students; // STL container - vector
    
public:
    // Add a new student
    void addStudent() {
        int id;
        string name;
        double gpa;
        
        cout << "\n=== Add New Student ===" << endl;
        cout << "Enter Student ID: ";
        cin >> id;
        
        // Check if ID already exists
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
    
    // Remove student by ID
    void removeStudent() {
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
    
    // Search student by ID
    void searchStudent() {
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
    
    // Display all students
    void displayAllStudents() {
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
    
    // Enroll student in a course
    void enrollStudentInCourse() {
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
        } else {
            cout << "Error: Student is already enrolled in " << courseName << "!" << endl;
        }
    }
    
    // Show courses for a student
    void showStudentCourses() {
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
    
    // Sort students by GPA using STL algorithm
    void sortStudentsByGPA() {
        if (students.empty()) {
            cout << "\nNo students to sort." << endl;
            return;
        }
        
        // Using STL sort algorithm
        sort(students.begin(), students.end(), compareByGPA);
        
        cout << "\n=== Students Sorted by GPA (Highest First) ===" << endl;
        displayAllStudents();
    }
    
    // Helper function to find student by ID
    int findStudentById(int id) {
        // Using STL find_if algorithm
        auto it = find_if(students.begin(), students.end(),
                         [id](const Student& s) { return s.getId() == id; });
        
        if (it != students.end()) {
            return distance(students.begin(), it);
        }
        return -1;
    }
    
    // Display main menu
    void showMenu() {
        cout << "\n========================================" << endl;
        cout << "   STUDENT COURSE MANAGEMENT SYSTEM" << endl;
        cout << "========================================" << endl;
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
    
    // Run the system
    void run() {
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
};

// Main function
int main() {
    cout << "========================================" << endl;
    cout << "   WELCOME TO STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    
    StudentManagementSystem system;
    system.run();
    
    return 0;
}