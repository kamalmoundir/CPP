/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:43:51 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/23 13:58:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

// Utility function to print container content
template<typename T>
void printContainer(const T& container, const std::string& name) {
    std::cout << name << " contains: ";
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Test with vector
void testVector() {
    std::cout << "\n----- TESTING VECTOR -----" << std::endl;
    
    // Initialize vector
    int arr[] = {1, 2, 9, 8, 10, 100, 8};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    printContainer(vec, "Vector");
    
    // Test finding existing value
    std::cout << "Searching for 8: ";
    try {
        if (easyfind(vec, 8))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test finding value at start
    std::cout << "Searching for 1: ";
    try {
        if (easyfind(vec, 1))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test finding non-existing value
    std::cout << "Searching for 42: ";
    try {
        if (easyfind(vec, 42))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

// Test with list
void testList() {
    std::cout << "\n----- TESTING LIST -----" << std::endl;
    
    // Initialize list
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);
    printContainer(lst, "List");
    
    // Test finding existing value
    std::cout << "Searching for 15: ";
    try {
        if (easyfind(lst, 15))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test finding non-existing value
    std::cout << "Searching for 30: ";
    try {
        if (easyfind(lst, 30))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

// Test with deque
void testDeque() {
    std::cout << "\n----- TESTING DEQUE -----" << std::endl;
    
    // Initialize deque
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_front(50);
    dq.push_back(300);
    printContainer(dq, "Deque");
    
    // Test finding existing value
    std::cout << "Searching for 100: ";
    try {
        if (easyfind(dq, 100))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test finding non-existing value
    std::cout << "Searching for 150: ";
    try {
        if (easyfind(dq, 150))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

// Test edge cases
void testEdgeCases() {
    std::cout << "\n----- TESTING EDGE CASES -----" << std::endl;
    
    // Empty container
    std::cout << "Testing empty container:" << std::endl;
    std::vector<int> empty;
    printContainer(empty, "Empty vector");
    
    std::cout << "Searching for 1 in empty container: ";
    try {
        if (easyfind(empty, 1))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Single element container
    std::cout << "\nTesting single element container:" << std::endl;
    std::vector<int> single;
    single.push_back(42);
    printContainer(single, "Single element vector");
    
    std::cout << "Searching for 42 in single element: ";
    try {
        if (easyfind(single, 42))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "Searching for 43 in single element: ";
    try {
        if (easyfind(single, 43))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Duplicate values
    std::cout << "\nTesting container with duplicates:" << std::endl;
    std::vector<int> dups;
    dups.push_back(5);
    dups.push_back(5);
    dups.push_back(10);
    dups.push_back(5);
    dups.push_back(15);
    printContainer(dups, "Vector with duplicates");
    
    std::cout << "Searching for 5 (duplicated value): ";
    try {
        if (easyfind(dups, 5))
            std::cout << "Value exists in the container" << std::endl;
        else
            std::cout << "Value doesn't exist in the container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    // Original test
    std::cout << "----- ORIGINAL TEST -----" << std::endl;
    int arr[] = {1, 2, 9, 8, 10, 100};
    std::vector<int> tab(arr, arr + sizeof(arr) / sizeof(arr[0]));
    printContainer(tab, "Original vector");
    
    std::cout << "Searching for 8: ";
    if(easyfind(tab, 8))
    {
        std::cout << "Value exist in the container" << std::endl;
    }
    else
    {
        std::cout << "Value doesn't exist in the container" << std::endl;
    }
    
    // Additional tests
    testVector();
    testList();
    testDeque();
    testEdgeCases();
    
    return 0;
}