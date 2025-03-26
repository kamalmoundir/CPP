/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:09:30 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/11 21:31:37 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}
void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
std::string Contact::getFirstName(void)
{
    return (this->firstName);
}
void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
std::string Contact::getLastName(void)
{
    return(this->lastName);
}
void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}
std::string Contact::getNickName(void)
{
    return(this->nickName);
}
void Contact::setPhoneNumber(std::string phoneNumber) 
{
    this->phoneNumber = phoneNumber;
}
std::string Contact::getPhoneNumber(void)
{
    return(this->phoneNumber);
}
void Contact::setDarkestScret(std::string darkestScret)
{
    this->darkestScret = darkestScret;
}
std::string Contact::getDarkestScret()
{
    return(this->darkestScret);
}