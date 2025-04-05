/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:21:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/05 20:43:15 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_rawBits(0){
    std::cout<< "Default constructor called" <<std::endl;
}
Fixed::Fixed (const Fixed& FixedCopy)
{
    std::cout<< "Copy constructor called" <<std::endl;
    this->setRawBits(FixedCopy.getRawBits());
}

Fixed::~Fixed(){
    std::cout<< "Destructor called" <<std::endl;
}


Fixed &Fixed::operator =(const Fixed& FixedCopy)
{
    std::cout << "Copy assignation operator called" << std::endl;
    //std::cout << "Debug: Assignment operator is running" << std::endl;
   // if(this != &FixedCopy)
   // {
        this->setRawBits(FixedCopy.getRawBits());
   // }
    return *this;
}

int Fixed::getRawBits( void )const
{
   std::cout << "getRawBits member function called" << std::endl;
    return(this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits =raw;
}

