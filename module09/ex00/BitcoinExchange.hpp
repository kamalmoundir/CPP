/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:21:09 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/26 20:56:11 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <stdexcept> 
#include <cctype> 

class BitcoinExchange
{
    private:
            std::map<std::string, float> _dataBase;
            std::string trim(const std::string& str) const;
            bool isValidValue(const float value) const;
            bool isValidDate(const std::string& date) const;
    public:
            BitcoinExchange();
            BitcoinExchange(const BitcoinExchange& other);
            BitcoinExchange& operator=(const BitcoinExchange& other);
            ~BitcoinExchange();
            void loadData(const std::string& fileData);
           void exchangeProcess(const std::string& fileInput);
};


#endif