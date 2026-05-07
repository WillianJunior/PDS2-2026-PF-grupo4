#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>
#include "Habilidade.hpp"

/**
 * @brief Classe abstrata de inventário.
 * * Define a interface base para qualquer tipo de inventário (Itens ou Habilidades).
 */
class Inventario {
    public:
    /**
     * @brief Mostra o inventário com sua composição atual.
     */
        virtual void mostrarInventario() = 0;

    /**
     * @brief Adiciona uma nova habilidade ao inventário.
     * @param habilidade A habilidade que será adicionada ao vetor.
     */
        virtual void novaAcao(Habilidade habilidade) = 0;

    /**
     * @brief Troca uma habilidade existente por uma nova.
     * @param posicao O índice da habilidade que será removida.
     * @param novaHabilidade A nova habilidade que ocupará o lugar.
     */
        virtual void trocarAcao(int posicao, Habilidade novaHabilidade) = 0;

    /**
     * @brief Descarta uma habilidade do inventário.
     * @param posicao O índice da habilidade no vetor que será removida.
     */
        virtual void descartarAcao(int posicao) = 0;

    /**
     * @brief Destrutor virtual para garantir a limpeza correta das classes filhas.
     */
        virtual ~Inventario() = default;
};

#endif