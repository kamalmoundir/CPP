/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:07 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/07 14:47:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook():number(0){}
PhoneBook::~PhoneBook(){}

void PhoneBook::AddContact(Contact newContact)
{
        int i = 0;
        if(number < 8)
        {
            contact[number] = newContact;
            number ++;
        }
        else
        {
            contact[number -1] = newContact;
        }
}
void PhoneBook::SearchContact(int index)
{
    int i ;
    
    i = 0;
    while(i < 8 && !contact[i].getFirstName().empty())
        i++;
    if(index <= i && index <= 8 && index > 0)
    {
    std::cout<<"First Name: "+contact[index - 1].getFirstName()<<std::endl;
    std::cout<<"Last Name: "+contact[index - 1].getLastName()<<std::endl;
    std::cout<<"NickeName: "+contact[index - 1].getNickName()<<std::endl;
    std::cout<<"Darkest Secrete: "+contact[index - 1].getDarkestScret()<<std::endl;
    std::cout<<"Phone Number: "+contact[index - 1].getPhoneNumber()<<std::endl; 
    }
}

void PhoneBook::ListContact(void)
{
    if (number == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|" << std::setw(10) << "INDEX"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "NickName"
              << "|" << std::endl;

    std::cout << "+-------------------------------------------+" << std::endl;

    for (int i = 0; i < number; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1;
        
        std::cout << "|" << std::setw(10) << (contact[i].getFirstName().size() > 10 
            ? contact[i].getFirstName().substr(0, 9) + "." 
            : contact[i].getFirstName());

        std::cout << "|" << std::setw(10) << (contact[i].getLastName().size() > 10 
            ? contact[i].getLastName().substr(0, 9) + "." 
            : contact[i].getLastName());

        std::cout << "|" << std::setw(10) << (contact[i].getNickName().size() > 10 
            ? contact[i].getNickName().substr(0, 9) + "." 
            : contact[i].getNickName())
            << "|" << std::endl;
    }
    std::cout << "+-------------------------------------------+" << std::endl;

}