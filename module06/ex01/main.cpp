/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:19 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 13:55:06 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
Data *dataT = new Data();

dataT->name ="test";
dataT->value = 42;

std::cout<<"Data before serialization : name:"<<dataT->name<<" value:"<<dataT->value<<std::endl;

uintptr_t dataSerialized = Serializer::serialize(dataT);

std::cout<<"Data after serialization : "<< dataSerialized <<std::endl;

Data *dataDeserialized = Serializer::deserialize(dataSerialized);
std::cout<<"Data After deserialization name :"<< dataDeserialized->name <<" Value = "<<dataDeserialized->value<<std::endl;
std::cout << "Pointers match: " << (dataT == dataDeserialized ? "Yes" : "No") << std::endl;
    
delete dataT;
return 0;
}