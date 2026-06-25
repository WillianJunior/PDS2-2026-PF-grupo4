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
        /** @brief String que contem a historia da sala. */
        std::string _historia;

        /** @brief Ponteiro que contem o inimigo. */
        std::unique_ptr<Inimigo> _inimigo;

        /** @brief String que contem o texto de vitória da sala. */
        std::string _textoVitoria;

        /** @brief String que contem o texto de derrota da sala. */
        std::string _textoDerrota;

        /** @brief Inteiro que armazena o id do inimigo. */
        int _idInimigo;

    public:
        /**
         * @brief Construtor da classe SalaCombate.
         * @param nome O nome ou identificador da sala de combate.
         * @param historia A história da sala apresentada ao jogador.
         * @param textoVitoria O texto que aparece para o jogador caso ele vença o combate na sala.
         * @param textoVitoria O texto que aparece para o jogador caso ele perca o combate na sala.
         * @param nomePersonagem O nome do personagem.
         * @param idInimigo O id do inimigo da sala.
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
         * @brief Retorna o id do inimigo.
         */
        int getId() override;


        /**
         * @brief Instancia ou prepara o(s) inimigo(s) que o jogador enfrentará nesta sala.
         * @param nomePersonagem O nome do personagem.
         * @param idInimigo O id do inimigo da sala.
         */
        std::unique_ptr<Inimigo> alocarInimigo(std::string nomePersonagem, int idInimigo);
};

#endif