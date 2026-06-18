#ifndef SALAESCOLHA_H
#define SALAESCOLHA_H

#include "SalaBase.hpp"
#include <iostream>
#include <string>
#include "Personagem.hpp"
#include <functional>
#include <vector>

struct OpcaoEscolha {
    std::string descricao;
    std::function<void(Personagem*)> consequencia;
};

/**
 * @brief Representa uma sala focada em escolhas e eventos interativos.
 * * Herda da classe SalaBase e adiciona lógicas específicas para apresentar opções ao jogador e executar consequências.
 */
class SalaEscolha : public SalaBase{
    private:
    /** @brief Armazena o nome específico desta sala. */
        std::string _historia;
        std::vector<OpcaoEscolha> _opcoes;
    
    public:
    /**
     * @brief Construtor da SalaEscolha.
     * * Inicializa a sala configurando o seu nome ou título.
     * @param nome O nome ou identificador da sala.
     */
        SalaEscolha(std::string nome, std::string historia);

    /**
     * @brief Encerra as atividades da sala atual.
     * * Sobrescreve o método da classe mãe (SalaBase) para lidar com a finalização do evento ou limpeza da tela.
     */
        void encerrarSala() override;

    /**
     * @brief Prepara ou avança o jogo para a próxima sala.
     * * Sobrescreve o método da classe mãe (SalaBase) para gerenciar o fluxo de transição após o evento terminar.
     * @param personagem O personagem no qual a sala irá executar ações sob.
     */
        int executarSala(Personagem& personagem)override;

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
     * @param personagem Personagem que as consequências da escolha serão acionadas.
     */
        void executarEvento(Personagem& personagem);
    /**
     * @brief Adiciona uma opcao para a sala de escolhas
     * * Uma opção é alocada no vetor de _opcoes da sala
     * @param descricao Descreve o que é o item ou habilidade "Trevo de 5 folhas".
     * @param consequencia Guarda qual a consequência da ação no personagem. "Adicionar item".
     */
        void adicionarOpcao(std::string descricao, std::function<void(Personagem*)> consequencia);
};

#endif