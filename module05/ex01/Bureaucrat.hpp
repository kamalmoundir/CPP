/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:27:13 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/17 12:21:46 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
   private:
   const std::string _name;
   int _grade;

   public :
   Bureaucrat();
   Bureaucrat(const std::string& name, int grade);
   ~Bureaucrat();
   Bureaucrat(const Bureaucrat& obj);
   Bureaucrat &operator=(const Bureaucrat &obj);
   std::string getName() const;
   int getGrade() const;
   
   void incrementGrade();
   void decrementGrade();

   void signForm(Form &form);
   
   class GradeTooHighException: public std::exception
   {
      public :
         const char *what() const throw();
   };
   
   class GradeTooLowException: public std::exception
   {
      public :
         const char *what() const throw(); 
   };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif