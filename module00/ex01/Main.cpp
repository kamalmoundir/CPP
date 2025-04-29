/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:21:10 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/07 14:43:25 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"


Contact inputContact()
{
  Contact newContact;
  std::string cmd;
  int number;

  std::cout <<"enter name :";
  std::getline(std::cin, cmd);
  newContact.setFirstName(cmd);
  
  std::cout <<"enter last name :";
  std::getline(std::cin, cmd);
  newContact.setLastName(cmd);
  
  std::cout <<"enter nickname :";
  std::getline(std::cin, cmd);
  newContact.setNickName(cmd);
  
  std::cout <<"enter darkest secret :";
  std::getline(std::cin, cmd);
  newContact.setDarkestScret(cmd);
  
  std::cout <<"enter phone number:";
  std::getline(std::cin, cmd);
  newContact.setPhoneNumber(cmd);
  std::cout << std::endl;

  return newContact;
}
bool isNumeric(std::string str)
{
  if(str.empty()) return false;
  for(char c: str)
  {
    if(!isdigit(c)) return false;
  }
  return true;
}

int main(void)
{
 
  PhoneBook phoneBook1;
  Contact newContact;
  std::string cmd;
  
  int i = 0;
  while(true)
  {
  
  std::cout<<"Enter your choice : (ADD | SEARCH | EXIT) : ";
  std::getline(std::cin,cmd);
  if(std::cin.eof())
  {
    std::cout << std::endl;
    break;
  }
  if(!cmd.compare("ADD"))
  {
    newContact = inputContact();
    phoneBook1.AddContact(newContact);
  }
  else if(!cmd.compare("SEARCH"))
  {
    phoneBook1.ListContact();
    std::string  cmd1;
    int index;
    std::cout<< "Enter phone index  : ";
    std::getline(std::cin,cmd1);
    std::cout << std::endl;
    if(isNumeric(cmd1))
    {
      index = stoi(cmd1);
      phoneBook1.SearchContact(index);
    }
  }
  else if(!cmd.compare("EXIT"))
   break;
  i++;
  }
  return 0;
}