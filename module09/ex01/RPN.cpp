/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:15:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/27 15:13:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other)
{
    (void)other;
}
RPN &RPN::operator=(const RPN &other)
{
    (void)other;
        return *this;
}

RPN::~RPN(){}


bool RPN::isNumber(const char token)
{
    return (token >= '0' && token <= '9'); 
}
bool RPN::isOperator(const char token)
{
    return(token == '+' || token == '-' || token == '/'  || token == '*' );
}
int RPN::operation(const int a, const int b, const char op)
{
    switch(op){
        
        case '+': return (a + b);break;
        case '-':return (a - b);break;
        case '*':return (a * b);break;
        case '/':{
                    if(b != 0){
                            return (a / b);break;
                    }
                    else{
                        throw std::runtime_error("Error");
                    }
        }
        default:
        {
            throw std::runtime_error("Error");
        }
    }
    return INT_MIN; 
}
int RPN::calculate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while(iss >> token)
    {
        if(token.length() == 1 && isNumber(token[0]))
        {
            int n = token[0] - '0' ;
            stack.push(n);
        }
        else if(token.length() == 1 && isOperator(token[0]))
        {
            if(stack.size() < 2)
            {
             throw std::runtime_error("Error");
            }
            int result;
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            result = operation(a, b, token[0]);
            stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }
    if(stack.size() != 1)
    {
        throw std::runtime_error("Error");
    }
    return stack.top();
}