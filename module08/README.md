# Module 08 - Templated Containers, Iterators, and Algorithms

## Overview
This module explores the Standard Template Library (STL) concepts through custom implementations. Students learn about containers, iterators, algorithms, and how these components work together to create powerful and efficient C++ programs.

## Learning Objectives
- Understand STL design principles and architecture
- Master container design and implementation
- Learn iterator concepts and implementation
- Practice algorithm design with templates
- Understand the relationship between containers, iterators, and algorithms
- Explore function objects and predicates

## STL Architecture
The STL is built on three main components:
1. **Containers**: Data structures that store objects
2. **Iterators**: Objects that traverse containers
3. **Algorithms**: Functions that operate on ranges defined by iterators

## Exercises

### Exercise 00: Easy Find
**Files:** `easyfind.hpp`, `easyfind.tpp`, `main.cpp`

Template function to find values in containers:
- Generic find function for STL containers
- Iterator-based searching
- Exception handling for not found cases
- Introduction to STL container concepts

**Key Concepts:**
- Template functions with container parameters
- STL container requirements
- Iterator usage and std::find
- Exception handling in generic code
- Template function implementation

**Template Function:**
```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value);
```

**Usage Examples:**
```cpp
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

try {
    std::vector<int>::iterator it = easyfind(vec, 2);
    std::cout << "Found: " << *it << std::endl;
} catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

**Supported Containers:**
- std::vector
- std::list
- std::deque
- Any container with iterators and find capability

### Exercise 01: Span
**Files:** `Span.hpp`, `Span.cpp`, `main.cpp`

Custom container class implementation:
- Fixed-size container with dynamic storage
- Iterator support for STL compatibility
- Range-based operations and algorithms
- Exception handling for capacity limits

**Key Concepts:**
- Container class design
- Dynamic memory management in containers
- Iterator implementation and compatibility
- STL algorithm compatibility
- Range operations and capacity management

**Span Class Features:**
```cpp
template<typename T>
class Span {
private:
    T* _data;
    unsigned int _capacity;
    unsigned int _size;

public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);
    
    void addNumber(const T& number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Iterator support
    typedef T* iterator;
    iterator begin() { return _data; }
    iterator end() { return _data + _size; }
    
    // Range operations
    template<typename Iterator>
    void addRange(Iterator first, Iterator last);
};
```

**Exception Classes:**
```cpp
class SpanFullException : public std::exception;
class SpanEmptyException : public std::exception;
class NotEnoughElementsException : public std::exception;
```

### Exercise 02: Mutated Abomination
**Files:** `MutantStack.hpp`, `MutantStack.tpp`, `main.cpp`

STL-compatible stack with iterator support:
- Inherit from std::stack
- Add iterator functionality to stack
- Maintain stack interface while adding traversal
- Template inheritance and extension

**Key Concepts:**
- Template inheritance
- Adding functionality to existing containers
- Iterator implementation for stack-like structures
- STL compatibility and interface design
- Container adapter modification

**MutantStack Class:**
```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& other);
    
    // Iterator types
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    
    // Iterator functions
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};
```

**Usage Example:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
mstack.push(3);

// Stack operations
std::cout << mstack.top() << std::endl;
mstack.pop();

// Iterator operations
for (MutantStack<int>::iterator it = mstack.begin(); 
     it != mstack.end(); ++it) {
    std::cout << *it << std::endl;
}
```

## Iterator Categories
STL defines five iterator categories:
1. **Input Iterator**: Read-only, forward movement
2. **Output Iterator**: Write-only, forward movement
3. **Forward Iterator**: Read/write, forward movement
4. **Bidirectional Iterator**: Read/write, forward and backward
5. **Random Access Iterator**: Read/write, random access

## Container Requirements
STL containers must provide:
- Default constructor
- Copy constructor and assignment
- Destructor
- begin() and end() iterators
- size() and empty() methods
- Appropriate typedefs (value_type, iterator, etc.)

## Algorithm Design Patterns
```cpp
// Generic find algorithm
template<typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& value) {
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return last;
}

// Generic transform algorithm
template<typename InputIt, typename OutputIt, typename UnaryOp>
OutputIt transform(InputIt first, InputIt last, OutputIt result, UnaryOp op) {
    while (first != last) {
        *result = op(*first);
        ++first;
        ++result;
    }
    return result;
}
```

## Function Objects and Predicates
```cpp
// Function object for comparison
template<typename T>
struct Less {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

// Usage with algorithms
std::sort(vec.begin(), vec.end(), Less<int>());
```

## STL Algorithms Categories
1. **Non-modifying**: find, count, search, equal
2. **Modifying**: copy, fill, transform, replace
3. **Sorting**: sort, partial_sort, stable_sort
4. **Set Operations**: set_union, set_intersection
5. **Heap Operations**: make_heap, push_heap, pop_heap

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **STL Design Principles**: Containers, iterators, algorithms separation
2. **Template Containers**: Generic data structures
3. **Iterator Concepts**: Traversal and access patterns
4. **Algorithm Design**: Generic functions with iterators
5. **Function Objects**: Callable objects for customization
6. **Container Adapters**: Modifying existing container interfaces
7. **Range Operations**: Working with iterator ranges
8. **Template Specialization**: Optimizing for specific types

## STL Best Practices
- Use appropriate container for your use case
- Prefer algorithms over hand-written loops
- Use const iterators when not modifying
- Take advantage of iterator categories for optimization
- Use function objects for customizable behavior
- Prefer range-based operations when possible
- Consider performance characteristics of different containers

## Performance Considerations
### Container Performance:
- **vector**: O(1) random access, O(1) amortized append
- **list**: O(1) insertion/deletion, O(n) access
- **deque**: O(1) front/back operations, O(1) random access
- **stack/queue**: O(1) operations, restricted access

### Algorithm Complexity:
- **find**: O(n) linear search
- **sort**: O(n log n) comparison-based
- **binary_search**: O(log n) on sorted range

## Common Patterns
### Range-based Processing:
```cpp
// Copy all elements
std::copy(source.begin(), source.end(), dest.begin());

// Transform elements
std::transform(vec.begin(), vec.end(), vec.begin(), 
               [](int x) { return x * 2; });

// Find with condition
auto it = std::find_if(vec.begin(), vec.end(), 
                       [](int x) { return x > 10; });
```

### Custom Comparators:
```cpp
// Sort with custom comparison
std::sort(vec.begin(), vec.end(), 
          [](const T& a, const T& b) { return a.value < b.value; });
```

## Important Notes
- STL promotes code reuse through generic programming
- Iterators provide uniform interface to different containers
- Algorithms work with any container providing appropriate iterators
- Template-based design enables zero-overhead abstractions
- STL containers handle memory management automatically
- Iterator invalidation rules vary by container and operation
- Choose containers based on required operations and performance
- STL algorithms are extensively tested and optimized
