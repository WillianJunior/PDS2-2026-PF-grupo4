#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.hpp"
#include "Inventario.hpp"
#include <iostream>
#include <string>

using namespace std;

class Personagem : public Entidade{
    private:
        string _nome;
        Inventario _inventario;
    public:
        Personagem(int vida, Habilidade habilidade, string nome, Inventario inventario);
        int escolherHabilidade(Habilidade& habilidade) override;
        void escolherItem(int posicaoItem);
        void receberDano(int dano) override;
        ~Personagem(); 
};

#endif