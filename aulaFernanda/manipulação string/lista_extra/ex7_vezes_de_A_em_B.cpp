//Leia duas strings A e B, e determine quantas vezes a string A ocorre na string B.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string frase1, frase2;
    do
    {
        cout << "digite a preimeira frase" << endl;
        getline(cin,frase1);
    } while (frase1 == "");
    do
    {
        cout << "digite a segunda frase" << endl;
        getline(cin,frase2);
    } while (frase2 == "");
    
    // int cont=0, vezes=0, j = 0;
    // for (int i = 0; i < frase1.size(); i++)
    // {
    //     if(tolower(frase1.at(i)) == tolower(frase2.at(j))){
    //         ++cont;
    //         j++;
    //         if (cont == frase2.size()){
    //             vezes += 1;
    //             cont = 0;
    //             j = 0;
    //         }
    //     }else{
    //         cont = 0;
    //         j = 0;
    //     }

    // }


    /*
    FORMA QUE A PROFESSORA UTILIZOU:
    bool achou;
    if(frase1.size() <= frase.size()){
        for(int i = 0; i < frase1.size(); i++){
            if(frase1[i] == frase2[0]){
                achou = true;
                for(int k = i, int j = 0; j < frase2.size(); k++; j++){
                    if(frase1[k] != frase2[j]){
                        achou = false;
                        break;
                    }
                if(achou){
                    vezes++; achou = false;
                }
                }
            }
        }
    }
    */

    transform(frase1.begin(),frase1.end(),frase1.begin(),::tolower);
    transform(frase2.begin(),frase2.end(),frase2.begin(),::tolower);

    int tamFrase2 = frase2.size(), vezes = 0;
    string fraseTeste;

    for (int i = 0; i < frase1.size(); i++)
    {   
        fraseTeste = frase1.substr(i, tamFrase2);
        if(fraseTeste.size() < frase2.size()){
            break;
        }else if(fraseTeste == frase2){
            vezes++;
        }
    }
    
    
    cout << vezes;
    return 0;
}