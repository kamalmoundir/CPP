/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:39:47 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/24 12:19:19 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    std::cout << "======= BASIC TEST============" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "======= LARGE NUMBER OF INPUT TEST============" << std::endl;

    try
    {
        std::vector<int> numbers;
        std::srand(std::time(0));
        for (int i = 0; i < 20000; i++)
            numbers.push_back(std::rand());

        std::cout << "Min element: " << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
        std::cout << "Max element: " << *std::max_element(numbers.begin(), numbers.end()) << std::endl;
        Span sp1 = Span(50000);
        sp1.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span :" << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span  :" << sp1.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n======= EXCEPTION TESTS ============" << std::endl;

    // Test 1: Span Full Exception
    try
    {
        std::cout << "Test 1: Adding too many numbers..." << std::endl;
        Span sp2 = Span(3);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        sp2.addNumber(4); // Should throw SpanFullException
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 2: No Span Exception - Empty container
    try
    {
        std::cout << "Test 2: Empty container span calculation..." << std::endl;
        Span sp3 = Span(10);
        std::cout << sp3.shortestSpan() << std::endl; // Should throw NoSpanException
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 3: No Span Exception - Single element
    try
    {
        std::cout << "Test 3: Single element span calculation..." << std::endl;
        Span sp4 = Span(10);
        sp4.addNumber(42);
        std::cout << sp4.longestSpan() << std::endl; // Should throw NoSpanException
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n======= EDGE CASES TESTS ============" << std::endl;

    // Test 4: Negative numbers
    try
    {
        std::cout << "Test 4: Negative numbers..." << std::endl;
        Span sp5 = Span(5);
        sp5.addNumber(-10);
        sp5.addNumber(-5);
        sp5.addNumber(0);
        sp5.addNumber(5);
        sp5.addNumber(10);
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl; // Should be 5
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;   // Should be 20
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 5: Duplicate numbers
    try
    {
        std::cout << "Test 5: Duplicate numbers..." << std::endl;
        Span sp6 = Span(5);
        sp6.addNumber(5);
        sp6.addNumber(5);
        sp6.addNumber(10);
        sp6.addNumber(15);
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl; // Should be 0
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;   // Should be 10
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 6: Two elements only
    try
    {
        std::cout << "Test 6: Minimum valid case (2 elements)..." << std::endl;
        Span sp7 = Span(2);
        sp7.addNumber(100);
        sp7.addNumber(200);
        std::cout << "Shortest span: " << sp7.shortestSpan() << std::endl; // Should be 100
        std::cout << "Longest span: " << sp7.longestSpan() << std::endl;   // Should be 100
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n======= TEMPLATE FUNCTION TESTS ============" << std::endl;

    // Test 7: addNumbers with different containers
    try
    {
        std::cout << "Test 7: Using addNumbers with array..." << std::endl;
        Span sp8 = Span(10);
        int arr[] = {1, 3, 5, 7, 9};
        sp8.addNumbers(arr, arr + 5);
        std::cout << "Numbers added from array" << std::endl;
        std::cout << "Shortest span: " << sp8.shortestSpan() << std::endl; // Should be 2
        std::cout << "Longest span: " << sp8.longestSpan() << std::endl;   // Should be 8
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 8: addNumbers overflow

    try
    {
        std::cout << "Test 8: Template function overflow..." << std::endl;
        Span sp9 = Span(3);
        std::vector<int> overflow;
        overflow.push_back(1);
        overflow.push_back(2);
        overflow.push_back(3);
        overflow.push_back(4);
        overflow.push_back(5);
        sp9.addNumbers(overflow.begin(), overflow.end()); // Should throw after 3 elements
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
