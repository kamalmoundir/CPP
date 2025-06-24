/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:01:20 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/24 14:30:00 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <string>

int main()
{
    std::cout << "=== BASIC MUTANT STACK TEST ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Stack contents (using iterators): ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);
    std::cout << "Copied to std::stack successfully!" << std::endl;

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
    MutantStack<int> mstack2(mstack);
    std::cout << "Original size: " << mstack.size() << std::endl;
    std::cout << "Copy size: " << mstack2.size() << std::endl;
    std::cout << "Copy contents: ";
    for (MutantStack<int>::iterator it2 = mstack2.begin(); it2 != mstack2.end(); ++it2)
    {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
    try
    {
        MutantStack<int> mstack3;
        mstack3.push(999);
        mstack3 = mstack;
        std::cout << "Assigned stack contents: ";
        for (MutantStack<int>::iterator it3 = mstack3.begin(); it3 != mstack3.end(); ++it3)
        {
            std::cout << *it3 << " ";
        }
        std::cout << std::endl;

        std::cout << "\n=== REVERSE ITERATOR TEST ===" << std::endl;
        std::cout << "Stack in reverse order: ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== CONST ITERATOR TEST ===" << std::endl;
    try
    {
        const MutantStack<int> const_mstack = mstack;
        std::cout << "Const stack contents: ";
        for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit)
        {
            std::cout << *cit << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== EMPTY STACK TEST ===" << std::endl;

    try
    {
        MutantStack<int> empty_stack;
        std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
        std::cout << "Empty stack iteration: ";
        for (MutantStack<int>::iterator empty_it = empty_stack.begin(); empty_it != empty_stack.end(); ++empty_it)
        {
            std::cout << *empty_it << " ";
        }
        std::cout << "(should be empty)" << std::endl;

        std::cout << "\n=== STRING MUTANT STACK TEST ===" << std::endl;
        MutantStack<std::string> str_stack;
        str_stack.push("Hello");
        str_stack.push("World");
        str_stack.push("MutantStack");

        std::cout << "String stack contents: ";
        for (MutantStack<std::string>::iterator str_it = str_stack.begin(); str_it != str_stack.end(); ++str_it)
        {
            std::cout << *str_it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== COMPARISON WITH std::list ===" << std::endl;
    try
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::cout << "std::list contents: ";
        for (std::list<int>::iterator lst_it = lst.begin(); lst_it != lst.end(); ++lst_it)
        {
            std::cout << *lst_it << " ";
        }
        std::cout << std::endl;

        std::cout << "MutantStack behaves like list but with stack interface!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== ITERATOR MODIFICATION TEST ===" << std::endl;

    try
    {
        MutantStack<int> modify_stack;
        modify_stack.push(1);
        modify_stack.push(2);
        modify_stack.push(3);

        std::cout << "Before modification: ";
        for (MutantStack<int>::iterator mod_it = modify_stack.begin(); mod_it != modify_stack.end(); ++mod_it)
        {
            std::cout << *mod_it << " ";
        }
        std::cout << std::endl;

        // Modify through iterators
        for (MutantStack<int>::iterator mod_it = modify_stack.begin(); mod_it != modify_stack.end(); ++mod_it)
        {
            *mod_it *= 10;
        }

        std::cout << "After modification (*= 10): ";
        for (MutantStack<int>::iterator mod_it = modify_stack.begin(); mod_it != modify_stack.end(); ++mod_it)
        {
            std::cout << *mod_it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}