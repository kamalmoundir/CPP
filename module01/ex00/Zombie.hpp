/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:04 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 15:55:07 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private :
    std::string _name;
    
    public:
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
    std::string getName(void);
};
void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif