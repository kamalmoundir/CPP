/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:58:17 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 16:45:10 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{ this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_hitPoints = 100;
    std::cout<<"FragTrap default constructor called"<<std::endl;
}

FragTrap::FragTrap(const std::string &name):ClapTrap(name)
{
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_hitPoints = 100;
    std::cout<<"FragTrap  " <<name<< " constructor called" <<std::endl;
}
FragTrap::FragTrap(FragTrap& obj):ClapTrap(obj)
{
    std::cout<<"FragTrap copy constructor called for "<<this->_name<<std::endl;
}
FragTrap &FragTrap::operator = (const FragTrap& obj)
{
    std::cout<<"FragTrap assignment operation called"<<std::endl;
    ClapTrap::operator=(obj);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap destructor called for "<<this->_name<<std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::cout <<"FragTrap  "<<this->_name<<" requests a positive high five! "<< std::endl;
}
void FragTrap::attack(const std::string& target)
{
    if(_hitPoints <= 0)
    {
        std::cout << "FragTrap " <<_name <<" can't attack because it has no hit point left!!"<<std::endl;
        return;
    }
    if(_energyPoints <= 0)
    {
        std::cout <<"FragTrap " <<_name <<" can't attack because it has no energy point left!!"<<std::endl;
        return;
    }
    std::cout << "FragTrap "<<_name <<" attacks "<< target<<", damage "<< _attackDamage<<" points of damage!"<<std::endl;
    _energyPoints --;
}