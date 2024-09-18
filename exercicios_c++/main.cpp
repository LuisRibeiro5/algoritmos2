#include <iostream>
#include <algorithm>

struct Contato
{
    std::string nome;
    std::string telefone;
    std::string email;
};

void mostra_menu();
void adicionar_contato(Contato*, int);
Contato *redimensionar_array(Contato *arr, int, int);
int busca_contato_pelo_nome(Contato*, int);
void remover_contato(Contato*, int, int);
bool compara_por_nome(const Contato &a, const Contato &b);

int main(){
    int quantidade = 0;
    Contato *celular = nullptr;
    int opcao;
    int idx_busca;

    
     
     do
     {
        mostra_menu();
        std::cin >> opcao;
        std::cin.ignore();
        std::sort(celular,celular + quantidade, compara_por_nome);

        switch (opcao)
        {
        case 1:
            celular = redimensionar_array(celular,quantidade,++quantidade);
            adicionar_contato(celular, quantidade);
            break;
  
        case 2:
            idx_busca = busca_contato_pelo_nome(celular,quantidade);
            if(idx_busca != -1){
                //Aqui estou passando como parametro o tamanho atual -1 para que no momento da copia do array antigo para o novo o ultimo elemento nao seja copiado (ultimo elemento é oque eu apaguei*)

                remover_contato(celular,quantidade,idx_busca);
                celular = redimensionar_array(celular,quantidade - 1,--quantidade);

            }else{
                std::cout << "\nNome de contato inexistente\n";
            } 
            
            break;
        }
     } while (opcao != 4);

    delete[] celular;
    return 0;
}

void mostra_menu(){
    std::cout << "\nMenu\n";
    std::cout << "\n1. Adicionar novo contato";
    std::cout << "\n2. Remover contato";
    std::cout << "\n3. Buscar contato"; 
    std::cout << "\n4. Sair";

    std::cout<< "\nOpcao: ";
};

Contato *redimensionar_array(Contato *arr, int tamanho_atual, int tamanho_novo){
    Contato *novo_array = new Contato[tamanho_novo];

    for(int i = 0; i < tamanho_atual; i++){
        novo_array[i] = arr[i];
    }

    delete[] arr;

    return novo_array;
};


void adicionar_contato(Contato *celular, int num_contato){
    Contato novo_contato;

    std::cout <<"\nNome: ";
    std::getline(std::cin,novo_contato.nome);

    std::cout <<"\nTelefone: ";
    std::getline(std::cin,novo_contato.telefone);

    std::cout <<"\nEmail: ";
    std::getline(std::cin,novo_contato.email);
    
    celular[num_contato - 1] = novo_contato;
}
    
int busca_contato_pelo_nome(Contato *celular, int tamanho){
    std::string alvo;
    std::cout << "\nNome: ";
    std::getline(std::cin, alvo);

    int left = 0, right = tamanho - 1, mei;
    while (left <= right)  
    {
        mei = left + (right - left) / 2;

        if(alvo == celular[mei].nome){
            return mei;
        } 

        if(alvo < celular[mei].nome){
            right = mei - 1;
        }   

        else{
            left = mei + 1;
        }    
    }

    return -1;
    
};

bool compara_por_nome(const Contato &a, const Contato &b){
    return a.nome < b.nome;
};

void remover_contato(Contato *celular, int quantidade, int idx_remover){
    for(int i = idx_remover; i < quantidade - 1; i++){
        celular[i] = celular[i + 1];
    }

    celular[quantidade - 1].nome = "";
    celular[quantidade - 1].telefone = "";
    celular[quantidade - 1].email = "";
};