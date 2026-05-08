#ifndef INVENTARIOHABILIDADE_H
#define INVENTARIOHABILIDADE_H

#include "Inventario.hpp"
#include "Habilidade.hpp"
#include <vector>

/**
 * @brief Classe que gerencia o inventário de habilidades de uma entidade.
 * * Implementa os métodos da classe abstrata Inventario focando em objetos Habilidade.
 */
class InventarioHabilidade : public Inventario<Habilidade> {
    private:
    /** @brief Vetor que armazena os objetos de habilidade. */
        std::vector<Habilidade> listaHabilidades;
        
    public:
    /**
     * @brief Exibe todas as habilidades presentes na lista da entidade.
     */
        void mostrarInventario() override;

    /**
     * @brief Adiciona uma nova habilidade ao final do vetor listaHabilidades.
     * @param habilidade Objeto da habilidade a ser inserido.
     */
        void novaAcao(Habilidade habilidade) override;

    /**
     * @brief Remove uma habilidade de uma posição específica e insere uma nova.
     * @param posicao Índice do vetor onde a troca ocorrerá.
     * @param novaHabilidade Objeto da nova habilidade a ser inserida.
     */
        void trocarAcao(int posicao, Habilidade novaHabilidade) override;

    /**
     * @brief Remove permanentemente uma habilidade do vetor.
     * @param posicao Índice da habilidade que será deletada.
     */
        void descartarAcao(int posicao) override;
};

#endif