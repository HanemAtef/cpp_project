# Student Course Management System

## Project Report

### Overview
The **Student Course Management System** is a console-based C++ application designed to efficiently manage student records and course enrollments. It provides administrators with a simple menu-driven interface to perform standard CRUD (Create, Read, Update, Delete) operations on a student database. 

### Architecture & Design
The project is built using strict Object-Oriented Programming (OOP) paradigms and leverages the C++ Standard Template Library (STL) for optimized data handling:
* **Encapsulation:** Class attributes are protected/private, accessed only via public getter methods and specific utility functions.
* **Inheritance:** A base `Person` class establishes common traits (like a name), which the `Student` class inherits and extends with academic-specific attributes (ID, GPA, Courses).
* **Data Structures (STL):**
    * `std::map`: Used in the `Manager` class for $O(\log n)$ retrieval, insertion, and deletion of students using their ID as the key.
    * `std::set`: Used inside the `Student` class to store enrolled courses, automatically preventing duplicate enrollments.
    * `std::vector` & `std::sort`: Utilized to copy map data and sort students dynamically by GPA.

### Key Features
* **Add/Remove Students:** Easily enroll or dismiss students from the system.
* **Course Management:** Enroll students in courses while preventing duplicate entries.
* **Search & Display:** Find specific students by ID or view the entire registry.
* **Academic Sorting:** Automatically sort and display all students from highest to lowest GPA.
* **Input Validation:** Handles invalid menu inputs to prevent console crashes.

---

## UML Class Diagram

The following diagram illustrates the structural relationships between the core classes of the application:

```mermaid
classDiagram
    class Person {
        #string name
        +Person(string name)
        +getName() string
    }

    class Student {
        -int id
        -float gpa
        -set~string~ courses
        +Student()
        +Student(int id, string name, float gpa)
        +getId() int
        +getGpa() float
        +getCourses() set~string~
        +enrollCourse(string course) bool
        +display() void
    }

    class Manager {
        -map~int, Student~ students
        +addStudent() void
        +removeStudent() void
        +searchStudent() void
        +displayAll() void
        +enrollStudentInCourse() void
        +showStudentCourses() void
        +sortStudentsByGPA() void
    }

    Person <|-- Student : Inherits
    Manager "1" *-- "many" Student : Manages
