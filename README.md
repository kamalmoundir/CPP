# C++ Programming Course - 42 School

## Overview
This repository contains a comprehensive C++ programming course consisting of 10 modules (00-09) that progressively teach modern C++ concepts from basic syntax to advanced template programming and STL usage. Each module builds upon the previous ones, creating a solid foundation in C++ programming.

## Course Structure

### 📚 Module Progression

| Module | Topic | Key Concepts | Difficulty |
|--------|-------|--------------|------------|
| [Module 00](module00/) | C++ Introduction | Namespaces, Classes, I/O, Static, Const | ⭐ |
| [Module 01](module01/) | Memory & Pointers | Stack/Heap, Pointers vs References | ⭐⭐ |
| [Module 02](module02/) | Operator Overloading | Orthodox Canonical Form, Fixed-point | ⭐⭐ |
| [Module 03](module03/) | Inheritance | Class Hierarchies, Method Overriding | ⭐⭐⭐ |
| [Module 04](module04/) | Polymorphism | Virtual Functions, Abstract Classes | ⭐⭐⭐ |
| [Module 05](module05/) | Exceptions | Exception Handling, Custom Exceptions | ⭐⭐⭐ |
| [Module 06](module06/) | C++ Casts | Type Casting, RTTI, Serialization | ⭐⭐⭐⭐ |
| [Module 07](module07/) | Templates | Generic Programming, Function/Class Templates | ⭐⭐⭐⭐ |
| [Module 08](module08/) | STL Foundations | Containers, Iterators, Algorithms | ⭐⭐⭐⭐⭐ |
| [Module 09](module09/) | Advanced STL | Real-world Applications, Performance | ⭐⭐⭐⭐⭐ |

## 🎯 Learning Path

### Phase 1: C++ Fundamentals (Modules 00-02)
**Goal**: Master basic C++ syntax and object-oriented programming basics
- Understand classes, objects, and member functions
- Learn memory management and the difference between stack and heap
- Practice operator overloading and the Orthodox Canonical Class Form

### Phase 2: Object-Oriented Programming (Modules 03-04)
**Goal**: Master inheritance, polymorphism, and advanced OOP concepts
- Understand inheritance hierarchies and method overriding
- Learn virtual functions and abstract classes
- Practice polymorphic design patterns

### Phase 3: Advanced C++ Features (Modules 05-06)
**Goal**: Handle errors gracefully and understand type systems
- Master exception handling and exception safety
- Learn the different types of C++ casts and when to use them
- Understand runtime type information (RTTI)

### Phase 4: Generic Programming (Modules 07-09)
**Goal**: Write generic, reusable code using templates and STL
- Master template programming and generic algorithms
- Understand STL containers, iterators, and algorithms
- Apply knowledge to real-world programming scenarios

## 🛠 Compilation Requirements

All projects are compiled using:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### Standard Requirements
- **C++ Standard**: C++98 (for historical learning purposes)
- **Compiler Flags**: Wall, Wextra, Werror (zero tolerance for warnings)
- **Build System**: Makefiles provided for each exercise
- **Naming Convention**: UpperCamelCase for classes, snake_case for files

## 📋 Project Guidelines

### Code Standards
- **Orthodox Canonical Class Form**: Every class must implement the big four
  - Default constructor
  - Copy constructor  
  - Copy assignment operator
  - Destructor
- **Memory Management**: No memory leaks, proper RAII implementation
- **Exception Safety**: Basic guarantee minimum, strong guarantee preferred
- **Const Correctness**: Proper use of const throughout

### Forbidden Features
- C-style casts (use C++ casts instead)
- External libraries (except standard library)
- Using namespace std (must use std:: prefix)
- Memory leaks and undefined behavior
- Global variables

## 🎮 Key Exercises Highlights

### 🔥 Must-Try Exercises

#### Module 00 - PhoneBook
- **Skill Level**: Beginner
- **Focus**: Basic class design and user interaction
- Interactive phonebook application with contact management

#### Module 02 - Fixed Point Class
- **Skill Level**: Intermediate  
- **Focus**: Operator overloading and numerical programming
- Custom fixed-point arithmetic class with complete operator set

