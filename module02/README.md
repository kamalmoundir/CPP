# Module 02 - Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form

## Overview
This module introduces ad-hoc polymorphism through operator overloading and the Orthodox Canonical Class Form. Students learn to create robust classes that behave like built-in types and understand fixed-point number representation.

## Learning Objectives
- Understand ad-hoc polymorphism and operator overloading
- Master the Orthodox Canonical Class Form (Coplien's form)
- Learn fixed-point arithmetic implementation
- Practice deep copy vs shallow copy
- Understand operator precedence and associativity
- Implement comparison and arithmetic operators

## Orthodox Canonical Class Form
Every class should implement these four essential methods:
1. **Default Constructor**: `ClassName()`
2. **Copy Constructor**: `ClassName(const ClassName& other)`
3. **Copy Assignment Operator**: `ClassName& operator=(const ClassName& other)`
4. **Destructor**: `~ClassName()`

## Exercises

### Exercise 00: My First Orthodox Canonical Class
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`

Basic implementation of Orthodox Canonical Class Form:
- Fixed-point number class with 8 fractional bits
- Raw bits storage and manipulation
- Constructor and destructor messages
- Copy constructor and assignment operator

**Key Concepts:**
- Orthodox Canonical Class Form implementation
- Fixed-point number representation
- Copy semantics
- Raw bit manipulation
- Constructor/destructor order

**Class Members:**
- `_rawBits`: Integer storing the fixed-point value
- `_fractionalBits`: Static constant (8 bits)
- `getRawBits()`: Returns raw value
- `setRawBits()`: Sets raw value

### Exercise 01: Towards a More Useful Fixed-Point Number Class
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`

Enhanced Fixed class with conversions:
- Float to fixed-point conversion
- Integer to fixed-point conversion
- Fixed-point to float conversion
- Fixed-point to integer conversion
- Output stream operator overloading

**Key Concepts:**
- Type conversion constructors
- Conversion member functions
- Operator overloading (`<<`)
- Fixed-point arithmetic principles
- Bit shifting for multiplication/division by powers of 2

**New Constructors:**
- `Fixed(const int value)`: Convert integer to fixed-point
- `Fixed(const float value)`: Convert float to fixed-point

**New Methods:**
- `toInt()`: Convert to integer
- `toFloat()`: Convert to float
- `operator<<`: Stream insertion operator

### Exercise 02: Now We're Talking
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`

Complete operator overloading implementation:
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/decrement: `++`, `--` (prefix and postfix)
- Min/max static functions

**Key Concepts:**
- Comprehensive operator overloading
- Prefix vs postfix increment/decrement
- Static member functions
- Operator precedence respect
- Const correctness in operators

**Comparison Operators:**
```cpp
bool operator>(const Fixed& rhs) const;
bool operator<(const Fixed& rhs) const;
bool operator>=(const Fixed& rhs) const;
bool operator<=(const Fixed& rhs) const;
bool operator==(const Fixed& rhs) const;
bool operator!=(const Fixed& rhs) const;
```

**Arithmetic Operators:**
```cpp
Fixed operator+(const Fixed& rhs) const;
Fixed operator-(const Fixed& rhs) const;
Fixed operator*(const Fixed& rhs) const;
Fixed operator/(const Fixed& rhs) const;
```

**Increment/Decrement:**
```cpp
Fixed& operator++();     // prefix
Fixed operator++(int);   // postfix
Fixed& operator--();     // prefix
Fixed operator--(int);   // postfix
```

**Static Functions:**
```cpp
static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);
```

### Exercise 03: BSP (Binary Space Partitioning)
**Files:** `Point.hpp`, `Point.cpp`, `Fixed.hpp`, `Fixed.cpp`, `bsp.cpp`, `main.cpp`

Practical application using the Fixed class:
- Point class with Fixed coordinates
- Binary Space Partitioning algorithm
- Point-in-triangle determination
- Geometric calculations using fixed-point arithmetic

**Key Concepts:**
- Using custom classes in algorithms
- Geometric calculations
- Fixed-point precision in real applications
- Binary Space Partitioning principles

**Point Class:**
- Two Fixed coordinates (x, y)
- Orthodox Canonical Class Form
- Const members (immutable after construction)

**BSP Function:**
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

## Fixed-Point Arithmetic
Fixed-point numbers represent fractional values using integers:
- **Integer part**: High-order bits
- **Fractional part**: Low-order bits
- **Scale factor**: 2^(fractional bits)

Example with 8 fractional bits:
- Value 42.42 → Raw bits: 42.42 × 256 = 10859
- Raw bits 10859 → Value: 10859 ÷ 256 = 42.42

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Orthodox Canonical Class Form**: Essential class methods
2. **Operator Overloading**: Making classes behave like built-in types
3. **Type Conversions**: Implicit and explicit conversions
4. **Const Correctness**: Proper use of const in methods and parameters
5. **Static Functions**: Class-level utility functions
6. **Copy Semantics**: Deep vs shallow copying
7. **Stream Operators**: Integration with iostream
8. **Fixed-Point Arithmetic**: Alternative to floating-point

## Operator Overloading Best Practices
- Return types should match expected behavior
- Maintain operator semantics (+ should add, not subtract)
- Use const correctness appropriately
- Consider efficiency (avoid unnecessary copies)
- Implement related operators consistently
- Follow convention for increment/decrement operators
- Make operators symmetric when possible

## Important Notes
- Fixed-point arithmetic provides deterministic results
- Useful in systems where floating-point is unreliable
- Operator overloading should maintain intuitive behavior
- Always implement the complete Orthodox Canonical Class Form
- Be careful with integer overflow in fixed-point calculations
- Prefix increment/decrement is generally more efficient than postfix
