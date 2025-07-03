/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:07:29 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/27 14:26:41 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error"<< '\n';
        return 1;
    }
    try
    {
        RPN rpn;
        int result = rpn.calculate(av[1]);
        std::cout<<result<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error"<< '\n';
        return 1;
    }
    return 0;
}
