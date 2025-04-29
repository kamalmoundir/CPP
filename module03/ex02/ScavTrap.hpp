/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:27:01 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/27 17:25:35 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap:public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(ScavTrap& obj);
    ~ScavTrap();
    ScavTrap &operator = (const ScavTrap &obj);
    void guardGate();
    void attack(const std::string& target);
    
};
#endif