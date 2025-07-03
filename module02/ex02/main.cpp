/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:14:17 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/23 11:34:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"




int main( void ) {
    
Fixed  a;
Fixed b( Fixed(5.05f) * Fixed(2) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max(a, b) << std::endl;
return 0;
}

/*
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.5f ) * Fixed( 2 ) );

//Fixed c(5);
Fixed  k(3.1f);
Fixed  x(2);
float z= 5 / 2;

std::cout << k + x << std::endl;
std::cout << k - x<< std::endl;
std::cout << (z) << std::endl;
try {
    std::cout<<"k / x =" << k / x << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
}
std::cout << " a :" <<a << std::endl;
std::cout << ++ a << std::endl;
std::cout << a << std::endl;
std::cout << a << std::endl;
std::cout << "a:"<<a << std::endl;
std::cout << b << std::endl;

if((k > x))
std::cout << "true" << std::endl;
else
std::cout << "false" << std::endl;
std::cout << Fixed::max( k, x ) << std::endl;
std::cout << Fixed::min( k, x ) << std::endl;
return 0;
}*/