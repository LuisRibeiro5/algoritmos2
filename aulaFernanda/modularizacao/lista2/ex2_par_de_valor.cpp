#include <iostream>

void le_par_de_valor(int [], int);
double calcula_combinacao_nr(int [], int);
int fatorial(int);



int main(){
    int qtde_pares, par_de_valor[2]={0};
    double combinacao;
    std::cout << "Digite quantas para de valor jdeseja ler: ";
    std::cin >> qtde_pares;

    for(int i = 0; i < qtde_pares; i++){
        le_par_de_valor(par_de_valor);
        combinacao = calcula_combinacao_nr(par_de_valor);
        std::cout << "A combinacao de " << par_de_valor[0] << " e " << par_de_valor[1] << " é " << combinacao;
    }

    return 0;
}

void le_par_de_valor(int par_de_valor[], int = 2){
    int n,r;
    while (r > n || r < 0 || n < 0){
        std::cout << "Digite o valor de n: ";
        std::cin >> n;

        std::cout << "Digite o valor de r: ";
        std::cin >> r;
        if(r > n || r < 0 || n < 0){
            std::cout << "Valores inválidos. Certifique-se de que n >= r e ambos sejam não negativos.\n";
        }
    }
    
    

    par_de_valor[0] = n;
    par_de_valor[1] = r;
};

double calcula_combinacao_nr(int par_de_valor[], int = 2){
    double combinacao;
    combinacao = fatorial(par_de_valor[0]) / (fatorial(par_de_valor[1]) * fatorial(par_de_valor[0] - par_de_valor[1]));

    return combinacao;
};

int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * fatorial(n - 1);
}

