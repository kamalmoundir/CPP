/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:31:54 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/03 15:49:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include<iostream>
#include<string>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning(void );
    void error(void); 
public:
    Harl();
    ~Harl();
    void complain( std::string level );
};



#endif