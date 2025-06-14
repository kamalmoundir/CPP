/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:29:38 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 17:18:36 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern &other)
{
   (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formType[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    int found = -1;
    for(int i = 0; i < 3; i++)
    {
        if(formType[i] == formName)
        {
            found = i;
            break;
        }
    }
    AForm* form = NULL;
    
    switch(found)
    {
        case 0: form = new RobotomyRequestForm(target);break;
        case 1: form = new ShrubberyCreationForm(target);break;
        case 2: form = new PresidentialPardonForm(target);break;
        default : throw FormNotFoundException();
    }
    if(form)
        std::cout<< "Intern creates " << formName <<std::endl;
        
    return form;
}
const char* Intern::FormNotFoundException::what() const throw()
{
    return "Error: Form type not found";   
} 
