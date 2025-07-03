# Module 07 - C++ Templates

## Overview
This module introduces C++ templates, a powerful feature for generic programming. Students learn to write code that works with different types, understand template instantiation, and explore the Standard Template Library (STL) foundations.

## Learning Objectives
- Understand template syntax and instantiation
- Master function templates and class templates
- Learn template specialization
- Practice generic programming principles
- Explore STL containers and iterators
- Understand template compilation model

## Template Basics
Templates allow you to write generic code that works with different types:
- **Function Templates**: Generic functions
- **Class Templates**: Generic classes
- **Template Parameters**: Type and non-type parameters
- **Template Instantiation**: Compiler generates specific code for each type
- **Template Specialization**: Custom implementations for specific types

## Exercises

### Exercise 00: Start with a Few Functions
**Files:** `whatever.hpp`, `main.cpp`

Basic function templates:
- Template functions for common operations
- Type deduction and explicit instantiation
- Template parameter constraints
- Generic algorithms

**Key Concepts:**
- Function template syntax
- Template type deduction
- Template instantiation
- Generic programming principles
- Template parameter requirements

**Template Functions to Implement:**
```cpp
template<typename T>
void swap(T& a, T& b);

template<typename T>
const T& min(const T& a, const T& b);

template<typename T>
const T& max(const T& a, const T& b);
```

**Usage Examples:**
```cpp
int a = 2, b = 3;
swap(a, b);           // Template type deduction
std::cout << min(a, b) << std::endl;  // Works with int

float x = 2.5f, y = 3.7f;
std::cout << max(x, y) << std::endl;  // Works with float

std::string s1 = "hello", s2 = "world";
swap(s1, s2);         // Works with strings
```

### Exercise 01: Iter
**Files:** `iter.hpp`, `main.cpp`

Template function that applies a function to array elements:
- Template function taking array, length, and function
- Function pointer parameters
- Template instantiation with different types
- Generic iteration pattern

**Key Concepts:**
- Template functions with function parameters
- Function pointer templates
- Array iteration patterns
- Template parameter deduction
- Generic algorithm design

**Template Function:**
```cpp
template<typename T, typename F>
void iter(T* array, size_t length, F function);
```

**Usage Examples:**
```cpp
int numbers[] = {1, 2, 3, 4, 5};
iter(numbers, 5, printElement);  // Apply printElement to each

std::string words[] = {"hello", "world"};
iter(words, 2, toUpperCase);     // Apply toUpperCase to each
```

### Exercise 02: Array
**Files:** `Array.hpp`, `Array.tpp`, `main.cpp`

Template class implementation:
- Generic array class with template parameter
- Dynamic memory management
- Copy constructor and assignment operator
- Bounds checking with exceptions
- Template class best practices

**Key Concepts:**
- Class template syntax
- Template class instantiation
- Template member functions
- Exception handling in templates
- Template compilation issues
- Template definition in headers

**Array Class Features:**
```cpp
template<typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();                           // Default constructor
    Array(unsigned int n);             // Constructor with size
    Array(const Array& other);         // Copy constructor
    ~Array();                          // Destructor
    Array& operator=(const Array& other); // Assignment operator
    
    T& operator[](unsigned int index);       // Element access
    const T& operator[](unsigned int index) const;
    
    unsigned int size() const;         // Get size
    
    // Exception class
    class OutOfBoundsException : public std::exception {
        virtual const char* what() const throw();
    };
};
```

**Template Usage:**
```cpp
Array<int> intArray(5);         // Array of 5 integers
Array<std::string> stringArray; // Empty string array

intArray[0] = 42;               // Element assignment
std::cout << intArray[0];       // Element access

try {
    intArray[10] = 5;           // Throws OutOfBoundsException
} catch (const std::exception& e) {
    std::cout << e.what();
}
```

## Template Syntax and Concepts

### Function Template Declaration:
```cpp
template<typename T>
T add(const T& a, const T& b) {
    return a + b;
}

// Alternative syntax
template<class T>
T multiply(const T& a, const T& b) {
    return a * b;
}
```

### Class Template Declaration:
```cpp
template<typename T>
class Container {
private:
    T data;
public:
    Container(const T& value) : data(value) {}
    T getValue() const { return data; }
    void setValue(const T& value) { data = value; }
};
```

### Template Instantiation:
```cpp
// Explicit instantiation
Container<int> intContainer(42);
Container<std::string> stringContainer("hello");

// Function template - type deduction
int result = add(5, 10);        // T deduced as int
double result2 = add(3.14, 2.86); // T deduced as double
```

## Template Compilation Model
Templates are compiled when instantiated, not when declared:
1. **Declaration**: Template syntax is checked
2. **Instantiation**: Compiler generates code for specific type
3. **Definition Required**: Template definitions must be visible at instantiation point
4. **Header Files**: Template definitions typically go in headers

## Template Specialization
```cpp
// Primary template
template<typename T>
class TypePrinter {
public:
    void print() { std::cout << "Unknown type"; }
};

// Specialization for int
template<>
class TypePrinter<int> {
public:
    void print() { std::cout << "Integer type"; }
};
```

## STL Foundation Concepts
Templates are the foundation of the Standard Template Library:
- **Containers**: vector, list, map, etc.
- **Iterators**: Generic way to traverse containers
- **Algorithms**: Generic functions that work with iterators
- **Function Objects**: Templates for callable objects

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Function Templates**: Generic functions with type parameters
2. **Class Templates**: Generic classes with type parameters
3. **Template Instantiation**: Compiler code generation
4. **Type Deduction**: Automatic type inference
5. **Template Compilation**: Two-phase compilation model
6. **Generic Programming**: Writing type-independent code
7. **Template Parameters**: Type and non-type parameters
8. **Template Specialization**: Custom implementations for specific types

## Template Best Practices
- Put template definitions in header files
- Use meaningful template parameter names
- Provide clear error messages for template constraints
- Consider template specialization for optimization
- Use const-correctness in template parameters
- Design templates for maximum reusability
- Document template requirements and constraints

## Common Template Pitfalls
- Template definitions in .cpp files (linking errors)
- Forgetting to include template definitions
- Template compilation error messages can be cryptic
- Template instantiation can increase binary size
- Template parameter naming conflicts
- Not considering template argument deduction rules

## Template Error Handling
```cpp
template<typename T>
class SafeArray {
    T* data;
    size_t _size;
public:
    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};
```

## Template Requirements
Templates work with types that provide required operations:
```cpp
template<typename T>
T maximum(const T& a, const T& b) {
    return (a > b) ? a : b;  // Requires operator>
}
```

## Important Notes
- Templates are instantiated at compile time for each unique type
- Template definitions must be visible at instantiation point
- Template code is type-checked when instantiated, not when declared
- Templates provide zero-overhead abstraction when used properly
- Template parameters can be types, values, or other templates
- Templates are the foundation of modern C++ generic programming
- C++98 templates are more limited than modern C++ but still powerful
- Template compilation can significantly increase build times
