#pragma once
#include <random>

class Moeda
{
private:
    char *lado_pra_cima;
    std::mt19937 gen;
    std::uniform_int_distribution<> distr_int;
    void set_lado(int);

public:
    Moeda(/* args */);
    void jogar();
    char *get_lado();
    ~Moeda();
};
