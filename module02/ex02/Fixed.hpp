/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:14:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/16 12:12:34 by kmoundir         ###   ########.fr       */
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
    ~Fixed();
    
    Fixed(const int rowBits);
    Fixed(const float rowBits);
    
    Fixed &operator =(const Fixed& FixedCopy);
    Fixed (const Fixed& FixedCopy);
   
    
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void )const;
    void setRawBits( int const raw );
    
    //The 4 increment/decrement
    //suffix operator ++a
    Fixed &operator ++();
    
    //postfix &operator a++
    Fixed operator ++(int);
    Fixed &operator --();
    Fixed operator --(int);
    
    //the 4 arithmetic operators
    Fixed operator *(const Fixed &obj)const;
    Fixed operator +(const Fixed &obj)const;
    Fixed operator -(const Fixed &obj)const;
    Fixed operator /(const Fixed &obj)const;
    
    //The 6 comparison operators
   bool operator > (const Fixed &obj)const;
   bool operator < (const Fixed &obj)const;
   bool operator <= (Fixed &obj)const;
   bool operator >= (Fixed &obj)const;
   bool operator == (Fixed &obj)const;
   bool operator != (Fixed &obj)const;

   //min and max functions
static Fixed &min(Fixed& a, Fixed& b);
static const Fixed &min(const Fixed& a, const Fixed& b);
static Fixed &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed& a,const Fixed& b); 
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif