/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:09:28 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/17 13:15:05 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_name("default"),_grade(150)
{
    std::cout <<"Bureaucrat default constructor called"<<std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name)
{
   std::cout<<"Bureaucrat Constructor with attribute called"<<std::endl;
   if(grade < 1)
   {
        throw GradeTooHighException();
   }
   else if( grade > 150)
   {
        throw GradeTooLowException(); 
   }
   else
   _grade = grade;
}
Bureaucrat::~Bureaucrat()
{
    std::cout <<"Bureaucrat destructor called" <<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):_name(obj.getName())
{
    std::cout<<"Bureaucrat copy object called"<<std::endl;
    this->_grade = obj.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout <<"Bureaucrat operator called"<<std::endl;
    
    if(this != &obj)
    {
        _grade = obj.getGrade();
    }
    
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if(_grade <= 1)
    {
        throw GradeTooHighException();
    }
    _grade --;
}

void Bureaucrat::decrementGrade()
{
    if(_grade >= 150)
    {
        throw GradeTooLowException();
    }
    _grade ++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
 return "Grade too high (must be between 1 and 150)";;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
   return "Grade too low (must be between 1 and 150)";;
}

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() <<", bureaucrat grade "<< bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(Form &form)
{
  try
  {
    form.beSigned(*this);
    std::cout<<_name <<" signed "<<form.getName()<<std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout <<_name <<" couldn’t sign " << form.getName()<<" because  "<< e.what() << '\n';
  }
}