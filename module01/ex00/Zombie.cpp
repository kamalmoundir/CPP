/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:01 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/11 10:55:58 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <string>


Zombie::Zombie()
{
    
}
Zombie::~Zombie()
{
    std::cout << this->getName()<<"'s destructor was called : is dead "<<std::endl;
}
void Zombie::announce(void)
{
    std::cout<<this->_name <<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
std::string Zombie::getName(void)
{
    return this->_name;  
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}
