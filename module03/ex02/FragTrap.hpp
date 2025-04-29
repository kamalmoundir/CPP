/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:58:04 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 16:16:52 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
    public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(FragTrap& obj);
    FragTrap &operator = (const FragTrap& obj);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys(void);
    private:
    
};

#endif