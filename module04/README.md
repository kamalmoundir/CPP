# Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces

## Overview
This module explores subtype polymorphism through virtual functions, abstract classes, and interfaces. Students learn about dynamic binding, pure virtual functions, and how to create flexible, extensible class hierarchies.

## Learning Objectives
- Understand virtual functions and dynamic binding
- Master abstract classes and pure virtual functions
- Learn interface design patterns
- Practice polymorphic behavior through base class pointers
- Understand virtual destructors and their importance
- Implement deep copy for complex objects

## Polymorphism Types
- **Compile-time Polymorphism**: Function/operator overloading (covered in Module 02)
- **Runtime Polymorphism**: Virtual functions and inheritance (this module)

## Exercises

### Exercise 00: Polymorphism
**Files:** `Animal.hpp`, `Animal.cpp`, `Dog.hpp`, `Dog.cpp`, `Cat.hpp`, `Cat.cpp`, `WrongAnimal.hpp`, `WrongAnimal.cpp`, `WrongCat.hpp`, `WrongCat.cpp`, `main.cpp`

Introduction to virtual functions and polymorphism:
- Animal base class with virtual `makeSound()`
- Dog and Cat derived classes with specific sounds
- Wrong classes to demonstrate non-virtual behavior
- Virtual destructor importance

**Key Concepts:**
- Virtual function declaration and overriding
- Dynamic binding vs static binding
- Virtual destructor necessity
- Polymorphic behavior through base pointers
- Method resolution at runtime

**Virtual vs Non-Virtual Comparison:**
```cpp
// Virtual (correct polymorphism)
Animal* animal = new Dog();
animal->makeSound(); // Calls Dog::makeSound()

// Non-virtual (static binding)
WrongAnimal* wrong = new WrongCat();
wrong->makeSound(); // Calls WrongAnimal::makeSound()
```

### Exercise 01: I Don't Want to Set the World on Fire
**Files:** Previous files plus `Brain.hpp`, `Brain.cpp`

Deep copy and complex object composition:
- Brain class with array of ideas
- Dog and Cat classes contain Brain objects
- Deep copy implementation in copy constructor and assignment
- Memory management for composed objects

**Key Concepts:**
- Object composition with dynamic allocation
- Deep copy vs shallow copy
- Copy constructor and assignment operator for complex objects
- Memory management in class hierarchies
- RAII (Resource Acquisition Is Initialization)

**Brain Class:**
- Array of 100 string ideas
- Deep copy semantics
- Proper memory management

**Animal Composition:**
- Dogs and Cats have Brain objects
- Brain allocated on heap
- Proper cleanup in destructors
- Deep copy ensures independence

### Exercise 02: Abstract Class
**Files:** Previous files modified, `AbstractAnimal.hpp`, `AbstractAnimal.cpp`

Pure virtual functions and abstract classes:
- AbstractAnimal with pure virtual `makeSound()`
- Cannot instantiate abstract classes
- Derived classes must implement pure virtual functions
- Interface-like behavior

**Key Concepts:**
- Pure virtual functions (`= 0`)
- Abstract classes (classes with pure virtual functions)
- Interface implementation requirements
- Cannot instantiate abstract classes
- Derived class obligations

**Pure Virtual Function:**
```cpp
class AbstractAnimal {
public:
    virtual void makeSound() const = 0;  // Pure virtual
    virtual ~AbstractAnimal();           // Virtual destructor
};
```

### Exercise 03: Interface & Recap
**Files:** `AMateria.hpp`, `AMateria.cpp`, `Character.hpp`, `Character.cpp`, `ICharacter.hpp`, `IMateriaSource.hpp`, `MateriaSource.hpp`, `MateriaSource.cpp`, `Ice.hpp`, `Ice.cpp`, `Cure.hpp`, `Cure.cpp`, `main.cpp`

Complex interface design and implementation:
- Multiple interfaces (ICharacter, IMateriaSource)
- Abstract base class (AMateria)
- Concrete implementations with polymorphic behavior
- Memory management for dynamic objects
- Clone pattern implementation

**Key Concepts:**
- Interface design patterns
- Multiple inheritance from interfaces
- Clone pattern for object copying
- Complex polymorphic systems
- Memory management in complex hierarchies
- Factory pattern elements

**Interface Examples:**
```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

## Virtual Function Mechanism
1. **Virtual Table (vtable)**: Each class with virtual functions has a table of function pointers
2. **Virtual Pointer (vptr)**: Each object has a pointer to its class's vtable
3. **Dynamic Binding**: Function calls resolved at runtime using vtable lookup
4. **Performance**: Small overhead for flexibility

## Abstract Classes vs Interfaces
### Abstract Classes:
- Can have both virtual and pure virtual functions
- Can have member variables
- Can provide default implementations
- Used when classes share common implementation

### Interfaces:
- Only pure virtual functions
- No member variables (except static const)
- No implementation details
- Used to define contracts/protocols

## Deep Copy Implementation
```cpp
class Animal {
private:
    Brain* brain;
public:
    // Copy constructor
    Animal(const Animal& other) {
        brain = new Brain(*other.brain);  // Deep copy
    }
    
    // Assignment operator
    Animal& operator=(const Animal& other) {
        if (this != &other) {
            delete brain;
            brain = new Brain(*other.brain);  // Deep copy
        }
        return *this;
    }
    
    // Destructor
    ~Animal() {
        delete brain;
    }
};
```

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **Virtual Functions**: Runtime polymorphism
2. **Pure Virtual Functions**: Abstract class requirements
3. **Virtual Destructors**: Proper cleanup in hierarchies
4. **Abstract Classes**: Classes that cannot be instantiated
5. **Interfaces**: Pure virtual function collections
6. **Deep Copy**: Complex object duplication
7. **Dynamic Binding**: Runtime method resolution
8. **Clone Pattern**: Object self-duplication

## Virtual Function Best Practices
- Always make destructors virtual in base classes
- Use pure virtual functions for interface requirements
- Prefer composition over inheritance when appropriate
- Implement deep copy for classes with dynamic resources
- Consider performance implications of virtual calls
- Design interfaces carefully for future extensibility

## Memory Management in Polymorphic Hierarchies
- Virtual destructors ensure proper cleanup
- Deep copy prevents sharing of dynamic resources
- RAII principles for automatic resource management
- Consider smart pointers for automatic memory management
- Be careful with object slicing

## Common Design Patterns
1. **Interface Pattern**: Pure virtual base classes
2. **Template Method**: Base class defines algorithm, derived classes implement steps
3. **Factory Method**: Virtual functions for object creation
4. **Clone Pattern**: Virtual functions for object copying

## Important Notes
- Virtual functions enable runtime polymorphism
- Pure virtual functions create abstract classes
- Virtual destructors are essential in inheritance hierarchies
- Deep copy is necessary for classes with dynamic resources
- Interfaces provide contracts for implementations
- Abstract classes can provide partial implementations
- Virtual function calls have small performance overhead
- Design for extensibility and maintainability
