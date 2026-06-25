#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Personagem.hpp"
#include <memory>
#include <string>
#include "Utils.hpp"


/**
 * @brief Classe responsável por gerenciar o menu principal do jogo.
 * * Lida com a interface inicial, permitindo ao jogador iniciar a partida e fazer as escolhas pré-jogo.
 */
class Menu {
    private:
    /** @brief Ponteiro para a escolha inicial de personagem. */
        std::unique_ptr<Personagem> escolherPersonagemInicial();
    
    public:
        /**
         * @brief Construtor padrão da classe Menu.
         */
        Menu();

        /**
         * @brief Executa a interface do menu principal
         * @param existeSave valor booleano que indica se existe um save, permitindo recuperar o progresso de um jogo antigo.
         * @return Ponteiro inteligente para o Personagem criado, ou nullptr se o utilizador optar por sair.
         */
        std::unique_ptr<Personagem> executarMenuInicial(bool existeSave);

        /**
         * @brief Destrutor da classe Menu.
         */
        ~Menu();
        
};

#endif