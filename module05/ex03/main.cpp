/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:50:55 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 17:21:05 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "========= TESTING INTERN =========\n" << std::endl;

    Intern someRandomIntern;
    AForm* form;

    // Test 1: Valid form creation
    std::cout << "--- Test 1: shrubbery creation ---" << std::endl;
    try {
        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: robotomy request ---" << std::endl;
    try {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: presidential pardon ---" << std::endl;
    try {
        form = someRandomIntern.makeForm("presidential pardon", "Arthur");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Invalid form name
    std::cout << "\n--- Test 4: invalid form ---" << std::endl;
    try {
        form = someRandomIntern.makeForm("unknown form", "target");
        delete form;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n========= END TESTS =========\n" << std::endl;
    return 0;
}

