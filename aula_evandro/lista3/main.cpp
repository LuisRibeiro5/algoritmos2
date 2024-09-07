#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

struct ContaDeCliente {
    std::string nome;
    std::string cpf;
    std::string endereco[3];
    std::string telefone;
    double saldo;
};

void mostra_menu_de_opcoes();
unsigned int recebe_opcao_valida();
void adiciona_nova_conta(ContaDeCliente&);
std::string recebe_nome_valido();
std::string recebe_cpf_valido();
void recebe_endereco_valido(std::string [], int = 3);
std::string recebe_telefone_valido();
double recebe_saldo_valido();

const int TAM = 10;
#ifdef TESTE
//bloco para testes
int main(){
    // mostra_menu_de_opcoes();
    int opcao = recebe_opcao_valida();
    std::string telefone = recebe_telefone_valido();
    std::cout << "\n" << telefone << "\n";
}
#else
//bloco principal
int main(){
    ContaDeCliente clientes[TAM]={""};
    int numContas = 0;

    mostra_menu_de_opcoes();
    int opcao = recebe_opcao_valida();
    
    switch (opcao)
    {
    case 1:
        adiciona_nova_conta(clientes[numContas]);
        numContas++;
        break;
    case 2:
        //remove_conta_cliente
        numContas--;
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

unsigned int recebe_opcao_valida(){
    unsigned int opcao;
    do
    {
        std::cout << "Opcao:";
        std::cin >> opcao;
    } while (opcao < 1 or opcao > 5);
    std::cin.ignore();
    return opcao;
}

void adiciona_nova_conta(ContaDeCliente& cliente){
    std::cout << "Digite as informacoes do cliente:\n";
    cliente.nome = recebe_nome_valido();
    cliente.cpf = recebe_cpf_valido();
    recebe_endereco_valido(cliente.endereco);
    cliente.telefone = recebe_telefone_valido();
    cliente.saldo = recebe_saldo_valido();
    
};

std::string recebe_nome_valido(){
    std::string nome;
    do
    {
        std::cout << "Nome: ";
        std::getline(std::cin,nome);
    } while (nome.empty() || nome == "\n" || nome == " ");
    return nome;
};

std::string recebe_cpf_valido(){
    std::string cpf;
    std::string cpf_limpo = "";
    while (true)
    {
        cpf_limpo = "";
        std::cout << "cpf: ";
        std::getline(std::cin,cpf);
        for (int i = 0; i < cpf.length(); i++){

            if (isdigit(cpf[i])){
                cpf_limpo += cpf[i];
            }
        }
        
        if(cpf_limpo.size() != 11){
            std::cout << "cpf inválido!\n";
        }else{
            break;
        }
    }
    
    return cpf_limpo;
};

void recebe_endereco_valido(std::string endereco[],int tam){
    do
    {
    std::cout << "Cidade: ";
   
    std::getline(std::cin,endereco[0]);
    } while (endereco[0] == "");

    std::string uf_limpo = "";
    do
    {
        uf_limpo = "";
        std::cout << "UF: ";
        std::getline(std::cin,endereco[1]);
        for(char c : endereco[1]){

            if (isalpha(c)){
                uf_limpo += toupper(c);
            }
        }

        if(uf_limpo.size() != 2){
            std::cout << "UF inválido! formato deve ser: \"SP\"\"SC\" \n";
        }else{
            endereco[1] = uf_limpo;
            break;
        }
        
    } while (true);

    std::string cep_limpo;
    do
    {
        cep_limpo="";
        std::cout << "CEP: ";
        std::getline(std::cin, endereco[2]);
        for(char c : endereco[2]){
            if(isdigit(c)){
                cep_limpo += c;
            }
        }
        if(cep_limpo.size() != 8){
            std::cout << "Endereço inválido!\n";
        }else{
            endereco[2] = cep_limpo;
            break;
        }
    } while (true);
}

std::string recebe_telefone_valido(){
    std::string telefone;
    std::string telefone_limpo;
    do{
        telefone_limpo = "";
        std::cout << "formato de telefone: (DDD) 9XXXX-YYYY\n";
        std::cout << "telefone: ";
       
        std::getline(std::cin,telefone);
        for(char c : telefone){
            if(isdigit(c)){
                telefone_limpo += c;
            }
        }
        if(telefone_limpo.size() > 12 || telefone_limpo.size() < 10){
            std::cout << "Formato telefônico inválido!\n";
        }else{
            break;
        }
    }while(true);
    return telefone_limpo;
};

double recebe_saldo_valido(){
    double saldo;
    do
    {
        std::cout << "Saldo na conta: ";
        std::cin >> saldo;
    } while (saldo < 0);
    
    return saldo;
};