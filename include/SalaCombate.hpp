#ifndef SALACOMBATE_H
#define SALACOMBATE_H

#include "SalaBase.hpp"
#include "Inimigo.hpp"
#include <iostream>
#include <string>
#include <memory>

/**
 * @brief Classe que representa uma sala focada em conflitos e batalhas.
 * * Herda de SalaBase e implementa as mecânicas específicas de combate, 
 * como gerenciamento de turnos e inimigos.
 */
class SalaCombate : public SalaBase {
    private:
        std::string _historia;
        std::unique_ptr<Inimigo> _inimigo;
    public:
        /**
         * @brief Construtor da classe SalaCombate.
         * @param nome O nome ou identificador da sala de combate.
         */
        SalaCombate(std::string nome);

        /**
         * @brief Finaliza os eventos da sala de combate.
         * Sobrescreve o método da classe mãe.
         */
        void encerrarSala() override;

        /**
         * @brief Faz a transição para a próxima sala após o término do combate.
         * Sobrescreve o método da classe mãe.
         */
        int executarSala() override;

        /**
         * @brief Exibe a interface da sala de combate (status, opções de batalha, etc.).
         * Sobrescreve o método da classe mãe.
         */
        void mostrarSala() override;

        /**
         * @brief Gerencia a ordem de ações e a alternância entre o turno do jogador e do inimigo.
         */
        void controleDeTurnos();

        /**
         * @brief Instancia ou prepara o(s) inimigo(s) que o jogador enfrentará nesta sala.
         */
        void alocarInimigo();
};

#endif