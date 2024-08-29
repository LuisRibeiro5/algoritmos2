#include <iostream>

void recebe_matriz(int [][3], int, int);
int escolhe_lin();
int escolhe_col();
int recebe_numero_valido(int [][3], int, int);
void verifica_posicao_livre(int [][3], int);
void mostra_matriz(int [][3], int, int);
bool verifica_num_na_matriz(const int [][3], int, int, int);
void e_matriz_de_lo_chu(const int [][3], int, int);

int main(){
    int matriz[3][3] = {0};
    recebe_matriz(matriz,3,3);
    mostra_matriz(matriz,3,3);
    e_matriz_de_lo_chu(matriz,3,3);
}

//verificoes de entrada
void mostra_matriz(int matriz[][3], int linha, int coluna){
    std::cout << "\n\n";
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            std::cout << matriz[i][j];
            if (j != 2)
            {
                std::cout << " | ";
            }
            
        }
        if (i != 2)
        {
            std::cout << "\n--------\n";
        }
    }
    std::cout << "\n\n";
}

void recebe_matriz(int matriz[][3], int linha, int coluna){
    for (int i = 0; i < 9; i++)
    {
        int num = recebe_numero_valido(matriz, linha, coluna);
        verifica_posicao_livre(matriz,num);
    }
} 

void verifica_posicao_livre(int matriz[3][3], int num){
    bool lin_e_col_valido = true;
    do
        {   
            std::cout << "Digite a linha e coluna da posicao que quer inseri-lo: \n";
            int lin = escolhe_lin();
            int col = escolhe_col();
            if (matriz[lin][col] != 0){
                std::cout << "Essa posicao já está ocupada!\n";
                lin_e_col_valido = false;
            }else{
                matriz[lin][col] = num;
                lin_e_col_valido =  true;
            }
        } while (!lin_e_col_valido);
    }

int recebe_numero_valido(int matriz[][3], int linha, int coluna){
    int num;
    bool taNaMatriz;
    do{
        std::cout << "escolha um numero de 1 à 9, nao digite em posicoes já inseridas uma vez:\n";
        mostra_matriz(matriz, linha, coluna);
        std::cout << "num: ";
        std::cin >> num;
        taNaMatriz = verifica_num_na_matriz(matriz,linha,coluna,num);
        if (num < 1 || num > 9 || taNaMatriz){
            std::cout << "numero invalida, insira novamente!\n";
        }
    }while(num < 1 || num > 9 || taNaMatriz);
     
    return num;
}

bool verifica_num_na_matriz(const int matriz[][3],int linha, int coluna, int num){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(num == matriz[i][j]){
                return true;
            }
        }
    }
    return false;
}

int escolhe_lin(){
    int lin;
    do
    {
        std::cout << "linha: "; 
        std::cin >> lin;
        if (lin < 1 || lin > 3){
            std::cout << "Deve estar nmmo intervalo de 1 e 3\n";
        }
        
    } while (lin < 1 || lin > 3);
    return --lin;
}
int escolhe_col(){
    int col;
    do
    {
        std::cout << "coluna: "; 
        std::cin >> col;
        if (col < 1 || col > 3){
            std::cout << "Deve estar nmmo intervalo de 1 e 3\n";
        }
        
    } while (col < 1 || col > 3);
    return --col;
}

//verificacoes de matriz de lo shu
void e_matriz_de_lo_chu(const int matriz[][3], int linha, int coluna){
    //verifica se linhas somadas é 15
    bool linhaSomou15 = true;
    for (int i = 0; i < linha; i++){

        if (matriz[i][0] + matriz[i][1] + matriz[i][2] != 15){
            linhaSomou15 = false;
        }
    }

    //verifica se colunas somadas é 15
    bool colunaSomou15 = true;
    for (int i = 0; i < linha; i++){

        if (matriz[0][i] + matriz[1][i] + matriz[2][i] != 15){
            colunaSomou15 = false;
        }
    }
    
    //verifica diagonais
    bool diagonaisSomou15 = true;
    if (matriz[0][0] + matriz[1][1] + matriz[2][2] != 15 || matriz[0][2] + matriz[1][1] + matriz[2][0] != 15){
        diagonaisSomou15 = false;
    }
    
    if (linhaSomou15 && colunaSomou15 && diagonaisSomou15)
    {
        std::cout << "Parabens voce conseguir insserir uma matriz de lo shu!\n";
    }else{
        std::cout << "Essa matriz nao é de lo shu.\n";
    }
    
}