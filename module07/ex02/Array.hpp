/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:11:01 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/19 22:58:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<exception>

template <typename T>
class Array
{
    private : 
            T* _elements;
            unsigned int _size  ;
    public :
            Array();
            Array(unsigned int n);
            Array(const Array& other);
            Array& operator=(const Array& other);
            ~Array();
            T& operator[](unsigned int index);
            const T& operator[](unsigned int index)const;
            unsigned int size() const;
};


template <typename T>
Array<T>::Array():_elements(NULL),_size(0)
{}
template <typename T>
Array<T>::Array(unsigned int n):_elements(NULL),_size(n)
{
        if(n > 0)
                _elements=new T[n];
}

template <typename T>
Array<T>::Array(const Array& other):_elements(NULL), _size(other._size)
{
        if(_size > 0)
        {  
                this->_elements = new T[_size];
                for(unsigned int i = 0 ;i < _size; i++)
                {
                        _elements[i] = other._elements[i];
                }
        }
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
        if(this != &other)
        {
                delete[] this->_elements;
                this->_size = other._size;
                if(_size > 0)
                {
                        this->_elements = new T[_size];
                        for(unsigned int i = 0 ;i < _size; i++)
                        {
                                _elements[i] = other._elements[i];
                        }
                }
                else
                {
                        _elements = NULL;
                }
        }
        return *this;
}

template <typename T>
Array<T>::~Array()
{
        delete[] _elements;
}
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
        if(_size <= index)
        {
                throw std::out_of_range("Index out of bounds");
        }
        return(_elements[index]); 
}

template <typename T>
const T& Array<T>::operator[](unsigned int index)const
{
         if(_size <= index)
        {
                throw std::out_of_range("Index out of bounds");
        }
        return(_elements[index]); 
}
template <typename T>
 unsigned int Array<T>::size() const
 {
        return _size;
 }