#include "estoque.hpp"
#include <iostream>

int main(){
    Estoque e(12314,100,3.50);
    std::cout << e.obter_codigo_item() << "\n" << e.obter_custo() << "\n" << e.obter_quantidade() << "\n" << e.obter_custo_total() << "\n\n"<< std::endl;

    Estoque f;
    f.definir_custo(7.50);
    f.definir_codigo_item(-12);
    f.definir_quantidade(10);

    std::cout << f.obter_codigo_item() << "\n" << f.obter_custo() << "\n" << f.obter_quantidade() << "\n" << f.obter_custo_total() << std::endl;

    return 0;
}