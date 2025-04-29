/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:31:57 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/11 12:18:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {

    std::string input;
    Harl        harl;

        std::cout << "Enter a level: ";
        std::cin >> input;
        harl.complain(input);

    return 0;
}