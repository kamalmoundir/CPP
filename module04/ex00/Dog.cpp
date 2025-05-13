/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:00 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 13:21:24 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(std::string type):Animal(type)
{
    std::cout<<"Dog constructor with attribut called"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor Called"<<std::endl;
}

Dog::Dog(Dog& obj):Animal(obj)
{
    std::cout<<"Dog object copy called"<<std::endl;
}

Dog &Dog::operator=(const Dog& obj)
{
    std::cout<<"Dog operator called"<<std::endl;
    Animal::operator=(obj);
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wolf \U0001F436" << std::endl;
}