/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:49:53 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/13 21:54:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>


class PhoneBook
{
private:
    Contact contact[8];
    int number;
    
public:
    PhoneBook();
    ~PhoneBook();
   void  AddContact(Contact newContact);
   void  SearchContact(int index);
   void  ListContact(void);
};


#endif