/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:07:39 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 22:45:01 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    
    this->name=name;
}
HumanB::~HumanB()
{
    
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
void HumanB::attack()
{
    std::cout<<this->name<<" attacks with their " <<(*this->weapon).getType()<<std::endl;
}