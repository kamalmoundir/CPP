/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:21:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/16 12:24:31 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_rawBits(0){}

//contructor convert integer into fixed point
Fixed::Fixed(const int rowBits)
{
    //std::cout << "Int constructor called" << std::endl;
    this->setRawBits(rowBits << this->_fractionalBits);// or _rowBits = rowBits* 256(2power (_fractionalBits))
}
//float construtor 
Fixed::Fixed(const float rowBits)
{   
    this->setRawBits(roundf(rowBits *(1 << this->_fractionalBits)));
}
// Copy constructor
Fixed::Fixed (const Fixed& FixedCopy)
{
   // std::cout<< "Copy constructor called" << std::endl;
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
Fixed::~Fixed(){}

Fixed &Fixed::operator =(const Fixed& FixedCopy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &FixedCopy)
    {
        this->setRawBits(FixedCopy.getRawBits());
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::getRawBits( void )const
{
  
    return(this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits =raw;
}

//operators

//The 4 increment/decrement
//suffix operator ++a
Fixed &Fixed::operator ++()
{
    this->_rawBits += 1;
    return *this;
}

//postfix operator a++
Fixed  Fixed::operator ++(int)
{
    Fixed tmp = *this;
    this->setRawBits(_rawBits + 1);
    return tmp;
}
Fixed &Fixed::operator --()
{ 
    this->setRawBits(_rawBits - 1);
    return (*this);
}

Fixed Fixed::operator --(int)
{
    Fixed tmp = *this;
    this->setRawBits(_rawBits - 1);
    return tmp;
}

//the 4 Arithmetic operators
Fixed Fixed::operator *(const Fixed &obj)const
{
    Fixed tmp;
    tmp.setRawBits((this->_rawBits * obj.getRawBits()) >> _fractionalBits);
    return tmp;
}

Fixed Fixed::operator +(const Fixed &obj)const
{
    Fixed tmp;
    tmp.setRawBits((this->getRawBits() + obj.getRawBits()));
    return tmp;
    
}

Fixed Fixed::operator -(const Fixed &obj)const
{
    Fixed tmp;
    tmp.setRawBits((this->getRawBits() - obj.getRawBits()));
    return tmp;
}

Fixed Fixed::operator /(const Fixed &obj)const
{

    if(obj.getRawBits() == 0)
    {
        throw std::runtime_error("ERROR devision by 0");
    }  
    Fixed tmp;
    tmp.setRawBits((this->getRawBits() << _fractionalBits )/ obj.getRawBits()) ;
    return tmp;
}

//The 6 comparison operators
bool Fixed::operator > (const Fixed &obj)const
{
    return(this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator < (const Fixed &obj)const
{
    return(this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator <= (Fixed &obj)const
{
    return(this->getRawBits() <= obj.getRawBits());
}
bool Fixed::operator >= (Fixed &obj)const
{
    return(this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator == (Fixed &obj)const
{
    return(this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator != (Fixed &obj)const
{
    return(this->getRawBits() != obj.getRawBits());
}

//min and max

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
    return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return((a > b) ? a : b);
}
const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a > b) ? a : b);
}
