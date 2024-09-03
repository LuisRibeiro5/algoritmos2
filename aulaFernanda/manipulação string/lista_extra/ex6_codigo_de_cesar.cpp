// O código de César é uma das mais simples e conhecidas técnicas de criptografia. É um tipo de substituição na qual cada letra do texto é substituída por outra, que se apresenta no alfabeto abaixo dela um número fixo de vezes. Ou seja, com uma troca de três posições ‘A’ seria substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente um programa que leia uma string e gere outra string codificada, fazendo uso desse Código de César (3 posições). Ex.:
#include <iostream>
#include <string>

using namespace std;

int main(){
    string frase;
    do
    {
        cout << "dogite uma frase" << endl;
        getline(cin,frase);
    } while (frase == "");

    for (int i = 0; i < frase.size(); i++)
    {   
        if(isalpha(frase.at(i))){
            frase[i] = frase[i] + 3;
                if(toupper(frase2[i]) > 90) // trata 3 ultimas letras
                    frase2[i]=frase2[i]-26;
                }
        }
        
    }
    
    cout << frase;

    return 0;
}