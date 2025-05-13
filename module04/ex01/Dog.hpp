/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 17:44:31 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "iostream"
#include "Brain.hpp"

class Dog:public Animal
{
    private:
    Brain* _brain;
    
    public:
    Dog();
    Dog(std::string type);
    Dog(const Dog& obj);
    Dog &operator=(const Dog& obj);
    ~Dog();
   void makeSound(void) const override;
    
};

#endif