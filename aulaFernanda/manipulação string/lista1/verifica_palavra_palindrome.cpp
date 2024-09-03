/* Uma palavra palíndrome é uma cadeia de caracteres cuja leitura tem o mesmo sentido se feita da direita para a esquerda ou vice-versa. Por exemplo, OSSO, OVO, RADAR, ... Ler n cadeias de caracteres e determinar quais delas são palíndromes.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    //Leitura da frase com as cadeias de caracters
    string frase;
    do{
        cout << "Digite uma cadeia de caracteres: \n";
        getline(cin,frase);
    } while (frase == "");


    //Pega palavras da frase e colaca em um vetor palavras
    vector<string> palavras;
    string palavra = "";
    for(int i = 0; i < frase.size(); i++){
        
        if(frase.at(i) == ' ' || frase.at(i) == ',' || frase.at(i) == '.' || frase.at(i) == '\n'){
            palavras.push_back(palavra);
            palavra = "";}
        else
            palavra += frase.at(i);
    }
        //Realiza essa operacao uma ultima vez para adicionar a ultima palavra no vetor
        palavras.push_back(palavra);
        palavra = "";

    
    vector<string> palavras_ao_contrario;
    for(int i = frase.size() - 1; i >= 0; i--){
        
        if(frase.at(i) == ' ' || frase.at(i) == ',' || frase.at(i) == '.'){
            palavras_ao_contrario.insert(palavras_ao_contrario.begin(),palavra);
            palavra = "";}
        else
            palavra += frase.at(i);
    }
        //Realiza essa operacao uma ultima vez para adicionar a ultima palavra no vetor
        palavras_ao_contrario.insert(palavras_ao_contrario.begin(), palavra);
        palavra = "";

        for(int i = 0; i < palavras_ao_contrario.size(); i++){
            if(palavras_ao_contrario[i] == palavras[i]){
                cout << palavras_ao_contrario[i] << "---" << palavras[i] << "::: PALÍNDROME" << endl;
            } else {
                cout << palavras_ao_contrario[i] << "---" << palavras[i] << "::: NAO É PALÍNDROME" << endl;
            }
            cout << '.' << endl;
        }

    //Logica que pega palavra e traforma ao contrario
    // string frase_ao_contrario;
    // for(int i = frase.size() - 1; i >= 0; --i){
    //     frase_ao_contrario = frase_ao_contrario + frase.at(i);
    // }

    // cout << frase << "\n" << frase_ao_contrario << "\n";

    return 0;
}
