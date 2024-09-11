# Dynamic Library Management System

## Overview

The **Dynamic Library Management System** is a C programming project designed to manage a collection of books dynamically. This system allows users to add, search, edit, delete, and sort books, all while utilizing advanced string and pointer operations. The system is implemented using structures and dynamic memory management to handle a growing number of books efficiently.

## Features

- **Dynamic Book Management**: Add and remove books from the system, with dynamic resizing of the underlying data structures.
- **Search Functionality**: Search for books by title, author, or ISBN.
- **Book Editing**: Modify details of existing books.
- **Sorting**: Sort books by title or author.
- **File Persistence**: Save and load library data to and from files, ensuring data persistence between sessions.
- **User-Friendly Interface**: Command-line interface for easy interaction with the system.

## Concepts Used

### Data Structures

- **Book Structure**: Represents each book with its title, author, ISBN, and availability status.

  ```c
  typedef struct {
      char *title;
      char *author;
      char *ISBN;
      int available; // 1 for available, 0 for borrowed
  } Book;
  ```

- **Library Structure**: Manages an array of `Book` structures, including dynamic resizing.

  ```c
  typedef struct {
      Book *books;
      int size;
      int capacity;
  } Library;
  ```

### Memory Management

- **Dynamic Allocation**: Utilizes `malloc` and `realloc` to dynamically manage memory for book arrays, ensuring efficient storage as the number of books grows.
- **Memory Deallocation**: Properly frees allocated memory to prevent memory leaks.

### String Handling

- **String Operations**: Uses functions such as `strcpy`, `strcmp`, and custom string manipulation functions to handle book titles, authors, and ISBNs.
- **Pointer Manipulation**: Advanced string operations are performed using pointers for efficient data handling.

### Sorting Algorithms

- **Sorting**: Implements sorting algorithms (e.g., bubble sort, quicksort) to order books by title or author, with updates to maintain consistency across parallel arrays.

### File Handling

- **Persistence**: Implements file operations to save and load library data, ensuring that data is retained between program runs.
