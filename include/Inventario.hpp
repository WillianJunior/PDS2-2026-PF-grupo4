#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>
#include "Utils.hpp"

/**
 * @brief Classe abstrata de inventário usando Templates.
 * @tparam T O tipo de objeto que o inventário irá guardar (Habilidade ou Item).
 * * Define a interface base para qualquer tipo de inventário (Itens ou Habilidades).
 */
template <typename T>
class Inventario {
    public:
    /**
     * @brief Mostra o inventário com sua composição atual.
     */
        virtual void mostrarInventario() = 0;

    /**
     * @brief Adiciona um novo elemento ao inventário.
     * @param elemento O elemento que será adicionado ao vetor.
     */
        virtual void novaAcao(T elemento) = 0;

    /**
     * @brief Troca um elemento existente por um novo.
     * @param posicao O índice do elemento que será removido.
     * @param novoElemento O novo elemento que ocupará o lugar.
     */
        virtual void trocarAcao(int posicao, T novoElemento) = 0;

    /**
     * @brief Descarta um elemento do inventário.
     * @param posicao O índice do elemento no vetor que será removido.
     */
        virtual void descartarAcao(int posicao) = 0;

    /**
     * @brief Destrutor virtual para garantir a limpeza correta das classes filhas.
     */
        virtual ~Inventario() = default;
};

#endif