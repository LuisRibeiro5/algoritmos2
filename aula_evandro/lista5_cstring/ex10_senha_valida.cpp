#include <iostream>
#include <cstring>

bool senha_eh_valida(const char *);
bool tem_seis_digitos(const char *senha);
bool tem_letra_maiusc(const char *senha);
bool tem_letra_minusc(const char *senha);
bool tem_um_digito(const char *senha);

int main(){
    char senha[20] = {'0'};
    std::cout << "Digite a senha: ";
    std::cin.getline(senha,20);

    while (!senha_eh_valida(senha))
    {
        std::cout << "\nDigite a senha: ";
        std::cin.getline(senha,20);
    }
    

    return 0;
}

bool senha_eh_valida(const char *senha){
    if(!tem_seis_digitos(senha)){
        std::cout << "\nSenha deve conter 6 digitos ou mais.";
        return false;
    }
    if (!tem_letra_maiusc(senha))
    {
        std::cout << "\nDeve ter uma letra maiscula.";
        return false;
    }
    if (!tem_letra_minusc(senha))
    {
        std::cout << "\nDeve ter uma letra minuscula.";
        return false;
    }
    if (!tem_um_digito(senha))
    {
        std::cout << "\nDeve ter um digito.";
        return false;
    }
    
    return true;
    

};

bool tem_seis_digitos(const char *senha){
    if(strlen(senha) > 5){
        return true;
    }

    return false;
}

bool tem_letra_maiusc(const char *senha){
    bool tem_maiusc = false;
    while(*senha){
        if (isupper(*senha))
        {
            tem_maiusc = true;
        }
        senha++;
    }

    return tem_maiusc;
}

bool tem_letra_minusc(const char *senha){
    bool tem_minusc = false;
    while(*senha){
        if (islower(*senha))
        {
            tem_minusc = true;
        }
        senha++;
    }

    return tem_minusc;
}

bool tem_um_digito(const char *senha){
    bool tem_digito = false;
    while(*senha){
        if (isdigit(*senha))
        {
            tem_digito = true;
        }
        senha++;
    }

    return tem_digito;
}

