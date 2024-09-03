//Faça um programa que receba do usuário uma string A e monte uma nova string B cujo conteúdo é a string A sem suas vogais. Mostre B ao final.
#include <iostream>
#include <string>

using namespace std;
int main(){
    string stringA;
    char vogais[] = {'a','e','i','o','u'};
    do
    {
        cout << "digite a atring A" << endl;
        getline(cin,stringA);
    } while (stringA == "");

    string stringB;
    char letra;
    //SEM ARRAY
    for (int i = 0; i < stringA.size(); i++)
    {
        letra = tolower(stringA.at(i));
        if(!(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')){
            stringB += stringA.at(i);
        }
    }
    
    //COM ARRAY
    //stringB = stringA;
    // for(int i = 0; i < stringB.size(); i++){
    //     for(int j = 0; j < 5; j++){
    //         if(tolower(stringB.at(i)) == vogais[j]){
    //                stringB.erase(i,1); i--;
    //            }


    //COM ARRAY
    //bool eVogal = true;
    // for(int i = 0; i < stringA.size(); i++){
    //     for(int j = 0; j < 5; j++){
    //         if(tolower(stringA.at(i)) == vogais[j]){
    //             eVogal = true;
    //             break;
    //         }else{
    //             eVogal = false;
    //         }
    //     }
    //     if(!eVogal){
    //         stringB += stringA.at(i);
    //     }
    // }

    cout << "\n" << stringA << endl;
    cout << "\n" << stringB << endl;
    
    return 0;

    
}