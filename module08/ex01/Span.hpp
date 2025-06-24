/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:17:24 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/24 12:25:47 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>

class Span
{
    private:
            unsigned int _N;
            std::vector<int> _number;
    public:
            Span(const unsigned int N);
            Span(const Span& other);
            Span& operator=(const Span& other);
            ~Span();
            void addNumber(int number);
            unsigned int shortestSpan()const;
            unsigned int longestSpan()const;
            template<typename Iterator>
            void addNumbers(Iterator begin, Iterator end);
            
            
            class SpanFullException: public std::exception 
            {
                public : 
                        virtual const char* what() const throw();
            };
            
            class NoSpanException: public std::exception 
            {
                public :
                        virtual const char* what() const throw();
            };
             
                   
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
        for(Iterator It = begin ; It != end ;++It )
        {
                if(_number.size() >= _N)
                 throw SpanFullException();
                _number.push_back(*It);
        }
}           