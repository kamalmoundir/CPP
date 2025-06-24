/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:35:28 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/19 16:10:15 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(T* array, size_t length, void (*func)(const T&))
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}