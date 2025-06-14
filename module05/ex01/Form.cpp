/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:28:57 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 17:40:58 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, const int gradeToSign, const int gradeToExecute) : _name(name),_isSigned(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    (void)isSigned;
    std::cout << "Form constructor with attributes called" << std::endl;
    if(gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if(gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "Form copy object" << std::endl;
    if(this != &obj)
    {
        this->_isSigned = obj.getIsSigned();      
    }
}

Form &Form::operator=(const Form &obj)
{
    std::cout << "Form operator" << std::endl;
    if (this != &obj)
    {
        this->_isSigned = obj.getIsSigned();
    }
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

const char  *Form::GradeTooHighException::what() const throw()
{
   return " Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return " Grade too low";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
    
}
    

std::ostream &operator<<(std::ostream &os,const Form &form)
{
    os << "Form :" << form.getName() << "\n- grade to sign :" << form.getGradeToSign() ;
    os <<"\n- grade to execute :" << form.getGradeToExecute() << "\n- is signed :"<< form.getIsSigned()<<std::endl;
    return os;
}