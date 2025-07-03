/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:53:45 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/27 14:20:43 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <climits>

class RPN
{
    private :
            bool isNumber(const char token);
            bool isOperator(const char token);
            int operation(const int a, const int b, const char op);
    public:
            RPN();
            RPN(const RPN& other);
            RPN& operator=(const RPN& other);
            ~RPN();
            int calculate(const std::string& expression);
};
#endif