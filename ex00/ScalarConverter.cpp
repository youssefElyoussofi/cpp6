#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& scalar)
{
    (void)scalar;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalar)
{
    (void)scalar;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    
}

static bool is_char_literal(const std::string& input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
        return true;
    return false;
}

static void print_char(double val)
{
    if (std::isnan(val) || std::isinf(val) || val > static_cast<double>(127) || val < static_cast<double>(0))
        std::cout << "char : impossible\n";
    else if (val > static_cast<double>(126) || val < static_cast<double>(32))
        std::cout << "char : Non displayable\n";
    else
        std::cout << "char : '" <<  static_cast<char>(val) << "'\n";
}

static void print_int(double val)
{
    if (std::isnan(val) || std::isinf(val) || static_cast<double>(2147483647) < val || static_cast<double>(-2147483648) > val)
        std::cout << "int : impossible\n";
    else
        std::cout << "int : " << static_cast<int>(val) << '\n';
}

static void print_float(double val)
{
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f\n";
}

static void print_double(double val)
{
    std::cout << "double : " << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if (is_char_literal(input))
    {
        std::cout << "char : '" << static_cast<char>(input[0]) << "'\n";
        std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f\n";
        std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
    }
    else
    {
        char* end = NULL;
        double val = strtod(input.c_str(),&end);

        bool isFloat = false;
        bool isValid = false;

        if (*end == 'f' && *(end + 1) == '\0')
            isFloat = true;
        if (*end == '\0' || isFloat)
            isValid = true;

        if (isValid)
        {
            print_char(val);
            print_int(val);
            print_float(val);
            print_double(val);
        }
        else
        {
            std::cout << "char : impossible\n";
            std::cout << "int : impossible\n";
            std::cout << "float : impossible\n";
            std::cout << "double : impossible\n";
        }
    }
}