#include <iostream>
#include <iomanip>  // For std::setprecision
#include "Fixed.hpp"

// Color codes for better readability
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void testCase(const std::string& name, const std::string& expected, const std::string& actual) {
    std::cout << name << ": ";
    if (expected == actual) {
        std::cout << GREEN << "PASS" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "  Expected: " << expected << std::endl;
        std::cout << "  Actual:   " << actual << std::endl;
    }
}

int main(void) {
    std::cout << YELLOW << "\n===== TESTING FIXED CLASS =====" << RESET << std::endl;
    
    // Test constructors
    std::cout << BLUE << "\nTesting Constructors:" << RESET << std::endl;
    
    std::cout << "Default constructor: " << std::endl;
    Fixed a;
    std::cout << "Value of a: " << a << std::endl;
    
    std::cout << "\nInteger constructor: " << std::endl;
    Fixed b(10);
    std::cout << "Value of b (from int 10): " << b << std::endl;
    
    std::cout << "\nFloat constructor: " << std::endl;
    Fixed c(42.42f);
    std::cout << "Value of c (from float 42.42): " << c << std::endl;
    
    std::cout << "\nNegative float constructor: " << std::endl;
    Fixed d(-42.42f);
    std::cout << "Value of d (from float -42.42): " << d << std::endl;
    
    std::cout << "\nCopy constructor: " << std::endl;
    Fixed e(c);
    std::cout << "Value of e (copy of c): " << e << std::endl;
    
    // Test assignment
    std::cout << BLUE << "\nTesting Assignment:" << RESET << std::endl;
    a = b;
    std::cout << "After a = b, value of a: " << a << std::endl;
    
    // Test conversion methods
    std::cout << BLUE << "\nTesting Conversion Methods:" << RESET << std::endl;
    std::cout << "b as integer: " << b.toInt() << std::endl;
    std::cout << "c as integer: " << c.toInt() << std::endl;
    std::cout << "c as float: " << std::fixed << std::setprecision(2) << c.toFloat() << std::endl;
    
    // Test edge cases
    std::cout << BLUE << "\nTesting Edge Cases:" << RESET << std::endl;
    Fixed zero;
    Fixed small(0.00390625f);  // 1/256
    Fixed large(1234.567f);
    
    std::cout << "Zero: " << zero << std::endl;
    std::cout << "Smallest positive value (1/256): " << small << std::endl;
    std::cout << "Large value (1234.567): " << large << std::endl;
    std::cout << "Large value as int: " << large.toInt() << std::endl;
    
    // Test raw bits
    std::cout << BLUE << "\nTesting Raw Bits:" << RESET << std::endl;
    std::cout << "Raw bits of a: " << a.getRawBits() << std::endl;
    std::cout << "Raw bits of c: " << c.getRawBits() << std::endl;
    
    // Verify expected values
    std::cout << BLUE << "\nVerifying Results:" << RESET << std::endl;
    testCase("Integer 10 as fixed-point", "10", std::to_string(b.toInt()));
    testCase("42.42 as integer", "42", std::to_string(c.toInt()));
    
    std::cout << YELLOW << "\n===== TEST COMPLETE =====" << RESET << std::endl;
    
    return 0;
}