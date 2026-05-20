#ifndef INVENTARIOITEM_H
#define INVENTARIOITEM_H

#include "Inventario.hpp"
#include "Item.hpp"
#include <vector>

/**
 * @brief Classe que gerencia o inventário de itens de uma entidade.
 * * Implementa os métodos da classe mãe Inventario focando em objetos do tipo Item.
 */
class InventarioItem : public Inventario<Item> {
    private:
    /** @brief Vetor que armazena os itens guardados no inventário. */
        std::vector<Item> _itens;
        
    public:
    /**
     * @brief Exibe todos os itens presentes no inventário da entidade.
     */
        void mostrarInventario() override;

    /**
     * @brief Adiciona um novo item ao final do inventário.
     * @param item O objeto do item a ser inserido no vetor _itens.
     */
        void novaAcao(Item item) override;

    /**
     * @brief Substitui um item existente por um novo em uma posição específica.
     * @param posicao O índice do vetor onde a troca vai ocorrer.
     * @param novoItem O novo item que vai ocupar o lugar do antigo.
     */
        void trocarAcao(int posicao, Item novoItem) override;

    /**
     * @brief Retorna a quantidade de itens no inventário.
     */
        int getTamanho();

    /**
     * @brief Retorna um item específico pela posição.
     */
        Item getItem(int posicao);

    /**
     * @brief Compara dois inventarios para verificar se sao iguais (usado em testes).
     * @param outro O inventario a ser comparado.
     * @return true se forem iguais.
     */
        bool operator==(const InventarioItem& outro) const;

    /**
     * @brief Remove permanentemente um item do inventário.
     * @param posicao O índice do item no vetor que será descartado.
     */
        void descartarAcao(int posicao) override;
};

#endif