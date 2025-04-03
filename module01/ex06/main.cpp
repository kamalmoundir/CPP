/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:13:30 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/03 16:18:25 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac , char **av)
{
    if(ac != 2 || !av[1])
    {
        std::cout<<"ERROR in arguments\n";
        return 1;   
    }
    else
    {
        Harl harl;
        
        harl.complain(av[1]);
    }
    return (0);
}