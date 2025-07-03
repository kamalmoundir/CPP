# Module 01 - Memory Allocation, Pointers, References

## Overview
This module focuses on memory allocation, pointers to members, references, and the switch statement. Students learn the differences between stack and heap allocation, and when to use each approach.

## Learning Objectives
- Understand dynamic memory allocation in C++
- Learn the differences between stack and heap memory
- Master pointers and references
- Practice proper memory management
- Understand the difference between pointers and references
- Work with member function pointers

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ
**Files:** `Zombie.hpp`, `Zombie.cpp`, `main.cpp`, `newZombie.cpp`, `randomChump.cpp`

Demonstrates memory allocation strategies:
- **Stack allocation**: `randomChump()` - creates zombie on stack (automatic cleanup)
- **Heap allocation**: `newZombie()` - creates zombie on heap (manual cleanup required)

**Key Concepts:**
- Constructor and destructor timing
- Stack vs heap allocation
- Memory cleanup responsibility
- Object lifetime management

**Functions to implement:**
- `randomChump(std::string name)`: Creates zombie on stack
- `newZombie(std::string name)`: Creates zombie on heap
- `announce()`: Zombie announces itself

### Exercise 01: Moar brainz!
**Files:** `Zombie.hpp`, `Zombie.cpp`, `main.cpp`, `zombieHorde.cpp`

Focus on array allocation and initialization:
- Create a horde of N zombies
- Allocate array on heap
- Initialize all zombies with names
- Proper cleanup of entire array

**Key Concepts:**
- Array allocation with `new[]`
- Array deallocation with `delete[]`
- Object initialization in arrays
- Memory management for multiple objects

**Function to implement:**
- `zombieHorde(int N, std::string name)`: Creates array of N zombies

### Exercise 02: HI THIS IS BRAIN
**Files:** `main.cpp`

Demonstrates pointers and references:
- String variable
- Pointer to string
- Reference to string
- Memory addresses and values

**Key Concepts:**
- Pointer declaration and usage (`*`)
- Reference declaration and usage (`&`)
- Memory address access
- Difference between pointers and references

### Exercise 03: Unnecessary Violence
**Files:** `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `main.cpp`

Object composition and reference vs pointer usage:
- **HumanA**: Always has a weapon (reference)
- **HumanB**: May not have a weapon (pointer)

**Key Concepts:**
- Object composition
- References vs pointers for object relationships
- Constructor initialization lists
- Optional object relationships

### Exercise 04: Sed is for Losers
**Files:** `main.cpp`

File manipulation and string replacement:
- Open and read files
- String search and replace
- File output
- Error handling

**Key Concepts:**
- File stream operations (`std::ifstream`, `std::ofstream`)
- String manipulation without regex
- Error handling for file operations
- Command-line argument processing

**Usage:**
```bash
./sed_replacement filename s1 s2
```

### Exercise 05: Harl 2.0
**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`

Function pointers and method dispatch:
- Array of member function pointers
- String-to-function mapping
- Clean alternative to switch statements

**Key Concepts:**
- Member function pointers
- Function pointer arrays
- String comparison for method selection
- Object method dispatch

**Harl levels:**
- DEBUG: Detailed diagnostic information
- INFO: General information
- WARNING: Warning messages
- ERROR: Error conditions

### Exercise 06: Harl Filter
**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`

Switch statement usage and level filtering:
- Filter messages by minimum level
- Use switch statement with fall-through
- Command-line level specification

**Key Concepts:**
- Switch statement syntax
- Fall-through behavior
- String-to-enum conversion
- Level-based filtering

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Memory Management**: `new` and `delete` operators
2. **Pointers vs References**: When and how to use each
3. **Object Lifetime**: Stack vs heap allocation
4. **File I/O**: Reading and writing files
5. **Function Pointers**: Member function pointers
6. **String Manipulation**: Finding and replacing substrings
7. **Error Handling**: Basic exception scenarios
8. **Switch Statements**: Control flow with fall-through

## Memory Management Best Practices
- Use stack allocation when object lifetime is scope-limited
- Use heap allocation for objects that need to outlive their creation scope
- Always pair `new` with `delete`
- Always pair `new[]` with `delete[]`
- Consider object ownership and responsibility for cleanup
- Prefer references over pointers when object must exist
- Use pointers when object relationship is optional

## Important Notes
- Every `new` must have a corresponding `delete`
- References cannot be null and cannot be reassigned
- Pointers can be null and can be reassigned
- Always initialize pointers and references
- Be careful with object lifetime and dangling pointers
