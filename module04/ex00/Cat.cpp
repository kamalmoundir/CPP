/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 13:13:42 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"


Cat::Cat():Animal("Cat")
{
    std::cout<< "Cat default constructor called"<<std::endl;
}

Cat::Cat(std::string type):Animal(type)
{
    std::cout<<"Cat constructor with attribute called"<<std::endl;
}
//cat destructor
Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
}

//TODO 
Cat::Cat(const Cat& obj):Animal(obj)
{
    std::cout<< "Cat copy object called"<<std::endl;
}

Cat &Cat::operator=(const Cat& obj)
{
    std::cout<<"Cat operator called"<<std::endl;
    Animal::operator=(obj);
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! \U0001F63C" << std::endl; // Unicode for 😼
}
