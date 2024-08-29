#include <iostream>

void recebe_dados_macacos(double [][5], int = 3);
void media_comida_todos(const double matriz[][5]);
void maior_e_menos_qtd_comida_gera(const double[][5]);

int main(){
    double comida_diaria_macacos[3][5];

    recebe_dados_macacos(comida_diaria_macacos);
    media_comida_todos(comida_diaria_macacos);
    maior_e_menos_qtd_comida_gera(comida_diaria_macacos);

    return 0;
}

void recebe_dados_macacos(double comida_diaria_macacos[][5], int linha){
    for (int i = 0; i < linha; i++)
    {
        std::cout << "Insira os daods do macaco " << i + 1;
        for (int j = 0; j < 5; j++)
        {
            do{
                std::cout << "\ninsira a comida do dia :"<< j + 1 <<  "\n";
                std::cin >> comida_diaria_macacos[i][j];
            }while(comida_diaria_macacos[i][j] < 0);
        }
    }
}

void media_comida_todos(const double matriz[][5]){
    double total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            total += matriz[i][j];
        }
        
    }
    double media = total / (3*5);
    std::cout << "A media de comida dos macacos é de: " << media;
}

void maior_e_menos_qtd_comida_gera(const double matriz[][5]){
    int linhaMin = 0, colunaMin = 0;
    int linhaMax = 0, colunaMax = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] < matriz[linhaMin][colunaMin])
            {
                linhaMin = i;
                colunaMin = j;
            }   
            if (matriz[i][j] > matriz[linhaMax][colunaMax])
            {
                linhaMax = i;
                colunaMax = j;
            }   

        }  
    }
    
    std::cout << "A maior qtd de comida consumida foi pelo macaco " << linhaMax +1 << " no dia " << colunaMax + 1<< ", foram exatamente " << matriz[linhaMax][colunaMax] << " kilos consumidos no dia";

    std::cout << "A menor qtd de comida consumida foi pelo macaco " << linhaMin+1 << " no dia " << colunaMin+1 << ", foram exatamente " << matriz[linhaMin][colunaMin] << " kilos consumidos no dia";
}