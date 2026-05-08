#ifndef MENU_H
#define MENU_H

#include <iostream>

/**
 * @brief Classe responsável por gerenciar o menu principal do jogo.
 * * Lida com a interface inicial, permitindo ao jogador iniciar a partida e fazer as escolhas pré-jogo.
 */
class Menu {
    public:
    /**
     * @brief Construtor padrão da classe Menu.
     * * Prepara a interface e os recursos iniciais necessários para exibir o menu na tela.
     */
        Menu();

    /**
     * @brief Inicia a partida.
     * * Faz a transição da tela de menu para o loop principal do jogo (gameplay).
     */
        void iniciarJogo();

    /**
     * @brief Permite a seleção do personagem.
     * * Exibe as opções disponíveis e registra qual personagem o jogador escolheu para iniciar a aventura.
     */
        void escolherPersonagemInicial();

    /**
     * @brief Destrutor da classe Menu.
     * * Libera da memória os recursos que foram alocados pela interface do menu.
     */
        ~Menu();
};

#endif