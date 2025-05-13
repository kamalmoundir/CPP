/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:28:48 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:17 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "default";
    this->_hitPoints = FragTrap::_hitPoints;     // 100 from FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;     // 100 from FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
    this->_name = obj._name;
    std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
        this->_name = obj._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    // Using ScavTrap's attack function as required
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

