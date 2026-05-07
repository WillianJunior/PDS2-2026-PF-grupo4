#ifndef INVENTARIOHABILIDADE_H
#define INVENTARIOHABILIDADE_H

#include "Inventario.hpp"
#include "Habilidade.hpp"

class InventarioHabilidade : public Inventario{
    public:
        std::vector<Habilidade> _habilidades;
        void mostrarInventario();
        void novoItem();
        void trocarItem();
        void descartarItem();
};

#endif