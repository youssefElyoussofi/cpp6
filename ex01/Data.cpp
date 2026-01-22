#include "Data.hpp"

Data::Data():num(0)
{

}

Data::Data(int num):num(num)
{
}

Data::Data(const Data& data)
{
    if (this != &data)
        *this = data;
}

Data& Data::operator=(const Data& data)
{
    if (this != &data)
        this->num = data.num;
    return *this;
}

Data::~Data()
{

}

int Data::getNum(void)
{
    return num;
}