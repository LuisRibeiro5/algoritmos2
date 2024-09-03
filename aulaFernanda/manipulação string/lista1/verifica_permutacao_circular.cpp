/*Dadas duas palavras verificar se uma é permutação circular de outra. Para se obter uma permutação circular dessa palavra transfere-se o primeiro caracter do início para o fim da mesma.
Para se obter todas as outras permutações circulares, repete-se esse mesmo processo para cada permutação circular obtida até que o último caracter da palavra inicial torne-se o primeiro. Assim,
por exemplo a palavra AROMA tem as seguintes permutaçõescirculares: ROMAA, OMAAR, MAARO, AAROM, AROMA. */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string palavra1, palavra2;

    do {
        cout << "Digite a primeira palavra: " << endl;
        getline(cin, palavra1);
    } while (palavra1 == " ");

    do {
        cout << "Digite a segunda palavra: " << endl;
        getline(cin, palavra2);
    } while (palavra2 == " ");

    bool ePermutacao = true;

    if (palavra1.size() != palavra2.size()) {
        ePermutacao = false;
    } else if (palavra1 == palavra2) {
        cout << "É permutacao circular." << endl;
    } else {
        for (int i = 0; i < palavra1.size(); i++) {
            // Mover o primeiro caractere para o final
            palavra1 = palavra1.substr(1) + palavra1.at(0);
            if (palavra2 == palavra1) {
                ePermutacao = true;
                break;
            } else {
                ePermutacao = false;
            }
        }
    }

    if (ePermutacao) {
        cout << "É permutacao." << endl;
    } else {
        cout << "Nao é permutacao." << endl;
    }

    return 0;
}



//DA PROFESSORA
// #include <iostream>
// #include <cstring>
// using namespace std;
// int main() // exercicio 6
// {
//     char aux;
//     string palav1, palav2;
//     bool achou = false;
//     unsigned int tam1, contRotacao = 0;
//     cout << "entre com a palavra: "; // fazer validacao das palavras
//     getline(cin, palav1);
//     cout << "entre com a outra palavra: ";
//     getline(cin, palav2);
//     tam1 = palav1.size(); // pega tam da palavra (no. de rotacoes)
//     if (tam1 == palav2.size())
//         do // poderia ser for tb
//         { 
//             if (palav1 == palav2)
//                 achou = true;
//             else
//             {
//                 aux = palav2.at(0);
//                 for (unsigned int j = 0; j < tam1 - 1; j++) // sem {}
//                     palav2[j] = palav2[j + 1];              // copia proximo p/frente
//                 palav2[tam1 - 1] = aux;                     // poe antiga inicial em ultimo
//             }
//             contRotacao++;
//         } while (not achou and contRotacao < tam1);
//     if (achou)
//         cout << "Estas palavras sao permutacoes circulares" << endl
//              << endl;
//     else
//         cout << "Estas palavras NAO sao permutacoes circulares" << endl
//              << endl;
//     return 0;
// }