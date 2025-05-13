/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:26:34 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 15:41:29 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
    std::string _type;
    
    public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &obj);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal& obj);
    void makeSound() const;
    std::string getType(void) const;
};
#endif