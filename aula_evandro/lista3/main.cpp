#include <iostream>
#include <string>

struct ContaDeCliente {
    std::string nome;
    std::string cpf;
    std::string endereco[3];
    std::string telefone;
    double saldo;
};

void mostra_menu_de_opcoes();
int recebe_opcao_valida();
void adiciona_nova_conta(ContaDeCliente&);
std::string recebe_nome_valido();
std::string recebe_cpf_valido();
void recebe_endereco_valido(std::string [], int);

const int TAM = 10;
#ifdef TESTE
//bloco para testes
int main(){
    mostra_menu_de_opcoes();
    int opcao = recebe_opcao_valida();

    return 0;
}
#else
//bloco principal
int main(){
    ContaDeCliente clientes[TAM]={""};
    int contaCliente = 0;

    mostra_menu_de_opcoes();
    int opcao = recebe_opcao_valida();
    
    switch (opcao)
    {
    case 1:
        //adiciona_nova_conta(clientes[contaCliente])
        contaCliente++;
        break;
    case 2:
        //remove_conta_cliente
        break;
    case 3:
        //lista_contas_cadastradas
        break;
    case 4:
        //imprime_conta_específica
        break;	
    case 5:
        //atualizar_conta_cliente
        break;
    }

    return 0;
}
#endif

void mostra_menu_de_opcoes(){
    std::cout << "\n====================================\n";
        std::cout << "\tMENU DE OPCOES:\n";

std::cout << "(1) - adicionar nova conta de cliente.\n";
std::cout << "(2) - remover conta de cliente\n";
std::cout << "(3) - Listar contas cadastradas.\n";
std::cout << "(4) - Imprimir conta específica.\n";
std::cout << "(5) - Atualizar conta de cliente.\n";
};

int recebe_opcao_valida(){
    int opcao;
    do
    {
        std::cout << "Opcao:";
        std::cin >> opcao;
    } while (opcao < 1 or opcao > 5);
    
    return opcao;
}

void adiciona_nova_conta(ContaDeCliente& cliente){
    std::cout << "Digite as informacoes do cliente:\n";
    cliente.nome = recebe_nome_valido();
    cliente.cpf = recebe_cpf_valido();
    recebe_endereco_valido(cliente.endereco);
    cliente.telefone = recebe_telefone_valido();
    
};

std::string recebe_nome_valido(){
    std::string nome;
    do
    {
        std::cout << "Nome: ";
        std::cin.ignore();
        std::getline(std::cin,nome);
    } while (nome.empty());
    return nome;
};

std::string recebe_cpf_valido(){
    std::string cpf;
    while (true)
    {
        std::cout << "cpf: ";
        std::cin.ignore();
        std::getline(std::cin,cpf);
        for (int i = 0; i < cpf.length(); i++){

            if (!isdigit(cpf[i])){
                cpf.erase(i);
                --i;
            }
        }
        
        if(cpf.size() != 11){
            std::cout << "cpf inválido!\n";
        }else{
            break;
        }
    }
    
    return cpf;
};

void recebe_endereco_valido(std::string endereco[],int tam = 3){
    do
    {
    std::cout << "Cidade: ";
    std::cin.ignore();
    std::getline(std::cin,endereco[0]);
    } while (endereco[0] == "");

    do
    {
        std::cout << "UF: ";
        std::cin.ignore();
        std::getline(std::cin,endereco[1]);
        for (int i = 0; i < endereco[1].size(); i++){

            if(!isalpha(endereco[1].at(i))){
                endereco[1].at(i) = toupper(endereco[1].at(i));
                endereco[1].erase(i);
                --i;
            }
        }

        if(endereco[1].size() != 2){
            std::cout << "UF inválido! formato deve ser: \"SP\"\"SC\" \n";
        }else{
            break;
        }
        
    } while (true);

    do
    {
        std::cout << "CEP: ";
        std::cin.ignore();
        std::getline(std::cin, endereco[2]);
        for (int i = 0; i < endereco[2].size(); i++){

            if(!isdigit(endereco[2].at(i))){
                endereco[2].erase(i);
                --i;
            }
        }
        if(endereco[2].size() != 8){
            std::cout << "Endereço inválido!\n";
        }else{
            break;
        }
    } while (true);
}