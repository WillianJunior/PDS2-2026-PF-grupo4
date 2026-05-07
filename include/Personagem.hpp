#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.hpp"
#include "InventarioItem.hpp"
#include <iostream>
#include <string>

/**
 * @brief Representa o personagem no jogo, herda da classe entidade
 * * Responsável por gerenciar as ações do personagem, como inventário, items, habilidades, vida.
 */

class Personagem : public Entidade{
    private:
    /** @brief Guarda os itens que o personagem possui */
        InventarioItem _inventario;

    public:
    /**
     * @brief Construtor padrão do personagem
     * Aloca a vida do personagem, seu inventário de habilidades, seu nome e seu inventario de itens iniciais.
     * @param vida Quantidade inicial de pontos de vida.
     * @param inventarioHabilidade Objeto que contém as habilidades iniciais do personagem
     * @param nome Nome do personagem
     * @param inventarioItem Objeto que contém os itens iniciais do personagem
     */
        Personagem(int vida, InventarioHabilidade inventarioHabilidade, std::string nome, InventarioItem inventarioItem);

    /**
     * @brief Selecionar uma habilidade, visualizar sua ação e executar
     * * Sobrescreve o método da classe mãe Entidade
     * * @param posicaoHabilidade índice (posição) da habilidade dentro do vetor _habilidades em inventarioHabilidade
     * @return Retorna um valor inteiro (dano causado, dano curado ou mudança de estado)
     */
        int escolherHabilidade(int posicaoHabilidade) override;

    /**
     * @brief Escolher um Item a partir do inventarioItem e utilizá-lo.
     * * Recebe qual a posição do item no vetor Items contido em inventarioItem para selecionar.
     * * @param posicaoItem índice (posição) do item dentro do vetor Items em inventarioItem.
     * @return Retorna um valor inteiro (dano causado, dano curado ou mudança de estado)
     */
        void escolherItem(int posicaoItem);

    /**
     * @brief Alterar a vida atual do personagem para mais ou para menos
     * * Deverá ter um valor máximo: P1 tem 100 de vida máxima, tentou curar 60 estando com 50 : fica com 100
     * * Sobrescreve o método da classe mãe (Entidade) para aplicar dano ou curar
     * @param valor Quantidade de vida a ser somada ou subtraída.
     */
        void alterarVida(int valor) override;
        
    /**
     * @brief Detecta se o personagem está morto ou vivo
     * * Sobrescreve o método da classe mãe (Entidade) para checar se está vivo ou morto
     * * Checa a vida e essa deve estar maior que 0 para estar em 0 (false).
     */
        bool isMorto() override;

    /**
     * @brief Destrutor da classe Personagem.
     * * Libera os recursos alocados pelo personagem quando ele for destruído.
     */
        ~Personagem(); 
};

#endif