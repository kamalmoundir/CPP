/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:41:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 16:00:13 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardon", false, 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardon", false, 25, 5),_target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other),_target(other._target)
{}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}
void PresidentialPardonForm::execute( const Bureaucrat& executor) const
{
   
    
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}