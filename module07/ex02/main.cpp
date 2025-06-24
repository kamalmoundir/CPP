/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:11:04 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/20 12:37:16 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include<cmath>
#include <cstdlib>

#define MAX_VAL 750

class Pair {
public:
    int x;
    char y;
    
    Pair() : x(0), y('A') {}
    Pair(int a, char b) : x(a), y(b) {}
};

void additionalBasicTests()
{
    std::cout << "\n====== ADDITIONAL BASIC ARRAY TESTS ======\n" << std::endl;
    
    // Test 1: Floating point array
    std::cout << "Test 1: Floating point array" << std::endl;
    Array<double> doubleArray(5);
    for (unsigned int i = 0; i < doubleArray.size(); i++) {
        doubleArray[i] = i * 1.5;
    }
    
    std::cout << "Double array contents: ";
    for (unsigned int i = 0; i < doubleArray.size(); i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 2: Const arrays and const correctness
    std::cout << "\nTest 2: Const array testing" << std::endl;
    const Array<int> constArray(3);
    // This would fail compilation: constArray[0] = 1;
    std::cout << "Const array size: " << constArray.size() << std::endl;
    std::cout << "Reading from const array: " << constArray[0] << std::endl;
    
    // Test 3: Self-assignment
    std::cout << "\nTest 3: Self-assignment" << std::endl;
    Array<int> selfArray(3);
    for (unsigned int i = 0; i < selfArray.size(); i++) {
        selfArray[i] = i * 100;
    }
    
    std::cout << "Before self-assignment: ";
    for (unsigned int i = 0; i < selfArray.size(); i++) {
        std::cout << selfArray[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int>& ref = selfArray;
    selfArray = ref;
    
    std::cout << "After self-assignment: ";
    for (unsigned int i = 0; i < selfArray.size(); i++) {
        std::cout << selfArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 4: Empty to non-empty assignment
    std::cout << "\nTest 4: Empty to non-empty assignment" << std::endl;
    Array<int> nonEmpty(5);
    for (unsigned int i = 0; i < nonEmpty.size(); i++) {
        nonEmpty[i] = i + 10;
    }
    
    std::cout << "Before assignment, size: " << nonEmpty.size() << std::endl;
    
    Array<int> emptyArr;
    nonEmpty = emptyArr;
    
    std::cout << "After assignment to empty, size: " << nonEmpty.size() << std::endl;
    
    // Test 5: Array of custom type
    std::cout << "\nTest 5: Array of pairs" << std::endl;
    
    Array<Pair> pairArray(3);
    pairArray[0] = Pair(1, 'X');
    pairArray[1] = Pair(2, 'Y');
    pairArray[2] = Pair(3, 'Z');
    
    std::cout << "Pair array contents: " << std::endl;
    for (unsigned int i = 0; i < pairArray.size(); i++) {
        std::cout << "Pair[" << i << "]: " << pairArray[i].x << ", " 
                  << pairArray[i].y << std::endl;
    }
    
    // Test 6: Array of Arrays (2D array simulation)
    std::cout << "\nTest 6: 2D array simulation" << std::endl;
    Array<Array<int> > matrix(3);
    
    for (unsigned int i = 0; i < matrix.size(); i++) {
        matrix[i] = Array<int>(3);
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = i * 3 + j;
        }
    }
    
    std::cout << "Matrix contents:" << std::endl;
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n====== END OF ADDITIONAL TESTS ======" << std::endl;
}
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    additionalBasicTests();
    return 0;
}