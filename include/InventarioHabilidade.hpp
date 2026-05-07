#ifndef INVENTARIOHABILIDADE_H
#define INVENTARIOHABILIDADE_H

#include "Inventario.hpp"
#include "Habilidade.hpp"

class InventarioHabilidade : public Inventario{
    private:
        std::vector<Habilidade> _habilidades;
    public:
        void mostrarInventario() override;
        void novaAcao() override;
        void trocarAcao() override;
        void descartarAcao() override;
};

#endif