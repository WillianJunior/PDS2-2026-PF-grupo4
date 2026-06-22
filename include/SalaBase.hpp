#ifndef SALABASE_H
#define SALABASE_H

#include <iostream>
#include <string>
#include "Utils.hpp"

class Personagem;
/**
 * @brief Classe base abstrata que representa uma sala genérica.
 * * Define a interface padrão e os atributos básicos que todas as 
 * salas específicas devem herdar e implementar.
 */
class SalaBase {
    protected:
        /** * @brief Nome ou identificador da sala. 
         */
        std::string _nome;

        /**
         * @brief Construtor da classe SalaBase.
         * @param nome O nome que será atribuído à sala.
         */
        SalaBase(std::string nome);

    public:
        /**
         * @brief Encerra a execução ou o contexto da sala atual.
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual void encerrarSala() = 0;

        /**
         * @brief Executa o loop da sala
         * @return Numero que representa a ID da proxima sala a ser carregada**/
        virtual int executarSala(Personagem& personagem) = 0;

        /**
         * @brief Exibe as informações, o menu ou o conteúdo da sala na tela.
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual void mostrarSala() = 0;

        /**
         * @brief Retorna o nome da sala.
         */
        std::string getNome();
        
        /**
         * @brief Retorna o tipo da sala ("C" para combate, "E" para escolha).
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual char getTipo() = 0;

        /**
         * @brief Destrutor virtual.
         * Garante que os recursos das classes derivadas sejam liberados corretamente.
         */
        virtual ~SalaBase();
};

#endif