/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:14:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/12 14:52:50 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
            int _rawBits;
            static const int _fractionalBits = 8; 
    public:
    Fixed();
    Fixed(const int rowBits);
    Fixed(const float rowBits);
    Fixed &operator =(const Fixed& FixedCopy);
    Fixed (const Fixed& FixedCopy);
    ~Fixed();
    
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void )const;
    void setRawBits( int const raw );
    
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif