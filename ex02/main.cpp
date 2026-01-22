#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <bits/stdc++.h>

Base* generate(void)
{
    int res = rand();

    if (res % 3 == 0)
        return new A;
    if (res % 3 == 1)
        return new B; 
    return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "the type is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "the type is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std:: cout << "the type is C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "the type is A" << std::endl;
    }
    catch(...){}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "the type is B" << std::endl;
    }
    catch(...){}    
    try
    {
        dynamic_cast<C&>(p);
        std:: cout << "the type is C" << std::endl;
    }
    catch(...){}    
}


int main()
{
    std::srand(time(0));

    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;    
    return 0;
}