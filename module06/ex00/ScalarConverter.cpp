/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:08:22 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/17 16:14:49 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

static void printMessage()
{
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: impossible"<<std::endl;
        std::cout<<"double: impossible"<<std::endl;
}
bool ScalarConverter::isLargeNumber(const std::string& literal)
{
    std::string literalTrim = trim(literal);
    if(literalTrim.empty())
        return false;
    size_t start = 0;
    if(literalTrim[0] == '-' || literalTrim[0] == '+')
        start ++;
    if(start == literalTrim.length())
        return false;
    for(size_t i = start ;i < literalTrim.length(); i++)
    {
        if(!std::isdigit(literalTrim[i]))
            return false;
    }
    errno = 0;
    long value = strtol(literalTrim.c_str(), NULL, 10);
    return (errno == ERANGE || value < INT_MIN || value > INT_MAX);
}
void ScalarConverter::convert(const std::string& literal)
{
    std::string literalTrim = trim(literal);
    
    if(literalTrim.empty())
    {
        printMessage();
        return ;
    }
    LiteralType type = detectType(literalTrim);
    switch(type)
    {
        case    CHAR:
                    {   
                        char c;
                        if(literalTrim.length() == 1)
                            c = literalTrim[0];
                        else
                            c = literalTrim[1]; 
                        convertFromChar(c);break;
                    }
        case    INT:
                    { 
                        errno = 0;
                        int value = std::atoi(literalTrim.c_str());
                        convertFromInt(static_cast<int>(value)); break;
                    }
        case    FLOAT:
                    {   errno = 0;
                        float value = strtof(literalTrim.c_str(), NULL);
                         if(errno == ERANGE)
                         {
                            printMessage();break;
                         }
                        convertFromFloat(value);break;
                    }
        case    DOUBLE:
                    {
                        errno = 0;
                        double value = strtod(literalTrim.c_str(), NULL);
                         if(errno == ERANGE)
                         {
                            printMessage();break;
                         }
                        convertFromDouble(value);break;
                    }
        case    PSEUDO:
                    {
                        convertFromPseudo(literalTrim);break;
                    }
        case    INVALID:
                    {
                        std::cout<<"ERROR: Invalid Literal!"<<std::endl;break;
                    }
    }
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal)
{
    if(isPseudoLiteral(literal))
        return PSEUDO;
    if(isInteger(literal))
        return INT;
    if(isChar(literal))
        return CHAR;
    if(isFloat(literal))
        return FLOAT;
    if(isDouble(literal))
        return DOUBLE;
    if(isLargeNumber(literal))
        return DOUBLE;
    return INVALID;
}
std::string ScalarConverter::trim(const std::string& str) 
{
    if(str.empty())
        return "";
    size_t start = 0;
    while(start < str.length() && std::isspace(str[start]))
        start++;
    
    size_t end = str.length();
    while(end > start && std::isspace(str[end -1]))
        end --;
    return str.substr(start,end - start);
}

bool ScalarConverter::isInteger(const std::string& literal)
{
    std::string literalTrim = trim(literal);
    if(literalTrim.empty())
        return false;
    size_t start = 0;
    if(literalTrim[0] == '-' || literalTrim[0] == '+')
        start ++;
    if(start == literalTrim.length())
        return false;
    for(size_t i = start ;i < literalTrim.length(); i++)
    {
        if(!std::isdigit(literalTrim[i]))
            return false;
    }
    errno = 0;
    long value = strtol(literalTrim.c_str(), NULL, 10);
    if(errno == ERANGE || value < INT_MIN || value > INT_MAX)
        return false; 
    return true;
}

bool  ScalarConverter::isFloat(const std::string& literal)
{
    std::string literalTrim = trim(literal);
    if(literalTrim.length() < 3 || literalTrim[literalTrim.length() - 1] != 'f')
        return false;
    std::string withoutF = literalTrim.substr(0, literalTrim.length() -1);
    size_t start = 0;
    if(withoutF[0] == '-' || withoutF[0]== '+')
        start = 1;
    bool hasDot = false;
    for(size_t i = start; i < withoutF.length(); i++)
    {  
        if(withoutF[i] == '.')
        {
            if(hasDot)
                return false;
            hasDot = true;
        }
        else if(!std::isdigit(withoutF[i]))
            return false; 
    }
    return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    std::string literalTrim = trim(literal);
    if(literalTrim.length()< 3)
        return false;
    size_t start = 0;
    if(literalTrim[0] == '-' || literalTrim[0]== '+')
        start = 1;
    if(start >= literalTrim.length())
        return false;
    bool hasDot = false;
    bool hasDigit = false;
    for(size_t i = start; i < literalTrim.length(); i++)
    {  
        if(literalTrim[i] == '.')
        {
            if(hasDot)
                return false;
            hasDot = true;
        }
        else if(std::isdigit(literalTrim[i]))
            hasDigit =true;
        else
            return false; 
    }
    return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return( literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff"
        );
}

