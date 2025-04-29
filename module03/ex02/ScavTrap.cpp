/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:27:04 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 16:45:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_hitPoints = 100;
    std::cout <<"ScavTrap default constructor called "<< std::endl;
}
ScavTrap::ScavTrap(const std::string& name):ClapTrap(name)
{
    this->_name = name;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_hitPoints = 100;
    std::cout <<"ScavTrap  "<< name <<"  constructor called "<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap& obj):ClapTrap(obj)
{
   std::cout << "ScavTrap copy constructor called for "<< this->_name<<std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for  " <<this->_name<<std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    ClapTrap::operator=(obj);
    return *this;
}
void ScavTrap::attack(const std::string& target)
{
    if(_hitPoints <= 0)
    {
        std::cout << "ScavTrap " <<_name <<" can't attack because it has no hit point left!!"<<std::endl;
        return;
    }
    if(_energyPoints <= 0)
    {
        std::cout <<"ScavTrap " <<_name <<" can't attack because it has no energy point left!!"<<std::endl;
        return;
    }
    std::cout << "ScavTrap "<<_name <<" attacks "<< target<<", damage "<< _attackDamage<<" points of damage!"<<std::endl;
    _energyPoints --;
}
void ScavTrap::guardGate()
{
    std::cout <<"ScavTrap "<< this->_name <<"  is now in Gate keeper mode."<< std::endl;
}