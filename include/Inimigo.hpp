#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidade.hpp"
#include "Personagem.hpp"
#include <iostream>
#include <string>

/**
 * @brief Entidade que irá contra o personagem principal
 * Classe que herda de entidade, sendo o inimigo do jogo com vida, habilidade e nomes específicos.
 */
class Inimigo : public Entidade{
    private:
    /** @brief Valor maximo que o inimigo pode ter de vida */
        int _vidaMaxima;

    public:
    /**
     * @brief Construtor do Inimigo
     * * Função que inicializa um inimigo com vida, inventario de habilidade, nome e seu tipo
     * @param vida Quantidade de vida que o inimigo tem
     * @param habilidade Quais são as habilidades do inimigo
     * @param nome Qual é o nome do inimigo
     */
        Inimigo(int vida, InventarioHabilidade habilidade, std::string nome);

    /**
     * @brief Selecionar uma habilidade a ser executada no turno.
     * * Sobrescreve o método da classe mãe Entidade
     * * @param posicaoHabilidade índice (posição) da habilidade dentro do vetor _habilidades em inventarioHabilidade
     * @return Retorna a copia do objeto Habilidade.
     */
        Habilidade& escolherHabilidade(int posicaoHabilidade) override;

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
     * @brief Realiza o combate do inimigo
     * * Possui um sistema de alaetoriedade para escolher as ações, mas filtra para tomar decisões um pouco mais lógicas.
     * @param personagem Recebe o personagem que está combatendo o inimigo.
     */
        void combateInimigo(Personagem& personagem);

    /**
     * @brief Destrutor de inimigo
     * * Sobrescreve o método de destruir Entidade, destruindo toda a data de Inimigo
     * * Evitar vazamento de memória
     */
        ~Inimigo();
};

#endif