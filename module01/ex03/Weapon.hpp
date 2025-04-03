/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:07:51 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 22:34:32 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include<iostream>

class Weapon
{
private:
    std::string type; 
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    std::string const &getType();
};

#endif