#### Module 04 - Abstract Animal Hierarchy
- **Skill Level**: Advanced
- **Focus**: Polymorphism and memory management
- Complex inheritance hierarchy with Brain composition and deep copying

#### Module 07 - Generic Array
- **Skill Level**: Advanced
- **Focus**: Template programming
- STL-like container with exception safety and type genericity

#### Module 09 - Bitcoin Exchange
- **Skill Level**: Expert
- **Focus**: Real-world application development
- Financial data processing with CSV parsing and historical rate calculations

## 📈 Difficulty Progression

```
Complexity Level
     ▲
     │     ┌─────────┐ Module 09 (Expert)
     │     │ STL &   │
     │     │ Real    │ ┌─────────┐ Module 08
     │     │ World   │ │ STL     │
     │     └─────────┘ │ Found.  │
     │                 └─────────┘
     │   ┌─────────┐ ┌─────────┐ Module 06-07
     │   │ Advanced│ │ Generic │
     │   │ Features│ │ Program │
     │   └─────────┘ └─────────┘
     │ ┌─────────┐ ┌─────────┐ Module 03-05
     │ │ OOP     │ │ Error   │
     │ │ Advanced│ │ Handling│
     │ └─────────┘ └─────────┘
     │ ┌─────────┐ Module 00-02
     │ │ C++     │
     │ │ Basics  │
     │ └─────────┘
     └─────────────────────────────────────► Time
```

## 🎓 Skills Developed

### Technical Skills
- **Memory Management**: Manual memory allocation, RAII, smart pointer concepts
- **Object-Oriented Design**: Inheritance, polymorphism, encapsulation
- **Generic Programming**: Templates, STL usage, algorithm design
- **Error Handling**: Exception safety, custom exceptions, robust code
- **Performance Optimization**: Algorithm complexity, container selection

### Software Engineering Practices
- **Code Organization**: Modular design, separation of concerns
- **Documentation**: Clear code structure and commenting
- **Testing**: Edge case handling, input validation
- **Debugging**: Understanding compiler errors and runtime issues
- **Best Practices**: Following established C++ conventions

## 📚 Additional Resources

### Recommended Reading
- **Primary**: "The C++ Programming Language" by Bjarne Stroustrup (included)
- **Modern Practices**: "Effective Modern C++" by Scott Meyers (included)
- **Reference**: [cppreference.com](https://cppreference.com)

### Online Resources
- [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines)
- [Compiler Explorer](https://godbolt.org/) for assembly analysis
- [C++ Insights](https://cppinsights.io/) for template expansion

## 🏆 Completion Milestones

### Bronze Level (Modules 00-03)
- ✅ Basic C++ syntax mastery
- ✅ Object-oriented programming understanding
- ✅ Memory management competency
- ✅ Inheritance hierarchy design

### Silver Level (Modules 04-06)
- ✅ Advanced OOP patterns
- ✅ Exception handling mastery
- ✅ Type system understanding
- ✅ Polymorphic design skills

### Gold Level (Modules 07-09)
- ✅ Template programming expertise
- ✅ STL proficiency
- ✅ Real-world application development
- ✅ Performance optimization skills

## 🚀 Getting Started

1. **Start with Module 00**: Begin with basic C++ concepts
2. **Read the Theory**: Each module has comprehensive documentation
3. **Code Along**: Implement exercises step by step
4. **Test Thoroughly**: Ensure your code handles edge cases
5. **Review and Refactor**: Apply best practices learned

## 📞 Support and Community

For questions and discussions:
- Review module-specific README files
- Study provided example code
- Analyze compiler error messages carefully
- Practice debugging techniques

## 🏅 Achievement Unlocked

Upon completion of this course, you will have:
- Solid foundation in C++ programming
- Understanding of modern C++ best practices
- Ability to write efficient, maintainable code
- Knowledge of template programming and STL
- Skills to tackle real-world C++ projects

---

**Happy Coding!** 🚀

*This course provides a comprehensive introduction to C++ programming, preparing students for advanced software development and system programming challenges.*