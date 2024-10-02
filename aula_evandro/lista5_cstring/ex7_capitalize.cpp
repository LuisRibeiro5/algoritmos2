#include <iostream>

void capitalize(char*);

int main(){
    char frase[21];
    std::cin.getline(frase,sizeof(frase));
        
    capitalize(frase);

    std::cout << frase << "\n";

    return 0;
}

void capitalize(char *arr){
    // std::cout << "inicio da func\n";
    // while (*arr != '\0')
    // {   
    //     if (*arr == ' ')
    //     {
    //         arr++;
    //         continue;
    //     }

    //     if (isalpha(*arr))
    //     {
    //         *arr = toupper(*arr);
    //         while(*arr != ' ' || *arr == '0'){
    //             arr++;
    //         }
    //     }else{
    //         arr++;
    //     }
        
    // }
    
    bool nova_palavra = true;
    while(*arr != '\0'){
        if (nova_palavra && isalpha(*arr)){
            *arr = toupper(*arr);
            nova_palavra = false;
        }

        if (*arr == ' '){
            nova_palavra = true;
        }

        arr++;
        
    }
};
