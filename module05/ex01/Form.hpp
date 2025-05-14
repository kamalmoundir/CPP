/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:31:27 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/14 11:47:46 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

#include<string>
#include<iostream>
#include<exception>


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
        Form &operator=(Form &obj);
        std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExecute();
        
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
    
};

std::ostream &operator<<(std::ostream &os,const Form &form);

#endif