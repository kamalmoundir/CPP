/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:07:43 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 22:42:39 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
     std::string name;
     Weapon *weapon;   
    public:
    void attack();
    void setWeapon(Weapon &weapon);
    HumanB(std::string name);
    ~HumanB();
    
};

#endif