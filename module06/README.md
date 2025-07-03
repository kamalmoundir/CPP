# Module 06 - C++ Casts

## Overview
This module introduces the different types of casting in C++, moving beyond C-style casts to more specific and safer C++ casting operators. Students learn when and how to use each cast type appropriately.

## Learning Objectives
- Understand the problems with C-style casts
- Master the four C++ cast operators
- Learn type detection and conversion
- Practice safe casting techniques
- Understand serialization and deserialization
- Learn to work with scalar types and conversions

## C++ Cast Operators
C++ provides four specific cast operators that are safer and more expressive than C-style casts:
1. **static_cast**: Compile-time type conversions
2. **dynamic_cast**: Runtime type checking for polymorphic types
3. **const_cast**: Adding or removing const/volatile qualifiers
4. **reinterpret_cast**: Low-level bit pattern reinterpretation

## Exercises

### Exercise 00: Conversion of Scalar Types
**Files:** `Converter.hpp`, `Converter.cpp`, `main.cpp`

Type detection and conversion between scalar types:
- Detect input type (char, int, float, double)
- Convert to all scalar types where possible
- Handle impossible conversions gracefully
- Display appropriate error messages

**Key Concepts:**
- Type detection from string input
- Safe type conversions using static_cast
- Handling conversion edge cases
- Displaying conversion results
- Input validation and error handling

**Conversion Logic:**
```cpp
// Example conversions
Input: "42"     → char: '*', int: 42, float: 42.0f, double: 42.0
Input: "42.5f"  → char: impossible, int: 42, float: 42.5f, double: 42.5
Input: "a"      → char: 'a', int: 97, float: 97.0f, double: 97.0
```

**Special Cases:**
- Non-displayable characters
- Overflow/underflow scenarios
- Invalid input handling
- Infinity and NaN values

### Exercise 01: Serialization
**Files:** `Data.hpp`, `Serializer.hpp`, `Serializer.cpp`, `main.cpp`

Serialization using reinterpret_cast:
- Convert pointers to integers (serialization)
- Convert integers back to pointers (deserialization)
- Demonstrate pointer-integer conversion safety
- Validate round-trip conversion integrity

**Key Concepts:**
- reinterpret_cast for pointer-integer conversion
- Serialization and deserialization concepts
- uintptr_t for portable pointer storage
- Round-trip conversion validation
- Pointer arithmetic and memory addresses

**Serializer Functions:**
```cpp
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();  // Non-instantiable
};
```

**Usage Example:**
```cpp
Data originalData;
uintptr_t serialized = Serializer::serialize(&originalData);
Data* deserialized = Serializer::deserialize(serialized);
// deserialized should equal &originalData
```

### Exercise 02: Identify Real Type
**Files:** `Base.hpp`, `Base.cpp`, `A.hpp`, `A.cpp`, `B.hpp`, `B.cpp`, `C.hpp`, `C.cpp`, `main.cpp`

Dynamic type identification using dynamic_cast:
- Polymorphic base class with virtual destructor
- Three derived classes (A, B, C)
- Type identification by pointer and by reference
- Random object generation

**Key Concepts:**
- dynamic_cast for runtime type identification
- Polymorphic class hierarchies
- Type identification patterns
- Reference vs pointer casting
- Exception handling with dynamic_cast on references

**Base Class Hierarchy:**
```cpp
class Base {
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

**Type Identification Functions:**
```cpp
Base* generate();                    // Random A, B, or C
void identify(Base* p);              // Identify using pointers
void identify(Base& p);              // Identify using references
```

**Dynamic Cast Patterns:**
```cpp
// Pointer version (returns nullptr on failure)
if (dynamic_cast<A*>(ptr)) {
    std::cout << "A" << std::endl;
}

// Reference version (throws bad_cast on failure)
try {
    (void)dynamic_cast<A&>(ref);
    std::cout << "A" << std::endl;
} catch (const std::bad_cast&) {
    // Not type A
}
```

## Cast Operator Details

### static_cast
- **Purpose**: Safe compile-time conversions
- **Use cases**: Numeric conversions, base-to-derived (when safe), void* conversions
- **Safety**: Compile-time checking, but no runtime verification

```cpp
double d = 3.14;
int i = static_cast<int>(d);  // 3

Base* base = new Derived();
Derived* derived = static_cast<Derived*>(base);  // Dangerous if wrong type
```

### dynamic_cast
- **Purpose**: Safe runtime polymorphic conversions
- **Use cases**: Base-to-derived conversions, cross-casting in multiple inheritance
- **Requirements**: Polymorphic types (virtual functions)
- **Safety**: Runtime type checking

```cpp
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);  // Safe, returns nullptr if wrong
if (derived) {
    // Successful cast
}
```

### const_cast
- **Purpose**: Add or remove const/volatile qualifiers
- **Use cases**: Interfacing with legacy APIs, implementing const methods
- **Warning**: Modifying originally const data is undefined behavior

```cpp
const int* constPtr = &value;
int* nonConstPtr = const_cast<int*>(constPtr);  // Remove const
```

### reinterpret_cast
- **Purpose**: Low-level reinterpretation of bit patterns
- **Use cases**: Pointer-to-integer conversion, hardware interfaces, serialization
- **Warning**: Very dangerous, implementation-dependent

```cpp
int* ptr = &value;
uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);  // Pointer to integer
```

## Cast Safety Hierarchy
1. **static_cast**: Compile-time safe, well-defined conversions
2. **dynamic_cast**: Runtime safe, requires polymorphic types
3. **const_cast**: Qualifier changes only, behavior depends on original object
4. **reinterpret_cast**: No safety guarantees, implementation-dependent

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Type Safety**: Explicit casting for better type safety
2. **Runtime Type Information (RTTI)**: dynamic_cast and type identification
3. **Serialization**: Converting objects to storable formats
4. **Polymorphism**: Using virtual functions for type identification
5. **Exception Handling**: bad_cast exceptions
6. **Template Concepts**: Type detection and conversion patterns
7. **Memory Management**: Pointer-integer conversions
8. **Const Correctness**: const_cast for qualifier manipulation

## Best Practices for Casting
- Prefer C++ casts over C-style casts for clarity and safety
- Use static_cast for well-defined conversions
- Use dynamic_cast for polymorphic type checking
- Avoid const_cast unless absolutely necessary
- Be extremely careful with reinterpret_cast
- Always check dynamic_cast results when using pointers
- Use exceptions appropriately with reference dynamic_cast

## Common Pitfalls
- Using C-style casts instead of appropriate C++ casts
- Not checking dynamic_cast return values
- Modifying originally const data after const_cast
- Platform-dependent behavior with reinterpret_cast
- Assuming static_cast provides runtime type safety
- Forgetting that dynamic_cast requires virtual functions

## When to Use Each Cast
- **static_cast**: Numeric conversions, known safe pointer conversions
- **dynamic_cast**: Unknown polymorphic type conversions, type checking
- **const_cast**: Interfacing with APIs that aren't const-correct
- **reinterpret_cast**: Low-level operations, serialization, hardware interfaces

## Important Notes
- C++ casts are more explicit and searchable than C-style casts
- dynamic_cast requires at least one virtual function in the class hierarchy
- Serialization with reinterpret_cast is implementation-dependent
- Type identification should use dynamic_cast rather than typeid when possible
- Always prefer the most restrictive cast that accomplishes your goal
- C++ casts make code intent clearer and enable better compiler checking
