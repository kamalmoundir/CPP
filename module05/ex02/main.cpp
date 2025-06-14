/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:50:55 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 16:01:00 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "========= TESTING FORM EXECUTION =========" << std::endl;

    try {
        // Create bureaucrats with different grades
        Bureaucrat lowGrade("Intern", 150);
        Bureaucrat midGrade("Manager", 50);
        Bureaucrat highGrade("President", 1);

        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm shrub("Garden");
        std::cout << shrub << std::endl;
        
        midGrade.signForm(shrub);
        midGrade.executeForm(shrub);

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        RobotomyRequestForm robot("Target1");
        std::cout << robot << std::endl;
        
        midGrade.signForm(robot);
        midGrade.executeForm(robot);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        PresidentialPardonForm pardon("Criminal");
        std::cout << pardon << std::endl;
        
        highGrade.signForm(pardon);
        highGrade.executeForm(pardon);

        std::cout << "\n--- Testing insufficient privileges ---" << std::endl;
        try {
            lowGrade.executeForm(shrub);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
        try {
            RobotomyRequestForm unsignedForm("UnsignedTarget");
            midGrade.executeForm(unsignedForm);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

