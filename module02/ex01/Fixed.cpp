/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:21:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/23 11:27:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_rawBits(0)
{
    std::cout<< "Default constructor called" <<std::endl;
}
//convert integer into fixed point
Fixed::Fixed(const int rowBits)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(rowBits << this->_fractionalBits);// or _rowBits = rowBits* 256(2power (_fractionalBits))
}
//float construtor 
Fixed::Fixed(const float rowBits)
{   
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(rowBits *(1 << this->_fractionalBits)));
}

// Copy constructor
Fixed::Fixed (const Fixed& FixedCopy)
{
    std::cout<< "Copy constructor called" << std::endl;
    this->setRawBits(FixedCopy.getRawBits());
}
//convert  fixed point to integer
int Fixed::toInt(void) const
{
    return (this->getRawBits() >> _fractionalBits);
}

//convert fixed point to float
float Fixed::toFloat(void) const
{
    return ((float)(this->getRawBits())/(1 << _fractionalBits));
}



Fixed::~Fixed()
{
    std::cout<< "Destructor called" <<std::endl;
}

Fixed &Fixed::operator = (const Fixed& FixedCopy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &FixedCopy)
    {
        this->setRawBits(FixedCopy.getRawBits());
    }
    return *this;
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::getRawBits(void)const
{
  
    return(this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits =raw;
}

