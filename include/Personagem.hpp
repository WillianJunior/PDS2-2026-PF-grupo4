#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.hpp"
#include "InventarioItem.hpp"
#include <iostream>
#include <string>

using namespace std;

//a entidade que vai ser alterada durante o jogo, temos que pensar ainda como ter 5 opçoes iniciais prontas, e ele decide entre as tres
//alem de ter que decidir quais as diferenças delas e como elas vao ser descritas no codigo (classe ou arquivo.txt)
class Personagem : public Entidade{
    private:
        InventarioItem _inventario;
    public:
        Personagem(int vida, InventarioHabilidade habilidade, string nome, InventarioItem inventario);

        
        int escolherHabilidade(Habilidade& habilidade) override;

        //vai receber qual a posiçao do vetor inventario e 
        void escolherItem(int posicaoItem);
        void alterarVida(int valor) override;
        ~Personagem(); 
};

#endif