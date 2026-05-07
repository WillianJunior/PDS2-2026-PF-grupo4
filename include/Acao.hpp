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
        bool _alvo;

    public:
        Acao(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo);
        
        virtual int alterarVida(bool alvo, int valor);
        virtual int aplicarEfeito(bool alvo, Efeito efeito);
        virtual void mostrarHabilidade();
        
        virtual ~Acao();
};

#endif