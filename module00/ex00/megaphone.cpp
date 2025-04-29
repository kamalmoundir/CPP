/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:26:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/07 14:29:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int main(int ac, char **av)
{
    int i = 1;
    int j;
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << std::endl;
        return 0;
    }
    else
    {
        while(i < ac)
        { 
            j = 0;
            while(av[i][j])
            {   
                std::cout << (char)toupper(av[i][j]);
                j ++;
            }
            i ++;
        }    
    }
    std::cout << std::endl;
    return 0;    
}