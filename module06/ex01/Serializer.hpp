/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:25:50 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 13:21:14 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"
#include <iostream>

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
       
    public:
     static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);  
};

#endif