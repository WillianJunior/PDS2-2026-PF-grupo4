#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "Efeito.hpp"
#include <iostream>
#include <string>


//uma habilidade pode alterar vida ou aplicar efeito
//se o alvo for personagem e alterar vida, ele cura
//se o alvo for inimigo e alterar vida, ele causa dano
//se o alvo for personagem e aplicar efeito, ele da algum buff
//se o alvo for inimigo e aplicar efeito, ele da algum debuff
class Habilidade{
    private:
        std::string _nome;
        bool _alvo;
        bool _tipo;
        int _valor;
        Efeito _efeito;
    public:
        Habilidade(std::string nome, bool alvo, bool tipo, int valor, Efeito efeito);
        int alterarVida(bool alvo, int valor);
        int aplicarEfeito(bool alvo, Efeito efeito);
        void mostrarHabilidade();
        ~Habilidade();
};


#endif 