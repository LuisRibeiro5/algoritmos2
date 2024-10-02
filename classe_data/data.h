#pragma once
#include <iostream>

class Data {
    private:
        int dia,mes,ano;

    public:
        Data();
        Data(int,int,int);
        std::string data_padrao();
        std::string data_extenso();
};