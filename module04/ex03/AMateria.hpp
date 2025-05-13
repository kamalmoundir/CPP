/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:33:59 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 12:49:17 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
    //TODO
    public:
    AMateria(std::string const & type);
    
  std::string const & getType() const; //Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};
#endif 