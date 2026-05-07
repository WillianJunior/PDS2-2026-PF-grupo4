#ifndef EFEITO_H
#define EFEITO_H

#include <iostream>

class Efeito{
    private:
        std::string _nome;
        int _valor;
        int _duracao;
    public:
        Efeito(std::string nome, int valor, int duracao);
        void aplicarEfeito();
        void atualizarDuracao();
        bool isEncerrado();
        ~Efeito();
};

#endif