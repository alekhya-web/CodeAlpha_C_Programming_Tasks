# CodeAlpha C Programming Internship

This repository contains solutions for the 3 C programming internship tasks assigned by **CodeAlpha**. Each program is written in standard, clean C with clear menus, input validation, and minimal comments.

---

## Tasks Overview

### 1. Task 1: Arithmetic Calculator (`task1_calculator.c`)
- **Description:** A console-based arithmetic calculator that performs basic operations (`+`, `-`, `*`, `/`).
- **Key Concepts:** `do-while` loop for repeated calculations, `switch-case` for operator branching, and divide-by-zero error handling.

### 2. Task 2: Matrix Operations (`task2_matrix.c`)
- **Description:** A menu-driven program performing matrix operations using 2D arrays.
- **Key Concepts:** Functions for matrix addition, multiplication, and transpose, paired with input prompts and loop-based dimension validation (e.g., checking identical dimensions for addition and matching inner dimensions for multiplication).

### 3. Task 3: Student Management System (`task3_student_management.c`)
- **Description:** A file-based CRUD system to manage student records.
- **Key Concepts:** `struct Student` (id, name, marks) and binary file handling using `fopen`, `fwrite`, `fread`, `remove`, and `rename` to add, view, search, update, and delete records.

---

## Compilation & Execution

Make sure you have **GCC** installed on your system.

### 1. Compile the Programs

Open your terminal or command prompt in this directory and run:

```bash
# Task 1: Calculator
gcc task1_calculator.c -o task1_calculator

# Task 2: Matrix Operations
gcc task2_matrix.c -o task2_matrix

# Task 3: Student Management System
gcc task3_student_management.c -o task3_student_management
```

### 2. Run the Programs

#### On Windows (PowerShell / Command Prompt):
```powershell
.\task1_calculator.exe
.\task2_matrix.exe
.\task3_student_management.exe
```

#### On Linux / macOS:
```bash
./task1_calculator
./task2_matrix
./task3_student_management
```

---

## Notes
- For **Task 3**, student records are persistently stored in a binary file named `students.dat` in the same directory.
- Input buffers are cleared where appropriate to prevent input skipping when reading strings and characters after numbers.
