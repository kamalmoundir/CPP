/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:41:09 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 16:00:41 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", false, 72, 45), _target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", false, 72, 45),_target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other),_target(other._target)
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout<<" Drilling Noise "<< std::endl;
    srand(time(NULL));
    if(rand() % 2)
        std::cout <<_target <<" has been robotomized successfully!"<<std::endl;
    else
        std::cout << "Robotomy of "<<_target <<" failed!"<< std::endl;
}