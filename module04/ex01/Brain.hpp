/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:28 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/08 10:41:59 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
    std::string _ideas[100];
    public:
    Brain();
    ~Brain();
    Brain(const Brain& copy);
    Brain &operator=(const Brain& obj); 
};

#endif