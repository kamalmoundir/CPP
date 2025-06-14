/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:41:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/14 17:31:52 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFROM_HPP
# define PRESIDENTIALPARDONFROM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
    private:

    std::string _target; 
    
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    void execute(const Bureaucrat &executor) const;
};
#endif