/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:21:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/26 21:25:24 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout<<"Error: could not open file."<<std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadData("data.csv");
    exchange.exchangeProcess(av[1]);
    
    return 0;
}