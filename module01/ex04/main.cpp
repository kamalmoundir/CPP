/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:44:48 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/11 14:26:27 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if(ac == 4)
    {
        std::string fileNameInput(av[1]);
        std::string s1(av[2]);
        std::string s2(av[3]);
        
        std::ifstream myReadfile(fileNameInput);
        if(!myReadfile.is_open())
           {
             std::cout<<"ERROR filename(path)"<<std::endl;
             return (1);
           }
            
        std::string outPutFile = fileNameInput + ".replace";
        std::ofstream replaceFile(outPutFile);
        if(!myReadfile.is_open())
           {
            std::cout<<"ERROR filename(path)"<<std::endl;
            return (1);
           }
        
        std::string line;
        while(getline(myReadfile, line))
        {
            size_t position = 0;;
            while((position = line.find(s1,position)) != std::string::npos)
            {
                line.erase(position,s1.length());
                line.insert(position,s2);
                position += s2.length();
            }
            replaceFile << line << '\n';
        }
       myReadfile.close();
       replaceFile.close();
    }
    else
        std::cout<< "Incorrect number of arguments!.\nplease enter <./name of program> <file path> <s1> <s2>"<<std::endl;

    return(0);
}