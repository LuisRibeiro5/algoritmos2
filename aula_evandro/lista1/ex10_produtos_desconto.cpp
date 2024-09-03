#include <iostream>

void solicitarDadosProduto(double&, int&);
double calcularValorTotal(double, int);
double aplicarDesconto(double);

int main(){
    double preco, limiteDesconto = 100, percentual = 10;
    int qtde;

    std::cout << "Digite os dados do produto \n";
    solicitarDadosProduto(preco,qtde);

    double valorTotal = calcularValorTotal(preco,qtde);

    double valorFinal = aplicarDesconto(valorTotal, limiteDesconto, percentual);

    std::cout << "Valor final das compras foi de : " << valorFinal << "\n";

    return 0;
}

void solicitarDadosProduto(double& preco, int& qtde){
    do
    {
        std::cout << "digite o preco: \n";
        std::cin >> preco;
        if(preco <= 0){
            std::cout << "Valor invalido! \n";
        }
    } while (preco <= 0);

    do
    {
        std::cout << "digite a qtde: \n";
        std::cin >> qtde;
        if(qtde <= 0){
            std::cout << "Valor invalido! \n";
        }
    } while (qtde <= 0);
};

double calcularValorTotal(double preco, int qtde){
    double valorTotal = preco * qtde;
    return valorTotal;
};

double aplicarDesconto(double valorTotal, double limite, double desconto){
    if(valorTotal > limite){
        return valorTotal - (valorTotal * (desconto / 100));
    }else{
        return valorTotal;
    }
};