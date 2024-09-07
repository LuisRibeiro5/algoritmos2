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

void adiciona_nova_conta(ContaDeCliente[], int);
std::string recebe_nome_valido();
std::string recebe_cpf_valido();
void recebe_endereco_valido(std::string [], int = 3);
std::string recebe_telefone_valido();
double recebe_saldo_valido();

void mostra_clientes_cpf(ContaDeCliente[], int);
ContaDeCliente* encontra_cliente_por_cpf(ContaDeCliente[],int,std::string);

void remove_conta_cliente(ContaDeCliente[]);

void lista_contas_cadastradas(ContaDeCliente[], int);

const int TAM = 10;
#ifdef TESTE
//bloco para testes
int main(){
    // mostra_menu_de_opcoes();
    
}
#else
//bloco principal
int main(){
    ContaDeCliente clientes[TAM]={""};
    int numContas = 0;
    std::string cpf_remover;

    mostra_menu_de_opcoes();
    int opcao = recebe_opcao_valida();
    
    switch (opcao)
    {
    case 1:
        if(numContas < 10){
            adiciona_nova_conta(clientes, TAM);
            numContas++;
        }else{
            std::cout << "Numero máximo de contas criadas atingido.\n";
        }
        break;
    case 2:
        mostra_clientes_cpf(clientes, TAM);

        std::cout << "digite o cpf da conta que deseja remover.\n";
        cpf_remover = recebe_cpf_valido();
        auto cliente = encontra_cliente_por_cpf(clientes,TAM,cpf_remover);
        if(cliente != nullptr){
            remove_conta_cliente(cliente);
            numContas--;
        }else{
            std::cout << "Cliente inexistente.\n";
        }
        break;
    case 3:
        lista_contas_cadastradas();
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

void adiciona_nova_conta(ContaDeCliente clientes[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        if(clientes[i].nome == ""){
            std::cout << "Digite as informacoes do cliente:\n";
        clientes[i].nome = recebe_nome_valido();
        clientes[i].cpf = recebe_cpf_valido();
        recebe_endereco_valido(clientes[i].endereco);
        clientes[i].telefone = recebe_telefone_valido();
        clientes[i].saldo = recebe_saldo_valido();
        }
    }
    
    
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

void mostra_clientes_cpf(ContaDeCliente clientes[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(clientes[i].nome.size() > 0){
            std::cout << clientes[i].nome << " - " << clientes[i].cpf << "\n";
        }
    }
};

void remove_conta_cliente(ContaDeCliente &cliente){
    cliente.nome = "";
    cliente.telefone = "";
    cliente.saldo = 0;
    cliente.endereco[0] = "";
    cliente.endereco[1] = "";
    cliente.endereco[2] = "";
};

ContaDeCliente* encontra_cliente_por_cpf(ContaDeCliente clientes[],int tamanho,std::string cpf_encontra){
    for (int i = 0; i < tamanho; i++)
    {
        if(clientes[i].cpf == cpf_encontra){
            return &clientes[i];
        }
    }
    return nullptr;
};

void lista_contas_cadastradas(ContaDeCliente clientes[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << clientes[i].nome;
        std::cout << clientes[i].cpf;
        std::cout << clientes[i].telefone;
        std::cout << clientes[i].endereco[0] << " - " 
                  << clientes[i].endereco[1] << " - " 
                  << clientes[i].endereco[3] << " - " ;
        std::cout << clientes[i].saldo;
        std::cout << "----------------------------------"
    }
    
};