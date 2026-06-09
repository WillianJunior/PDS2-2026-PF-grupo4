#ifndef SALAESCOLHA_H
#define SALAESCOLHA_H

#include "SalaBase.hpp"
#include <iostream>
#include <string>

/**
 * @brief Representa uma sala focada em escolhas e eventos interativos.
 * * Herda da classe SalaBase e adiciona lógicas específicas para apresentar opções ao jogador e executar consequências.
 */
class SalaEscolha : public SalaBase{
    private:
    /** @brief Armazena o nome específico desta sala. */
        std::string _nome;
    
    public:
    /**
     * @brief Construtor da SalaEscolha.
     * * Inicializa a sala configurando o seu nome ou título.
     * @param nome O nome ou identificador da sala.
     */
        SalaEscolha(std::string nome);
    /**
     * @brief Retorna o nome da sala.
     * @return std::string contendo o nome da sala.
     */
        std::string getNome() const;

    /**
     * @brief Encerra as atividades da sala atual.
     * * Sobrescreve o método da classe mãe (SalaBase) para lidar com a finalização do evento ou limpeza da tela.
     */
        void encerrarSala() override;

    /**
     * @brief Prepara ou avança o jogo para a próxima sala.
     * * Sobrescreve o método da classe mãe (SalaBase) para gerenciar o fluxo de transição após o evento terminar.
     */
        int executarSala();

    /**
     * @brief Exibe as informações e o ambiente da sala para o jogador.
     * * Sobrescreve o método da classe mãe (SalaBase).
     */
        void mostrarSala() override;

    /**
     * @brief Exibe as opções de decisão disponíveis para o jogador nesta sala.
     */
        void mostrarOpcoes();

    /**
     * @brief Processa a decisão do jogador e executa o evento correspondente.
     * * Aplica as consequências da escolha (ex: receber um item, perder vida, etc).
     */
        void executarEvento();
};

#endif