/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:43:47 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/23 13:58:13 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
bool easyfind(T& container, int value)
{
    if(std::find(container.begin(), container.end(), value) == container.end())
    {
        throw easyfindException();
    }
    return true;   
}