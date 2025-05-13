/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:25:57 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 14:44:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("wrong cat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const std::string type):WrongAnimal(type)
{
    std::cout << "WrongCat constructor with attribut called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj):WrongAnimal(obj)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = obj;
}
WrongCat &WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &obj)
        this->_type = obj._type;
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

