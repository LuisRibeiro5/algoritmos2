#include "estoque.hpp"
#include <iostream>

Estoque::Estoque()
    : codigo{0}, qtde{0}, custo_unit{0}, custo_tot{0} {}

Estoque::Estoque(int v_codigo, int v_qtde, double v_custo_unit){
    definir_codigo_item(v_codigo);
    definir_custo(v_custo_unit);
    definir_quantidade(v_qtde);

}

void Estoque::definir_codigo_item(int v_codigo){
    codigo = v_codigo < 0 ? 0 : v_codigo;
}

void Estoque::definir_custo(double v_custo){
    custo_unit = v_custo < 0 ? 0 : v_custo;
    definir_custo_total();
}

void Estoque::definir_quantidade(int v_qtde){
    qtde = v_qtde < 0 ? 0 : v_qtde;
    definir_custo_total();
}

void Estoque::definir_custo_total(){
    custo_tot = qtde * custo_unit;
}

int Estoque::obter_codigo_item(){
    return codigo;
}

int Estoque::obter_quantidade(){
    return qtde;
}

double Estoque::obter_custo(){
    return custo_unit;
}

double Estoque::obter_custo_total(){
    return custo_tot;
}