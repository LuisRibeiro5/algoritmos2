// Faça um programa que leia duas strings e verifique se a segunda string está contida no final da primeira, retornando o resultado da verificação.
#include <iostream>
#include <string>

using namespace std;

int main(){
    string frase1, frase2;
    do
    {
        cout << "Digite a primeira frase" << endl;
        getline(cin,frase1);
    } while (frase1 == "");

    do
    {
        cout << "Digite a segunda frase" << endl;
        getline(cin,frase2);
    } while (frase2 == "");

    int pos = frase1.size() - frase2.size();

    if (pos < 0){
        cout << "frase2 nao esta no final da frase1 " << endl;
    }else if(frase1.substr(pos) == frase2){
        cout << "frase 2 esta no final da frase 1 \n" << frase1 << "\n" << "\t" << frase2 << endl;  
    } else {
        cout << "frase2 nao esta no final da frase1 " << endl;

    }
    

    /*
    RESOLUCAO DA PROF SEM SUBSTR:
    bool achou = false;
    if(frase1.size() < frase2.size()){
        achou= false;
    }else { 
        for(int i = frase1.size() - 1, j = frase2.size() - 1; j>=0; i--, j--){
            if(frase1[i] != frase2[j]){
                achou = false; break;
            }
        }
    }
    if(achou){
        cout << "ta no final";        
    }else{
        cout << "nao ta no final";    
    }
    */

    return 0;
    
}