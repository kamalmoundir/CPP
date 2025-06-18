/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:11 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 16:30:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>



int main(void)
{

    Base *obj= generate();
    
    std::cout<<"pointer identification:"<<std::endl;
    identify(obj);
    
    std::cout<<"reference identification:"<<std::endl;
    identify(*obj);

    delete obj;
    
    return 0;
}
