/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:35:47 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/19 14:20:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}
template <typename T>
const T& min(T& a, T& b)
{
    return a < b ? a : b;
}

template <typename T>
const T& max(T& a, T& b)
{
    return a > b ? a : b;
}