/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:26:49 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 13:52:10 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_HPP
# define AFORM_HPP

#include<string>
#include<iostream>
#include<exception>


class Bureaucrat;

class AForm
{
    private:
    
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        AForm();
        AForm(const std::string &name, const bool isSigned,const int gradeToSign,const int gradeToExecute);
        virtual ~AForm();
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        std::string getName()const;
        bool getIsSigned() const;
        int getGradeToSign() const ;
        int getGradeToExecute() const ;
        virtual void execute(const  Bureaucrat& executor) const = 0;
        void beSigned(Bureaucrat &bureaucrat);
         
        class GradeTooHighException: public std::exception
        {
            public :
               virtual const char  *what() const throw();  
        };
        
        class  GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
        
        class FormNotSignedException :public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os,const AForm &form);


#endif