bool ScalarConverter::isChar(const std::string& literal)
{
    std::string literalTrim =trim(literal);
    if(literalTrim.length()== 3 && literalTrim[0] =='\'' && literalTrim[2] =='\'' )
        return true;
    if(literalTrim.length() == 1 && std::isprint(literalTrim[0]))
        return true;
    return false;
}

void ScalarConverter::convertFromChar(char c)
{
    std::cout<<"char: '"<< c << "'"<<std::endl;
    std::cout<<"int: "<<static_cast<int>(c)<<std::endl;
    std::cout<<"float: "<<static_cast<float>(c)<<".0f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(c)<<".0"<<std::endl;
}
void ScalarConverter::convertFromInt(int i)
{
    if(i < 0 || i > 127)
        std::cout<<"char: impossible"<<std::endl;
    else if(i < 32 || i == 127)
        std::cout<<"char: Non displayable"<<std::endl;
    else
        std::cout<<"char: '"<<static_cast<char>(i)<<"'"<<std::endl;
    
    std::cout<<"int: "<<i<<std::endl;
    std::cout<<"float: "<<static_cast<float>(i)<<".0f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(i)<<".0"<<std::endl;
}

void ScalarConverter::convertFromFloat(float f)
{

    if(std::isnan(f))
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
        return;
    }
    if(std::isinf(f))
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        if(f > 0)
        {
            std::cout <<"float: +inff"<<std::endl;
            std::cout <<"double: +inf"<<std::endl;
        }
        else
        {
            std::cout<<"float: -inff"<<std::endl;
            std::cout<<"double: -inf"<<std::endl;
        }
        return;
    }
    //char conversion
    if(f < 0 || f > 127 || f != static_cast<int>(f))
        std::cout<<"char: impossible"<<std::endl;
    else if(f < 32 || f == 127)
        std::cout<<"char: Non displayable"<<std::endl;
    else
        std::cout<<"char: '"<<static_cast<char>(f)<<"'"<<std::endl;
    
    if(f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
        std::cout<<"int: impossible"<<std::endl;
    else
        std::cout<<"int: "<<static_cast<int>(f)<<std::endl;

    //Float conversion
    std::cout<<"float: "<<f;
    if(f == static_cast<int>(f))
    {
        std::cout<<".0";
    }
    std::cout<<"f"<<std::endl;

    //Double conversion
    std::cout <<"double: "<<static_cast<double>(f);
    if(f == static_cast<int>(f))
        std::cout<<".0";
    std::cout<<std::endl;
}

void ScalarConverter::convertFromDouble(double d)
{

    if(std::isnan(d))
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
        return;
    }
    if(std::isinf(d))
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        if(d > 0)
        {
            std::cout <<"float: +inff"<<std::endl;
            std::cout <<"double: +inf"<<std::endl;
        }
        else
        {
            std::cout<<"float: -inff"<<std::endl;
            std::cout<<"double: -inf"<<std::endl;
        }
        return;
    }
    //char conversion
    if(d < 0 || d > 127 || d!= static_cast<int>(d))
        std::cout<<"char: impossible"<<std::endl;
    else if(d < 32 || d == 127)
        std::cout<<"char: Non displayable"<<std::endl;
    else
        std::cout<<"char: '"<<static_cast<char>(d)<<"'"<<std::endl;
    
    if(d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
        std::cout<<"int: impossible"<<std::endl;
    else
        std::cout<<"int: "<<static_cast<int>(d)<<std::endl;

    //Float conversion
    float f =static_cast<float>(d);
    std::cout<<"float: "<<f;
    if(f == static_cast<int>(f))
    {
        std::cout<<".0";
    }
    std::cout<<"f"<<std::endl;

    //Double conversion
    std::cout <<"double: "<<d;
  if(d == static_cast<int>(d))
        std::cout<<".0";
    std::cout<<std::endl;
}

void ScalarConverter::convertFromPseudo(const std::string& literal)
{
   std::cout<<"char: impossible"<<std::endl;
   std::cout<<"int: impossible"<<std::endl;
   
    if(literal == "nanf" || literal == "nan")
   {
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
   }
   else if(literal == "+inf" || literal == "+inff")
   {
      std::cout <<"float: +inff"<<std::endl;
      std::cout <<"double: +inf"<<std::endl;
   }
   else if(literal == "-inf" || literal == "-inff")
   {
      std::cout <<"float: -inff"<<std::endl;
      std::cout <<"double: -inf"<<std::endl;
   }
}
