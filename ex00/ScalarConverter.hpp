#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <string>
#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& scalar);
        ScalarConverter& operator=(const ScalarConverter& scalar);
        ~ScalarConverter();
        static void convert(const std::string& input);
};

#endif