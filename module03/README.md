# Module 03 - Inheritance

## Overview
This module introduces inheritance, one of the fundamental pillars of Object-Oriented Programming. Students learn about class hierarchies, method overriding, access specifiers, and the relationship between base and derived classes.

## Learning Objectives
- Understand inheritance concepts and terminology
- Learn public, protected, and private inheritance
- Master method overriding and virtual functions
- Practice constructor and destructor call order
- Understand the "is-a" relationship
- Work with base class pointers and derived objects

## Inheritance Basics
- **Base Class (Parent)**: The class being inherited from
- **Derived Class (Child)**: The class that inherits from another
- **Access Specifiers**: public, protected, private
- **Method Overriding**: Redefining base class methods in derived classes
- **Constructor Chain**: Base constructors called before derived constructors
- **Destructor Chain**: Derived destructors called before base destructors

## Exercises

### Exercise 00: Aaaaand... OPEN!
**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`

Basic class implementation with attributes and methods:
- ClapTrap class with hit points, energy points, attack damage
- Attack, take damage, and repair functions
- Resource management (energy cost for actions)

**Key Concepts:**
- Basic class design
- Member variable management
- Method implementation
- State validation and limits

**ClapTrap Features:**
- 10 hit points, 10 energy points, 0 attack damage
- Can attack (costs 1 energy)
- Can take damage (reduces hit points)
- Can be repaired (costs 1 energy, increases hit points)
- Cannot act when no hit points or energy

### Exercise 01: Serena, My Love!
**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `main.cpp`

Introduction to inheritance:
- ScavTrap inherits from ClapTrap
- Different default values for inherited attributes
- Method overriding for specialized behavior
- Additional unique methods

**Key Concepts:**
- Public inheritance
- Constructor and destructor call order
- Method overriding
- Inherited member access
- Specialized behavior in derived classes

**ScavTrap Features:**
- 100 hit points, 50 energy points, 20 attack damage
- Overridden attack() method with different message
- Special ability: guardGate()
- Maintains ClapTrap interface while extending functionality

### Exercise 02: Repetitive Work
**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `main.cpp`

Multiple inheritance chains:
- FragTrap also inherits from ClapTrap
- Different attributes and behaviors
- Method overriding with unique implementations
- Parallel inheritance hierarchies

**Key Concepts:**
- Multiple derived classes from same base
- Independent inheritance paths
- Method specialization per derived class
- Code reuse through inheritance

**FragTrap Features:**
- 100 hit points, 100 energy points, 30 attack damage
- Overridden attack() method
- Special ability: highFivesGuys()
- Different specialization than ScavTrap

### Exercise 03: Now It's Weird!
**Files:** All previous files plus `DiamondTrap.hpp`, `DiamondTrap.cpp`

Diamond inheritance problem and virtual inheritance:
- DiamondTrap inherits from both ScavTrap and FragTrap
- Virtual inheritance to solve diamond problem
- Attribute selection from different parents
- Method resolution and overriding

**Key Concepts:**
- Multiple inheritance
- Diamond inheritance problem
- Virtual inheritance solution
- Method resolution order
- Attribute shadowing and selection

**DiamondTrap Features:**
- Inherits hit points from FragTrap
- Inherits energy points from ScavTrap
- Inherits attack damage from FragTrap
- Uses ScavTrap's attack() method
- Special ability: whoAmI()
- Has both ClapTrap name and DiamondTrap name

## Constructor and Destructor Order
### Single Inheritance (ScavTrap):
```
Construction: ClapTrap → ScavTrap
Destruction:  ScavTrap → ClapTrap
```

### Multiple Inheritance (DiamondTrap):
```
Construction: ClapTrap → ScavTrap → FragTrap → DiamondTrap
Destruction:  DiamondTrap → FragTrap → ScavTrap → ClapTrap
```

## Access Specifiers in Inheritance
- **public inheritance**: "is-a" relationship, maintains interface
- **protected inheritance**: Rarely used, converts public to protected
- **private inheritance**: "implemented-in-terms-of" relationship

## Method Overriding
```cpp
// Base class
class ClapTrap {
public:
    void attack(const std::string& target);  // Base implementation
};

// Derived class
class ScavTrap : public ClapTrap {
public:
    void attack(const std::string& target);  // Overridden implementation
};
```

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Public Inheritance**: "is-a" relationship
2. **Method Overriding**: Specialized behavior in derived classes
3. **Constructor/Destructor Chains**: Object lifecycle in hierarchies
4. **Multiple Inheritance**: Inheriting from multiple base classes
5. **Diamond Problem**: Ambiguity in multiple inheritance
6. **Virtual Inheritance**: Solution to diamond problem
7. **Access Control**: public, protected, private in inheritance
8. **Code Reuse**: Sharing implementation through inheritance

## Inheritance Best Practices
- Use public inheritance for "is-a" relationships
- Override methods to specialize behavior
- Call base class constructors explicitly when needed
- Be careful with multiple inheritance complexity
- Use virtual inheritance to solve diamond problems
- Consider composition as alternative to inheritance
- Make destructors virtual in base classes (covered in Module 04)

## Common Pitfalls
- Forgetting to call base class constructors
- Not understanding constructor/destructor order
- Diamond inheritance without virtual inheritance
- Confusing method overriding with method overloading
- Using inheritance when composition would be better
- Not considering object slicing issues

## Important Notes
- Inheritance creates "is-a" relationships
- Derived objects can be used wherever base objects are expected
- Method overriding allows specialization of behavior
- Multiple inheritance should be used carefully
- Virtual inheritance solves diamond problem but adds complexity
- Always consider whether inheritance is the right tool for the job
