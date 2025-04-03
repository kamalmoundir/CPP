/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:07 by kmoundir          #+#    #+#             */
/*   Updated: 2025/03/27 17:51:55 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{  
   std::string names = "zombie";
  Zombie* zombies =zombieHorde(4,names) ;
  for(int i = 0; i< 4 ;i++)
  zombies->announce();
  delete[] zombies;   
   return (0); 
}