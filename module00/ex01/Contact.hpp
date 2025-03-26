/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:15:41 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/11 21:33:39 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private :
    
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestScret;

    public :
     Contact();
     ~Contact();
     void setFirstName(std::string firstName);
     void setLastName(std::string lastName);
     void setNickName(std::string nickName);
     void setPhoneNumber(std::string phoneNumber);
     void setDarkestScret(std::string darkestScret);
     std::string getFirstName(void);
     std::string getLastName(void);
     std::string getNickName(void);
     std::string getPhoneNumber(void);
     std::string getDarkestScret();
};

#endif