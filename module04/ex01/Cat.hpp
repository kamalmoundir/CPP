/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:42 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 16:36:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat:public Animal
{
    private:
    Brain* brain;
    
    public:
    Cat();
    Cat(std::string type);
    Cat(const Cat& obj);
    ~Cat();
    Cat &operator=(const Cat& obj);
    void makeSound() const override;
};

#endif