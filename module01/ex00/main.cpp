/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:07 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/11 10:55:07 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{  
   std::string zombieName;
   std::string zombieName1;
   
   std::cout << "Enter zombie(stack) name :";
   std::getline(std::cin, zombieName);

   if (std::cin.eof() == true){
		std::cin.clear();
		clearerr(stdin);
		std::cout << "EOF detected, exiting program." << std::endl;
      return 1;
	}
   randomChump(zombieName);
   std::cout << "Enter zombie(heap) name ";
   std::getline(std::cin, zombieName1);

   if (std::cin.eof() == true)
   {
		std::cin.clear();
		clearerr(stdin);
		std::cout << "EOF detected, exiting program." << std::endl;
      return 1;
	}
   Zombie *n_zombie = newZombie(zombieName1);
   n_zombie->announce();
   delete n_zombie;
   
   
   return (0); 
}