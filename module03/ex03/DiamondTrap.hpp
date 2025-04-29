/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:28:53 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 19:40:42 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap:public ScavTrap ,public FragTrap
{
    private:
    std::string _name;
    
    public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap &obj);
    ~DiamondTrap();
    
    
};

#endif