/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:47 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 10:54:39 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("Animal")
{
    std::cout << "Animal Default Constructor Called"<<std::endl;
}

Animal::Animal(const std::string type):_type(type)
{
    std::cout << "Animal Constructor with attribut  Called"<<std::endl;
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal copy object called" <<std::endl;
    *this = obj;
}

Animal::~Animal()
{
    std::cout<< "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& obj)
{
    std::cout << "Animal operator called"<<std::endl;
    if(this != &obj)
        this->_type = obj._type;    
    return (*this);
}

std::string Animal::getType(void)const
{
    return (this->_type);
}

void Animal::makeSound(void) const
{
    std::cout<< "Animal make no Sound"<<std::endl;
}