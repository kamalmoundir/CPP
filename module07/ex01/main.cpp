/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:35:31 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/19 17:03:16 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Test functions for different types
void printInt(const int& i)
{
    std::cout << i << std::endl;
}

template<typename T>
void printType(const T& i)
{
    std::cout << i << std::endl;
}

template<typename T>
void doubleValue(T& i)
{
    i = i * 2;
}

template<typename T>
void incrementValue(T& i)
{
    i++;
}

void makeUppercase(std::string& str)
{
    for(size_t i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void addPrefix(std::string& str)
{
    str = "[PREFIX] " + str;
}

template<typename T>
void printWithIndex(const T& value)
{
    static int index = 0;
    std::cout << "[" << index++ << "] = " << value << std::endl;
}

void testBasicIntegerArray()
{
    std::cout << "=== Test 1: Basic Integer Array ===" << std::endl;
    
    int array[] = {1, 2, 3, 45};
    size_t length = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Original array:" << std::endl;
    iter(array, length, printType<int>);
    
    std::cout << std::endl;
}

void testStringArray()
{
    std::cout << "=== Test 2: String Array ===" << std::endl;
    
    std::string arrayStr[] = {"test", "test1", "test2", "test4"};
    size_t length = sizeof(arrayStr) / sizeof(arrayStr[0]);
    
    std::cout << "String array:" << std::endl;
    iter(arrayStr, length, printType<std::string>);
    
    std::cout << std::endl;
}

void testModifyingIntegerArray()
{
    std::cout << "=== Test 3: Modifying Integer Array ===" << std::endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Before doubling:" << std::endl;
    iter(numbers, length, printType<int>);
    
    std::cout << "Doubling all values..." << std::endl;
    iter(numbers, length, doubleValue<int>);
    
    std::cout << "After doubling:" << std::endl;
    iter(numbers, length, printType<int>);
    
    std::cout << std::endl;
}

void testCharacterArray()
{
    std::cout << "=== Test 4: Character Array ===" << std::endl;
    
    char chars[] = {'A', 'B', 'C', 'D', 'E'};
    size_t length = sizeof(chars) / sizeof(chars[0]);
    
    std::cout << "Character array:" << std::endl;
    iter(chars, length, printType<char>);
    
    std::cout << "Incrementing characters..." << std::endl;
    iter(chars, length, incrementValue<char>);
    
    std::cout << "After incrementing:" << std::endl;
    iter(chars, length, printType<char>);
    
    std::cout << std::endl;
}

void testDoubleArray()
{
    std::cout << "=== Test 5: Double Array ===" << std::endl;
    
    double decimals[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t length = sizeof(decimals) / sizeof(decimals[0]);
    
    std::cout << "Double array:" << std::endl;
    iter(decimals, length, printType<double>);
    
    std::cout << "Doubling values..." << std::endl;
    iter(decimals, length, doubleValue<double>);
    
    std::cout << "After doubling:" << std::endl;
    iter(decimals, length, printType<double>);
    
    std::cout << std::endl;
}


void testStringModification()
{
    std::cout << "=== Test 6: String Modification ===" << std::endl;
    
    std::string words[] = {"hello", "world", "template", "functions"};
    size_t length = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original strings:" << std::endl;
    iter(words, length, printType<std::string>);
    
    std::cout << "Converting to uppercase..." << std::endl;
    iter(words, length, makeUppercase);
    
    std::cout << "After uppercase conversion:" << std::endl;
    iter(words, length, printType<std::string>);
    
    std::cout << "Adding prefix..." << std::endl;
    iter(words, length, addPrefix);
    
    std::cout << "After adding prefix:" << std::endl;
    iter(words, length, printType<std::string>);
    
    std::cout << std::endl;
}


void testEmptyArray()
{
    std::cout << "=== Test 7: Empty Array ===" << std::endl;
    
   
    int* emptyArray = NULL;
    size_t length = 0;
    
    std::cout << "Testing empty array (should print nothing):" << std::endl;
    iter(emptyArray, length, printType<int>);
    std::cout << "Empty array test completed." << std::endl;
    
    std::cout << std::endl;
}

void testSingleElementArray()
{
    std::cout << "=== Test 8: Single Element Array ===" << std::endl;
    
    int single[] = {42};
    size_t length = sizeof(single) / sizeof(single[0]);
    
    std::cout << "Single element array:" << std::endl;
    iter(single, length, printType<int>);
    
    std::cout << std::endl;
}

void testLargeArray()
{
    std::cout << "=== Test 9: Large Array ===" << std::endl;
    
    int largeArray[100];
    for(int i = 0; i < 100; i++) {
        largeArray[i] = i + 1;
    }
    
    std::cout << "First 10 elements of large array:" << std::endl;
    iter(largeArray, 10, printType<int>);
    
    std::cout << "Last 10 elements of large array:" << std::endl;
    iter(largeArray + 90, 10, printType<int>);
    
    std::cout << std::endl;
}

void testBooleanArray()
{
    std::cout << "=== Test 10: Boolean Array ===" << std::endl;
    
    bool flags[] = {true, false, true, false, true};
    size_t length = sizeof(flags) / sizeof(flags[0]);
    
    std::cout << "Boolean array:" << std::endl;
    iter(flags, length, printType<bool>);
    
    std::cout << std::endl;
}


void testMixedTypeDemo()
{
    std::cout << "=== Test 11: Mixed Type Demonstration ===" << std::endl;
    
    int specificInts[] = {100, 200, 300};
    size_t intLength = sizeof(specificInts) / sizeof(specificInts[0]);
    
    std::cout << "Using specific printInt function:" << std::endl;
    iter(specificInts, intLength, printInt);
    
    std::cout << "Using generic printType function:" << std::endl;
    iter(specificInts, intLength, printType<int>);
    
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "========== COMPREHENSIVE ITER TEMPLATE TESTS ==========" << std::endl << std::endl;
    
    
    testBasicIntegerArray();
    testStringArray();
    testModifyingIntegerArray();
    testCharacterArray();
    testDoubleArray();
    testStringModification();
    testEmptyArray();
    testSingleElementArray();
    testLargeArray();
    testBooleanArray();
    testMixedTypeDemo();
    
    std::cout << "========== ALL TESTS COMPLETED ==========" << std::endl;
    
    return 0;
}