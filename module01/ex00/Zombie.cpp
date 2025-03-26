/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:01 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/26 18:08:40 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <string>


Zombie::Zombie()
{
    
}
Zombie::~Zombie()
{
    std::cout << this->getName()<<" test test "<<std::endl;
}
std::string Zombie::getName(void)
{
    return this->_name;  
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}
