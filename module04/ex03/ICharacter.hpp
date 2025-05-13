/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:49:34 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 12:54:10 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

#endif