/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 13:09:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "iostream"

class Dog:public Animal
{
    public:
    Dog();
    Dog(std::string type);
    Dog(Dog& obj);
    Dog &operator=(const Dog& obj);
    ~Dog();
   void makeSound(void) const override;
    
};

#endif