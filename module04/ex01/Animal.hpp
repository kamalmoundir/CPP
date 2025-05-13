/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:53 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 15:41:14 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include<iostream>

class Animal
{
    protected:
        std::string _type;
        
    public:
    Animal();
    Animal(const std::string type);
    Animal(const Animal& obj);
    Animal &operator=(const Animal& obj);
    virtual ~Animal();
    std::string getType(void)const;
    virtual void makeSound(void) const;
};

#endif