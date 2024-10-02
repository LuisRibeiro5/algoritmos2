#include <iostream>

int to_int(char*);

int main(){
    char num[21];

    std::cout << "Digite um num: ";
    std::cin.getline(num,sizeof(num));

    int num_int = to_int(num);

    std::cout << num_int;

    return 0;
}

int to_int(char *str){
    int num = std::stoi(str);

    return num;
};

