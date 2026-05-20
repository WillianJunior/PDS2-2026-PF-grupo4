#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidade.hpp"
#include <iostream>
#include <string>

/**
 * @brief Entidade que irá contra o personagem principal
 * Classe que herda de entidade, sendo o inimigo do jogo com vida, habilidade e nomes específicos.
 */
class Inimigo : public Entidade{
    private:
    /** @brief Se o inimigo é um inimigo menor ou um Boss */
        bool tipo;
    public:
    /**
     * @brief Construtor do Inimigo
     * * Função que inicializa um inimigo com vida, inventario de habilidade, nome e seu tipo
     * @param vida Quantidade de vida que o inimigo tem
     * @param habilidade Quais são as habilidades do inimigo
     * @param nome Qual é o nome do inimigo
     * @param tipo Se o inimigo é um boss ou um inimigo menor
     */
        Inimigo(int vida, InventarioHabilidade habilidade, std::string nome, bool tipo);

    /**
     * @brief Selecionar uma habilidade, visualizar sua ação e executar
     * * Sobrescreve o método da classe mãe Entidade
     * * @param posicaoHabilidade índice (posição) da habilidade dentro do vetor _habilidades em inventarioHabilidade
     * @return Retorna um valor inteiro (dano causado, dano curado ou mudança de estado)
     */
        int escolherHabilidade(int posicaoHabilidade) override;

    /**
     * @brief Alterar a vida atual do inimigo para mais ou para menos
     * * Deverá ter um valor máximo: Gerald Weber tem 100 de vida máxima, tentou curar 60 estando com 50 : fica com 100
     * * Sobrescreve o método da classe mãe (Entidade) para tomar dano ou curar
     * @param valor Quantidade de vida a ser somada ou subtraída.
     */
        void alterarVida(int valor) override;

    /**
     * @brief Detecta se o personagem está morto ou vivo
     * * Sobrescreve o método da classe mãe (Entidade) para checar se está vivo ou morto
     * * Checa a vida e essa deve estar maior que 0 para estar em 0 (false).
     * @return Retorna true se estiver morto (vida <= 0), e false caso contrário.
     */
        bool isMorto() override;
    
    /**
     * @brief Retorna o tipo do inimigo (menor ou Boss).
     */
        bool getTipo();

    /**
     * @brief Destrutor de inimigo
     * * Sobrescreve o método de destruir Entidade, destruindo toda a data de Inimigo
     * * Evitar vazamento de memória
     */
        ~Inimigo();
};

#endif