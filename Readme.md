# Student Course Management System

A C++ console application for managing students and their course enrollments.

## Features

- Add new students with ID, name, and GPA
- Remove existing students by ID
- Search for students by ID
- Display all students with their information
- Enroll students in courses (prevents duplicate enrollments)
- View courses for a specific student
- Sort students by GPA (highest first)
- Input validation for GPA (0.0-4.0) and unique IDs

## Technologies Used

- C++ (C++11 or later)
- STL Containers: vector, set
- STL Algorithms: sort, find_if

## Requirements

- C++ compiler with C++11 support (g++, clang++, MSVC)
- No external libraries required

## How to Compile and Run

### Using g++ (Linux/Mac):

```bash
g++ -std=c++11 main.cpp -o student_management
./student_management