# C Programming Projects

A selection of **C** programs written in a Linux environment for my C programming course (B.Sc. in Computer Science, Netanya Academic College).

They go from recursion and array algorithms to pointers, dynamic memory, function pointers and multi-file programs with a static library.

**Skills shown:** C, Linux, GCC, recursion, algorithms and complexity, pointers (including `char ***`), dynamic memory (`malloc` / `free`), generic programming with `void *` and function pointers, variadic functions (`stdarg.h`), header files and static libraries (`ar`), standard input processing.

---

## 📂 Projects

### 01 – Recursion on digits
Recursive functions on the digits of a number: sum, search, count, maximum, count of even digits, checking if digits are sorted, sorting and merging digits, plus a variant of the **Tower of Hanoi**.

### 02 – Multi-file program with a static library
A program that builds a new number from the digits of a given number at the requested positions.
Split into several source files, with a **header file** (`myHeaders/utils.h`) and helper functions packaged as a **static library** (`libutils.a`). Input validation returns different exit codes for each error.

### 03 – Word count (`wc`-like)
Reads text from standard input until EOF and counts characters, words, lines, letters, digits and whitespace, similar to the Linux `wc` command.

### 04 – Array algorithms
- **Maximum subarray sum**, three ways:
  - brute force, O(n²) (`max_subarray_bruteforce.c`)
  - **Kadane's algorithm**, O(n) (`max_subarray_kadane.c`)
  - the same algorithm with a **variadic function** (`max_subarray_variadic.c`)
- **Subsequence check**: tests whether one array appears in order inside another (`is_subsequence.c`)

### 05 – Polynomial division
Divides two polynomials stored as coefficient arrays and prints the quotient and the remainder in readable form.

### 06 – Sorting strings with a triple pointer
Works on a `char ***` structure (a NULL-terminated array of NULL-terminated arrays of strings): prints all the strings, then sorts them alphabetically across all the groups using dynamic memory.

### 07 – Generic sort with function pointers
A generic sorting function, similar to `qsort`, that works on any type thanks to `void *`, the element size and a **comparison function pointer**. Tested on arrays of `int`, `double`, 2D `char` arrays and arrays of string pointers.

### 08 – Jagged array transpose
Prints the transpose of a jagged array (rows of different lengths, where the first cell of each row stores its length), using only pointer arithmetic.

---

## ▶️ How to compile and run (Linux)

Single-file projects:
```bash
gcc -Wall -o program file_name.c
./program
```

Project 02 (static library):
```bash
cd 02-Multi-File-Static-Library
gcc -c countDigits.c checkDigit.c reverse.c
ar rcs libutils.a countDigits.o checkDigit.o reverse.o
gcc -o program program.c -L. -lutils
./program
```

Project 03 (reads from standard input):
```bash
./program < some_text_file.txt
```

---

👩‍💻 **Sarah Assous** – Computer Science student
[LinkedIn](https://www.linkedin.com/in/sarah-assous)
