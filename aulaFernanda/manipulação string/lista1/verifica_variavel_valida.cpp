/*5. Dada uma cadeia de caracteres, verifique se é ou não um identificador (nome de variável) válido. 
Um identificador válido é uma cadeia de caracteres cujo primeiro caracter deve ser uma letra e os demais devem ser dígitos, letras ou o underscore ( _ ). Exemplos: casa_azul, conjunto1, umValor. */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    int n;
    do
    {
        cout << "Quantas palavrar deseja escrever? " << endl;
        cin >> n;
    } while (n <= 0);
    cin.ignore();

    for (int i = 0; i < n; i++)
    {   
        string palavra;
        do
        {
            cout << "Digite a palavra" << endl;
            getline(cin,palavra);
        } while (palavra == "");

        bool variavelValida = true;
        
        if (!isalpha(palavra.at(0)))
        {
            variavelValida = false;
        }else{
            for (int j = 0; j < palavra.size() - 1; j++)
            {   
                //Essa Validacao pode ser feita fora do laço
                // if (!isalpha(palavra.at(0))){
                //     variavelValida = false; break;
                // }
                if (!isalnum(palavra.at(i)) && palavra.at(i) != '_'){
                    variavelValida = false; break;
                }
            }
        }

        if(variavelValida){
            cout << palavra << " é uma variavel valida.";
        }else{
            cout << palavra << " não é uma variavel valida.";
        }
        cout << "\n";
        
    }
    

    return 0;
}