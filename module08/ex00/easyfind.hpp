/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:43:44 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/23 13:58:06 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

class easyfindException: public std::exception
{
    public :
    
    const char* what() const throw()
    {
        return "Error: value not found";
    }
};

template<typename T>
bool easyfind(T& container, int value);

#include "easyfind.tpp"