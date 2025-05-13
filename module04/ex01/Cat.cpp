/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 17:41:35 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"


Cat::Cat():Animal("Cat")
{
    std::cout<< "Cat default constructor called"<<std::endl;
    this->brain = new Brain();
}

Cat::Cat(std::string type):Animal(type)
{
    std::cout<<"Cat constructor with attribute called"<<std::endl;
    this->brain = new Brain();
}
//cat destructor
Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
    if (this->brain)
        delete this->brain;
   
}

//TODO 
Cat::Cat(const Cat& obj):Animal(obj)
{
    std::cout<< "Cat copy object called"<<std::endl;
    this->brain = new Brain(*(obj.brain));
}

Cat &Cat::operator=(const Cat& obj)
{
    std::cout<<"Cat operator called"<<std::endl;
    if(this != &obj)
    {
        Animal::operator=(obj);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! 😼 " << std::endl; 
}
