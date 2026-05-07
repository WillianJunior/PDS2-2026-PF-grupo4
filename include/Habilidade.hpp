#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "Acao.hpp"

class Habilidade : public Acao {
    public:
        Habilidade(std::string nome, bool alvo, int valor, Efeito efeito);
        ~Habilidade();
};

#endif