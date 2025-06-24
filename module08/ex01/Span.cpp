/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:56:49 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/24 12:24:08 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span(const unsigned int N):_N(N)
{}

Span::Span(const Span& other):_N(other._N),_number(other._number)
{}
Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        this->_N = other._N;
        this->_number = other._number;
    }
    return *this;
}
Span::~Span()
{}
void Span::addNumber(int number)
{
    if(_number.size() >= _N)
    {
        throw SpanFullException();
    }
    _number.push_back(number);
}
unsigned int Span::shortestSpan()const
{
    if(_number.size() < 2)
        throw NoSpanException();
    unsigned int spanMin = UINT_MAX;
    std::vector<int> sorted = _number;
    std::sort(sorted.begin(), sorted.end());
    for(size_t i = 1; i < sorted.size(); i++)
    {
        unsigned int span =  sorted[i] - sorted[i - 1];
        if(spanMin > span)
        {
            spanMin = span;   
        }
    }
    return spanMin;
}

unsigned int Span::longestSpan()const
{
    if(_number.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted = _number;
    std::sort(sorted.begin(), sorted.end());

    return static_cast<unsigned int>(sorted.back() - sorted.front());
    
}

const char *Span::SpanFullException::what() const throw()
{
    return "the container is Full";
}

const char* Span::NoSpanException::what() const throw()
{
    return  "Not enough numbers to calculate span";
}
