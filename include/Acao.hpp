#ifndef ACAO_H
#define ACAO_H

#include "Efeito.hpp"
#include <iostream>
#include <string>

class Acao {
    protected:
        std::string _nome;
        bool _tipo;
        int _valor;
        Efeito _efeito;

    public:
        Acao(std::string nome, bool alvo, int valor, Efeito efeito);
        
        virtual int alterarVida(bool alvo, int valor);
        virtual int aplicarEfeito(bool alvo, Efeito efeito);
        virtual void mostrarHabilidade();
        
        virtual ~Acao();
};

#endif