# Module 09 - STL Containers and Advanced C++

## Overview
This final module demonstrates practical applications of C++ and STL knowledge through real-world programming challenges. Students work with file processing, data structures, and complex algorithms while applying all previously learned concepts.

## Learning Objectives
- Apply STL containers in practical scenarios
- Master file I/O and data processing
- Implement complex data structures and algorithms
- Practice performance optimization techniques
- Understand real-world C++ application development
- Integrate multiple C++ concepts in comprehensive projects

## Real-World Applications
This module focuses on practical programming scenarios:
- Financial data processing
- Algorithm implementation and optimization
- Data parsing and validation
- Container selection for specific use cases
- Performance-critical code development

## Exercises

### Exercise 00: Bitcoin Exchange
**Files:** `BitcoinExchange.hpp`, `BitcoinExchange.cpp`, `main.cpp`, `data.csv`

Financial data processing application:
- Parse CSV data files with historical Bitcoin prices
- Process input files with date-value pairs
- Validate dates and values with comprehensive error handling
- Calculate Bitcoin values based on historical exchange rates

**Key Concepts:**
- File I/O and CSV parsing
- std::map for key-value storage and fast lookups
- Date parsing and validation
- Financial calculations with floating-point precision
- Error handling for malformed data
- STL algorithms for data processing

**Features:**
- **Database Loading**: Parse CSV file with date,price format
- **Input Processing**: Handle date | value format
- **Date Validation**: Check for valid dates and chronological order
- **Value Validation**: Ensure positive values within reasonable limits
- **Price Lookup**: Find closest historical price for given date
- **Error Reporting**: Comprehensive error messages for invalid data

**Database Format (data.csv):**
```
date,exchange_rate
2009-01-02,0
2009-01-03,0
2009-01-04,0
...
```

**Input Format:**
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
...
```

**Error Cases:**
- Invalid date formats
- Dates before database start
- Negative values
- Values too large (> 1000)
- Malformed input lines

### Exercise 01: Reverse Polish Notation (RPN)
**Files:** `RPN.hpp`, `RPN.cpp`, `main.cpp`

Mathematical expression evaluator:
- Implement stack-based RPN calculator
- Parse and validate mathematical expressions
- Handle arithmetic operations with error checking
- Demonstrate stack data structure usage

**Key Concepts:**
- Stack data structure for expression evaluation
- String parsing and tokenization
- Mathematical operation implementation
- Error handling for division by zero and invalid operations
- Algorithm implementation with STL containers

**RPN Algorithm:**
1. Parse expression into tokens
2. For each token:
   - If number: push onto stack
   - If operator: pop two operands, calculate, push result
3. Final result should be single value on stack

**Supported Operations:**
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)

**Example:**
```
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
Steps: 8, 9 → 72, 9 → 63, 9 → 54, 9 → 45, 4 → 41, 1 → 42
Output: 42
```

**Error Cases:**
- Invalid tokens
- Insufficient operands for operators
- Division by zero
- Too many operands (more than one result)

### Exercise 02: PmergeMe
**Files:** `PmergeMe.hpp`, `PmergeMe.cpp`, `main.cpp`

Performance comparison of sorting algorithms:
- Implement merge-insert sort (Ford-Johnson algorithm)
- Compare performance using different STL containers
- Measure and report execution times
- Handle large datasets efficiently

**Key Concepts:**
- Advanced sorting algorithm implementation
- Performance measurement and comparison
- STL container performance characteristics
- Memory efficiency and optimization
- Algorithm complexity analysis
- Template programming for multiple container types

**Ford-Johnson Algorithm (Merge-Insert Sort):**
1. Group elements in pairs and sort each pair
2. Sort pairs by their larger elements
3. Insert smaller elements using binary insertion
4. Optimize insertion sequence to minimize comparisons

**Container Comparison:**
- **std::vector**: Random access, contiguous memory
- **std::deque**: Double-ended queue, segmented memory
- Performance comparison for different data sizes

**Features:**
- **Input Validation**: Ensure positive integers, no duplicates
- **Algorithm Implementation**: Ford-Johnson merge-insert sort
- **Performance Measurement**: Time execution for both containers
- **Result Verification**: Ensure sorting correctness
- **Output Format**: Display before/after states and timing

**Example Output:**
```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

