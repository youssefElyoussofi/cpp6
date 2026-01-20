#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data *data = new Data(5);

    uintptr_t ptr = Serializer::serialize(data);
    Data *dataPtr = Serializer::deserialize(ptr);

    if (data == dataPtr)
        std::cout << "success casing\n";

    std::cout << dataPtr->getNum() << std::endl;

    // test to see that reinterpret_cast not safe
    // uintptr_t fakePtr = 0xDEADBEEF;
    // dataPtr = Serializer::deserialize(fakePtr);
    // std::cout << dataPtr->getNum() << std::endl;

    delete data;
    return 0;
}