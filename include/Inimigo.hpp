#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidade.hpp"
#include <iostream>
#include <string>


class Inimigo : public Entidade{
    private:
        bool tipo;
    public:
        Inimigo(double vida, InventarioHabilidade habilidade, std::string nome, bool tipo);
        int escolherHabilidade(Habilidade& habilidade) override;
        void alterarVida(int valor) override;
        ~Inimigo();
};

#endif