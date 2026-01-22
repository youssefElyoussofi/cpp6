#include "ScalarConverter.hpp"

int main()
{
    std::cout << "test 00 : TAB \n";    
    ScalarConverter::convert("	");
    std::cout << "\ntest 01 : 88 \n";    
    ScalarConverter::convert("88");
    std::cout << "\ntest 02 : 12.5 \n";    
    ScalarConverter::convert("12.5");
    std::cout << "\ntest 03 : 99888888888888888888 \n";    
    ScalarConverter::convert("99888888888888888888");
    std::cout << "\ntest 04 : nan \n";    
    ScalarConverter::convert("nan");
    std::cout << "\ntest 05 : 5.0f \n";    
    ScalarConverter::convert("5.0f");
    std::cout << "\ntest 06 : 76fdg \n";    
    ScalarConverter::convert("76fdg");
    std::cout << "\ntest 07 : a \n";    
    ScalarConverter::convert("a");
    return 0;
}
