#ifndef ITEM_H
#define ITEM_H

#include "Efeito.hpp"
#include <iostream>
#include <string>


class Item{
    private:
        std::string _nome;
        bool _alvo;
        bool _tipo;
        int _valor;
        Efeito _efeito;
    public:
        Item(std::string nome, bool alvo, bool tipo, int valor, Efeito efeito);
        int alterarVida(bool alvo, int valor);
        int aplicarEfeito(bool alvo, Efeito efeito);
        void mostrarHabilidade();
        ~Item();
};


#endif 