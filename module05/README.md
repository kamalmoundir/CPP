# Module 05 - Repetition and Exceptions

## Overview
This module introduces exception handling in C++, teaching students how to handle errors gracefully and create robust applications. Students learn about try-catch blocks, exception classes, and exception safety.

## Learning Objectives
- Understand exception handling mechanisms
- Learn to throw and catch exceptions
- Master custom exception classes
- Practice exception safety principles
- Understand RAII in exception contexts
- Learn exception specifications and best practices

## Exception Handling Basics
- **try block**: Code that might throw exceptions
- **catch block**: Code that handles specific exceptions
- **throw statement**: Mechanism to raise exceptions
- **Exception classes**: Custom types for specific errors
- **Stack unwinding**: Automatic cleanup during exception propagation

## Exercises

### Exercise 00: Mommy, When I Grow Up, I Want to Be a Bureaucrat!
**Files:** `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`

Basic exception handling and custom exception classes:
- Bureaucrat class with grade validation
- Custom exception classes for grade errors
- Constructor validation with exceptions
- Member function error handling

**Key Concepts:**
- Custom exception class design
- Constructor validation
- Exception throwing from methods
- Basic try-catch usage
- Exception inheritance from std::exception

**Bureaucrat Features:**
- Name (const, cannot be changed)
- Grade (1-150, 1 is highest)
- Increment/decrement grade with validation
- Custom exceptions for invalid grades

**Custom Exceptions:**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw();
};
```

### Exercise 01: Form Up, Maggots!
**Files:** Previous files plus `Form.hpp`, `Form.cpp`

Exception handling in object interactions:
- Form class with signing requirements
- Bureaucrat-Form interaction with validation
- Exception handling in complex operations
- Multiple exception types for different errors

**Key Concepts:**
- Object interaction validation
- Multiple exception types
- Exception handling in member functions
- Permission-based operations
- State validation before operations

**Form Features:**
- Name (const)
- Signed status (boolean)
- Grade required to sign
- Grade required to execute
- Can only be signed by qualified bureaucrats

**Form Exceptions:**
- GradeTooHighException
- GradeTooLowException
- FormAlreadySignedException (custom addition)

### Exercise 02: No, You Need Form 28B, Not 28C...
**Files:** Previous files plus `ShrubberyCreationForm.hpp`, `ShrubberyCreationForm.cpp`, `RobotomyRequestForm.hpp`, `RobotomyRequestForm.cpp`, `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp`

Inheritance with exception handling:
- Abstract base Form class
- Concrete form implementations
- Polymorphic exception handling
- File operations with exception safety

**Key Concepts:**
- Abstract base classes with exceptions
- Polymorphic exception handling
- File operation exceptions
- Exception safety in file operations
- Different exception types for different operations

**Concrete Forms:**
- **ShrubberyCreationForm**: Creates ASCII tree files
  - Sign grade: 145, Execute grade: 137
  - File creation with exception handling
- **RobotomyRequestForm**: Simulates robotomy procedure
  - Sign grade: 72, Execute grade: 45
  - Random success/failure with exceptions
- **PresidentialPardonForm**: Presidential pardon
  - Sign grade: 25, Execute grade: 5
  - High-level operation simulation

### Exercise 03: At Least This Beats Coffee-Making
**Files:** Previous files plus `Intern.hpp`, `Intern.cpp`

Factory pattern with exception handling:
- Intern class that creates forms
- Form creation by name with validation
- Exception handling for unknown form types
- Factory method pattern implementation

**Key Concepts:**
- Factory pattern with exceptions
- String-based object creation
- Exception handling in factory methods
- Unknown type error handling
- Dynamic object creation validation

**Intern Features:**
- `makeForm(std::string formName, std::string target)` method
- Creates appropriate form based on name
- Throws exception for unknown form names
- Returns pointer to created form

## Exception Class Hierarchy
```
std::exception
    ├── Bureaucrat::GradeTooHighException
    ├── Bureaucrat::GradeTooLowException
    ├── Form::GradeTooHighException
    ├── Form::GradeTooLowException
    ├── Form::FormNotSignedException
    └── Intern::FormNotFoundException
```

## Exception Safety Levels
1. **No Guarantee**: Code may be left in invalid state
2. **Basic Guarantee**: No resource leaks, objects in valid state
3. **Strong Guarantee**: Operation succeeds or has no effect
4. **No-throw Guarantee**: Operation never throws exceptions

## Exception Handling Best Practices
```cpp
// Proper exception handling
try {
    Bureaucrat bob("Bob", 5);
    Form* form = intern.makeForm("shrubbery creation", "garden");
    bob.signForm(*form);
    bob.executeForm(*form);
    delete form;
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Cleanup if necessary
}
```

## RAII and Exception Safety
```cpp
class SafeForm {
    std::ofstream file;
public:
    SafeForm(const std::string& filename) : file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file");
        }
    }
    // Destructor automatically closes file
    // Even if exception occurs
    ~SafeForm() {
        if (file.is_open()) {
            file.close();
        }
    }
};
```

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Exception Handling**: try-catch-throw mechanism
2. **Custom Exceptions**: Inheriting from std::exception
3. **Exception Safety**: RAII and resource management
4. **Exception Specifications**: throw() declarations
5. **Stack Unwinding**: Automatic cleanup during exceptions
6. **Factory Pattern**: Object creation with exception handling
7. **Polymorphic Exceptions**: Catching base class references
8. **File Operations**: Exception-safe file handling

## Exception Handling Patterns
### Custom Exception Design:
```cpp
class MyException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "My custom error message";
    }
};
```

### Exception-Safe Resource Management:
```cpp
void safeFunction() {
    Resource* resource = new Resource();
    try {
        // Operations that might throw
        riskyOperation(resource);
        delete resource;  // Normal cleanup
    } catch (...) {
        delete resource;  // Exception cleanup
        throw;           // Re-throw
    }
}
```

### Factory with Exception Handling:
```cpp
Form* createForm(const std::string& type) {
    if (type == "shrubbery") {
        return new ShrubberyCreationForm();
    }
    throw UnknownFormException();
}
```

## Common Exception Scenarios
- Constructor validation failures
- Invalid parameter values
- Resource allocation failures
- File operation errors
- Permission or state violations
- Unknown type or identifier requests

## Important Notes
- Always inherit custom exceptions from std::exception
- Use const references when catching exceptions
- Implement what() method for meaningful error messages
- Consider exception safety levels in design
- Use RAII for automatic resource cleanup
- Don't throw exceptions from destructors
- Catch specific exceptions before general ones
- Re-throw exceptions when appropriate (throw; without parameter)
