/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:28:34 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/30 23:25:56 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
 
    if(ac < 2)
    {
        std::cerr << "Invalid Number of parameters " << std::endl;
        return 1;
    }
      
    try
    {
        PmergeMe sorter;
        sorter.sort(ac, av);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}