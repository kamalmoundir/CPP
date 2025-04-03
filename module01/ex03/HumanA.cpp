/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:07:46 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 23:15:27 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name_N,Weapon &weapon_N):name(name_N),weapon(weapon_N){}
HumanA::~HumanA()
{
    
}
void HumanA::attack()
{
    std::cout<<this->name<<" attacks with their " <<this->weapon.getType()<<std::endl;
}