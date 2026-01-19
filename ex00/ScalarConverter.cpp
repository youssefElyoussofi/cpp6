#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

static bool is_double(const std::string& input)
{
    size_t pos = input.find('.');
    if (pos == std::string::npos || pos == 0 || pos == input.length())
        return false;
    std::string first_half = input.substr(0,pos);
    for (size_t i = 0; first_half[i]; i++)
    {
        if (!std::isdigit(first_half[i]))
            return false;
    }
    std::string second_half = input.substr(pos + 1);
    if (second_half.empty())
        return false;
    for (size_t i = 0; second_half[i]; i++)
    {
        if (!std::isdigit(second_half[i]))
            return false;
    }
    return true;
}

static bool is_float(const std::string& input)
{
    size_t len = input.length() - 1;

    if (input[len] != 'f')
        return false;
    if (!is_double(input.substr(len)))
        return false;
    return true;
}

static bool is_char(const std::string& input)
{
    if (input.length() == 1 && std::isdigit(input[0]))
        return true;
    return false;
}

static bool is_int(const std::string& input)
{
    for (size_t i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string& input)
{
    if (is_char(input))
    {
        std::cout << "char : '" << static_cast<char>(input[0]) << "'\n";
        std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << 'f' << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
    }
    else if (is_int(input) || is_double(input) || is_float(input))
    {
        double tmp_d = static_cast<double>(strtod(input.c_str(),NULL));
        int tmp_i = static_cast<int>(tmp_d);
        if (tmp_i >= 0 && tmp_i <= 127)
        {
            if (tmp_i >= 32 && tmp_i <= 126)
                std::cout << "char : '" << static_cast<char>(tmp_i) << "'\n";
            else
                std::cout << "char : Non displayable\n";
        }
        else
            std::cout << "char : impossible\n";
        std::cout << "int : " << tmp_i << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(tmp_d) << 'f' << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(tmp_d) << std::endl;
    }
    else
        std::cout << "not work\n";
}