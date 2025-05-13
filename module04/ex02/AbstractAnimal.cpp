/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:47 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 11:00:32 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal():_type("Animal")
{
    std::cout << "Animal Default Constructor Called"<<std::endl;
}

AbstractAnimal::AbstractAnimal(const std::string type):_type(type)
{
    std::cout << "Animal Constructor with attribut  Called"<<std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal& obj)
{
    std::cout << "Animal copy object called" <<std::endl;
    *this = obj;
}

AbstractAnimal::~AbstractAnimal()
{
    std::cout<< "Animal destructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal& obj)
{
    std::cout << "Animal operator called"<<std::endl;
    if(this != &obj)
        this->_type = obj._type;    
    return (*this);
}

std::string AbstractAnimal::getType(void)const
{
    return (this->_type);
}
