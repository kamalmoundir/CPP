/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:26:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 14:45:21 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("wrong animal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type):_type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
        *this = obj;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &obj)
        this->_type = obj._type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}