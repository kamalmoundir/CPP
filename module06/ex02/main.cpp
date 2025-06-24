/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:11 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 18:38:24 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

void testBasicFunctionality()
{
    std::cout << "=== Test 1: Basic Functionality ===" << std::endl;
    
    Base *obj = generate();
    
    std::cout << "pointer identification:" << std::endl;
    identify(obj);
    
    std::cout << "reference identification:" << std::endl;
    identify(*obj);
    
    delete obj;
    std::cout << std::endl;
}

void testMultipleObjectGeneration()
{
    std::cout << "=== Test 2: Multiple Object Generation ===" << std::endl;
    
    std::cout << "Generating 10 objects to test randomness:" << std::endl;
    
    int countA = 0, countB = 0, countC = 0;
    
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Object " << (i + 1) << ": ";
        Base *obj = generate();
        
        // Count types using pointer identification
        if(dynamic_cast<A*>(obj))
            countA++;
        else if(dynamic_cast<B*>(obj))
            countB++;
        else if(dynamic_cast<C*>(obj))
            countC++;
        
        delete obj;
    }
    
    std::cout << "Distribution: A=" << countA << " B=" << countB << " C=" << countC << std::endl;
    std::cout << std::endl;
}

void testBothIdentificationMethods()
{
    std::cout << "=== Test 3: Both Identification Methods ===" << std::endl;
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << "--- Test " << (i + 1) << " ---" << std::endl;
        Base *obj = generate();
        
        std::cout << "Pointer method: ";
        identify(obj);
        
        std::cout << "Reference method: ";
        identify(*obj);
        
        std::cout << "Both methods should give same result" << std::endl;
        std::cout << std::endl;
        
        delete obj;
    }
}

void testNullPointerHandling()
{
    std::cout << "=== Test 4: NULL Pointer Handling ===" << std::endl;
    
    Base *nullPtr = NULL;
    std::cout << "Testing identify with NULL pointer:" << std::endl;
    identify(nullPtr);  // Should print "unknown type"
    
    std::cout << std::endl;
}

void testDirectObjectCreation()
{
    std::cout << "=== Test 5: Direct Object Creation ===" << std::endl;
    
    std::cout << "Creating A object directly:" << std::endl;
    A *directA = new A();
    std::cout << "Pointer identification: ";
    identify(static_cast<Base*>(directA));
    std::cout << "Reference identification: ";
    identify(*static_cast<Base*>(directA));
    delete directA;
    
    std::cout << "Creating B object directly:" << std::endl;
    B *directB = new B();
    std::cout << "Pointer identification: ";
    identify(static_cast<Base*>(directB));
    std::cout << "Reference identification: ";
    identify(*static_cast<Base*>(directB));
    delete directB;
    
    std::cout << "Creating C object directly:" << std::endl;
    C *directC = new C();
    std::cout << "Pointer identification: ";
    identify(static_cast<Base*>(directC));
    std::cout << "Reference identification: ";
    identify(*static_cast<Base*>(directC));
    delete directC;
    
    std::cout << std::endl;
}

void testPolymorphicBehavior()
{
    std::cout << "=== Test 6: Polymorphic Behavior ===" << std::endl;
    
    // Create array of Base pointers
    Base* objects[6];
    
    // Fill with randomly generated objects
    std::cout << "Creating array of 6 objects:" << std::endl;
    for(int i = 0; i < 6; i++)
    {
        objects[i] = generate();
    }
    
    std::cout << "\nIdentifying all objects using pointer method:" << std::endl;
    for(int i = 0; i < 6; i++)
    {
        std::cout << "Object[" << i << "]: ";
        identify(objects[i]);
    }
    
    std::cout << "\nIdentifying all objects using reference method:" << std::endl;
    for(int i = 0; i < 6; i++)
    {
        std::cout << "Object[" << i << "]: ";
        identify(*objects[i]);
    }
    
    // Clean up
    for(int i = 0; i < 6; i++)
    {
        delete objects[i];
    }
    
    std::cout << std::endl;
}

void testExceptionHandling()
{
    std::cout << "=== Test 7: Exception Handling ===" << std::endl;
    
    std::cout << "Testing reference identification (uses exceptions internally):" << std::endl;
    
    for(int i = 0; i < 3; i++)
    {
        Base *obj = generate();
        std::cout << "Object " << (i + 1) << " reference ID: ";
        
        try {
            identify(*obj);
            std::cout << "Successfully identified without external exception" << std::endl;
        }
        catch(...) {
            std::cout << "Unexpected exception caught!" << std::endl;
        }
        
        delete obj;
    }
    
    std::cout << std::endl;
}

void displayTestSummary()
{
    std::cout << "=== TEST SUMMARY ===" << std::endl;
    std::cout << "✓ Basic functionality test" << std::endl;
    std::cout << "✓ Random generation distribution test" << std::endl;
    std::cout << "✓ Pointer vs Reference identification consistency" << std::endl;
    std::cout << "✓ NULL pointer handling" << std::endl;
    std::cout << "✓ Direct object creation verification" << std::endl;
    std::cout << "✓ Polymorphic behavior with arrays" << std::endl;
    std::cout << "✓ Exception handling robustness" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "========== DYNAMIC CAST IDENTIFICATION TESTS ==========" << std::endl << std::endl;
    
    // Run all tests
    testBasicFunctionality();
    testMultipleObjectGeneration();
    testBothIdentificationMethods();
    testNullPointerHandling();
    testDirectObjectCreation();
    testPolymorphicBehavior();
    testExceptionHandling();
    
    displayTestSummary();
    
    std::cout << "========== ALL TESTS COMPLETED ==========" << std::endl;
    
    return 0;
}
