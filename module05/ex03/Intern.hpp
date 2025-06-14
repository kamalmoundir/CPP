/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:25:02 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 16:51:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
    public:
            Intern();
            Intern(const Intern& other);
            Intern& operator=(const Intern& other);
            ~Intern();
            AForm* makeForm(const std::string &formName, const std::string &target);

    class FormNotFoundException : public std::exception
    {
        public:
            virtual const char *what() const throw();   
    };
                
};

#endif