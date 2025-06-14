/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:25:52 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 17:30:46 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, bool isSigned, const int gradeToSign, const int gradeToExecute) : _name(name),_isSigned(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    (void)isSigned;
    std::cout << "AForm constructor with attributes called" << std::endl;
    if(gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if(gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "AForm copy object" << std::endl;
    if(this != &obj)
    {
        this->_isSigned = obj.getIsSigned();      
    }
}

AForm &AForm::operator=(const AForm &obj)
{
    std::cout << "AForm operator" << std::endl;
    if (this != &obj)
    {
        this->_isSigned = obj.getIsSigned();
    }
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

const char  *AForm::GradeTooHighException::what() const throw()
{
   return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
    
}
const char *AForm::FormNotSignedException::what() const throw()
{
        return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os,const AForm &form)
{
    os << "AForm :" << form.getName() << "\n- grade to sign :" << form.getGradeToSign() ;
    os <<"\n- grade to execute :" << form.getGradeToExecute() << "\n- is signed :"<< form.getIsSigned()<<std::endl;
    return os;
}