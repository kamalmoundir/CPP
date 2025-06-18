#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <cctype>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        enum LiteralType
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID,
            PSEUDO
        };

        static LiteralType detectType(const std::string& literal);
        static bool isInteger(const std::string& literal);
        static bool isChar(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);
        static bool isLargeNumber(const std::string& literal);
        static std::string trim(const std::string& str) ;

        static void convertFromChar(char c);
        static void convertFromInt(int i);
        static void convertFromFloat(float f);
        static void convertFromDouble(double d);
        static void convertFromPseudo(const std::string& literal);


    public:
        static void convert(const std::string& literal);
};


#endif