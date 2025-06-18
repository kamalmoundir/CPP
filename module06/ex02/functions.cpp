/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:45:22 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base * generate(void)
{   
    static bool seeded = false;
    if(!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    int randomTime = rand() % 3;
    switch(randomTime)
    {
        case 0 : {std::cout<<"A object created ."<<std::endl;return new A();}
        case 1 :  {std::cout<<"B object created ."<<std::endl;return new B();}
        default  : {std::cout<<"C object created ."<<std::endl;return new C();}
    }    
}
void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
    {
        std::cout<<"A"<<std::endl;
    }
    else if(dynamic_cast<B*>(p))
    {
        std::cout<<"B"<<std::endl;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout<<"C"<<std::endl;
    }
    else
    {
        std::cout<<"Unknown type"<<std::endl;
    }
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<"A"<<std::endl;
    }
    catch(...)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
             std::cout<<"B"<<std::endl;
        }
        catch(...)
        {
    
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout<<"C"<<std::endl;
            }
            catch(...)
            {
                std::cout<<"Unknown type"<<std::endl;
            }
        }
    }
    
}