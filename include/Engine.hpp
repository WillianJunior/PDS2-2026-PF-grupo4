#ifndef ENGINE_H
#define ENGINE_H

#include "Personagem.hpp"
#include "SalaBase.hpp"
#include <memory>
#include "Utils.hpp"

/**
 * @brief Classe gerenciadora do loop principal do jogo - maquina de estados
 * Cria o ciclo de vida do jogo, desde a configuração inicial do 
 * personagem as instâncias das salas.
 */
class Engine {
    private:
        /** @brief Ponteiro que controla o tempo de vida do personagem. */
        std::unique_ptr<Personagem> _personagem;

        /** @brief Vector que irá guardar todas as salas da run */
        std::vector<std::unique_ptr<SalaBase>> _salasDoJogo;

        /** @brief Irá gerar aleatoriamente a sequencias das salas da run */
        void prepararSalas(std::string nome);

        /** * @brief 
         * @param idSala Identificador numérico da sala a ser carregada.
         * @return Ponteiro para a nova instância genérica de SalaBase.
         */
        std::unique_ptr<SalaBase> fabricarProximaSala(int idSala);

        

    public:
        /** @brief Define se está acontecendo os testes (quando true, desativa comportamentos que atrapaham os testes (ex: saves)). */
        static bool modoTeste;

        /**
         * @brief Construtor da Engine.
         */
        Engine();

        /**
         * @brief Inicia o motor do jogo.
         * Delega a interface inicial ao Menu, configura a entidade principal 
         * e entra no loop contínuo de transição de salas.
         */
        void iniciar();

        /**
         * @brief Destrutor da Engine.
         * Declarado como default para delegar a limpeza ao std::unique_ptr.
         */
        ~Engine() = default;
};

#endif