#include "data.h"
#include <iostream>

int main(){
    Data data1(01,02,2000);
    Data data2;

    std::cout << data1.data_extenso() << std::endl;
    std::cout << data1.data_padrao() << std::endl;

    return 0;
}