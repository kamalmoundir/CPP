/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:17:26 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/27 17:56:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called ." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor of " << _name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor of " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : _name(obj._name), _hitPoints(obj._hitPoints)
, _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
    std::cout<<"ClapTrap copy constructor called for "<< _name <<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;

    if (this != &obj)
    {
        this->_name = obj._name;
        this->_hitPoints = obj._hitPoints;
        this->_energyPoints = obj._energyPoints;
        this->_attackDamage = obj._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if(_hitPoints <= 0)
    {
        std::cout << "ClapTrap " <<_name <<" can't attack because it has no hit point left!!"<<std::endl;
        return;
    }
    if(_energyPoints <= 0)
    {
        std::cout <<"ClapTrap " <<_name <<" can't attack because it has no energy point left!!"<<std::endl;
        return;
    }
    std::cout << "ClapTrap "<<_name <<" attacks "<< target<<", damage "<< _attackDamage<<" points of damage!"<<std::endl;
    _energyPoints --;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitPoints <= 0)
    {
        std::cout<< "ClapTrap " << _name << " is already destroyed" << std::endl;
        return;
    }
    if(amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << " ClapTrap "<< _name << " takes " << amount << " points of damage! Hit points reamining: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name <<" can't repair itself because it has no hit points left!" << std::endl;
        return;
    }
    if(_energyPoints <= 0)
    {
        std::cout << "ClapTrap " <<_name << " can't repair itself because it has no energy points left!" <<std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints --;
    
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
          << " points! Hit points: " << _hitPoints << std::endl;
    
}
