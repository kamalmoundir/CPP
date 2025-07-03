/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:21:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/26 21:39:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _dataBase(other._dataBase) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_dataBase = other._dataBase;
    }
    return *this;
}

bool BitcoinExchange::isValidValue(const float value) const
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    try
    {

        if (date.length() != 10 || date[4] != '-' || date[7] != '-')
            return false;

        int year = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8, 2).c_str());

        if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) // isALeap year
            daysInMonth[1] = 29;
        if (day > daysInMonth[month - 1])
        {
            return false;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    if (str.empty())
        return "";
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

void BitcoinExchange::loadData(const std::string &fileData)
{
    std::string line;
    int countLine = 0;
    bool headerLine = true;
    std::ifstream file(fileData.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: opening file.");
    }
    while (std::getline(file, line))
    {
        if (headerLine)
        {
            headerLine = false;
            continue;
        }
        size_t pos = line.find(",");
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << countLine << std::endl;
            continue;
        }
        // trim and extract date and rate
        std::string dateStr = trim(line.substr(0, pos));
        std::string rateStr = trim(line.substr(pos + 1));

        // convert rate string to float
        float rateF = atof(rateStr.c_str());
        this->_dataBase[dateStr] = rateF;
        countLine++;
    }
    file.close();
}

void BitcoinExchange::exchangeProcess(const std::string &fileInput)
{
    std::string line;
    std::ifstream file(fileInput.c_str());


    if (!file.is_open())
    {
        throw std::runtime_error("Error: opening file.");
    }
    if (!std::getline(file, line))
    {
        throw std::runtime_error("Error :Empty file!");
    }
    if (trim(line) != "date | value")
    {
        throw std::runtime_error("Error: invalid header!");
    }
    while (std::getline(file, line)){
        if (line.empty())
            continue;
        size_t PipePos = line.find("|");
        if (PipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = trim(line.substr(0, PipePos));
        std::string valueStr = trim(line.substr(PipePos + 1));
        
        if(!isValidDate(dateStr)){
            std::cerr <<"Error: bad input => "<< dateStr<<std::endl;
            continue;
        }

        float value = atof(valueStr.c_str());
        if(!isValidValue(value))
        {
            if(value < 0)
                std::cerr << "Error: not a positive number."<< std::endl;
            else
                std::cerr << "Error: too large a number."<<std::endl;
            continue;         
        }
        //search in dataBase for the date if not exist use the closest date
        std::map<std::string, float>::iterator it =this->_dataBase.upper_bound(dateStr);
        if(it == _dataBase.begin())
        {
            std::cerr <<"Error: date too early => "<<dateStr <<std::endl;
            continue;
        }
        --it;
  
            float rate = it->second;
            float result = value * rate;
            std::cout <<dateStr << " => " << value << " = " << result << std::endl;
     
    }
    file.close();
}