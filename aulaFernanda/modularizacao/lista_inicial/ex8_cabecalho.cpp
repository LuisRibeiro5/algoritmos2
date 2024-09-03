/*Crie um procedimento que gere um cabeçalho para um relatório. Esse procedimento deve receber um nome como parâmetro. O cabeçalho tem a seguinte forma*/
#include <iostream>

void cabecalho(std::string);

int main(){
    cabecalho("Luis");
};

void cabecalho(std::string fulano){
    std::cout << "\n============================================\n";
    std::cout << "UNIVALI – POLITECNICA – Ciência da Computação\nDisciplina Algoritmo e Programação 2per\nNome:" << fulano;
    std::cout << "\n============================================\n";
};
