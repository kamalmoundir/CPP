/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/07 16:33:41 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
    std::cout<<"Brain Default constructor called"<<std::endl;
}

Brain::~Brain()
{
    std::cout<<"Brain destructor called!"<<std::endl;
}

Brain::Brain(const Brain& obj)
{
    std::cout<<"Brain object Copy called"<<std::endl;
    *this = obj;
    
}

Brain &Brain::operator=(const Brain& obj)
{
    std::cout<<"Brain Operator called "<<std::endl;
    if(this != &obj)
    {
        for(int i = 0; i < 100; i ++) 
        {
            this->_ideas[i] = obj._ideas[i];
        }
    }
    return (*this);
}