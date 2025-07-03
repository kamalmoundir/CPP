# Module 00 - C++ Introduction and Basic Concepts

## Overview
This module introduces the basic concepts of C++ programming, including namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other basic C++ fundamentals.

## Learning Objectives
- Understand C++ namespaces and their usage
- Learn about classes and objects in C++
- Work with member functions and constructors
- Practice using stdio streams (iostream)
- Understand initialization lists
- Learn about static and const keywords

## Exercises

### Exercise 00: Megaphone
**Files:** `megaphone.cpp`

A simple program that demonstrates:
- Command-line argument handling
- String manipulation
- Character case conversion using `std::toupper()`
- Basic iostream usage

**Usage:**
```bash
./megaphone "hello world"
```
The program converts all arguments to uppercase and outputs them. If no arguments are provided, it outputs a default loud message.

### Exercise 01: My Awesome PhoneBook
**Files:** `PhoneBook.hpp`, `PhoneBook.cpp`, `Contact.hpp`, `Contact.cpp`, `Main.cpp`

A phonebook application that demonstrates:
- Class design and implementation
- Private and public members
- Object arrays and data storage
- User input handling
- String formatting and display

**Features:**
- Store up to 8 contacts
- ADD command: Add a new contact
- SEARCH command: Display and search contacts
- EXIT command: Quit the program
- Contact information includes: first name, last name, nickname, phone number, darkest secret

**Usage:**
```bash
./phonebook
```

### Exercise 02: The Job of Your Dreams
**Files:** `Account.hpp`, `Account.cpp`, `tests.cpp`

Recreate missing source code based on provided header file and log file:
- Implement the Account class methods
- Handle static members and methods
- Manage account transactions and display
- Match exact output format from the log file

**Key Concepts:**
- Static member variables and functions
- Timestamp formatting
- Account balance management
- Transaction logging

## Compilation
All exercises include Makefiles with the following flags:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Namespaces**: `std::`
2. **Classes and Objects**: Basic OOP principles
3. **Member Functions**: Public and private methods
4. **Constructors and Destructors**: Object lifecycle
5. **Static Members**: Class-level data and functions
6. **Const Correctness**: Immutable data and functions
7. **Stream I/O**: `std::cout`, `std::cin`, `std::getline`
8. **String Manipulation**: C++ string class usage

## Important Notes
- All code follows C++98 standard
- No external libraries allowed (except standard library)
- Memory management is handled automatically for basic types
- Focus on understanding fundamental C++ syntax and concepts
