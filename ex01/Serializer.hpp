#ifndef  Serializer_hpp
#define  Serializer_hpp

#include <string>
#include <stdint.h>

class Data;

class Serializer
{
    private:
        Serializer();

    public:
        Serializer(const Serializer& serial);
        Serializer& operator=(const Serializer& serial);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif