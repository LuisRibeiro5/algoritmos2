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
std::string recebe_cpf_valido(ContaDeCliente[], int);
void recebe_endereco_valido(std::string [], int = 3);
std::string recebe_telefone_valido();
double recebe_saldo_valido();

void mostra_clientes_cpf(ContaDeCliente[], int);
ContaDeCliente* encontra_cliente_por_cpf(ContaDeCliente[],int,std::string);
bool cpf_ja_existe(ContaDeCliente[], int, std::string);
std::string recebe_cpf_valido_para_filtragem(ContaDeCliente[],int);

void remove_conta_cliente(ContaDeCliente&);

void lista_contas_cadastradas(ContaDeCliente[], int);

void imprime_conta_especifica(ContaDeCliente);

void atualizar_conta_cliente(ContaDeCliente[],int,ContaDeCliente);

const int TAM = 10;
#ifdef TESTE
//bloco para testes
int main(){
    ContaDeCliente clientes[TAM] = {""};
    
    
}
#else
//bloco principal
int main(){
    ContaDeCliente clientes[TAM]={""};
    int numContas = 0;
    std::string cpf_filtragens;
    int opcao;
    do{
        mostra_menu_de_opcoes();
        opcao = recebe_opcao_valida();
        
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
        case 2:{
            if(numContas < 1){
                std::cout << "nenhuma conta criada.\n";
                break;
            }
            mostra_clientes_cpf(clientes, TAM);
            std::cout << "digite o cpf da conta que deseja remover.\n";
            cpf_filtragens = recebe_cpf_valido_para_filtragem(clientes, TAM);
            auto cliente = encontra_cliente_por_cpf(clientes,TAM,cpf_filtragens);
            if(cliente != nullptr){
                remove_conta_cliente(*cliente);
                numContas--;
            }else{
                std::cout << "Cliente inexistente.\n";
            }
            break;
        }
        case 3:
            if(numContas < 1){
                std::cout << "nenhuma conta criada.\n";
                break;
            }
            lista_contas_cadastradas(clientes, TAM);
            break;

        case 4:{
            if(numContas < 1){
                std::cout << "nenhuma conta criada.\n";
                break;
            }
            std::cout << "digite o cpf da conta que deseja imprimir.\n";
            cpf_filtragens = recebe_cpf_valido_para_filtragem(clientes,TAM);
            auto cliente = encontra_cliente_por_cpf(clientes,TAM,cpf_filtragens);
            if(cliente != nullptr){
                imprime_conta_especifica(*cliente);
            }else{
                std::cout << "Cliente nao encontrado ou nao existe. Revise os dados.\n";
            }
            break;	
        }
        case 5:{
            if(numContas < 1){
                std::cout << "nenhuma conta criada.\n";
                break;
            }
            std::cout << "digite o cpf da conta que deseja editar.\n";
            cpf_filtragens = recebe_cpf_valido_para_filtragem(clientes,TAM);
            auto cliente = encontra_cliente_por_cpf(clientes,TAM,cpf_filtragens);
            if(cliente != nullptr){
                atualizar_conta_cliente(clientes, TAM, *cliente);
            }else{
                std::cout << "Cliente nao encontrado ou nao existe. Revise os dados.\n";
            }
            break;
        } 
        }
    }while(opcao != 6);
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
std::cout << "(6) - Sair.\n";
};

unsigned int recebe_opcao_valida(){
    unsigned int opcao;
    do
    {
        std::cout << "Opcao:";
        std::cin >> opcao;
    } while (opcao < 1 or opcao > 6);
    std::cin.ignore();
    return opcao;
}

void adiciona_nova_conta(ContaDeCliente clientes[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        if(clientes[i].nome == ""){
            std::cout << "Digite as informacoes do cliente:\n";
        clientes[i].nome = recebe_nome_valido();
        clientes[i].cpf = recebe_cpf_valido(clientes,tamanho);
        recebe_endereco_valido(clientes[i].endereco);
        clientes[i].telefone = recebe_telefone_valido();
        clientes[i].saldo = recebe_saldo_valido();
        break;
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

std::string recebe_cpf_valido(ContaDeCliente clientes[],int tamanho){
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
        }else if(cpf_ja_existe(clientes,tamanho,cpf_limpo)){
            std::cout << "esse cpf ja existe!\n";
        }else{
            break;
        }
    }
    
    return cpf_limpo;
};

bool cpf_ja_existe(ContaDeCliente clientes[], int tamanho, std::string cpf_recebido){
    for (int i = 0; i < tamanho; i++)
    {
        if(clientes[i].cpf == cpf_recebido){
            return true;
        }
    }
    return false;
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
    do{
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
        if(clientes[i].nome.size() > 0){
            std::cout << clientes[i].nome << "\n";
            std::cout << clientes[i].cpf << "\n";
            std::cout << clientes[i].telefone << "\n";
            std::cout << clientes[i].endereco[0] << " - " 
                    << clientes[i].endereco[1] << " - " 
                    << clientes[i].endereco[2] << " - " << "\n";
            std::cout << clientes[i].saldo << "\n";
            std::cout << "----------------------------------\n";
        }
    }
};

void imprime_conta_especifica(ContaDeCliente cliente){
    std::cout << cliente.nome << "\n";
    std::cout << cliente.cpf << "\n";
    std::cout << cliente.telefone << "\n";
    std::cout << cliente.endereco[0] << " - " 
            << cliente.endereco[1] << " - " 
            << cliente.endereco[2] << " - " << "\n";
    std::cout << cliente.saldo << "\n";
    std::cout << "----------------------------------\n";
}

void atualizar_conta_cliente(ContaDeCliente clientes[],int tamanho,ContaDeCliente cliente){
    std::cout << "Digite as informacoes do cliente atualizadas:\n";
        cliente.nome = recebe_nome_valido();
        cliente.nome = recebe_cpf_valido(clientes,tamanho);
        recebe_endereco_valido(cliente.endereco);
        cliente.telefone = recebe_telefone_valido();
        cliente.saldo = recebe_saldo_valido();
};

std::string recebe_cpf_valido_para_filtragem(ContaDeCliente clientes[],int tamanho){
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
        }else if(!cpf_ja_existe(clientes,tamanho,cpf_limpo)){
            std::cout << "esse cpf nao existe!\n";
        }else{
            break;
        }
    }
    
    return cpf_limpo;
};
