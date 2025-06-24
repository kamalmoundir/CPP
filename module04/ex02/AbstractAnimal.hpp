/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:53 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/18 12:27:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

#include<iostream>

class AbstractAnimal
{
    protected:
        std::string _type;
        
    public:
    AbstractAnimal();
    AbstractAnimal(const std::string type);
    AbstractAnimal(const AbstractAnimal& obj);
    AbstractAnimal &operator=(const AbstractAnimal& obj);
    virtual ~AbstractAnimal();
    std::string getType(void)const;
    virtual void makeSound(void) const = 0;
};

#endif