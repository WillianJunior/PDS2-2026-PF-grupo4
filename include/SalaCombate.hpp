#ifndef SALACOMBATE_H
#define SALACOMBATE_H

#include "SalaBase.hpp"
#include "Inimigo.hpp"
#include "Personagem.hpp"
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
        std::string _textoVitoria;
        std::string _textoDerrota;


    public:
        /**
         * @brief Construtor da classe SalaCombate.
         * @param nome O nome ou identificador da sala de combate.
         */
        SalaCombate(std::string nome, std::string historia, std::string textoVitoria, std::string textoDerrota, std::string nomePersonagem, int idInimigo);
        /**
         * @brief Finaliza os eventos da sala de combate.
         * Sobrescreve o método da classe mãe.
         */
        void encerrarSala() override;

        /**
         * @brief Faz a transição para a próxima sala após o término do combate.
         * Sobrescreve o método da classe mãe.
         */
        int executarSala(Personagem& Personagem) override;

        /**
         * @brief Exibe a interface da sala de combate (status, opções de batalha, etc.).
         * Sobrescreve o método da classe mãe.
         */
        void mostrarSala() override;

        /**
         * @brief Retorna o tipo da sala ("C" para combate, "E" para escolha).
         */
        char getTipo() override;


        /**
         * @brief Instancia ou prepara o(s) inimigo(s) que o jogador enfrentará nesta sala.
         */
        std::unique_ptr<Inimigo> alocarInimigo(std::string nomePersonagem, int idInimigo);
};

#endif