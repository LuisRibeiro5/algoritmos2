/* Um número é dito ser capicua quando lido da esquerda para a direita é o mesmo que quando lido da direita para 
a esquerda. O ano 2002, por exemplo, é capicua. Então, elabore uma função para verificar se um número possui 
essa característica. Considere apenas números com 4 dígitos. Caso o número seja capicua, a função deve retornar 
1 e 0 em caso contrário. Crie também um programa para testar tal função. */
#include <iostream>

std::string recebeNumString();
void validaNum(std::string&);
bool ehCapicua(std::string);

int main(){
    std::string num = recebeNumString();
    validaNum(num);
    std::cout << "numero é capicua?\n" << ehCapicua(num) << std::endl;
    
}
std::string recebeNumString(){
    std::string num;
    do
    {
        std::cout << "digite o um numero de 4 caracteres: \n";
        std::cin >> num;
    } while (num == " " || num.size() != 4);
    return num;
}

void validaNum(std::string &num){
    bool numValido;
    do{
        numValido = true;
        for (int i = 0; i < num.length() - 1;i++)
        {
            if (!isdigit(num[i]))
            {
                numValido = false; 
                break;
            }      
        }
        if (!numValido)
        {
            num = recebeNumString();
        }
    }while (!numValido);
}

bool ehCapicua(std::string num){
    for (int i = 0, j = num.size()-1; i < num.size()/2 - 1; i++, j--)
    {
        if (num[i] != num[j])
        {
            return false;
        }
        
    }
    return true;
};

/*
FUNCAO PARA VER SE E CAPICUA DA PROFESSORA:

bool ehCapicua(int num){
    int v1,v2,v3,v4;
    int numOriginal = num; //NUMERO INVERSO RECEBE O ORIGINAL PARA PRESERVAR O ORIGINAL

    v1 = num / 1000;
    num = num % 1000;

    v2 = num / 100;
    num = num % 100;

    v3 = num / 10;
    
    v4 = num % 10;

    int numInverso = v4 * 1000 + v3 * 100 + v2 * 10 + v1; //NUMERO INVERSO RECEBE SEU REAL VALOR

    if(numInverso == numOriginal){// COMPARA INVERSO COM O ORIGINAL
        return true;
    } else{
        return false;
    }
}
*/
