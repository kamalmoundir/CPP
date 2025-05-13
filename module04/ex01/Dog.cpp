/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:00 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 11:08:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout<<"Dog default constructor called"<<std::endl;
    this->_brain = new Brain();
}

Dog::Dog(std::string type):Animal(type)
{
    std::cout<<"Dog constructor with attribut called"<<std::endl;
    this->_brain = new Brain();
}

Dog::~Dog()
{
    std::cout<<"Dog destructor Called"<<std::endl;
    if (this->_brain)
        delete this->_brain;
}

Dog::Dog(const Dog& obj):Animal(obj)
{
    std::cout<<"Dog object copy called"<<std::endl;
    this->_brain = new Brain(*(obj._brain));
}

Dog &Dog::operator=(const Dog& obj)
{
    std::cout<<"Dog operator called"<<std::endl;
    if(this != &obj)
    {
        Animal::operator=(obj);
        if(this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(obj._brain));
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wolf \U0001F436" << std::endl;
}