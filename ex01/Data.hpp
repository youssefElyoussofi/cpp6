#ifndef Data_hpp
#define Data_hpp

class Data
{
    private:
        int num;
    public:
        Data();
        Data(int num);
        Data(const Data& data);
        Data& operator=(const Data& data);
        ~Data();
        int getNum(void);
};

#endif