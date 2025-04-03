/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:06:32 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/03 16:06:34 by kmoundir         ###   ########.fr       */
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