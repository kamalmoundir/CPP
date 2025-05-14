/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:28:57 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/14 11:54:30 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor with attributes called" << std::endl;
    // code
}
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}
Form::Form(const Form &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "Form copy object" << std::endl;
    // code todo
}

Form &Form::operator=(Form &obj)
{
    std::cout << "Form " << std::endl;
    if (this != &obj)
    {
        this->_isSigned = obj.getIsSigned();
    }
    return *this;
}

std::string Form::getName()
{
    return this->_name;
}

bool Form::getIsSigned()
{
    return this->_isSigned;
}

int Form::getGradeToSign()
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute()
{
    return this->_gradeToSign;
}



const char  *Form::GradeTooHighException::what() const throw()
{
   return "";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "";
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
    os << "Name :" << form.getName() << ", grade to sign " << form.getGradeToSign() ;
    os <<", grade to execute " << form.getGradeToExecute() << ", is signed :"<< form.getIsSigned()<<std::endl;
}