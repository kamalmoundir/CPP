/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:31:27 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/17 12:38:49 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

#include<string>
#include<iostream>
#include<exception>


class Bureaucrat;

class Form
{
    private:
    
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        Form();
        Form(const std::string &name, const bool isSigned,const int gradeToSign,const int gradeToExecute);
        ~Form();
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        std::string getName()const;
        bool getIsSigned() const;
        int getGradeToSign() const ;
        int getGradeToExecute() const ;
        
        class GradeTooHighException: public std::exception
        {
            public :
                const char  *what() const throw();  
        };
        
        class  GradeTooLowException : public std::exception
        {
            public :
                const char *what() const throw();
        };

        void beSigned(Bureaucrat &bureaucrat); 
    
};

std::ostream &operator<<(std::ostream &os,const Form &form);


#endif