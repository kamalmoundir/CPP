/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:14:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/05 20:27:36 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
            int _rawBits;
            static const int _fractionalBits = 8; 
    public:
    Fixed();
    Fixed (const Fixed& FixedCopy);
    ~Fixed();
    Fixed &operator =(const Fixed& fix);
    int getRawBits( void )const;
    void setRawBits( int const raw );
    
    
};


#endif