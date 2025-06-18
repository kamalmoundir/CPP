/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:00:56 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 16:05:09 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
    public :
        virtual ~Base();
};

class A:public Base{};
class B:public Base{};
class C:public Base{};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);




