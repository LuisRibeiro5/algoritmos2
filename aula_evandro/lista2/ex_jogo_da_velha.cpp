#include <iostream>

void escolhe_jogador(char& player);
void mostra_velha(const char velha[][3], int = 3);
void joga_jogador(char velha[][3], char& player);
bool verifica_vencedor(const char velha[][3], char player, int = 3);
void troca_player(char&);

int main(){
    char velha[][3] = {{'*','*','*',},
                       {'*','*','*',},
                       {'*','*','*',}};
    char player;
    escolhe_jogador(player);
    int i = 0;
    do
    {
        mostra_velha(velha);
        joga_jogador(velha,player);
        if(verifica_vencedor(velha,player)){
            std::cout << "O jogador " << player << "venceu!\n";
            break;
        }
        if(i == 8){
            std::cout << "\nEmpate!\n";
            break;
        }
        troca_player(player);
    } while (i++ < 9);
    
    mostra_velha(velha);

    return 0;

}

void mostra_velha(const char velha[][3], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            std::cout << velha[i][j];
            if (j != 2)
            {
                std::cout << "|";
            }
            
        }
        if (i != 2){

            std::cout << "\n-----\n";         
        }
    }
    std::cout << "\n\n";
};

void escolhe_jogador(char& player){
    do
    {
        std::cout << "Jogador 1 quer ser 'O' ou 'X'?\n";
        std::cin >> player;
        player = toupper(player);
        if(player != 'X' && player != 'O'){
            std::cout << "Voce deve escolher entre X e O!\n";
        }
    } while (player != 'X' && player != 'O');   
}

void joga_jogador(char velha[][3], char& player){
    int linha,coluna;
    std::cout << "Vez do " << player << "\n";
    do
    {
        std::cout << "escolha uma posicao noi jogo-da-velha, informando uma linha(1 à 3) e coluna(1 à 3): \nlinha: ";
        std::cin >> linha;
        std::cout << "coluna: ";
        std::cin >> coluna;
        linha--;coluna--;
        if (velha[linha][coluna] == '*')
        {
            velha[linha][coluna] = player;
        }else{
            std::cout << "posicao invalida! escolha outra.\n";
        }
        
    } while (velha[linha][coluna] != player);
}

bool verifica_vencedor(const char velha[][3], char player, int tamanho){
    bool ganhou = false;
    for (int i = 0; i < tamanho; i++){
        if(velha[i][0] == player && velha[i][1] == player && velha[i][2] == player){
            return ganhou = true;
        }
    }

    for (int i = 0; i < tamanho; i++){
        if(velha[0][i] == player && velha[1][i] == player && velha[2][i] == player){
            return ganhou = true;
        }
    }
    
    if(velha[0][0] == player && velha[1][1] == player && velha[2][2] == player || velha[0][2] == player && velha[1][1] == player && velha[2][0] == player) {
            return ganhou = true;
    }
    return ganhou;
}

void troca_player(char& player){
    if (player == 'X')
    {
        player = 'O';
    }else{
        player = 'X';
    }
}