## Advanced STL Usage Patterns

### Map-based Data Processing:
```cpp
std::map<std::string, double> database;
// Efficient O(log n) lookups
auto it = database.lower_bound(date);
if (it != database.begin()) {
    --it;  // Get closest earlier date
}
```

### Stack-based Algorithm Implementation:
```cpp
std::stack<double> operandStack;
for (const auto& token : tokens) {
    if (isOperator(token)) {
        double b = operandStack.top(); operandStack.pop();
        double a = operandStack.top(); operandStack.pop();
        operandStack.push(calculate(a, b, token));
    } else {
        operandStack.push(parseNumber(token));
    }
}
```

### Performance Measurement:
```cpp
#include <ctime>
clock_t start = clock();
// Algorithm execution
clock_t end = clock();
double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
```

## Container Selection Guidelines

### When to Use Each Container:
- **std::vector**: Default choice, random access needed
- **std::deque**: Frequent front/back insertion/deletion
- **std::list**: Frequent middle insertion/deletion
- **std::map**: Key-value pairs, sorted order, O(log n) access
- **std::set**: Unique sorted elements
- **std::stack**: LIFO operations
- **std::queue**: FIFO operations

### Performance Characteristics:
| Container | Access | Insert/Delete | Search | Memory |
|-----------|--------|---------------|---------|---------|
| vector    | O(1)   | O(n) / O(1)*  | O(n)    | Contiguous |
| deque     | O(1)   | O(1) ends     | O(n)    | Segmented |
| list      | O(n)   | O(1)          | O(n)    | Non-contiguous |
| map       | O(log n)| O(log n)     | O(log n)| Tree |

## Error Handling Strategies
```cpp
// Input validation
if (value < 0) {
    throw std::invalid_argument("Error: not a positive number.");
}

// Range checking
if (value > MAX_VALUE) {
    throw std::out_of_range("Error: too large a number.");
}

// Date validation
if (!isValidDate(dateStr)) {
    throw std::invalid_argument("Error: bad input => " + dateStr);
}
```

## Compilation
All exercises use Makefiles with:
- `-Wall -Wextra -Werror`
- `-std=c++98`

## Key C++ Concepts Covered
1. **File I/O**: Reading and parsing data files
2. **STL Containers**: Practical application of maps, stacks, vectors
3. **Algorithm Implementation**: Complex sorting and calculation algorithms
4. **Performance Analysis**: Measuring and comparing execution times
5. **Error Handling**: Comprehensive input validation and error reporting
6. **String Processing**: Parsing and tokenizing input data
7. **Data Validation**: Ensuring data integrity and format compliance
8. **Memory Management**: Efficient use of containers and memory

## Performance Optimization Techniques
- Choose appropriate containers based on access patterns
- Minimize memory allocations and copies
- Use references and const where possible
- Profile code to identify bottlenecks
- Consider algorithm complexity and data size
- Leverage STL algorithm optimizations

## Real-World Programming Practices
- Comprehensive input validation
- Meaningful error messages
- Modular code design
- Performance measurement and reporting
- Code documentation and maintainability
- Testing with various input scenarios

## Integration of Previous Modules
This module demonstrates integration of concepts from all previous modules:
- **Module 00**: Basic C++ syntax and classes
- **Module 01**: Memory management and references
- **Module 02**: Operator overloading and canonical form
- **Module 03**: Inheritance and polymorphism
- **Module 04**: Virtual functions and abstract classes
- **Module 05**: Exception handling
- **Module 06**: Type casting and conversions
- **Module 07**: Template programming
- **Module 08**: STL containers and algorithms

## Important Notes
- This module emphasizes practical application over theoretical concepts
- Performance considerations become critical with real-world data sizes
- Proper error handling is essential for robust applications
- STL provides powerful tools for common programming tasks
- Algorithm choice significantly impacts performance
- Code should be maintainable and well-documented
- Testing with various inputs reveals edge cases and bugs
- Modern C++ builds upon these foundational concepts
