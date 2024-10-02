#include "moeda.h"
#include <iostream>
#include <cstring>

int main(){
    Moeda m;

    int cara = 0, coroa = 0;

    for (int i = 0; i < 20; i++)
    {
        std::cout << "\n" << (m.get_lado());
        if (strcmp(m.get_lado(), "cara")){
            cara++;

        }else{
            coroa++;
        }
        
        m.jogar();
    }

    std::cout << "\n" << cara;
    std::cout << "\n" << coroa;
    

    return 0;
}