# C Starter Projects

A collection of C programming projects tracking my journey from core console logic to advanced memory management and modular architecture. 

---

## Repository Structure
c-fundamental-projects
├── GameHub/                  # Terminal-based mini-games (Blackjack, RPS)
└── StudentManagementSystem/  # Dynamic memory & Binary File I/O system


# Projects Overview
1. GameHub
A lightweight, terminal-based game collection practicing basic logic flow and console UI design.

Features: Blackjack (with automated dealer AI) and Rock-Paper-Scissors (with timing animations).

Core Concepts: <windows.h> utilities, random seeding (srand), loops, and basic pointers.

2. Student Management System
A robust command-line application simulating database persistence using dynamic structures.

Features: Dynamic student tracking with auto-resizing arrays and persistence across sessions.

Core Concepts: Heap allocation (malloc/realloc), Binary File I/O (fwrite/fread), and modular programming (.h / .c multi-file design).

# How to Run
Navigate into the specific project directory and run the compilation commands:
# To run GameHub
cd GameHub && gcc main.c -o GameHub && ./GameHub

# To run Student Management System
cd StudentManagementSystem && gcc main.c student.c -o StudentSystem && ./StudentSystem

## About Me
Computer Engineering student at Yaşar University. This repository represents my journey into mastering programming fundamentals, data structures, and memory management. I am focused on building a strong core in computer science while continuously expanding my skillset toward modern software development practices.
