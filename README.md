# Student-Management-System-C-Programming-
Project Overview:

This project is a console-based Student Management System developed using the C programming language.
It was created as part of the SOC Engineer Training at Xpand CS to demonstrate strong understanding and practical implementation of core C concepts, including structures, arrays, pointers, file handling, searching and sorting algorithms, and menu-driven programs.

The system allows users to manage student records efficiently through an interactive menu interface.

Project Objectives:

Apply fundamental and advanced C programming concepts

Practice modular programming using functions

Implement searching and sorting algorithms

Use pointers for data manipulation

Store and retrieve data using file handling

Build a user-friendly menu-based application

Project Features & Implementation:
1. Structures

Defined a Student structure containing:

Student ID (int)

Full Name (char[50])

Age (int)

Total Marks (float)

Average (float)

Grade (char)

2. Arrays & Input/Output

Created an array of Student structures for 5 students

Implemented data input using for loops

Input validation:

Age must be between 17 and 25

Total Marks must be between 0 and 400

Displayed student records in a formatted table

3. Functions & Operations

Implemented modular functions for better code readability and maintenance:

calculateAverage() – Calculates student average (Total Marks / 4)

calculateClassAverage() – Computes overall class average

assignGrade() – Assigns grades based on average:

A: 90–100

B: 80–89

C: 70–79

D: 60–69

F: Below 60

4. Searching Algorithm

Implemented Linear Search

Function searchStudent():

Searches by Student ID

Returns index if found, -1 if not found

Displays appropriate messages:

Student Found

Student Not Found

5. Sorting Algorithm

Implemented Bubble Sort

Sorts students by Total Marks (Descending Order)

Displays student data before and after sorting

(Optional) Shows each pass of the bubble sort for learning purposes

6. Pointers

Used pointers to traverse the student array

Implemented updateStudent() using pointers to modify student data

Demonstrated pointer arithmetic for array access

7. Conditionals & Loops

Used switch statements to display performance categories:

Excellent (A)

Good (B)

Satisfactory (C)

Needs Improvement (D/F)

Implemented do-while loops for re-entering invalid input

Used nested if-else statements for detailed grade comments

8. File Handling

saveToFile():

Saves student data to students.txt

loadFromFile():

Loads student data from file into memory

File format:

ID,Name,Age,Marks,Average,Grade

9. Menu System

The program includes an interactive menu:

==========================================
STUDENT MANAGEMENT SYSTEM
==========================================
1. ENTER STUDENT DATA
2. DISPLAY ALL STUDENTS
3. SEARCH FOR STUDENT
4. SORT STUDENTS BY MARKS
5. CALCULATE CLASS STATISTICS
6. SAVE DATA TO FILE
7. LOAD DATA FROM FILE
8. UPDATE STUDENT RECORD
9. EXIT
==========================================
Enter your choice (1-9):


Technologies Used:

Language: C

Concepts: Structures, Arrays, Pointers, File Handling, Algorithms

IDE/Compiler: Any standard C compiler (GCC recommended)

Acknowledgment:

This project was developed as part of the SOC Engineer Training at Xpand CS.
Special thanks to Abdelrahman Hamed, our C Scripting Instructor, for his guidance and support.

Repository:

All project files and source code are available in this repository.
Feel free to explore, fork, and contribute!
