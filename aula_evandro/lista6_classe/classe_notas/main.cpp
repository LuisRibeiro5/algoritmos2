#include "notas.h"
#include <iostream>

int main(){
    Notas pedro;

    double nota;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "digite a nota " << i+1 << ": ";
        std::cin >> nota;
        pedro.set_nota(i,nota);
    }
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n" << pedro.obter_nota(i);
    }
    
    std::cout << "\n A media eh " << pedro.media_notas() << "\n";

    return 0;
}